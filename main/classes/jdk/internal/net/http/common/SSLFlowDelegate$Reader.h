#ifndef _jdk_internal_net_http_common_SSLFlowDelegate$Reader_h_
#define _jdk_internal_net_http_common_SSLFlowDelegate$Reader_h_
//$ class jdk.internal.net.http.common.SSLFlowDelegate$Reader
//$ extends jdk.internal.net.http.common.SubscriberWrapper

#include <jdk/internal/net/http/common/SubscriberWrapper.h>

#pragma push_macro("TARGET_BUFSIZE")
#undef TARGET_BUFSIZE

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
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
			namespace atomic {
				class AtomicInteger;
			}
		}
	}
}
namespace javax {
	namespace net {
		namespace ssl {
			class SSLEngineResult$Status;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
					class SSLFlowDelegate;
					class SSLFlowDelegate$EngineResult;
					class SequentialScheduler;
					class SubscriberWrapper$SchedulingAction;
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

class $export SSLFlowDelegate$Reader : public ::jdk::internal::net::http::common::SubscriberWrapper {
	$class(SSLFlowDelegate$Reader, 0, ::jdk::internal::net::http::common::SubscriberWrapper)
public:
	SSLFlowDelegate$Reader();
	void init$(::jdk::internal::net::http::common::SSLFlowDelegate* this$0);
	void addToReadBuf(::java::util::List* buffers, bool complete);
	virtual $String* dbgString() override;
	virtual ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction* enterScheduling() override;
	virtual bool errorCommon($Throwable* throwable) override;
	virtual void incoming(::java::util::List* buffers, bool complete) override;
	bool needsMoreData();
	void processData();
	void reallocReadBuf();
	void requestMoreDataIfNeeded();
	void schedule();
	void stop();
	virtual bool supportsRecycling() override;
	virtual $String* toString() override;
	::jdk::internal::net::http::common::SSLFlowDelegate$EngineResult* unwrapBuffer(::java::nio::ByteBuffer* src);
	using ::jdk::internal::net::http::common::SubscriberWrapper::upstreamWindowUpdate;
	virtual int64_t upstreamWindowUpdate(int64_t currentWindow, int64_t downstreamQsize) override;
	::jdk::internal::net::http::common::SSLFlowDelegate* this$0 = nullptr;
	static bool $assertionsDisabled;
	static const int32_t TARGET_BUFSIZE = 16384; // 16 * 1024
	::jdk::internal::net::http::common::SequentialScheduler* scheduler = nullptr;
	$volatile(::java::nio::ByteBuffer*) readBuf = nullptr;
	$volatile(bool) completing = false;
	$Object* readBufferLock = nullptr;
	::jdk::internal::net::http::common::Logger* debugr = nullptr;
	::java::util::concurrent::atomic::AtomicInteger* count = nullptr;
	$volatile(int32_t) minBytesRequired = 0;
	$volatile(::javax::net::ssl::SSLEngineResult$Status*) lastUnwrapStatus = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("TARGET_BUFSIZE")

#endif // _jdk_internal_net_http_common_SSLFlowDelegate$Reader_h_