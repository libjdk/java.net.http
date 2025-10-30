#include <jdk/internal/net/http/Http2Connection$Http2TubeSubscriber.h>

#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/Runnable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Collection.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/ConcurrentLinkedQueue.h>
#include <java/util/concurrent/Executor.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef MAX_VALUE

using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $ConcurrentLinkedQueue = ::java::util::concurrent::ConcurrentLinkedQueue;
using $Executor = ::java::util::concurrent::Executor;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $Supplier = ::java::util::function::Supplier;
using $Http2Connection = ::jdk::internal::net::http::Http2Connection;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$DelegatingExecutor = ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $SequentialScheduler = ::jdk::internal::net::http::common::SequentialScheduler;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http2Connection$Http2TubeSubscriber$$Lambda$processQueue : public $Runnable {
	$class(Http2Connection$Http2TubeSubscriber$$Lambda$processQueue, $NO_CLASS_INIT, $Runnable)
public:
	void init$(Http2Connection$Http2TubeSubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual void run() override {
		$nc(inst$)->processQueue();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$Http2TubeSubscriber$$Lambda$processQueue>());
	}
	Http2Connection$Http2TubeSubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$Http2TubeSubscriber$$Lambda$processQueue::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http2Connection$Http2TubeSubscriber$$Lambda$processQueue, inst$)},
	{}
};
$MethodInfo Http2Connection$Http2TubeSubscriber$$Lambda$processQueue::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http2Connection$Http2TubeSubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$Http2TubeSubscriber$$Lambda$processQueue::*)(Http2Connection$Http2TubeSubscriber*)>(&Http2Connection$Http2TubeSubscriber$$Lambda$processQueue::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$Http2TubeSubscriber$$Lambda$processQueue::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$Http2TubeSubscriber$$Lambda$processQueue",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$Http2TubeSubscriber$$Lambda$processQueue::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$Http2TubeSubscriber$$Lambda$processQueue, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$Http2TubeSubscriber$$Lambda$processQueue::class$ = nullptr;

class Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1 : public $Supplier {
	$class(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$($List* item) {
		$set(this, item, item);
	}
	virtual $Object* get() override {
		 return $of(Http2Connection$Http2TubeSubscriber::lambda$onNext$0(item));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1>());
	}
	$List* item = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1::fieldInfos[2] = {
	{"item", "Ljava/util/List;", nullptr, $PUBLIC, $field(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1, item)},
	{}
};
$MethodInfo Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/List;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1::*)($List*)>(&Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1::class$ = nullptr;

class Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2 : public $Supplier {
	$class(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Throwable* throwable) {
		$set(this, throwable, throwable);
	}
	virtual $Object* get() override {
		 return $of(Http2Connection$Http2TubeSubscriber::lambda$onError$1(throwable));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2>());
	}
	$Throwable* throwable = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2::fieldInfos[2] = {
	{"throwable", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2, throwable)},
	{}
};
$MethodInfo Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2::methodInfos[3] = {
	{"<init>", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2::*)($Throwable*)>(&Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2::class$ = nullptr;

$FieldInfo _Http2Connection$Http2TubeSubscriber_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/Http2Connection;", nullptr, $FINAL | $SYNTHETIC, $field(Http2Connection$Http2TubeSubscriber, this$0)},
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http2Connection$Http2TubeSubscriber, $assertionsDisabled)},
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $PRIVATE | $VOLATILE, $field(Http2Connection$Http2TubeSubscriber, subscription)},
	{"completed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Http2Connection$Http2TubeSubscriber, completed)},
	{"dropped", "Z", nullptr, $PRIVATE | $VOLATILE, $field(Http2Connection$Http2TubeSubscriber, dropped)},
	{"error", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $VOLATILE, $field(Http2Connection$Http2TubeSubscriber, error)},
	{"queue", "Ljava/util/concurrent/ConcurrentLinkedQueue;", "Ljava/util/concurrent/ConcurrentLinkedQueue<Ljava/nio/ByteBuffer;>;", $PRIVATE | $FINAL, $field(Http2Connection$Http2TubeSubscriber, queue)},
	{"scheduler", "Ljdk/internal/net/http/common/SequentialScheduler;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection$Http2TubeSubscriber, scheduler)},
	{"client", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection$Http2TubeSubscriber, client)},
	{}
};

