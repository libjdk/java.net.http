#ifndef _jdk_internal_net_http_websocket_StatusCodes_h_
#define _jdk_internal_net_http_websocket_StatusCodes_h_
//$ class jdk.internal.net.http.websocket.StatusCodes
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("CLOSED_ABNORMALLY")
#undef CLOSED_ABNORMALLY
#pragma push_macro("NOT_CONSISTENT")
#undef NOT_CONSISTENT
#pragma push_macro("NO_STATUS_CODE")
#undef NO_STATUS_CODE
#pragma push_macro("PROTOCOL_ERROR")
#undef PROTOCOL_ERROR

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

class StatusCodes : public ::java::lang::Object {
	$class(StatusCodes, $NO_CLASS_INIT, ::java::lang::Object)
public:
	StatusCodes();
	void init$();
	static bool isLegal(int32_t code);
	static bool isLegalToReceiveFromServer(int32_t code);
	static bool isLegalToSendFromClient(int32_t code);
	static const int32_t PROTOCOL_ERROR = 1002;
	static const int32_t NO_STATUS_CODE = 1005;
	static const int32_t CLOSED_ABNORMALLY = 1006;
	static const int32_t NOT_CONSISTENT = 1007;
};

				} // websocket
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("CLOSED_ABNORMALLY")
#pragma pop_macro("NOT_CONSISTENT")
#pragma pop_macro("NO_STATUS_CODE")
#pragma pop_macro("PROTOCOL_ERROR")

#endif // _jdk_internal_net_http_websocket_StatusCodes_h_