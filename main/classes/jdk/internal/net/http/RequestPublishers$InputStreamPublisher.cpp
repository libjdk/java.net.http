#include <jdk/internal/net/http/RequestPublishers$InputStreamPublisher.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/Iterable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/Iterator.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/PullPublisher.h>
#include <jdk/internal/net/http/RequestPublishers$StreamIterator.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Iterable = ::java::lang::Iterable;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpRequest$BodyPublisher = ::java::net::http::HttpRequest$BodyPublisher;
using $Iterator = ::java::util::Iterator;
using $Objects = ::java::util::Objects;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Supplier = ::java::util::function::Supplier;
using $PullPublisher = ::jdk::internal::net::http::PullPublisher;
using $RequestPublishers = ::jdk::internal::net::http::RequestPublishers;
using $RequestPublishers$StreamIterator = ::jdk::internal::net::http::RequestPublishers$StreamIterator;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0 : public $Iterable {
	$class(RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0, $NO_CLASS_INIT, $Iterable)
public:
	void init$($InputStream* is) {
		$set(this, is, is);
	}
	virtual $Iterator* iterator() override {
		 return RequestPublishers$InputStreamPublisher::lambda$iterableOf$0(is);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0>());
	}
	$InputStream* is = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0::fieldInfos[2] = {
	{"is", "Ljava/io/InputStream;", nullptr, $PUBLIC, $field(RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0, is)},
	{}
};
$MethodInfo RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0::methodInfos[3] = {
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0::*)($InputStream*)>(&RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0::init$))},
	{"iterator", "()Ljava/util/Iterator;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0",
	"java.lang.Object",
	"java.lang.Iterable",
	fieldInfos,
	methodInfos
};
$Class* RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0::class$ = nullptr;

$FieldInfo _RequestPublishers$InputStreamPublisher_FieldInfo_[] = {
	{"streamSupplier", "Ljava/util/function/Supplier;", "Ljava/util/function/Supplier<+Ljava/io/InputStream;>;", $PRIVATE | $FINAL, $field(RequestPublishers$InputStreamPublisher, streamSupplier)},
	{}
};

$MethodInfo _RequestPublishers$InputStreamPublisher_MethodInfo_[] = {
	{"<init>", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<+Ljava/io/InputStream;>;)V", $PUBLIC, $method(static_cast<void(RequestPublishers$InputStreamPublisher::*)($Supplier*)>(&RequestPublishers$InputStreamPublisher::init$))},
	{"contentLength", "()J", nullptr, $PUBLIC},
	{"iterableOf", "(Ljava/io/InputStream;)Ljava/lang/Iterable;", "(Ljava/io/InputStream;)Ljava/lang/Iterable<Ljava/nio/ByteBuffer;>;", $PROTECTED},
	{"lambda$iterableOf$0", "(Ljava/io/InputStream;)Ljava/util/Iterator;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Iterator*(*)($InputStream*)>(&RequestPublishers$InputStreamPublisher::lambda$iterableOf$0))},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{}
};

$InnerClassInfo _RequestPublishers$InputStreamPublisher_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RequestPublishers$InputStreamPublisher", "jdk.internal.net.http.RequestPublishers", "InputStreamPublisher", $PUBLIC | $STATIC},
	{"java.net.http.HttpRequest$BodyPublisher", "java.net.http.HttpRequest", "BodyPublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _RequestPublishers$InputStreamPublisher_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.RequestPublishers$InputStreamPublisher",
	"java.lang.Object",
	"java.net.http.HttpRequest$BodyPublisher",
	_RequestPublishers$InputStreamPublisher_FieldInfo_,
	_RequestPublishers$InputStreamPublisher_MethodInfo_,
	nullptr,
	nullptr,
	_RequestPublishers$InputStreamPublisher_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RequestPublishers"
};

$Object* allocate$RequestPublishers$InputStreamPublisher($Class* clazz) {
	return $of($alloc(RequestPublishers$InputStreamPublisher));
}

void RequestPublishers$InputStreamPublisher::init$($Supplier* streamSupplier) {
	$set(this, streamSupplier, $cast($Supplier, $Objects::requireNonNull(streamSupplier)));
}

void RequestPublishers$InputStreamPublisher::subscribe($Flow$Subscriber* subscriber) {
	$useLocalCurrentObjectStackCache();
	$var($PullPublisher, publisher, nullptr);
	$var($InputStream, is, $cast($InputStream, $nc(this->streamSupplier)->get()));
	if (is == nullptr) {
		$var($Throwable, t, $new($IOException, "streamSupplier returned null"_s));
		$assign(publisher, $new($PullPublisher, nullptr, t));
	} else {
		$assign(publisher, $new($PullPublisher, $(iterableOf(is)), nullptr));
	}
	$nc(publisher)->subscribe(subscriber);
}

$Iterable* RequestPublishers$InputStreamPublisher::iterableOf($InputStream* is) {
	return static_cast<$Iterable*>($new(RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0, is));
}

int64_t RequestPublishers$InputStreamPublisher::contentLength() {
	return -1;
}

$Iterator* RequestPublishers$InputStreamPublisher::lambda$iterableOf$0($InputStream* is) {
	$init(RequestPublishers$InputStreamPublisher);
	return $new($RequestPublishers$StreamIterator, is);
}

RequestPublishers$InputStreamPublisher::RequestPublishers$InputStreamPublisher() {
}

$Class* RequestPublishers$InputStreamPublisher::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0::classInfo$.name)) {
			return RequestPublishers$InputStreamPublisher$$Lambda$lambda$iterableOf$0::load$(name, initialize);
		}
	}
	$loadClass(RequestPublishers$InputStreamPublisher, name, initialize, &_RequestPublishers$InputStreamPublisher_ClassInfo_, allocate$RequestPublishers$InputStreamPublisher);
	return class$;
}

$Class* RequestPublishers$InputStreamPublisher::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk