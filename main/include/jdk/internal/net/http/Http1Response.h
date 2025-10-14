#ifndef _jdk_internal_net_http_Http1Response_h_
#define _jdk_internal_net_http_Http1Response_h_
//$ class jdk.internal.net.http.Http1Response
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("MAX_IGNORE")
#undef MAX_IGNORE
#pragma push_macro("NOP")
#undef NOP

namespace java {
	namespace io {
		class EOFException;
	}
}
namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
			class HttpResponse;
			class HttpResponse$BodySubscriber;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
			class Executor;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http1AsyncReceiver;
				class Http1Exchange;
				class Http1HeaderParser;
				class Http1Response$BodyReader;
				class Http1Response$ClientRefCountTracker;
				class Http1Response$HeadersReader;
				class Http1Response$Http1BodySubscriber;
				class Http1Response$Receiver;
				class Http1Response$State;
				class HttpConnection;
				class HttpRequestImpl;
				class Response;
				class ResponseContent;
				class ResponseContent$BodyParser;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
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

class $import Http1Response : public ::java::lang::Object {
	$class(Http1Response, 0, ::java::lang::Object)
public:
	Http1Response();
	void init$(::jdk::internal::net::http::HttpConnection* conn, ::jdk::internal::net::http::Http1Exchange* exchange, ::jdk::internal::net::http::Http1AsyncReceiver* asyncReceiver);
	::jdk::internal::net::http::Http1Response$State* advance(::jdk::internal::net::http::Http1Response$State* previous);
	virtual void completed();
	$String* dbgString();
	virtual bool finished();
	virtual int64_t fixupContentLen(int64_t clen);
	virtual ::java::util::concurrent::CompletableFuture* ignoreBody(::java::util::concurrent::Executor* executor);
	static $String* lambda$onReadError$6(::java::util::concurrent::CompletableFuture* cf);
	static $String* lambda$onReadError$7($Throwable* t);
	void lambda$readBody$1(::jdk::internal::net::http::Http1Response$Http1BodySubscriber* subscriber, ::java::util::concurrent::CompletableFuture* cf, $Throwable* t);
	void lambda$readBody$2(::jdk::internal::net::http::Http1Response$Http1BodySubscriber* subscriber, ::java::util::concurrent::CompletableFuture* cf, ::jdk::internal::net::http::Http1Response$ClientRefCountTracker* refCountTracker, ::jdk::internal::net::http::Http1Response$State* s, $Throwable* t);
	void lambda$readBody$3(int64_t clen, ::jdk::internal::net::http::Http1Response$Http1BodySubscriber* subscriber, ::java::util::concurrent::CompletableFuture* cf, ::jdk::internal::net::http::Http1Response$ClientRefCountTracker* refCountTracker);
	void lambda$readBody$4(::java::util::concurrent::CompletableFuture* cf, $Throwable* t);
	static void lambda$readBody$5(::jdk::internal::net::http::Http1Response$ClientRefCountTracker* refCountTracker, Object$* s, $Throwable* t);
	::jdk::internal::net::http::Response* lambda$readHeadersAsync$0(::jdk::internal::net::http::Http1Response$State* completed);
	virtual void nullBody(::java::net::http::HttpResponse* resp, $Throwable* t);
	void onFinished();
	virtual void onReadError($Throwable* t);
	virtual ::java::util::concurrent::CompletableFuture* readBody(::java::net::http::HttpResponse$BodySubscriber* p, bool return2Cache, ::java::util::concurrent::Executor* executor);
	virtual ::java::util::concurrent::CompletableFuture* readHeadersAsync(::java::util::concurrent::Executor* executor);
	virtual ::jdk::internal::net::http::Http1Response$Receiver* receiver(::jdk::internal::net::http::Http1Response$State* state);
	virtual int32_t responseCode();
	virtual ::java::net::http::HttpHeaders* responseHeaders();
	static bool $assertionsDisabled;
	$volatile(::jdk::internal::net::http::ResponseContent*) content = nullptr;
	::jdk::internal::net::http::HttpRequestImpl* request = nullptr;
	::jdk::internal::net::http::Response* response = nullptr;
	::jdk::internal::net::http::HttpConnection* connection = nullptr;
	::java::net::http::HttpHeaders* headers = nullptr;
	int32_t responseCode$ = 0;
	::jdk::internal::net::http::Http1Exchange* exchange = nullptr;
	bool return2Cache = false;
	::jdk::internal::net::http::Http1Response$HeadersReader* headersReader = nullptr;
	::jdk::internal::net::http::Http1Response$BodyReader* bodyReader = nullptr;
	::jdk::internal::net::http::Http1AsyncReceiver* asyncReceiver = nullptr;
	$volatile(::java::io::EOFException*) eof = nullptr;
	$volatile(::jdk::internal::net::http::ResponseContent$BodyParser*) bodyParser = nullptr;
	static const int32_t MAX_IGNORE = 1024;
	$volatile(::jdk::internal::net::http::Http1Response$State*) readProgress = nullptr;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	static ::java::util::concurrent::atomic::AtomicLong* responseCount;
	int64_t id = 0;
	::jdk::internal::net::http::Http1HeaderParser* hd = nullptr;
	$String* dbgTag = nullptr;
	$volatile(bool) firstTimeAround = false;
	bool finished$ = false;
	static ::java::util::concurrent::Flow$Subscription* NOP;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("MAX_IGNORE")
#pragma pop_macro("NOP")

#endif // _jdk_internal_net_http_Http1Response_h_