#ifndef _jdk_internal_net_http_websocket_CheckFailedException_h_
#define _jdk_internal_net_http_websocket_CheckFailedException_h_
//$ class jdk.internal.net.http.websocket.CheckFailedException
//$ extends java.lang.RuntimeException

#include <java/lang/RuntimeException.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class CheckFailedException : public ::java::lang::RuntimeException {
	$class(CheckFailedException, $NO_CLASS_INIT, ::java::lang::RuntimeException)
public:
	CheckFailedException();
	void init$($String* message);
	static const int64_t serialVersionUID = (int64_t)1;
	CheckFailedException(const CheckFailedException& e);
	virtual void throw$() override;
	inline CheckFailedException* operator ->() {
		return (CheckFailedException*)throwing$;
	}
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_websocket_CheckFailedException_h_