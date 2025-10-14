#ifndef _jdk_internal_net_http_common_ImmutableSSLSession_h_
#define _jdk_internal_net_http_common_ImmutableSSLSession_h_
//$ class jdk.internal.net.http.common.ImmutableSSLSession
//$ extends javax.net.ssl.SSLSession

#include <java/lang/Array.h>
#include <javax/net/ssl/SSLSession.h>

namespace java {
	namespace security {
		class Principal;
	}
}
namespace java {
	namespace security {
		namespace cert {
			class Certificate;
		}
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLSessionContext;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export ImmutableSSLSession : public ::javax::net::ssl::SSLSession {
	$class(ImmutableSSLSession, $NO_CLASS_INIT, ::javax::net::ssl::SSLSession)
public:
	ImmutableSSLSession();
	void init$(::javax::net::ssl::SSLSession* session);
	virtual int32_t getApplicationBufferSize() override;
	virtual $String* getCipherSuite() override;
	virtual int64_t getCreationTime() override;
	virtual $bytes* getId() override;
	virtual int64_t getLastAccessedTime() override;
	virtual $Array<::java::security::cert::Certificate>* getLocalCertificates() override;
	virtual ::java::security::Principal* getLocalPrincipal() override;
	virtual int32_t getPacketBufferSize() override;
	virtual $Array<::java::security::cert::Certificate>* getPeerCertificates() override;
	virtual $String* getPeerHost() override;
	virtual int32_t getPeerPort() override;
	virtual ::java::security::Principal* getPeerPrincipal() override;
	virtual $String* getProtocol() override;
	virtual ::javax::net::ssl::SSLSessionContext* getSessionContext() override;
	virtual $Object* getValue($String* name) override;
	virtual $StringArray* getValueNames() override;
	virtual void invalidate() override;
	virtual bool isValid() override;
	virtual void putValue($String* name, Object$* value) override;
	virtual void removeValue($String* name) override;
	::javax::net::ssl::SSLSession* delegate = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_ImmutableSSLSession_h_