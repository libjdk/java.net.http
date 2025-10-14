#ifndef _java_net_http_HttpClient$Version_h_
#define _java_net_http_HttpClient$Version_h_
//$ class java.net.http.HttpClient$Version
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("HTTP_1_1")
#undef HTTP_1_1
#pragma push_macro("HTTP_2")
#undef HTTP_2

namespace java {
	namespace net {
		namespace http {

class $export HttpClient$Version : public ::java::lang::Enum {
	$class(HttpClient$Version, 0, ::java::lang::Enum)
public:
	HttpClient$Version();
	static $Array<::java::net::http::HttpClient$Version>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::java::net::http::HttpClient$Version* valueOf($String* name);
	static $Array<::java::net::http::HttpClient$Version>* values();
	static ::java::net::http::HttpClient$Version* HTTP_1_1;
	static ::java::net::http::HttpClient$Version* HTTP_2;
	static $Array<::java::net::http::HttpClient$Version>* $VALUES;
};

		} // http
	} // net
} // java

#pragma pop_macro("HTTP_1_1")
#pragma pop_macro("HTTP_2")

#endif // _java_net_http_HttpClient$Version_h_