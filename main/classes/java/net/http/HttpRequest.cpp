#include <java/net/http/HttpRequest.h>

#include <java/io/Serializable.h>
#include <java/lang/Iterable.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/net/http/HttpRequest$BodyPublishers.h>
#include <java/net/http/HttpRequest$Builder.h>
#include <java/time/Duration.h>
#include <java/util/List.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Consumer.h>
#include <jdk/internal/net/http/HttpRequestBuilderImpl.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $URI = ::java::net::URI;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $HttpRequest$BodyPublishers = ::java::net::http::HttpRequest$BodyPublishers;
using $HttpRequest$Builder = ::java::net::http::HttpRequest$Builder;
using $Duration = ::java::time::Duration;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Consumer = ::java::util::function::Consumer;
using $HttpRequestBuilderImpl = ::jdk::internal::net::http::HttpRequestBuilderImpl;

namespace java {
	namespace net {
		namespace http {

class HttpRequest$$Lambda$lambda$newBuilder$1 : public $BiConsumer {
	$class(HttpRequest$$Lambda$lambda$newBuilder$1, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($HttpRequest$Builder* builder) {
		$set(this, builder, builder);
	}
	virtual void accept(Object$* name, Object$* values) override {
		HttpRequest::lambda$newBuilder$1(builder, $cast($String, name), $cast($List, values));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequest$$Lambda$lambda$newBuilder$1>());
	}
	$HttpRequest$Builder* builder = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpRequest$$Lambda$lambda$newBuilder$1::fieldInfos[2] = {
	{"builder", "Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC, $field(HttpRequest$$Lambda$lambda$newBuilder$1, builder)},
	{}
};
$MethodInfo HttpRequest$$Lambda$lambda$newBuilder$1::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpRequest$Builder;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequest$$Lambda$lambda$newBuilder$1::*)($HttpRequest$Builder*)>(&HttpRequest$$Lambda$lambda$newBuilder$1::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequest$$Lambda$lambda$newBuilder$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpRequest$$Lambda$lambda$newBuilder$1",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* HttpRequest$$Lambda$lambda$newBuilder$1::load$($String* name, bool initialize) {
	$loadClass(HttpRequest$$Lambda$lambda$newBuilder$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequest$$Lambda$lambda$newBuilder$1::class$ = nullptr;

class HttpRequest$$Lambda$version$1 : public $Consumer {
	$class(HttpRequest$$Lambda$version$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($HttpRequest$Builder* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* version) override {
		$nc(inst$)->version($cast($HttpClient$Version, version));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequest$$Lambda$version$1>());
	}
	$HttpRequest$Builder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpRequest$$Lambda$version$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpRequest$$Lambda$version$1, inst$)},
	{}
};
$MethodInfo HttpRequest$$Lambda$version$1::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpRequest$Builder;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequest$$Lambda$version$1::*)($HttpRequest$Builder*)>(&HttpRequest$$Lambda$version$1::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequest$$Lambda$version$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpRequest$$Lambda$version$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HttpRequest$$Lambda$version$1::load$($String* name, bool initialize) {
	$loadClass(HttpRequest$$Lambda$version$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequest$$Lambda$version$1::class$ = nullptr;

class HttpRequest$$Lambda$timeout$2 : public $Consumer {
	$class(HttpRequest$$Lambda$timeout$2, $NO_CLASS_INIT, $Consumer)
public:
	void init$($HttpRequest$Builder* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* duration) override {
		$nc(inst$)->timeout($cast($Duration, duration));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequest$$Lambda$timeout$2>());
	}
	$HttpRequest$Builder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpRequest$$Lambda$timeout$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpRequest$$Lambda$timeout$2, inst$)},
	{}
};
$MethodInfo HttpRequest$$Lambda$timeout$2::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpRequest$Builder;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequest$$Lambda$timeout$2::*)($HttpRequest$Builder*)>(&HttpRequest$$Lambda$timeout$2::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequest$$Lambda$timeout$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpRequest$$Lambda$timeout$2",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HttpRequest$$Lambda$timeout$2::load$($String* name, bool initialize) {
	$loadClass(HttpRequest$$Lambda$timeout$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequest$$Lambda$timeout$2::class$ = nullptr;

class HttpRequest$$Lambda$lambda$newBuilder$2$3 : public $Consumer {
	$class(HttpRequest$$Lambda$lambda$newBuilder$2$3, $NO_CLASS_INIT, $Consumer)
public:
	void init$($HttpRequest$Builder* builder, $String* method) {
		$set(this, builder, builder);
		$set(this, method, method);
	}
	virtual void accept(Object$* bodyPublisher) override {
		HttpRequest::lambda$newBuilder$2(builder, method, $cast($HttpRequest$BodyPublisher, bodyPublisher));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequest$$Lambda$lambda$newBuilder$2$3>());
	}
	$HttpRequest$Builder* builder = nullptr;
	$String* method = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpRequest$$Lambda$lambda$newBuilder$2$3::fieldInfos[3] = {
	{"builder", "Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC, $field(HttpRequest$$Lambda$lambda$newBuilder$2$3, builder)},
	{"method", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HttpRequest$$Lambda$lambda$newBuilder$2$3, method)},
	{}
};
$MethodInfo HttpRequest$$Lambda$lambda$newBuilder$2$3::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpRequest$Builder;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequest$$Lambda$lambda$newBuilder$2$3::*)($HttpRequest$Builder*,$String*)>(&HttpRequest$$Lambda$lambda$newBuilder$2$3::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequest$$Lambda$lambda$newBuilder$2$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpRequest$$Lambda$lambda$newBuilder$2$3",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HttpRequest$$Lambda$lambda$newBuilder$2$3::load$($String* name, bool initialize) {
	$loadClass(HttpRequest$$Lambda$lambda$newBuilder$2$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequest$$Lambda$lambda$newBuilder$2$3::class$ = nullptr;

class HttpRequest$$Lambda$lambda$newBuilder$3$4 : public $Runnable {
	$class(HttpRequest$$Lambda$lambda$newBuilder$3$4, $NO_CLASS_INIT, $Runnable)
public:
	void init$($String* method, $HttpRequest$Builder* builder) {
		$set(this, method, method);
		$set(this, builder, builder);
	}
	virtual void run() override {
		HttpRequest::lambda$newBuilder$3(method, builder);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequest$$Lambda$lambda$newBuilder$3$4>());
	}
	$String* method = nullptr;
	$HttpRequest$Builder* builder = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpRequest$$Lambda$lambda$newBuilder$3$4::fieldInfos[3] = {
	{"method", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HttpRequest$$Lambda$lambda$newBuilder$3$4, method)},
	{"builder", "Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC, $field(HttpRequest$$Lambda$lambda$newBuilder$3$4, builder)},
	{}
};
$MethodInfo HttpRequest$$Lambda$lambda$newBuilder$3$4::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;Ljava/net/http/HttpRequest$Builder;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequest$$Lambda$lambda$newBuilder$3$4::*)($String*,$HttpRequest$Builder*)>(&HttpRequest$$Lambda$lambda$newBuilder$3$4::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequest$$Lambda$lambda$newBuilder$3$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpRequest$$Lambda$lambda$newBuilder$3$4",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* HttpRequest$$Lambda$lambda$newBuilder$3$4::load$($String* name, bool initialize) {
	$loadClass(HttpRequest$$Lambda$lambda$newBuilder$3$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequest$$Lambda$lambda$newBuilder$3$4::class$ = nullptr;

class HttpRequest$$Lambda$lambda$newBuilder$0$5 : public $Consumer {
	$class(HttpRequest$$Lambda$lambda$newBuilder$0$5, $NO_CLASS_INIT, $Consumer)
public:
	void init$($HttpRequest$Builder* builder, $String* name) {
		$set(this, builder, builder);
		$set(this, name, name);
	}
	virtual void accept(Object$* value) override {
		HttpRequest::lambda$newBuilder$0(builder, name, $cast($String, value));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpRequest$$Lambda$lambda$newBuilder$0$5>());
	}
	$HttpRequest$Builder* builder = nullptr;
	$String* name = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpRequest$$Lambda$lambda$newBuilder$0$5::fieldInfos[3] = {
	{"builder", "Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC, $field(HttpRequest$$Lambda$lambda$newBuilder$0$5, builder)},
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HttpRequest$$Lambda$lambda$newBuilder$0$5, name)},
	{}
};
$MethodInfo HttpRequest$$Lambda$lambda$newBuilder$0$5::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpRequest$Builder;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpRequest$$Lambda$lambda$newBuilder$0$5::*)($HttpRequest$Builder*,$String*)>(&HttpRequest$$Lambda$lambda$newBuilder$0$5::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpRequest$$Lambda$lambda$newBuilder$0$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpRequest$$Lambda$lambda$newBuilder$0$5",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HttpRequest$$Lambda$lambda$newBuilder$0$5::load$($String* name, bool initialize) {
	$loadClass(HttpRequest$$Lambda$lambda$newBuilder$0$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpRequest$$Lambda$lambda$newBuilder$0$5::class$ = nullptr;

$MethodInfo _HttpRequest_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PROTECTED, $method(static_cast<void(HttpRequest::*)()>(&HttpRequest::init$))},
	{"bodyPublisher", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/http/HttpRequest$BodyPublisher;>;", $PUBLIC | $ABSTRACT},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"expectContinue", "()Z", nullptr, $PUBLIC | $ABSTRACT},
	{"hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"headers", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC | $ABSTRACT},
	{"lambda$newBuilder$0", "(Ljava/net/http/HttpRequest$Builder;Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($HttpRequest$Builder*,$String*,$String*)>(&HttpRequest::lambda$newBuilder$0))},
	{"lambda$newBuilder$1", "(Ljava/net/http/HttpRequest$Builder;Ljava/lang/String;Ljava/util/List;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($HttpRequest$Builder*,$String*,$List*)>(&HttpRequest::lambda$newBuilder$1))},
	{"lambda$newBuilder$2", "(Ljava/net/http/HttpRequest$Builder;Ljava/lang/String;Ljava/net/http/HttpRequest$BodyPublisher;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($HttpRequest$Builder*,$String*,$HttpRequest$BodyPublisher*)>(&HttpRequest::lambda$newBuilder$2))},
	{"lambda$newBuilder$3", "(Ljava/lang/String;Ljava/net/http/HttpRequest$Builder;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($String*,$HttpRequest$Builder*)>(&HttpRequest::lambda$newBuilder$3))},
	{"method", "()Ljava/lang/String;", nullptr, $PUBLIC | $ABSTRACT},
	{"newBuilder", "(Ljava/net/URI;)Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$Builder*(*)($URI*)>(&HttpRequest::newBuilder))},
	{"newBuilder", "(Ljava/net/http/HttpRequest;Ljava/util/function/BiPredicate;)Ljava/net/http/HttpRequest$Builder;", "(Ljava/net/http/HttpRequest;Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;)Ljava/net/http/HttpRequest$Builder;", $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$Builder*(*)(HttpRequest*,$BiPredicate*)>(&HttpRequest::newBuilder))},
	{"newBuilder", "()Ljava/net/http/HttpRequest$Builder;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HttpRequest$Builder*(*)()>(&HttpRequest::newBuilder))},
	{"timeout", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/time/Duration;>;", $PUBLIC | $ABSTRACT},
	{"uri", "()Ljava/net/URI;", nullptr, $PUBLIC | $ABSTRACT},
	{"version", "()Ljava/util/Optional;", "()Ljava/util/Optional<Ljava/net/http/HttpClient$Version;>;", $PUBLIC | $ABSTRACT},
	{}
};

$InnerClassInfo _HttpRequest_InnerClassesInfo_[] = {
	{"java.net.http.HttpRequest$BodyPublishers", "java.net.http.HttpRequest", "BodyPublishers", $PUBLIC | $STATIC},
	{"java.net.http.HttpRequest$BodyPublisher", "java.net.http.HttpRequest", "BodyPublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.net.http.HttpRequest$Builder", "java.net.http.HttpRequest", "Builder", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _HttpRequest_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"java.net.http.HttpRequest",
	"java.lang.Object",
	nullptr,
	nullptr,
	_HttpRequest_MethodInfo_,
	nullptr,
	nullptr,
	_HttpRequest_InnerClassesInfo_,
	nullptr,
	nullptr,
	"java.net.http.HttpRequest$BodyPublishers,java.net.http.HttpRequest$BodyPublisher,java.net.http.HttpRequest$Builder"
};

$Object* allocate$HttpRequest($Class* clazz) {
	return $of($alloc(HttpRequest));
}

void HttpRequest::init$() {
}

$HttpRequest$Builder* HttpRequest::newBuilder($URI* uri) {
	return $new($HttpRequestBuilderImpl, uri);
}

$HttpRequest$Builder* HttpRequest::newBuilder(HttpRequest* request, $BiPredicate* filter) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(request);
	$Objects::requireNonNull(filter);
	$var($HttpRequest$Builder, builder, HttpRequest::newBuilder());
	$nc(builder)->uri($(request->uri()));
	builder->expectContinue(request->expectContinue());
	$var($HttpHeaders, headers, $HttpHeaders::of($($nc($(request->headers()))->map()), filter));
	$nc($($nc(headers)->map()))->forEach(static_cast<$BiConsumer*>($$new(HttpRequest$$Lambda$lambda$newBuilder$1, builder)));
	$nc($(request->version()))->ifPresent(static_cast<$Consumer*>($$new(HttpRequest$$Lambda$version$1, static_cast<$HttpRequest$Builder*>(builder))));
	$nc($(request->timeout()))->ifPresent(static_cast<$Consumer*>($$new(HttpRequest$$Lambda$timeout$2, static_cast<$HttpRequest$Builder*>(builder))));
	$var($String, method, request->method());
	$var($Consumer, var$0, static_cast<$Consumer*>($new(HttpRequest$$Lambda$lambda$newBuilder$2$3, builder, method)));
	$nc($(request->bodyPublisher()))->ifPresentOrElse(var$0, static_cast<$Runnable*>($$new(HttpRequest$$Lambda$lambda$newBuilder$3$4, method, builder)));
	return builder;
}

$HttpRequest$Builder* HttpRequest::newBuilder() {
	return $new($HttpRequestBuilderImpl);
}

bool HttpRequest::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf(HttpRequest, obj))) {
		return false;
	}
	$var(HttpRequest, that, $cast(HttpRequest, obj));
	if (!$nc($($nc(that)->method()))->equals($(this->method()))) {
		return false;
	}
	if (!$nc($($nc(that)->uri()))->equals($(this->uri()))) {
		return false;
	}
	if (!$nc($($nc(that)->headers()))->equals($(this->headers()))) {
		return false;
	}
	return true;
}

int32_t HttpRequest::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t var$1 = $nc($(method()))->hashCode();
	int32_t var$0 = var$1 + $nc($(uri()))->hashCode();
	return var$0 + $nc($(headers()))->hashCode();
}

void HttpRequest::lambda$newBuilder$3($String* method, $HttpRequest$Builder* builder) {
	$useLocalCurrentObjectStackCache();
	{
		$var($String, s15412$, method);
		int32_t tmp15412$ = -1;
		switch ($nc(s15412$)->hashCode()) {
		case 0x00011336:
			{
				if (s15412$->equals("GET"_s)) {
					tmp15412$ = 0;
				}
				break;
			}
		case 0x77F979AB:
			{
				if (s15412$->equals("DELETE"_s)) {
					tmp15412$ = 1;
				}
				break;
			}
		}
		switch (tmp15412$) {
		case 0:
			{
				$nc(builder)->GET();
				break;
			}
		case 1:
			{
				$nc(builder)->DELETE();
				break;
			}
		default:
			{
				$nc(builder)->method(method, $($HttpRequest$BodyPublishers::noBody()));
				break;
			}
		}
	}
}

void HttpRequest::lambda$newBuilder$2($HttpRequest$Builder* builder, $String* method, $HttpRequest$BodyPublisher* bodyPublisher) {
	$nc(builder)->method(method, bodyPublisher);
}

void HttpRequest::lambda$newBuilder$1($HttpRequest$Builder* builder, $String* name, $List* values) {
	$nc(values)->forEach(static_cast<$Consumer*>($$new(HttpRequest$$Lambda$lambda$newBuilder$0$5, builder, name)));
}

void HttpRequest::lambda$newBuilder$0($HttpRequest$Builder* builder, $String* name, $String* value) {
	$nc(builder)->header(name, value);
}

HttpRequest::HttpRequest() {
}

$Class* HttpRequest::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpRequest$$Lambda$lambda$newBuilder$1::classInfo$.name)) {
			return HttpRequest$$Lambda$lambda$newBuilder$1::load$(name, initialize);
		}
		if (name->equals(HttpRequest$$Lambda$version$1::classInfo$.name)) {
			return HttpRequest$$Lambda$version$1::load$(name, initialize);
		}
		if (name->equals(HttpRequest$$Lambda$timeout$2::classInfo$.name)) {
			return HttpRequest$$Lambda$timeout$2::load$(name, initialize);
		}
		if (name->equals(HttpRequest$$Lambda$lambda$newBuilder$2$3::classInfo$.name)) {
			return HttpRequest$$Lambda$lambda$newBuilder$2$3::load$(name, initialize);
		}
		if (name->equals(HttpRequest$$Lambda$lambda$newBuilder$3$4::classInfo$.name)) {
			return HttpRequest$$Lambda$lambda$newBuilder$3$4::load$(name, initialize);
		}
		if (name->equals(HttpRequest$$Lambda$lambda$newBuilder$0$5::classInfo$.name)) {
			return HttpRequest$$Lambda$lambda$newBuilder$0$5::load$(name, initialize);
		}
	}
	$loadClass(HttpRequest, name, initialize, &_HttpRequest_ClassInfo_, allocate$HttpRequest);
	return class$;
}

$Class* HttpRequest::class$ = nullptr;

		} // http
	} // net
} // java