/* xoreos - A reimplementation of BioWare's Aurora engine
 *
 * xoreos is the legal property of its developers, whose names
 * can be found in the AUTHORS file distributed with this source
 * distribution.
 *
 * xoreos is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * xoreos is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with xoreos. If not, see <http://www.gnu.org/licenses/>.
 */

/** @file
 *  Classes for serializing and deserializing raw data.
 */

#ifndef COMMON_SERIALIZATIONSTREAM_H
#define COMMON_SERIALIZATIONSTREAM_H

#include "src/common/readstream.h"
#include "src/common/writestream.h"

namespace Common {

/** Base class for raw serialization. The serialization methods
 *  can either write or read depending on the used sub class. */
class SerializationStream {
public:
	virtual ~SerializationStream();

	/** Read or write a uint64 little endian value. */
	virtual void readOrWriteUint64LE(uint64 &value) = 0;
	/** Read or write a uint32 little endian value. */
	virtual void readOrWriteUint32LE(uint32 &value) = 0;
	/** Read or write a uint16 little endian value. */
	virtual void readOrWriteUint16LE(uint16 &value) = 0;
	/** Read or write a uint64 big endian value. */
	virtual void readOrWriteUint64BE(uint64 &value) = 0;
	/** Read or write a uint32 big endian value. */
	virtual void readOrWriteUint32BE(uint32 &value) = 0;
	/** Read or write a uint16 big endian value. */
	virtual void readOrWriteUint16BE(uint16 &value) = 0;
	/** Read or write a int64 little endian value. */
	virtual void readOrWriteSint64LE(int64 &value) = 0;
	/** Read or write a int32 little endian value. */
	virtual void readOrWriteSint32LE(int32 &value) = 0;
	/** Read or write a int16 little endian value. */
	virtual void readOrWriteSint16LE(int16 &value) = 0;
	/** Read or write a int64 big endian value. */
	virtual void readOrWriteSint64BE(int64 &value) = 0;
	/** Read or write a int32 big endian value. */
	virtual void readOrWriteSint32BE(int32 &value) = 0;
	/** Read or write a int16 big endian value. */
	virtual void readOrWriteSint16BE(int16 &value) = 0;

	/** Read or write a uint64 little endian value. */
	virtual void readOrWriteUint64LE(const uint64 &value) = 0;
	/** Read or write a uint32 little endian value. */
	virtual void readOrWriteUint32LE(const uint32 &value) = 0;
	/** Read or write a uint16 little endian value. */
	virtual void readOrWriteUint16LE(const uint16 &value) = 0;
	/** Read or write a uint64 big endian value. */
	virtual void readOrWriteUint64BE(const uint64 &value) = 0;
	/** Read or write a uint32 big endian value. */
	virtual void readOrWriteUint32BE(const uint32 &value) = 0;
	/** Read or write a uint16 big endian value. */
	virtual void readOrWriteUint16BE(const uint16 &value) = 0;
	/** Read or write a int64 little endian value. */
	virtual void readOrWriteSint64LE(const int64 &value) = 0;
	/** Read or write a int32 little endian value. */
	virtual void readOrWriteSint32LE(const int32 &value) = 0;
	/** Read or write a int16 little endian value. */
	virtual void readOrWriteSint16LE(const int16 &value) = 0;
	/** Read or write a int64 big endian value. */
	virtual void readOrWriteSint64BE(const int64 &value) = 0;
	/** Read or write a int32 big endian value. */
	virtual void readOrWriteSint32BE(const int32 &value) = 0;
	/** Read or write a int16 big endian value. */
	virtual void readOrWriteSint16BE(const int16 &value) = 0;

	/** Read or write byte. */
	virtual void readOrWriteByte(byte &value) = 0;
	/** Read or write byte. */
	virtual void readOrWriteByte(const byte &value) = 0;
	/** Read or write char. */
	virtual void readOrWriteChar(char &value) = 0;
	/** Read or write char. */
	virtual void readOrWriteChar(const char &value) = 0;

	/** Read or write the string given as value as ascii string, prefixed with
	 *  a byte representing the length of value.
	 *
	 *  @param value the string to write.
	 */
	virtual void readOrWriteBytePrefixedASCIIString(Common::UString &value) = 0;

	/** Read or write the string given as value as ascii string, prefixed with
	 *  a little endian uint32 representing the length of value.
	 *
	 *  @param value the string to write.
	 */
	virtual void readOrWriteUint32LEPrefixedASCIIString(Common::UString &value) = 0;

	/** Read or write the string given as value as ascii string, prefixed with
	 *  a byte representing the length of value.
	 *
	 *  @param value the string to write.
	 */
	virtual void readOrWriteBytePrefixedASCIIString(const Common::UString &value) = 0;

	/** Read or write the string given as value as ascii string, prefixed with
	 *  a little endian uint32 representing the length of value.
	 *
	 *  @param value the string to write.
	 */
	virtual void readOrWriteUint32LEPrefixedASCIIString(const Common::UString &value) = 0;
};

/** Serialization implementation for reading. */
class SerializationReadStream : public SerializationStream {
public:
	SerializationReadStream(SeekableReadStream &stream);

	void readOrWriteUint64LE(uint64 &value);
	void readOrWriteUint32LE(uint32 &value);
	void readOrWriteUint16LE(uint16 &value);
	void readOrWriteUint64BE(uint64 &value);
	void readOrWriteUint32BE(uint32 &value);
	void readOrWriteUint16BE(uint16 &value);
	void readOrWriteSint64LE(int64 &value);
	void readOrWriteSint32LE(int32 &value);
	void readOrWriteSint16LE(int16 &value);
	void readOrWriteSint64BE(int64 &value);
	void readOrWriteSint32BE(int32 &value);
	void readOrWriteSint16BE(int16 &value);

	void readOrWriteUint64LE(const uint64 &value);
	void readOrWriteUint32LE(const uint32 &value);
	void readOrWriteUint16LE(const uint16 &value);
	void readOrWriteUint64BE(const uint64 &value);
	void readOrWriteUint32BE(const uint32 &value);
	void readOrWriteUint16BE(const uint16 &value);
	void readOrWriteSint64LE(const int64 &value);
	void readOrWriteSint32LE(const int32 &value);
	void readOrWriteSint16LE(const int16 &value);
	void readOrWriteSint64BE(const int64 &value);
	void readOrWriteSint32BE(const int32 &value);
	void readOrWriteSint16BE(const int16 &value);

	void readOrWriteByte(byte &value);
	void readOrWriteByte(const byte &value);

	void readOrWriteChar(char &value);
	void readOrWriteChar(const char &value);

	void readOrWriteBytePrefixedASCIIString(Common::UString &value);
	void readOrWriteUint32LEPrefixedASCIIString(Common::UString &value);
	void readOrWriteBytePrefixedASCIIString(const Common::UString &value);
	void readOrWriteUint32LEPrefixedASCIIString(const Common::UString &value);

private:
	SeekableReadStream &_stream;
};

/** Serialization implementation for writing. */
class SerializationWriteStream : public SerializationStream {
public:
	SerializationWriteStream(WriteStream &stream);

	void readOrWriteUint64LE(uint64 &value);
	void readOrWriteUint32LE(uint32 &value);
	void readOrWriteUint16LE(uint16 &value);
	void readOrWriteUint64BE(uint64 &value);
	void readOrWriteUint32BE(uint32 &value);
	void readOrWriteUint16BE(uint16 &value);
	void readOrWriteSint64LE(int64 &value);
	void readOrWriteSint32LE(int32 &value);
	void readOrWriteSint16LE(int16 &value);
	void readOrWriteSint64BE(int64 &value);
	void readOrWriteSint32BE(int32 &value);
	void readOrWriteSint16BE(int16 &value);

	void readOrWriteUint64LE(const uint64 &value);
	void readOrWriteUint32LE(const uint32 &value);
	void readOrWriteUint16LE(const uint16 &value);
	void readOrWriteUint64BE(const uint64 &value);
	void readOrWriteUint32BE(const uint32 &value);
	void readOrWriteUint16BE(const uint16 &value);
	void readOrWriteSint64LE(const int64 &value);
	void readOrWriteSint32LE(const int32 &value);
	void readOrWriteSint16LE(const int16 &value);
	void readOrWriteSint64BE(const int64 &value);
	void readOrWriteSint32BE(const int32 &value);
	void readOrWriteSint16BE(const int16 &value);

	void readOrWriteByte(byte &value);
	void readOrWriteByte(const byte &value);
	void readOrWriteChar(char &value);
	void readOrWriteChar(const char &value);

	void readOrWriteBytePrefixedASCIIString(Common::UString &value);
	void readOrWriteUint32LEPrefixedASCIIString(Common::UString &value);
	void readOrWriteBytePrefixedASCIIString(const Common::UString &value);
	void readOrWriteUint32LEPrefixedASCIIString(const Common::UString &value);

private:
	WriteStream &_stream;
};

} // End of namespace Common

#endif // COMMON_SERIALIZATIONSTREAM_H
