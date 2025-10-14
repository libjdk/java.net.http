#ifndef _jdk_internal_net_http_hpack_IndexNameValueWriter_h_
#define _jdk_internal_net_http_hpack_IndexNameValueWriter_h_
//$ class jdk.internal.net.http.hpack.IndexNameValueWriter
//$ extends jdk.internal.net.http.hpack.BinaryRepresentationWriter

#include <jdk/internal/net/http/hpack/BinaryRepresentationWriter.h>

#pragma push_macro("NAME_PART_WRITTEN")
#undef NAME_PART_WRITTEN
#pragma push_macro("NEW")
#undef NEW
#pragma push_macro("VALUE_WRITTEN")
#undef VALUE_WRITTEN

namespace java {
	namespace lang {
		class CharSequence;
	}
}
namespace java {
	namespace nio {
		class ByteBuffer;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
					class HeaderTable;
					class IntegerWriter;
					class StringWriter;
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

class IndexNameValueWriter : public ::jdk::internal::net::http::hpack::BinaryRepresentationWriter {
	$class(IndexNameValueWriter, $NO_CLASS_INIT, ::jdk::internal::net::http::hpack::BinaryRepresentationWriter)
public:
	IndexNameValueWriter();
	void init$(int32_t pattern, int32_t prefix);
	virtual ::jdk::internal::net::http::hpack::IndexNameValueWriter* index(int32_t index);
	virtual ::jdk::internal::net::http::hpack::IndexNameValueWriter* name(::java::lang::CharSequence* name, bool useHuffman);
	virtual ::jdk::internal::net::http::hpack::IndexNameValueWriter* reset() override;
	virtual ::jdk::internal::net::http::hpack::IndexNameValueWriter* value(::java::lang::CharSequence* value, bool useHuffman);
	virtual bool write(::jdk::internal::net::http::hpack::HeaderTable* table, ::java::nio::ByteBuffer* destination) override;
	int32_t pattern = 0;
	int32_t prefix = 0;
	::jdk::internal::net::http::hpack::IntegerWriter* intWriter = nullptr;
	::jdk::internal::net::http::hpack::StringWriter* nameWriter = nullptr;
	::jdk::internal::net::http::hpack::StringWriter* valueWriter = nullptr;
	bool indexedRepresentation = false;
	static const int32_t NEW = 0;
	static const int32_t NAME_PART_WRITTEN = 1;
	static const int32_t VALUE_WRITTEN = 2;
	int32_t state = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("NAME_PART_WRITTEN")
#pragma pop_macro("NEW")
#pragma pop_macro("VALUE_WRITTEN")

#endif // _jdk_internal_net_http_hpack_IndexNameValueWriter_h_