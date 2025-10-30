#include <jdk/internal/net/http/websocket/StatusCodes.h>

#include <jcpp.h>

#undef CLOSED_ABNORMALLY
#undef NOT_CONSISTENT
#undef NO_STATUS_CODE
#undef PROTOCOL_ERROR

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace websocket {

$FieldInfo _StatusCodes_FieldInfo_[] = {
	{"PROTOCOL_ERROR", "I", nullptr, $STATIC | $FINAL, $constField(StatusCodes, PROTOCOL_ERROR)},
	{"NO_STATUS_CODE", "I", nullptr, $STATIC | $FINAL, $constField(StatusCodes, NO_STATUS_CODE)},
	{"CLOSED_ABNORMALLY", "I", nullptr, $STATIC | $FINAL, $constField(StatusCodes, CLOSED_ABNORMALLY)},
	{"NOT_CONSISTENT", "I", nullptr, $STATIC | $FINAL, $constField(StatusCodes, NOT_CONSISTENT)},
	{}
};

$MethodInfo _StatusCodes_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(StatusCodes::*)()>(&StatusCodes::init$))},
	{"isLegal", "(I)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)(int32_t)>(&StatusCodes::isLegal))},
	{"isLegalToReceiveFromServer", "(I)Z", nullptr, $STATIC, $method(static_cast<bool(*)(int32_t)>(&StatusCodes::isLegalToReceiveFromServer))},
	{"isLegalToSendFromClient", "(I)Z", nullptr, $STATIC, $method(static_cast<bool(*)(int32_t)>(&StatusCodes::isLegalToSendFromClient))},
	{}
};

$ClassInfo _StatusCodes_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.websocket.StatusCodes",
	"java.lang.Object",
	nullptr,
	_StatusCodes_FieldInfo_,
	_StatusCodes_MethodInfo_
};

$Object* allocate$StatusCodes($Class* clazz) {
	return $of($alloc(StatusCodes));
}

void StatusCodes::init$() {
}

bool StatusCodes::isLegalToSendFromClient(int32_t code) {
	if (!isLegal(code)) {
		return false;
	}
	if (code > 4999) {
		return false;
	}

	bool var$0 = false;
	switch (code) {
	case StatusCodes::PROTOCOL_ERROR:
		{}
	case StatusCodes::NOT_CONSISTENT:
		{}
	case 1003:
		{}
	case 1009:
		{}
	case 1010:
		{}
	case 1012:
		{}
	case 1013:
		{}
	case 1014:
		{
			var$0 = false;
			break;
		}
	default:
		{
			var$0 = true;
			break;
		}
	}
	return var$0;
}

bool StatusCodes::isLegalToReceiveFromServer(int32_t code) {
	if (!isLegal(code)) {
		return false;
	}
	return code != 1010;
}

bool StatusCodes::isLegal(int32_t code) {
	if (code < 1000 || code > 0x0000FFFF) {
		return false;
	}
	if ((code >= 1016 && code <= 2999) || code == 1004) {
		return false;
	}

	bool var$0 = false;
	switch (code) {
	case StatusCodes::NO_STATUS_CODE:
		{}
	case StatusCodes::CLOSED_ABNORMALLY:
		{}
	case 1015:
		{
			var$0 = false;
			break;
		}
	default:
		{
			var$0 = true;
			break;
		}
	}
	return var$0;
}

StatusCodes::StatusCodes() {
}

$Class* StatusCodes::load$($String* name, bool initialize) {
	$loadClass(StatusCodes, name, initialize, &_StatusCodes_ClassInfo_, allocate$StatusCodes);
	return class$;
}

$Class* StatusCodes::class$ = nullptr;

				} // websocket
			} // http
		} // net
	} // internal
} // jdk