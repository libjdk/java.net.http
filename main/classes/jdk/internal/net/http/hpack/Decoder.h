#ifndef _jdk_internal_net_http_hpack_Decoder_h_
#define _jdk_internal_net_http_hpack_Decoder_h_
//$ class jdk.internal.net.http.hpack.Decoder
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("DECODERS_IDS")
#undef DECODERS_IDS

namespace java {
	namespace lang {
		class StringBuilder;
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
					class Decoder$State;
					class DecodingCallback;
					class HPACK$Logger;
					class IntegerReader;
					class SimpleHeaderTable;
					class SimpleHeaderTable$HeaderField;
					class StringReader;
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

class Decoder : public ::java::lang::Object {
	$class(Decoder, 0, ::java::lang::Object)
public:
	Decoder();
	void init$(int32_t capacity);
	void cleanUpAfterReading();
	bool completeReading(::java::nio::ByteBuffer* input);
	void decode(::java::nio::ByteBuffer* headerBlock, bool endOfHeaderBlock, ::jdk::internal::net::http::hpack::DecodingCallback* consumer);
	::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField* getHeaderFieldAt(int32_t index);
	::jdk::internal::net::http::hpack::SimpleHeaderTable* getTable();
	static $String* lambda$decode$3(::java::nio::ByteBuffer* headerBlock, bool endOfHeaderBlock);
	$String* lambda$decode$4();
	static $String* lambda$new$0(int32_t capacity);
	$String* lambda$new$1();
	$String* lambda$resumeIndexed$6();
	$String* lambda$resumeLiteral$7();
	$String* lambda$resumeLiteral$8();
	$String* lambda$resumeLiteralNeverIndexed$11();
	$String* lambda$resumeLiteralNeverIndexed$12();
	$String* lambda$resumeLiteralWithIndexing$10($String* n);
	$String* lambda$resumeLiteralWithIndexing$9();
	static $String* lambda$resumeReady$5(::jdk::internal::net::http::hpack::Decoder$State* s, int32_t b);
	$String* lambda$resumeSizeUpdate$13();
	static $String* lambda$setMaxCapacity$2(int32_t capacity);
	void proceed(::java::nio::ByteBuffer* input, ::jdk::internal::net::http::hpack::DecodingCallback* action);
	void resumeIndexed(::java::nio::ByteBuffer* input, ::jdk::internal::net::http::hpack::DecodingCallback* action);
	void resumeLiteral(::java::nio::ByteBuffer* input, ::jdk::internal::net::http::hpack::DecodingCallback* action);
	void resumeLiteralNeverIndexed(::java::nio::ByteBuffer* input, ::jdk::internal::net::http::hpack::DecodingCallback* action);
	void resumeLiteralWithIndexing(::java::nio::ByteBuffer* input, ::jdk::internal::net::http::hpack::DecodingCallback* action);
	void resumeReady(::java::nio::ByteBuffer* input);
	void resumeSizeUpdate(::java::nio::ByteBuffer* input, ::jdk::internal::net::http::hpack::DecodingCallback* action);
	void setMaxCapacity(int32_t capacity);
	void setMaxCapacity0(int32_t capacity);
	static bool $assertionsDisabled;
	::jdk::internal::net::http::hpack::HPACK$Logger* logger = nullptr;
	static ::java::util::concurrent::atomic::AtomicLong* DECODERS_IDS;
	static ::java::util::List* states;
	int64_t id = 0;
	::jdk::internal::net::http::hpack::SimpleHeaderTable* table = nullptr;
	::jdk::internal::net::http::hpack::Decoder$State* state = nullptr;
	::jdk::internal::net::http::hpack::IntegerReader* integerReader = nullptr;
	::jdk::internal::net::http::hpack::StringReader* stringReader = nullptr;
	::java::lang::StringBuilder* name = nullptr;
	::java::lang::StringBuilder* value = nullptr;
	int32_t intValue = 0;
	bool firstValueRead = false;
	bool firstValueIndex = false;
	bool nameHuffmanEncoded = false;
	bool valueHuffmanEncoded = false;
	int32_t capacity = 0;
};

				} // hpack
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DECODERS_IDS")

#endif // _jdk_internal_net_http_hpack_Decoder_h_