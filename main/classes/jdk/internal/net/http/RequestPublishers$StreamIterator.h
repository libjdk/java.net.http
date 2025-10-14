#ifndef _jdk_internal_net_http_RequestPublishers$StreamIterator_h_
#define _jdk_internal_net_http_RequestPublishers$StreamIterator_h_
//$ class jdk.internal.net.http.RequestPublishers$StreamIterator
//$ extends java.util.Iterator

#include <java/util/Iterator.h>

namespace java {
	namespace io {
		class InputStream;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
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

class $export RequestPublishers$StreamIterator : public ::java::util::Iterator {
	$class(RequestPublishers$StreamIterator, $NO_CLASS_INIT, ::java::util::Iterator)
public:
	RequestPublishers$StreamIterator();
	void init$(::java::io::InputStream* is);
	void init$(::java::io::InputStream* is, ::java::util::function::Supplier* bufSupplier);
	void closeStream();
	virtual bool hasNext() override;
	virtual $Object* next() override;
	int32_t read();
	::java::io::InputStream* is = nullptr;
	::java::util::function::Supplier* bufSupplier = nullptr;
	$volatile(bool) eof = false;
	$volatile(::java::nio::ByteBuffer*) nextBuffer = nullptr;
	$volatile(bool) need2Read = false;
	$volatile(bool) haveNext = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RequestPublishers$StreamIterator_h_