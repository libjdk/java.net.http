#include <jdk/internal/net/http/SocketTube$SSLDirectBufferSource.h>

#include <java/lang/AssertionError.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/BufferSupplier.h>
#include <jcpp.h>

using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $SocketTube$BufferSource = ::jdk::internal::net::http::SocketTube$BufferSource;
using $BufferSupplier = ::jdk::internal::net::http::common::BufferSupplier;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _SocketTube$SSLDirectBufferSource_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SocketTube$SSLDirectBufferSource, $assertionsDisabled)},
	{"factory", "Ljdk/internal/net/http/common/BufferSupplier;", nullptr, $PRIVATE | $FINAL, $field(SocketTube$SSLDirectBufferSource, factory)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $PRIVATE | $FINAL, $field(SocketTube$SSLDirectBufferSource, client)},
	{"current", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $field(SocketTube$SSLDirectBufferSource, current)},
	{}
};

$MethodInfo _SocketTube$SSLDirectBufferSource_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$SSLDirectBufferSource::*)($HttpClientImpl*)>(&SocketTube$SSLDirectBufferSource::init$))},
	{"append", "(Ljava/util/List;Ljava/nio/ByteBuffer;I)Ljava/util/List;", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Ljava/nio/ByteBuffer;I)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PUBLIC | $FINAL},
	{"getBuffer", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $FINAL},
	{"returnUnused", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SocketTube$SSLDirectBufferSource_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$SSLDirectBufferSource", "jdk.internal.net.http.SocketTube", "SSLDirectBufferSource", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.SocketTube$BufferSource", "jdk.internal.net.http.SocketTube", "BufferSource", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SocketTube$SSLDirectBufferSource_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.SocketTube$SSLDirectBufferSource",
	"java.lang.Object",
	"jdk.internal.net.http.SocketTube$BufferSource",
	_SocketTube$SSLDirectBufferSource_FieldInfo_,
	_SocketTube$SSLDirectBufferSource_MethodInfo_,
	nullptr,
	nullptr,
	_SocketTube$SSLDirectBufferSource_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$SSLDirectBufferSource($Class* clazz) {
	return $of($alloc(SocketTube$SSLDirectBufferSource));
}

bool SocketTube$SSLDirectBufferSource::$assertionsDisabled = false;

void SocketTube$SSLDirectBufferSource::init$($HttpClientImpl* client) {
	$set(this, client, $cast($HttpClientImpl, $Objects::requireNonNull(client)));
	$set(this, factory, $cast($BufferSupplier, $Objects::requireNonNull($(client->getSSLBufferSupplier()))));
}

$ByteBuffer* SocketTube$SSLDirectBufferSource::getBuffer() {
	if (!SocketTube$SSLDirectBufferSource::$assertionsDisabled && !$nc(this->client)->isSelectorThread()) {
		$throwNew($AssertionError);
	}
	$var($ByteBuffer, buf, this->current);
	if (buf == nullptr) {
		$assign(buf, ($set(this, current, $cast($ByteBuffer, $nc(this->factory)->get()))));
	}
	if (!SocketTube$SSLDirectBufferSource::$assertionsDisabled && !$nc(buf)->hasRemaining()) {
		$throwNew($AssertionError);
	}
	if (!SocketTube$SSLDirectBufferSource::$assertionsDisabled && !($nc(buf)->position() == 0)) {
		$throwNew($AssertionError);
	}
	return buf;
}

$List* SocketTube$SSLDirectBufferSource::append($List* list, $ByteBuffer* buf, int32_t start) {
	if (!SocketTube$SSLDirectBufferSource::$assertionsDisabled && !$nc(this->client)->isSelectorThread()) {
		$throwNew($AssertionError);
	}
	if (!SocketTube$SSLDirectBufferSource::$assertionsDisabled && !$nc(buf)->isDirect()) {
		$throwNew($AssertionError);
	}
	if (!SocketTube$SSLDirectBufferSource::$assertionsDisabled && !(start == 0)) {
		$throwNew($AssertionError);
	}
	if (!SocketTube$SSLDirectBufferSource::$assertionsDisabled && !(this->current == buf)) {
		$throwNew($AssertionError);
	}
	$set(this, current, nullptr);
	$nc(buf)->limit(buf->position());
	buf->position(start);
	return $SocketTube::listOf(list, buf);
}

void SocketTube$SSLDirectBufferSource::returnUnused($ByteBuffer* buffer) {
	if (!SocketTube$SSLDirectBufferSource::$assertionsDisabled && !(buffer == this->current)) {
		$throwNew($AssertionError);
	}
	$var($ByteBuffer, buf, this->current);
	if (buf != nullptr) {
		if (!SocketTube$SSLDirectBufferSource::$assertionsDisabled && !(buf->position() == 0)) {
			$throwNew($AssertionError);
		}
		$set(this, current, nullptr);
		buf->limit(buf->position());
		$nc(this->factory)->recycle(buf);
	}
}

void clinit$SocketTube$SSLDirectBufferSource($Class* class$) {
	$load($SocketTube);
	SocketTube$SSLDirectBufferSource::$assertionsDisabled = !$SocketTube::class$->desiredAssertionStatus();
}

SocketTube$SSLDirectBufferSource::SocketTube$SSLDirectBufferSource() {
}

$Class* SocketTube$SSLDirectBufferSource::load$($String* name, bool initialize) {
	$loadClass(SocketTube$SSLDirectBufferSource, name, initialize, &_SocketTube$SSLDirectBufferSource_ClassInfo_, clinit$SocketTube$SSLDirectBufferSource, allocate$SocketTube$SSLDirectBufferSource);
	return class$;
}

$Class* SocketTube$SSLDirectBufferSource::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk