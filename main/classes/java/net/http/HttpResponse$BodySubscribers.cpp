#include <java/net/http/HttpResponse$BodySubscribers.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardOpenOption.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/BufferingSubscriber.h>
#include <jdk/internal/net/http/LineSubscriberAdapter.h>
#include <jdk/internal/net/http/ResponseSubscribers$ByteArraySubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$ConsumerSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$HttpResponseInputStream.h>
#include <jdk/internal/net/http/ResponseSubscribers$MappingSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$NullSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$PathSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$SubscriberAdapter.h>
#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jcpp.h>

#undef CREATE
#undef DELETE_ON_CLOSE
#undef READ
#undef UTF_8
#undef WRITE

using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $OpenOption = ::java::nio::file::OpenOption;
using $Path = ::java::nio::file::Path;
using $StandardOpenOption = ::java::nio::file::StandardOpenOption;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $BufferingSubscriber = ::jdk::internal::net::http::BufferingSubscriber;
using $LineSubscriberAdapter = ::jdk::internal::net::http::LineSubscriberAdapter;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseSubscribers$ByteArraySubscriber = ::jdk::internal::net::http::ResponseSubscribers$ByteArraySubscriber;
using $ResponseSubscribers$ConsumerSubscriber = ::jdk::internal::net::http::ResponseSubscribers$ConsumerSubscriber;
using $ResponseSubscribers$HttpResponseInputStream = ::jdk::internal::net::http::ResponseSubscribers$HttpResponseInputStream;
using $ResponseSubscribers$MappingSubscriber = ::jdk::internal::net::http::ResponseSubscribers$MappingSubscriber;
using $ResponseSubscribers$NullSubscriber = ::jdk::internal::net::http::ResponseSubscribers$NullSubscriber;
using $ResponseSubscribers$PathSubscriber = ::jdk::internal::net::http::ResponseSubscribers$PathSubscriber;
using $ResponseSubscribers$SubscriberAdapter = ::jdk::internal::net::http::ResponseSubscribers$SubscriberAdapter;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;

