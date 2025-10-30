#include <jdk/internal/net/http/WindowController.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/InternalError.h>
#include <java/lang/Iterable.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedHashMap.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/concurrent/locks/ReentrantLock.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/Stream.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG
#undef DEFAULT_INITIAL_WINDOW_SIZE

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $Iterable = ::java::lang::Iterable;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedHashMap = ::java::util::LinkedHashMap;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $ReentrantLock = ::java::util::concurrent::locks::ReentrantLock;
using $Consumer = ::java::util::function::Consumer;
using $Supplier = ::java::util::function::Supplier;
using $Stream = ::jdk::internal::net::http::Stream;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class WindowController$$Lambda$toString : public $Supplier {
	$class(WindowController$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WindowController$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo WindowController$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(WindowController$$Lambda$toString, inst$)},
	{}
};
$MethodInfo WindowController$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(WindowController$$Lambda$toString::*)($String*)>(&WindowController$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo WindowController$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.WindowController$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* WindowController$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(WindowController$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WindowController$$Lambda$toString::class$ = nullptr;

class WindowController$$Lambda$signalWindowUpdate$1 : public $Consumer {
	$class(WindowController$$Lambda$signalWindowUpdate$1, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* inst$) override {
		$sure($Stream, inst$)->signalWindowUpdate();
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<WindowController$$Lambda$signalWindowUpdate$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo WindowController$$Lambda$signalWindowUpdate$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(WindowController$$Lambda$signalWindowUpdate$1::*)()>(&WindowController$$Lambda$signalWindowUpdate$1::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo WindowController$$Lambda$signalWindowUpdate$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.WindowController$$Lambda$signalWindowUpdate$1",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* WindowController$$Lambda$signalWindowUpdate$1::load$($String* name, bool initialize) {
	$loadClass(WindowController$$Lambda$signalWindowUpdate$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* WindowController$$Lambda$signalWindowUpdate$1::class$ = nullptr;

$FieldInfo _WindowController_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(WindowController, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $STATIC | $FINAL, $staticField(WindowController, debug)},
	{"DEFAULT_INITIAL_WINDOW_SIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(WindowController, DEFAULT_INITIAL_WINDOW_SIZE)},
	{"connectionWindowSize", "I", nullptr, $PRIVATE, $field(WindowController, connectionWindowSize$)},
	{"streams", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Ljava/lang/Integer;>;", $PRIVATE | $FINAL, $field(WindowController, streams)},
	{"pending", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/Integer;Ljava/util/Map$Entry<Ljdk/internal/net/http/Stream<*>;Ljava/lang/Integer;>;>;", $PRIVATE | $FINAL, $field(WindowController, pending)},
	{"controllerLock", "Ljava/util/concurrent/locks/ReentrantLock;", nullptr, $PRIVATE | $FINAL, $field(WindowController, controllerLock)},
	{}
};

$MethodInfo _WindowController_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(WindowController::*)()>(&WindowController::init$))},
	{"adjustActiveStreams", "(I)V", nullptr, 0, $method(static_cast<void(WindowController::*)(int32_t)>(&WindowController::adjustActiveStreams))},
	{"connectionWindowSize", "()I", nullptr, 0, $method(static_cast<int32_t(WindowController::*)()>(&WindowController::connectionWindowSize))},
	{"increaseConnectionWindow", "(I)Z", nullptr, 0, $method(static_cast<bool(WindowController::*)(int32_t)>(&WindowController::increaseConnectionWindow))},
	{"increaseStreamWindow", "(II)Z", nullptr, 0, $method(static_cast<bool(WindowController::*)(int32_t,int32_t)>(&WindowController::increaseStreamWindow))},
	{"registerStream", "(II)V", nullptr, 0, $method(static_cast<void(WindowController::*)(int32_t,int32_t)>(&WindowController::registerStream))},
	{"removeStream", "(I)V", nullptr, 0, $method(static_cast<void(WindowController::*)(int32_t)>(&WindowController::removeStream))},
	{"streamWindowSize", "(I)I", nullptr, 0, $method(static_cast<int32_t(WindowController::*)(int32_t)>(&WindowController::streamWindowSize))},
	{"tryAcquire", "(IILjdk/internal/net/http/Stream;)I", "(IILjdk/internal/net/http/Stream<*>;)I", 0, $method(static_cast<int32_t(WindowController::*)(int32_t,int32_t,$Stream*)>(&WindowController::tryAcquire))},
	{}
};

$ClassInfo _WindowController_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.WindowController",
	"java.lang.Object",
	nullptr,
	_WindowController_FieldInfo_,
	_WindowController_MethodInfo_
};

$Object* allocate$WindowController($Class* clazz) {
	return $of($alloc(WindowController));
}

bool WindowController::$assertionsDisabled = false;
$Logger* WindowController::debug = nullptr;

void WindowController::init$() {
	$set(this, streams, $new($HashMap));
	$set(this, pending, $new($LinkedHashMap));
	$set(this, controllerLock, $new($ReentrantLock));
	this->connectionWindowSize$ = WindowController::DEFAULT_INITIAL_WINDOW_SIZE;
}

void WindowController::registerStream(int32_t streamid, int32_t initialStreamWindowSize) {
	$useLocalCurrentObjectStackCache();
	$nc(this->controllerLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($Object, var$1, $of($Integer::valueOf(streamid)));
			$var($Integer, old, $cast($Integer, $nc(this->streams)->put(var$1, $($Integer::valueOf(initialStreamWindowSize)))));
			if (old != nullptr) {
				$throwNew($InternalError, $$str({"Unexpected entry ["_s, old, "] for streamid: "_s, $$str(streamid)}));
			}
		} catch ($Throwable& var$2) {
			$assign(var$0, var$2);
		} /*finally*/ {
			$nc(this->controllerLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void WindowController::removeStream(int32_t streamid) {
	$useLocalCurrentObjectStackCache();
	$nc(this->controllerLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($Integer, old, $cast($Integer, $nc(this->streams)->remove($($Integer::valueOf(streamid)))));
			bool isClientStream = ((int32_t)(streamid & (uint32_t)1)) == 1;
			if (old == nullptr && isClientStream) {
				$throwNew($InternalError, $$str({"Expected entry for streamid: "_s, $$str(streamid)}));
			} else if (old != nullptr && !isClientStream) {
				$throwNew($InternalError, $$str({"Unexpected entry for streamid: "_s, $$str(streamid)}));
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->controllerLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

int32_t WindowController::tryAcquire(int32_t requestAmount, int32_t streamid, $Stream* stream) {
	$useLocalCurrentObjectStackCache();
	$nc(this->controllerLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			$var($Integer, streamSize, $cast($Integer, $nc(this->streams)->get($($Integer::valueOf(streamid)))));
			if (streamSize == nullptr) {
				$throwNew($InternalError, $$str({"Expected entry for streamid: "_s, $$str(streamid)}));
			}
			int32_t x = $Math::min(requestAmount, $Math::min($nc(streamSize)->intValue(), this->connectionWindowSize$));
			if (x <= 0) {
				if ($nc(WindowController::debug)->on()) {
					$nc(WindowController::debug)->log("Stream %d requesting %d but only %d available (stream: %d, connection: %d)"_s, $$new($ObjectArray, {
						$($of($Integer::valueOf(streamid))),
						$($of($Integer::valueOf(requestAmount))),
						$($of($Integer::valueOf($Math::min($nc(streamSize)->intValue(), this->connectionWindowSize$)))),
						$of(streamSize),
						$($of($Integer::valueOf(this->connectionWindowSize$)))
					}));
				}
				$var($Object, var$3, $of($Integer::valueOf(streamid)));
				$nc(this->pending)->put(var$3, $($Map::entry(stream, $($Integer::valueOf(requestAmount)))));
				var$2 = x;
				return$1 = true;
				goto $finally;
			}
			$nc(this->pending)->remove($($Integer::valueOf(streamid)));
			$assign(streamSize, $Integer::valueOf(($nc(streamSize)->intValue() - x)));
			$nc(this->streams)->put($($Integer::valueOf(streamid)), streamSize);
			this->connectionWindowSize$ -= x;
			if ($nc(WindowController::debug)->on()) {
				$nc(WindowController::debug)->log("Stream %d amount allocated %d, now %d available (stream: %d, connection: %d)"_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(streamid))),
					$($of($Integer::valueOf(x))),
					$($of($Integer::valueOf($Math::min($nc(streamSize)->intValue(), this->connectionWindowSize$)))),
					$of(streamSize),
					$($of($Integer::valueOf(this->connectionWindowSize$)))
				}));
			}
			var$2 = x;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$4) {
			$assign(var$0, var$4);
		} $finally: {
			$nc(this->controllerLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

bool WindowController::increaseConnectionWindow(int32_t amount) {
	$useLocalCurrentObjectStackCache();
	$var($List, candidates, nullptr);
	$nc(this->controllerLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			int32_t size = this->connectionWindowSize$;
			size += amount;
			if (size < 0) {
				var$2 = false;
				return$1 = true;
				goto $finally;
			}
			this->connectionWindowSize$ = size;
			if ($nc(WindowController::debug)->on()) {
				$nc(WindowController::debug)->log("Connection window size is now %d (amount added %d)"_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(size))),
					$($of($Integer::valueOf(amount)))
				}));
			}
			$var($Iterator, iter, $nc($($nc(this->pending)->entrySet()))->iterator());
			while ($nc(iter)->hasNext() && size > 0) {
				$var($Map$Entry, item, $cast($Map$Entry, iter->next()));
				$var($Integer, streamSize, $cast($Integer, $nc(this->streams)->get($($nc(item)->getKey()))));
				if (streamSize == nullptr) {
					iter->remove();
				} else {
					$var($Map$Entry, e, $cast($Map$Entry, $nc(item)->getValue()));
					int32_t requestedAmount = $nc(($cast($Integer, $($nc(e)->getValue()))))->intValue();
					int32_t minAmount = 1;
					if (size >= minAmount && $nc(streamSize)->intValue() >= minAmount) {
						size -= $Math::min(streamSize->intValue(), requestedAmount);
						iter->remove();
						if (candidates == nullptr) {
							$assign(candidates, $new($ArrayList));
						}
						$nc(candidates)->add($cast($Stream, $(e->getKey())));
					}
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->controllerLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	if (candidates != nullptr) {
		candidates->forEach(static_cast<$Consumer*>($$new(WindowController$$Lambda$signalWindowUpdate$1)));
	}
	return true;
}

bool WindowController::increaseStreamWindow(int32_t amount, int32_t streamid) {
	$useLocalCurrentObjectStackCache();
	$var($Stream, s, nullptr);
	$nc(this->controllerLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		bool var$2 = false;
		bool return$1 = false;
		try {
			$var($Integer, size, $cast($Integer, $nc(this->streams)->get($($Integer::valueOf(streamid)))));
			if (size == nullptr) {
				if ($nc(WindowController::debug)->on()) {
					$nc(WindowController::debug)->log("WARNING: No entry found for streamid: %s. May be cancelled?"_s, $$new($ObjectArray, {$($of($Integer::valueOf(streamid)))}));
				}
			} else {
				int32_t prev = $nc(size)->intValue();
				$assign(size, $Integer::valueOf(prev + amount));
				if (size->intValue() < prev) {
					var$2 = false;
					return$1 = true;
					goto $finally;
				}
				$nc(this->streams)->put($($Integer::valueOf(streamid)), size);
				if ($nc(WindowController::debug)->on()) {
					$nc(WindowController::debug)->log("Stream %s window size is now %s (amount added %d)"_s, $$new($ObjectArray, {
						$($of($Integer::valueOf(streamid))),
						$of(size),
						$($of($Integer::valueOf(amount)))
					}));
				}
				$var($Map$Entry, p, $cast($Map$Entry, $nc(this->pending)->get($($Integer::valueOf(streamid)))));
				if (p != nullptr) {
					int32_t minAmount = 1;
					if (size->intValue() >= minAmount && this->connectionWindowSize$ >= minAmount) {
						$nc(this->pending)->remove($($Integer::valueOf(streamid)));
						$assign(s, $cast($Stream, p->getKey()));
					}
				}
			}
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->controllerLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	if (s != nullptr) {
		s->signalWindowUpdate();
	}
	return true;
}

void WindowController::adjustActiveStreams(int32_t adjustAmount) {
	$useLocalCurrentObjectStackCache();
	if (!WindowController::$assertionsDisabled && !(adjustAmount != 0)) {
		$throwNew($AssertionError);
	}
	$nc(this->controllerLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		try {
			{
				$var($Iterator, i$, $nc($($nc(this->streams)->entrySet()))->iterator());
				for (; $nc(i$)->hasNext();) {
					$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
					{
						int32_t streamid = $nc(($cast($Integer, $($nc(entry)->getKey()))))->intValue();
						if (streamid != 0 && (streamid % 2) != 0) {
							$var($Integer, size, $cast($Integer, entry->getValue()));
							$assign(size, $Integer::valueOf(($nc(size)->intValue() + adjustAmount)));
							$nc(this->streams)->put($($Integer::valueOf(streamid)), size);
							if ($nc(WindowController::debug)->on()) {
								$nc(WindowController::debug)->log("Stream %s window size is now %s (adjusting amount %d)"_s, $$new($ObjectArray, {
									$($of($Integer::valueOf(streamid))),
									$of(size),
									$($of($Integer::valueOf(adjustAmount)))
								}));
							}
						}
					}
				}
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$nc(this->controllerLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

int32_t WindowController::connectionWindowSize() {
	$nc(this->controllerLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			var$2 = this->connectionWindowSize$;
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->controllerLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

int32_t WindowController::streamWindowSize(int32_t streamid) {
	$useLocalCurrentObjectStackCache();
	$nc(this->controllerLock)->lock();
	{
		$var($Throwable, var$0, nullptr);
		int32_t var$2 = 0;
		bool return$1 = false;
		try {
			$var($Integer, size, $cast($Integer, $nc(this->streams)->get($($Integer::valueOf(streamid)))));
			if (size == nullptr) {
				$throwNew($InternalError, $$str({"Expected entry for streamid: "_s, $$str(streamid)}));
			}
			var$2 = $nc(size)->intValue();
			return$1 = true;
			goto $finally;
		} catch ($Throwable& var$3) {
			$assign(var$0, var$3);
		} $finally: {
			$nc(this->controllerLock)->unlock();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
		if (return$1) {
			return var$2;
		}
	}
	$shouldNotReachHere();
}

void clinit$WindowController($Class* class$) {
	WindowController::$assertionsDisabled = !WindowController::class$->desiredAssertionStatus();
	$init($Utils);
	$assignStatic(WindowController::debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(WindowController$$Lambda$toString, static_cast<$String*>("WindowController"_s))), $Utils::DEBUG));
}

WindowController::WindowController() {
}

$Class* WindowController::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(WindowController$$Lambda$toString::classInfo$.name)) {
			return WindowController$$Lambda$toString::load$(name, initialize);
		}
		if (name->equals(WindowController$$Lambda$signalWindowUpdate$1::classInfo$.name)) {
			return WindowController$$Lambda$signalWindowUpdate$1::load$(name, initialize);
		}
	}
	$loadClass(WindowController, name, initialize, &_WindowController_ClassInfo_, clinit$WindowController, allocate$WindowController);
	return class$;
}

$Class* WindowController::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk