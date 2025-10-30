#include <jdk/internal/net/http/ResponseBodyHandlers$FileDownloadBodyHandler.h>

#include <java/io/File.h>
#include <java/io/FilePermission.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/SecurityManager.h>
#include <java/lang/UnsupportedOperationException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse$ResponseInfo.h>
#include <java/nio/file/Files.h>
#include <java/nio/file/LinkOption.h>
#include <java/nio/file/Path.h>
#include <java/nio/file/Paths.h>
#include <java/security/AccessControlContext.h>
#include <java/security/AccessController.h>
#include <java/security/Permission.h>
#include <java/util/List.h>
#include <java/util/Optional.h>
#include <java/util/function/Supplier.h>
#include <java/util/regex/Matcher.h>
#include <java/util/regex/Pattern.h>
#include <jdk/internal/net/http/ResponseBodyHandlers.h>
#include <jdk/internal/net/http/ResponseSubscribers$PathSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>
#include <jcpp.h>

#undef DISPOSITION_TYPE
#undef FILENAME
#undef PROHIBITED

using $FilePermissionArray = $Array<::java::io::FilePermission>;
using $LinkOptionArray = $Array<::java::nio::file::LinkOption>;
using $File = ::java::io::File;
using $FilePermission = ::java::io::FilePermission;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $SecurityManager = ::java::lang::SecurityManager;
using $UnsupportedOperationException = ::java::lang::UnsupportedOperationException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpResponse$BodyHandler = ::java::net::http::HttpResponse$BodyHandler;
using $HttpResponse$BodySubscriber = ::java::net::http::HttpResponse$BodySubscriber;
using $HttpResponse$ResponseInfo = ::java::net::http::HttpResponse$ResponseInfo;
using $Files = ::java::nio::file::Files;
using $LinkOption = ::java::nio::file::LinkOption;
using $Path = ::java::nio::file::Path;
using $Paths = ::java::nio::file::Paths;
using $AccessControlContext = ::java::security::AccessControlContext;
using $AccessController = ::java::security::AccessController;
using $Permission = ::java::security::Permission;
using $List = ::java::util::List;
using $Optional = ::java::util::Optional;
using $Supplier = ::java::util::function::Supplier;
using $Matcher = ::java::util::regex::Matcher;
using $Pattern = ::java::util::regex::Pattern;
using $ResponseBodyHandlers = ::jdk::internal::net::http::ResponseBodyHandlers;
using $ResponseSubscribers$PathSubscriber = ::jdk::internal::net::http::ResponseSubscribers$PathSubscriber;
using $ResponseSubscribers$TrustedSubscriber = ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0 : public $Supplier {
	$class(ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$($HttpResponse$ResponseInfo* responseInfo) {
		$set(this, responseInfo, responseInfo);
	}
	virtual $Object* get() override {
		 return $of(ResponseBodyHandlers$FileDownloadBodyHandler::lambda$apply$0(responseInfo));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0>());
	}
	$HttpResponse$ResponseInfo* responseInfo = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0::fieldInfos[2] = {
	{"responseInfo", "Ljava/net/http/HttpResponse$ResponseInfo;", nullptr, $PUBLIC, $field(ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0, responseInfo)},
	{}
};
$MethodInfo ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpResponse$ResponseInfo;)V", nullptr, $PUBLIC, $method(static_cast<void(ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0::*)($HttpResponse$ResponseInfo*)>(&ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0::load$($String* name, bool initialize) {
	$loadClass(ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0::class$ = nullptr;

$FieldInfo _ResponseBodyHandlers$FileDownloadBodyHandler_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(ResponseBodyHandlers$FileDownloadBodyHandler, $assertionsDisabled)},
	{"directory", "Ljava/nio/file/Path;", nullptr, $PRIVATE | $FINAL, $field(ResponseBodyHandlers$FileDownloadBodyHandler, directory)},
	{"openOptions", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/file/OpenOption;>;", $PRIVATE | $FINAL, $field(ResponseBodyHandlers$FileDownloadBodyHandler, openOptions)},
	{"acc", "Ljava/security/AccessControlContext;", nullptr, $PRIVATE | $FINAL, $field(ResponseBodyHandlers$FileDownloadBodyHandler, acc)},
	{"filePermissions", "[Ljava/io/FilePermission;", nullptr, $PRIVATE | $FINAL, $field(ResponseBodyHandlers$FileDownloadBodyHandler, filePermissions)},
	{"DISPOSITION_TYPE", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(ResponseBodyHandlers$FileDownloadBodyHandler, DISPOSITION_TYPE)},
	{"FILENAME", "Ljava/util/regex/Pattern;", nullptr, $STATIC | $FINAL, $staticField(ResponseBodyHandlers$FileDownloadBodyHandler, FILENAME)},
	{"PROHIBITED", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/String;>;", $STATIC | $FINAL, $staticField(ResponseBodyHandlers$FileDownloadBodyHandler, PROHIBITED)},
	{}
};

$MethodInfo _ResponseBodyHandlers$FileDownloadBodyHandler_MethodInfo_[] = {
	{"<init>", "(Ljava/nio/file/Path;Ljava/util/List;Ljava/security/AccessControlContext;[Ljava/io/FilePermission;)V", "(Ljava/nio/file/Path;Ljava/util/List<Ljava/nio/file/OpenOption;>;Ljava/security/AccessControlContext;[Ljava/io/FilePermission;)V", $PRIVATE | $TRANSIENT, $method(static_cast<void(ResponseBodyHandlers$FileDownloadBodyHandler::*)($Path*,$List*,$AccessControlContext*,$FilePermissionArray*)>(&ResponseBodyHandlers$FileDownloadBodyHandler::init$))},
	{"apply", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber;", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/net/http/HttpResponse$BodySubscriber<Ljava/nio/file/Path;>;", $PUBLIC},
	{"create", "(Ljava/nio/file/Path;Ljava/util/List;)Ljdk/internal/net/http/ResponseBodyHandlers$FileDownloadBodyHandler;", "(Ljava/nio/file/Path;Ljava/util/List<Ljava/nio/file/OpenOption;>;)Ljdk/internal/net/http/ResponseBodyHandlers$FileDownloadBodyHandler;", $PUBLIC | $STATIC, $method(static_cast<ResponseBodyHandlers$FileDownloadBodyHandler*(*)($Path*,$List*)>(&ResponseBodyHandlers$FileDownloadBodyHandler::create))},
	{"lambda$apply$0", "(Ljava/net/http/HttpResponse$ResponseInfo;)Ljava/io/UncheckedIOException;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$UncheckedIOException*(*)($HttpResponse$ResponseInfo*)>(&ResponseBodyHandlers$FileDownloadBodyHandler::lambda$apply$0))},
	{"unchecked", "(Ljava/net/http/HttpResponse$ResponseInfo;Ljava/lang/String;)Ljava/io/UncheckedIOException;", nullptr, $STATIC | $FINAL, $method(static_cast<$UncheckedIOException*(*)($HttpResponse$ResponseInfo*,$String*)>(&ResponseBodyHandlers$FileDownloadBodyHandler::unchecked))},
	{}
};

$InnerClassInfo _ResponseBodyHandlers$FileDownloadBodyHandler_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseBodyHandlers$FileDownloadBodyHandler", "jdk.internal.net.http.ResponseBodyHandlers", "FileDownloadBodyHandler", $PUBLIC | $STATIC},
	{"java.net.http.HttpResponse$BodyHandler", "java.net.http.HttpResponse", "BodyHandler", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ResponseBodyHandlers$FileDownloadBodyHandler_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.ResponseBodyHandlers$FileDownloadBodyHandler",
	"java.lang.Object",
	"java.net.http.HttpResponse$BodyHandler",
	_ResponseBodyHandlers$FileDownloadBodyHandler_FieldInfo_,
	_ResponseBodyHandlers$FileDownloadBodyHandler_MethodInfo_,
	"Ljava/lang/Object;Ljava/net/http/HttpResponse$BodyHandler<Ljava/nio/file/Path;>;",
	nullptr,
	_ResponseBodyHandlers$FileDownloadBodyHandler_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseBodyHandlers"
};

$Object* allocate$ResponseBodyHandlers$FileDownloadBodyHandler($Class* clazz) {
	return $of($alloc(ResponseBodyHandlers$FileDownloadBodyHandler));
}

bool ResponseBodyHandlers$FileDownloadBodyHandler::$assertionsDisabled = false;
$String* ResponseBodyHandlers$FileDownloadBodyHandler::DISPOSITION_TYPE = nullptr;
$Pattern* ResponseBodyHandlers$FileDownloadBodyHandler::FILENAME = nullptr;
$List* ResponseBodyHandlers$FileDownloadBodyHandler::PROHIBITED = nullptr;

ResponseBodyHandlers$FileDownloadBodyHandler* ResponseBodyHandlers$FileDownloadBodyHandler::create($Path* directory, $List* openOptions) {
	$init(ResponseBodyHandlers$FileDownloadBodyHandler);
	$useLocalCurrentObjectStackCache();
	$var($String, fn, nullptr);
	try {
		$assign(fn, $ResponseBodyHandlers::pathForSecurityCheck(directory));
	} catch ($UnsupportedOperationException& uoe) {
		$throwNew($IllegalArgumentException, $$str({"invalid path: "_s, directory}), uoe);
	}
	$var($FilePermissionArray, filePermissions, nullptr);
	$var($SecurityManager, sm, $System::getSecurityManager());
	if (sm != nullptr) {
		$var($FilePermission, writePermission, $new($FilePermission, fn, "write"_s));
		$init($File);
		$var($String, writePathPerm, $str({fn, $$str($File::separatorChar), "*"_s}));
		$var($FilePermission, writeInDirPermission, $new($FilePermission, writePathPerm, "write"_s));
		sm->checkPermission(writeInDirPermission);
		$var($FilePermission, readPermission, $new($FilePermission, fn, "read"_s));
		sm->checkPermission(readPermission);
		$assign(filePermissions, $new($FilePermissionArray, {
			writePermission,
			writeInDirPermission
		}));
	}
	if ($Files::notExists(directory, $$new($LinkOptionArray, 0))) {
		$throwNew($IllegalArgumentException, $$str({"non-existent directory: "_s, directory}));
	}
	if (!$Files::isDirectory(directory, $$new($LinkOptionArray, 0))) {
		$throwNew($IllegalArgumentException, $$str({"not a directory: "_s, directory}));
	}
	if (!$Files::isWritable(directory)) {
		$throwNew($IllegalArgumentException, $$str({"non-writable directory: "_s, directory}));
	}
	bool var$0 = !ResponseBodyHandlers$FileDownloadBodyHandler::$assertionsDisabled;
	if (var$0) {
		bool var$1 = filePermissions == nullptr;
		if (!var$1) {
			bool var$2 = $nc($($nc($nc(filePermissions)->get(0))->getActions()))->equals("write"_s);
			var$1 = (var$2 && $nc($($nc(filePermissions->get(1))->getActions()))->equals("write"_s));
		}
		var$0 = !var$1;
	}
	if (var$0) {
		$throwNew($AssertionError);
	}
	$var($AccessControlContext, acc, sm != nullptr ? $AccessController::getContext() : ($AccessControlContext*)nullptr);
	return $new(ResponseBodyHandlers$FileDownloadBodyHandler, directory, openOptions, acc, filePermissions);
}

void ResponseBodyHandlers$FileDownloadBodyHandler::init$($Path* directory, $List* openOptions, $AccessControlContext* acc, $FilePermissionArray* filePermissions) {
	$set(this, directory, directory);
	$set(this, openOptions, openOptions);
	$set(this, acc, acc);
	$set(this, filePermissions, filePermissions);
}

$UncheckedIOException* ResponseBodyHandlers$FileDownloadBodyHandler::unchecked($HttpResponse$ResponseInfo* rinfo, $String* msg) {
	$init(ResponseBodyHandlers$FileDownloadBodyHandler);
	$useLocalCurrentObjectStackCache();
	$var($String, s, $String::format("%s in response [%d, %s]"_s, $$new($ObjectArray, {
		$of(msg),
		$($of($Integer::valueOf($nc(rinfo)->statusCode()))),
		$($of($nc(rinfo)->headers()))
	})));
	return $new($UncheckedIOException, $$new($IOException, s));
}

$HttpResponse$BodySubscriber* ResponseBodyHandlers$FileDownloadBodyHandler::apply($HttpResponse$ResponseInfo* responseInfo) {
	$useLocalCurrentObjectStackCache();
	$var($String, dispoHeader, $cast($String, $nc($($nc($($nc(responseInfo)->headers()))->firstValue("Content-Disposition"_s)))->orElseThrow(static_cast<$Supplier*>($$new(ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0, responseInfo)))));
	if (!$nc(dispoHeader)->regionMatches(true, 0, ResponseBodyHandlers$FileDownloadBodyHandler::DISPOSITION_TYPE, 0, $nc(ResponseBodyHandlers$FileDownloadBodyHandler::DISPOSITION_TYPE)->length())) {
		$throw($(unchecked(responseInfo, "Unknown Content-Disposition type"_s)));
	}
	$var($Matcher, matcher, $nc(ResponseBodyHandlers$FileDownloadBodyHandler::FILENAME)->matcher(dispoHeader));
	if (!$nc(matcher)->find()) {
		$throw($(unchecked(responseInfo, "Bad Content-Disposition filename parameter"_s)));
	}
	int32_t n = $nc(matcher)->end();
	int32_t semi = $($nc(dispoHeader)->substring(n))->indexOf(";"_s);
	$var($String, filenameParam, nullptr);
	if (semi < 0) {
		$assign(filenameParam, dispoHeader->substring(n));
	} else {
		$assign(filenameParam, dispoHeader->substring(n, n + semi));
	}
	int32_t x = $nc(filenameParam)->lastIndexOf("/"_s);
	if (x != -1) {
		$assign(filenameParam, filenameParam->substring(x + 1));
	}
	x = filenameParam->lastIndexOf("\\"_s);
	if (x != -1) {
		$assign(filenameParam, filenameParam->substring(x + 1));
	}
	$assign(filenameParam, filenameParam->trim());
	if (filenameParam->startsWith("\""_s)) {
		bool var$0 = !filenameParam->endsWith("\""_s);
		if (var$0 || filenameParam->length() == 1) {
			$throw($(unchecked(responseInfo, "Badly quoted Content-Disposition filename parameter"_s)));
		}
		$assign(filenameParam, filenameParam->substring(1, filenameParam->length() - 1));
	} else if (filenameParam->contains(" "_s)) {
		$throw($(unchecked(responseInfo, "unquoted space in Content-Disposition filename parameter"_s)));
	}
	if ($nc(ResponseBodyHandlers$FileDownloadBodyHandler::PROHIBITED)->contains(filenameParam)) {
		$throw($(unchecked(responseInfo, $$str({"Prohibited Content-Disposition filename parameter:"_s, filenameParam}))));
	}
	$var($Path, file, $Paths::get($($nc(this->directory)->toString()), $$new($StringArray, {filenameParam})));
	if (!$nc(file)->startsWith(this->directory)) {
		$throw($(unchecked(responseInfo, $$str({"Resulting file, "_s, $(file->toString()), ", outside of given directory"_s}))));
	}
	return $new($ResponseSubscribers$PathSubscriber, file, this->openOptions, this->acc, this->filePermissions);
}

$UncheckedIOException* ResponseBodyHandlers$FileDownloadBodyHandler::lambda$apply$0($HttpResponse$ResponseInfo* responseInfo) {
	$init(ResponseBodyHandlers$FileDownloadBodyHandler);
	return unchecked(responseInfo, "No Content-Disposition header"_s);
}

void clinit$ResponseBodyHandlers$FileDownloadBodyHandler($Class* class$) {
	$assignStatic(ResponseBodyHandlers$FileDownloadBodyHandler::DISPOSITION_TYPE, "attachment;"_s);
	$load($ResponseBodyHandlers);
	ResponseBodyHandlers$FileDownloadBodyHandler::$assertionsDisabled = !$ResponseBodyHandlers::class$->desiredAssertionStatus();
	$assignStatic(ResponseBodyHandlers$FileDownloadBodyHandler::FILENAME, $Pattern::compile("filename\\s*="_s, 2));
	$assignStatic(ResponseBodyHandlers$FileDownloadBodyHandler::PROHIBITED, $List::of("."_s, ".."_s, ""_s, "~"_s, "|"_s));
}

ResponseBodyHandlers$FileDownloadBodyHandler::ResponseBodyHandlers$FileDownloadBodyHandler() {
}

$Class* ResponseBodyHandlers$FileDownloadBodyHandler::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0::classInfo$.name)) {
			return ResponseBodyHandlers$FileDownloadBodyHandler$$Lambda$lambda$apply$0::load$(name, initialize);
		}
	}
	$loadClass(ResponseBodyHandlers$FileDownloadBodyHandler, name, initialize, &_ResponseBodyHandlers$FileDownloadBodyHandler_ClassInfo_, clinit$ResponseBodyHandlers$FileDownloadBodyHandler, allocate$ResponseBodyHandlers$FileDownloadBodyHandler);
	return class$;
}

$Class* ResponseBodyHandlers$FileDownloadBodyHandler::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk