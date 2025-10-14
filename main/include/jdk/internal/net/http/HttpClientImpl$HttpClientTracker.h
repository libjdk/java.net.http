#ifndef _jdk_internal_net_http_HttpClientImpl$HttpClientTracker_h_
#define _jdk_internal_net_http_HttpClientImpl$HttpClientTracker_h_
//$ class jdk.internal.net.http.HttpClientImpl$HttpClientTracker
//$ extends jdk.internal.net.http.common.OperationTrackers$Tracker

#include <jdk/internal/net/http/common/OperationTrackers$Tracker.h>

namespace java {
	namespace lang {
		namespace ref {
			class Reference;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import HttpClientImpl$HttpClientTracker : public ::jdk::internal::net::http::common::OperationTrackers$Tracker {
	$class(HttpClientImpl$HttpClientTracker, $NO_CLASS_INIT, ::jdk::internal::net::http::common::OperationTrackers$Tracker)
public:
	HttpClientImpl$HttpClientTracker();
	void init$(::java::util::concurrent::atomic::AtomicLong* http, ::java::util::concurrent::atomic::AtomicLong* http2, ::java::util::concurrent::atomic::AtomicLong* ws, ::java::util::concurrent::atomic::AtomicLong* ops, ::java::lang::ref::Reference* ref, $String* name);
	virtual $String* getName() override;
	virtual int64_t getOutstandingHttp2Streams() override;
	virtual int64_t getOutstandingHttpOperations() override;
	virtual int64_t getOutstandingOperations() override;
	virtual int64_t getOutstandingWebSocketOperations() override;
	virtual bool isFacadeReferenced() override;
	::java::util::concurrent::atomic::AtomicLong* httpCount = nullptr;
	::java::util::concurrent::atomic::AtomicLong* http2Count = nullptr;
	::java::util::concurrent::atomic::AtomicLong* websocketCount = nullptr;
	::java::util::concurrent::atomic::AtomicLong* operationsCount = nullptr;
	::java::lang::ref::Reference* reference = nullptr;
	$String* name = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpClientImpl$HttpClientTracker_h_