namespace java {
	namespace net {
		namespace http {

class HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0 : public $Function {
	$class(HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(HttpResponse$BodySubscribers::lambda$fromSubscriber$0($cast($Flow$Subscriber, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0::*)()>(&HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0::class$ = nullptr;

class HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1 : public $Function {
	$class(HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1, $NO_CLASS_INIT, $Function)
public:
	void init$($Charset* charset) {
		$set(this, charset, charset);
	}
	virtual $Object* apply(Object$* bytes) override {
		 return $of(HttpResponse$BodySubscribers::lambda$ofString$2(charset, $cast($bytes, bytes)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1>());
	}
	$Charset* charset = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1::fieldInfos[2] = {
	{"charset", "Ljava/nio/charset/Charset;", nullptr, $PUBLIC, $field(HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1, charset)},
	{}
};
$MethodInfo HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1::methodInfos[3] = {
	{"<init>", "(Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1::*)($Charset*)>(&HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1::class$ = nullptr;

$MethodInfo _HttpResponse$BodySubscribers_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(HttpResponse$BodySubscribers::*)()>(&HttpResponse$BodySubscribers::init$))},
	{"buffering", "(Ljava/net/http/HttpResponse$BodySubscriber;I)Ljava/net/http/HttpResponse$BodySubscriber;", "<T:Ljava/lang/Object;>(Ljava/net/http/HttpResponse$BodySubscriber<TT;>;I)Ljava/net/http/HttpResponse$BodySubscriber<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($HttpResponse$BodySubscriber*,int32_t)>(&HttpResponse$BodySubscribers::buffering))},
	{"discarding", "()Ljava/net/http/HttpResponse$BodySubscriber;", "()Ljava/net/http/HttpResponse$BodySubscriber<Ljava/lang/Void;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)()>(&HttpResponse$BodySubscribers::discarding))},
	{"fromLineSubscriber", "(Ljava/util/concurrent/Flow$Subscriber;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/lang/String;>;)Ljava/net/http/HttpResponse$BodySubscriber<Ljava/lang/Void;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Flow$Subscriber*)>(&HttpResponse$BodySubscribers::fromLineSubscriber))},
	{"fromLineSubscriber", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/function/Function;Ljava/nio/charset/Charset;Ljava/lang/String;)Ljava/net/http/HttpResponse$BodySubscriber;", "<S::Ljava/util/concurrent/Flow$Subscriber<-Ljava/lang/String;>;T:Ljava/lang/Object;>(TS;Ljava/util/function/Function<-TS;+TT;>;Ljava/nio/charset/Charset;Ljava/lang/String;)Ljava/net/http/HttpResponse$BodySubscriber<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Flow$Subscriber*,$Function*,$Charset*,$String*)>(&HttpResponse$BodySubscribers::fromLineSubscriber))},
	{"fromSubscriber", "(Ljava/util/concurrent/Flow$Subscriber;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)Ljava/net/http/HttpResponse$BodySubscriber<Ljava/lang/Void;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Flow$Subscriber*)>(&HttpResponse$BodySubscribers::fromSubscriber))},
	{"fromSubscriber", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/function/Function;)Ljava/net/http/HttpResponse$BodySubscriber;", "<S::Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;T:Ljava/lang/Object;>(TS;Ljava/util/function/Function<-TS;+TT;>;)Ljava/net/http/HttpResponse$BodySubscriber<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Flow$Subscriber*,$Function*)>(&HttpResponse$BodySubscribers::fromSubscriber))},
	{"lambda$fromSubscriber$0", "(Ljava/util/concurrent/Flow$Subscriber;)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Void*(*)($Flow$Subscriber*)>(&HttpResponse$BodySubscribers::lambda$fromSubscriber$0))},
	{"lambda$ofString$2", "(Ljava/nio/charset/Charset;[B)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($Charset*,$bytes*)>(&HttpResponse$BodySubscribers::lambda$ofString$2))},
	{"mapping", "(Ljava/net/http/HttpResponse$BodySubscriber;Ljava/util/function/Function;)Ljava/net/http/HttpResponse$BodySubscriber;", "<T:Ljava/lang/Object;U:Ljava/lang/Object;>(Ljava/net/http/HttpResponse$BodySubscriber<TT;>;Ljava/util/function/Function<-TT;+TU;>;)Ljava/net/http/HttpResponse$BodySubscriber<TU;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($HttpResponse$BodySubscriber*,$Function*)>(&HttpResponse$BodySubscribers::mapping))},
	{"ofByteArray", "()Ljava/net/http/HttpResponse$BodySubscriber;", "()Ljava/net/http/HttpResponse$BodySubscriber<[B>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)()>(&HttpResponse$BodySubscribers::ofByteArray))},
	{"ofByteArrayConsumer", "(Ljava/util/function/Consumer;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/util/function/Consumer<Ljava/util/Optional<[B>;>;)Ljava/net/http/HttpResponse$BodySubscriber<Ljava/lang/Void;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Consumer*)>(&HttpResponse$BodySubscribers::ofByteArrayConsumer))},
	{"ofFile", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/net/http/HttpResponse$BodySubscriber<Ljava/nio/file/Path;>;", $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Path*,$OpenOptionArray*)>(&HttpResponse$BodySubscribers::ofFile))},
	{"ofFile", "(Ljava/nio/file/Path;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/nio/file/Path;)Ljava/net/http/HttpResponse$BodySubscriber<Ljava/nio/file/Path;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Path*)>(&HttpResponse$BodySubscribers::ofFile))},
	{"ofInputStream", "()Ljava/net/http/HttpResponse$BodySubscriber;", "()Ljava/net/http/HttpResponse$BodySubscriber<Ljava/io/InputStream;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)()>(&HttpResponse$BodySubscribers::ofInputStream))},
	{"ofLines", "(Ljava/nio/charset/Charset;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/nio/charset/Charset;)Ljava/net/http/HttpResponse$BodySubscriber<Ljava/util/stream/Stream<Ljava/lang/String;>;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Charset*)>(&HttpResponse$BodySubscribers::ofLines))},
	{"ofPublisher", "()Ljava/net/http/HttpResponse$BodySubscriber;", "()Ljava/net/http/HttpResponse$BodySubscriber<Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)()>(&HttpResponse$BodySubscribers::ofPublisher))},
	{"ofString", "(Ljava/nio/charset/Charset;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/nio/charset/Charset;)Ljava/net/http/HttpResponse$BodySubscriber<Ljava/lang/String;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Charset*)>(&HttpResponse$BodySubscribers::ofString))},
	{"replacing", "(Ljava/lang/Object;)Ljava/net/http/HttpResponse$BodySubscriber;", "<U:Ljava/lang/Object;>(TU;)Ljava/net/http/HttpResponse$BodySubscriber<TU;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)(Object$*)>(&HttpResponse$BodySubscribers::replacing))},
	{}
};

$InnerClassInfo _HttpResponse$BodySubscribers_InnerClassesInfo_[] = {
	{"java.net.http.HttpResponse$BodySubscribers", "java.net.http.HttpResponse", "BodySubscribers", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _HttpResponse$BodySubscribers_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.http.HttpResponse$BodySubscribers",
	"java.lang.Object",
	nullptr,
	nullptr,
	_HttpResponse$BodySubscribers_MethodInfo_,
	nullptr,
	nullptr,
	_HttpResponse$BodySubscribers_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpResponse"
};

$Object* allocate$HttpResponse$BodySubscribers($Class* clazz) {
	return $of($alloc(HttpResponse$BodySubscribers));
}

void HttpResponse$BodySubscribers::init$() {
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::fromSubscriber($Flow$Subscriber* subscriber) {
	return $new($ResponseSubscribers$SubscriberAdapter, subscriber, static_cast<$Function*>($$new(HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0)));
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::fromSubscriber($Flow$Subscriber* subscriber, $Function* finisher) {
	return $new($ResponseSubscribers$SubscriberAdapter, subscriber, finisher);
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::fromLineSubscriber($Flow$Subscriber* subscriber) {
	$init($StandardCharsets);
	return fromLineSubscriber(subscriber, static_cast<$Function*>($$new(HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0)), $StandardCharsets::UTF_8, nullptr);
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::fromLineSubscriber($Flow$Subscriber* subscriber, $Function* finisher, $Charset* charset, $String* lineSeparator) {
	return $LineSubscriberAdapter::create(subscriber, finisher, charset, lineSeparator);
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::ofString($Charset* charset) {
	$Objects::requireNonNull(charset);
	return $new($ResponseSubscribers$ByteArraySubscriber, static_cast<$Function*>($$new(HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1, charset)));
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::ofByteArray() {
	return $new($ResponseSubscribers$ByteArraySubscriber, $($Function::identity()));
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::ofFile($Path* file, $OpenOptionArray* openOptions) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(file);
	$var($List, opts, $List::of(openOptions));
	$init($StandardOpenOption);
	bool var$0 = $nc(opts)->contains($StandardOpenOption::DELETE_ON_CLOSE);
	if (var$0 || $nc(opts)->contains($StandardOpenOption::READ)) {
		$throwNew($IllegalArgumentException, $$str({"invalid openOptions: "_s, opts}));
	}
	return $ResponseSubscribers$PathSubscriber::create(file, opts);
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::ofFile($Path* file) {
	$init($StandardOpenOption);
	return ofFile(file, $$new($OpenOptionArray, {
		static_cast<$OpenOption*>($StandardOpenOption::CREATE),
		static_cast<$OpenOption*>($StandardOpenOption::WRITE)
	}));
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::ofByteArrayConsumer($Consumer* consumer) {
	return $new($ResponseSubscribers$ConsumerSubscriber, consumer);
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::ofInputStream() {
	return $new($ResponseSubscribers$HttpResponseInputStream);
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::ofLines($Charset* charset) {
	return $ResponseSubscribers::createLineStream(charset);
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::ofPublisher() {
	return $ResponseSubscribers::createPublisher();
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::replacing(Object$* value) {
	return $new($ResponseSubscribers$NullSubscriber, $($Optional::ofNullable(value)));
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::discarding() {
	return $new($ResponseSubscribers$NullSubscriber, $($Optional::ofNullable(nullptr)));
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::buffering($HttpResponse$BodySubscriber* downstream, int32_t bufferSize) {
	if (bufferSize <= 0) {
		$throwNew($IllegalArgumentException, "must be greater than 0"_s);
	}
	return $new($BufferingSubscriber, downstream, bufferSize);
}

$HttpResponse$BodySubscriber* HttpResponse$BodySubscribers::mapping($HttpResponse$BodySubscriber* upstream, $Function* mapper) {
	return $new($ResponseSubscribers$MappingSubscriber, upstream, mapper);
}

$String* HttpResponse$BodySubscribers::lambda$ofString$2($Charset* charset, $bytes* bytes) {
	return $new($String, bytes, charset);
}

$Void* HttpResponse$BodySubscribers::lambda$fromSubscriber$0($Flow$Subscriber* s) {
	return nullptr;
}

HttpResponse$BodySubscribers::HttpResponse$BodySubscribers() {
}

$Class* HttpResponse$BodySubscribers::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0::classInfo$.name)) {
			return HttpResponse$BodySubscribers$$Lambda$lambda$fromSubscriber$0::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1::classInfo$.name)) {
			return HttpResponse$BodySubscribers$$Lambda$lambda$ofString$2$1::load$(name, initialize);
		}
	}
	$loadClass(HttpResponse$BodySubscribers, name, initialize, &_HttpResponse$BodySubscribers_ClassInfo_, allocate$HttpResponse$BodySubscribers);
	return class$;
}

$Class* HttpResponse$BodySubscribers::class$ = nullptr;

		} // http
	} // net
} // java