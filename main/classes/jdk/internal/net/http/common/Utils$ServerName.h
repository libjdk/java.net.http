#ifndef _jdk_internal_net_http_common_Utils$ServerName_h_
#define _jdk_internal_net_http_common_Utils$ServerName_h_
//$ class jdk.internal.net.http.common.Utils$ServerName
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export Utils$ServerName : public ::java::lang::Object {
	$class(Utils$ServerName, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Utils$ServerName();
	void init$($String* name, bool isLiteral);
	virtual $String* getName();
	virtual bool isLiteral();
	$String* name = nullptr;
	bool isLiteral$ = false;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_Utils$ServerName_h_