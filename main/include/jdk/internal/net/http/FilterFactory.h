#ifndef _jdk_internal_net_http_FilterFactory_h_
#define _jdk_internal_net_http_FilterFactory_h_
//$ class jdk.internal.net.http.FilterFactory
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace util {
		class LinkedList;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import FilterFactory : public ::java::lang::Object {
	$class(FilterFactory, $NO_CLASS_INIT, ::java::lang::Object)
public:
	FilterFactory();
	void init$();
	virtual void addFilter($Class* type);
	virtual ::java::util::LinkedList* getFilterChain();
	::java::util::LinkedList* filterClasses = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_FilterFactory_h_