#include <jdk/internal/net/http/websocket/Frame$Masker.h>

#include <java/lang/AssertionError.h>
#include <java/lang/Math.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/websocket/Frame.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $Frame = ::jdk::internal::net::http::websocket::Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _Frame$Masker_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Frame$Masker, $assertionsDisabled)},
	{"acc", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(Frame$Masker, acc)},
	{"maskBytes", "[I", nullptr, $PRIVATE | $FINAL, $field(Frame$Masker, maskBytes)},
	{"offset", "I", nullptr, $PRIVATE, $field(Frame$Masker, offset)},
	{"maskLong", "J", nullptr, $PRIVATE, $field(Frame$Masker, maskLong)},
	{}
};

$MethodInfo _Frame$Masker_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Frame$Masker::*)()>(&Frame$Masker::init$))},
	{"begin", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Frame$Masker::*)($ByteBuffer*,$ByteBuffer*)>(&Frame$Masker::begin))},
	{"end", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Frame$Masker::*)($ByteBuffer*,$ByteBuffer*)>(&Frame$Masker::end))},
	{"loop", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Frame$Masker::*)($ByteBuffer*,$ByteBuffer*)>(&Frame$Masker::loop))},
	{"mask", "(I)Ljdk/internal/net/http/websocket/Frame$Masker;", nullptr, 0, $method(static_cast<Frame$Masker*(Frame$Masker::*)(int32_t)>(&Frame$Masker::mask))},
	{"transferMasking", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;I)V", nullptr, $STATIC, $method(static_cast<void(*)($ByteBuffer*,$ByteBuffer*,int32_t)>(&Frame$Masker::transferMasking))},
	{"transferMasking", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)Ljdk/internal/net/http/websocket/Frame$Masker;", nullptr, 0, $method(static_cast<Frame$Masker*(Frame$Masker::*)($ByteBuffer*,$ByteBuffer*)>(&Frame$Masker::transferMasking))},
	{}
};

$InnerClassInfo _Frame$Masker_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.websocket.Frame$Masker", "jdk.internal.net.http.websocket.Frame", "Masker", $STATIC | $FINAL},
	{}
};

$ClassInfo _Frame$Masker_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.websocket.Frame$Masker",
	"java.lang.Object",
	nullptr,
	_Frame$Masker_FieldInfo_,
	_Frame$Masker_MethodInfo_,
	nullptr,
	nullptr,
	_Frame$Masker_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.websocket.Frame"
};

$Object* allocate$Frame$Masker($Class* clazz) {
	return $of($alloc(Frame$Masker));
}

bool Frame$Masker::$assertionsDisabled = false;

void Frame$Masker::init$() {
	$set(this, acc, $ByteBuffer::allocate(8));
	$set(this, maskBytes, $new($ints, 4));
}

void Frame$Masker::transferMasking($ByteBuffer* src, $ByteBuffer* dst, int32_t mask) {
	$init(Frame$Masker);
	$useLocalCurrentObjectStackCache();
	int32_t var$0 = $nc(src)->remaining();
	if (var$0 > $nc(dst)->remaining()) {
		$throwNew($IllegalArgumentException, $($Utils::dump($$new($ObjectArray, {
			$of(src),
			$of(dst)
		}))));
	}
	$nc($($$new(Frame$Masker)->mask(mask)))->transferMasking(src, dst);
}

Frame$Masker* Frame$Masker::mask(int32_t value) {
	$useLocalCurrentObjectStackCache();
	$nc($($nc($($nc($($nc(this->acc)->clear()))->putInt(value)))->putInt(value)))->flip();
	for (int32_t i = 0; i < $nc(this->maskBytes)->length; ++i) {
		$nc(this->maskBytes)->set(i, $nc(this->acc)->get(i));
	}
	this->offset = 0;
	this->maskLong = $nc(this->acc)->getLong(0);
	return this;
}

Frame$Masker* Frame$Masker::transferMasking($ByteBuffer* src, $ByteBuffer* dst) {
	begin(src, dst);
	loop(src, dst);
	end(src, dst);
	return this;
}

void Frame$Masker::begin($ByteBuffer* src, $ByteBuffer* dst) {
	if (this->offset == 0) {
		return;
	}
	int32_t i = $nc(src)->position();
	int32_t j = $nc(dst)->position();
	int32_t srcLim = src->limit();
	int32_t dstLim = dst->limit();
	for (; this->offset < 4 && i < srcLim && j < dstLim; ++i, ++j, ++this->offset) {
		dst->put(j, (int8_t)(src->get(i) ^ $nc(this->maskBytes)->get(this->offset)));
	}
	this->offset &= (uint32_t)3;
	src->position(i);
	dst->position(j);
}

void Frame$Masker::loop($ByteBuffer* src, $ByteBuffer* dst) {
	int32_t i = $nc(src)->position();
	int32_t j = $nc(dst)->position();
	int32_t srcLongLim = src->limit() - 7;
	int32_t dstLongLim = dst->limit() - 7;
	for (; i < srcLongLim && j < dstLongLim; i += 8, j += 8) {
		dst->putLong(j, src->getLong(i) ^ this->maskLong);
	}
	if (i > src->limit()) {
		src->position(i - 8);
	} else {
		src->position(i);
	}
	if (j > dst->limit()) {
		dst->position(j - 8);
	} else {
		dst->position(j);
	}
}

void Frame$Masker::end($ByteBuffer* src, $ByteBuffer* dst) {
	bool var$0 = !Frame$Masker::$assertionsDisabled;
	if (var$0) {
		int32_t var$1 = $nc(src)->remaining();
		var$0 = !($Math::min(var$1, $nc(dst)->remaining()) < 8);
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	int32_t srcLim = $nc(src)->limit();
	int32_t dstLim = $nc(dst)->limit();
	int32_t i = src->position();
	int32_t j = dst->position();
	for (; i < srcLim && j < dstLim; ++i, ++j, this->offset = (int32_t)((this->offset + 1) & (uint32_t)3)) {
		dst->put(j, (int8_t)(src->get(i) ^ $nc(this->maskBytes)->get(this->offset)));
	}
	src->position(i);
	dst->position(j);
}

void clinit$Frame$Masker($Class* class$) {
	$load($Frame);
	Frame$Masker::$assertionsDisabled = !$Frame::class$->desiredAssertionStatus();
}

Frame$Masker::Frame$Masker() {
}

$Class* Frame$Masker::load$($String* name, bool initialize) {
	$loadClass(Frame$Masker, name, initialize, &_Frame$Masker_ClassInfo_, clinit$Frame$Masker, allocate$Frame$Masker);
	return class$;
}

$Class* Frame$Masker::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk