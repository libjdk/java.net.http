#ifndef _jdk_internal_net_http_hpack_HeaderTable_h_
#define _jdk_internal_net_http_hpack_HeaderTable_h_
//$ class jdk.internal.net.http.hpack.HeaderTable
//$ extends jdk.internal.net.http.hpack.SimpleHeaderTable

#include <jdk/internal/net/http/hpack/SimpleHeaderTable.h>

namespace java {
	namespace lang {
		class CharSequence;
	}
}
namespace java {
	namespace util {
		class Deque;
		class Map;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
					class HPACK$Logger;
					class SimpleHeaderTable$HeaderField;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class HeaderTable : public ::jdk::internal::net::http::hpack::SimpleHeaderTable {
	$class(HeaderTable, 0, ::jdk::internal::net::http::hpack::SimpleHeaderTable)
public:
	HeaderTable();
	void init$(int32_t maxSize, ::jdk::internal::net::http::hpack::HPACK$Logger* logger);
	virtual void add(::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* f) override;
	int32_t indexOf(::java::lang::CharSequence* name, ::java::lang::CharSequence* value);
	bool indexesUniqueAndOrdered(::java::util::Deque* indexes);
	static ::java::util::Deque* lambda$add$2($String* k);
	static ::java::util::Map* lambda$static$0($String* k);
	virtual ::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* remove() override;
	int32_t search($String* name, $String* value);
	static bool $assertionsDisabled;
	static ::java::util::Map* staticIndexes;
	::java::util::Map* map = nullptr;
	int64_t counter = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_hpack_HeaderTable_h_