#ifndef _jdk_internal_net_http_ResponseBodyHandlers$FileDownloadBodyHandler_h_
#define _jdk_internal_net_http_ResponseBodyHandlers$FileDownloadBodyHandler_h_
//$ class jdk.internal.net.http.ResponseBodyHandlers$FileDownloadBodyHandler
//$ extends java.net.http.HttpResponse$BodyHandler

#include <java/lang/Array.h>
#include <java/net/http/HttpResponse$BodyHandler.h>

#pragma push_macro("DISPOSITION_TYPE")
#undef DISPOSITION_TYPE
#pragma push_macro("FILENAME")
#undef FILENAME
#pragma push_macro("PROHIBITED")
#undef PROHIBITED

namespace java {
	namespace io {
		class FilePermission;
		class UncheckedIOException;
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
namespace java {
	namespace util {
		namespace regex {
			class Pattern;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import ResponseBodyHandlers$FileDownloadBodyHandler : public ::java::net::http::HttpResponse$BodyHandler {
	$class(ResponseBodyHandlers$FileDownloadBodyHandler, 0, ::java::net::http::HttpResponse$BodyHandler)
public:
	ResponseBodyHandlers$FileDownloadBodyHandler();
	void init$(::java::nio::file::Path* directory, ::java::util::List* openOptions, ::java::security::AccessControlContext* acc, $Array<::java::io::FilePermission>* filePermissions);
	virtual ::java::net::http::HttpResponse$BodySubscriber* apply(::java::net::http::HttpResponse$ResponseInfo* responseInfo) override;
	static ::jdk::internal::net::http::ResponseBodyHandlers$FileDownloadBodyHandler* create(::java::nio::file::Path* directory, ::java::util::List* openOptions);
	static ::java::io::UncheckedIOException* lambda$apply$0(::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::io::UncheckedIOException* unchecked(::java::net::http::HttpResponse$ResponseInfo* rinfo, $String* msg);
	static bool $assertionsDisabled;
	::java::nio::file::Path* directory = nullptr;
	::java::util::List* openOptions = nullptr;
	::java::security::AccessControlContext* acc = nullptr;
	$Array<::java::io::FilePermission>* filePermissions = nullptr;
	static $String* DISPOSITION_TYPE;
	static ::java::util::regex::Pattern* FILENAME;
	static ::java::util::List* PROHIBITED;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DISPOSITION_TYPE")
#pragma pop_macro("FILENAME")
#pragma pop_macro("PROHIBITED")

#endif // _jdk_internal_net_http_ResponseBodyHandlers$FileDownloadBodyHandler_h_