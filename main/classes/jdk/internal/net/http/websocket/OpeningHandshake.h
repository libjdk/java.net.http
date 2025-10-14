#ifndef _jdk_internal_net_http_websocket_OpeningHandshake_h_
#define _jdk_internal_net_http_websocket_OpeningHandshake_h_
//$ class jdk.internal.net.http.websocket.OpeningHandshake
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("HEADER_ACCEPT")
#undef HEADER_ACCEPT
#pragma push_macro("HEADER_CONNECTION")
#undef HEADER_CONNECTION
#pragma push_macro("HEADER_EXTENSIONS")
#undef HEADER_EXTENSIONS
#pragma push_macro("HEADER_KEY")
#undef HEADER_KEY
#pragma push_macro("HEADER_PROTOCOL")
#undef HEADER_PROTOCOL
#pragma push_macro("HEADER_UPGRADE")
#undef HEADER_UPGRADE
#pragma push_macro("HEADER_VERSION")
#undef HEADER_VERSION
#pragma push_macro("ILLEGAL_HEADERS")
#undef ILLEGAL_HEADERS
#pragma push_macro("VERSION")
#undef VERSION

namespace java {
	namespace lang {
		class IllegalArgumentException;
	}
}
namespace java {
	namespace net {
		class Proxy;
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient;
			class HttpHeaders;
			class HttpResponse;
		}
	}
}
namespace java {
	namespace security {
		class MessageDigest;
		class SecureRandom;
	}
}
namespace java {
	namespace util {
		class Collection;
		class Optional;
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
					class Pair;
				}
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {
					class BuilderImpl;
					class CheckFailedException;
					class OpeningHandshake$Result;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class OpeningHandshake : public ::java::lang::Object {
	$class(OpeningHandshake, 0, ::java::lang::Object)
public:
	OpeningHandshake();
	void init$(::jdk::internal::net::http::websocket::BuilderImpl* b);
	$String* checkAndReturnSubprotocol(::java::net::http::HttpHeaders* responseHeaders);
	static ::jdk::internal::net::http::websocket::CheckFailedException* checkFailed($String* message);
	static void checkPermissions(::jdk::internal::net::http::websocket::BuilderImpl* b, ::java::net::Proxy* proxy);
	static ::java::net::URI* checkURI(::java::net::URI* uri);
	static $String* createNonce();
	static ::java::util::Collection* createRequestSubprotocols(::java::util::Collection* subprotocols);
	static ::java::net::URI* createRequestURI(::java::net::URI* uri);
	::jdk::internal::net::http::websocket::OpeningHandshake$Result* handleResponse(::java::net::http::HttpResponse* response);
	static ::java::lang::IllegalArgumentException* illegal($String* message);
	static $String* lambda$checkPermissions$1(::jdk::internal::net::http::common::Pair* p);
	::java::util::concurrent::CompletableFuture* lambda$send$0();
	static ::java::net::Proxy* proxyFor(::java::util::Optional* selector, ::java::net::URI* uri);
	static void requireAbsent(::java::net::http::HttpHeaders* responseHeaders, $String* headerName);
	static ::java::util::Optional* requireAtMostOne(::java::net::http::HttpHeaders* responseHeaders, $String* headerName);
	static $String* requireSingle(::java::net::http::HttpHeaders* responseHeaders, $String* headerName);
	::java::util::concurrent::CompletableFuture* resultFrom(::java::net::http::HttpResponse* response);
	virtual ::java::util::concurrent::CompletableFuture* send();
	static bool $assertionsDisabled;
	static $String* HEADER_CONNECTION;
	static $String* HEADER_UPGRADE;
	static $String* HEADER_ACCEPT;
	static $String* HEADER_EXTENSIONS;
	static $String* HEADER_KEY;
	static $String* HEADER_PROTOCOL;
	static $String* HEADER_VERSION;
	static $String* VERSION;
	static ::java::util::Set* ILLEGAL_HEADERS;
	static ::java::security::SecureRandom* random;
	::java::security::MessageDigest* sha1 = nullptr;
	::java::net::http::HttpClient* client = nullptr;
	::jdk::internal::net::http::HttpRequestImpl* request = nullptr;
	::java::util::Collection* subprotocols = nullptr;
	$String* nonce = nullptr;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("HEADER_ACCEPT")
#pragma pop_macro("HEADER_CONNECTION")
#pragma pop_macro("HEADER_EXTENSIONS")
#pragma pop_macro("HEADER_KEY")
#pragma pop_macro("HEADER_PROTOCOL")
#pragma pop_macro("HEADER_UPGRADE")
#pragma pop_macro("HEADER_VERSION")
#pragma pop_macro("ILLEGAL_HEADERS")
#pragma pop_macro("VERSION")

#endif // _jdk_internal_net_http_websocket_OpeningHandshake_h_