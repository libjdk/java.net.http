#include <jdk/internal/net/http/hpack/ISO_8859_1$Writer.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
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

using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
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

class ISO_8859_1$Writer$$Lambda$lambda$new$0 : public $HPACK$BufferUpdateConsumer {
	$class(ISO_8859_1$Writer$$Lambda$lambda$new$0, $NO_CLASS_INIT, $HPACK$BufferUpdateConsumer)
public:
	void init$(ISO_8859_1$Writer* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(int64_t buf, int32_t bufLen) override {
		$nc(inst$)->lambda$new$0(buf, bufLen);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ISO_8859_1$Writer$$Lambda$lambda$new$0>());
	}
	ISO_8859_1$Writer* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ISO_8859_1$Writer$$Lambda$lambda$new$0::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ISO_8859_1$Writer$$Lambda$lambda$new$0, inst$)},
	{}
};
$MethodInfo ISO_8859_1$Writer$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/ISO_8859_1$Writer;)V", nullptr, $PUBLIC, $method(static_cast<void(ISO_8859_1$Writer$$Lambda$lambda$new$0::*)(ISO_8859_1$Writer*)>(&ISO_8859_1$Writer$$Lambda$lambda$new$0::init$))},
	{"accept", "(JI)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo ISO_8859_1$Writer$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.ISO_8859_1$Writer$$Lambda$lambda$new$0",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.HPACK$BufferUpdateConsumer",
	fieldInfos,
	methodInfos
};
$Class* ISO_8859_1$Writer$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(ISO_8859_1$Writer$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ISO_8859_1$Writer$$Lambda$lambda$new$0::class$ = nullptr;

$FieldInfo _ISO_8859_1$Writer_FieldInfo_[] = {
	{"UPDATER", "Ljdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer;", nullptr, $PRIVATE | $FINAL, $field(ISO_8859_1$Writer, UPDATER)},
	{"source", "Ljava/lang/CharSequence;", nullptr, $PRIVATE, $field(ISO_8859_1$Writer, source)},
	{"pos", "I", nullptr, $PRIVATE, $field(ISO_8859_1$Writer, pos)},
	{"end", "I", nullptr, $PRIVATE, $field(ISO_8859_1$Writer, end)},
	{"buffer", "J", nullptr, $PRIVATE, $field(ISO_8859_1$Writer, buffer)},
	{"bufferLen", "I", nullptr, $PRIVATE, $field(ISO_8859_1$Writer, bufferLen)},
	{}
};

$MethodInfo _ISO_8859_1$Writer_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ISO_8859_1$Writer::*)()>(&ISO_8859_1$Writer::init$))},
	{"configure", "(Ljava/lang/CharSequence;II)Ljdk/internal/net/http/hpack/ISO_8859_1$Writer;", nullptr, $PUBLIC, $method(static_cast<ISO_8859_1$Writer*(ISO_8859_1$Writer::*)($CharSequence*,int32_t,int32_t)>(&ISO_8859_1$Writer::configure))},
	{"lambda$new$0", "(JI)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(ISO_8859_1$Writer::*)(int64_t,int32_t)>(&ISO_8859_1$Writer::lambda$new$0))},
	{"reset", "()Ljdk/internal/net/http/hpack/ISO_8859_1$Writer;", nullptr, $PUBLIC, $method(static_cast<ISO_8859_1$Writer*(ISO_8859_1$Writer::*)()>(&ISO_8859_1$Writer::reset))},
	{"write", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC, $method(static_cast<bool(ISO_8859_1$Writer::*)($ByteBuffer*)>(&ISO_8859_1$Writer::write))},
	{}
};

$InnerClassInfo _ISO_8859_1$Writer_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.ISO_8859_1$Writer", "jdk.internal.net.http.hpack.ISO_8859_1", "Writer", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _ISO_8859_1$Writer_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.ISO_8859_1$Writer",
	"java.lang.Object",
	nullptr,
	_ISO_8859_1$Writer_FieldInfo_,
	_ISO_8859_1$Writer_MethodInfo_,
	nullptr,
	nullptr,
	_ISO_8859_1$Writer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.ISO_8859_1"
};

$Object* allocate$ISO_8859_1$Writer($Class* clazz) {
	return $of($alloc(ISO_8859_1$Writer));
}

void ISO_8859_1$Writer::init$() {
	$set(this, UPDATER, static_cast<$HPACK$BufferUpdateConsumer*>($new(ISO_8859_1$Writer$$Lambda$lambda$new$0, this)));
}

ISO_8859_1$Writer* ISO_8859_1$Writer::configure($CharSequence* source, int32_t start, int32_t end) {
	$set(this, source, source);
	this->pos = start;
	this->end = end;
	return this;
}

bool ISO_8859_1$Writer::write($ByteBuffer* destination) {
	$useLocalCurrentObjectStackCache();
	while (true) {
		while (true) {
			if (this->pos >= this->end) {
				break;
			}
			char16_t c = $nc(this->source)->charAt(this->pos);
			if (c > 255) {
				$throwNew($IllegalArgumentException, $($Integer::toString((int32_t)c)));
			}
			if (this->bufferLen <= 56) {
				this->buffer |= ($sl((int64_t)c, 56 - this->bufferLen));
				this->bufferLen += 8;
				++this->pos;
			} else {
				break;
			}
		}
		if (this->bufferLen == 0) {
			return true;
		}
		int32_t nBytes = $HPACK::write(this->buffer, this->bufferLen, this->UPDATER, destination);
		if (nBytes == 0) {
			return false;
		}
	}
}

ISO_8859_1$Writer* ISO_8859_1$Writer::reset() {
	$set(this, source, nullptr);
	this->pos = -1;
	this->end = -1;
	this->buffer = 0;
	this->bufferLen = 0;
	return this;
}

void ISO_8859_1$Writer::lambda$new$0(int64_t buf, int32_t bufLen) {
	this->buffer = buf;
	this->bufferLen = bufLen;
}

ISO_8859_1$Writer::ISO_8859_1$Writer() {
}

$Class* ISO_8859_1$Writer::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ISO_8859_1$Writer$$Lambda$lambda$new$0::classInfo$.name)) {
			return ISO_8859_1$Writer$$Lambda$lambda$new$0::load$(name, initialize);
		}
	}
	$loadClass(ISO_8859_1$Writer, name, initialize, &_ISO_8859_1$Writer_ClassInfo_, allocate$ISO_8859_1$Writer);
	return class$;
}

$Class* ISO_8859_1$Writer::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk