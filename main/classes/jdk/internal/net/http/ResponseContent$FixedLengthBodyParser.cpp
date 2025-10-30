#include <jdk/internal/net/http/ResponseContent$FixedLengthBodyParser.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AbstractSubscription.h>
#include <jdk/internal/net/http/ResponseContent.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $List = ::java::util::List;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $AbstractSubscription = ::jdk::internal::net::http::AbstractSubscription;
using $ResponseContent = ::jdk::internal::net::http::ResponseContent;
using $ResponseContent$BodyParser = ::jdk::internal::net::http::ResponseContent$BodyParser;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class ResponseContent$FixedLengthBodyParser$$Lambda$dbgString : public $Supplier {
	$class(ResponseContent$FixedLengthBodyParser$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(ResponseContent$FixedLengthBodyParser* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseContent$FixedLengthBodyParser$$Lambda$dbgString>());
	}
	ResponseContent$FixedLengthBodyParser* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseContent$FixedLengthBodyParser$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseContent$FixedLengthBodyParser$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo ResponseContent$FixedLengthBodyParser$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseContent$FixedLengthBodyParser;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseContent$FixedLengthBodyParser$$Lambda$dbgString::*)(ResponseContent$FixedLengthBodyParser*)>(&ResponseContent$FixedLengthBodyParser$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseContent$FixedLengthBodyParser$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseContent$FixedLengthBodyParser$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ResponseContent$FixedLengthBodyParser$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(ResponseContent$FixedLengthBodyParser$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseContent$FixedLengthBodyParser$$Lambda$dbgString::class$ = nullptr;

$FieldInfo _ResponseContent$FixedLengthBodyParser_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/ResponseContent;", nullptr, $FINAL | $SYNTHETIC, $field(ResponseContent$FixedLengthBodyParser, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseContent$FixedLengthBodyParser, $assertionsDisabled)},
	{"contentLength", "J", nullptr, $FINAL, $field(ResponseContent$FixedLengthBodyParser, contentLength)},
	{"onComplete", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<Ljava/lang/Throwable;>;", $FINAL, $field(ResponseContent$FixedLengthBodyParser, onComplete)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(ResponseContent$FixedLengthBodyParser, debug)},
	{"dbgTag", "Ljava/lang/String;", nullptr, $FINAL, $field(ResponseContent$FixedLengthBodyParser, dbgTag)},
	{"remaining", "J", nullptr, $VOLATILE, $field(ResponseContent$FixedLengthBodyParser, remaining)},
	{"closedExceptionally", "Ljava/lang/Throwable;", nullptr, $VOLATILE, $field(ResponseContent$FixedLengthBodyParser, closedExceptionally)},
	{"sub", "Ljdk/internal/net/http/AbstractSubscription;", nullptr, $VOLATILE, $field(ResponseContent$FixedLengthBodyParser, sub)},
	{}
};

$MethodInfo _ResponseContent$FixedLengthBodyParser_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseContent;JLjava/util/function/Consumer;)V", "(JLjava/util/function/Consumer<Ljava/lang/Throwable;>;)V", 0, $method(static_cast<void(ResponseContent$FixedLengthBodyParser::*)($ResponseContent*,int64_t,$Consumer*)>(&ResponseContent$FixedLengthBodyParser::init$))},
	{"accept", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"currentStateMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"dbgString", "()Ljava/lang/String;", nullptr, 0},
	{"onSubscribe", "(Ljdk/internal/net/http/AbstractSubscription;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ResponseContent$FixedLengthBodyParser_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseContent$FixedLengthBodyParser", "jdk.internal.net.http.ResponseContent", "FixedLengthBodyParser", 0},
	{"jdk.internal.net.http.ResponseContent$BodyParser", "jdk.internal.net.http.ResponseContent", "BodyParser", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseContent$FixedLengthBodyParser_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.ResponseContent$FixedLengthBodyParser",
	"java.lang.Object",
	"jdk.internal.net.http.ResponseContent$BodyParser",
	_ResponseContent$FixedLengthBodyParser_FieldInfo_,
	_ResponseContent$FixedLengthBodyParser_MethodInfo_,
	nullptr,
	nullptr,
	_ResponseContent$FixedLengthBodyParser_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseContent"
};

$Object* allocate$ResponseContent$FixedLengthBodyParser($Class* clazz) {
	return $of($alloc(ResponseContent$FixedLengthBodyParser));
}

bool ResponseContent$FixedLengthBodyParser::$assertionsDisabled = false;

void ResponseContent$FixedLengthBodyParser::init$($ResponseContent* this$0, int64_t contentLength, $Consumer* onComplete) {
	$set(this, this$0, this$0);
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(ResponseContent$FixedLengthBodyParser$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, dbgTag, $str({this->this$0->dbgTag, "/FixedLengthBodyParser"_s}));
	this->contentLength = (this->remaining = contentLength);
	$set(this, onComplete, onComplete);
}

$String* ResponseContent$FixedLengthBodyParser::dbgString() {
	return this->dbgTag;
}

void ResponseContent$FixedLengthBodyParser::onSubscribe($AbstractSubscription* sub) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"length="_s, $$str(this->contentLength), ", onSubscribe: "_s, $($nc($of(this->this$0->pusher))->getClass()->getName())}));
	}
	$nc(this->this$0->pusher)->onSubscribe(($set(this, sub, sub)));
	try {
		if (this->contentLength == 0) {
			$nc(this->this$0->onFinished)->run();
			$nc(this->this$0->pusher)->onComplete();
			$nc(this->onComplete)->accept(nullptr);
		}
	} catch ($Throwable& t) {
		$set(this, closedExceptionally, t);
		{
			$var($Throwable, var$0, nullptr);
			try {
				$nc(this->this$0->pusher)->onError(t);
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$nc(this->onComplete)->accept(t);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

$String* ResponseContent$FixedLengthBodyParser::currentStateMessage() {
	$useLocalCurrentObjectStackCache();
	return $String::format("fixed content-length: %d, bytes received: %d"_s, $$new($ObjectArray, {
		$($of($Long::valueOf(this->contentLength))),
		$($of($Long::valueOf(this->contentLength - this->remaining)))
	}));
}

void ResponseContent$FixedLengthBodyParser::accept($ByteBuffer* b) {
	$useLocalCurrentObjectStackCache();
	if (this->closedExceptionally != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log($$str({"already closed: "_s, this->closedExceptionally}));
		}
		return;
	}
	bool completed = false;
	try {
		int64_t unfulfilled = this->remaining;
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Parser got %d bytes (%d remaining / %d)"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf($nc(b)->remaining()))),
				$($of($Long::valueOf(unfulfilled))),
				$($of($Long::valueOf(this->contentLength)))
			}));
		}
		if (!ResponseContent$FixedLengthBodyParser::$assertionsDisabled && !(unfulfilled != 0 || this->contentLength == 0 || $nc(b)->remaining() == 0)) {
			$throwNew($AssertionError);
		}
		if (unfulfilled == 0 && this->contentLength > 0) {
			return;
		}
		if ($nc(b)->hasRemaining() && unfulfilled > 0) {
			bool hasDemand = $nc($($nc(this->sub)->demand()))->tryDecrement();
			if (!ResponseContent$FixedLengthBodyParser::$assertionsDisabled && !hasDemand) {
				$throwNew($AssertionError);
			}
			int32_t amount = (int32_t)$Math::min((int64_t)b->remaining(), unfulfilled);
			unfulfilled = this->remaining -= amount;
			$var($ByteBuffer, buffer, $Utils::sliceWithLimitedCapacity(b, amount));
			$nc(this->this$0->pusher)->onNext($($List::of($($of($nc(buffer)->asReadOnlyBuffer())))));
		}
		if (unfulfilled == 0) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("Parser got all expected bytes: completing"_s);
			}
			if (!ResponseContent$FixedLengthBodyParser::$assertionsDisabled && !(this->closedExceptionally == nullptr)) {
				$throwNew($AssertionError);
			}
			$nc(this->this$0->onFinished)->run();
			$nc(this->this$0->pusher)->onComplete();
			completed = true;
			$nc(this->onComplete)->accept(this->closedExceptionally);
		} else if (!ResponseContent$FixedLengthBodyParser::$assertionsDisabled && !($nc(b)->remaining() == 0)) {
			$throwNew($AssertionError);
		}
	} catch ($Throwable& t) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Unexpected exception"_s, t);
		}
		$set(this, closedExceptionally, t);
		if (!completed) {
			$nc(this->onComplete)->accept(t);
		}
	}
}

void ResponseContent$FixedLengthBodyParser::accept(Object$* b) {
	this->accept($cast($ByteBuffer, b));
}

void clinit$ResponseContent$FixedLengthBodyParser($Class* class$) {
	$load($ResponseContent);
	ResponseContent$FixedLengthBodyParser::$assertionsDisabled = !$ResponseContent::class$->desiredAssertionStatus();
}

ResponseContent$FixedLengthBodyParser::ResponseContent$FixedLengthBodyParser() {
}

$Class* ResponseContent$FixedLengthBodyParser::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResponseContent$FixedLengthBodyParser$$Lambda$dbgString::classInfo$.name)) {
			return ResponseContent$FixedLengthBodyParser$$Lambda$dbgString::load$(name, initialize);
		}
	}
	$loadClass(ResponseContent$FixedLengthBodyParser, name, initialize, &_ResponseContent$FixedLengthBodyParser_ClassInfo_, clinit$ResponseContent$FixedLengthBodyParser, allocate$ResponseContent$FixedLengthBodyParser);
	return class$;
}

$Class* ResponseContent$FixedLengthBodyParser::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk