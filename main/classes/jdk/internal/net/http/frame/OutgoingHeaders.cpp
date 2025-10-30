#include <jdk/internal/net/http/frame/OutgoingHeaders.h>

#include <java/net/http/HttpHeaders.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jcpp.h>

#undef PRIORITY

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _OutgoingHeaders_FieldInfo_[] = {
	{"streamDependency", "I", nullptr, 0, $field(OutgoingHeaders, streamDependency)},
	{"weight", "I", nullptr, 0, $field(OutgoingHeaders, weight)},
	{"exclusive", "Z", nullptr, 0, $field(OutgoingHeaders, exclusive)},
	{"attachment", "Ljava/lang/Object;", "TT;", 0, $field(OutgoingHeaders, attachment)},
	{"PRIORITY", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(OutgoingHeaders, PRIORITY)},
	{"user", "Ljava/net/http/HttpHeaders;", nullptr, 0, $field(OutgoingHeaders, user)},
	{"system", "Ljava/net/http/HttpHeaders;", nullptr, 0, $field(OutgoingHeaders, system)},
	{}
};

$MethodInfo _OutgoingHeaders_MethodInfo_[] = {
	{"<init>", "(Ljava/net/http/HttpHeaders;Ljava/net/http/HttpHeaders;Ljava/lang/Object;)V", "(Ljava/net/http/HttpHeaders;Ljava/net/http/HttpHeaders;TT;)V", $PUBLIC, $method(static_cast<void(OutgoingHeaders::*)($HttpHeaders*,$HttpHeaders*,Object$*)>(&OutgoingHeaders::init$))},
	{"getAttachment", "()Ljava/lang/Object;", "()TT;", $PUBLIC},
	{"getExclusive", "()Z", nullptr, $PUBLIC},
	{"getStreamDependency", "()I", nullptr, $PUBLIC},
	{"getSystemHeaders", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC},
	{"getUserHeaders", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC},
	{"getWeight", "()I", nullptr, $PUBLIC},
	{"setPriority", "(IZI)V", nullptr, $PUBLIC},
	{}
};

$ClassInfo _OutgoingHeaders_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.OutgoingHeaders",
	"jdk.internal.net.http.frame.Http2Frame",
	nullptr,
	_OutgoingHeaders_FieldInfo_,
	_OutgoingHeaders_MethodInfo_,
	"<T:Ljava/lang/Object;>Ljdk/internal/net/http/frame/Http2Frame;"
};

$Object* allocate$OutgoingHeaders($Class* clazz) {
	return $of($alloc(OutgoingHeaders));
}

void OutgoingHeaders::init$($HttpHeaders* hdrs1, $HttpHeaders* hdrs2, Object$* attachment) {
	$Http2Frame::init$(0, 0);
	$set(this, user, hdrs2);
	$set(this, system, hdrs1);
	$set(this, attachment, attachment);
}

void OutgoingHeaders::setPriority(int32_t streamDependency, bool exclusive, int32_t weight) {
	this->streamDependency = streamDependency;
	this->exclusive = exclusive;
	this->weight = weight;
	this->flags |= OutgoingHeaders::PRIORITY;
}

int32_t OutgoingHeaders::getStreamDependency() {
	return this->streamDependency;
}

int32_t OutgoingHeaders::getWeight() {
	return this->weight;
}

bool OutgoingHeaders::getExclusive() {
	return this->exclusive;
}

$Object* OutgoingHeaders::getAttachment() {
	return $of(this->attachment);
}

$HttpHeaders* OutgoingHeaders::getUserHeaders() {
	return this->user;
}

$HttpHeaders* OutgoingHeaders::getSystemHeaders() {
	return this->system;
}

OutgoingHeaders::OutgoingHeaders() {
}

$Class* OutgoingHeaders::load$($String* name, bool initialize) {
	$loadClass(OutgoingHeaders, name, initialize, &_OutgoingHeaders_ClassInfo_, allocate$OutgoingHeaders);
	return class$;
}

$Class* OutgoingHeaders::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk