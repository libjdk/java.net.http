#include <jdk/internal/net/http/Stream$StreamWindowUpdateSender.h>

#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/Stream.h>
#include <jdk/internal/net/http/WindowUpdateSender.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;
using $Stream = ::jdk::internal::net::http::Stream;
using $WindowUpdateSender = ::jdk::internal::net::http::WindowUpdateSender;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _Stream$StreamWindowUpdateSender_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Stream;", nullptr, $FINAL | $SYNTHETIC, $field(Stream$StreamWindowUpdateSender, this$0)},
	{}
};

$MethodInfo _Stream$StreamWindowUpdateSender_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Stream;Ljdk/internal/net/http/Http2Connection;)V", nullptr, 0, $method(static_cast<void(Stream$StreamWindowUpdateSender::*)($Stream*,$Http2Connection*)>(&Stream$StreamWindowUpdateSender::init$))},
	{"dbgString", "()Ljava/lang/String;", nullptr, 0},
	{"getStreamId", "()I", nullptr, 0},
	{}
};

$InnerClassInfo _Stream$StreamWindowUpdateSender_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Stream$StreamWindowUpdateSender", "jdk.internal.net.http.Stream", "StreamWindowUpdateSender", $FINAL},
	{}
};

$ClassInfo _Stream$StreamWindowUpdateSender_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Stream$StreamWindowUpdateSender",
	"jdk.internal.net.http.WindowUpdateSender",
	nullptr,
	_Stream$StreamWindowUpdateSender_FieldInfo_,
	_Stream$StreamWindowUpdateSender_MethodInfo_,
	nullptr,
	nullptr,
	_Stream$StreamWindowUpdateSender_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Stream"
};

$Object* allocate$Stream$StreamWindowUpdateSender($Class* clazz) {
	return $of($alloc(Stream$StreamWindowUpdateSender));
}

void Stream$StreamWindowUpdateSender::init$($Stream* this$0, $Http2Connection* connection) {
	$set(this, this$0, this$0);
	$WindowUpdateSender::init$(connection);
}

int32_t Stream$StreamWindowUpdateSender::getStreamId() {
	return this->this$0->streamid;
}

$String* Stream$StreamWindowUpdateSender::dbgString() {
	$useLocalCurrentObjectStackCache();
	$var($String, dbg, this->$WindowUpdateSender::dbgString$);
	if (dbg != nullptr) {
		return dbg;
	}
	if (this->this$0->streamid == 0) {
		return $str({$($nc(this->connection)->dbgString()), ":WindowUpdateSender(stream: ?)"_s});
	} else {
		$assign(dbg, $str({$($nc(this->connection)->dbgString()), ":WindowUpdateSender(stream: "_s, $$str(this->this$0->streamid), ")"_s}));
		return $set(this, dbgString$, dbg);
	}
}

Stream$StreamWindowUpdateSender::Stream$StreamWindowUpdateSender() {
}

$Class* Stream$StreamWindowUpdateSender::load$($String* name, bool initialize) {
	$loadClass(Stream$StreamWindowUpdateSender, name, initialize, &_Stream$StreamWindowUpdateSender_ClassInfo_, allocate$Stream$StreamWindowUpdateSender);
	return class$;
}

$Class* Stream$StreamWindowUpdateSender::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk