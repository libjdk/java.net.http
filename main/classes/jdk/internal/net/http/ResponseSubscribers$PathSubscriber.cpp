#include <jdk/internal/net/http/ResponseSubscribers$PathSubscriber.h>

#include <java/io/Closeable.h>
#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/Channel.h>
#include <java/nio/channels/FileChannel.h>
#include <java/nio/channels/InterruptibleChannel.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/nio/file/OpenOption.h>
#include <java/nio/file/Path.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/security/PrivilegedAction.h>
#include <java/security/PrivilegedActionException.h>
#include <java/security/PrivilegedExceptionAction.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <java/util/concurrent/atomic/AtomicBoolean.h>
#include <java/util/function/IntFunction.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef EMPTY_BB_ARRAY
#undef EMPTY_FILE_PERMISSIONS

using $CloseableArray = $Array<::java::io::Closeable>;
using $FilePermissionArray = $Array<::java::io::FilePermission>;
using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $OpenOptionArray = $Array<::java::nio::file::OpenOption>;
using $PermissionArray = $Array<::java::security::Permission>;
using $Closeable = ::java::io::Closeable;
using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Channel = ::java::nio::channels::Channel;
using $FileChannel = ::java::nio::channels::FileChannel;
using $InterruptibleChannel = ::java::nio::channels::InterruptibleChannel;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $OpenOption = ::java::nio::file::OpenOption;
using $Path = ::java::nio::file::Path;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $PrivilegedActionException = ::java::security::PrivilegedActionException;
using $PrivilegedExceptionAction = ::java::security::PrivilegedExceptionAction;
using $Collection = ::java::util::Collection;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $AtomicBoolean = ::java::util::concurrent::atomic::AtomicBoolean;
using $IntFunction = ::java::util::function::IntFunction;
using $Stream = ::java::util::stream::Stream;
using $ResponseSubscribers = ::jdk::internal::net::http::ResponseSubscribers;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0 : public $IntFunction {
	$class(ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0, $NO_CLASS_INIT, $IntFunction)
public:
	void init$() {
	}
	virtual $Object* apply(int32_t x$0) override {
		 return $of(ResponseSubscribers$PathSubscriber::lambda$new$0(x$0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0::*)()>(&ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0::init$))},
	{"apply", "(I)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.util.function.IntFunction",
	nullptr,
	methodInfos
};
$Class* ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0::class$ = nullptr;

class ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1 : public $PrivilegedExceptionAction {
	$class(ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1, $NO_CLASS_INIT, $PrivilegedExceptionAction)
public:
	void init$(ResponseSubscribers$PathSubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$onSubscribe$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1>());
	}
	ResponseSubscribers$PathSubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1, inst$)},
	{}
};
$MethodInfo ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseSubscribers$PathSubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1::*)(ResponseSubscribers$PathSubscriber*)>(&ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1",
	"java.lang.Object",
	"java.security.PrivilegedExceptionAction",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1::class$ = nullptr;

class ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2 : public $PrivilegedAction {
	$class(ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$(ResponseSubscribers$PathSubscriber* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* run() override {
		 return $of($nc(inst$)->lambda$close$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2>());
	}
	ResponseSubscribers$PathSubscriber* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2, inst$)},
	{}
};
$MethodInfo ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/ResponseSubscribers$PathSubscriber;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2::*)(ResponseSubscribers$PathSubscriber*)>(&ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2::load$($String* name, bool initialize) {
	$loadClass(ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2::class$ = nullptr;

$FieldInfo _ResponseSubscribers$PathSubscriber_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseSubscribers$PathSubscriber, $assertionsDisabled)},
	{"EMPTY_FILE_PERMISSIONS", "[Ljava/io/FilePermission;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(ResponseSubscribers$PathSubscriber, EMPTY_FILE_PERMISSIONS)},
	{"file", "Ljava/nio/file/Path;", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$PathSubscriber, file)},
	{"options", "[Ljava/nio/file/OpenOption;", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$PathSubscriber, options)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$PathSubscriber, acc)},
	{"filePermissions", "[Ljava/io/FilePermission;", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$PathSubscriber, filePermissions)},
	{"isDefaultFS", "Z", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$PathSubscriber, isDefaultFS$)},
	{"result", "Ljava/util/concurrent/CompletableFuture;", "Ljava/util/concurrent/CompletableFuture<Ljava/nio/file/Path;>;", $PRIVATE | $FINAL, $field(ResponseSubscribers$PathSubscriber, result)},
	{"subscribed", "Ljava/util/concurrent/atomic/AtomicBoolean;", nullptr, $PRIVATE | $FINAL, $field(ResponseSubscribers$PathSubscriber, subscribed)},
	{"subscription", "Ljava/util/concurrent/Flow$Subscription;", nullptr, $PRIVATE | $VOLATILE, $field(ResponseSubscribers$PathSubscriber, subscription)},
	{"out", "Ljava/nio/channels/FileChannel;", nullptr, $PRIVATE | $VOLATILE, $field(ResponseSubscribers$PathSubscriber, out)},
	{}
};

