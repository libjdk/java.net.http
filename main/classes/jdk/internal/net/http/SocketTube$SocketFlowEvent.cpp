#include <jdk/internal/net/http/SocketTube$SocketFlowEvent.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/nio/channels/spi/AbstractSelectableChannel.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jcpp.h>

#undef REPEATING

using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AbstractSelectableChannel = ::java::nio::channels::spi::AbstractSelectableChannel;
using $Supplier = ::java::util::function::Supplier;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0 : public $Supplier {
	$class(SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$(SocketTube$SocketFlowEvent* inst, $IOException* error) {
		$set(this, inst$, inst);
		$set(this, error, error);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$abort$0(error));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0>());
	}
	SocketTube$SocketFlowEvent* inst$ = nullptr;
	$IOException* error = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0, inst$)},
	{"error", "Ljava/io/IOException;", nullptr, $PUBLIC, $field(SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0, error)},
	{}
};
$MethodInfo SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/SocketTube$SocketFlowEvent;Ljava/io/IOException;)V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0::*)(SocketTube$SocketFlowEvent*,$IOException*)>(&SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0::load$($String* name, bool initialize) {
	$loadClass(SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0::class$ = nullptr;

$FieldInfo _SocketTube$SocketFlowEvent_FieldInfo_[] = {
	{"channel", "Ljava/nio/channels/SocketChannel;", nullptr, $FINAL, $field(SocketTube$SocketFlowEvent, channel$)},
	{"defaultInterest", "I", nullptr, $FINAL, $field(SocketTube$SocketFlowEvent, defaultInterest)},
	{"interestOps", "I", nullptr, $VOLATILE, $field(SocketTube$SocketFlowEvent, interestOps$)},
	{"registered", "Z", nullptr, $VOLATILE, $field(SocketTube$SocketFlowEvent, registered$)},
	{}
};

$MethodInfo _SocketTube$SocketFlowEvent_MethodInfo_[] = {
	{"<init>", "(ILjava/nio/channels/SocketChannel;)V", nullptr, 0, $method(static_cast<void(SocketTube$SocketFlowEvent::*)(int32_t,$SocketChannel*)>(&SocketTube$SocketFlowEvent::init$))},
	{"abort", "(Ljava/io/IOException;)V", nullptr, $PUBLIC | $FINAL},
	{"channel", "()Ljava/nio/channels/SelectableChannel;", nullptr, $PUBLIC | $FINAL},
	{"debug", "()Ljdk/internal/net/http/common/Logger;", nullptr, $ABSTRACT},
	{"handle", "()V", nullptr, $PUBLIC | $FINAL},
	{"interestOps", "()I", nullptr, $PUBLIC | $FINAL},
	{"lambda$abort$0", "(Ljava/io/IOException;)Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(SocketTube$SocketFlowEvent::*)($IOException*)>(&SocketTube$SocketFlowEvent::lambda$abort$0))},
	{"pause", "()V", nullptr, $FINAL, $method(static_cast<void(SocketTube$SocketFlowEvent::*)()>(&SocketTube$SocketFlowEvent::pause))},
	{"registered", "()Z", nullptr, $FINAL, $method(static_cast<bool(SocketTube$SocketFlowEvent::*)()>(&SocketTube$SocketFlowEvent::registered))},
	{"resume", "()V", nullptr, $FINAL, $method(static_cast<void(SocketTube$SocketFlowEvent::*)()>(&SocketTube$SocketFlowEvent::resume))},
	{"signalError", "(Ljava/lang/Throwable;)V", nullptr, $PROTECTED | $ABSTRACT},
	{"signalEvent", "()V", nullptr, $PROTECTED | $ABSTRACT},
	{}
};

$InnerClassInfo _SocketTube$SocketFlowEvent_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$SocketFlowEvent", "jdk.internal.net.http.SocketTube", "SocketFlowEvent", $PRIVATE | $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _SocketTube$SocketFlowEvent_ClassInfo_ = {
	$ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.SocketTube$SocketFlowEvent",
	"jdk.internal.net.http.AsyncEvent",
	nullptr,
	_SocketTube$SocketFlowEvent_FieldInfo_,
	_SocketTube$SocketFlowEvent_MethodInfo_,
	nullptr,
	nullptr,
	_SocketTube$SocketFlowEvent_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$SocketFlowEvent($Class* clazz) {
	return $of($alloc(SocketTube$SocketFlowEvent));
}

void SocketTube$SocketFlowEvent::init$(int32_t defaultInterest, $SocketChannel* channel) {
	$AsyncEvent::init$($AsyncEvent::REPEATING);
	this->defaultInterest = defaultInterest;
	$set(this, channel$, channel);
}

bool SocketTube$SocketFlowEvent::registered() {
	return this->registered$;
}

void SocketTube$SocketFlowEvent::resume() {
	this->interestOps$ = this->defaultInterest;
	this->registered$ = true;
}

void SocketTube$SocketFlowEvent::pause() {
	this->interestOps$ = 0;
}

$SelectableChannel* SocketTube$SocketFlowEvent::channel() {
	return this->channel$;
}

int32_t SocketTube$SocketFlowEvent::interestOps() {
	return this->interestOps$;
}

void SocketTube$SocketFlowEvent::handle() {
	pause();
	signalEvent();
}

void SocketTube$SocketFlowEvent::abort($IOException* error) {
	$useLocalCurrentObjectStackCache();
	$nc($(debug()))->log(static_cast<$Supplier*>($$new(SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0, this, error)));
	pause();
	signalError(error);
}

$String* SocketTube$SocketFlowEvent::lambda$abort$0($IOException* error) {
	return $str({$($of(this)->getClass()->getSimpleName()), " abort: "_s, error});
}

SocketTube$SocketFlowEvent::SocketTube$SocketFlowEvent() {
}

$Class* SocketTube$SocketFlowEvent::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0::classInfo$.name)) {
			return SocketTube$SocketFlowEvent$$Lambda$lambda$abort$0::load$(name, initialize);
		}
	}
	$loadClass(SocketTube$SocketFlowEvent, name, initialize, &_SocketTube$SocketFlowEvent_ClassInfo_, allocate$SocketTube$SocketFlowEvent);
	return class$;
}

$Class* SocketTube$SocketFlowEvent::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk