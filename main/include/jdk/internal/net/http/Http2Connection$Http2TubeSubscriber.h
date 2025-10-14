#ifndef _jdk_internal_net_http_Http2Connection$Http2TubeSubscriber_h_
#define _jdk_internal_net_http_Http2Connection$Http2TubeSubscriber_h_
//$ class jdk.internal.net.http.Http2Connection$Http2TubeSubscriber
//$ extends jdk.internal.net.http.common.FlowTube$TubeSubscriber

#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>

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
			class ConcurrentLinkedQueue;
			class Flow$Subscription;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http2Connection;
				class HttpClientImpl;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SequentialScheduler;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http2Connection$Http2TubeSubscriber : public ::jdk::internal::net::http::common::FlowTube$TubeSubscriber {
	$class(Http2Connection$Http2TubeSubscriber, 0, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber)
public:
	Http2Connection$Http2TubeSubscriber();
	void init$(::jdk::internal::net::http::Http2Connection* this$0, ::jdk::internal::net::http::HttpClientImpl* client);
	virtual void dropSubscription() override;
	static $String* lambda$onError$1($Throwable* throwable);
	static $String* lambda$onNext$0(::java::util::List* item);
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	void processQueue();
	void runOrSchedule();
	::jdk::internal::net::http::Http2Connection* this$0 = nullptr;
	static bool $assertionsDisabled;
	$volatile(::java::util::concurrent::Flow$Subscription*) subscription = nullptr;
	$volatile(bool) completed = false;
	$volatile(bool) dropped = false;
	$volatile($Throwable*) error = nullptr;
	::java::util::concurrent::ConcurrentLinkedQueue* queue = nullptr;
	::jdk::internal::net::http::common::SequentialScheduler* scheduler = nullptr;
	::jdk::internal::net::http::HttpClientImpl* client = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http2Connection$Http2TubeSubscriber_h_