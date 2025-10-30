#include <jdk/internal/net/http/Http1Response$BodyReader.h>

#include <java/io/EOFException.h>
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
#include <jdk/internal/net/http/Http1Response$Receiver.h>
#include <jdk/internal/net/http/Http1Response$State.h>
#include <jdk/internal/net/http/Http1Response.h>
#include <jdk/internal/net/http/ResponseContent$BodyParser.h>
#include <jdk/internal/net/http/ResponseContent$UnknownLengthBodyParser.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef READING_BODY

using $EOFException = ::java::io::EOFException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $AbstractSubscription = ::jdk::internal::net::http::AbstractSubscription;
using $Http1Response = ::jdk::internal::net::http::Http1Response;
using $Http1Response$Receiver = ::jdk::internal::net::http::Http1Response$Receiver;
using $Http1Response$State = ::jdk::internal::net::http::Http1Response$State;
using $ResponseContent$BodyParser = ::jdk::internal::net::http::ResponseContent$BodyParser;
using $ResponseContent$UnknownLengthBodyParser = ::jdk::internal::net::http::ResponseContent$UnknownLengthBodyParser;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http1Response$BodyReader$$Lambda$currentStateMessage : public $Supplier {
	$class(Http1Response$BodyReader$$Lambda$currentStateMessage, $NO_CLASS_INIT, $Supplier)
public:
	void init$($ResponseContent$BodyParser* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->currentStateMessage());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1Response$BodyReader$$Lambda$currentStateMessage>());
	}
	$ResponseContent$BodyParser* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http1Response$BodyReader$$Lambda$currentStateMessage::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http1Response$BodyReader$$Lambda$currentStateMessage, inst$)},
	{}
};
$MethodInfo Http1Response$BodyReader$$Lambda$currentStateMessage::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseContent$BodyParser;)V", nullptr, $PUBLIC, $method(static_cast<void(Http1Response$BodyReader$$Lambda$currentStateMessage::*)($ResponseContent$BodyParser*)>(&Http1Response$BodyReader$$Lambda$currentStateMessage::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1Response$BodyReader$$Lambda$currentStateMessage::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1Response$BodyReader$$Lambda$currentStateMessage",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http1Response$BodyReader$$Lambda$currentStateMessage::load$($String* name, bool initialize) {
	$loadClass(Http1Response$BodyReader$$Lambda$currentStateMessage, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1Response$BodyReader$$Lambda$currentStateMessage::class$ = nullptr;

$FieldInfo _Http1Response$BodyReader_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Http1Response;", nullptr, $FINAL | $SYNTHETIC, $field(Http1Response$BodyReader, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1Response$BodyReader, $assertionsDisabled)},
	{"onComplete", "Ljava/util/function/Consumer;", "Ljava/util/function/Consumer<Ljdk/internal/net/http/Http1Response$State;>;", $FINAL, $field(Http1Response$BodyReader, onComplete$)},
	{"parser", "Ljdk/internal/net/http/ResponseContent$BodyParser;", nullptr, $VOLATILE, $field(Http1Response$BodyReader, parser)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http1Response$State;>;", $VOLATILE, $field(Http1Response$BodyReader, cf)},
	{"subscription", "Ljdk/internal/net/http/AbstractSubscription;", nullptr, $VOLATILE, $field(Http1Response$BodyReader, subscription$)},
	{}
};

$MethodInfo _Http1Response$BodyReader_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http1Response;Ljava/util/function/Consumer;)V", "(Ljava/util/function/Consumer<Ljdk/internal/net/http/Http1Response$State;>;)V", 0, $method(static_cast<void(Http1Response$BodyReader::*)($Http1Response*,$Consumer*)>(&Http1Response$BodyReader::init$))},
	{"close", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $FINAL},
	{"completion", "()Ljava/util/concurrent/CompletableFuture;", "()Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http1Response$State;>;", 0},
	{"handle", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/ResponseContent$BodyParser;Ljava/util/concurrent/CompletableFuture;)V", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/ResponseContent$BodyParser;Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http1Response$State;>;)V", $FINAL, $method(static_cast<void(Http1Response$BodyReader::*)($ByteBuffer*,$ResponseContent$BodyParser*,$CompletableFuture*)>(&Http1Response$BodyReader::handle))},
	{"handle", "(Ljava/nio/ByteBuffer;Ljava/lang/Object;Ljava/util/concurrent/CompletableFuture;)V", nullptr, $VOLATILE | $SYNTHETIC},
	{"onComplete", "(Ljava/lang/Throwable;)V", nullptr, $FINAL, $method(static_cast<void(Http1Response$BodyReader::*)($Throwable*)>(&Http1Response$BodyReader::onComplete))},
	{"onReadError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $FINAL},
	{"onSubscribe", "(Ljdk/internal/net/http/AbstractSubscription;)V", nullptr, $PUBLIC},
	{"reset", "()V", nullptr, 0},
	{"start", "(Ljdk/internal/net/http/ResponseContent$BodyParser;)V", nullptr, $FINAL, $method(static_cast<void(Http1Response$BodyReader::*)($ResponseContent$BodyParser*)>(&Http1Response$BodyReader::start))},
	{"start", "(Ljava/lang/Object;)V", nullptr, $VOLATILE | $SYNTHETIC},
	{"subscription", "()Ljdk/internal/net/http/AbstractSubscription;", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"tryAsyncReceive", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _Http1Response$BodyReader_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1Response$BodyReader", "jdk.internal.net.http.Http1Response", "BodyReader", $FINAL},
	{"jdk.internal.net.http.Http1Response$Receiver", "jdk.internal.net.http.Http1Response", "Receiver", $STATIC | $ABSTRACT},
	{"jdk.internal.net.http.ResponseContent$BodyParser", "jdk.internal.net.http.ResponseContent", "BodyParser", $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Http1Response$BodyReader_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http1Response$BodyReader",
	"jdk.internal.net.http.Http1Response$Receiver",
	nullptr,
	_Http1Response$BodyReader_FieldInfo_,
	_Http1Response$BodyReader_MethodInfo_,
	"Ljdk/internal/net/http/Http1Response$Receiver<Ljdk/internal/net/http/ResponseContent$BodyParser;>;",
	nullptr,
	_Http1Response$BodyReader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1Response"
};

$Object* allocate$Http1Response$BodyReader($Class* clazz) {
	return $of($alloc(Http1Response$BodyReader));
}

bool Http1Response$BodyReader::$assertionsDisabled = false;

void Http1Response$BodyReader::init$($Http1Response* this$0, $Consumer* onComplete) {
	$set(this, this$0, this$0);
	$Http1Response$Receiver::init$();
	$set(this, onComplete$, onComplete);
}

void Http1Response$BodyReader::reset() {
	$set(this, parser, nullptr);
	$set(this, cf, nullptr);
	$set(this, subscription$, nullptr);
}

void Http1Response$BodyReader::start($ResponseContent$BodyParser* parser) {
	$set(this, cf, $new($MinimalFuture));
	$set(this, parser, parser);
}

$CompletableFuture* Http1Response$BodyReader::completion() {
	return this->cf;
}

bool Http1Response$BodyReader::tryAsyncReceive($ByteBuffer* b) {
	return accept(b, this->parser, this->cf);
}

void Http1Response$BodyReader::onReadError($Throwable* t$renamed) {
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	if ($instanceOf($EOFException, t) && this->this$0->bodyParser != nullptr && $instanceOf($ResponseContent$UnknownLengthBodyParser, this->this$0->bodyParser)) {
		$nc(($cast($ResponseContent$UnknownLengthBodyParser, this->this$0->bodyParser)))->complete();
		return;
	}
	$assign(t, $Utils::wrapWithExtraDetail(t, static_cast<$Supplier*>($$new(Http1Response$BodyReader$$Lambda$currentStateMessage, static_cast<$ResponseContent$BodyParser*>($nc(this->parser))))));
	this->this$0->onReadError(t);
}

$AbstractSubscription* Http1Response$BodyReader::subscription() {
	return this->subscription$;
}

void Http1Response$BodyReader::onSubscribe($AbstractSubscription* s) {
	$set(this, subscription$, s);
	try {
		$nc(this->parser)->onSubscribe(s);
	} catch ($Throwable& t) {
		$nc(this->cf)->completeExceptionally(t);
		$throw(t);
	}
}

void Http1Response$BodyReader::handle($ByteBuffer* b, $ResponseContent$BodyParser* parser, $CompletableFuture* cf) {
	$useLocalCurrentObjectStackCache();
	if (!Http1Response$BodyReader::$assertionsDisabled && !(cf != nullptr)) {
		$throwNew($AssertionError, $of("parsing not started"_s));
	}
	if (!Http1Response$BodyReader::$assertionsDisabled && !(parser != nullptr)) {
		$throwNew($AssertionError, $of("no parser"_s));
	}
	try {
		if ($nc(this->this$0->debug)->on()) {
			$var($String, var$1, $$str({"Sending "_s, $$str($nc(b)->remaining()), "/"_s}));
			$var($String, var$0, $$concat(var$1, $$str(b->capacity())));
			$nc(this->this$0->debug)->log($$concat(var$0, " bytes to body parser"));
		}
		$nc(parser)->accept(b);
	} catch ($Throwable& t) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log($$str({"Body parser failed to handle buffer: "_s, t}));
		}
		if (!$nc(cf)->isDone()) {
			cf->completeExceptionally(t);
		}
	}
}

