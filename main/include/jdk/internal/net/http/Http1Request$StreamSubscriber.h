#ifndef _jdk_internal_net_http_Http1Request$StreamSubscriber_h_
#define _jdk_internal_net_http_Http1Request$StreamSubscriber_h_
//$ class jdk.internal.net.http.Http1Request$StreamSubscriber
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
				class Http1Request;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http1Request$StreamSubscriber : public ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber {
	$class(Http1Request$StreamSubscriber, $NO_CLASS_INIT, ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber)
public:
	Http1Request$StreamSubscriber();
	void init$(::jdk::internal::net::http::Http1Request* this$0);
	virtual $String* currentStateMessage() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onNext(::java::nio::ByteBuffer* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	::jdk::internal::net::http::Http1Request* this$0 = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Request$StreamSubscriber_h_