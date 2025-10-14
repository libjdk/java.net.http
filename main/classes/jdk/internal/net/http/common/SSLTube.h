#ifndef _jdk_internal_net_http_common_SSLTube_h_
#define _jdk_internal_net_http_common_SSLTube_h_
//$ class jdk.internal.net.http.common.SSLTube
//$ extends jdk.internal.net.http.common.FlowTube

#include <jdk/internal/net/http/common/FlowTube.h>

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
			class Executor;
			class Flow$Subscriber;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Consumer;
		}
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLEngine;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Demand;
					class FlowTube$TubePublisher;
					class FlowTube$TubeSubscriber;
					class Logger;
					class SSLFlowDelegate;
					class SSLTube$SSLSubscriberWrapper;
					class SSLTube$SSLSubscriptionWrapper;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export SSLTube : public ::jdk::internal::net::http::common::FlowTube {
	$class(SSLTube, 0, ::jdk::internal::net::http::common::FlowTube)
public:
	SSLTube();
	void init$(::javax::net::ssl::SSLEngine* engine, ::java::util::concurrent::Executor* executor, ::jdk::internal::net::http::common::FlowTube* tube);
	void init$(::javax::net::ssl::SSLEngine* engine, ::java::util::concurrent::Executor* executor, ::java::util::function::Consumer* recycler, ::jdk::internal::net::http::common::FlowTube* tube);
	virtual $Throwable* checkForHandshake($Throwable* t);
	virtual void connectFlows(::jdk::internal::net::http::common::FlowTube$TubePublisher* writePub, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber* readSub) override;
	$String* dbgString();
	virtual ::java::util::concurrent::CompletableFuture* getALPN();
	$String* handshakeFailed();
	bool handshaking();
	virtual bool isFinished() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	virtual void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* s) override;
	virtual $String* toString() override;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	::jdk::internal::net::http::common::FlowTube* tube = nullptr;
	::jdk::internal::net::http::common::SSLTube$SSLSubscriberWrapper* readSubscriber = nullptr;
	::jdk::internal::net::http::common::SSLTube$SSLSubscriptionWrapper* writeSubscription = nullptr;
	::jdk::internal::net::http::common::SSLFlowDelegate* sslDelegate = nullptr;
	::javax::net::ssl::SSLEngine* engine = nullptr;
	$volatile(bool) finished = false;
	$volatile(::java::util::concurrent::Flow$Subscription*) readSubscription = nullptr;
	::jdk::internal::net::http::common::Demand* writeDemand = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLTube_h_