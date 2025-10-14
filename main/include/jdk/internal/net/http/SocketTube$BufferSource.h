#ifndef _jdk_internal_net_http_SocketTube$BufferSource_h_
#define _jdk_internal_net_http_SocketTube$BufferSource_h_
//$ interface jdk.internal.net.http.SocketTube$BufferSource
//$ extends java.lang.Object

#include <java/lang/Object.h>

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

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import SocketTube$BufferSource : public ::java::lang::Object {
	$interface(SocketTube$BufferSource, $NO_CLASS_INIT, ::java::lang::Object)
public:
	virtual ::java::util::List* append(::java::util::List* list, ::java::nio::ByteBuffer* buffer, int32_t start) {return nullptr;}
	virtual ::java::nio::ByteBuffer* getBuffer() {return nullptr;}
	virtual void returnUnused(::java::nio::ByteBuffer* buffer);
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_SocketTube$BufferSource_h_