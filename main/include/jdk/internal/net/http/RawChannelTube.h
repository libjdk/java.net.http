#ifndef _jdk_internal_net_http_RawChannelTube_h_
#define _jdk_internal_net_http_RawChannelTube_h_
//$ class jdk.internal.net.http.RawChannelTube
//$ extends jdk.internal.net.http.websocket.RawChannel

#include <java/lang/Array.h>
#include <jdk/internal/net/http/websocket/RawChannel.h>

namespace java {
	namespace lang {
		namespace ref {
			class Cleaner;
		}
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
				class AtomicBoolean;
			}
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Supplier;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HttpConnection;
				class RawChannelTube$ReadSubscriber;
				class RawChannelTube$WritePublisher;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class FlowTube;
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
				namespace websocket {
					class RawChannel$RawEvent;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import RawChannelTube : public ::jdk::internal::net::http::websocket::RawChannel {
	$class(RawChannelTube, 0, ::jdk::internal::net::http::websocket::RawChannel)
public:
	RawChannelTube();
	void init$(::jdk::internal::net::http::HttpConnection* connection, ::java::util::function::Supplier* initial);
	virtual void close() override;
	void connectFlows();
	static ::java::util::List* copy($Array<::java::nio::ByteBuffer>* src, int32_t offset, int32_t len);
	virtual ::java::nio::ByteBuffer* initialByteBuffer() override;
	virtual ::java::nio::ByteBuffer* read() override;
	virtual void registerEvent(::jdk::internal::net::http::websocket::RawChannel$RawEvent* event) override;
	virtual void shutdownInput() override;
	virtual void shutdownOutput() override;
	virtual int64_t write($Array<::java::nio::ByteBuffer>* srcs, int32_t offset, int32_t length) override;
	static bool $assertionsDisabled;
	::jdk::internal::net::http::HttpConnection* connection = nullptr;
	::jdk::internal::net::http::common::FlowTube* tube = nullptr;
	::jdk::internal::net::http::RawChannelTube$WritePublisher* writePublisher = nullptr;
	::jdk::internal::net::http::RawChannelTube$ReadSubscriber* readSubscriber = nullptr;
	::java::util::function::Supplier* initial = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* inited = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* outputClosed = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* inputClosed = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* closed = nullptr;
	$String* dbgTag = nullptr;
	::jdk::internal::net::http::common::Logger* debug = nullptr;
	static ::java::lang::ref::Cleaner* cleaner;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RawChannelTube_h_