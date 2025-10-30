#include <jdk/internal/net/http/websocket/Frame$HeaderWriter.h>

#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/websocket/Frame$Opcode.h>
#include <jdk/internal/net/http/websocket/Frame.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Frame = ::jdk::internal::net::http::websocket::Frame;
using $Frame$Opcode = ::jdk::internal::net::http::websocket::Frame$Opcode;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _Frame$HeaderWriter_FieldInfo_[] = {
	{"firstChar", "C", nullptr, $PRIVATE, $field(Frame$HeaderWriter, firstChar)},
	{"payloadLen", "J", nullptr, $PRIVATE, $field(Frame$HeaderWriter, payloadLen$)},
	{"maskingKey", "I", nullptr, $PRIVATE, $field(Frame$HeaderWriter, maskingKey)},
	{"mask", "Z", nullptr, $PRIVATE, $field(Frame$HeaderWriter, mask$)},
	{}
};

$MethodInfo _Frame$HeaderWriter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Frame$HeaderWriter::*)()>(&Frame$HeaderWriter::init$))},
	{"fin", "(Z)Ljdk/internal/net/http/websocket/Frame$HeaderWriter;", nullptr, 0, $method(static_cast<Frame$HeaderWriter*(Frame$HeaderWriter::*)(bool)>(&Frame$HeaderWriter::fin))},
	{"mask", "(I)Ljdk/internal/net/http/websocket/Frame$HeaderWriter;", nullptr, 0, $method(static_cast<Frame$HeaderWriter*(Frame$HeaderWriter::*)(int32_t)>(&Frame$HeaderWriter::mask))},
	{"noMask", "()Ljdk/internal/net/http/websocket/Frame$HeaderWriter;", nullptr, 0, $method(static_cast<Frame$HeaderWriter*(Frame$HeaderWriter::*)()>(&Frame$HeaderWriter::noMask))},
	{"opcode", "(Ljdk/internal/net/http/websocket/Frame$Opcode;)Ljdk/internal/net/http/websocket/Frame$HeaderWriter;", nullptr, 0, $method(static_cast<Frame$HeaderWriter*(Frame$HeaderWriter::*)($Frame$Opcode*)>(&Frame$HeaderWriter::opcode))},
	{"payloadLen", "(J)Ljdk/internal/net/http/websocket/Frame$HeaderWriter;", nullptr, 0, $method(static_cast<Frame$HeaderWriter*(Frame$HeaderWriter::*)(int64_t)>(&Frame$HeaderWriter::payloadLen))},
	{"rsv1", "(Z)Ljdk/internal/net/http/websocket/Frame$HeaderWriter;", nullptr, 0, $method(static_cast<Frame$HeaderWriter*(Frame$HeaderWriter::*)(bool)>(&Frame$HeaderWriter::rsv1))},
	{"rsv2", "(Z)Ljdk/internal/net/http/websocket/Frame$HeaderWriter;", nullptr, 0, $method(static_cast<Frame$HeaderWriter*(Frame$HeaderWriter::*)(bool)>(&Frame$HeaderWriter::rsv2))},
	{"rsv3", "(Z)Ljdk/internal/net/http/websocket/Frame$HeaderWriter;", nullptr, 0, $method(static_cast<Frame$HeaderWriter*(Frame$HeaderWriter::*)(bool)>(&Frame$HeaderWriter::rsv3))},
	{"write", "(Ljava/nio/ByteBuffer;)V", nullptr, 0, $method(static_cast<void(Frame$HeaderWriter::*)($ByteBuffer*)>(&Frame$HeaderWriter::write))},
	{}
};

$InnerClassInfo _Frame$HeaderWriter_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.Frame$HeaderWriter", "jdk.internal.net.http.websocket.Frame", "HeaderWriter", $STATIC | $FINAL},
	{}
};

$ClassInfo _Frame$HeaderWriter_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.websocket.Frame$HeaderWriter",
	"java.lang.Object",
	nullptr,
	_Frame$HeaderWriter_FieldInfo_,
	_Frame$HeaderWriter_MethodInfo_,
	nullptr,
	nullptr,
	_Frame$HeaderWriter_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.Frame"
};

$Object* allocate$Frame$HeaderWriter($Class* clazz) {
	return $of($alloc(Frame$HeaderWriter));
}

void Frame$HeaderWriter::init$() {
}

Frame$HeaderWriter* Frame$HeaderWriter::fin(bool value) {
	if (value) {
		this->firstChar |= 32768;
	} else {
		this->firstChar &= (char16_t)~32768;
	}
	return this;
}

Frame$HeaderWriter* Frame$HeaderWriter::rsv1(bool value) {
	if (value) {
		this->firstChar |= 16384;
	} else {
		this->firstChar &= (char16_t)~16384;
	}
	return this;
}

Frame$HeaderWriter* Frame$HeaderWriter::rsv2(bool value) {
	if (value) {
		this->firstChar |= 8192;
	} else {
		this->firstChar &= (char16_t)~8192;
	}
	return this;
}

Frame$HeaderWriter* Frame$HeaderWriter::rsv3(bool value) {
	if (value) {
		this->firstChar |= 4096;
	} else {
		this->firstChar &= (char16_t)~4096;
	}
	return this;
}

Frame$HeaderWriter* Frame$HeaderWriter::opcode($Frame$Opcode* value) {
	this->firstChar = (char16_t)(((int32_t)(this->firstChar & (uint32_t)0x0000F0FF)) | ($nc(value)->code << 8));
	return this;
}

Frame$HeaderWriter* Frame$HeaderWriter::payloadLen(int64_t value) {
	$useLocalCurrentObjectStackCache();
	if (value < 0) {
		$throwNew($IllegalArgumentException, $$str({"Negative: "_s, $$str(value)}));
	}
	this->payloadLen$ = value;
	this->firstChar &= (char16_t)0x0000FF80;
	if (this->payloadLen$ < 126) {
		this->firstChar |= this->payloadLen$;
	} else if (this->payloadLen$ < 0x00010000) {
		this->firstChar |= 126;
	} else {
		this->firstChar |= 127;
	}
	return this;
}

Frame$HeaderWriter* Frame$HeaderWriter::mask(int32_t value) {
	this->firstChar |= 128;
	this->maskingKey = value;
	this->mask$ = true;
	return this;
}

Frame$HeaderWriter* Frame$HeaderWriter::noMask() {
	this->firstChar &= (char16_t)~128;
	this->mask$ = false;
	return this;
}

void Frame$HeaderWriter::write($ByteBuffer* buffer) {
	$nc(buffer)->putChar(this->firstChar);
	if (this->payloadLen$ >= 126) {
		if (this->payloadLen$ < 0x00010000) {
			buffer->putChar((char16_t)this->payloadLen$);
		} else {
			buffer->putLong(this->payloadLen$);
		}
	}
	if (this->mask$) {
		buffer->putInt(this->maskingKey);
	}
}

Frame$HeaderWriter::Frame$HeaderWriter() {
}

$Class* Frame$HeaderWriter::load$($String* name, bool initialize) {
	$loadClass(Frame$HeaderWriter, name, initialize, &_Frame$HeaderWriter_ClassInfo_, allocate$Frame$HeaderWriter);
	return class$;
}

$Class* Frame$HeaderWriter::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk