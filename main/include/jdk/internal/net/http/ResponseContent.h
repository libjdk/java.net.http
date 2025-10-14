#ifndef _jdk_internal_net_http_ResponseContent_h_
#define _jdk_internal_net_http_ResponseContent_h_
//$ class jdk.internal.net.http.ResponseContent
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("CR")
#undef CR
#pragma push_macro("LF")
#undef LF
#pragma push_macro("MAX_CHUNK_HEADER_SIZE")
#undef MAX_CHUNK_HEADER_SIZE

namespace java {
	namespace lang {
		class Runnable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
			class HttpResponse$BodySubscriber;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Consumer;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpConnection;
				class ResponseContent$BodyParser;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import ResponseContent : public ::java::lang::Object {
	$class(ResponseContent, $NO_CLASS_INIT, ::java::lang::Object)
public:
	ResponseContent();
	void init$(::jdk::internal::net::http::HttpConnection* connection, int64_t contentLength, ::java::net::http::HttpHeaders* h, ::java::net::http::HttpResponse$BodySubscriber* userSubscriber, ::java::lang::Runnable* onFinished);
	virtual bool contentChunked();
	virtual ::jdk::internal::net::http::ResponseContent$BodyParser* getBodyParser(::java::util::function::Consumer* onComplete);
	::java::net::http::HttpResponse$BodySubscriber* pusher = nullptr;
	int64_t contentLength = 0;
	::java::net::http::HttpHeaders* headers = nullptr;
	::java::lang::Runnable* onFinished = nullptr;
	$String* dbgTag = nullptr;
	static const int32_t LF = 10;
	static const int32_t CR = 13;
	bool chunkedContent = false;
	bool chunkedContentInitialized = false;
	static const int32_t MAX_CHUNK_HEADER_SIZE = 2050;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("CR")
#pragma pop_macro("LF")
#pragma pop_macro("MAX_CHUNK_HEADER_SIZE")

#endif // _jdk_internal_net_http_ResponseContent_h_