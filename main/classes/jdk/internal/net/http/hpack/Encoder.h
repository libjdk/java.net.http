#ifndef _jdk_internal_net_http_hpack_Encoder_h_
#define _jdk_internal_net_http_hpack_Encoder_h_
//$ class jdk.internal.net.http.hpack.Encoder
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("ENCODERS_IDS")
#undef ENCODERS_IDS

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
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicLong;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {
					class BinaryRepresentationWriter;
					class BulkSizeUpdateWriter;
					class HPACK$Logger;
					class HeaderTable;
					class IndexedWriter;
					class LiteralNeverIndexedWriter;
					class LiteralWithIndexingWriter;
					class LiteralWriter;
					class QuickHuffman$Writer;
					class SizeUpdateWriter;
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

class Encoder : public ::java::lang::Object {
	$class(Encoder, 0, ::java::lang::Object)
public:
	Encoder();
	void init$(int32_t maxCapacity);
	virtual int32_t calculateCapacity(int32_t maxCapacity);
	void checkEncoding();
	bool encode(::java::nio::ByteBuffer* headerBlock);
	::jdk::internal::net::http::hpack::HeaderTable* getHeaderTable();
	int32_t getMaxCapacity();
	virtual void header(::java::lang::CharSequence* name, ::java::lang::CharSequence* value);
	virtual void header(::java::lang::CharSequence* name, ::java::lang::CharSequence* value, bool sensitive);
	void indexed(int32_t index);
	bool isHuffmanBetterFor(::java::lang::CharSequence* value);
	static $String* lambda$encode$5(::java::nio::ByteBuffer* headerBlock);
	static $String* lambda$header$2(::java::lang::CharSequence* name, ::java::lang::CharSequence* value, bool sensitive);
	static $String* lambda$indexed$6(int32_t index);
	static $String* lambda$literal$7(int32_t index, ::java::lang::CharSequence* value, bool useHuffman);
	static $String* lambda$literal$8(::java::lang::CharSequence* name, bool nameHuffman, ::java::lang::CharSequence* value, bool valueHuffman);
	static $String* lambda$literalNeverIndexed$10(::java::lang::CharSequence* name, bool nameHuffman, ::java::lang::CharSequence* value, bool valueHuffman);
	static $String* lambda$literalNeverIndexed$9(int32_t index, ::java::lang::CharSequence* value, bool valueHuffman);
	static $String* lambda$literalWithIndexing$11(int32_t index, ::java::lang::CharSequence* value, bool valueHuffman);
	static $String* lambda$literalWithIndexing$12(::java::lang::CharSequence* name, bool nameHuffman, ::java::lang::CharSequence* value, bool valueHuffman);
	static $String* lambda$new$0(int32_t maxCapacity);
	$String* lambda$new$1();
	static $String* lambda$setMaxCapacity$3(int32_t capacity);
	static $String* lambda$setMaxCapacity0$4(int32_t calculated);
	static $String* lambda$sizeUpdate$13(int32_t capacity);
	void literal(int32_t index, ::java::lang::CharSequence* value, bool useHuffman);
	void literal(::java::lang::CharSequence* name, bool nameHuffman, ::java::lang::CharSequence* value, bool valueHuffman);
	void literalNeverIndexed(int32_t index, ::java::lang::CharSequence* value, bool valueHuffman);
	void literalNeverIndexed(::java::lang::CharSequence* name, bool nameHuffman, ::java::lang::CharSequence* value, bool valueHuffman);
	void literalWithIndexing(int32_t index, ::java::lang::CharSequence* value, bool valueHuffman);
	void literalWithIndexing(::java::lang::CharSequence* name, bool nameHuffman, ::java::lang::CharSequence* value, bool valueHuffman);
	bool prependWithCapacityUpdate(::java::nio::ByteBuffer* headerBlock);
	virtual void setMaxCapacity(int32_t capacity);
	void setMaxCapacity0(int32_t capacity);
	void sizeUpdate(int32_t capacity);
	static ::java::util::concurrent::atomic::AtomicLong* ENCODERS_IDS;
	::jdk::internal::net::http::hpack::QuickHuffman$Writer* huffmanWriter = nullptr;
	::jdk::internal::net::http::hpack::HPACK$Logger* logger = nullptr;
	int64_t id = 0;
	::jdk::internal::net::http::hpack::IndexedWriter* indexedWriter = nullptr;
	::jdk::internal::net::http::hpack::LiteralWriter* literalWriter = nullptr;
	::jdk::internal::net::http::hpack::LiteralNeverIndexedWriter* literalNeverIndexedWriter = nullptr;
	::jdk::internal::net::http::hpack::LiteralWithIndexingWriter* literalWithIndexingWriter = nullptr;
	::jdk::internal::net::http::hpack::SizeUpdateWriter* sizeUpdateWriter = nullptr;
	::jdk::internal::net::http::hpack::BulkSizeUpdateWriter* bulkSizeUpdateWriter = nullptr;
	::jdk::internal::net::http::hpack::BinaryRepresentationWriter* writer = nullptr;
	::jdk::internal::net::http::hpack::HeaderTable* headerTable = nullptr;
	bool encoding = false;
	int32_t maxCapacity = 0;
	int32_t currCapacity = 0;
	int32_t lastCapacity = 0;
	int64_t minCapacity = 0;
	bool capacityUpdate = false;
	bool configuredCapacityUpdate = false;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("ENCODERS_IDS")

#endif // _jdk_internal_net_http_hpack_Encoder_h_