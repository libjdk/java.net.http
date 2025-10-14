#ifndef _jdk_internal_net_http_LineSubscriberAdapter_h_
#define _jdk_internal_net_http_LineSubscriberAdapter_h_
//$ class jdk.internal.net.http.LineSubscriberAdapter
//$ extends java.net.http.HttpResponse$BodySubscriber

#include <java/net/http/HttpResponse$BodySubscriber.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace nio {
		namespace charset {
			class Charset;
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
			class CompletableFuture;
			class CompletionStage;
			class Flow$Subscriber;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicBoolean;
			}
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
				class LineSubscriberAdapter$LineSubscription;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import LineSubscriberAdapter : public ::java::net::http::HttpResponse$BodySubscriber {
	$class(LineSubscriberAdapter, $NO_CLASS_INIT, ::java::net::http::HttpResponse$BodySubscriber)
public:
	LineSubscriberAdapter();
	void init$(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::function::Function* finisher, ::java::nio::charset::Charset* charset, $String* eol);
	static ::jdk::internal::net::http::LineSubscriberAdapter* create(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::function::Function* finisher, ::java::nio::charset::Charset* charset, $String* eol);
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	::java::util::concurrent::CompletableFuture* cf = nullptr;
	::java::util::concurrent::Flow$Subscriber* subscriber = nullptr;
	::java::util::function::Function* finisher = nullptr;
	::java::nio::charset::Charset* charset = nullptr;
	$String* eol = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* subscribed = nullptr;
	$volatile(::jdk::internal::net::http::LineSubscriberAdapter$LineSubscription*) downstream = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_LineSubscriberAdapter_h_