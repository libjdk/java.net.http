#ifndef _jdk_internal_net_http_HttpRequestBuilderImpl_h_
#define _jdk_internal_net_http_HttpRequestBuilderImpl_h_
//$ class jdk.internal.net.http.HttpRequestBuilderImpl
//$ extends java.net.http.HttpRequest$Builder

#include <java/lang/Array.h>
#include <java/net/http/HttpRequest$Builder.h>

#pragma push_macro("DELETE")
#undef DELETE
#pragma push_macro("GET")
#undef GET
#pragma push_macro("POST")
#undef POST
#pragma push_macro("PUT")
#undef PUT

namespace java {
	namespace net {
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient$Version;
			class HttpRequest;
			class HttpRequest$BodyPublisher;
		}
	}
}
namespace java {
	namespace time {
		class Duration;
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
				class HttpRequestImpl;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class HttpHeadersBuilder;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import HttpRequestBuilderImpl : public ::java::net::http::HttpRequest$Builder {
	$class(HttpRequestBuilderImpl, 0, ::java::net::http::HttpRequest$Builder)
public:
	HttpRequestBuilderImpl();
	void init$(::java::net::URI* uri);
	void init$();
	virtual ::java::net::http::HttpRequest$Builder* DELETE() override;
	virtual ::java::net::http::HttpRequest$Builder* GET() override;
	virtual ::java::net::http::HttpRequest$Builder* POST(::java::net::http::HttpRequest$BodyPublisher* body) override;
	virtual ::java::net::http::HttpRequest$Builder* PUT(::java::net::http::HttpRequest$BodyPublisher* body) override;
	virtual ::java::net::http::HttpRequest$BodyPublisher* bodyPublisher();
	virtual ::java::net::http::HttpRequest* build() override;
	virtual ::jdk::internal::net::http::HttpRequestImpl* buildForWebSocket();
	void checkNameAndValue($String* name, $String* value);
	static void checkURI(::java::net::URI* uri);
	virtual ::jdk::internal::net::http::HttpRequestBuilderImpl* copy() override;
	virtual ::jdk::internal::net::http::HttpRequestBuilderImpl* expectContinue(bool enable) override;
	virtual bool expectContinue();
	virtual ::jdk::internal::net::http::HttpRequestBuilderImpl* header($String* name, $String* value) override;
	virtual ::jdk::internal::net::http::HttpRequestBuilderImpl* headers($StringArray* params) override;
	virtual ::jdk::internal::net::http::common::HttpHeadersBuilder* headersBuilder();
	virtual $String* method();
	virtual ::java::net::http::HttpRequest$Builder* method($String* method, ::java::net::http::HttpRequest$BodyPublisher* body) override;
	::java::net::http::HttpRequest$Builder* method0($String* method, ::java::net::http::HttpRequest$BodyPublisher* body);
	virtual ::jdk::internal::net::http::HttpRequestBuilderImpl* setHeader($String* name, $String* value) override;
	virtual ::java::net::http::HttpRequest$Builder* timeout(::java::time::Duration* duration) override;
	virtual ::java::time::Duration* timeout();
	virtual ::jdk::internal::net::http::HttpRequestBuilderImpl* uri(::java::net::URI* uri) override;
	virtual ::java::net::URI* uri();
	virtual ::jdk::internal::net::http::HttpRequestBuilderImpl* version(::java::net::http::HttpClient$Version* version) override;
	virtual ::java::util::Optional* version();
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::HttpHeadersBuilder* headersBuilder$ = nullptr;
	::java::net::URI* uri$ = nullptr;
	$String* method$ = nullptr;
	bool expectContinue$ = false;
	::java::net::http::HttpRequest$BodyPublisher* bodyPublisher$ = nullptr;
	$volatile(::java::util::Optional*) version$ = nullptr;
	::java::time::Duration* duration = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DELETE")
#pragma pop_macro("GET")
#pragma pop_macro("POST")
#pragma pop_macro("PUT")

#endif // _jdk_internal_net_http_HttpRequestBuilderImpl_h_