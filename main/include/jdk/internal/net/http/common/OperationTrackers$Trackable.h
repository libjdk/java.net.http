#ifndef _jdk_internal_net_http_common_OperationTrackers$Trackable_h_
#define _jdk_internal_net_http_common_OperationTrackers$Trackable_h_
//$ interface jdk.internal.net.http.common.OperationTrackers$Trackable
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class OperationTrackers$Tracker;
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

class $import OperationTrackers$Trackable : public ::java::lang::Object {
	$interface(OperationTrackers$Trackable, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::jdk::internal::net::http::common::OperationTrackers$Tracker* getOperationsTracker() {return nullptr;}
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_OperationTrackers$Trackable_h_