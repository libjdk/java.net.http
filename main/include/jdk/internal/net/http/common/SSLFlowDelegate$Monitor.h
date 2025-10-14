#ifndef _jdk_internal_net_http_common_SSLFlowDelegate$Monitor_h_
#define _jdk_internal_net_http_common_SSLFlowDelegate$Monitor_h_
//$ class jdk.internal.net.http.common.SSLFlowDelegate$Monitor
//$ extends java.lang.Thread

#include <java/lang/Thread.h>

namespace java {
	namespace lang {
		namespace ref {
			class ReferenceQueue;
		}
	}
}
namespace java {
	namespace util {
		class List;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class SSLFlowDelegate$Monitorable;
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

class $import SSLFlowDelegate$Monitor : public ::java::lang::Thread {
	$class(SSLFlowDelegate$Monitor, 0, ::java::lang::Thread)
public:
	SSLFlowDelegate$Monitor();
	void init$();
	static void add(::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable* o);
	virtual void addTarget(::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable* o);
	static void remove(::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable* o);
	virtual void removeTarget(::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable* o);
	virtual void run() override;
	::java::util::List* list = nullptr;
	::java::util::List* finalList = nullptr;
	::java::lang::ref::ReferenceQueue* queue = nullptr;
	static ::jdk::internal::net::http::common::SSLFlowDelegate$Monitor* themon;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLFlowDelegate$Monitor_h_