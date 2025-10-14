#ifndef _jdk_internal_net_http_RequestPublishers$IterablePublisher$ByteBufferIterator_h_
#define _jdk_internal_net_http_RequestPublishers$IterablePublisher$ByteBufferIterator_h_
//$ class jdk.internal.net.http.RequestPublishers$IterablePublisher$ByteBufferIterator
//$ extends java.util.Iterator

#include <java/util/Iterator.h>

namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class ConcurrentLinkedQueue;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class RequestPublishers$IterablePublisher;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export RequestPublishers$IterablePublisher$ByteBufferIterator : public ::java::util::Iterator {
	$class(RequestPublishers$IterablePublisher$ByteBufferIterator, $NO_CLASS_INIT, ::java::util::Iterator)
public:
	RequestPublishers$IterablePublisher$ByteBufferIterator();
	void init$(::jdk::internal::net::http::RequestPublishers$IterablePublisher* this$0);
	virtual void copy();
	virtual ::java::nio::ByteBuffer* getBuffer();
	virtual bool hasNext() override;
	virtual $Object* next() override;
	::jdk::internal::net::http::RequestPublishers$IterablePublisher* this$0 = nullptr;
	::java::util::concurrent::ConcurrentLinkedQueue* buffers = nullptr;
	::java::util::Iterator* iterator = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$IterablePublisher$ByteBufferIterator_h_