$MethodInfo _ResponseSubscribers$PathSubscriber_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/file/Path;Ljava/util/List;Ljava/security/AccessControlContext;[Ljava/io/FilePermission;)V", "(Ljava/nio/file/Path;Ljava/util/List<Ljava/nio/file/OpenOption;>;Ljava/security/AccessControlContext;[Ljava/io/FilePermission;)V", $TRANSIENT, $method(static_cast<void(ResponseSubscribers$PathSubscriber::*)($Path*,$List*,$AccessControlContext*,$FilePermissionArray*)>(&ResponseSubscribers$PathSubscriber::init$))},
	{"close", "()V", nullptr, $PRIVATE, $method(static_cast<void(ResponseSubscribers$PathSubscriber::*)()>(&ResponseSubscribers$PathSubscriber::close))},
	{"create", "(Ljava/nio/file/Path;Ljava/util/List;)Ljdk/internal/net/http/ResponseSubscribers$PathSubscriber;", "(Ljava/nio/file/Path;Ljava/util/List<Ljava/nio/file/OpenOption;>;)Ljdk/internal/net/http/ResponseSubscribers$PathSubscriber;", $PUBLIC | $STATIC, $method(static_cast<ResponseSubscribers$PathSubscriber*(*)($Path*,$List*)>(&ResponseSubscribers$PathSubscriber::create))},
	{"getBody", "()Ljava/util/concurrent/CompletionStage;", "()Ljava/util/concurrent/CompletionStage<Ljava/nio/file/Path;>;", $PUBLIC},
	{"isDefaultFS", "(Ljava/nio/file/Path;)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($Path*)>(&ResponseSubscribers$PathSubscriber::isDefaultFS))},
	{"lambda$close$2", "()Ljava/lang/Void;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$Void*(ResponseSubscribers$PathSubscriber::*)()>(&ResponseSubscribers$PathSubscriber::lambda$close$2))},
	{"lambda$new$0", "(I)[Ljava/nio/file/OpenOption;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$OpenOptionArray*(*)(int32_t)>(&ResponseSubscribers$PathSubscriber::lambda$new$0))},
	{"lambda$onSubscribe$1", "()Ljava/nio/channels/FileChannel;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$FileChannel*(ResponseSubscribers$PathSubscriber::*)()>(&ResponseSubscribers$PathSubscriber::lambda$onSubscribe$1)), "java.lang.Exception"},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"pathForSecurityCheck", "(Ljava/nio/file/Path;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $method(static_cast<$String*(*)($Path*)>(&ResponseSubscribers$PathSubscriber::pathForSecurityCheck))},
	{}
};

$InnerClassInfo _ResponseSubscribers$PathSubscriber_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseSubscribers$PathSubscriber", "jdk.internal.net.http.ResponseSubscribers", "PathSubscriber", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", "jdk.internal.net.http.ResponseSubscribers", "TrustedSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseSubscribers$PathSubscriber_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseSubscribers$PathSubscriber",
	"java.lang.Object",
	"jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber",
	_ResponseSubscribers$PathSubscriber_FieldInfo_,
	_ResponseSubscribers$PathSubscriber_MethodInfo_,
	"Ljava/lang/Object;Ljdk/internal/net/http/ResponseSubscribers$TrustedSubscriber<Ljava/nio/file/Path;>;",
	nullptr,
	_ResponseSubscribers$PathSubscriber_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseSubscribers"
};

$Object* allocate$ResponseSubscribers$PathSubscriber($Class* clazz) {
	return $of($alloc(ResponseSubscribers$PathSubscriber));
}

bool ResponseSubscribers$PathSubscriber::$assertionsDisabled = false;
$FilePermissionArray* ResponseSubscribers$PathSubscriber::EMPTY_FILE_PERMISSIONS = nullptr;

$String* ResponseSubscribers$PathSubscriber::pathForSecurityCheck($Path* path) {
	$init(ResponseSubscribers$PathSubscriber);
	return $nc($($nc(path)->toFile()))->getPath();
}

ResponseSubscribers$PathSubscriber* ResponseSubscribers$PathSubscriber::create($Path* file, $List* options) {
	$init(ResponseSubscribers$PathSubscriber);
	$useLocalCurrentObjectStackCache();
	$var($SecurityManager, sm, $System::getSecurityManager());
	$var($FilePermission, filePermission, nullptr);
	if (sm != nullptr) {
		try {
			$var($String, fn, pathForSecurityCheck(file));
			$var($FilePermission, writePermission, $new($FilePermission, fn, "write"_s));
			sm->checkPermission(writePermission);
			$assign(filePermission, writePermission);
		} catch ($UnsupportedOperationException& ignored) {
		}
	}
	if (!ResponseSubscribers$PathSubscriber::$assertionsDisabled && !(filePermission == nullptr || $nc($($nc(filePermission)->getActions()))->equals("write"_s))) {
		$throwNew($AssertionError);
	}
	$var($AccessControlContext, acc, sm != nullptr ? $AccessController::getContext() : ($AccessControlContext*)nullptr);
	return $new(ResponseSubscribers$PathSubscriber, file, options, acc, $$new($FilePermissionArray, {filePermission}));
}

void ResponseSubscribers$PathSubscriber::init$($Path* file, $List* options, $AccessControlContext* acc, $FilePermissionArray* filePermissions) {
	$useLocalCurrentObjectStackCache();
	$set(this, result, $new($MinimalFuture));
	$set(this, subscribed, $new($AtomicBoolean));
	$set(this, file, file);
	$set(this, options, $fcast($OpenOptionArray, $nc($($nc(options)->stream()))->toArray(static_cast<$IntFunction*>($$new(ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0)))));
	$set(this, acc, acc);
	$set(this, filePermissions, filePermissions == nullptr || $nc(filePermissions)->get(0) == nullptr ? ResponseSubscribers$PathSubscriber::EMPTY_FILE_PERMISSIONS : filePermissions);
	this->isDefaultFS$ = isDefaultFS(file);
}

bool ResponseSubscribers$PathSubscriber::isDefaultFS($Path* file) {
	$init(ResponseSubscribers$PathSubscriber);
	try {
		$nc(file)->toFile();
		return true;
	} catch ($UnsupportedOperationException& uoe) {
		return false;
	}
	$shouldNotReachHere();
}

void ResponseSubscribers$PathSubscriber::onSubscribe($Flow$Subscription* subscription) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$Objects::requireNonNull(subscription);
	if (!$nc(this->subscribed)->compareAndSet(false, true)) {
		subscription->cancel();
		return;
	}
	$set(this, subscription, subscription);
	if (this->acc == nullptr) {
		try {
			$set(this, out, $FileChannel::open(this->file, this->options));
		} catch ($IOException& ioe) {
			$nc(this->result)->completeExceptionally(ioe);
			subscription->cancel();
			return;
		}
	} else {
		try {
			$var($PrivilegedExceptionAction, pa, static_cast<$PrivilegedExceptionAction*>($new(ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1, this)));
			$set(this, out, this->isDefaultFS$ ? $cast($FileChannel, $AccessController::doPrivileged(pa, this->acc, $fcast($PermissionArray, this->filePermissions))) : $cast($FileChannel, $AccessController::doPrivileged(pa, this->acc)));
		} catch ($PrivilegedActionException& pae) {
			$var($Throwable, t, pae->getCause() != nullptr ? pae->getCause() : static_cast<$Throwable*>(pae));
			$nc(this->result)->completeExceptionally(t);
			subscription->cancel();
			return;
		} catch ($Exception& e) {
			$nc(this->result)->completeExceptionally(e);
			subscription->cancel();
			return;
		}
	}
	subscription->request(1);
}

void ResponseSubscribers$PathSubscriber::onNext($List* items) {
	try {
		$init($Utils);
		$nc(this->out)->write($fcast($ByteBufferArray, $($nc(items)->toArray($Utils::EMPTY_BB_ARRAY))));
	} catch ($IOException& ex) {
		close();
		$nc(this->subscription)->cancel();
		$nc(this->result)->completeExceptionally(ex);
	}
	$nc(this->subscription)->request(1);
}

void ResponseSubscribers$PathSubscriber::onError($Throwable* e) {
	$nc(this->result)->completeExceptionally(e);
	close();
}

void ResponseSubscribers$PathSubscriber::onComplete() {
	close();
	$nc(this->result)->complete(this->file);
}

$CompletionStage* ResponseSubscribers$PathSubscriber::getBody() {
	return this->result;
}

void ResponseSubscribers$PathSubscriber::close() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	if (this->acc == nullptr) {
		$Utils::close($$new($CloseableArray, {static_cast<$Closeable*>(static_cast<$Channel*>(static_cast<$InterruptibleChannel*>(static_cast<$AbstractInterruptibleChannel*>(this->out))))}));
	} else {
		$var($PrivilegedAction, pa, static_cast<$PrivilegedAction*>($new(ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2, this)));
		if (this->isDefaultFS$) {
			$AccessController::doPrivileged(pa, this->acc, $fcast($PermissionArray, this->filePermissions));
		} else {
			$AccessController::doPrivileged(pa, this->acc);
		}
	}
}

void ResponseSubscribers$PathSubscriber::onNext(Object$* items) {
	this->onNext($cast($List, items));
}

$Void* ResponseSubscribers$PathSubscriber::lambda$close$2() {
	$Utils::close($$new($CloseableArray, {static_cast<$Closeable*>(static_cast<$Channel*>(static_cast<$InterruptibleChannel*>(static_cast<$AbstractInterruptibleChannel*>(this->out))))}));
	return nullptr;
}

$FileChannel* ResponseSubscribers$PathSubscriber::lambda$onSubscribe$1() {
	return $FileChannel::open(this->file, this->options);
}

$OpenOptionArray* ResponseSubscribers$PathSubscriber::lambda$new$0(int32_t x$0) {
	$init(ResponseSubscribers$PathSubscriber);
	return $new($OpenOptionArray, x$0);
}

void clinit$ResponseSubscribers$PathSubscriber($Class* class$) {
	$load($ResponseSubscribers);
	ResponseSubscribers$PathSubscriber::$assertionsDisabled = !$ResponseSubscribers::class$->desiredAssertionStatus();
	$assignStatic(ResponseSubscribers$PathSubscriber::EMPTY_FILE_PERMISSIONS, $new($FilePermissionArray, 0));
}

ResponseSubscribers$PathSubscriber::ResponseSubscribers$PathSubscriber() {
}

$Class* ResponseSubscribers$PathSubscriber::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0::classInfo$.name)) {
			return ResponseSubscribers$PathSubscriber$$Lambda$lambda$new$0::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1::classInfo$.name)) {
			return ResponseSubscribers$PathSubscriber$$Lambda$lambda$onSubscribe$1$1::load$(name, initialize);
		}
		if (name->equals(ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2::classInfo$.name)) {
			return ResponseSubscribers$PathSubscriber$$Lambda$lambda$close$2$2::load$(name, initialize);
		}
	}
	$loadClass(ResponseSubscribers$PathSubscriber, name, initialize, &_ResponseSubscribers$PathSubscriber_ClassInfo_, clinit$ResponseSubscribers$PathSubscriber, allocate$ResponseSubscribers$PathSubscriber);
	return class$;
}

$Class* ResponseSubscribers$PathSubscriber::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk