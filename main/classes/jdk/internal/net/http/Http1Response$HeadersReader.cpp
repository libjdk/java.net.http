#include <jdk/internal/net/http/Http1Response$HeadersReader.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/AbstractSubscription.h>
#include <jdk/internal/net/http/Http1HeaderParser.h>
#include <jdk/internal/net/http/Http1Response$Receiver.h>
#include <jdk/internal/net/http/Http1Response$State.h>
#include <jdk/internal/net/http/Http1Response.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef READING_HEADERS

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $AbstractSubscription = ::jdk::internal::net::http::AbstractSubscription;
using $Http1HeaderParser = ::jdk::internal::net::http::Http1HeaderParser;
using $Http1Response = ::jdk::internal::net::http::Http1Response;
using $Http1Response$Receiver = ::jdk::internal::net::http::Http1Response$Receiver;
using $Http1Response$State = ::jdk::internal::net::http::Http1Response$State;
using $Demand = ::jdk::internal::net::http::common::Demand;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http1Response$HeadersReader$$Lambda$currentStateMessage : public $Supplier {
	$class(Http1Response$HeadersReader$$Lambda$currentStateMessage, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Http1HeaderParser* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->currentStateMessage());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$HeadersReader$$Lambda$currentStateMessage>());
	}
	$Http1HeaderParser* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$HeadersReader$$Lambda$currentStateMessage::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Response$HeadersReader$$Lambda$currentStateMessage, inst$)},
	{}
};
$MethodInfo Http1Response$HeadersReader$$Lambda$currentStateMessage::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http1HeaderParser;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$HeadersReader$$Lambda$currentStateMessage::*)($Http1HeaderParser*)>(&Http1Response$HeadersReader$$Lambda$currentStateMessage::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$HeadersReader$$Lambda$currentStateMessage::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$HeadersReader$$Lambda$currentStateMessage",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$HeadersReader$$Lambda$currentStateMessage::load$($String* name, bool initialize) {
	$loadClass(Http1Response$HeadersReader$$Lambda$currentStateMessage, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$HeadersReader$$Lambda$currentStateMessage::class$ = nullptr;

$FieldInfo _Http1Response$HeadersReader_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Http1Response;", nullptr, $FINAL | $SYNTHETIC, $field(Http1Response$HeadersReader, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Response$HeadersReader, $assertionsDisabled)},
	{"onComplete", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<Ljdk/internal/net/http/Http1Response$State;>;", $FINAL, $field(Http1Response$HeadersReader, onComplete)},
	{"parser", "Ljdk/internal/net/http/Http1HeaderParser;", nullptr, $VOLATILE, $field(Http1Response$HeadersReader, parser)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http1Response$State;>;", $VOLATILE, $field(Http1Response$HeadersReader, cf)},
	{"count", "J", nullptr, $VOLATILE, $field(Http1Response$HeadersReader, count)},
	{"subscription", "Ljdk/internal/net/http/AbstractSubscription;", nullptr, $VOLATILE, $field(Http1Response$HeadersReader, subscription$)},
	{}
};

$MethodInfo _Http1Response$HeadersReader_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<Ljdk/internal/net/http/Http1Response$State;>;)V", 0, $method(static_cast<void(Http1Response$HeadersReader::*)($Http1Response*,$Consumer*)>(&Http1Response$HeadersReader::init$))},
	{"close", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"completion", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http1Response$State;>;", 0},
	{"handle", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/Http1HeaderParser;Ljava/util/concurrent/CompletableFuture;)V", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/Http1HeaderParser;Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http1Response$State;>;)V", $FINAL, $method(static_cast<void(Http1Response$HeadersReader::*)($ByteBuffer*,$Http1HeaderParser*,$CompletableFuture*)>(&Http1Response$HeadersReader::handle))},
	{"handle", "(Ljava/nio/ByteBuffer;Ljava/lang/Object;Ljava/util/concurrent/CompletableFuture;)V", nullptr, $VOLATILE | $SYNTHETIC},
	{"onReadError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $FINAL},
	{"onSubscribe", "(Ljdk/internal/net/http/AbstractSubscription;)V", nullptr, $PUBLIC},
	{"reset", "()V", nullptr, 0},
	{"start", "(Ljdk/internal/net/http/Http1HeaderParser;)V", nullptr, $FINAL, $method(static_cast<void(Http1Response$HeadersReader::*)($Http1HeaderParser*)>(&Http1Response$HeadersReader::start))},
	{"start", "(Ljava/lang/Object;)V", nullptr, $VOLATILE | $SYNTHETIC},
	{"subscription", "()Ljdk/internal/net/http/AbstractSubscription;", nullptr, $PUBLIC},
	{"tryAsyncReceive", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _Http1Response$HeadersReader_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Response$HeadersReader", "jdk.internal.net.http.Http1Response", "HeadersReader", $FINAL},
	{"jdk.internal.net.http.Http1Response$Receiver", "jdk.internal.net.http.Http1Response", "Receiver", $STATIC | $ABSTRACT},
	{}
};

$ClassInfo _Http1Response$HeadersReader_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http1Response$HeadersReader",
	"jdk.internal.net.http.Http1Response$Receiver",
	nullptr,
	_Http1Response$HeadersReader_FieldInfo_,
	_Http1Response$HeadersReader_MethodInfo_,
	"Ljdk/internal/net/http/Http1Response$Receiver<Ljdk/internal/net/http/Http1HeaderParser;>;",
	nullptr,
	_Http1Response$HeadersReader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Response"
};

$Object* allocate$Http1Response$HeadersReader($Class* clazz) {
	return $of($alloc(Http1Response$HeadersReader));
}

bool Http1Response$HeadersReader::$assertionsDisabled = false;

void Http1Response$HeadersReader::init$($Http1Response* this$0, $Consumer* onComplete) {
	$set(this, this$0, this$0);
	$Http1Response$Receiver::init$();
	$set(this, onComplete, onComplete);
}

$AbstractSubscription* Http1Response$HeadersReader::subscription() {
	return this->subscription$;
}

void Http1Response$HeadersReader::onSubscribe($AbstractSubscription* s) {
	$set(this, subscription$, s);
	$nc(s)->request(1);
}

void Http1Response$HeadersReader::reset() {
	$set(this, cf, nullptr);
	$set(this, parser, nullptr);
	this->count = 0;
	$set(this, subscription$, nullptr);
}

void Http1Response$HeadersReader::start($Http1HeaderParser* hp) {
	this->count = 0;
	$set(this, cf, $new($MinimalFuture));
	$set(this, parser, hp);
}

$CompletableFuture* Http1Response$HeadersReader::completion() {
	return this->cf;
}

bool Http1Response$HeadersReader::tryAsyncReceive($ByteBuffer* ref) {
	bool hasDemand = $nc($($nc(this->subscription$)->demand()))->tryDecrement();
	if (!Http1Response$HeadersReader::$assertionsDisabled && !hasDemand) {
		$throwNew($AssertionError);
	}
	bool needsMore = accept(ref, this->parser, this->cf);
	if (needsMore) {
		$nc(this->subscription$)->request(1);
	}
	return needsMore;
}

void Http1Response$HeadersReader::onReadError($Throwable* t$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	$assign(t, $Utils::wrapWithExtraDetail(t, static_cast<$Supplier*>($$new(Http1Response$HeadersReader$$Lambda$currentStateMessage, static_cast<$Http1HeaderParser*>($nc(this->parser))))));
	this->this$0->onReadError(t);
}

void Http1Response$HeadersReader::handle($ByteBuffer* b, $Http1HeaderParser* parser, $CompletableFuture* cf) {
	$useLocalCurrentObjectStackCache();
	if (!Http1Response$HeadersReader::$assertionsDisabled && !(cf != nullptr)) {
		$throwNew($AssertionError, $of("parsing not started"_s));
	}
	if (!Http1Response$HeadersReader::$assertionsDisabled && !(parser != nullptr)) {
		$throwNew($AssertionError, $of("no parser"_s));
	}
	try {
		this->count += $nc(b)->remaining();
		if ($nc(this->this$0->debug)->on()) {
			$var($String, var$1, $$str({"Sending "_s, $$str(b->remaining()), "/"_s}));
			$var($String, var$0, $$concat(var$1, $$str(b->capacity())));
			$nc(this->this$0->debug)->log($$concat(var$0, " bytes to header parser"));
		}
		if ($nc(parser)->parse(b)) {
			this->count -= b->remaining();
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log($$str({"Parsing headers completed. bytes="_s, $$str(this->count)}));
			}
			$init($Http1Response$State);
			$nc(this->onComplete)->accept($Http1Response$State::READING_HEADERS);
			$nc(cf)->complete($Http1Response$State::READING_HEADERS);
		}
	} catch ($Throwable& t) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log($$str({"Header parser failed to handle buffer: "_s, t}));
		}
		$nc(cf)->completeExceptionally(t);
	}
}

void Http1Response$HeadersReader::close($Throwable* error) {
	$useLocalCurrentObjectStackCache();
	if (error != nullptr) {
		$var($CompletableFuture, cf, this->cf);
		if (cf != nullptr) {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log($$str({"close: completing header parser CF with "_s, error}));
			}
			cf->completeExceptionally(error);
		}
	}
}

void Http1Response$HeadersReader::handle($ByteBuffer* b, Object$* parser, $CompletableFuture* cf) {
	this->handle(b, $cast($Http1HeaderParser, parser), cf);
}

void Http1Response$HeadersReader::start(Object$* hp) {
	this->start($cast($Http1HeaderParser, hp));
}

void clinit$Http1Response$HeadersReader($Class* class$) {
	$load($Http1Response);
	Http1Response$HeadersReader::$assertionsDisabled = !$Http1Response::class$->desiredAssertionStatus();
}

Http1Response$HeadersReader::Http1Response$HeadersReader() {
}

$Class* Http1Response$HeadersReader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http1Response$HeadersReader$$Lambda$currentStateMessage::classInfo$.name)) {
			return Http1Response$HeadersReader$$Lambda$currentStateMessage::load$(name, initialize);
		}
	}
	$loadClass(Http1Response$HeadersReader, name, initialize, &_Http1Response$HeadersReader_ClassInfo_, clinit$Http1Response$HeadersReader, allocate$Http1Response$HeadersReader);
	return class$;
}

$Class* Http1Response$HeadersReader::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk