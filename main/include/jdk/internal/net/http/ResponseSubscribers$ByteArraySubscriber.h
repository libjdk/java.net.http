#ifndef _jdk_internal_net_http_ResponseSubscribers$ByteArraySubscriber_h_
#define _jdk_internal_net_http_ResponseSubscribers$ByteArraySubscriber_h_
//$ class jdk.internal.net.http.ResponseSubscribers$ByteArraySubscriber
//$ extends jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber

#include <java/lang/Array.h>
#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace util {
		class List;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
			class CompletionStage;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Function;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import ResponseSubscribers$ByteArraySubscriber : public ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber {
	$class(ResponseSubscribers$ByteArraySubscriber, 0, ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber)
public:
	ResponseSubscribers$ByteArraySubscriber();
	void init$(::java::util::function::Function* finisher);
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	static $bytes* join(::java::util::List* bytes);
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	virtual void onNext(::java::util::List* items);
	virtual void onNext(Object$* items) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	static bool $assertionsDisabled;
	::java::util::function::Function* finisher = nullptr;
	::java::util::concurrent::CompletableFuture* result = nullptr;
	::java::util::List* received = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscription*) subscription = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers$ByteArraySubscriber_h_