#ifndef _jdk_internal_net_http_ConnectionPool$CleanupTrigger_h_
#define _jdk_internal_net_http_ConnectionPool$CleanupTrigger_h_
//$ class jdk.internal.net.http.ConnectionPool$CleanupTrigger
//$ extends jdk.internal.net.http.common.FlowTube$TubeSubscriber
//$ implements jdk.internal.net.http.common.FlowTube$TubePublisher,java.util.concurrent.Flow$Subscription

#include <java/util/concurrent/Flow$Subscription.h>
#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>
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
			class Flow$Subscriber;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class ConnectionPool;
				class HttpConnection;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ConnectionPool$CleanupTrigger : public ::jdk::internal::net::http::common::FlowTube$TubeSubscriber, public ::jdk::internal::net::http::common::FlowTube$TubePublisher, public ::java::util::concurrent::Flow$Subscription {
	$class(ConnectionPool$CleanupTrigger, $NO_CLASS_INIT, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber, ::jdk::internal::net::http::common::FlowTube$TubePublisher, ::java::util::concurrent::Flow$Subscription)
public:
	ConnectionPool$CleanupTrigger();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$(::jdk::internal::net::http::ConnectionPool* this$0, ::jdk::internal::net::http::HttpConnection* connection);
	virtual void cancel() override;
	bool isDone();
	virtual void onComplete() override;
	virtual void onError($Throwable* error) override;
	void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	virtual void request(int64_t n) override;
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	virtual $String* toString() override;
	void triggerCleanup($Throwable* error);
	::jdk::internal::net::http::ConnectionPool* this$0 = nullptr;
	::jdk::internal::net::http::HttpConnection* connection = nullptr;
	$volatile(bool) done = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ConnectionPool$CleanupTrigger_h_