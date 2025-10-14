#ifndef _jdk_internal_net_http_common_SSLFlowDelegate$EngineResult_h_
#define _jdk_internal_net_http_common_SSLFlowDelegate$EngineResult_h_
//$ class jdk.internal.net.http.common.SSLFlowDelegate$EngineResult
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLEngineResult;
			class SSLEngineResult$HandshakeStatus;
			class SSLEngineResult$Status;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import SSLFlowDelegate$EngineResult : public ::java::lang::Object {
	$class(SSLFlowDelegate$EngineResult, $NO_CLASS_INIT, ::java::lang::Object)
public:
	SSLFlowDelegate$EngineResult();
	void init$(::javax::net::ssl::SSLEngineResult* result);
	void init$(::javax::net::ssl::SSLEngineResult* result, ::java::nio::ByteBuffer* destBuffer);
	virtual int32_t bytesConsumed();
	virtual int32_t bytesProduced();
	virtual ::javax::net::ssl::SSLEngineResult$HandshakeStatus* handshakeStatus();
	virtual bool handshaking();
	virtual bool needUnwrap();
	virtual ::javax::net::ssl::SSLEngineResult$Status* status();
	::javax::net::ssl::SSLEngineResult* result = nullptr;
	::java::nio::ByteBuffer* destBuffer = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLFlowDelegate$EngineResult_h_