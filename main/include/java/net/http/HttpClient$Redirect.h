#ifndef _java_net_http_HttpClient$Redirect_h_
#define _java_net_http_HttpClient$Redirect_h_
//$ class java.net.http.HttpClient$Redirect
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("ALWAYS")
#undef ALWAYS
#pragma push_macro("NEVER")
#undef NEVER
#pragma push_macro("NORMAL")
#undef NORMAL

namespace java {
	namespace net {
		namespace http {

class $import HttpClient$Redirect : public ::java::lang::Enum {
	$class(HttpClient$Redirect, 0, ::java::lang::Enum)
public:
	HttpClient$Redirect();
	static $Array<::java::net::http::HttpClient$Redirect>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::java::net::http::HttpClient$Redirect* valueOf($String* name);
	static $Array<::java::net::http::HttpClient$Redirect>* values();
	static ::java::net::http::HttpClient$Redirect* NEVER;
	static ::java::net::http::HttpClient$Redirect* ALWAYS;
	static ::java::net::http::HttpClient$Redirect* NORMAL;
	static $Array<::java::net::http::HttpClient$Redirect>* $VALUES;
};

		} // http
	} // net
} // java

#pragma pop_macro("ALWAYS")
#pragma pop_macro("NEVER")
#pragma pop_macro("NORMAL")

#endif // _java_net_http_HttpClient$Redirect_h_