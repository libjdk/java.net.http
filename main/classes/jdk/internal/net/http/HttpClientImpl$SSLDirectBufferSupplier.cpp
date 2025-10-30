#include <jdk/internal/net/http/HttpClientImpl$SSLDirectBufferSupplier.h>

#include <java/lang/AssertionError.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Objects.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef BUFSIZE
#undef POOL_SIZE

using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Objects = ::java::util::Objects;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $BufferSupplier = ::jdk::internal::net::http::common::BufferSupplier;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _HttpClientImpl$SSLDirectBufferSupplier_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpClientImpl$SSLDirectBufferSupplier, $assertionsDisabled)},
	{"POOL_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HttpClientImpl$SSLDirectBufferSupplier, POOL_SIZE)},
	{"pool", "[Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$SSLDirectBufferSupplier, pool)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$SSLDirectBufferSupplier, client)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$SSLDirectBufferSupplier, debug)},
	{"tail", "I", nullptr, $PRIVATE, $field(HttpClientImpl$SSLDirectBufferSupplier, tail)},
	{"count", "I", nullptr, $PRIVATE, $field(HttpClientImpl$SSLDirectBufferSupplier, count)},
	{}
};

$MethodInfo _HttpClientImpl$SSLDirectBufferSupplier_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, 0, $method(static_cast<void(HttpClientImpl$SSLDirectBufferSupplier::*)($HttpClientImpl*)>(&HttpClientImpl$SSLDirectBufferSupplier::init$))},
	{"get", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC},
	{"recycle", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HttpClientImpl$SSLDirectBufferSupplier_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpClientImpl$SSLDirectBufferSupplier", "jdk.internal.net.http.HttpClientImpl", "SSLDirectBufferSupplier", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _HttpClientImpl$SSLDirectBufferSupplier_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpClientImpl$SSLDirectBufferSupplier",
	"java.lang.Object",
	"jdk.internal.net.http.common.BufferSupplier",
	_HttpClientImpl$SSLDirectBufferSupplier_FieldInfo_,
	_HttpClientImpl$SSLDirectBufferSupplier_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClientImpl$SSLDirectBufferSupplier_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpClientImpl"
};

$Object* allocate$HttpClientImpl$SSLDirectBufferSupplier($Class* clazz) {
	return $of($alloc(HttpClientImpl$SSLDirectBufferSupplier));
}

bool HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled = false;

void HttpClientImpl$SSLDirectBufferSupplier::init$($HttpClientImpl* client) {
	$set(this, pool, $new($ByteBufferArray, HttpClientImpl$SSLDirectBufferSupplier::POOL_SIZE));
	$set(this, client, $cast($HttpClientImpl, $Objects::requireNonNull(client)));
	$set(this, debug, client->debug);
}

$Object* HttpClientImpl$SSLDirectBufferSupplier::get() {
	$useLocalCurrentObjectStackCache();
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !$nc(this->client)->isSelectorThread()) {
		$throwNew($AssertionError);
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !(this->tail <= HttpClientImpl$SSLDirectBufferSupplier::POOL_SIZE)) {
		$throwNew($AssertionError, $of($$str({"allocate tail is "_s, $$str(this->tail)})));
	}
	$var($ByteBuffer, buf, nullptr);
	if (this->tail == 0) {
		if ($nc(this->debug)->on()) {
			$init($Utils);
			$nc(this->debug)->log("ByteBuffer.allocateDirect(%d)"_s, $$new($ObjectArray, {$($of($Integer::valueOf($Utils::BUFSIZE)))}));
		}
		if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !(this->count++ < HttpClientImpl$SSLDirectBufferSupplier::POOL_SIZE)) {
			$throwNew($AssertionError, $of($$str({"trying to allocate more than "_s, $$str(HttpClientImpl$SSLDirectBufferSupplier::POOL_SIZE), " buffers"_s})));
		}
		$init($Utils);
		$assign(buf, $ByteBuffer::allocateDirect($Utils::BUFSIZE));
	} else {
		if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !(this->tail > 0)) {
			$throwNew($AssertionError, $of($$str({"non positive tail value: "_s, $$str(this->tail)})));
		}
		--this->tail;
		$assign(buf, $nc(this->pool)->get(this->tail));
		$nc(this->pool)->set(this->tail, nullptr);
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !$nc(buf)->isDirect()) {
		$throwNew($AssertionError);
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !($nc(buf)->position() == 0)) {
		$throwNew($AssertionError);
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !$nc(buf)->hasRemaining()) {
		$throwNew($AssertionError);
	}
	$init($Utils);
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !($nc(buf)->limit() == $Utils::BUFSIZE)) {
		$throwNew($AssertionError);
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !(this->tail < HttpClientImpl$SSLDirectBufferSupplier::POOL_SIZE)) {
		$throwNew($AssertionError);
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !(this->tail >= 0)) {
		$throwNew($AssertionError);
	}
	return $of(buf);
}

void HttpClientImpl$SSLDirectBufferSupplier::recycle($ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !$nc(this->client)->isSelectorThread()) {
		$throwNew($AssertionError);
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !$nc(buffer)->isDirect()) {
		$throwNew($AssertionError);
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && ! !$nc(buffer)->hasRemaining()) {
		$throwNew($AssertionError);
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !(this->tail < HttpClientImpl$SSLDirectBufferSupplier::POOL_SIZE)) {
		$throwNew($AssertionError, $of($$str({"recycle tail is "_s, $$str(this->tail)})));
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !(this->tail >= 0)) {
		$throwNew($AssertionError);
	}
	$nc(buffer)->position(0);
	buffer->limit(buffer->capacity());
	if (this->tail < HttpClientImpl$SSLDirectBufferSupplier::POOL_SIZE) {
		$nc(this->pool)->set(this->tail, buffer);
		++this->tail;
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !(this->tail <= HttpClientImpl$SSLDirectBufferSupplier::POOL_SIZE)) {
		$throwNew($AssertionError);
	}
	if (!HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled && !(this->tail > 0)) {
		$throwNew($AssertionError);
	}
}

void clinit$HttpClientImpl$SSLDirectBufferSupplier($Class* class$) {
	$load($HttpClientImpl);
	HttpClientImpl$SSLDirectBufferSupplier::$assertionsDisabled = !$HttpClientImpl::class$->desiredAssertionStatus();
}

HttpClientImpl$SSLDirectBufferSupplier::HttpClientImpl$SSLDirectBufferSupplier() {
}

$Class* HttpClientImpl$SSLDirectBufferSupplier::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$SSLDirectBufferSupplier, name, initialize, &_HttpClientImpl$SSLDirectBufferSupplier_ClassInfo_, clinit$HttpClientImpl$SSLDirectBufferSupplier, allocate$HttpClientImpl$SSLDirectBufferSupplier);
	return class$;
}

$Class* HttpClientImpl$SSLDirectBufferSupplier::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk