#ifndef _jdk_internal_net_http_common_Utils_h_
#define _jdk_internal_net_http_common_Utils_h_
//$ class jdk.internal.net.http.common.Utils
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("ACCEPT_ALL")
#undef ACCEPT_ALL
#pragma push_macro("ALLOWED_HEADERS")
#undef ALLOWED_HEADERS
#pragma push_macro("ALL_HEADERS")
#undef ALL_HEADERS
#pragma push_macro("ASSERTIONSENABLED")
#undef ASSERTIONSENABLED
#pragma push_macro("BUFSIZE")
#undef BUFSIZE
#pragma push_macro("CONTEXT_RESTRICTED")
#undef CONTEXT_RESTRICTED
#pragma push_macro("COPY_THRESHOLD")
#undef COPY_THRESHOLD
#pragma push_macro("DEBUG")
#undef DEBUG
#pragma push_macro("DEBUG_HPACK")
#undef DEBUG_HPACK
#pragma push_macro("DEBUG_WS")
#undef DEBUG_WS
#pragma push_macro("DEFAULT_BUFSIZE")
#undef DEFAULT_BUFSIZE
#pragma push_macro("DISALLOWED_HEADERS_SET")
#undef DISALLOWED_HEADERS_SET
#pragma push_macro("EMPTY_BB_ARRAY")
#undef EMPTY_BB_ARRAY
#pragma push_macro("EMPTY_BB_LIST")
#undef EMPTY_BB_LIST
#pragma push_macro("EMPTY_BYTEBUFFER")
#undef EMPTY_BYTEBUFFER
#pragma push_macro("HEADER_CONNECTION")
#undef HEADER_CONNECTION
#pragma push_macro("HEADER_UPGRADE")
#undef HEADER_UPGRADE
#pragma push_macro("HOST_RESTRICTED")
#undef HOST_RESTRICTED
#pragma push_macro("IS_HOST")
#undef IS_HOST
#pragma push_macro("IS_PROXY_HEADER")
#undef IS_PROXY_HEADER
#pragma push_macro("NO_PROXY_HEADER")
#undef NO_PROXY_HEADER
#pragma push_macro("NO_PROXY_HEADERS_FILTER")
#undef NO_PROXY_HEADERS_FILTER
#pragma push_macro("PROXY_AUTH_DISABLED_SCHEMES")
#undef PROXY_AUTH_DISABLED_SCHEMES
#pragma push_macro("PROXY_AUTH_TUNNEL_DISABLED_SCHEMES")
#undef PROXY_AUTH_TUNNEL_DISABLED_SCHEMES
#pragma push_macro("PROXY_FILTER")
#undef PROXY_FILTER
#pragma push_macro("PROXY_TUNNEL_FILTER")
#undef PROXY_TUNNEL_FILTER
#pragma push_macro("PROXY_TUNNEL_RESTRICTED")
#undef PROXY_TUNNEL_RESTRICTED
#pragma push_macro("TESTING")
#undef TESTING
#pragma push_macro("VALIDATE_USER_HEADER")
#undef VALIDATE_USER_HEADER
#pragma push_macro("WSPACES")
#undef WSPACES

namespace java {
	namespace io {
		class Closeable;
		class IOException;
		class UncheckedIOException;
	}
}
namespace java {
	namespace lang {
		class Boolean;
		class IllegalArgumentException;
		class Integer;
		class System$Logger$Level;
		class Throwable;
	}
}
namespace java {
	namespace net {
		class InetSocketAddress;
		class URI;
		class URLPermission;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpClient;
			class HttpHeaders;
		}
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
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
		class Collection;
		class List;
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
namespace java {
	namespace util {
		namespace function {
			class BiPredicate;
			class Predicate;
			class Supplier;
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
namespace javax {
	namespace net {
		namespace ssl {
			class SSLParameters;
			class SSLSession;
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
					class Logger;
					class Utils$ServerName;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export Utils : public ::java::lang::Object {
	$class(Utils, 0, ::java::lang::Object)
public:
	Utils();
	void init$();
	static ::java::util::function::BiPredicate* CONTEXT_RESTRICTED(::java::net::http::HttpClient* client);
	static ::java::util::function::BiPredicate* PROXY_TUNNEL_RESTRICTED(::java::net::http::HttpClient* client);
	static int64_t accumulateBuffers(::java::util::List* currentList, ::java::util::List* buffersToAdd);
	static ::java::nio::charset::Charset* charsetFrom(::java::net::http::HttpHeaders* headers);
	static void close($Array<::java::io::Closeable>* closeables);
	static int32_t copy(::java::nio::ByteBuffer* src, ::java::nio::ByteBuffer* dst);
	static ::java::nio::ByteBuffer* copy(::java::nio::ByteBuffer* src);
	static ::java::nio::ByteBuffer* copyAligned(::java::nio::ByteBuffer* src);
	static ::javax::net::ssl::SSLParameters* copySSLParameters(::javax::net::ssl::SSLParameters* p);
	static $String* dump($ObjectArray* objects);
	static $String* encode($String* s);
	static void flipToMark(::java::nio::ByteBuffer* buffer, int32_t mark);
	static bool getBooleanProperty($String* name, bool def);
	static ::java::nio::ByteBuffer* getBuffer();
	static $Throwable* getCancelCause($Throwable* x);
	static $Throwable* getCompletionCause($Throwable* x);
	static ::jdk::internal::net::http::common::Logger* getDebugLogger(::java::util::function::Supplier* dbgTag);
	static ::jdk::internal::net::http::common::Logger* getDebugLogger(::java::util::function::Supplier* dbgTag, ::java::lang::System$Logger$Level* errLevel);
	static ::jdk::internal::net::http::common::Logger* getDebugLogger(::java::util::function::Supplier* dbgTag, bool on);
	static ::java::util::Set* getDisallowedHeaders();
	static ::jdk::internal::net::http::common::Logger* getHpackLogger(::java::util::function::Supplier* dbgTag, ::java::lang::System$Logger$Level* errLevel);
	static ::jdk::internal::net::http::common::Logger* getHpackLogger(::java::util::function::Supplier* dbgTag, bool on);
	static ::java::io::IOException* getIOException($Throwable* t);
	static int32_t getIntegerNetProperty($String* name, int32_t defaultValue);
	static int32_t getIntegerProperty($String* name, int32_t defaultValue);
	static $String* getNetProperty($String* name);
	static $String* getProperty($String* name);
	static ::jdk::internal::net::http::common::Utils$ServerName* getServerName(::java::net::InetSocketAddress* addr);
	static ::jdk::internal::net::http::common::Logger* getWebSocketLogger(::java::util::function::Supplier* dbgTag, ::java::lang::System$Logger$Level* errLevel);
	static ::jdk::internal::net::http::common::Logger* getWebSocketLogger(::java::util::function::Supplier* dbgTag, bool on);
	static bool hasRemaining(::java::util::List* bufs);
	static $String* hostString(::jdk::internal::net::http::HttpRequestImpl* request);
	static bool hostnameVerificationDisabledValue();
	static ::javax::net::ssl::SSLSession* immutableSession(::javax::net::ssl::SSLSession* session);
	static bool isAllowedForProxy($String* name, $String* value, ::java::util::Set* disabledSchemes, ::java::util::function::Predicate* allowedKeys);
	static bool isHostnameVerificationDisabled();
	static bool isLoopbackLiteral($bytes* bytes);
	static bool isValidName($String* token);
	static bool isValidValue($String* token);
	static bool lambda$CONTEXT_RESTRICTED$3(::java::net::http::HttpClient* client, $String* k, $String* v);
	static ::java::lang::Boolean* lambda$getBooleanProperty$15($String* name, bool def);
	static ::java::lang::Integer* lambda$getIntegerNetProperty$13($String* name, int32_t defaultValue);
	static ::java::lang::Integer* lambda$getIntegerProperty$17($String* name, int32_t defaultValue);
	static $String* lambda$getNetProperty$14($String* name);
	static $String* lambda$getProperty$16($String* name);
	static bool lambda$static$0($String* x, $String* y);
	static bool lambda$static$1($String* header, $String* unused);
	static bool lambda$static$10($String* s, $String* v);
	static bool lambda$static$11($String* s, $String* v);
	static bool lambda$static$12($String* n, $String* v);
	static bool lambda$static$2($String* name, $String* value);
	static bool lambda$static$4($String* k, $String* v);
	static bool lambda$static$5($String* k);
	static bool lambda$static$6($String* s);
	static bool lambda$static$7($String* s);
	static ::java::util::concurrent::CompletableFuture* lambda$wrapForDebug$9(::jdk::internal::net::http::common::Logger* logger, $String* name, ::java::util::concurrent::CompletableFuture* cf, Object$* r, $Throwable* t);
	static ::java::lang::IllegalArgumentException* newIAE($String* message, $ObjectArray* args);
	static ::java::net::URLPermission* permissionForProxy(::java::net::InetSocketAddress* proxyAddress);
	static ::java::net::URLPermission* permissionForServer(::java::net::URI* uri, $String* method, ::java::util::stream::Stream* headers);
	static int32_t pow2Size(int32_t n);
	static bool proxyHasDisabledSchemes(bool tunnel);
	static int64_t remaining($Array<::java::nio::ByteBuffer>* bufs);
	static int64_t remaining(::java::util::List* bufs);
	static int32_t remaining(::java::util::List* bufs, int32_t max);
	static int32_t remaining($Array<::java::nio::ByteBuffer>* refs, int32_t max);
	static ::java::net::InetSocketAddress* resolveAddress(::java::net::InetSocketAddress* address);
	static void setWebSocketUpgradeHeaders(::jdk::internal::net::http::HttpRequestImpl* request);
	static ::java::nio::ByteBuffer* sliceWithLimitedCapacity(::java::nio::ByteBuffer* buffer, int32_t amount);
	static $String* stackTrace($Throwable* t);
	static $String* stringOf(::java::util::Collection* source);
	static int64_t synchronizedRemaining(::java::util::List* bufs);
	static $Throwable* toConnectException($Throwable* e);
	static ::java::io::UncheckedIOException* unchecked(::java::io::IOException* e);
	static ::java::util::concurrent::CompletableFuture* wrapForDebug(::jdk::internal::net::http::common::Logger* logger, $String* name, ::java::util::concurrent::CompletableFuture* cf);
	static $Throwable* wrapWithExtraDetail($Throwable* t, ::java::util::function::Supplier* messageSupplier);
	static bool $assertionsDisabled;
	static bool ASSERTIONSENABLED;
	static bool DEBUG;
	static bool DEBUG_WS;
	static bool DEBUG_HPACK;
	static bool TESTING;
	static bool isHostnameVerificationDisabled$;
	static const int32_t DEFAULT_BUFSIZE = 16384; // 16 * 1024
	static int32_t BUFSIZE;
	static ::java::util::function::BiPredicate* ACCEPT_ALL;
	static ::java::util::Set* DISALLOWED_HEADERS_SET;
	static ::java::util::function::BiPredicate* ALLOWED_HEADERS;
	static ::java::util::function::BiPredicate* VALIDATE_USER_HEADER;
	static ::java::util::function::BiPredicate* HOST_RESTRICTED;
	static ::java::util::function::Predicate* IS_HOST;
	static ::java::util::function::Predicate* IS_PROXY_HEADER;
	static ::java::util::function::Predicate* NO_PROXY_HEADER;
	static ::java::util::function::Predicate* ALL_HEADERS;
	static ::java::util::Set* PROXY_AUTH_DISABLED_SCHEMES;
	static ::java::util::Set* PROXY_AUTH_TUNNEL_DISABLED_SCHEMES;
	static $String* WSPACES;
	static ::java::util::function::BiPredicate* PROXY_TUNNEL_FILTER;
	static ::java::util::function::BiPredicate* PROXY_FILTER;
	static ::java::util::function::BiPredicate* NO_PROXY_HEADERS_FILTER;
	static $String* HEADER_CONNECTION;
	static $String* HEADER_UPGRADE;
	static $booleans* tchar;
	static $booleans* fieldvchar;
	static const int32_t COPY_THRESHOLD = 8192;
	static ::java::nio::ByteBuffer* EMPTY_BYTEBUFFER;
	static $Array<::java::nio::ByteBuffer>* EMPTY_BB_ARRAY;
	static ::java::util::List* EMPTY_BB_LIST;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("ACCEPT_ALL")
#pragma pop_macro("ALLOWED_HEADERS")
#pragma pop_macro("ALL_HEADERS")
#pragma pop_macro("ASSERTIONSENABLED")
#pragma pop_macro("BUFSIZE")
#pragma pop_macro("CONTEXT_RESTRICTED")
#pragma pop_macro("COPY_THRESHOLD")
#pragma pop_macro("DEBUG")
#pragma pop_macro("DEBUG_HPACK")
#pragma pop_macro("DEBUG_WS")
#pragma pop_macro("DEFAULT_BUFSIZE")
#pragma pop_macro("DISALLOWED_HEADERS_SET")
#pragma pop_macro("EMPTY_BB_ARRAY")
#pragma pop_macro("EMPTY_BB_LIST")
#pragma pop_macro("EMPTY_BYTEBUFFER")
#pragma pop_macro("HEADER_CONNECTION")
#pragma pop_macro("HEADER_UPGRADE")
#pragma pop_macro("HOST_RESTRICTED")
#pragma pop_macro("IS_HOST")
#pragma pop_macro("IS_PROXY_HEADER")
#pragma pop_macro("NO_PROXY_HEADER")
#pragma pop_macro("NO_PROXY_HEADERS_FILTER")
#pragma pop_macro("PROXY_AUTH_DISABLED_SCHEMES")
#pragma pop_macro("PROXY_AUTH_TUNNEL_DISABLED_SCHEMES")
#pragma pop_macro("PROXY_FILTER")
#pragma pop_macro("PROXY_TUNNEL_FILTER")
#pragma pop_macro("PROXY_TUNNEL_RESTRICTED")
#pragma pop_macro("TESTING")
#pragma pop_macro("VALIDATE_USER_HEADER")
#pragma pop_macro("WSPACES")

#endif // _jdk_internal_net_http_common_Utils_h_