#ifndef _jdk_internal_net_http_ResponseBodyHandlers$PathBodyHandler_h_
#define _jdk_internal_net_http_ResponseBodyHandlers$PathBodyHandler_h_
//$ class jdk.internal.net.http.ResponseBodyHandlers$PathBodyHandler
//$ extends java.net.http.HttpResponse$BodyHandler

#include <java/net/http/HttpResponse$BodyHandler.h>

namespace java {
	namespace io {
		class FilePermission;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpResponse$BodySubscriber;
			class HttpResponse$ResponseInfo;
		}
	}
}
namespace java {
	namespace nio {
		namespace file {
			class Path;
		}
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
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

class $import ResponseBodyHandlers$PathBodyHandler : public ::java::net::http::HttpResponse$BodyHandler {
	$class(ResponseBodyHandlers$PathBodyHandler, 0, ::java::net::http::HttpResponse$BodyHandler)
public:
	ResponseBodyHandlers$PathBodyHandler();
	void init$(::java::nio::file::Path* file, ::java::util::List* openOptions, ::java::security::AccessControlContext* acc, ::java::io::FilePermission* filePermission);
	virtual ::java::net::http::HttpResponse$BodySubscriber* apply(::java::net::http::HttpResponse$ResponseInfo* responseInfo) override;
	static ::jdk::internal::net::http::ResponseBodyHandlers$PathBodyHandler* create(::java::nio::file::Path* file, ::java::util::List* openOptions);
	static bool $assertionsDisabled;
	::java::nio::file::Path* file = nullptr;
	::java::util::List* openOptions = nullptr;
	::java::security::AccessControlContext* acc = nullptr;
	::java::io::FilePermission* filePermission = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseBodyHandlers$PathBodyHandler_h_