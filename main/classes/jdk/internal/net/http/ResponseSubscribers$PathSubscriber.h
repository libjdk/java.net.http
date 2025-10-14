#ifndef _jdk_internal_net_http_ResponseSubscribers$PathSubscriber_h_
#define _jdk_internal_net_http_ResponseSubscribers$PathSubscriber_h_
//$ class jdk.internal.net.http.ResponseSubscribers$PathSubscriber
//$ extends jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber

#include <java/lang/Array.h>
#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>

#pragma push_macro("EMPTY_FILE_PERMISSIONS")
#undef EMPTY_FILE_PERMISSIONS

namespace java {
	namespace io {
		class FilePermission;
	}
}
namespace java {
	namespace lang {
		class Throwable;
		class Void;
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class FileChannel;
		}
	}
}
namespace java {
	namespace nio {
		namespace file {
			class OpenOption;
			class Path;
		}
	}
}
namespace java {
	namespace security {
		class AccessControlContext;
	}
}
namespace java {
	namespace util {
		class List;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletableFuture;
			class CompletionStage;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicBoolean;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export ResponseSubscribers$PathSubscriber : public ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber {
	$class(ResponseSubscribers$PathSubscriber, 0, ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber)
public:
	ResponseSubscribers$PathSubscriber();
	void init$(::java::nio::file::Path* file, ::java::util::List* options, ::java::security::AccessControlContext* acc, $Array<::java::io::FilePermission>* filePermissions);
	void close();
	static ::jdk::internal::net::http::ResponseSubscribers$PathSubscriber* create(::java::nio::file::Path* file, ::java::util::List* options);
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	static bool isDefaultFS(::java::nio::file::Path* file);
	::java::lang::Void* lambda$close$2();
	static $Array<::java::nio::file::OpenOption>* lambda$new$0(int32_t x$0);
	::java::nio::channels::FileChannel* lambda$onSubscribe$1();
	virtual void onComplete() override;
	virtual void onError($Throwable* e) override;
	virtual void onNext(::java::util::List* items);
	virtual void onNext(Object$* items) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	static $String* pathForSecurityCheck(::java::nio::file::Path* path);
	static bool $assertionsDisabled;
	static $Array<::java::io::FilePermission>* EMPTY_FILE_PERMISSIONS;
	::java::nio::file::Path* file = nullptr;
	$Array<::java::nio::file::OpenOption>* options = nullptr;
	::java::security::AccessControlContext* acc = nullptr;
	$Array<::java::io::FilePermission>* filePermissions = nullptr;
	bool isDefaultFS$ = false;
	::java::util::concurrent::CompletableFuture* result = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* subscribed = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscription*) subscription = nullptr;
	$volatile(::java::nio::channels::FileChannel*) out = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("EMPTY_FILE_PERMISSIONS")

#endif // _jdk_internal_net_http_ResponseSubscribers$PathSubscriber_h_