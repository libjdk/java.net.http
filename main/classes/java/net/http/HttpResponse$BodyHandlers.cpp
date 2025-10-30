#include <java/net/http/HttpResponse$BodyHandlers.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse$BodySubscribers.h>
#include <java/net/http/HttpResponse$ResponseInfo.h>
#include <java/net/http/HttpResponse.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/StandardOpenOption.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/ResponseBodyHandlers$FileDownloadBodyHandler.h>
#include <jdk/internal/net/http/ResponseBodyHandlers$PathBodyHandler.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef CREATE
#undef DELETE_ON_CLOSE
#undef READ
#undef WRITE

using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpResponse = ::java::net::http::HttpResponse;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $HttpResponse$BodySubscribers = ::java::net::http::HttpResponse$BodySubscribers;
using $HttpResponse$ResponseInfo = ::java::net::http::HttpResponse$ResponseInfo;
using $Charset = ::java::nio::charset::Charset;
using $OpenOption = ::java::nio::file::OpenOption;
using $Path = ::java::nio::file::Path;
using $StandardOpenOption = ::java::nio::file::StandardOpenOption;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $ResponseBodyHandlers$FileDownloadBodyHandler = ::jdk::internal::net::http::ResponseBodyHandlers$FileDownloadBodyHandler;
using $ResponseBodyHandlers$PathBodyHandler = ::jdk::internal::net::http::ResponseBodyHandlers$PathBodyHandler;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace java {
	namespace net {
		namespace http {

class HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$($Flow$Subscriber* subscriber) {
		$set(this, subscriber, subscriber);
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$fromSubscriber$1(subscriber, responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1>());
	}
	$Flow$Subscriber* subscriber = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1::fieldInfos[2] = {
	{"subscriber", "Ljava/util/concurrent/Flow$Subscriber;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1, subscriber)},
	{}
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Subscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1::*)($Flow$Subscriber*)>(&HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	fieldInfos,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$($Flow$Subscriber* subscriber, $Function* finisher) {
		$set(this, subscriber, subscriber);
		$set(this, finisher, finisher);
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$fromSubscriber$2(subscriber, finisher, responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1>());
	}
	$Flow$Subscriber* subscriber = nullptr;
	$Function* finisher = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1::fieldInfos[3] = {
	{"subscriber", "Ljava/util/concurrent/Flow$Subscriber;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1, subscriber)},
	{"finisher", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1, finisher)},
	{}
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/function/Function;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1::*)($Flow$Subscriber*,$Function*)>(&HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	fieldInfos,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$($Flow$Subscriber* subscriber) {
		$set(this, subscriber, subscriber);
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$fromLineSubscriber$4(subscriber, responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2>());
	}
	$Flow$Subscriber* subscriber = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2::fieldInfos[2] = {
	{"subscriber", "Ljava/util/concurrent/Flow$Subscriber;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2, subscriber)},
	{}
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Subscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2::*)($Flow$Subscriber*)>(&HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	fieldInfos,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$($Flow$Subscriber* subscriber, $Function* finisher, $String* lineSeparator) {
		$set(this, subscriber, subscriber);
		$set(this, finisher, finisher);
		$set(this, lineSeparator, lineSeparator);
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$fromLineSubscriber$5(subscriber, finisher, lineSeparator, responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3>());
	}
	$Flow$Subscriber* subscriber = nullptr;
	$Function* finisher = nullptr;
	$String* lineSeparator = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3::fieldInfos[4] = {
	{"subscriber", "Ljava/util/concurrent/Flow$Subscriber;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3, subscriber)},
	{"finisher", "Ljava/util/function/Function;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3, finisher)},
	{"lineSeparator", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3, lineSeparator)},
	{}
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3::methodInfos[3] = {
	{"<init>", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/function/Function;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3::*)($Flow$Subscriber*,$Function*,$String*)>(&HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	fieldInfos,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$() {
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$discarding$6(responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4::*)()>(&HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	nullptr,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$(Object$* value) {
		$set(this, value, value);
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$replacing$7(value, responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5>());
	}
	$Object* value = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5::fieldInfos[2] = {
	{"value", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5, value)},
	{}
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Object;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5::*)(Object$*)>(&HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	fieldInfos,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$($Charset* charset) {
		$set(this, charset, charset);
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$ofString$8(charset, responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6>());
	}
	$Charset* charset = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6::fieldInfos[2] = {
	{"charset", "Ljava/nio/charset/Charset;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6, charset)},
	{}
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6::methodInfos[3] = {
	{"<init>", "(Ljava/nio/charset/Charset;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6::*)($Charset*)>(&HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	fieldInfos,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$() {
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$ofInputStream$9(responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7::*)()>(&HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	nullptr,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$() {
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$ofLines$10(responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8::*)()>(&HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	nullptr,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$($Consumer* consumer) {
		$set(this, consumer, consumer);
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$ofByteArrayConsumer$11(consumer, responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9>());
	}
	$Consumer* consumer = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9::fieldInfos[2] = {
	{"consumer", "Ljava/util/function/Consumer;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9, consumer)},
	{}
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/Consumer;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9::*)($Consumer*)>(&HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	fieldInfos,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$() {
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$ofByteArray$12(responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10::*)()>(&HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	nullptr,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$() {
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$ofString$13(responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11::*)()>(&HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	nullptr,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$() {
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$ofPublisher$14(responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12::*)()>(&HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	nullptr,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13 : public $HttpResponse$BodyHandler {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13, $NO_CLASS_INIT, $HttpResponse$BodyHandler)
public:
	void init$($HttpResponse$BodyHandler* downstreamHandler, int32_t bufferSize) {
		$set(this, downstreamHandler, downstreamHandler);
		this->bufferSize = bufferSize;
	}
	virtual $HttpResponse$BodySubscriber* apply($HttpResponse$ResponseInfo* responseInfo) override {
		 return HttpResponse$BodyHandlers::lambda$buffering$15(downstreamHandler, bufferSize, responseInfo);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13>());
	}
	$HttpResponse$BodyHandler* downstreamHandler = nullptr;
	int32_t bufferSize = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13::fieldInfos[3] = {
	{"downstreamHandler", "Ljava/net/http/HttpResponse$BodyHandler;", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13, downstreamHandler)},
	{"bufferSize", "I", nullptr, $PUBLIC, $field(HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13, bufferSize)},
	{}
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpResponse$BodyHandler;I)V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13::*)($HttpResponse$BodyHandler*,int32_t)>(&HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	fieldInfos,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13::class$ = nullptr;

class HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14 : public $Function {
	$class(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* s) override {
		 return $of(HttpResponse$BodyHandlers::lambda$fromSubscriber$0($cast($Flow$Subscriber, s)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14::*)()>(&HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14::load$($String* name, bool initialize) {
	$loadClass(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14::class$ = nullptr;

$MethodInfo _HttpResponse$BodyHandlers_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(HttpResponse$BodyHandlers::*)()>(&HttpResponse$BodyHandlers::init$))},
	{"buffering", "(Ljava/net/http/HttpResponse$BodyHandler;I)Ljava/net/http/HttpResponse$BodyHandler;", "<T:Ljava/lang/Object;>(Ljava/net/http/HttpResponse$BodyHandler<TT;>;I)Ljava/net/http/HttpResponse$BodyHandler<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)($HttpResponse$BodyHandler*,int32_t)>(&HttpResponse$BodyHandlers::buffering))},
	{"discarding", "()Ljava/net/http/HttpResponse$BodyHandler;", "()Ljava/net/http/HttpResponse$BodyHandler<Ljava/lang/Void;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)()>(&HttpResponse$BodyHandlers::discarding))},
	{"fromLineSubscriber", "(Ljava/util/concurrent/Flow$Subscriber;)Ljava/net/http/HttpResponse$BodyHandler;", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/lang/String;>;)Ljava/net/http/HttpResponse$BodyHandler<Ljava/lang/Void;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)($Flow$Subscriber*)>(&HttpResponse$BodyHandlers::fromLineSubscriber))},
	{"fromLineSubscriber", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/function/Function;Ljava/lang/String;)Ljava/net/http/HttpResponse$BodyHandler;", "<S::Ljava/util/concurrent/Flow$Subscriber<-Ljava/lang/String;>;T:Ljava/lang/Object;>(TS;Ljava/util/function/Function<-TS;+TT;>;Ljava/lang/String;)Ljava/net/http/HttpResponse$BodyHandler<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)($Flow$Subscriber*,$Function*,$String*)>(&HttpResponse$BodyHandlers::fromLineSubscriber))},
	{"fromSubscriber", "(Ljava/util/concurrent/Flow$Subscriber;)Ljava/net/http/HttpResponse$BodyHandler;", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)Ljava/net/http/HttpResponse$BodyHandler<Ljava/lang/Void;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)($Flow$Subscriber*)>(&HttpResponse$BodyHandlers::fromSubscriber))},
	{"fromSubscriber", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/function/Function;)Ljava/net/http/HttpResponse$BodyHandler;", "<S::Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;T:Ljava/lang/Object;>(TS;Ljava/util/function/Function<-TS;+TT;>;)Ljava/net/http/HttpResponse$BodyHandler<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)($Flow$Subscriber*,$Function*)>(&HttpResponse$BodyHandlers::fromSubscriber))},
	{"lambda$buffering$15", "(Ljava/net/http/HttpResponse$BodyHandler;ILjava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($HttpResponse$BodyHandler*,int32_t,$HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$buffering$15))},
	{"lambda$discarding$6", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$discarding$6))},
	{"lambda$fromLineSubscriber$4", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Flow$Subscriber*,$HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$fromLineSubscriber$4))},
	{"lambda$fromLineSubscriber$5", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/function/Function;Ljava/lang/String;Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Flow$Subscriber*,$Function*,$String*,$HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$fromLineSubscriber$5))},
	{"lambda$fromSubscriber$0", "(Ljava/util/concurrent/Flow$Subscriber;)Ljava/lang/Void;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Void*(*)($Flow$Subscriber*)>(&HttpResponse$BodyHandlers::lambda$fromSubscriber$0))},
	{"lambda$fromSubscriber$1", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Flow$Subscriber*,$HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$fromSubscriber$1))},
	{"lambda$fromSubscriber$2", "(Ljava/util/concurrent/Flow$Subscriber;Ljava/util/function/Function;Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Flow$Subscriber*,$Function*,$HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$fromSubscriber$2))},
	{"lambda$ofByteArray$12", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$ofByteArray$12))},
	{"lambda$ofByteArrayConsumer$11", "(Ljava/util/function/Consumer;Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Consumer*,$HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$ofByteArrayConsumer$11))},
	{"lambda$ofInputStream$9", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$ofInputStream$9))},
	{"lambda$ofLines$10", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$ofLines$10))},
	{"lambda$ofPublisher$14", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$ofPublisher$14))},
	{"lambda$ofString$13", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$ofString$13))},
	{"lambda$ofString$8", "(Ljava/nio/charset/Charset;Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)($Charset*,$HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$ofString$8))},
	{"lambda$replacing$7", "(Ljava/lang/Object;Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$HttpResponse$BodySubscriber*(*)(Object$*,$HttpResponse$ResponseInfo*)>(&HttpResponse$BodyHandlers::lambda$replacing$7))},
	{"ofByteArray", "()Ljava/net/http/HttpResponse$BodyHandler;", "()Ljava/net/http/HttpResponse$BodyHandler<[B>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)()>(&HttpResponse$BodyHandlers::ofByteArray))},
	{"ofByteArrayConsumer", "(Ljava/util/function/Consumer;)Ljava/net/http/HttpResponse$BodyHandler;", "(Ljava/util/function/Consumer<Ljava/util/Optional<[B>;>;)Ljava/net/http/HttpResponse$BodyHandler<Ljava/lang/Void;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)($Consumer*)>(&HttpResponse$BodyHandlers::ofByteArrayConsumer))},
	{"ofFile", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/net/http/HttpResponse$BodyHandler;", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/net/http/HttpResponse$BodyHandler<Ljava/nio/file/Path;>;", $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<$HttpResponse$BodyHandler*(*)($Path*,$OpenOptionArray*)>(&HttpResponse$BodyHandlers::ofFile))},
	{"ofFile", "(Ljava/nio/file/Path;)Ljava/net/http/HttpResponse$BodyHandler;", "(Ljava/nio/file/Path;)Ljava/net/http/HttpResponse$BodyHandler<Ljava/nio/file/Path;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)($Path*)>(&HttpResponse$BodyHandlers::ofFile))},
	{"ofFileDownload", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/net/http/HttpResponse$BodyHandler;", "(Ljava/nio/file/Path;[Ljava/nio/file/OpenOption;)Ljava/net/http/HttpResponse$BodyHandler<Ljava/nio/file/Path;>;", $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<$HttpResponse$BodyHandler*(*)($Path*,$OpenOptionArray*)>(&HttpResponse$BodyHandlers::ofFileDownload))},
	{"ofInputStream", "()Ljava/net/http/HttpResponse$BodyHandler;", "()Ljava/net/http/HttpResponse$BodyHandler<Ljava/io/InputStream;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)()>(&HttpResponse$BodyHandlers::ofInputStream))},
	{"ofLines", "()Ljava/net/http/HttpResponse$BodyHandler;", "()Ljava/net/http/HttpResponse$BodyHandler<Ljava/util/stream/Stream<Ljava/lang/String;>;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)()>(&HttpResponse$BodyHandlers::ofLines))},
	{"ofPublisher", "()Ljava/net/http/HttpResponse$BodyHandler;", "()Ljava/net/http/HttpResponse$BodyHandler<Ljava/util/concurrent/Flow$Publisher<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)()>(&HttpResponse$BodyHandlers::ofPublisher))},
	{"ofString", "(Ljava/nio/charset/Charset;)Ljava/net/http/HttpResponse$BodyHandler;", "(Ljava/nio/charset/Charset;)Ljava/net/http/HttpResponse$BodyHandler<Ljava/lang/String;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)($Charset*)>(&HttpResponse$BodyHandlers::ofString))},
	{"ofString", "()Ljava/net/http/HttpResponse$BodyHandler;", "()Ljava/net/http/HttpResponse$BodyHandler<Ljava/lang/String;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)()>(&HttpResponse$BodyHandlers::ofString))},
	{"replacing", "(Ljava/lang/Object;)Ljava/net/http/HttpResponse$BodyHandler;", "<U:Ljava/lang/Object;>(TU;)Ljava/net/http/HttpResponse$BodyHandler<TU;>;", $PUBLIC | $STATIC, $method(static_cast<$HttpResponse$BodyHandler*(*)(Object$*)>(&HttpResponse$BodyHandlers::replacing))},
	{}
};

$InnerClassInfo _HttpResponse$BodyHandlers_InnerClassesInfo_[] = {
	{"java.net.http.HttpResponse$BodyHandlers", "java.net.http.HttpResponse", "BodyHandlers", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _HttpResponse$BodyHandlers_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"java.net.http.HttpResponse$BodyHandlers",
	"java.lang.Object",
	nullptr,
	nullptr,
	_HttpResponse$BodyHandlers_MethodInfo_,
	nullptr,
	nullptr,
	_HttpResponse$BodyHandlers_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"java.net.http.HttpResponse"
};

$Object* allocate$HttpResponse$BodyHandlers($Class* clazz) {
	return $of($alloc(HttpResponse$BodyHandlers));
}

void HttpResponse$BodyHandlers::init$() {
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::fromSubscriber($Flow$Subscriber* subscriber) {
	$Objects::requireNonNull(subscriber);
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1, subscriber));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::fromSubscriber($Flow$Subscriber* subscriber, $Function* finisher) {
	$Objects::requireNonNull(subscriber);
	$Objects::requireNonNull(finisher);
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1, subscriber, finisher));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::fromLineSubscriber($Flow$Subscriber* subscriber) {
	$Objects::requireNonNull(subscriber);
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2, subscriber));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::fromLineSubscriber($Flow$Subscriber* subscriber, $Function* finisher, $String* lineSeparator) {
	$Objects::requireNonNull(subscriber);
	$Objects::requireNonNull(finisher);
	if (lineSeparator != nullptr && lineSeparator->isEmpty()) {
		$throwNew($IllegalArgumentException, "empty line separator"_s);
	}
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3, subscriber, finisher, lineSeparator));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::discarding() {
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::replacing(Object$* value) {
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5, value));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::ofString($Charset* charset) {
	$Objects::requireNonNull(charset);
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6, charset));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::ofFile($Path* file, $OpenOptionArray* openOptions) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(file);
	$var($List, opts, $List::of(openOptions));
	$init($StandardOpenOption);
	bool var$0 = $nc(opts)->contains($StandardOpenOption::DELETE_ON_CLOSE);
	if (var$0 || $nc(opts)->contains($StandardOpenOption::READ)) {
		$throwNew($IllegalArgumentException, $$str({"invalid openOptions: "_s, opts}));
	}
	return $ResponseBodyHandlers$PathBodyHandler::create(file, opts);
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::ofFile($Path* file) {
	$init($StandardOpenOption);
	return HttpResponse$BodyHandlers::ofFile(file, $$new($OpenOptionArray, {
		static_cast<$OpenOption*>($StandardOpenOption::CREATE),
		static_cast<$OpenOption*>($StandardOpenOption::WRITE)
	}));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::ofFileDownload($Path* directory, $OpenOptionArray* openOptions) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(directory);
	$var($List, opts, $List::of(openOptions));
	$init($StandardOpenOption);
	if ($nc(opts)->contains($StandardOpenOption::DELETE_ON_CLOSE)) {
		$throwNew($IllegalArgumentException, $$str({"invalid option: "_s, $StandardOpenOption::DELETE_ON_CLOSE}));
	}
	return $ResponseBodyHandlers$FileDownloadBodyHandler::create(directory, opts);
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::ofInputStream() {
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::ofLines() {
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::ofByteArrayConsumer($Consumer* consumer) {
	$Objects::requireNonNull(consumer);
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9, consumer));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::ofByteArray() {
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::ofString() {
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::ofPublisher() {
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12));
}

$HttpResponse$BodyHandler* HttpResponse$BodyHandlers::buffering($HttpResponse$BodyHandler* downstreamHandler, int32_t bufferSize) {
	$Objects::requireNonNull(downstreamHandler);
	if (bufferSize <= 0) {
		$throwNew($IllegalArgumentException, "must be greater than 0"_s);
	}
	return static_cast<$HttpResponse$BodyHandler*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13, downstreamHandler, bufferSize));
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$buffering$15($HttpResponse$BodyHandler* downstreamHandler, int32_t bufferSize, $HttpResponse$ResponseInfo* responseInfo) {
	return $HttpResponse$BodySubscribers::buffering($($nc(downstreamHandler)->apply(responseInfo)), bufferSize);
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$ofPublisher$14($HttpResponse$ResponseInfo* responseInfo) {
	return $HttpResponse$BodySubscribers::ofPublisher();
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$ofString$13($HttpResponse$ResponseInfo* responseInfo) {
	$useLocalCurrentObjectStackCache();
	return $HttpResponse$BodySubscribers::ofString($($Utils::charsetFrom($($nc(responseInfo)->headers()))));
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$ofByteArray$12($HttpResponse$ResponseInfo* responseInfo) {
	return $HttpResponse$BodySubscribers::ofByteArray();
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$ofByteArrayConsumer$11($Consumer* consumer, $HttpResponse$ResponseInfo* responseInfo) {
	return $HttpResponse$BodySubscribers::ofByteArrayConsumer(consumer);
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$ofLines$10($HttpResponse$ResponseInfo* responseInfo) {
	$useLocalCurrentObjectStackCache();
	return $HttpResponse$BodySubscribers::ofLines($($Utils::charsetFrom($($nc(responseInfo)->headers()))));
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$ofInputStream$9($HttpResponse$ResponseInfo* responseInfo) {
	return $HttpResponse$BodySubscribers::ofInputStream();
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$ofString$8($Charset* charset, $HttpResponse$ResponseInfo* responseInfo) {
	return $HttpResponse$BodySubscribers::ofString(charset);
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$replacing$7(Object$* value, $HttpResponse$ResponseInfo* responseInfo) {
	return $HttpResponse$BodySubscribers::replacing(value);
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$discarding$6($HttpResponse$ResponseInfo* responseInfo) {
	return $HttpResponse$BodySubscribers::discarding();
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$fromLineSubscriber$5($Flow$Subscriber* subscriber, $Function* finisher, $String* lineSeparator, $HttpResponse$ResponseInfo* responseInfo) {
	$useLocalCurrentObjectStackCache();
	return $HttpResponse$BodySubscribers::fromLineSubscriber(subscriber, finisher, $($Utils::charsetFrom($($nc(responseInfo)->headers()))), lineSeparator);
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$fromLineSubscriber$4($Flow$Subscriber* subscriber, $HttpResponse$ResponseInfo* responseInfo) {
	$useLocalCurrentObjectStackCache();
	$var($Flow$Subscriber, var$0, subscriber);
	$var($Function, var$1, static_cast<$Function*>($new(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14)));
	return $HttpResponse$BodySubscribers::fromLineSubscriber(var$0, var$1, $($Utils::charsetFrom($($nc(responseInfo)->headers()))), nullptr);
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$fromSubscriber$2($Flow$Subscriber* subscriber, $Function* finisher, $HttpResponse$ResponseInfo* responseInfo) {
	return $HttpResponse$BodySubscribers::fromSubscriber(subscriber, finisher);
}

$HttpResponse$BodySubscriber* HttpResponse$BodyHandlers::lambda$fromSubscriber$1($Flow$Subscriber* subscriber, $HttpResponse$ResponseInfo* responseInfo) {
	return $HttpResponse$BodySubscribers::fromSubscriber(subscriber, static_cast<$Function*>($$new(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14)));
}

$Void* HttpResponse$BodyHandlers::lambda$fromSubscriber$0($Flow$Subscriber* s) {
	return nullptr;
}

HttpResponse$BodyHandlers::HttpResponse$BodyHandlers() {
}

$Class* HttpResponse$BodyHandlers::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$1::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$2$1::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$4$2::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$fromLineSubscriber$5$3::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$discarding$6$4::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$replacing$7$5::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$ofString$8$6::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$ofInputStream$9$7::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$ofLines$10$8::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArrayConsumer$11$9::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$ofByteArray$12$10::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$ofString$13$11::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$ofPublisher$14$12::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$buffering$15$13::load$(name, initialize);
		}
		if (name->equals(HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14::classInfo$.name)) {
			return HttpResponse$BodyHandlers$$Lambda$lambda$fromSubscriber$0$14::load$(name, initialize);
		}
	}
	$loadClass(HttpResponse$BodyHandlers, name, initialize, &_HttpResponse$BodyHandlers_ClassInfo_, allocate$HttpResponse$BodyHandlers);
	return class$;
}

$Class* HttpResponse$BodyHandlers::class$ = nullptr;

		} // http
	} // net
} // java