#include <jdk/internal/net/http/HttpClientImpl$SelectorAttachment.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/IllegalStateException.h>
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
#include <java/util/AbstractSet.h>
#include <java/util/HashSet.h>
#include <java/util/Iterator.h>
#include <java/util/Set.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef DEBUG

using $AsyncEventArray = $Array<::jdk::internal::net::http::AsyncEvent>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
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
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $AbstractSet = ::java::util::AbstractSet;
using $Collection = ::java::util::Collection;
using $HashSet = ::java::util::HashSet;
using $Iterator = ::java::util::Iterator;
using $Set = ::java::util::Set;
using $Predicate = ::java::util::function::Predicate;
using $Supplier = ::java::util::function::Supplier;
using $Stream = ::java::util::stream::Stream;
using $AsyncEvent = ::jdk::internal::net::http::AsyncEvent;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class HttpClientImpl$SelectorAttachment$$Lambda$toString : public $Supplier {
	$class(HttpClientImpl$SelectorAttachment$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$SelectorAttachment$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$SelectorAttachment$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(HttpClientImpl$SelectorAttachment$$Lambda$toString, inst$)},
	{}
};
$MethodInfo HttpClientImpl$SelectorAttachment$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$SelectorAttachment$$Lambda$toString::*)($String*)>(&HttpClientImpl$SelectorAttachment$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$SelectorAttachment$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$SelectorAttachment$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$SelectorAttachment$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$SelectorAttachment$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$SelectorAttachment$$Lambda$toString::class$ = nullptr;

class HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1 : public $Predicate {
	$class(HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1, $NO_CLASS_INIT, $Predicate)
public:
	void init$(int32_t interestOps) {
		this->interestOps = interestOps;
	}
	virtual bool test(Object$* ev) override {
		 return HttpClientImpl$SelectorAttachment::lambda$events$0(interestOps, $cast($AsyncEvent, ev));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1>());
	}
	int32_t interestOps = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1::fieldInfos[2] = {
	{"interestOps", "I", nullptr, $PUBLIC, $field(HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1, interestOps)},
	{}
};
$MethodInfo HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1::*)(int32_t)>(&HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1::load$($String* name, bool initialize) {
	$loadClass(HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1::class$ = nullptr;

$FieldInfo _HttpClientImpl$SelectorAttachment_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HttpClientImpl$SelectorAttachment, $assertionsDisabled)},
	{"chan", "Ljava/nio/channels/SelectableChannel;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$SelectorAttachment, chan)},
	{"selector", "Ljava/nio/channels/Selector;", nullptr, $PRIVATE | $FINAL, $field(HttpClientImpl$SelectorAttachment, selector)},
	{"pending", "Ljava/util/Set;", "Ljava/util/Set<Ljdk/internal/net/http/AsyncEvent;>;", $PRIVATE | $FINAL, $field(HttpClientImpl$SelectorAttachment, pending)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpClientImpl$SelectorAttachment, debug)},
	{"interestOps", "I", nullptr, $PRIVATE, $field(HttpClientImpl$SelectorAttachment, interestOps)},
	{}
};

$MethodInfo _HttpClientImpl$SelectorAttachment_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/channels/SelectableChannel;Ljava/nio/channels/Selector;)V", nullptr, 0, $method(static_cast<void(HttpClientImpl$SelectorAttachment::*)($SelectableChannel*,$Selector*)>(&HttpClientImpl$SelectorAttachment::init$))},
	{"abortPending", "(Ljava/lang/Throwable;)V", nullptr, 0},
	{"events", "(I)Ljava/util/stream/Stream;", "(I)Ljava/util/stream/Stream<Ljdk/internal/net/http/AsyncEvent;>;", 0},
	{"lambda$events$0", "(ILjdk/internal/net/http/AsyncEvent;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)(int32_t,$AsyncEvent*)>(&HttpClientImpl$SelectorAttachment::lambda$events$0))},
	{"register", "(Ljdk/internal/net/http/AsyncEvent;)V", nullptr, 0, nullptr, "java.nio.channels.ClosedChannelException"},
	{"resetInterestOps", "(I)V", nullptr, 0},
	{}
};

$InnerClassInfo _HttpClientImpl$SelectorAttachment_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HttpClientImpl$SelectorAttachment", "jdk.internal.net.http.HttpClientImpl", "SelectorAttachment", $PRIVATE | $STATIC},
	{}
};

$ClassInfo _HttpClientImpl$SelectorAttachment_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.HttpClientImpl$SelectorAttachment",
	"java.lang.Object",
	nullptr,
	_HttpClientImpl$SelectorAttachment_FieldInfo_,
	_HttpClientImpl$SelectorAttachment_MethodInfo_,
	nullptr,
	nullptr,
	_HttpClientImpl$SelectorAttachment_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HttpClientImpl"
};

$Object* allocate$HttpClientImpl$SelectorAttachment($Class* clazz) {
	return $of($alloc(HttpClientImpl$SelectorAttachment));
}

bool HttpClientImpl$SelectorAttachment::$assertionsDisabled = false;
$Logger* HttpClientImpl$SelectorAttachment::debug = nullptr;

void HttpClientImpl$SelectorAttachment::init$($SelectableChannel* chan, $Selector* selector) {
	$set(this, pending, $new($HashSet));
	$set(this, chan, chan);
	$set(this, selector, selector);
}

void HttpClientImpl$SelectorAttachment::register$($AsyncEvent* e) {
	$useLocalCurrentObjectStackCache();
	int32_t newOps = $nc(e)->interestOps();
	bool reRegister = ((int32_t)(this->interestOps & (uint32_t)newOps)) != newOps;
	this->interestOps |= newOps;
	$nc(this->pending)->add(e);
	if ($nc(HttpClientImpl$SelectorAttachment::debug)->on()) {
		$nc(HttpClientImpl$SelectorAttachment::debug)->log("Registering %s for %d (%s)"_s, $$new($ObjectArray, {
			$of(e),
			$($of($Integer::valueOf(newOps))),
			$($of($Boolean::valueOf(reRegister)))
		}));
	}
	if (reRegister) {
		try {
			$nc(this->chan)->register$(this->selector, this->interestOps, this);
		} catch ($Throwable& x) {
			abortPending(x);
		}
	} else if (!$nc(this->chan)->isOpen()) {
		abortPending($$new($ClosedChannelException));
	}
}

$Stream* HttpClientImpl$SelectorAttachment::events(int32_t interestOps) {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc(this->pending)->stream()))->filter(static_cast<$Predicate*>($$new(HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1, interestOps)));
}

void HttpClientImpl$SelectorAttachment::resetInterestOps(int32_t interestOps) {
	$useLocalCurrentObjectStackCache();
	int32_t newOps = 0;
	$var($Iterator, itr, $nc(this->pending)->iterator());
	while ($nc(itr)->hasNext()) {
		$var($AsyncEvent, event, $cast($AsyncEvent, itr->next()));
		int32_t evops = $nc(event)->interestOps();
		if (event->repeating()) {
			newOps |= evops;
			continue;
		}
		if (((int32_t)(evops & (uint32_t)interestOps)) != 0) {
			itr->remove();
		} else {
			newOps |= evops;
		}
	}
	this->interestOps = newOps;
	$var($SelectionKey, key, $nc(this->chan)->keyFor(this->selector));
	if (newOps == 0 && key != nullptr && $nc(this->pending)->isEmpty()) {
		key->cancel();
	} else {
		try {
			if (key == nullptr || !key->isValid()) {
				$throwNew($CancelledKeyException);
			}
			key->interestOps(newOps);
			if (!$nc(this->chan)->isOpen()) {
				abortPending($$new($ClosedChannelException));
				return;
			}
			if (!HttpClientImpl$SelectorAttachment::$assertionsDisabled && !(key->interestOps() == newOps)) {
				$throwNew($AssertionError);
			}
		} catch ($CancelledKeyException& x) {
			if ($nc(HttpClientImpl$SelectorAttachment::debug)->on()) {
				$nc(HttpClientImpl$SelectorAttachment::debug)->log($$str({"key cancelled for "_s, this->chan}));
			}
			abortPending(x);
		}
	}
}

void HttpClientImpl$SelectorAttachment::abortPending($Throwable* x) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(this->pending)->isEmpty()) {
		$var($AsyncEventArray, evts, $fcast($AsyncEventArray, $nc(this->pending)->toArray($$new($AsyncEventArray, 0))));
		$nc(this->pending)->clear();
		$var($IOException, io, $Utils::getIOException(x));
		{
			$var($AsyncEventArray, arr$, evts);
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($AsyncEvent, event, arr$->get(i$));
				{
					$nc(event)->abort(io);
				}
			}
		}
	}
}

bool HttpClientImpl$SelectorAttachment::lambda$events$0(int32_t interestOps, $AsyncEvent* ev) {
	$init(HttpClientImpl$SelectorAttachment);
	return ((int32_t)($nc(ev)->interestOps() & (uint32_t)interestOps)) != 0;
}

void clinit$HttpClientImpl$SelectorAttachment($Class* class$) {
	$load($HttpClientImpl);
	HttpClientImpl$SelectorAttachment::$assertionsDisabled = !$HttpClientImpl::class$->desiredAssertionStatus();
	$init($Utils);
	$assignStatic(HttpClientImpl$SelectorAttachment::debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(HttpClientImpl$SelectorAttachment$$Lambda$toString, static_cast<$String*>("SelectorAttachment"_s))), $Utils::DEBUG));
}

HttpClientImpl$SelectorAttachment::HttpClientImpl$SelectorAttachment() {
}

$Class* HttpClientImpl$SelectorAttachment::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpClientImpl$SelectorAttachment$$Lambda$toString::classInfo$.name)) {
			return HttpClientImpl$SelectorAttachment$$Lambda$toString::load$(name, initialize);
		}
		if (name->equals(HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1::classInfo$.name)) {
			return HttpClientImpl$SelectorAttachment$$Lambda$lambda$events$0$1::load$(name, initialize);
		}
	}
	$loadClass(HttpClientImpl$SelectorAttachment, name, initialize, &_HttpClientImpl$SelectorAttachment_ClassInfo_, clinit$HttpClientImpl$SelectorAttachment, allocate$HttpClientImpl$SelectorAttachment);
	return class$;
}

$Class* HttpClientImpl$SelectorAttachment::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk