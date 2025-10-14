#ifndef _jdk_internal_net_http_common_OperationTrackers$Tracker_h_
#define _jdk_internal_net_http_common_OperationTrackers$Tracker_h_
//$ interface jdk.internal.net.http.common.OperationTrackers$Tracker
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export OperationTrackers$Tracker : public ::java::lang::Object {
	$interface(OperationTrackers$Tracker, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual $String* getName() {return nullptr;}
	virtual int64_t getOutstandingHttp2Streams() {return 0;}
	virtual int64_t getOutstandingHttpOperations() {return 0;}
	virtual int64_t getOutstandingOperations() {return 0;}
	virtual int64_t getOutstandingWebSocketOperations() {return 0;}
	virtual bool isFacadeReferenced() {return false;}
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_OperationTrackers$Tracker_h_