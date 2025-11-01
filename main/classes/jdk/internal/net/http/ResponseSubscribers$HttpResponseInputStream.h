#ifndef _jdk_internal_net_http_ResponseSubscribers$HttpResponseInputStream_h_
#define _jdk_internal_net_http_ResponseSubscribers$HttpResponseInputStream_h_
//$ class jdk.internal.net.http.ResponseSubscribers$HttpResponseInputStream
//$ extends java.io.InputStream
//$ implements jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber

#include <java/io/InputStream.h>
#include <java/lang/Array.h>
#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>

#pragma push_macro("LAST_BUFFER")
#undef LAST_BUFFER
#pragma push_macro("LAST_LIST")
#undef LAST_LIST
#pragma push_macro("MAX_BUFFERS_IN_QUEUE")
#undef MAX_BUFFERS_IN_QUEUE

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
		class Iterator;
		class List;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class BlockingQueue;
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
				namespace common {
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

class $export ResponseSubscribers$HttpResponseInputStream : public ::java::io::InputStream, public ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber {
	$class(ResponseSubscribers$HttpResponseInputStream, 0, ::java::io::InputStream, ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber)
public:
	ResponseSubscribers$HttpResponseInputStream();
	virtual $Object* clone() override;
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	void init$();
	void init$(int32_t maxBuffers);
	virtual int32_t available() override;
	virtual void close() override;
	::java::nio::ByteBuffer* current();
	virtual ::java::util::concurrent::CompletionStage* getBody() override;
	virtual void onComplete() override;
	virtual void onError($Throwable* thrwbl) override;
	virtual void onNext(::java::util::List* t);
	virtual void onNext(Object$* t) override;
	virtual void onSubscribe(::java::util::concurrent::Flow$Subscription* s) override;
	using ::java::io::InputStream::read;
	virtual int32_t read($bytes* bytes, int32_t off, int32_t len) override;
	virtual int32_t read() override;
	virtual $String* toString() override;
	static bool $assertionsDisabled;
	static const int32_t MAX_BUFFERS_IN_QUEUE = 1;
	static ::java::nio::ByteBuffer* LAST_BUFFER;
	static ::java::util::List* LAST_LIST;
	static ::jdk::internal::net::http::common::Logger* debug;
	::java::util::concurrent::BlockingQueue* buffers = nullptr;
	$volatile(::java::util::concurrent::Flow$Subscription*) subscription = nullptr;
	$volatile(bool) closed = false;
	$volatile($Throwable*) failed = nullptr;
	$volatile(::java::util::Iterator*) currentListItr = nullptr;
	$volatile(::java::nio::ByteBuffer*) currentBuffer = nullptr;
	::java::util::concurrent::atomic::AtomicBoolean* subscribed = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("LAST_BUFFER")
#pragma pop_macro("LAST_LIST")
#pragma pop_macro("MAX_BUFFERS_IN_QUEUE")

#endif // _jdk_internal_net_http_ResponseSubscribers$HttpResponseInputStream_h_