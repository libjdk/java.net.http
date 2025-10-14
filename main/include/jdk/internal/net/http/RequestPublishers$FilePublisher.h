#ifndef _jdk_internal_net_http_RequestPublishers$FilePublisher_h_
#define _jdk_internal_net_http_RequestPublishers$FilePublisher_h_
//$ class jdk.internal.net.http.RequestPublishers$FilePublisher
//$ extends java.net.http.HttpRequest$BodyPublisher

#include <java/net/http/HttpRequest$BodyPublisher.h>

namespace java {
	namespace io {
		class InputStream;
	}
}
namespace java {
	namespace lang {
		class RuntimeException;
		class Throwable;
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
		class Permission;
	}
}
namespace java {
	namespace util {
		class Iterator;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Subscriber;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Function;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import RequestPublishers$FilePublisher : public ::java::net::http::HttpRequest$BodyPublisher {
	$class(RequestPublishers$FilePublisher, 0, ::java::net::http::HttpRequest$BodyPublisher)
public:
	RequestPublishers$FilePublisher();
	void init$(::java::nio::file::Path* name, int64_t length, ::java::util::function::Function* inputStreamSupplier);
	virtual int64_t contentLength() override;
	static ::jdk::internal::net::http::RequestPublishers$FilePublisher* create(::java::nio::file::Path* path);
	static ::java::io::InputStream* createInputStream(::java::nio::file::Path* path, ::java::security::AccessControlContext* acc, ::java::security::Permission* perm, bool defaultFS);
	static ::java::io::InputStream* lambda$create$0(::java::security::AccessControlContext* acc, ::java::security::Permission* perm, bool finalDefaultFS, ::java::nio::file::Path* p);
	static ::java::io::InputStream* lambda$createInputStream$1(::java::nio::file::Path* path);
	static ::java::io::InputStream* lambda$createInputStream$2(::java::nio::file::Path* path);
	static ::java::util::Iterator* lambda$subscribe$3(::java::io::InputStream* fis);
	static $String* pathForSecurityCheck(::java::nio::file::Path* path);
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	static ::java::lang::RuntimeException* toUncheckedException($Throwable* t);
	static bool $assertionsDisabled;
	::java::nio::file::Path* path = nullptr;
	int64_t length = 0;
	::java::util::function::Function* inputStreamSupplier = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$FilePublisher_h_