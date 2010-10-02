// Copyright (C) 2009  Internet Systems Consortium, Inc. ("ISC")
//
// Permission to use, copy, modify, and/or distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH
// REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,
// INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
// LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE
// OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
// PERFORMANCE OF THIS SOFTWARE.

// $Id$

#ifndef __MESSAGE_H
#define __MESSAGE_H 1

#include <stdint.h>

#include <iterator>
#include <string>
#include <ostream>

#include <exceptions/exceptions.h>

#include <dns/edns.h>
#include <dns/question.h>
#include <dns/rrset.h>

namespace isc {
namespace dns {

///
/// \brief A standard DNS module exception that is thrown if a wire format
/// message parser encounters a short length of data that don't even contain
/// the full header section.
///
class MessageTooShort : public Exception {
public:
    MessageTooShort(const char* file, size_t line, const char* what) :
        isc::Exception(file, line, what) {}
};

///
/// \brief A standard DNS module exception that is thrown if a section iterator
/// is being constructed for an incompatible section.  Specifically, this
/// happens RRset iterator is being constructed for a Question section.
///
class InvalidMessageSection : public Exception {
public:
    InvalidMessageSection(const char* file, size_t line, const char* what) :
        isc::Exception(file, line, what) {}
};

///
/// \brief A standard DNS module exception that is thrown if a \c Message
/// class method is called that is prohibited for the current mode of
/// the message.
///
class InvalidMessageOperation : public Exception {
public:
    InvalidMessageOperation(const char* file, size_t line, const char* what) :
        isc::Exception(file, line, what) {}
};

///
/// \brief A standard DNS module exception that is thrown if a UDP buffer size
/// smaller than the standard default maximum (DEFAULT_MAX_UDPSIZE) is
/// being specified for the message.
///
class InvalidMessageUDPSize : public Exception {
public:
    InvalidMessageUDPSize(const char* file, size_t line, const char* what) :
        isc::Exception(file, line, what) {}
};

typedef uint16_t qid_t;

class InputBuffer;
class MessageRenderer;
class Message;
class MessageImpl;
class Opcode;
class Rcode;

template <typename T>
struct SectionIteratorImpl;

/// \brief The \c MessageFlag class objects represent standard flag bits
/// of the header section of DNS messages.
///
/// Constant objects are defined for standard flags.
class MessageFlag {
public:
    /// \brief Returns the corresponding bit of the MessageFlag.
    ///
    /// Note: this value is intended to be used for rendering or parsing
    /// low level wire-format data.  Applications should use abstract
    /// interfaces.  This also means the interface is not well sophisticated,
    /// and we should revisit the design.
    uint16_t getBit() const { return (flagbit_); }
    static const MessageFlag& QR();
    static const MessageFlag& AA();
    static const MessageFlag& TC();
    static const MessageFlag& RD();
    static const MessageFlag& RA();
    static const MessageFlag& AD();
    static const MessageFlag& CD();
private:
    MessageFlag(uint16_t flagbit) : flagbit_(flagbit) {}
    uint16_t flagbit_;
};

inline const MessageFlag&
MessageFlag::QR()
{
    static MessageFlag f(0x8000);
    return (f);
}

inline const MessageFlag&
MessageFlag::AA()
{
    static MessageFlag f(0x0400);
    return (f);
}

inline const MessageFlag&
MessageFlag::TC()
{
    static MessageFlag f(0x0200);
    return (f);
}

inline const MessageFlag&
MessageFlag::RD()
{
    static MessageFlag f(0x0100);
    return (f);
}

inline const MessageFlag&
MessageFlag::RA()
{
    static MessageFlag f(0x0080);
    return (f);
}

inline const MessageFlag&
MessageFlag::AD()
{
    static MessageFlag f(0x0020);
    return (f);
}

inline const MessageFlag&
MessageFlag::CD()
{
    static MessageFlag f(0x0010);
    return (f);
}

/// \brief The \c Section class objects represent DNS message sections such
/// as the header, question, or answer.
///
/// Note: this class doesn't seem to be very useful.  We should probably
/// revisit this design.
///
/// Note: whether or not it's represented as a class, we'll need a way
/// to represent more advanced sections such as those used in dynamic updates.
/// This is a TODO item.
///
/// Constant objects are defined for standard flags.
class Section {
public:
    /// \brief Returns the relative position of the \c Section in DNS messages.
    unsigned int getCode() const { return (code_); }
    bool operator==(const Section& other) const
        { return (code_ == other.code_); }
    bool operator!=(const Section& other) const
        { return (code_ != other.code_); }

    static const Section& QUESTION();
    static const Section& ANSWER();
    static const Section& AUTHORITY();
    static const Section& ADDITIONAL();
private:
    enum {
        SECTION_QUESTION = 0,
        SECTION_ANSWER = 1,
        SECTION_AUTHORITY = 2,
        SECTION_ADDITIONAL = 3
    };

    Section(int code) : code_(code) {}
    unsigned int code_;
};

inline const Section&
Section::QUESTION()
{
    static Section s(SECTION_QUESTION);
    return (s);
}

inline const Section&
Section::ANSWER()
{
    static Section s(SECTION_ANSWER);
    return (s);
}

inline const Section&
Section::AUTHORITY()
{
    static Section s(SECTION_AUTHORITY);
    return (s);
}

inline const Section&
Section::ADDITIONAL()
{
    static Section s(SECTION_ADDITIONAL);
    return (s);
}

/// \c SectionIterator is a templated class to provide standard-compatible
/// iterators for Questions and RRsets for a given DNS message section.
/// The template parameter is either \c QuestionPtr (for the question section)
/// or \c RRsetPtr (for the answer, authority, or additional section).
template <typename T>
class SectionIterator : public std::iterator<std::input_iterator_tag, T> {
public:
    SectionIterator<T>() : impl_(NULL) {}
    SectionIterator<T>(const SectionIteratorImpl<T>& impl);
    ~SectionIterator<T>();
    SectionIterator<T>(const SectionIterator<T>& source);
    void operator=(const SectionIterator<T>& source);
    SectionIterator<T>& operator++();
    SectionIterator<T> operator++(int);
    const T& operator*() const;
    const T* operator->() const;
    bool operator==(const SectionIterator<T>& other) const;
    bool operator!=(const SectionIterator<T>& other) const;
private:
    SectionIteratorImpl<T>* impl_;
};

typedef SectionIterator<QuestionPtr> QuestionIterator;
typedef SectionIterator<RRsetPtr> RRsetIterator;

/// \brief The \c Message class encapsulates a standard DNS message.
///
/// Details of the design and interfaces of this class are still in flux.
/// Here are some notes about the current design.
///
/// Since many realistic DNS applications deal with messages, message objects
/// will be frequently used, and can be performance sensitive.  To minimize
/// the performance overhead of constructing and destructing the objects,
/// this class is designed to be reusable.  The \c clear() method is provided
/// for this purpose.
///
/// A \c Message class object is in either the \c PARSE or the \c RENDER mode.
/// A \c PARSE mode object is intended to be used to convert wire-format
/// message data into a complete \c Message object.
/// A \c RENDER mode object is intended to be used to convert a \c Message
/// object into wire-format data.
/// Some of the method functions of this class are limited to a specific mode.
/// In general, "set" type operations are only allowed for \c RENDER mode
/// objects.
/// The initial mode must be specified on construction, and can be changed
/// through some method functions.
///
/// This class uses the "pimpl" idiom, and hides detailed implementation
/// through the \c impl_ pointer.  Since a \c Message object is expected to
/// be reused, the construction overhead of this approach should be acceptable.
///
/// Open issues (among other things):
/// - We may want to provide an "iterator" for all RRsets/RRs for convenience.
///   This will be for applications that do not care about performance much,
///   so the implementation can only be moderately efficient.
/// - may want to provide a "find" method for a specified type
///   of RR in the message.
class Message {
public:
    enum Mode {
        PARSE = 0,
        RENDER = 1
    };

    ///
    /// \name Constructors and Destructor
    ///
    /// Note: The copy constructor and the assignment operator are intentionally
    /// defined as private.  The intended use case wouldn't require copies of
    /// a \c Message object; once created, it would normally be expected to
    /// be reused, changing the mode from \c PARSE to \c RENDER, and vice
    /// versa.
    //@{
public:
    /// \brief The constructor.
    /// The mode of the message is specified by the \c mode parameter.
    Message(Mode mode);
    /// \brief The destructor.
    ~Message();
private:
    Message(const Message& source);
    Message& operator=(const Message& source);
    //@}
public:
    /// \brief Return whether the specified header flag bit is set in the
    /// header section.
    bool getHeaderFlag(const MessageFlag& flag) const;

    /// \brief Set the specified header flag bit is set in the header section.
    ///
    /// Only allowed in the \c RENDER mode.
    void setHeaderFlag(const MessageFlag& flag);

    /// \brief Clear the specified header flag bit is set in the header section.
    ///
    /// Only allowed in the \c RENDER mode.
    /// Note: it may make more sense to integrate this method into \c
    /// \c setHeaderFlag() with an additional argument.
    void clearHeaderFlag(const MessageFlag& flag);

    /// \brief Return the query ID given in the header section of the message.
    qid_t getQid() const;

    /// \brief Set the query ID of the header section of the message.
    ///
    /// Only allowed in the \c RENDER mode.
    void setQid(qid_t qid);

    /// \brief Return the Response Code of the message.
    ///
    /// This includes extended codes specified by an EDNS OPT RR (when
    /// included).  In the \c PARSE mode, if the received message contains
    /// an EDNS OPT RR, the corresponding extended code is identified and
    /// returned.
    ///
    /// The message must have been properly parsed (in the case of the
    /// \c PARSE mode) or an \c Rcode has been set (in the case of the
    /// \c RENDER mode) beforehand.  Otherwise, an exception of class
    /// \c InvalidMessageOperation will be thrown.
    const Rcode& getRcode() const;

    /// \brief Set the Response Code of the message.
    ///
    /// Only allowed in the \c RENDER mode.
    ///
    /// If the specified code is an EDNS extended RCODE, an EDNS OPT RR will be
    /// included in the message.
    void setRcode(const Rcode& rcode);

    /// \brief Return the OPCODE given in the header section of the message.
    ///
    /// The message must have been properly parsed (in the case of the
    /// \c PARSE mode) or an \c Opcode has been set (in the case of the
    /// \c RENDER mode) beforehand.  Otherwise, an exception of class
    /// \c InvalidMessageOperation will be thrown.
    const Opcode& getOpcode() const;

    /// \brief Set the OPCODE of the header section of the message.
    ///
    /// Only allowed in the \c RENDER mode.
    void setOpcode(const Opcode& opcode);

    /// \brief Return, if any, the EDNS associated with the message.
    ///
    /// This method never throws an exception.
    ///
    /// \return A shared pointer to the EDNS.  This will be a null shared
    /// pointer if the message is not associated with EDNS.
    ConstEDNSPtr getEDNS() const;

    /// \brief Set EDNS for the message.
    ///
    /// Only allowed in the \c RENDER mode; otherwise an exception of class
    /// \c InvalidMessageOperation will be thrown.
    ///
    /// \param edns A shared pointer to an \c EDNS object to be set in
    /// \c Message.
    void setEDNS(ConstEDNSPtr edns);

    /// \brief Returns the number of RRs contained in the given section.
    unsigned int getRRCount(const Section& section) const;

    /// \brief Return an iterator corresponding to the beginning of the
    /// Question section of the message.
    const QuestionIterator beginQuestion() const;

