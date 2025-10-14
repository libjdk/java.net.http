#ifndef _jdk_internal_net_http_common_HttpHeadersBuilder_h_
#define _jdk_internal_net_http_common_HttpHeadersBuilder_h_
//$ class jdk.internal.net.http.common.HttpHeadersBuilder
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
		}
	}
}
namespace java {
	namespace util {
		class List;
		class Map;
		class TreeMap;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export HttpHeadersBuilder : public ::java::lang::Object {
	$class(HttpHeadersBuilder, $NO_CLASS_INIT, ::java::lang::Object)
public:
	HttpHeadersBuilder();
	void init$();
	virtual void addHeader($String* name, $String* value);
	virtual ::java::net::http::HttpHeaders* build();
	virtual void clear();
	static ::java::util::List* lambda$addHeader$0($String* k);
	virtual ::java::util::Map* map();
	virtual void setHeader($String* name, $String* value);
	virtual ::jdk::internal::net::http::common::HttpHeadersBuilder* structuralCopy();
	virtual $String* toString() override;
	::java::util::TreeMap* headersMap = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_HttpHeadersBuilder_h_