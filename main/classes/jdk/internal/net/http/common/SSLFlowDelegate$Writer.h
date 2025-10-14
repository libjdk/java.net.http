#ifndef _jdk_internal_net_http_common_SSLFlowDelegate$Writer_h_
#define _jdk_internal_net_http_common_SSLFlowDelegate$Writer_h_
//$ class jdk.internal.net.http.common.SSLFlowDelegate$Writer
//$ extends jdk.internal.net.http.common.SubscriberWrapper

#include <java/lang/Array.h>
#include <jdk/internal/net/http/common/SubscriberWrapper.h>

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

class $export SSLFlowDelegate$Writer : public ::jdk::internal::net::http::common::SubscriberWrapper {
	$class(SSLFlowDelegate$Writer, 0, ::jdk::internal::net::http::common::SubscriberWrapper)
public:
	SSLFlowDelegate$Writer();
	void init$(::jdk::internal::net::http::common::SSLFlowDelegate* this$0);
	virtual bool closing() override;
	virtual $String* dbgString() override;
	bool hsTriggered();
	virtual void incoming(::java::util::List* buffers, bool complete) override;
	bool isCompleting();
	bool needWrap();
	using ::jdk::internal::net::http::common::SubscriberWrapper::onSubscribe;
	virtual void onSubscribe() override;
	void processData();
	virtual void schedule();
	void sendResultBytes(::jdk::internal::net::http::common::SSLFlowDelegate$EngineResult* result);
	virtual void stop();
	virtual $String* toString() override;
	virtual void triggerWrite();
	using ::jdk::internal::net::http::common::SubscriberWrapper::upstreamWindowUpdate;
	virtual int64_t upstreamWindowUpdate(int64_t currentWindow, int64_t downstreamQsize) override;
	virtual ::jdk::internal::net::http::common::SSLFlowDelegate$EngineResult* wrapBuffers($Array<::java::nio::ByteBuffer>* src);
	::jdk::internal::net::http::common::SSLFlowDelegate* this$0 = nullptr;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::SequentialScheduler* scheduler = nullptr;
	::java::util::List* writeList = nullptr;
	::jdk::internal::net::http::common::Logger* debugw = nullptr;
	$volatile(bool) completing = false;
	bool completed = false;
	$volatile(::java::nio::ByteBuffer*) writeBuffer = nullptr;
	$volatile(::javax::net::ssl::SSLEngineResult$Status*) lastWrappedStatus = nullptr;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_SSLFlowDelegate$Writer_h_