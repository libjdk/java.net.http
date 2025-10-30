#include <jdk/internal/net/http/HttpClientImpl$SelectorManager.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
#include <java/lang/Iterable.h>
#include <java/lang/Math.h>
#include <java/lang/Runnable.h>
#include <java/lang/ThreadGroup.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/channels/CancelledKeyException.h>
#include <java/nio/channels/ClosedChannelException.h>
#include <java/nio/channels/SelectableChannel.h>
#include <java/nio/channels/SelectionKey.h>
#include <java/nio/channels/Selector.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Set.h>
#include <java/util/function/Consumer.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/AsyncTriggerEvent.h>
#include <jdk/internal/net/http/ConnectionPool.h>
#include <jdk/internal/net/http/HttpClientImpl$SelectorAttachment.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Pair.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef ASSERTIONSENABLED
#undef DEF_NODEADLINE
#undef MAX_NODEADLINE
#undef MIN_NODEADLINE
#undef NODEADLINE

using $IOException = ::java::io::IOException;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Iterable = ::java::lang::Iterable;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Runnable = ::java::lang::Runnable;
using $RuntimeException = ::java::lang::RuntimeException;
using $ThreadGroup = ::java::lang::ThreadGroup;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $CancelledKeyException = ::java::nio::channels::CancelledKeyException;
using $ClosedChannelException = ::java::nio::channels::ClosedChannelException;
using $SelectableChannel = ::java::nio::channels::SelectableChannel;
using $SelectionKey = ::java::nio::channels::SelectionKey;
using $Selector = ::java::nio::channels::Selector;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $AbstractSelectableChannel = ::java::nio::channels::spi::AbstractSelectableChannel;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Set = ::java::util::Set;
using $Consumer = ::java::util::function::Consumer;
using $Stream = ::java::util::stream::Stream;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;
using $AsyncTriggerEvent = ::jdk::internal::net::http::AsyncTriggerEvent;
using $ConnectionPool = ::jdk::internal::net::http::ConnectionPool;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpClientImpl$SelectorAttachment = ::jdk::internal::net::http::HttpClientImpl$SelectorAttachment;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Pair = ::jdk::internal::net::http::common::Pair;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class HttpClientImpl$SelectorManager$$Lambda$lambda$run$0 : public $Consumer {
	$class(HttpClientImpl$SelectorManager$$Lambda$lambda$run$0, $NO_CLASS_INIT, $Consumer)
public:
	void init$($List* errorList, $IOException* ex) {
		$set(this, errorList, errorList);
		$set(this, ex, ex);
	}
	virtual void accept(Object$* e) override {
		HttpClientImpl$SelectorManager::lambda$run$0(errorList, ex, $cast($AsyncEvent, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$SelectorManager$$Lambda$lambda$run$0>());
	}
	$List* errorList = nullptr;
	$IOException* ex = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$0::fieldInfos[3] = {
	{"errorList", "Ljava/util/List;", nullptr, $PUBLIC, $field(HttpClientImpl$SelectorManager$$Lambda$lambda$run$0, errorList)},
	{"ex", "Ljava/io/IOException;", nullptr, $PUBLIC, $field(HttpClientImpl$SelectorManager$$Lambda$lambda$run$0, ex)},
	{}
};
$MethodInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$0::methodInfos[3] = {
	{"<init>", "(Ljava/util/List;Ljava/io/IOException;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$SelectorManager$$Lambda$lambda$run$0::*)($List*,$IOException*)>(&HttpClientImpl$SelectorManager$$Lambda$lambda$run$0::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$SelectorManager$$Lambda$lambda$run$0",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$SelectorManager$$Lambda$lambda$run$0::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$SelectorManager$$Lambda$lambda$run$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$SelectorManager$$Lambda$lambda$run$0::class$ = nullptr;

class HttpClientImpl$SelectorManager$$Lambda$add$1 : public $Consumer {
	$class(HttpClientImpl$SelectorManager$$Lambda$add$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$($List* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* arg0) override {
		$nc(inst$)->add(arg0);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$SelectorManager$$Lambda$add$1>());
	}
	$List* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$SelectorManager$$Lambda$add$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpClientImpl$SelectorManager$$Lambda$add$1, inst$)},
	{}
};
$MethodInfo HttpClientImpl$SelectorManager$$Lambda$add$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/List;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$SelectorManager$$Lambda$add$1::*)($List*)>(&HttpClientImpl$SelectorManager$$Lambda$add$1::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$SelectorManager$$Lambda$add$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$SelectorManager$$Lambda$add$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$SelectorManager$$Lambda$add$1::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$SelectorManager$$Lambda$add$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$SelectorManager$$Lambda$add$1::class$ = nullptr;

class HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2 : public $Runnable {
	$class(HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2, $NO_CLASS_INIT, $Runnable)
public:
	void init$($HttpClientImpl$SelectorAttachment* sa, int32_t eventsOccurred) {
		$set(this, sa, sa);
		this->eventsOccurred = eventsOccurred;
	}
	virtual void run() override {
		HttpClientImpl$SelectorManager::lambda$run$2(sa, eventsOccurred);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2>());
	}
	$HttpClientImpl$SelectorAttachment* sa = nullptr;
	int32_t eventsOccurred = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2::fieldInfos[3] = {
	{"sa", "Ljdk/internal/net/http/HttpClientImpl$SelectorAttachment;", nullptr, $PUBLIC, $field(HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2, sa)},
	{"eventsOccurred", "I", nullptr, $PUBLIC, $field(HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2, eventsOccurred)},
	{}
};
$MethodInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl$SelectorAttachment;I)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2::*)($HttpClientImpl$SelectorAttachment*,int32_t)>(&HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2::init$))},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2",
	"java.lang.Object",
	"java.lang.Runnable",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2::class$ = nullptr;

class HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3 : public $Consumer {
	$class(HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3, $NO_CLASS_INIT, $Consumer)
public:
	void init$(HttpClientImpl$SelectorManager* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* e) override {
		$nc(inst$)->lambda$run$3($cast($AsyncEvent, e));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3>());
	}
	HttpClientImpl$SelectorManager* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3, inst$)},
	{}
};
$MethodInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl$SelectorManager;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3::*)(HttpClientImpl$SelectorManager*)>(&HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3::class$ = nullptr;

class HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4 : public $Consumer {
	$class(HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4, $NO_CLASS_INIT, $Consumer)
public:
	void init$(HttpClientImpl$SelectorManager* inst) {
		$set(this, inst$, inst);
	}
	virtual void accept(Object$* p) override {
		$nc(inst$)->lambda$run$4($cast($Pair, p));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4>());
	}
	HttpClientImpl$SelectorManager* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4, inst$)},
	{}
};
$MethodInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl$SelectorManager;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4::*)(HttpClientImpl$SelectorManager*)>(&HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4::class$ = nullptr;

class HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5 : public $Consumer {
	$class(HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* r) override {
		HttpClientImpl$SelectorManager::lambda$run$5($cast($Runnable, r));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5::*)()>(&HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5::class$ = nullptr;

$FieldInfo _HttpClientImpl$SelectorManager_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpClientImpl$SelectorManager, $assertionsDisabled)},
	{"MIN_NODEADLINE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HttpClientImpl$SelectorManager, MIN_NODEADLINE)},
	{"MAX_NODEADLINE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HttpClientImpl$SelectorManager, MAX_NODEADLINE)},
	{"DEF_NODEADLINE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(HttpClientImpl$SelectorManager, DEF_NODEADLINE)},
	{"NODEADLINE", "J", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpClientImpl$SelectorManager, NODEADLINE)},
	{"selector", "Ljava/nio/channels/Selector;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$SelectorManager, selector)},
	{"closed", "Z", nullptr, $PRIVATE | $VOLATILE, $field(HttpClientImpl$SelectorManager, closed)},
	{"registrations", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/net/http/AsyncEvent;>;", $PRIVATE | $FINAL, $field(HttpClientImpl$SelectorManager, registrations)},
	{"deregistrations", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/net/http/AsyncTriggerEvent;>;", $PRIVATE | $FINAL, $field(HttpClientImpl$SelectorManager, deregistrations)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$SelectorManager, debug)},
	{"debugtimeout", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$SelectorManager, debugtimeout)},
	{"owner", "Ljdk/internal/net/http/HttpClientImpl;", nullptr, 0, $field(HttpClientImpl$SelectorManager, owner)},
	{"pool", "Ljdk/internal/net/http/ConnectionPool;", nullptr, 0, $field(HttpClientImpl$SelectorManager, pool)},
	{}
};

$MethodInfo _HttpClientImpl$SelectorManager_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpClientImpl;)V", nullptr, 0, $method(static_cast<void(HttpClientImpl$SelectorManager::*)($HttpClientImpl*)>(&HttpClientImpl$SelectorManager::init$)), "java.io.IOException"},
	{"cancel", "(Ljava/nio/channels/SocketChannel;)V", nullptr, $SYNCHRONIZED, $method(static_cast<void(HttpClientImpl$SelectorManager::*)($SocketChannel*)>(&HttpClientImpl$SelectorManager::cancel))},
	{"eventUpdated", "(Ljdk/internal/net/http/AsyncEvent;)V", nullptr, 0, $method(static_cast<void(HttpClientImpl$SelectorManager::*)($AsyncEvent*)>(&HttpClientImpl$SelectorManager::eventUpdated)), "java.nio.channels.ClosedChannelException"},
	{"handleEvent", "(Ljdk/internal/net/http/AsyncEvent;Ljava/io/IOException;)V", nullptr, 0, $method(static_cast<void(HttpClientImpl$SelectorManager::*)($AsyncEvent*,$IOException*)>(&HttpClientImpl$SelectorManager::handleEvent))},
	{"lambda$run$0", "(Ljava/util/List;Ljava/io/IOException;Ljdk/internal/net/http/AsyncEvent;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($List*,$IOException*,$AsyncEvent*)>(&HttpClientImpl$SelectorManager::lambda$run$0))},
	{"lambda$run$2", "(Ljdk/internal/net/http/HttpClientImpl$SelectorAttachment;I)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($HttpClientImpl$SelectorAttachment*,int32_t)>(&HttpClientImpl$SelectorManager::lambda$run$2))},
	{"lambda$run$3", "(Ljdk/internal/net/http/AsyncEvent;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(HttpClientImpl$SelectorManager::*)($AsyncEvent*)>(&HttpClientImpl$SelectorManager::lambda$run$3))},
	{"lambda$run$4", "(Ljdk/internal/net/http/common/Pair;)V", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<void(HttpClientImpl$SelectorManager::*)($Pair*)>(&HttpClientImpl$SelectorManager::lambda$run$4))},
	{"lambda$run$5", "(Ljava/lang/Runnable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($Runnable*)>(&HttpClientImpl$SelectorManager::lambda$run$5))},
	{"register", "(Ljdk/internal/net/http/AsyncEvent;)V", nullptr, $SYNCHRONIZED, $method(static_cast<void(HttpClientImpl$SelectorManager::*)($AsyncEvent*)>(&HttpClientImpl$SelectorManager::register$))},
	{"run", "()V", nullptr, $PUBLIC},
	{"shutdown", "()V", nullptr, $SYNCHRONIZED, $method(static_cast<void(HttpClientImpl$SelectorManager::*)()>(&HttpClientImpl$SelectorManager::shutdown))},
	{"wakeupSelector", "()V", nullptr, 0, $method(static_cast<void(HttpClientImpl$SelectorManager::*)()>(&HttpClientImpl$SelectorManager::wakeupSelector))},
	{}
};

$InnerClassInfo _HttpClientImpl$SelectorManager_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpClientImpl$SelectorManager", "jdk.internal.net.http.HttpClientImpl", "SelectorManager", $PRIVATE | $STATIC | $FINAL},
	{}
};

$ClassInfo _HttpClientImpl$SelectorManager_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.HttpClientImpl$SelectorManager",
	"java.lang.Thread",
	nullptr,
	_HttpClientImpl$SelectorManager_FieldInfo_,
	_HttpClientImpl$SelectorManager_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClientImpl$SelectorManager_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpClientImpl"
};

$Object* allocate$HttpClientImpl$SelectorManager($Class* clazz) {
	return $of($alloc(HttpClientImpl$SelectorManager));
}

bool HttpClientImpl$SelectorManager::$assertionsDisabled = false;
int64_t HttpClientImpl$SelectorManager::NODEADLINE = 0;

void HttpClientImpl$SelectorManager::init$($HttpClientImpl* ref) {
	$useLocalCurrentObjectStackCache();
	$Thread::init$(nullptr, nullptr, $$str({"HttpClient-"_s, $$str($nc(ref)->id), "-SelectorManager"_s}), 0, false);
	$set(this, owner, ref);
	$set(this, debug, $nc(ref)->debug);
	$set(this, debugtimeout, ref->debugtimeout);
	$set(this, pool, ref->connectionPool());
	$set(this, registrations, $new($ArrayList));
	$set(this, deregistrations, $new($ArrayList));
	$set(this, selector, $Selector::open());
}

void HttpClientImpl$SelectorManager::eventUpdated($AsyncEvent* e) {
	$useLocalCurrentObjectStackCache();
	if ($equals($Thread::currentThread(), this)) {
		$var($SelectionKey, key, $nc($($nc(e)->channel()))->keyFor(this->selector));
		if (key != nullptr && key->isValid()) {
			$var($HttpClientImpl$SelectorAttachment, sa, $cast($HttpClientImpl$SelectorAttachment, key->attachment()));
			$nc(sa)->register$(e);
		} else if (e->interestOps() != 0) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("No key for channel"_s);
			}
			e->abort($$new($IOException, "No key for channel"_s));
		}
	} else {
		register$(e);
	}
}

void HttpClientImpl$SelectorManager::register$($AsyncEvent* e) {
	$synchronized(this) {
		$nc(this->registrations)->add(e);
		$nc(this->selector)->wakeup();
	}
}

void HttpClientImpl$SelectorManager::cancel($SocketChannel* e) {
	$synchronized(this) {
		$var($SelectionKey, key, $nc(e)->keyFor(this->selector));
		if (key != nullptr) {
			key->cancel();
		}
		$nc(this->selector)->wakeup();
	}
}

void HttpClientImpl$SelectorManager::wakeupSelector() {
	$nc(this->selector)->wakeup();
}

void HttpClientImpl$SelectorManager::shutdown() {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$Log::logTrace("{0}: shutting down"_s, $$new($ObjectArray, {$($of(getName()))}));
		if ($nc(this->debug)->on()) {
			$nc(this->debug)->log("SelectorManager shutting down"_s);
		}
		this->closed = true;
		{
			$var($Throwable, var$0, nullptr);
			try {
				try {
					$nc(this->selector)->close();
				} catch ($IOException& ignored) {
				}
			} catch ($Throwable& var$1) {
				$assign(var$0, var$1);
			} /*finally*/ {
				$nc(this->owner)->stop();
			}
			if (var$0 != nullptr) {
				$throw(var$0);
			}
		}
	}
}

void HttpClientImpl$SelectorManager::run() {
	$useLocalCurrentObjectStackCache();
	$var($List, errorList, $new($ArrayList));
	$var($List, readyList, $new($ArrayList));
	$var($List, resetList, $new($ArrayList));
	{
		$var($Throwable, var$0, nullptr);
		bool return$1 = false;
		try {
			try {
				if ($Log::channel()) {
					$Log::logChannel($$str({$(getName()), ": starting"_s}), $$new($ObjectArray, 0));
				}
				while (!$($Thread::currentThread())->isInterrupted()) {
					$synchronized(this) {
						if (!HttpClientImpl$SelectorManager::$assertionsDisabled && !errorList->isEmpty()) {
							$throwNew($AssertionError);
						}
						if (!HttpClientImpl$SelectorManager::$assertionsDisabled && !readyList->isEmpty()) {
							$throwNew($AssertionError);
						}
						if (!HttpClientImpl$SelectorManager::$assertionsDisabled && !resetList->isEmpty()) {
							$throwNew($AssertionError);
						}
						{
							$var($Iterator, i$, $nc(this->deregistrations)->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($AsyncTriggerEvent, event, $cast($AsyncTriggerEvent, i$->next()));
								{
									$nc(event)->handle();
								}
							}
						}
						$nc(this->deregistrations)->clear();
						{
							$var($Iterator, i$, $nc(this->registrations)->iterator());
							for (; $nc(i$)->hasNext();) {
								$var($AsyncEvent, event, $cast($AsyncEvent, i$->next()));
								{
									if ($instanceOf($AsyncTriggerEvent, event)) {
										readyList->add(event);
										continue;
									}
									$var($SelectableChannel, chan, $nc(event)->channel());
									$var($SelectionKey, key, nullptr);
									try {
										$assign(key, $nc(chan)->keyFor(this->selector));
										$var($HttpClientImpl$SelectorAttachment, sa, nullptr);
										if (key == nullptr || !$nc(key)->isValid()) {
											if (key != nullptr) {
												$nc(this->selector)->selectNow();
											}
											$assign(sa, $new($HttpClientImpl$SelectorAttachment, chan, this->selector));
										} else {
											$assign(sa, $cast($HttpClientImpl$SelectorAttachment, key->attachment()));
										}
										$nc(sa)->register$(event);
										if (!chan->isOpen()) {
											$throwNew($IOException, "Channel closed"_s);
										}
									} catch ($IOException& e) {
										$Log::logTrace("{0}: {1}"_s, $$new($ObjectArray, {
											$($of(getName())),
											$of(e)
										}));
										if ($nc(this->debug)->on()) {
											$nc(this->debug)->log($$str({"Got "_s, $($of(e)->getClass()->getName()), " while handling registration events"_s}));
										}
										$nc(chan)->close();
										errorList->add($$new($Pair, event, e));
										if (key != nullptr) {
											key->cancel();
											$nc(this->selector)->selectNow();
										}
									}
								}
							}
						}
						$nc(this->registrations)->clear();
						$nc($($nc(this->selector)->selectedKeys()))->clear();
					}
					{
						$var($Iterator, i$, readyList->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($AsyncEvent, event, $cast($AsyncEvent, i$->next()));
							{
								if (!HttpClientImpl$SelectorManager::$assertionsDisabled && !$instanceOf($AsyncTriggerEvent, event)) {
									$throwNew($AssertionError);
								}
								$nc(event)->handle();
							}
						}
					}
					readyList->clear();
					{
						$var($Iterator, i$, errorList->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($Pair, error, $cast($Pair, i$->next()));
							{
								handleEvent($cast($AsyncEvent, $nc(error)->first), $cast($IOException, error->second));
							}
						}
					}
					errorList->clear();
					if (!$nc(this->owner)->isReferenced()) {
						$Log::logTrace("{0}: {1}"_s, $$new($ObjectArray, {
							$($of(getName())),
							$of("HttpClient no longer referenced. Exiting..."_s)
						}));
						return$1 = true;
						goto $finally;
					}
					int64_t nextTimeout = $nc(this->owner)->purgeTimeoutsAndReturnNextDeadline();
					if ($nc(this->debugtimeout)->on()) {
						$nc(this->debugtimeout)->log("next timeout: %d"_s, $$new($ObjectArray, {$($of($Long::valueOf(nextTimeout)))}));
					}
					int64_t nextExpiry = $nc(this->pool)->purgeExpiredConnectionsAndReturnNextDeadline();
					if ($nc(this->debugtimeout)->on()) {
						$nc(this->debugtimeout)->log("next expired: %d"_s, $$new($ObjectArray, {$($of($Long::valueOf(nextExpiry)))}));
					}
					if (!HttpClientImpl$SelectorManager::$assertionsDisabled && !(nextTimeout >= 0)) {
						$throwNew($AssertionError);
					}
					if (!HttpClientImpl$SelectorManager::$assertionsDisabled && !(nextExpiry >= 0)) {
						$throwNew($AssertionError);
					}
					if (nextTimeout <= 0) {
						nextTimeout = HttpClientImpl$SelectorManager::NODEADLINE;
					}
					if (nextExpiry <= 0) {
						nextExpiry = HttpClientImpl$SelectorManager::NODEADLINE;
					} else {
						nextExpiry = $Math::min(HttpClientImpl$SelectorManager::NODEADLINE, nextExpiry);
					}
					int64_t millis = $Math::min(nextExpiry, nextTimeout);
					if ($nc(this->debugtimeout)->on()) {
						$nc(this->debugtimeout)->log("Next deadline is %d"_s, $$new($ObjectArray, {$($of($Long::valueOf((millis == 0 ? HttpClientImpl$SelectorManager::NODEADLINE : millis))))}));
					}
					int32_t n = $nc(this->selector)->select(millis == 0 ? HttpClientImpl$SelectorManager::NODEADLINE : millis);
					if (n == 0) {
						if (!$nc(this->owner)->isReferenced()) {
							$Log::logTrace("{0}: {1}"_s, $$new($ObjectArray, {
								$($of(getName())),
								$of("HttpClient no longer referenced. Exiting..."_s)
							}));
							return$1 = true;
							goto $finally;
						}
						$nc(this->owner)->purgeTimeoutsAndReturnNextDeadline();
						continue;
					}
					$var($Set, keys, $nc(this->selector)->selectedKeys());
					if (!HttpClientImpl$SelectorManager::$assertionsDisabled && !errorList->isEmpty()) {
						$throwNew($AssertionError);
					}
					{
						$var($Iterator, i$, $nc(keys)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($SelectionKey, key, $cast($SelectionKey, i$->next()));
							{
								$var($HttpClientImpl$SelectorAttachment, sa, $cast($HttpClientImpl$SelectorAttachment, $nc(key)->attachment()));
								if (!key->isValid()) {
									$var($IOException, ex, $nc($nc(sa)->chan)->isOpen() ? $new($IOException, "Invalid key"_s) : static_cast<$IOException*>($new($ClosedChannelException)));
									$nc($nc(sa)->pending)->forEach(static_cast<$Consumer*>($$new(HttpClientImpl$SelectorManager$$Lambda$lambda$run$0, errorList, ex)));
									$nc(sa->pending)->clear();
									continue;
								}
								int32_t eventsOccurred = 0;
								try {
									eventsOccurred = key->readyOps();
								} catch ($CancelledKeyException& ex) {
									$var($IOException, io, $Utils::getIOException(ex));
									$nc($nc(sa)->pending)->forEach(static_cast<$Consumer*>($$new(HttpClientImpl$SelectorManager$$Lambda$lambda$run$0, errorList, io)));
									$nc(sa->pending)->clear();
									continue;
								}
								$nc($($nc(sa)->events(eventsOccurred)))->forEach(static_cast<$Consumer*>($$new(HttpClientImpl$SelectorManager$$Lambda$add$1, static_cast<$List*>(readyList))));
								resetList->add(static_cast<$Runnable*>($$new(HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2, sa, eventsOccurred)));
							}
						}
					}
					$nc(this->selector)->selectNow();
					$nc($($nc(this->selector)->selectedKeys()))->clear();
					readyList->forEach(static_cast<$Consumer*>($$new(HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3, this)));
					readyList->clear();
					errorList->forEach(static_cast<$Consumer*>($$new(HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4, this)));
					errorList->clear();
					resetList->forEach(static_cast<$Consumer*>($$new(HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5)));
					resetList->clear();
				}
			} catch ($Throwable& e) {
				if (!this->closed) {
					$var($String, err, $Utils::stackTrace(e));
					$Log::logError("{0}: {1}: {2}"_s, $$new($ObjectArray, {
						$($of(getName())),
						$of("HttpClientImpl shutting down due to fatal error"_s),
						$of(err)
					}));
				}
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log("shutting down"_s, e);
				}
				$init($Utils);
				if ($Utils::ASSERTIONSENABLED && !$nc(this->debug)->on()) {
					e->printStackTrace($System::err);
				}
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} $finally: {
			if ($Log::channel()) {
				$Log::logChannel($$str({$(getName()), ": stopping"_s}), $$new($ObjectArray, 0));
			}
			shutdown();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return;
		}
	}
}

