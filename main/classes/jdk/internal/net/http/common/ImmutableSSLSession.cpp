#include <jdk/internal/net/http/common/ImmutableSSLSession.h>

#include <java/lang/UnsupportedOperationException.h>
#include <java/security/Principal.h>
#include <java/security/cert/Certificate.h>
#include <javax/net/ssl/SSLSession.h>
#include <javax/net/ssl/SSLSessionContext.h>
#include <jcpp.h>

using $CertificateArray = $Array<::java::security::cert::Certificate>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Principal = ::java::security::Principal;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $SSLSessionContext = ::javax::net::ssl::SSLSessionContext;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _ImmutableSSLSession_FieldInfo_[] = {
	{"delegate", "Ljavax/net/ssl/SSLSession;", nullptr, $PRIVATE | $FINAL, $field(ImmutableSSLSession, delegate)},
	{}
};

$MethodInfo _ImmutableSSLSession_MethodInfo_[] = {
	{"<init>", "(Ljavax/net/ssl/SSLSession;)V", nullptr, 0, $method(static_cast<void(ImmutableSSLSession::*)($SSLSession*)>(&ImmutableSSLSession::init$))},
	{"getApplicationBufferSize", "()I", nullptr, $PUBLIC},
	{"getCipherSuite", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getCreationTime", "()J", nullptr, $PUBLIC},
	{"getId", "()[B", nullptr, $PUBLIC},
	{"getLastAccessedTime", "()J", nullptr, $PUBLIC},
	{"getLocalCertificates", "()[Ljava/security/cert/Certificate;", nullptr, $PUBLIC},
	{"getLocalPrincipal", "()Ljava/security/Principal;", nullptr, $PUBLIC},
	{"getPacketBufferSize", "()I", nullptr, $PUBLIC},
	{"getPeerCertificates", "()[Ljava/security/cert/Certificate;", nullptr, $PUBLIC, nullptr, "javax.net.ssl.SSLPeerUnverifiedException"},
	{"getPeerHost", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getPeerPort", "()I", nullptr, $PUBLIC},
	{"getPeerPrincipal", "()Ljava/security/Principal;", nullptr, $PUBLIC, nullptr, "javax.net.ssl.SSLPeerUnverifiedException"},
	{"getProtocol", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"getSessionContext", "()Ljavax/net/ssl/SSLSessionContext;", nullptr, $PUBLIC},
	{"getValue", "(Ljava/lang/String;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{"getValueNames", "()[Ljava/lang/String;", nullptr, $PUBLIC},
	{"invalidate", "()V", nullptr, $PUBLIC},
	{"isValid", "()Z", nullptr, $PUBLIC},
	{"putValue", "(Ljava/lang/String;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{"removeValue", "(Ljava/lang/String;)V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _ImmutableSSLSession_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.common.ImmutableSSLSession",
	"java.lang.Object",
	"javax.net.ssl.SSLSession",
	_ImmutableSSLSession_FieldInfo_,
	_ImmutableSSLSession_MethodInfo_
};

$Object* allocate$ImmutableSSLSession($Class* clazz) {
	return $of($alloc(ImmutableSSLSession));
}

void ImmutableSSLSession::init$($SSLSession* session) {
	$set(this, delegate, session);
}

$bytes* ImmutableSSLSession::getId() {
	return $nc(this->delegate)->getId();
}

$SSLSessionContext* ImmutableSSLSession::getSessionContext() {
	return $nc(this->delegate)->getSessionContext();
}

int64_t ImmutableSSLSession::getCreationTime() {
	return $nc(this->delegate)->getCreationTime();
}

int64_t ImmutableSSLSession::getLastAccessedTime() {
	return $nc(this->delegate)->getLastAccessedTime();
}

void ImmutableSSLSession::invalidate() {
	$throwNew($UnsupportedOperationException, "session is not mutable"_s);
}

bool ImmutableSSLSession::isValid() {
	return $nc(this->delegate)->isValid();
}

void ImmutableSSLSession::putValue($String* name, Object$* value) {
	$throwNew($UnsupportedOperationException, "session is not mutable"_s);
}

$Object* ImmutableSSLSession::getValue($String* name) {
	return $of($nc(this->delegate)->getValue(name));
}

void ImmutableSSLSession::removeValue($String* name) {
	$throwNew($UnsupportedOperationException, "session is not mutable"_s);
}

$StringArray* ImmutableSSLSession::getValueNames() {
	return $nc(this->delegate)->getValueNames();
}

$CertificateArray* ImmutableSSLSession::getPeerCertificates() {
	return $nc(this->delegate)->getPeerCertificates();
}

$CertificateArray* ImmutableSSLSession::getLocalCertificates() {
	return $nc(this->delegate)->getLocalCertificates();
}

$Principal* ImmutableSSLSession::getPeerPrincipal() {
	return $nc(this->delegate)->getPeerPrincipal();
}

$Principal* ImmutableSSLSession::getLocalPrincipal() {
	return $nc(this->delegate)->getLocalPrincipal();
}

$String* ImmutableSSLSession::getCipherSuite() {
	return $nc(this->delegate)->getCipherSuite();
}

$String* ImmutableSSLSession::getProtocol() {
	return $nc(this->delegate)->getProtocol();
}

$String* ImmutableSSLSession::getPeerHost() {
	return $nc(this->delegate)->getPeerHost();
}

int32_t ImmutableSSLSession::getPeerPort() {
	return $nc(this->delegate)->getPeerPort();
}

int32_t ImmutableSSLSession::getPacketBufferSize() {
	return $nc(this->delegate)->getPacketBufferSize();
}

int32_t ImmutableSSLSession::getApplicationBufferSize() {
	return $nc(this->delegate)->getApplicationBufferSize();
}

ImmutableSSLSession::ImmutableSSLSession() {
}

$Class* ImmutableSSLSession::load$($String* name, bool initialize) {
	$loadClass(ImmutableSSLSession, name, initialize, &_ImmutableSSLSession_ClassInfo_, allocate$ImmutableSSLSession);
	return class$;
}

$Class* ImmutableSSLSession::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk