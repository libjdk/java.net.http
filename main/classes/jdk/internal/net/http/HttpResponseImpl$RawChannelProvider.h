#ifndef _jdk_internal_net_http_HttpResponseImpl$RawChannelProvider_h_
#define _jdk_internal_net_http_HttpResponseImpl$RawChannelProvider_h_
//$ class jdk.internal.net.http.HttpResponseImpl$RawChannelProvider
//$ extends jdk.internal.net.http.websocket.RawChannel$Provider

#include <jdk/internal/net/http/websocket/RawChannel$Provider.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Exchange;
				class ExchangeImpl;
				class HttpConnection;
				class Response;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class RawChannel;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export HttpResponseImpl$RawChannelProvider : public ::jdk::internal::net::http::websocket::RawChannel$Provider {
	$class(HttpResponseImpl$RawChannelProvider, 0, ::jdk::internal::net::http::websocket::RawChannel$Provider)
public:
	HttpResponseImpl$RawChannelProvider();
	void init$(::jdk::internal::net::http::HttpConnection* conn, ::jdk::internal::net::http::Exchange* exch);
	virtual void closeRawChannel() override;
	static ::jdk::internal::net::http::HttpConnection* connection(::jdk::internal::net::http::Response* resp, ::jdk::internal::net::http::Exchange* exch);
	static ::jdk::internal::net::http::HttpResponseImpl$RawChannelProvider* create(::jdk::internal::net::http::Response* resp, ::jdk::internal::net::http::Exchange* exch);
	::jdk::internal::net::http::ExchangeImpl* exchangeImpl();
	virtual ::jdk::internal::net::http::websocket::RawChannel* rawChannel() override;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::HttpConnection* connection$ = nullptr;
	::jdk::internal::net::http::Exchange* exchange = nullptr;
	::jdk::internal::net::http::websocket::RawChannel* rawchan = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpResponseImpl$RawChannelProvider_h_