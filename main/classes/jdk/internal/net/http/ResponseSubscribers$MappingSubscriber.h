#ifndef _jdk_internal_net_http_ResponseSubscribers$MappingSubscriber_h_
#define _jdk_internal_net_http_ResponseSubscribers$MappingSubscriber_h_
//$ class jdk.internal.net.http.ResponseSubscribers$MappingSubscriber
//$ extends jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber

#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpResponse$BodySubscriber;
		}
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

class $export ResponseSubscribers$MappingSubscriber : public ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber {
	$class(ResponseSubscribers$MappingSubscriber, $NO_CLASS_INIT, ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber)
public:
	ResponseSubscribers$MappingSubscriber();
	void init$(::java::net::http::HttpResponse$BodySubscriber* upstream, ::java::util::function::Function* mapper);
	void init$(::java::net::http::HttpResponse$BodySubscriber* upstream, ::java::util::function::Function* mapper, bool trusted);
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	virtual bool needsExecutor() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	virtual void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	::java::net::http::HttpResponse$BodySubscriber* upstream = nullptr;
	::java::util::function::Function* mapper = nullptr;
	bool trusted = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers$MappingSubscriber_h_