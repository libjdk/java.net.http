#include <jdk/internal/net/http/ResponseBodyHandlers$PathBodyHandler.h>

#include <java/io/FilePermission.h>
#include <java/lang/AssertionError.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse$ResponseInfo.h>
#include <java/nio/file/Path.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/util/List.h>
#include <jdk/internal/net/http/ResponseBodyHandlers.h>
#include <jdk/internal/net/http/ResponseSubscribers$PathSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>
#include <jcpp.h>

using $FilePermissionArray = $Array<::java::io::FilePermission>;
using $FilePermission = ::java::io::FilePermission;
using $AssertionError = ::java::lang::AssertionError;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $HttpResponse$ResponseInfo = ::java::net::http::HttpResponse$ResponseInfo;
using $Path = ::java::nio::file::Path;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $List = ::java::util::List;
using $ResponseBodyHandlers = ::jdk::internal::net::http::ResponseBodyHandlers;
using $ResponseSubscribers$PathSubscriber = ::jdk::internal::net::http::ResponseSubscribers$PathSubscriber;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ResponseBodyHandlers$PathBodyHandler_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseBodyHandlers$PathBodyHandler, $assertionsDisabled)},
	{"file", "Ljava/nio/file/Path;", nullptr, $PRIVATE | $FINAL, $field(ResponseBodyHandlers$PathBodyHandler, file)},
	{"openOptions", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/file/OpenOption;>;", $PRIVATE | $FINAL, $field(ResponseBodyHandlers$PathBodyHandler, openOptions)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(ResponseBodyHandlers$PathBodyHandler, acc)},
	{"filePermission", "Ljava/io/FilePermission;", nullptr, $PRIVATE | $FINAL, $field(ResponseBodyHandlers$PathBodyHandler, filePermission)},
	{}
};

$MethodInfo _ResponseBodyHandlers$PathBodyHandler_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/file/Path;Ljava/util/List;Ljava/security/AccessControlContext;Ljava/io/FilePermission;)V", "(Ljava/nio/file/Path;Ljava/util/List<Ljava/nio/file/OpenOption;>;Ljava/security/AccessControlContext;Ljava/io/FilePermission;)V", $PRIVATE, $method(static_cast<void(ResponseBodyHandlers$PathBodyHandler::*)($Path*,$List*,$AccessControlContext*,$FilePermission*)>(&ResponseBodyHandlers$PathBodyHandler::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber<Ljava/nio/file/Path;>;", $PUBLIC},
	{"create", "(Ljava/nio/file/Path;Ljava/util/List;)Ljdk/internal/net/http/ResponseBodyHandlers$PathBodyHandler;", "(Ljava/nio/file/Path;Ljava/util/List<Ljava/nio/file/OpenOption;>;)Ljdk/internal/net/http/ResponseBodyHandlers$PathBodyHandler;", $PUBLIC | $STATIC, $method(static_cast<ResponseBodyHandlers$PathBodyHandler*(*)($Path*,$List*)>(&ResponseBodyHandlers$PathBodyHandler::create))},
	{}
};

$InnerClassInfo _ResponseBodyHandlers$PathBodyHandler_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseBodyHandlers$PathBodyHandler", "jdk.internal.net.http.ResponseBodyHandlers", "PathBodyHandler", $PUBLIC | $STATIC},
	{"java.net.http.HttpResponse$BodyHandler", "java.net.http.HttpResponse", "BodyHandler", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseBodyHandlers$PathBodyHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseBodyHandlers$PathBodyHandler",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	_ResponseBodyHandlers$PathBodyHandler_FieldInfo_,
	_ResponseBodyHandlers$PathBodyHandler_MethodInfo_,
	"Ljava/lang/Object;Ljava/net/http/HttpResponse$BodyHandler<Ljava/nio/file/Path;>;",
	nullptr,
	_ResponseBodyHandlers$PathBodyHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseBodyHandlers"
};

$Object* allocate$ResponseBodyHandlers$PathBodyHandler($Class* clazz) {
	return $of($alloc(ResponseBodyHandlers$PathBodyHandler));
}

bool ResponseBodyHandlers$PathBodyHandler::$assertionsDisabled = false;

ResponseBodyHandlers$PathBodyHandler* ResponseBodyHandlers$PathBodyHandler::create($Path* file, $List* openOptions) {
	$init(ResponseBodyHandlers$PathBodyHandler);
	$useLocalCurrentObjectStackCache();
	$var($FilePermission, filePermission, nullptr);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		try {
			$var($String, fn, $ResponseBodyHandlers::pathForSecurityCheck(file));
			$var($FilePermission, writePermission, $new($FilePermission, fn, "write"_s));
			sm->checkPermission(writePermission);
			$assign(filePermission, writePermission);
		} catch ($UnsupportedOperationException& ignored) {
		}
	}
	if (!ResponseBodyHandlers$PathBodyHandler::$assertionsDisabled && !(filePermission == nullptr || $nc($($nc(filePermission)->getActions()))->equals("write"_s))) {
		$throwNew($AssertionError);
	}
	$var($AccessControlContext, acc, sm != nullptr ? $AccessController::getContext() : ($AccessControlContext*)nullptr);
	return $new(ResponseBodyHandlers$PathBodyHandler, file, openOptions, acc, filePermission);
}

void ResponseBodyHandlers$PathBodyHandler::init$($Path* file, $List* openOptions, $AccessControlContext* acc, $FilePermission* filePermission) {
	$set(this, file, file);
	$set(this, openOptions, openOptions);
	$set(this, acc, acc);
	$set(this, filePermission, filePermission);
}

$HttpResponse$BodySubscriber* ResponseBodyHandlers$PathBodyHandler::apply($HttpResponse$ResponseInfo* responseInfo) {
	return $new($ResponseSubscribers$PathSubscriber, this->file, this->openOptions, this->acc, $$new($FilePermissionArray, {this->filePermission}));
}

void clinit$ResponseBodyHandlers$PathBodyHandler($Class* class$) {
	$load($ResponseBodyHandlers);
	ResponseBodyHandlers$PathBodyHandler::$assertionsDisabled = !$ResponseBodyHandlers::class$->desiredAssertionStatus();
}

ResponseBodyHandlers$PathBodyHandler::ResponseBodyHandlers$PathBodyHandler() {
}

$Class* ResponseBodyHandlers$PathBodyHandler::load$($String* name, bool initialize) {
	$loadClass(ResponseBodyHandlers$PathBodyHandler, name, initialize, &_ResponseBodyHandlers$PathBodyHandler_ClassInfo_, clinit$ResponseBodyHandlers$PathBodyHandler, allocate$ResponseBodyHandlers$PathBodyHandler);
	return class$;
}

$Class* ResponseBodyHandlers$PathBodyHandler::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk