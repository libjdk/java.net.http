#ifndef _jdk_internal_net_http_ResponseContent$BodyParser_h_
#define _jdk_internal_net_http_ResponseContent$BodyParser_h_
//$ interface jdk.internal.net.http.ResponseContent$BodyParser
//$ extends java.util.function.Consumer

#include <java/util/function/Consumer.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AbstractSubscription;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ResponseContent$BodyParser : public ::java::util::function::Consumer {
	$interface(ResponseContent$BodyParser, $NO_CLASS_INIT, ::java::util::function::Consumer)
public:
	virtual $String* currentStateMessage() {return nullptr;}
	virtual void onSubscribe(::jdk::internal::net::http::AbstractSubscription* sub) {}
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseContent$BodyParser_h_