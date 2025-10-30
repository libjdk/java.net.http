#include <jdk/internal/net/http/ResponseContent$BodyParser.h>

#include <jdk/internal/net/http/AbstractSubscription.h>
#include <jdk/internal/net/http/ResponseContent.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Consumer = ::java::util::function::Consumer;
using $AbstractSubscription = ::jdk::internal::net::http::AbstractSubscription;
using $ResponseContent = ::jdk::internal::net::http::ResponseContent;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _ResponseContent$BodyParser_MethodInfo_[] = {
	{"currentStateMessage", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"onSubscribe", "(Ljdk/internal/net/http/AbstractSubscription;)V", nullptr, $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _ResponseContent$BodyParser_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseContent$BodyParser", "jdk.internal.net.http.ResponseContent", "BodyParser", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseContent$BodyParser_ClassInfo_ = {
	$INTERFACE | $ABSTRACT,
	"jdk.internal.net.http.ResponseContent$BodyParser",
	nullptr,
	"java.util.function.Consumer",
	nullptr,
	_ResponseContent$BodyParser_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/function/Consumer<Ljava/nio/ByteBuffer;>;",
	nullptr,
	_ResponseContent$BodyParser_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseContent"
};

$Object* allocate$ResponseContent$BodyParser($Class* clazz) {
	return $of($alloc(ResponseContent$BodyParser));
}

$Class* ResponseContent$BodyParser::load$($String* name, bool initialize) {
	$loadClass(ResponseContent$BodyParser, name, initialize, &_ResponseContent$BodyParser_ClassInfo_, allocate$ResponseContent$BodyParser);
	return class$;
}

$Class* ResponseContent$BodyParser::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk