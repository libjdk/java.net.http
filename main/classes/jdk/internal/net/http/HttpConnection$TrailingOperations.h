#ifndef _jdk_internal_net_http_HttpConnection$TrailingOperations_h_
#define _jdk_internal_net_http_HttpConnection$TrailingOperations_h_
//$ class jdk.internal.net.http.HttpConnection$TrailingOperations
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace util {
		class Map;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletionStage;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export HttpConnection$TrailingOperations : public ::java::lang::Object {
	$class(HttpConnection$TrailingOperations, $NO_CLASS_INIT, ::java::lang::Object)
public:
	HttpConnection$TrailingOperations();
	void init$();
	void add(::java::util::concurrent::CompletionStage* cf);
	void lambda$add$0(::java::util::concurrent::CompletionStage* cf, Object$* r, $Throwable* t);
	bool remove(::java::util::concurrent::CompletionStage* cf);
	::java::util::Map* operations = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpConnection$TrailingOperations_h_