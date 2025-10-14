#ifndef _jdk_internal_net_http_hpack_SimpleHeaderTable$HeaderField_h_
#define _jdk_internal_net_http_hpack_SimpleHeaderTable$HeaderField_h_
//$ class jdk.internal.net.http.hpack.SimpleHeaderTable$HeaderField
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class SimpleHeaderTable$HeaderField : public ::java::lang::Object {
	$class(SimpleHeaderTable$HeaderField, $NO_CLASS_INIT, ::java::lang::Object)
public:
	SimpleHeaderTable$HeaderField();
	void init$($String* name);
	void init$($String* name, $String* value);
	virtual $String* toString() override;
	$String* name = nullptr;
	$String* value = nullptr;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_SimpleHeaderTable$HeaderField_h_