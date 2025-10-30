#include <jdk/internal/net/http/ResponseContent$UnknownLengthBodyParser.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
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

class ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString : public $Supplier {
	$class(ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(ResponseContent$UnknownLengthBodyParser* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString>());
	}
	ResponseContent$UnknownLengthBodyParser* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseContent$UnknownLengthBodyParser;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString::*)(ResponseContent$UnknownLengthBodyParser*)>(&ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString::class$ = nullptr;

$FieldInfo _ResponseContent$UnknownLengthBodyParser_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/ResponseContent;", nullptr, $FINAL | $SYNTHETIC, $field(ResponseContent$UnknownLengthBodyParser, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseContent$UnknownLengthBodyParser, $assertionsDisabled)},
	{"onComplete", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<Ljava/lang/Throwable;>;", $FINAL, $field(ResponseContent$UnknownLengthBodyParser, onComplete)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(ResponseContent$UnknownLengthBodyParser, debug)},
	{"dbgTag", "Ljava/lang/String;", nullptr, $FINAL, $field(ResponseContent$UnknownLengthBodyParser, dbgTag)},
	{"closedExceptionally", "Ljava/lang/Throwable;", nullptr, $VOLATILE, $field(ResponseContent$UnknownLengthBodyParser, closedExceptionally)},
	{"sub", "Ljdk/internal/net/http/AbstractSubscription;", nullptr, $VOLATILE, $field(ResponseContent$UnknownLengthBodyParser, sub)},
	{"breceived", "I", nullptr, $VOLATILE, $field(ResponseContent$UnknownLengthBodyParser, breceived)},
	{}
};

$MethodInfo _ResponseContent$UnknownLengthBodyParser_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseContent;Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<Ljava/lang/Throwable;>;)V", 0, $method(static_cast<void(ResponseContent$UnknownLengthBodyParser::*)($ResponseContent*,$Consumer*)>(&ResponseContent$UnknownLengthBodyParser::init$))},
	{"accept", "(Ljava/nio/ByteBuffer;)V", nullptr, $PUBLIC},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"complete", "()V", nullptr, $PUBLIC},
	{"currentStateMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"dbgString", "()Ljava/lang/String;", nullptr, 0},
	{"onSubscribe", "(Ljdk/internal/net/http/AbstractSubscription;)V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ResponseContent$UnknownLengthBodyParser_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseContent$UnknownLengthBodyParser", "jdk.internal.net.http.ResponseContent", "UnknownLengthBodyParser", 0},
	{"jdk.internal.net.http.ResponseContent$BodyParser", "jdk.internal.net.http.ResponseContent", "BodyParser", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseContent$UnknownLengthBodyParser_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.ResponseContent$UnknownLengthBodyParser",
	"java.lang.Object",
	"jdk.internal.net.http.ResponseContent$BodyParser",
	_ResponseContent$UnknownLengthBodyParser_FieldInfo_,
	_ResponseContent$UnknownLengthBodyParser_MethodInfo_,
	nullptr,
	nullptr,
	_ResponseContent$UnknownLengthBodyParser_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseContent"
};

$Object* allocate$ResponseContent$UnknownLengthBodyParser($Class* clazz) {
	return $of($alloc(ResponseContent$UnknownLengthBodyParser));
}

bool ResponseContent$UnknownLengthBodyParser::$assertionsDisabled = false;

void ResponseContent$UnknownLengthBodyParser::init$($ResponseContent* this$0, $Consumer* onComplete) {
	$set(this, this$0, this$0);
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, dbgTag, $str({this->this$0->dbgTag, "/UnknownLengthBodyParser"_s}));
	this->breceived = 0;
	$set(this, onComplete, onComplete);
}

$String* ResponseContent$UnknownLengthBodyParser::dbgString() {
	return this->dbgTag;
}

void ResponseContent$UnknownLengthBodyParser::onSubscribe($AbstractSubscription* sub) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log($$str({"onSubscribe: "_s, $($nc($of(this->this$0->pusher))->getClass()->getName())}));
	}
	$nc(this->this$0->pusher)->onSubscribe(($set(this, sub, sub)));
}

$String* ResponseContent$UnknownLengthBodyParser::currentStateMessage() {
	$useLocalCurrentObjectStackCache();
	return $String::format("http1_0 content, bytes received: %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->breceived)))}));
}

void ResponseContent$UnknownLengthBodyParser::accept($ByteBuffer* b) {
	$useLocalCurrentObjectStackCache();
	if (this->closedExceptionally != nullptr) {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log($$str({"already closed: "_s, this->closedExceptionally}));
		}
		return;
	}
	bool completed = false;
	try {
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("Parser got %d bytes "_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(b)->remaining())))}));
		}
		if ($nc(b)->hasRemaining()) {
			bool hasDemand = $nc($($nc(this->sub)->demand()))->tryDecrement();
			if (!ResponseContent$UnknownLengthBodyParser::$assertionsDisabled && !hasDemand) {
				$throwNew($AssertionError);
			}
			this->breceived += b->remaining();
			$nc(this->this$0->pusher)->onNext($($List::of($($of(b->asReadOnlyBuffer())))));
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

void ResponseContent$UnknownLengthBodyParser::complete() {
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Parser got all expected bytes: completing"_s);
	}
	if (!ResponseContent$UnknownLengthBodyParser::$assertionsDisabled && !(this->closedExceptionally == nullptr)) {
		$throwNew($AssertionError);
	}
	$nc(this->this$0->onFinished)->run();
	$nc(this->this$0->pusher)->onComplete();
	$nc(this->onComplete)->accept(this->closedExceptionally);
}

void ResponseContent$UnknownLengthBodyParser::accept(Object$* b) {
	this->accept($cast($ByteBuffer, b));
}

void clinit$ResponseContent$UnknownLengthBodyParser($Class* class$) {
	$load($ResponseContent);
	ResponseContent$UnknownLengthBodyParser::$assertionsDisabled = !$ResponseContent::class$->desiredAssertionStatus();
}

ResponseContent$UnknownLengthBodyParser::ResponseContent$UnknownLengthBodyParser() {
}

$Class* ResponseContent$UnknownLengthBodyParser::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString::classInfo$.name)) {
			return ResponseContent$UnknownLengthBodyParser$$Lambda$dbgString::load$(name, initialize);
		}
	}
	$loadClass(ResponseContent$UnknownLengthBodyParser, name, initialize, &_ResponseContent$UnknownLengthBodyParser_ClassInfo_, clinit$ResponseContent$UnknownLengthBodyParser, allocate$ResponseContent$UnknownLengthBodyParser);
	return class$;
}

$Class* ResponseContent$UnknownLengthBodyParser::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk