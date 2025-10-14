#ifndef _java_net_http_HttpHeaders_h_
#define _java_net_http_HttpHeaders_h_
//$ class java.net.http.HttpHeaders
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("NO_HEADERS")
#undef NO_HEADERS

namespace java {
	namespace util {
		class ArrayList;
		class List;
		class Map;
		class Map$Entry;
		class Optional;
		class OptionalLong;
		class TreeMap;
		class TreeSet;
	}
}
namespace java {
	namespace util {
		namespace function {
			class BiPredicate;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $import HttpHeaders : public ::java::lang::Object {
	$class(HttpHeaders, 0, ::java::lang::Object)
public:
	HttpHeaders();
	void init$(::java::util::Map* headers);
	::java::util::List* allValues($String* name);
	static int32_t entryHash(::java::util::Map$Entry* e);
	virtual bool equals(Object$* obj) override;
	::java::util::Optional* firstValue($String* name);
	::java::util::OptionalLong* firstValueAsLong($String* name);
	virtual int32_t hashCode() override;
	static ::java::net::http::HttpHeaders* headersOf(::java::util::Map* map, ::java::util::function::BiPredicate* filter);
	static void lambda$headersOf$0(::java::util::function::BiPredicate* filter, $String* headerName, ::java::util::ArrayList* tempList, $String* headerValue);
	static void lambda$headersOf$1(::java::util::function::BiPredicate* filter, ::java::util::ArrayList* tempList, ::java::util::TreeMap* other, ::java::util::TreeSet* notAdded, $String* key, ::java::util::List* value);
	::java::util::Map* map();
	static ::java::net::http::HttpHeaders* of(::java::util::Map* headerMap, ::java::util::function::BiPredicate* filter);
	virtual $String* toString() override;
	static ::java::net::http::HttpHeaders* NO_HEADERS;
	::java::util::Map* headers = nullptr;
};

		} // http
	} // net
} // java

#pragma pop_macro("NO_HEADERS")

#endif // _java_net_http_HttpHeaders_h_