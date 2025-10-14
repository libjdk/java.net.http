#ifndef _jdk_internal_net_http_HeaderParser_h_
#define _jdk_internal_net_http_HeaderParser_h_
//$ class jdk.internal.net.http.HeaderParser
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace util {
		class Iterator;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export HeaderParser : public ::java::lang::Object {
	$class(HeaderParser, $NO_CLASS_INIT, ::java::lang::Object)
public:
	HeaderParser();
	void init$($String* raw);
	virtual $String* findKey(int32_t i);
	virtual $String* findValue(int32_t i);
	virtual $String* findValue($String* key);
	virtual $String* findValue($String* k, $String* Default);
	virtual ::java::util::Iterator* keys();
	void parse();
	virtual $String* toString() override;
	$String* raw = nullptr;
	$Array<::java::lang::String, 2>* tab = nullptr;
	int32_t nkeys = 0;
	int32_t asize = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HeaderParser_h_