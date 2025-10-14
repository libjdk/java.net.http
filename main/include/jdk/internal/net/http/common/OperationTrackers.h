#ifndef _jdk_internal_net_http_common_OperationTrackers_h_
#define _jdk_internal_net_http_common_OperationTrackers_h_
//$ class jdk.internal.net.http.common.OperationTrackers
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		namespace http {
			class HttpClient;
		}
	}
}
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

class $import OperationTrackers : public ::java::lang::Object {
	$class(OperationTrackers, $NO_CLASS_INIT, ::java::lang::Object)
public:
	OperationTrackers();
	void init$();
	static ::jdk::internal::net::http::common::OperationTrackers$Tracker* getTracker(::java::net::http::HttpClient* client);
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_OperationTrackers_h_