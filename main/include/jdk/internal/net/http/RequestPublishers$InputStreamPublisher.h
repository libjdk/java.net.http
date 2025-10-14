#ifndef _jdk_internal_net_http_RequestPublishers$InputStreamPublisher_h_
#define _jdk_internal_net_http_RequestPublishers$InputStreamPublisher_h_
//$ class jdk.internal.net.http.RequestPublishers$InputStreamPublisher
//$ extends java.net.http.HttpRequest$BodyPublisher

#include <java/net/http/HttpRequest$BodyPublisher.h>

namespace java {
	namespace io {
		class InputStream;
	}
}
namespace java {
	namespace lang {
		class Iterable;
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
			class Supplier;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import RequestPublishers$InputStreamPublisher : public ::java::net::http::HttpRequest$BodyPublisher {
	$class(RequestPublishers$InputStreamPublisher, $NO_CLASS_INIT, ::java::net::http::HttpRequest$BodyPublisher)
public:
	RequestPublishers$InputStreamPublisher();
	void init$(::java::util::function::Supplier* streamSupplier);
	virtual int64_t contentLength() override;
	virtual ::java::lang::Iterable* iterableOf(::java::io::InputStream* is);
	static ::java::util::Iterator* lambda$iterableOf$0(::java::io::InputStream* is);
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* subscriber) override;
	::java::util::function::Supplier* streamSupplier = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$InputStreamPublisher_h_