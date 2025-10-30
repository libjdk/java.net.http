#include <jdk/internal/net/http/ResponseBodyHandlers.h>

#include <java/io/File.h>
#include <java/nio/file/Path.h>
#include <jcpp.h>

using $File = ::java::io::File;
using $ClassInfo = ::java::lang::ClassInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Path = ::java::nio::file::Path;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$MethodInfo _ResponseBodyHandlers_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(ResponseBodyHandlers::*)()>(&ResponseBodyHandlers::init$))},
	{"pathForSecurityCheck", "(Ljava/nio/file/Path;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $method(static_cast<$String*(*)($Path*)>(&ResponseBodyHandlers::pathForSecurityCheck))},
	{}
};

$InnerClassInfo _ResponseBodyHandlers_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ResponseBodyHandlers$FileDownloadBodyHandler", "jdk.internal.net.http.ResponseBodyHandlers", "FileDownloadBodyHandler", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseBodyHandlers$PushPromisesHandlerWithMap", "jdk.internal.net.http.ResponseBodyHandlers", "PushPromisesHandlerWithMap", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.ResponseBodyHandlers$PathBodyHandler", "jdk.internal.net.http.ResponseBodyHandlers", "PathBodyHandler", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _ResponseBodyHandlers_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.ResponseBodyHandlers",
	"java.lang.Object",
	nullptr,
	nullptr,
	_ResponseBodyHandlers_MethodInfo_,
	nullptr,
	nullptr,
	_ResponseBodyHandlers_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ResponseBodyHandlers$FileDownloadBodyHandler,jdk.internal.net.http.ResponseBodyHandlers$PushPromisesHandlerWithMap,jdk.internal.net.http.ResponseBodyHandlers$PathBodyHandler"
};

$Object* allocate$ResponseBodyHandlers($Class* clazz) {
	return $of($alloc(ResponseBodyHandlers));
}

void ResponseBodyHandlers::init$() {
}

$String* ResponseBodyHandlers::pathForSecurityCheck($Path* path) {
	return $nc($($nc(path)->toFile()))->getPath();
}

ResponseBodyHandlers::ResponseBodyHandlers() {
}

$Class* ResponseBodyHandlers::load$($String* name, bool initialize) {
	$loadClass(ResponseBodyHandlers, name, initialize, &_ResponseBodyHandlers_ClassInfo_, allocate$ResponseBodyHandlers);
	return class$;
}

$Class* ResponseBodyHandlers::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk