#include <jdk/internal/net/http/ResponseContent.h>

#include <java/io/IOException.h>
#include <java/lang/Runnable.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/util/Optional.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/ResponseContent$BodyParser.h>
#include <jdk/internal/net/http/ResponseContent$ChunkedBodyParser.h>
#include <jdk/internal/net/http/ResponseContent$FixedLengthBodyParser.h>
#include <jdk/internal/net/http/ResponseContent$UnknownLengthBodyParser.h>
#include <jcpp.h>

#undef CR
#undef LF
#undef MAX_CHUNK_HEADER_SIZE

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $Optional = ::java::util::Optional;
using $Consumer = ::java::util::function::Consumer;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $ResponseContent$BodyParser = ::jdk::internal::net::http::ResponseContent$BodyParser;
using $ResponseContent$ChunkedBodyParser = ::jdk::internal::net::http::ResponseContent$ChunkedBodyParser;
using $ResponseContent$FixedLengthBodyParser = ::jdk::internal::net::http::ResponseContent$FixedLengthBodyParser;
using $ResponseContent$UnknownLengthBodyParser = ::jdk::internal::net::http::ResponseContent$UnknownLengthBodyParser;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseContent_FieldInfo_[] = {
	{"pusher", "Ljava/net/http/HttpResponse$BodySubscriber;", "Ljava/net/http/HttpResponse$BodySubscriber<*>;", $FINAL, $field(ResponseContent, pusher)},
	{"contentLength", "J", nullptr, $FINAL, $field(ResponseContent, contentLength)},
	{"headers", "Ljava/net/http/HttpHeaders;", nullptr, $FINAL, $field(ResponseContent, headers)},
	{"onFinished", "Ljava/lang/Runnable;", nullptr, $PRIVATE | $FINAL, $field(ResponseContent, onFinished)},
	{"dbgTag", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(ResponseContent, dbgTag)},
	{"LF", "I", nullptr, $STATIC | $FINAL, $constField(ResponseContent, LF)},
	{"CR", "I", nullptr, $STATIC | $FINAL, $constField(ResponseContent, CR)},
	{"chunkedContent", "Z", nullptr, $PRIVATE, $field(ResponseContent, chunkedContent)},
	{"chunkedContentInitialized", "Z", nullptr, $PRIVATE, $field(ResponseContent, chunkedContentInitialized)},
	{"MAX_CHUNK_HEADER_SIZE", "I", nullptr, $STATIC | $FINAL, $constField(ResponseContent, MAX_CHUNK_HEADER_SIZE)},
	{}
};

$MethodInfo _ResponseContent_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;JLjava/net/http/HttpHeaders;Ljava/net/http/HttpResponse$BodySubscriber;Ljava/lang/Runnable;)V", "(Ljdk/internal/net/http/HttpConnection;JLjava/net/http/HttpHeaders;Ljava/net/http/HttpResponse$BodySubscriber<*>;Ljava/lang/Runnable;)V", 0, $method(static_cast<void(ResponseContent::*)($HttpConnection*,int64_t,$HttpHeaders*,$HttpResponse$BodySubscriber*,$Runnable*)>(&ResponseContent::init$))},
	{"contentChunked", "()Z", nullptr, 0, nullptr, "java.io.IOException"},
	{"getBodyParser", "(Ljava/util/function/Consumer;)Ljdk/internal/net/http/ResponseContent$BodyParser;", "(Ljava/util/function/Consumer<Ljava/lang/Throwable;>;)Ljdk/internal/net/http/ResponseContent$BodyParser;", 0, nullptr, "java.io.IOException"},
	{}
};

$InnerClassInfo _ResponseContent_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseContent$FixedLengthBodyParser", "jdk.internal.net.http.ResponseContent", "FixedLengthBodyParser", 0},
	{"jdk.internal.net.http.ResponseContent$UnknownLengthBodyParser", "jdk.internal.net.http.ResponseContent", "UnknownLengthBodyParser", 0},
	{"jdk.internal.net.http.ResponseContent$ChunkedBodyParser", "jdk.internal.net.http.ResponseContent", "ChunkedBodyParser", 0},
	{"jdk.internal.net.http.ResponseContent$ChunkState", "jdk.internal.net.http.ResponseContent", "ChunkState", $STATIC | $FINAL | $ENUM},
	{"jdk.internal.net.http.ResponseContent$BodyParser", "jdk.internal.net.http.ResponseContent", "BodyParser", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseContent_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.ResponseContent",
	"java.lang.Object",
	nullptr,
	_ResponseContent_FieldInfo_,
	_ResponseContent_MethodInfo_,
	nullptr,
	nullptr,
	_ResponseContent_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseContent$FixedLengthBodyParser,jdk.internal.net.http.ResponseContent$UnknownLengthBodyParser,jdk.internal.net.http.ResponseContent$ChunkedBodyParser,jdk.internal.net.http.ResponseContent$ChunkState,jdk.internal.net.http.ResponseContent$BodyParser"
};

$Object* allocate$ResponseContent($Class* clazz) {
	return $of($alloc(ResponseContent));
}

void ResponseContent::init$($HttpConnection* connection, int64_t contentLength, $HttpHeaders* h, $HttpResponse$BodySubscriber* userSubscriber, $Runnable* onFinished) {
	$set(this, pusher, userSubscriber);
	this->contentLength = contentLength;
	$set(this, headers, h);
	$set(this, onFinished, onFinished);
	$set(this, dbgTag, $str({$($nc(connection)->dbgString()), "/ResponseContent"_s}));
}

bool ResponseContent::contentChunked() {
	$useLocalCurrentObjectStackCache();
	if (this->chunkedContentInitialized) {
		return this->chunkedContent;
	}
	if (this->contentLength == -2) {
		this->chunkedContentInitialized = true;
		this->chunkedContent = false;
		return this->chunkedContent;
	}
	if (this->contentLength == -1) {
		$var($String, tc, $cast($String, $nc($($nc(this->headers)->firstValue("Transfer-Encoding"_s)))->orElse(""_s)));
		if (!$nc(tc)->isEmpty()) {
			if (tc->equalsIgnoreCase("chunked"_s)) {
				this->chunkedContent = true;
			} else {
				$throwNew($IOException, "invalid content"_s);
			}
		} else {
			this->chunkedContent = false;
		}
	}
	this->chunkedContentInitialized = true;
	return this->chunkedContent;
}

$ResponseContent$BodyParser* ResponseContent::getBodyParser($Consumer* onComplete) {
	if (contentChunked()) {
		return $new($ResponseContent$ChunkedBodyParser, this, onComplete);
	} else {
		return this->contentLength == -2 ? static_cast<$ResponseContent$BodyParser*>($new($ResponseContent$UnknownLengthBodyParser, this, onComplete)) : static_cast<$ResponseContent$BodyParser*>($new($ResponseContent$FixedLengthBodyParser, this, this->contentLength, onComplete));
	}
}

ResponseContent::ResponseContent() {
}

$Class* ResponseContent::load$($String* name, bool initialize) {
	$loadClass(ResponseContent, name, initialize, &_ResponseContent_ClassInfo_, allocate$ResponseContent);
	return class$;
}

$Class* ResponseContent::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk