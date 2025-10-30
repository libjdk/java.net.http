#include <jdk/internal/net/http/Http2Connection$FramesController.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/frame/FramesDecoder.h>
#include <jcpp.h>

#undef EMPTY_TRIGGER

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Supplier = ::java::util::function::Supplier;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $FramesDecoder = ::jdk::internal::net::http::frame::FramesDecoder;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0 : public $Supplier {
	$class(Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$($List* pending) {
		$set(this, pending, pending);
	}
	virtual $Object* get() override {
		 return $of(Http2Connection$FramesController::lambda$processReceivedData$0(pending));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0>());
	}
	$List* pending = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0::fieldInfos[2] = {
	{"pending", "Ljava/util/List;", nullptr, $PUBLIC, $field(Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0, pending)},
	{}
};
$MethodInfo Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/List;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0::*)($List*)>(&Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0::class$ = nullptr;

$FieldInfo _Http2Connection$FramesController_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Http2Connection;", nullptr, $FINAL | $SYNTHETIC, $field(Http2Connection$FramesController, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http2Connection$FramesController, $assertionsDisabled)},
	{"prefaceSent", "Z", nullptr, $VOLATILE, $field(Http2Connection$FramesController, prefaceSent)},
	{"pending", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $VOLATILE, $field(Http2Connection$FramesController, pending)},
	{}
};

$MethodInfo _Http2Connection$FramesController_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http2Connection;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection$FramesController::*)($Http2Connection*)>(&Http2Connection$FramesController::init$))},
	{"lambda$processReceivedData$0", "(Ljava/util/List;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($List*)>(&Http2Connection$FramesController::lambda$processReceivedData$0))},
	{"markPrefaceSent", "()V", nullptr, 0, $method(static_cast<void(Http2Connection$FramesController::*)()>(&Http2Connection$FramesController::markPrefaceSent))},
	{"processReceivedData", "(Ljdk/internal/net/http/frame/FramesDecoder;Ljava/nio/ByteBuffer;)Z", nullptr, 0, $method(static_cast<bool(Http2Connection$FramesController::*)($FramesDecoder*,$ByteBuffer*)>(&Http2Connection$FramesController::processReceivedData)), "java.io.IOException"},
	{}
};

$InnerClassInfo _Http2Connection$FramesController_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http2Connection$FramesController", "jdk.internal.net.http.Http2Connection", "FramesController", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _Http2Connection$FramesController_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http2Connection$FramesController",
	"java.lang.Object",
	nullptr,
	_Http2Connection$FramesController_FieldInfo_,
	_Http2Connection$FramesController_MethodInfo_,
	nullptr,
	nullptr,
	_Http2Connection$FramesController_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http2Connection"
};

$Object* allocate$Http2Connection$FramesController($Class* clazz) {
	return $of($alloc(Http2Connection$FramesController));
}

bool Http2Connection$FramesController::$assertionsDisabled = false;

void Http2Connection$FramesController::init$($Http2Connection* this$0) {
	$set(this, this$0, this$0);
}

bool Http2Connection$FramesController::processReceivedData($FramesDecoder* decoder, $ByteBuffer* buf) {
	$useLocalCurrentObjectStackCache();
	if (!this->prefaceSent) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("Preface not sent: buffering %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(buf)->remaining())))}));
		}
		$synchronized(this) {
			if (!this->prefaceSent) {
				if (this->pending == nullptr) {
					$set(this, pending, $new($ArrayList));
				}
				$nc(this->pending)->add(buf);
				if ($nc(this->this$0->debug)->on()) {
					$nc(this->this$0->debug)->log($$str({"there are now %d bytes buffered waiting for preface to be sent"_s, $$str($Utils::remaining(this->pending))}));
				}
				return false;
			}
		}
	}
	$var($List, pending, this->pending);
	$set(this, pending, nullptr);
	if (pending != nullptr) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log(static_cast<$Supplier*>($$new(Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0, pending)));
		}
		{
			$var($Iterator, i$, pending->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($ByteBuffer, b, $cast($ByteBuffer, i$->next()));
				{
					$nc(decoder)->decode(b);
				}
			}
		}
	}
	$init($Http2Connection);
	if (buf != $Http2Connection::EMPTY_TRIGGER) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("Processing %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(buf)->remaining())))}));
		}
		$nc(decoder)->decode(buf);
	}
	return true;
}

void Http2Connection$FramesController::markPrefaceSent() {
	if (!Http2Connection$FramesController::$assertionsDisabled && ! !this->prefaceSent) {
		$throwNew($AssertionError);
	}
	$synchronized(this) {
		this->prefaceSent = true;
	}
}

$String* Http2Connection$FramesController::lambda$processReceivedData$0($List* pending) {
	$init(Http2Connection$FramesController);
	return $str({"Processing buffered data: "_s, $$str($Utils::remaining(pending))});
}

void clinit$Http2Connection$FramesController($Class* class$) {
	$load($Http2Connection);
	Http2Connection$FramesController::$assertionsDisabled = !$Http2Connection::class$->desiredAssertionStatus();
}

Http2Connection$FramesController::Http2Connection$FramesController() {
}

$Class* Http2Connection$FramesController::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0::classInfo$.name)) {
			return Http2Connection$FramesController$$Lambda$lambda$processReceivedData$0::load$(name, initialize);
		}
	}
	$loadClass(Http2Connection$FramesController, name, initialize, &_Http2Connection$FramesController_ClassInfo_, clinit$Http2Connection$FramesController, allocate$Http2Connection$FramesController);
	return class$;
}

$Class* Http2Connection$FramesController::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk