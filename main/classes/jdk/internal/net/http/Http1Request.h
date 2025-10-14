#ifndef _jdk_internal_net_http_Http1Request_h_
#define _jdk_internal_net_http_Http1Request_h_
//$ class jdk.internal.net.http.Http1Request
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("COOKIE_HEADER")
#undef COOKIE_HEADER
#pragma push_macro("CRLF")
#undef CRLF
#pragma push_macro("EMPTY_CHUNK_BYTES")
#undef EMPTY_CHUNK_BYTES
#pragma push_macro("NOCOOKIES")
#undef NOCOOKIES

namespace java {
	namespace lang {
		class StringBuilder;
	}
}
namespace java {
	namespace net {
		class InetSocketAddress;
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
			class HttpRequest$BodyPublisher;
		}
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		class List;
	}
}
namespace java {
	namespace util {
		namespace function {
			class BiPredicate;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http1Exchange;
				class Http1Exchange$Http1BodySubscriber;
				class HttpConnection;
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
					class Logger;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1Request : public ::java::lang::Object {
	$class(Http1Request, 0, ::java::lang::Object)
public:
	Http1Request();
	void init$(::jdk::internal::net::http::HttpRequestImpl* request, ::jdk::internal::net::http::Http1Exchange* http1Exchange);
	$String* authorityString(::java::net::InetSocketAddress* addr);
	void collectCookies(::java::lang::StringBuilder* sb, ::java::net::http::HttpHeaders* system, ::java::net::http::HttpHeaders* user);
	virtual void collectHeaders0(::java::lang::StringBuilder* sb);
	void collectHeaders1(::java::lang::StringBuilder* sb, ::java::net::http::HttpHeaders* headers, ::java::util::function::BiPredicate* filter);
	virtual ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber* continueRequest();
	virtual bool finished();
	static ::java::nio::ByteBuffer* getHeader(int32_t size);
	$String* getPathAndQuery(::java::net::URI* uri);
	virtual ::java::util::List* headers();
	$String* hostString();
	static bool lambda$collectHeaders0$1(::java::net::http::HttpHeaders* uh, $String* k, $String* v);
	static bool lambda$static$0($String* k, $String* v);
	void logHeaders($String* completeHeaders);
	$String* requestURI();
	virtual void setFinished();
	static $String* COOKIE_HEADER;
	static ::java::util::function::BiPredicate* NOCOOKIES;
	::jdk::internal::net::http::HttpRequestImpl* request = nullptr;
	::jdk::internal::net::http::Http1Exchange* http1Exchange = nullptr;
	::jdk::internal::net::http::HttpConnection* connection = nullptr;
	::java::net::http::HttpRequest$BodyPublisher* requestPublisher = nullptr;
	$volatile(::java::net::http::HttpHeaders*) userHeaders = nullptr;
	::jdk::internal::net::http::common::HttpHeadersBuilder* systemHeadersBuilder = nullptr;
	$volatile(bool) streaming = false;
	$volatile(int64_t) contentLength = 0;
	bool finished$ = false;
	static $bytes* CRLF;
	static $bytes* EMPTY_CHUNK_BYTES;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("COOKIE_HEADER")
#pragma pop_macro("CRLF")
#pragma pop_macro("EMPTY_CHUNK_BYTES")
#pragma pop_macro("NOCOOKIES")

#endif // _jdk_internal_net_http_Http1Request_h_