    /// \brief Return an iterator corresponding to the end of the
    /// Question section of the message.
    const QuestionIterator endQuestion() const;

    /// \brief Return an iterator corresponding to the beginning of the
    /// given section (other than Question) of the message.
    const RRsetIterator beginSection(const Section& section) const;

    /// \brief Return an iterator corresponding to the end of the
    /// given section (other than Question) of the message.
    const RRsetIterator endSection(const Section& section) const;

    /// \brief Add a (pointer like object of) Question to the message.
    ///
    /// Only allowed in the \c RENDER mode.
    void addQuestion(QuestionPtr question);

    /// \brief Add a (pointer like object of) Question to the message.
    ///
    /// This version internally creates a \c QuestionPtr object from the
    /// given \c question and calls the other version of this method.
    /// So this is inherently less efficient, but is provided because this
    /// form may be more intuitive and may make more sense for performance
    /// insensitive applications.
    ///
    /// Only allowed in the \c RENDER mode.
    void addQuestion(const Question& question);

    /// \brief Add a (pointer like object of) RRset to the given section
    /// of the message.
    ///
    /// This interface takes into account the RRSIG possibly attached to
    /// \c rrset.  This interface design needs to be revisited later.
    ///
    /// Only allowed in the \c RENDER mode.
    ///
    /// Note that addRRset() does not currently check for duplicate
    /// data before inserting RRsets.  The caller is responsible for
    /// checking for these (see hasRRset() below).
    void addRRset(const Section& section, RRsetPtr rrset, bool sign = false);

    /// \brief Determine whether the given section already has an RRset
    /// matching the name and type of this one
    bool hasRRset(const Section& section, RRsetPtr rrset);

    // The following methods are not currently implemented.
    //void removeQuestion(QuestionPtr question);
    //void removeRRset(const Section& section, RRsetPtr rrset);
    // notyet:
    //void addRR(const Section& section, const RR& rr);
    //void removeRR(const Section& section, const RR& rr);

    /// \brief Clear the message content (if any) and reinitialize it in the
    /// specified mode.
    void clear(Mode mode);

    /// \brief Prepare for making a response from a request.
    ///
    /// This will clear the DNS header except those fields that should be kept
    /// for the response, and clear answer and the following sections.
    /// See also dns_message_reply() of BIND9.
    void makeResponse();

    /// \brief Convert the Message to a string.
    ///
    /// At least \c Opcode and \c Rcode must be validly set in the \c Message
    /// (as a result of parse in the \c PARSE mode or by explicitly setting
    /// in the \c RENDER mode);  otherwise, an exception of
    /// class \c InvalidMessageOperation will be thrown.
    std::string toText() const;

    /// \brief Render the message in wire formant into a \c MessageRenderer
    /// object.
    ///
    /// This \c Message must be in the \c RENDER mode and both \c Opcode and
    /// \c Rcode must have been set beforehand; otherwise, an exception of
    /// class \c InvalidMessageOperation will be thrown.
    void toWire(MessageRenderer& renderer);

    /// \brief Parse the header section of the \c Message.
    void parseHeader(InputBuffer& buffer);

    /// \brief Parse the \c Message.
    void fromWire(InputBuffer& buffer);

    ///
    /// \name Protocol constants
    ///
    //@{
    /// \brief The default maximum size of UDP DNS messages that don't cause
    /// truncation.
    ///
    /// With EDNS the maximum size can be increased per message.
    static const uint16_t DEFAULT_MAX_UDPSIZE = 512;

    /// \brief The highest EDNS version this implementation supports.
    static const uint8_t EDNS_SUPPORTED_VERSION = 0;
    //@}

private:
    MessageImpl* impl_;
};

std::ostream& operator<<(std::ostream& os, const Message& message);
}
}
#endif  // __MESSAGE_H

// Local Variables: 
// mode: c++
// End: 