$MethodInfo _Http2Connection$Http2TubeSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/Http2Connection;Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, 0, $method(static_cast<void(Http2Connection$Http2TubeSubscriber::*)($Http2Connection*,$HttpClientImpl*)>(&Http2Connection$Http2TubeSubscriber::init$))},
	{"dropSubscription", "()V", nullptr, $PUBLIC},
	{"lambda$onError$1", "(Ljava/lang/Throwable;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($Throwable*)>(&Http2Connection$Http2TubeSubscriber::lambda$onError$1))},
	{"lambda$onNext$0", "(Ljava/util/List;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($List*)>(&Http2Connection$Http2TubeSubscriber::lambda$onNext$0))},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(Http2Connection$Http2TubeSubscriber::*)($List*)>(&Http2Connection$Http2TubeSubscriber::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"processQueue", "()V", nullptr, $FINAL, $method(static_cast<void(Http2Connection$Http2TubeSubscriber::*)()>(&Http2Connection$Http2TubeSubscriber::processQueue))},
	{"runOrSchedule", "()V", nullptr, $PRIVATE | $FINAL, $method(static_cast<void(Http2Connection$Http2TubeSubscriber::*)()>(&Http2Connection$Http2TubeSubscriber::runOrSchedule))},
	{}
};

$InnerClassInfo _Http2Connection$Http2TubeSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http2Connection$Http2TubeSubscriber", "jdk.internal.net.http.Http2Connection", "Http2TubeSubscriber", $FINAL},
	{"jdk.internal.net.http.common.FlowTube$TubeSubscriber", "jdk.internal.net.http.common.FlowTube", "TubeSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Http2Connection$Http2TubeSubscriber_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.Http2Connection$Http2TubeSubscriber",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubeSubscriber",
	_Http2Connection$Http2TubeSubscriber_FieldInfo_,
	_Http2Connection$Http2TubeSubscriber_MethodInfo_,
	nullptr,
	nullptr,
	_Http2Connection$Http2TubeSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http2Connection"
};

$Object* allocate$Http2Connection$Http2TubeSubscriber($Class* clazz) {
	return $of($alloc(Http2Connection$Http2TubeSubscriber));
}

bool Http2Connection$Http2TubeSubscriber::$assertionsDisabled = false;

void Http2Connection$Http2TubeSubscriber::init$($Http2Connection* this$0, $HttpClientImpl* client) {
	$set(this, this$0, this$0);
	$set(this, queue, $new($ConcurrentLinkedQueue));
	$set(this, scheduler, $SequentialScheduler::lockingScheduler(static_cast<$Runnable*>($$new(Http2Connection$Http2TubeSubscriber$$Lambda$processQueue, this))));
	$set(this, client, $cast($HttpClientImpl, $Objects::requireNonNull(client)));
}

void Http2Connection$Http2TubeSubscriber::processQueue() {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		try {
			try {
				while (true) {
					bool var$1 = !$nc(this->queue)->isEmpty();
					if (!(var$1 && !$nc(this->scheduler)->isStopped())) {
						break;
					}
					{
						$var($ByteBuffer, buffer, $cast($ByteBuffer, $nc(this->queue)->poll()));
						if ($nc(this->this$0->debug)->on()) {
							$nc(this->this$0->debug)->log("sending %d to Http2Connection.asyncReceive"_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(buffer)->remaining())))}));
						}
						this->this$0->asyncReceive(buffer);
					}
				}
			} catch ($Throwable& t) {
				$var($Throwable, x, this->error);
				if (x == nullptr) {
					$set(this, error, t);
				}
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} /*finally*/ {
			$var($Throwable, x, this->error);
			if (x != nullptr) {
				if ($nc(this->this$0->debug)->on()) {
					$nc(this->this$0->debug)->log("Stopping scheduler"_s, x);
				}
				$nc(this->scheduler)->stop();
				this->this$0->shutdown(x);
			}
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Http2Connection$Http2TubeSubscriber::runOrSchedule() {
	if ($nc(this->client)->isSelectorThread()) {
		$nc(this->scheduler)->runOrSchedule($($nc(this->client)->theExecutor()));
	} else {
		$nc(this->scheduler)->runOrSchedule();
	}
}

void Http2Connection$Http2TubeSubscriber::onSubscribe($Flow$Subscription* subscription) {
	if (!Http2Connection$Http2TubeSubscriber::$assertionsDisabled && !(this->subscription == nullptr || this->dropped == false)) {
		$throwNew($AssertionError);
	}
	$set(this, subscription, subscription);
	this->dropped = false;
	if (!this->completed) {
		if ($nc(this->this$0->debug)->on()) {
			$nc(this->this$0->debug)->log("onSubscribe: requesting Long.MAX_VALUE for reading"_s);
		}
		$nc(subscription)->request($Long::MAX_VALUE);
	} else if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("onSubscribe: already completed"_s);
	}
}

void Http2Connection$Http2TubeSubscriber::onNext($List* item) {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log(static_cast<$Supplier*>($$new(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1, item)));
	}
	$nc(this->queue)->addAll(item);
	runOrSchedule();
}

void Http2Connection$Http2TubeSubscriber::onError($Throwable* throwable) {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log(static_cast<$Supplier*>($$new(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2, throwable)));
	}
	$set(this, error, throwable);
	this->completed = true;
	runOrSchedule();
}

void Http2Connection$Http2TubeSubscriber::onComplete() {
	$var($String, msg, this->this$0->isActive() ? "EOF reached while reading"_s : "Idle connection closed by HTTP/2 peer"_s);
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log(msg);
	}
	$set(this, error, $new($EOFException, msg));
	this->completed = true;
	runOrSchedule();
}

void Http2Connection$Http2TubeSubscriber::dropSubscription() {
	if ($nc(this->this$0->debug)->on()) {
		$nc(this->this$0->debug)->log("dropSubscription"_s);
	}
	this->dropped = true;
}

void Http2Connection$Http2TubeSubscriber::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

$String* Http2Connection$Http2TubeSubscriber::lambda$onError$1($Throwable* throwable) {
	$init(Http2Connection$Http2TubeSubscriber);
	return $str({"onError: "_s, throwable});
}

$String* Http2Connection$Http2TubeSubscriber::lambda$onNext$0($List* item) {
	$init(Http2Connection$Http2TubeSubscriber);
	$useLocalCurrentObjectStackCache();
	$var($String, var$1, $$str({"onNext: got "_s, $$str($Utils::remaining(item)), " bytes in "_s}));
	$var($String, var$0, $$concat(var$1, $$str($nc(item)->size())));
	return $concat(var$0, " buffers");
}

void clinit$Http2Connection$Http2TubeSubscriber($Class* class$) {
	$load($Http2Connection);
	Http2Connection$Http2TubeSubscriber::$assertionsDisabled = !$Http2Connection::class$->desiredAssertionStatus();
}

Http2Connection$Http2TubeSubscriber::Http2Connection$Http2TubeSubscriber() {
}

$Class* Http2Connection$Http2TubeSubscriber::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http2Connection$Http2TubeSubscriber$$Lambda$processQueue::classInfo$.name)) {
			return Http2Connection$Http2TubeSubscriber$$Lambda$processQueue::load$(name, initialize);
		}
		if (name->equals(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1::classInfo$.name)) {
			return Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onNext$0$1::load$(name, initialize);
		}
		if (name->equals(Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2::classInfo$.name)) {
			return Http2Connection$Http2TubeSubscriber$$Lambda$lambda$onError$1$2::load$(name, initialize);
		}
	}
	$loadClass(Http2Connection$Http2TubeSubscriber, name, initialize, &_Http2Connection$Http2TubeSubscriber_ClassInfo_, clinit$Http2Connection$Http2TubeSubscriber, allocate$Http2Connection$Http2TubeSubscriber);
	return class$;
}

$Class* Http2Connection$Http2TubeSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk