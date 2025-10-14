#ifndef _jdk_internal_net_http_ResponseSubscribers_h_
#define _jdk_internal_net_http_ResponseSubscribers_h_
//$ class jdk.internal.net.http.ResponseSubscribers
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace io {
		class InputStream;
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
			class HttpResponse$BodySubscriber;
		}
	}
}
namespace java {
	namespace nio {
		namespace charset {
			class Charset;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
			class CompletionStage;
			class Executor;
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
namespace java {
	namespace util {
		namespace stream {
			class Stream;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ResponseSubscribers : public ::java::lang::Object {
	$class(ResponseSubscribers, 0, ::java::lang::Object)
public:
	ResponseSubscribers();
	void init$();
	static ::java::net::http::HttpResponse$BodySubscriber* createLineStream();
	static ::java::net::http::HttpResponse$BodySubscriber* createLineStream(::java::nio::charset::Charset* charset);
	static ::java::net::http::HttpResponse$BodySubscriber* createPublisher();
	static ::java::util::concurrent::CompletionStage* getBodyAsync(::java::util::concurrent::Executor* e, ::java::net::http::HttpResponse$BodySubscriber* bs);
	static ::java::util::concurrent::CompletableFuture* getBodyAsync(::java::util::concurrent::Executor* e, ::java::net::http::HttpResponse$BodySubscriber* bs, ::java::util::concurrent::CompletableFuture* cf);
	static ::java::util::concurrent::CompletableFuture* getBodyAsync(::java::util::concurrent::Executor* e, ::java::net::http::HttpResponse$BodySubscriber* bs, ::java::util::concurrent::CompletableFuture* cf, ::java::util::function::Consumer* errorHandler);
	static void lambda$createLineStream$0(::java::io::InputStream* stream);
	static ::java::util::stream::Stream* lambda$createLineStream$1(::java::nio::charset::Charset* charset, ::java::io::InputStream* stream);
	static void lambda$getBodyAsync$2(::java::util::concurrent::CompletableFuture* cf, Object$* r, $Throwable* t);
	static void lambda$getBodyAsync$3(::java::net::http::HttpResponse$BodySubscriber* bs, ::java::util::concurrent::CompletableFuture* cf, ::java::util::function::Consumer* errorHandler);
	static bool $assertionsDisabled;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_ResponseSubscribers_h_