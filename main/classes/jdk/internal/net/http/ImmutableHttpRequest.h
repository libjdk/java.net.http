#ifndef _jdk_internal_net_http_ImmutableHttpRequest_h_
#define _jdk_internal_net_http_ImmutableHttpRequest_h_
//$ class jdk.internal.net.http.ImmutableHttpRequest
//$ extends java.net.http.HttpRequest

#include <java/net/http/HttpRequest.h>

namespace java {
	namespace net {
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
		}
	}
}
namespace java {
	namespace util {
		class Optional;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpRequestBuilderImpl;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ImmutableHttpRequest : public ::java::net::http::HttpRequest {
	$class(ImmutableHttpRequest, $NO_CLASS_INIT, ::java::net::http::HttpRequest)
public:
	ImmutableHttpRequest();
	void init$(::jdk::internal::net::http::HttpRequestBuilderImpl* builder);
	virtual ::java::util::Optional* bodyPublisher() override;
	virtual bool expectContinue() override;
	virtual ::java::net::http::HttpHeaders* headers() override;
	virtual $String* method() override;
	virtual ::java::util::Optional* timeout() override;
	virtual $String* toString() override;
	virtual ::java::net::URI* uri() override;
	virtual ::java::util::Optional* version() override;
	$String* method$ = nullptr;
	::java::net::URI* uri$ = nullptr;
	::java::net::http::HttpHeaders* headers$ = nullptr;
	::java::util::Optional* requestPublisher = nullptr;
	bool expectContinue$ = false;
	::java::util::Optional* timeout$ = nullptr;
	::java::util::Optional* version$ = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ImmutableHttpRequest_h_