void Http1Response$BodyReader::onComplete($Throwable* closedExceptionally) {
	if ($nc(this->cf)->isDone()) {
		return;
	}
	if (closedExceptionally != nullptr) {
		$nc(this->cf)->completeExceptionally(closedExceptionally);
	} else {
		$init($Http1Response$State);
		$nc(this->onComplete$)->accept($Http1Response$State::READING_BODY);
		$nc(this->cf)->complete($Http1Response$State::READING_BODY);
	}
}

void Http1Response$BodyReader::close($Throwable* error) {
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, cf, this->cf);
	if (cf != nullptr && !cf->isDone()) {
		if (error != nullptr) {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log($$str({"close: completing body parser CF with "_s, error}));
			}
			cf->completeExceptionally(error);
		} else {
			if ($nc(this->this$0->debug)->on()) {
				$nc(this->this$0->debug)->log("close: completing body parser CF"_s);
			}
			$init($Http1Response$State);
			cf->complete($Http1Response$State::READING_BODY);
		}
	}
}

$String* Http1Response$BodyReader::toString() {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $$str({$($Http1Response$Receiver::toString()), "/parser="_s}));
	return $concat(var$0, $($String::valueOf($of(this->parser))));
}

void Http1Response$BodyReader::handle($ByteBuffer* b, Object$* parser, $CompletableFuture* cf) {
	this->handle(b, $cast($ResponseContent$BodyParser, parser), cf);
}

void Http1Response$BodyReader::start(Object$* parser) {
	this->start($cast($ResponseContent$BodyParser, parser));
}

void clinit$Http1Response$BodyReader($Class* class$) {
	$load($Http1Response);
	Http1Response$BodyReader::$assertionsDisabled = !$Http1Response::class$->desiredAssertionStatus();
}

Http1Response$BodyReader::Http1Response$BodyReader() {
}

$Class* Http1Response$BodyReader::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http1Response$BodyReader$$Lambda$currentStateMessage::classInfo$.name)) {
			return Http1Response$BodyReader$$Lambda$currentStateMessage::load$(name, initialize);
		}
	}
	$loadClass(Http1Response$BodyReader, name, initialize, &_Http1Response$BodyReader_ClassInfo_, clinit$Http1Response$BodyReader, allocate$Http1Response$BodyReader);
	return class$;
}

$Class* Http1Response$BodyReader::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk