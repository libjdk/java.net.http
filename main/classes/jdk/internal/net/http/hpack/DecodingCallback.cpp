#include <jdk/internal/net/http/hpack/DecodingCallback.h>

#include <java/lang/CharSequence.h>
#include <jcpp.h>

using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $CompoundAttribute = ::java::lang::CompoundAttribute;
using $MethodInfo = ::java::lang::MethodInfo;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$CompoundAttribute _DecodingCallback_Annotations_[] = {
	{"Ljava/lang/FunctionalInterface;", nullptr},
	{}
};

$MethodInfo _DecodingCallback_MethodInfo_[] = {
	{"onDecoded", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)V", nullptr, $PUBLIC | $ABSTRACT},
	{"onDecoded", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;Z)V", nullptr, $PUBLIC},
	{"onIndexed", "(ILjava/lang/CharSequence;Ljava/lang/CharSequence;)V", nullptr, $PUBLIC},
	{"onLiteral", "(ILjava/lang/CharSequence;Ljava/lang/CharSequence;Z)V", nullptr, $PUBLIC},
	{"onLiteral", "(Ljava/lang/CharSequence;ZLjava/lang/CharSequence;Z)V", nullptr, $PUBLIC},
	{"onLiteralNeverIndexed", "(ILjava/lang/CharSequence;Ljava/lang/CharSequence;Z)V", nullptr, $PUBLIC},
	{"onLiteralNeverIndexed", "(Ljava/lang/CharSequence;ZLjava/lang/CharSequence;Z)V", nullptr, $PUBLIC},
	{"onLiteralWithIndexing", "(ILjava/lang/CharSequence;Ljava/lang/CharSequence;Z)V", nullptr, $PUBLIC},
	{"onLiteralWithIndexing", "(Ljava/lang/CharSequence;ZLjava/lang/CharSequence;Z)V", nullptr, $PUBLIC},
	{"onSizeUpdate", "(I)V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _DecodingCallback_ClassInfo_ = {
	$PUBLIC | $INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.hpack.DecodingCallback",
	nullptr,
	nullptr,
	nullptr,
	_DecodingCallback_MethodInfo_,
	nullptr,
	nullptr,
	nullptr,
	_DecodingCallback_Annotations_
};

$Object* allocate$DecodingCallback($Class* clazz) {
	return $of($alloc(DecodingCallback));
}

void DecodingCallback::onDecoded($CharSequence* name, $CharSequence* value, bool sensitive) {
	onDecoded(name, value);
}

void DecodingCallback::onIndexed(int32_t index, $CharSequence* name, $CharSequence* value) {
	onDecoded(name, value, false);
}

void DecodingCallback::onLiteral(int32_t index, $CharSequence* name, $CharSequence* value, bool valueHuffman) {
	onDecoded(name, value, false);
}

void DecodingCallback::onLiteral($CharSequence* name, bool nameHuffman, $CharSequence* value, bool valueHuffman) {
	onDecoded(name, value, false);
}

void DecodingCallback::onLiteralNeverIndexed(int32_t index, $CharSequence* name, $CharSequence* value, bool valueHuffman) {
	onDecoded(name, value, true);
}

void DecodingCallback::onLiteralNeverIndexed($CharSequence* name, bool nameHuffman, $CharSequence* value, bool valueHuffman) {
	onDecoded(name, value, true);
}

void DecodingCallback::onLiteralWithIndexing(int32_t index, $CharSequence* name, $CharSequence* value, bool valueHuffman) {
	onDecoded(name, value, false);
}

void DecodingCallback::onLiteralWithIndexing($CharSequence* name, bool nameHuffman, $CharSequence* value, bool valueHuffman) {
	onDecoded(name, value, false);
}

void DecodingCallback::onSizeUpdate(int32_t capacity) {
}

$Class* DecodingCallback::load$($String* name, bool initialize) {
	$loadClass(DecodingCallback, name, initialize, &_DecodingCallback_ClassInfo_, allocate$DecodingCallback);
	return class$;
}

$Class* DecodingCallback::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk