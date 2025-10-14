#ifndef _jdk_internal_net_http_websocket_BuilderImpl_h_
#define _jdk_internal_net_http_websocket_BuilderImpl_h_
//$ class jdk.internal.net.http.websocket.BuilderImpl
//$ extends java.net.http.WebSocket$Builder

#include <java/lang/Array.h>
#include <java/net/http/WebSocket$Builder.h>

namespace java {
	namespace net {
		class ProxySelector;
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient;
			class WebSocket$Listener;
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
		class Collection;
		class Optional;
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
				namespace websocket {

class BuilderImpl : public ::java::net::http::WebSocket$Builder {
	$class(BuilderImpl, 0, ::java::net::http::WebSocket$Builder)
public:
	BuilderImpl();
	void init$(::java::net::http::HttpClient* client, ::java::net::ProxySelector* proxySelector);
	void init$(::java::net::http::HttpClient* client, ::java::net::URI* uri, ::java::net::http::WebSocket$Listener* listener, ::java::util::Optional* proxySelector, ::java::util::Collection* headers, ::java::util::Collection* subprotocols, ::java::time::Duration* timeout);
	virtual ::java::util::concurrent::CompletableFuture* buildAsync(::java::net::URI* uri, ::java::net::http::WebSocket$Listener* listener) override;
	virtual ::java::net::http::WebSocket$Builder* connectTimeout(::java::time::Duration* timeout) override;
	::java::net::http::HttpClient* getClient();
	::java::time::Duration* getConnectTimeout();
	::java::util::Collection* getHeaders();
	::java::net::http::WebSocket$Listener* getListener();
	::java::util::Optional* getProxySelector();
	::java::util::Collection* getSubprotocols();
	::java::net::URI* getUri();
	virtual ::java::net::http::WebSocket$Builder* header($String* name, $String* value) override;
	::jdk::internal::net::http::websocket::BuilderImpl* immutableCopy();
	virtual ::java::net::http::WebSocket$Builder* subprotocols($String* mostPreferred, $StringArray* lesserPreferred) override;
	static bool $assertionsDisabled;
	::java::net::http::HttpClient* client = nullptr;
	::java::net::URI* uri = nullptr;
	::java::net::http::WebSocket$Listener* listener = nullptr;
	::java::util::Optional* proxySelector = nullptr;
	::java::util::Collection* headers = nullptr;
	::java::util::Collection* subprotocols$ = nullptr;
	::java::time::Duration* timeout = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_BuilderImpl_h_