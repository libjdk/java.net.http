#include <jdk/internal/net/http/ResponseSubscribers$HttpResponseInputStream.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/InterruptedException.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/ArrayBlockingQueue.h>
#include <java/util/concurrent/BlockingQueue.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG
#undef LAST_BUFFER
#undef LAST_LIST
#undef MAX_BUFFERS_IN_QUEUE

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $ArrayBlockingQueue = ::java::util::concurrent::ArrayBlockingQueue;
using $BlockingQueue = ::java::util::concurrent::BlockingQueue;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $Supplier = ::java::util::function::Supplier;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class ResponseSubscribers$HttpResponseInputStream$$Lambda$toString : public $Supplier {
	$class(ResponseSubscribers$HttpResponseInputStream$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$HttpResponseInputStream$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$HttpResponseInputStream$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseSubscribers$HttpResponseInputStream$$Lambda$toString, inst$)},
	{}
};
$MethodInfo ResponseSubscribers$HttpResponseInputStream$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$HttpResponseInputStream$$Lambda$toString::*)($String*)>(&ResponseSubscribers$HttpResponseInputStream$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$HttpResponseInputStream$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$HttpResponseInputStream$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$HttpResponseInputStream$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$HttpResponseInputStream$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$HttpResponseInputStream$$Lambda$toString::class$ = nullptr;

$FieldInfo _ResponseSubscribers$HttpResponseInputStream_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseSubscribers$HttpResponseInputStream, $assertionsDisabled)},
	{"MAX_BUFFERS_IN_QUEUE", "I", nullptr, $STATIC | $FINAL, $constField(ResponseSubscribers$HttpResponseInputStream, MAX_BUFFERS_IN_QUEUE)},
	{"LAST_BUFFER", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ResponseSubscribers$HttpResponseInputStream, LAST_BUFFER)},
	{"LAST_LIST", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE | $STATIC | $FINAL, $staticField(ResponseSubscribers$HttpResponseInputStream, LAST_LIST)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ResponseSubscribers$HttpResponseInputStream, debug)},
	{"buffers", "Ljava/util/concurrent/BlockingQueue;", "Ljava/util/concurrent/BlockingQueue<Ljava/util/List<Ljava/nio/ByteBuffer;>;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$HttpResponseInputStream, buffers)},
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $PRIVATE | $VOLATILE, $field(ResponseSubscribers$HttpResponseInputStream, subscription)},
	{"closed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(ResponseSubscribers$HttpResponseInputStream, closed)},
	{"failed", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $VOLATILE, $field(ResponseSubscribers$HttpResponseInputStream, failed)},
	{"currentListItr", "Ljava/util/Iterator;", "Ljava/util/Iterator<Ljava/nio/ByteBuffer;>;", $PRIVATE | $VOLATILE, $field(ResponseSubscribers$HttpResponseInputStream, currentListItr)},
	{"currentBuffer", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $VOLATILE, $field(ResponseSubscribers$HttpResponseInputStream, currentBuffer)},
	{"subscribed", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$HttpResponseInputStream, subscribed)},
	{}
};

$MethodInfo _ResponseSubscribers$HttpResponseInputStream_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$HttpResponseInputStream::*)()>(&ResponseSubscribers$HttpResponseInputStream::init$))},
	{"<init>", "(I)V", nullptr, 0, $method(static_cast<void(ResponseSubscribers$HttpResponseInputStream::*)(int32_t)>(&ResponseSubscribers$HttpResponseInputStream::init$))},
	{"available", "()I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"close", "()V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"current", "()Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $method(static_cast<$ByteBuffer*(ResponseSubscribers$HttpResponseInputStream::*)()>(&ResponseSubscribers$HttpResponseInputStream::current)), "java.io.IOException"},
	{"getBody", "()Ljava/util/concurrent/CompletionStage;", "()Ljava/util/concurrent/CompletionStage<Ljava/io/InputStream;>;", $PUBLIC},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"read", "([BII)I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"read", "()I", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"*toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _ResponseSubscribers$HttpResponseInputStream_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$HttpResponseInputStream", "jdk.internal.net.http.ResponseSubscribers", "HttpResponseInputStream", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", "jdk.internal.net.http.ResponseSubscribers", "TrustedSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$HttpResponseInputStream_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$HttpResponseInputStream",
	"java.io.InputStream",
	"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber",
	_ResponseSubscribers$HttpResponseInputStream_FieldInfo_,
	_ResponseSubscribers$HttpResponseInputStream_MethodInfo_,
	"Ljava/io/InputStream;Ljdk/internal/net/http/ResponseSubscribers$TrustedSubscriber<Ljava/io/InputStream;>;",
	nullptr,
	_ResponseSubscribers$HttpResponseInputStream_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$HttpResponseInputStream($Class* clazz) {
	return $of($alloc(ResponseSubscribers$HttpResponseInputStream));
}

int32_t ResponseSubscribers$HttpResponseInputStream::hashCode() {
	 return this->$InputStream::hashCode();
}

bool ResponseSubscribers$HttpResponseInputStream::equals(Object$* arg0) {
	 return this->$InputStream::equals(arg0);
}

$Object* ResponseSubscribers$HttpResponseInputStream::clone() {
	 return this->$InputStream::clone();
}

$String* ResponseSubscribers$HttpResponseInputStream::toString() {
	 return this->$InputStream::toString();
}

void ResponseSubscribers$HttpResponseInputStream::finalize() {
	this->$InputStream::finalize();
}

bool ResponseSubscribers$HttpResponseInputStream::$assertionsDisabled = false;
$ByteBuffer* ResponseSubscribers$HttpResponseInputStream::LAST_BUFFER = nullptr;
$List* ResponseSubscribers$HttpResponseInputStream::LAST_LIST = nullptr;
$Logger* ResponseSubscribers$HttpResponseInputStream::debug = nullptr;

void ResponseSubscribers$HttpResponseInputStream::init$() {
	ResponseSubscribers$HttpResponseInputStream::init$(ResponseSubscribers$HttpResponseInputStream::MAX_BUFFERS_IN_QUEUE);
}

void ResponseSubscribers$HttpResponseInputStream::init$(int32_t maxBuffers) {
	$InputStream::init$();
	$set(this, subscribed, $new($AtomicBoolean));
	int32_t capacity = (maxBuffers <= 0 ? ResponseSubscribers$HttpResponseInputStream::MAX_BUFFERS_IN_QUEUE : maxBuffers);
	$set(this, buffers, $new($ArrayBlockingQueue, capacity + 1));
}

$CompletionStage* ResponseSubscribers$HttpResponseInputStream::getBody() {
	return $CompletableFuture::completedStage(this);
}

$ByteBuffer* ResponseSubscribers$HttpResponseInputStream::current() {
	$useLocalCurrentObjectStackCache();
	while (this->currentBuffer == nullptr || !$nc(this->currentBuffer)->hasRemaining()) {
		if (this->closed || this->failed != nullptr) {
			$throwNew($IOException, "closed"_s, this->failed);
		}
		if (this->currentBuffer == ResponseSubscribers$HttpResponseInputStream::LAST_BUFFER) {
			break;
		}
		try {
			if (this->currentListItr == nullptr || !$nc(this->currentListItr)->hasNext()) {
				if ($nc(ResponseSubscribers$HttpResponseInputStream::debug)->on()) {
					$nc(ResponseSubscribers$HttpResponseInputStream::debug)->log("Taking list of Buffers"_s);
				}
				$var($List, lb, $cast($List, $nc(this->buffers)->take()));
				$set(this, currentListItr, $nc(lb)->iterator());
				if ($nc(ResponseSubscribers$HttpResponseInputStream::debug)->on()) {
					$nc(ResponseSubscribers$HttpResponseInputStream::debug)->log("List of Buffers Taken"_s);
				}
				if (this->closed || this->failed != nullptr) {
					$throwNew($IOException, "closed"_s, this->failed);
				}
				if (lb == ResponseSubscribers$HttpResponseInputStream::LAST_LIST) {
					$set(this, currentListItr, nullptr);
					$set(this, currentBuffer, ResponseSubscribers$HttpResponseInputStream::LAST_BUFFER);
					break;
				}
				$var($Flow$Subscription, s, this->subscription);
				if (s != nullptr) {
					if ($nc(ResponseSubscribers$HttpResponseInputStream::debug)->on()) {
						$nc(ResponseSubscribers$HttpResponseInputStream::debug)->log("Increased demand by 1"_s);
					}
					s->request(1);
				}
				if (!ResponseSubscribers$HttpResponseInputStream::$assertionsDisabled && !(this->currentListItr != nullptr)) {
					$throwNew($AssertionError);
				}
				if (lb->isEmpty()) {
					continue;
				}
			}
			if (!ResponseSubscribers$HttpResponseInputStream::$assertionsDisabled && !(this->currentListItr != nullptr)) {
				$throwNew($AssertionError);
			}
			if (!ResponseSubscribers$HttpResponseInputStream::$assertionsDisabled && !$nc(this->currentListItr)->hasNext()) {
				$throwNew($AssertionError);
			}
			if ($nc(ResponseSubscribers$HttpResponseInputStream::debug)->on()) {
				$nc(ResponseSubscribers$HttpResponseInputStream::debug)->log("Next Buffer"_s);
			}
			$set(this, currentBuffer, $cast($ByteBuffer, $nc(this->currentListItr)->next()));
		} catch ($InterruptedException& ex) {
		}
	}
	if (!ResponseSubscribers$HttpResponseInputStream::$assertionsDisabled && !(this->currentBuffer == ResponseSubscribers$HttpResponseInputStream::LAST_BUFFER || $nc(this->currentBuffer)->hasRemaining())) {
		$throwNew($AssertionError);
	}
	return this->currentBuffer;
}

int32_t ResponseSubscribers$HttpResponseInputStream::read($bytes* bytes, int32_t off, int32_t len) {
	$Objects::checkFromIndexSize(off, len, $nc(bytes)->length);
	if (len == 0) {
		return 0;
	}
	$var($ByteBuffer, buffer, nullptr);
	if (($assign(buffer, current())) == ResponseSubscribers$HttpResponseInputStream::LAST_BUFFER) {
		return -1;
	}
	int32_t read = $Math::min($nc(buffer)->remaining(), len);
	if (!ResponseSubscribers$HttpResponseInputStream::$assertionsDisabled && !(read > 0 && read <= $nc(buffer)->remaining())) {
		$throwNew($AssertionError);
	}
	$nc(buffer)->get(bytes, off, read);
	return read;
}

int32_t ResponseSubscribers$HttpResponseInputStream::read() {
	$var($ByteBuffer, buffer, nullptr);
	if (($assign(buffer, current())) == ResponseSubscribers$HttpResponseInputStream::LAST_BUFFER) {
		return -1;
	}
	return (int32_t)($nc(buffer)->get() & (uint32_t)255);
}

int32_t ResponseSubscribers$HttpResponseInputStream::available() {
	$useLocalCurrentObjectStackCache();
	if (this->closed) {
		return 0;
	}
	int32_t available = 0;
	$var($ByteBuffer, current, this->currentBuffer);
	if (current == ResponseSubscribers$HttpResponseInputStream::LAST_BUFFER) {
		return 0;
	}
	if (current != nullptr) {
		available = current->remaining();
	}
	if (available != 0) {
		return available;
	}
	$var($Iterator, iterator, this->currentListItr);
	if (iterator != nullptr && iterator->hasNext()) {
		return 1;
	}
	if ($nc(this->buffers)->isEmpty()) {
		return 0;
	}
	return 1;
}

void ResponseSubscribers$HttpResponseInputStream::onSubscribe($Flow$Subscription* s) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(s);
	try {
		if (!$nc(this->subscribed)->compareAndSet(false, true)) {
			s->cancel();
		} else {
			bool closed = false;
			$synchronized(this) {
				closed = this->closed;
				if (!closed) {
					$set(this, subscription, s);
				}
			}
			if (closed) {
				s->cancel();
				return;
			}
			if (!ResponseSubscribers$HttpResponseInputStream::$assertionsDisabled && !($nc(this->buffers)->remainingCapacity() > 1)) {
				$throwNew($AssertionError);
			}
			if ($nc(ResponseSubscribers$HttpResponseInputStream::debug)->on()) {
				$nc(ResponseSubscribers$HttpResponseInputStream::debug)->log($$str({"onSubscribe: requesting "_s, $$str($Math::max(1, $nc(this->buffers)->remainingCapacity() - 1))}));
			}
			s->request($Math::max(1, $nc(this->buffers)->remainingCapacity() - 1));
		}
	} catch ($Throwable& t) {
		$set(this, failed, t);
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					close();
				} catch ($IOException& x) {
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				onError(t);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void ResponseSubscribers$HttpResponseInputStream::onNext($List* t) {
	$Objects::requireNonNull(t);
	try {
		if ($nc(ResponseSubscribers$HttpResponseInputStream::debug)->on()) {
			$nc(ResponseSubscribers$HttpResponseInputStream::debug)->log("next item received"_s);
		}
		if (!$nc(this->buffers)->offer(t)) {
			$throwNew($IllegalStateException, "queue is full"_s);
		}
		if ($nc(ResponseSubscribers$HttpResponseInputStream::debug)->on()) {
			$nc(ResponseSubscribers$HttpResponseInputStream::debug)->log("item offered"_s);
		}
	} catch ($Throwable& ex) {
		$set(this, failed, ex);
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					close();
				} catch ($IOException& ex1) {
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				onError(ex);
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void ResponseSubscribers$HttpResponseInputStream::onError($Throwable* thrwbl) {
	$set(this, subscription, nullptr);
	$set(this, failed, $cast($Throwable, $Objects::requireNonNull(thrwbl)));
	$nc(this->buffers)->offer(ResponseSubscribers$HttpResponseInputStream::LAST_LIST);
}

void ResponseSubscribers$HttpResponseInputStream::onComplete() {
	$set(this, subscription, nullptr);
	onNext(ResponseSubscribers$HttpResponseInputStream::LAST_LIST);
}

void ResponseSubscribers$HttpResponseInputStream::close() {
	$useLocalCurrentObjectStackCache();
	$var($Flow$Subscription, s, nullptr);
	$synchronized(this) {
		if (this->closed) {
			return;
		}
		this->closed = true;
		$assign(s, this->subscription);
		$set(this, subscription, nullptr);
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (s != nullptr) {
				s->cancel();
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->buffers)->offer(ResponseSubscribers$HttpResponseInputStream::LAST_LIST);
			$InputStream::close();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void ResponseSubscribers$HttpResponseInputStream::onNext(Object$* t) {
	this->onNext($cast($List, t));
}

void clinit$ResponseSubscribers$HttpResponseInputStream($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$load($ResponseSubscribers);
	ResponseSubscribers$HttpResponseInputStream::$assertionsDisabled = !$ResponseSubscribers::class$->desiredAssertionStatus();
	$assignStatic(ResponseSubscribers$HttpResponseInputStream::LAST_BUFFER, $ByteBuffer::wrap($$new($bytes, 0)));
	$assignStatic(ResponseSubscribers$HttpResponseInputStream::LAST_LIST, $List::of($of(ResponseSubscribers$HttpResponseInputStream::LAST_BUFFER)));
	$init($Utils);
	$assignStatic(ResponseSubscribers$HttpResponseInputStream::debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(ResponseSubscribers$HttpResponseInputStream$$Lambda$toString, static_cast<$String*>("HttpResponseInputStream"_s))), $Utils::DEBUG));
}

ResponseSubscribers$HttpResponseInputStream::ResponseSubscribers$HttpResponseInputStream() {
}

$Class* ResponseSubscribers$HttpResponseInputStream::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResponseSubscribers$HttpResponseInputStream$$Lambda$toString::classInfo$.name)) {
			return ResponseSubscribers$HttpResponseInputStream$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(ResponseSubscribers$HttpResponseInputStream, name, initialize, &_ResponseSubscribers$HttpResponseInputStream_ClassInfo_, clinit$ResponseSubscribers$HttpResponseInputStream, allocate$ResponseSubscribers$HttpResponseInputStream);
	return class$;
}

$Class* ResponseSubscribers$HttpResponseInputStream::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk