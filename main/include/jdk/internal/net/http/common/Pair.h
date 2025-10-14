#ifndef _jdk_internal_net_http_common_Pair_h_
#define _jdk_internal_net_http_common_Pair_h_
//$ class jdk.internal.net.http.common.Pair
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import Pair : public ::java::lang::Object {
	$class(Pair, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Pair();
	void init$(Object$* first, Object$* second);
	static ::jdk::internal::net::http::common::Pair* pair(Object$* first, Object$* second);
	virtual $String* toString() override;
	$Object* first = nullptr;
	$Object* second = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_Pair_h_