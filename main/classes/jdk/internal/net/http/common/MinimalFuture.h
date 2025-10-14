#ifndef _jdk_internal_net_http_common_MinimalFuture_h_
#define _jdk_internal_net_http_common_MinimalFuture_h_
//$ class jdk.internal.net.http.common.MinimalFuture
//$ extends java.util.concurrent.CompletableFuture

#include <java/util/concurrent/CompletableFuture.h>

#pragma push_macro("TOKENS")
#undef TOKENS

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class CompletionStage;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Cancelable;
					class MinimalFuture$ExceptionalSupplier;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $export MinimalFuture : public ::java::util::concurrent::CompletableFuture {
	$class(MinimalFuture, 0, ::java::util::concurrent::CompletableFuture)
public:
	MinimalFuture();
	using ::java::util::concurrent::CompletableFuture::complete;
	void init$();
	void init$(::jdk::internal::net::http::common::Cancelable* cancelable);
	virtual bool cancel(bool mayInterruptIfRunning) override;
	::jdk::internal::net::http::common::Cancelable* cancelable();
	static void complete(::java::util::concurrent::CompletableFuture* cf, Object$* result, $Throwable* t);
	static ::jdk::internal::net::http::common::MinimalFuture* completedFuture(Object$* value);
	static ::java::util::concurrent::CompletableFuture* failedFuture($Throwable* ex);
	static void lambda$of$0(::jdk::internal::net::http::common::MinimalFuture* cf, Object$* r, $Throwable* t);
	virtual ::jdk::internal::net::http::common::MinimalFuture* newIncompleteFuture() override;
	virtual void obtrudeException($Throwable* ex) override;
	virtual void obtrudeValue(Object$* value) override;
	static ::jdk::internal::net::http::common::MinimalFuture* of(::java::util::concurrent::CompletionStage* stage);
	static ::java::util::concurrent::CompletableFuture* supply(::jdk::internal::net::http::common::MinimalFuture$ExceptionalSupplier* supplier);
	virtual $String* toString() override;
	static ::java::util::concurrent::atomic::AtomicLong* TOKENS;
	int64_t id = 0;
	::jdk::internal::net::http::common::Cancelable* cancelable$ = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("TOKENS")

#endif // _jdk_internal_net_http_common_MinimalFuture_h_