void HttpClientImpl$SelectorManager::handleEvent($AsyncEvent* event, $IOException* ioe) {
	if (this->closed || ioe != nullptr) {
		$nc(event)->abort(ioe);
	} else {
		$nc(event)->handle();
	}
}

void HttpClientImpl$SelectorManager::lambda$run$5($Runnable* r) {
	$init(HttpClientImpl$SelectorManager);
	$nc(r)->run();
}

void HttpClientImpl$SelectorManager::lambda$run$4($Pair* p) {
	handleEvent($cast($AsyncEvent, $nc(p)->first), $cast($IOException, p->second));
}

void HttpClientImpl$SelectorManager::lambda$run$3($AsyncEvent* e) {
	handleEvent(e, nullptr);
}

void HttpClientImpl$SelectorManager::lambda$run$2($HttpClientImpl$SelectorAttachment* sa, int32_t eventsOccurred) {
	$init(HttpClientImpl$SelectorManager);
	$nc(sa)->resetInterestOps(eventsOccurred);
}

void HttpClientImpl$SelectorManager::lambda$run$0($List* errorList, $IOException* ex, $AsyncEvent* e) {
	$init(HttpClientImpl$SelectorManager);
	$nc(errorList)->add($$new($Pair, e, ex));
}

void clinit$HttpClientImpl$SelectorManager($Class* class$) {
	$load($HttpClientImpl);
	HttpClientImpl$SelectorManager::$assertionsDisabled = !$HttpClientImpl::class$->desiredAssertionStatus();
	{
		int64_t deadline = $Utils::getIntegerProperty("jdk.internal.httpclient.selectorTimeout"_s, HttpClientImpl$SelectorManager::DEF_NODEADLINE);
		if (deadline <= 0) {
			deadline = HttpClientImpl$SelectorManager::DEF_NODEADLINE;
		}
		deadline = $Math::max(deadline, (int64_t)HttpClientImpl$SelectorManager::MIN_NODEADLINE);
		HttpClientImpl$SelectorManager::NODEADLINE = $Math::min(deadline, (int64_t)HttpClientImpl$SelectorManager::MAX_NODEADLINE);
	}
}

HttpClientImpl$SelectorManager::HttpClientImpl$SelectorManager() {
}

$Class* HttpClientImpl$SelectorManager::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpClientImpl$SelectorManager$$Lambda$lambda$run$0::classInfo$.name)) {
			return HttpClientImpl$SelectorManager$$Lambda$lambda$run$0::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$SelectorManager$$Lambda$add$1::classInfo$.name)) {
			return HttpClientImpl$SelectorManager$$Lambda$add$1::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2::classInfo$.name)) {
			return HttpClientImpl$SelectorManager$$Lambda$lambda$run$2$2::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3::classInfo$.name)) {
			return HttpClientImpl$SelectorManager$$Lambda$lambda$run$3$3::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4::classInfo$.name)) {
			return HttpClientImpl$SelectorManager$$Lambda$lambda$run$4$4::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5::classInfo$.name)) {
			return HttpClientImpl$SelectorManager$$Lambda$lambda$run$5$5::load$(name, initialize);
		}
	}
	$loadClass(HttpClientImpl$SelectorManager, name, initialize, &_HttpClientImpl$SelectorManager_ClassInfo_, clinit$HttpClientImpl$SelectorManager, allocate$HttpClientImpl$SelectorManager);
	return class$;
}

$Class* HttpClientImpl$SelectorManager::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk