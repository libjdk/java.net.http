#include <jdk/internal/net/http/hpack/ISO_8859_1$Reader.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/Appendable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer.h>
#include <jdk/internal/net/http/hpack/HPACK.h>
#include <jdk/internal/net/http/hpack/ISO_8859_1.h>
#include <jcpp.h>

#undef UPDATER

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $Appendable = ::java::lang::Appendable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $HPACK = ::jdk::internal::net::http::hpack::HPACK;
using $HPACK$BufferUpdateConsumer = ::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer;
using $ISO_8859_1 = ::jdk::internal::net::http::hpack::ISO_8859_1;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class ISO_8859_1$Reader$$Lambda$lambda$new$0 : public $HPACK$BufferUpdateConsumer {
	$class(ISO_8859_1$Reader$$Lambda$lambda$new$0, $NO_CLASS_INIT, $HPACK$BufferUpdateConsumer)
public:
	void init$(ISO_8859_1$Reader* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(int64_t buf, int32_t bufLen) override {
		$nc(inst$)->lambda$new$0(buf, bufLen);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ISO_8859_1$Reader$$Lambda$lambda$new$0>());
	}
	ISO_8859_1$Reader* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ISO_8859_1$Reader$$Lambda$lambda$new$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ISO_8859_1$Reader$$Lambda$lambda$new$0, inst$)},
	{}
};
$MethodInfo ISO_8859_1$Reader$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/ISO_8859_1$Reader;)V", nullptr, $PUBLIC, $method(static_cast<void(ISO_8859_1$Reader$$Lambda$lambda$new$0::*)(ISO_8859_1$Reader*)>(&ISO_8859_1$Reader$$Lambda$lambda$new$0::init$))},
	{"accept", "(JI)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ISO_8859_1$Reader$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.ISO_8859_1$Reader$$Lambda$lambda$new$0",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.HPACK$BufferUpdateConsumer",
	fieldInfos,
	methodInfos
};
$Class* ISO_8859_1$Reader$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(ISO_8859_1$Reader$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ISO_8859_1$Reader$$Lambda$lambda$new$0::class$ = nullptr;

$FieldInfo _ISO_8859_1$Reader_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ISO_8859_1$Reader, $assertionsDisabled)},
	{"UPDATER", "Ljdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer;", nullptr, $PRIVATE | $FINAL, $field(ISO_8859_1$Reader, UPDATER)},
	{"buffer", "J", nullptr, $PRIVATE, $field(ISO_8859_1$Reader, buffer)},
	{"bufferLen", "I", nullptr, $PRIVATE, $field(ISO_8859_1$Reader, bufferLen)},
	{}
};

$MethodInfo _ISO_8859_1$Reader_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ISO_8859_1$Reader::*)()>(&ISO_8859_1$Reader::init$))},
	{"lambda$new$0", "(JI)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(ISO_8859_1$Reader::*)(int64_t,int32_t)>(&ISO_8859_1$Reader::lambda$new$0))},
	{"read", "(Ljava/nio/ByteBuffer;Ljava/lang/Appendable;)V", nullptr, $PUBLIC, $method(static_cast<void(ISO_8859_1$Reader::*)($ByteBuffer*,$Appendable*)>(&ISO_8859_1$Reader::read)), "java.io.IOException"},
	{"reset", "()Ljdk/internal/net/http/hpack/ISO_8859_1$Reader;", nullptr, $PUBLIC, $method(static_cast<ISO_8859_1$Reader*(ISO_8859_1$Reader::*)()>(&ISO_8859_1$Reader::reset))},
	{}
};

$InnerClassInfo _ISO_8859_1$Reader_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.ISO_8859_1$Reader", "jdk.internal.net.http.hpack.ISO_8859_1", "Reader", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _ISO_8859_1$Reader_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.ISO_8859_1$Reader",
	"java.lang.Object",
	nullptr,
	_ISO_8859_1$Reader_FieldInfo_,
	_ISO_8859_1$Reader_MethodInfo_,
	nullptr,
	nullptr,
	_ISO_8859_1$Reader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.ISO_8859_1"
};

$Object* allocate$ISO_8859_1$Reader($Class* clazz) {
	return $of($alloc(ISO_8859_1$Reader));
}

bool ISO_8859_1$Reader::$assertionsDisabled = false;

void ISO_8859_1$Reader::init$() {
	$set(this, UPDATER, static_cast<$HPACK$BufferUpdateConsumer*>($new(ISO_8859_1$Reader$$Lambda$lambda$new$0, this)));
}

void ISO_8859_1$Reader::read($ByteBuffer* source, $Appendable* destination) {
	while (true) {
		int32_t nBytes = $HPACK::read(source, this->buffer, this->bufferLen, this->UPDATER);
		if (nBytes == 0) {
			return;
		}
		if (!ISO_8859_1$Reader::$assertionsDisabled && !(this->bufferLen % 8 == 0)) {
			$throwNew($AssertionError, this->bufferLen);
		}
		while (this->bufferLen > 0) {
			char16_t c = (char16_t)((int64_t)((uint64_t)this->buffer >> 56));
			try {
				$nc(destination)->append(c);
			} catch ($IOException& e) {
				$throwNew($IOException, "Error appending to the destination"_s, e);
			}
			this->buffer <<= 8;
			this->bufferLen -= 8;
		}
	}
}

ISO_8859_1$Reader* ISO_8859_1$Reader::reset() {
	this->buffer = 0;
	this->bufferLen = 0;
	return this;
}

void ISO_8859_1$Reader::lambda$new$0(int64_t buf, int32_t bufLen) {
	this->buffer = buf;
	this->bufferLen = bufLen;
}

void clinit$ISO_8859_1$Reader($Class* class$) {
	$load($ISO_8859_1);
	ISO_8859_1$Reader::$assertionsDisabled = !$ISO_8859_1::class$->desiredAssertionStatus();
}

ISO_8859_1$Reader::ISO_8859_1$Reader() {
}

$Class* ISO_8859_1$Reader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ISO_8859_1$Reader$$Lambda$lambda$new$0::classInfo$.name)) {
			return ISO_8859_1$Reader$$Lambda$lambda$new$0::load$(name, initialize);
		}
	}
	$loadClass(ISO_8859_1$Reader, name, initialize, &_ISO_8859_1$Reader_ClassInfo_, clinit$ISO_8859_1$Reader, allocate$ISO_8859_1$Reader);
	return class$;
}

$Class* ISO_8859_1$Reader::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk