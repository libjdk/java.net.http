#ifndef _jdk_internal_net_http_SocketTube_h_
#define _jdk_internal_net_http_SocketTube_h_
//$ class jdk.internal.net.http.SocketTube
//$ extends jdk.internal.net.http.common.FlowTube

#include <jdk/internal/net/http/common/FlowTube.h>

#pragma push_macro("EOF")
#undef EOF
#pragma push_macro("IDS")
#undef IDS
#pragma push_macro("MAX_BUFFERS")
#undef MAX_BUFFERS
#pragma push_macro("NOTHING")
#undef NOTHING

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class SocketChannel;
		}
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
			class Flow$Subscriber;
			class Flow$Subscription;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
				class AtomicReference;
			}
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Consumer;
			class Supplier;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpClientImpl;
				class SocketTube$BufferSource;
				class SocketTube$InternalReadPublisher;
				class SocketTube$InternalWriteSubscriber;
				class SocketTube$SliceBufferSource;
				class SocketTube$SocketFlowEvent;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class FlowTube$TubePublisher;
					class FlowTube$TubeSubscriber;
					class Logger;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import SocketTube : public ::jdk::internal::net::http::common::FlowTube {
	$class(SocketTube, 0, ::jdk::internal::net::http::common::FlowTube)
public:
	SocketTube();
	void init$(::jdk::internal::net::http::HttpClientImpl* client, ::java::nio::channels::SocketChannel* channel, ::java::util::function::Supplier* buffersFactory);
	$String* channelDescr();
	virtual void connectFlows(::jdk::internal::net::http::common::FlowTube$TubePublisher* writePublisher, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber* readSubscriber) override;
	$String* dbgString();
	void debugState($String* when);
	virtual bool isFinished() override;
	static ::java::util::List* listOf(::java::util::List* list, Object$* item);
	virtual void onComplete() override;
	virtual void onError($Throwable* throwable) override;
	void onNext(::java::util::List* item);
	virtual void onNext(Object$* item) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* subscription) override;
	void pauseEvent(::jdk::internal::net::http::SocketTube$SocketFlowEvent* event, ::java::util::function::Consumer* errorSignaler);
	::java::util::List* readAvailable(::jdk::internal::net::http::SocketTube$BufferSource* buffersSource);
	void resumeEvent(::jdk::internal::net::http::SocketTube$SocketFlowEvent* event, ::java::util::function::Consumer* errorSignaler);
	void signalClosed();
	virtual void subscribe(::java::util::concurrent::Flow$Subscriber* s) override;
	virtual $String* toString() override;
	int64_t writeAvailable(::java::util::List* bytes);
	static bool $assertionsDisabled;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	static ::java::util::concurrent::atomic::AtomicLong* IDS;
	::jdk::internal::net::http::HttpClientImpl* client = nullptr;
	::java::nio::channels::SocketChannel* channel = nullptr;
	::jdk::internal::net::http::SocketTube$SliceBufferSource* sliceBuffersSource = nullptr;
	$Object* lock = nullptr;
	::java::util::concurrent::atomic::AtomicReference* errorRef = nullptr;
	::jdk::internal::net::http::SocketTube$InternalReadPublisher* readPublisher = nullptr;
	::jdk::internal::net::http::SocketTube$InternalWriteSubscriber* writeSubscriber = nullptr;
	int64_t id = 0;
	static const int32_t MAX_BUFFERS = 3;
	static ::java::util::List* EOF;
	static ::java::util::List* NOTHING;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("EOF")
#pragma pop_macro("IDS")
#pragma pop_macro("MAX_BUFFERS")
#pragma pop_macro("NOTHING")

#endif // _jdk_internal_net_http_SocketTube_h_