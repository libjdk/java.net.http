#ifndef _jdk_internal_net_http_Http1Exchange$DataPair_h_
#define _jdk_internal_net_http_Http1Exchange$DataPair_h_
//$ class jdk.internal.net.http.Http1Exchange$DataPair
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import Http1Exchange$DataPair : public ::java::lang::Object {
	$class(Http1Exchange$DataPair, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Http1Exchange$DataPair();
	void init$(::java::util::List* data, $Throwable* throwable);
	virtual $String* toString() override;
	$Throwable* throwable = nullptr;
	::java::util::List* data = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_Http1Exchange$DataPair_h_