#ifndef _jdk_internal_net_http_Http2ClientImpl_h_
#define _jdk_internal_net_http_Http2ClientImpl_h_
//$ class jdk.internal.net.http.Http2ClientImpl
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("K")
#undef K
#pragma push_macro("STOPPED")
#undef STOPPED

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
	namespace util {
		class Map;
		class Set;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Exchange;
				class Http2Connection;
				class HttpClientImpl;
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
				namespace frame {
					class SettingsFrame;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http2ClientImpl : public ::java::lang::Object {
	$class(Http2ClientImpl, 0, ::java::lang::Object)
public:
	Http2ClientImpl();
	void init$(::jdk::internal::net::http::HttpClientImpl* client);
	virtual ::jdk::internal::net::http::HttpClientImpl* client();
	void close(::jdk::internal::net::http::Http2Connection* h2c);
	virtual void deleteConnection(::jdk::internal::net::http::Http2Connection* c);
	virtual ::jdk::internal::net::http::frame::SettingsFrame* getClientSettings();
	virtual ::java::util::concurrent::CompletableFuture* getConnectionFor(::jdk::internal::net::http::HttpRequestImpl* req, ::jdk::internal::net::http::Exchange* exchange);
	virtual int32_t getConnectionWindowSize(::jdk::internal::net::http::frame::SettingsFrame* clientSettings);
	static int32_t getParameter($String* property, int32_t min, int32_t max, int32_t defaultValue);
	virtual $String* getSettingsString();
	void lambda$getConnectionFor$0($String* key, ::jdk::internal::net::http::Http2Connection* conn, $Throwable* t);
	virtual bool offerConnection(::jdk::internal::net::http::Http2Connection* c);
	virtual void stop();
	static ::jdk::internal::net::http::common::Logger* debug;
	::jdk::internal::net::http::HttpClientImpl* client$ = nullptr;
	::java::util::Map* connections = nullptr;
	::java::util::Set* failures = nullptr;
	::java::io::EOFException* STOPPED = nullptr;
	static const int32_t K = 1024;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("K")
#pragma pop_macro("STOPPED")

#endif // _jdk_internal_net_http_Http2ClientImpl_h_