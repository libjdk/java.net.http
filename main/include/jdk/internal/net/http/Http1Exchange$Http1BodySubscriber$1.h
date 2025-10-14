#ifndef _jdk_internal_net_http_Http1Exchange$Http1BodySubscriber$1_h_
#define _jdk_internal_net_http_Http1Exchange$Http1BodySubscriber$1_h_
//$ class jdk.internal.net.http.Http1Exchange$Http1BodySubscriber$1
//$ extends jdk.internal.net.http.Http1Exchange$Http1BodySubscriber

#include <jdk/internal/net/http/Http1Exchange$Http1BodySubscriber.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Subscription;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http1Exchange$Http1BodySubscriber$1 : public ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber {
	$class(Http1Exchange$Http1BodySubscriber$1, $NO_CLASS_INIT, ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber)
public:
	Http1Exchange$Http1BodySubscriber$1();
	void init$(::jdk::internal::net::http::common::Logger* debug);
	virtual $String* currentStateMessage() override;
	void error();
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	virtual void onNext(::java::nio::ByteBuffer* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Exchange$Http1BodySubscriber$1_h_