#ifndef _jdk_internal_net_http_hpack_SimpleHeaderTable_h_
#define _jdk_internal_net_http_hpack_SimpleHeaderTable_h_
//$ class jdk.internal.net.http.hpack.SimpleHeaderTable
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("ENTRY_SIZE")
#undef ENTRY_SIZE
#pragma push_macro("STATIC_TABLE_LENGTH")
#undef STATIC_TABLE_LENGTH

namespace java {
	namespace lang {
		class CharSequence;
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
				namespace hpack {
					class HPACK$Logger;
					class SimpleHeaderTable$CircularBuffer;
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

class SimpleHeaderTable : public ::java::lang::Object {
	$class(SimpleHeaderTable, 0, ::java::lang::Object)
public:
	SimpleHeaderTable();
	void init$(int32_t maxSize, ::jdk::internal::net::http::hpack::HPACK$Logger* logger);
	virtual void add(::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* f);
	int32_t checkIndex(int32_t index);
	virtual ::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* evictEntry();
	virtual ::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* get(int32_t index);
	virtual $String* getStateString();
	static $String* lambda$evictEntry$5(::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* f, int32_t s);
	static $String* lambda$put$0(::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* h);
	static $String* lambda$put$1(::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* h, int32_t entrySize);
	$String* lambda$put$2();
	static $String* lambda$put$3(::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* h);
	static $String* lambda$put$4(::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* h);
	virtual int32_t length();
	virtual int32_t maxSize();
	virtual void put(::java::lang::CharSequence* name, ::java::lang::CharSequence* value);
	void put(::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* h);
	virtual ::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* remove();
	virtual void setMaxSize(int32_t maxSize);
	virtual int32_t size();
	virtual int32_t sizeOf(::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* f);
	virtual $String* toString() override;
	static ::java::util::List* staticTable;
	static int32_t STATIC_TABLE_LENGTH;
	static const int32_t ENTRY_SIZE = 32;
	::jdk::internal::net::http::hpack::HPACK$Logger* logger = nullptr;
	int32_t maxSize$ = 0;
	int32_t size$ = 0;
	::jdk::internal::net::http::hpack::SimpleHeaderTable$CircularBuffer* buffer = nullptr;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("ENTRY_SIZE")
#pragma pop_macro("STATIC_TABLE_LENGTH")

#endif // _jdk_internal_net_http_hpack_SimpleHeaderTable_h_