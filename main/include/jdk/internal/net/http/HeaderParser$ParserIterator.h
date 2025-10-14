#ifndef _jdk_internal_net_http_HeaderParser$ParserIterator_h_
#define _jdk_internal_net_http_HeaderParser$ParserIterator_h_
//$ class jdk.internal.net.http.HeaderParser$ParserIterator
//$ extends java.util.Iterator

#include <java/util/Iterator.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class HeaderParser;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import HeaderParser$ParserIterator : public ::java::util::Iterator {
	$class(HeaderParser$ParserIterator, $NO_CLASS_INIT, ::java::util::Iterator)
public:
	HeaderParser$ParserIterator();
	void init$(::jdk::internal::net::http::HeaderParser* this$0, bool returnValue);
	virtual bool hasNext() override;
	virtual $Object* next() override;
	::jdk::internal::net::http::HeaderParser* this$0 = nullptr;
	int32_t index = 0;
	bool returnsValue = false;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HeaderParser$ParserIterator_h_