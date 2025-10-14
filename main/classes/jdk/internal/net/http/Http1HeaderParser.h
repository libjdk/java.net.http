#ifndef _jdk_internal_net_http_Http1HeaderParser_h_
#define _jdk_internal_net_http_Http1HeaderParser_h_
//$ class jdk.internal.net.http.Http1HeaderParser
//$ extends java.lang.Object

#include <java/lang/Array.h>

#pragma push_macro("CR")
#undef CR
#pragma push_macro("HT")
#undef HT
#pragma push_macro("LF")
#undef LF
#pragma push_macro("SP")
#undef SP

namespace java {
	namespace lang {
		class StringBuilder;
	}
}
namespace java {
	namespace net {
		class ProtocolException;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
		}
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
		class Map;
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class Http1HeaderParser$State;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export Http1HeaderParser : public ::java::lang::Object {
	$class(Http1HeaderParser, 0, ::java::lang::Object)
public:
	Http1HeaderParser();
	void init$();
	void addHeaderFromString($String* headerString);
	bool canContinueParsing(::java::nio::ByteBuffer* buffer);
	virtual $String* currentStateMessage();
	char16_t get(::java::nio::ByteBuffer* input);
	virtual ::java::net::http::HttpHeaders* headers();
	static ::java::util::List* lambda$addHeaderFromString$0($String* k);
	void maybeEndHeaders(::java::nio::ByteBuffer* input);
	void maybeStartHeaders(::java::nio::ByteBuffer* input);
	virtual bool parse(::java::nio::ByteBuffer* input);
	::java::net::ProtocolException* protocolException($String* format, $ObjectArray* args);
	void readResumeHeader(::java::nio::ByteBuffer* input);
	void readResumeStatusLine(::java::nio::ByteBuffer* input);
	void readStatusLineFeed(::java::nio::ByteBuffer* input);
	virtual int32_t responseCode();
	void resumeOrEndHeaders(::java::nio::ByteBuffer* input);
	void resumeOrLF(::java::nio::ByteBuffer* input);
	void resumeOrSecondCR(::java::nio::ByteBuffer* input);
	virtual $String* statusLine();
	static bool $assertionsDisabled;
	static const char16_t CR = ((char16_t)13);
	static const char16_t LF = ((char16_t)10);
	static const char16_t HT = ((char16_t)9);
	static const char16_t SP = ((char16_t)32);
	::java::lang::StringBuilder* sb = nullptr;
	$String* statusLine$ = nullptr;
	int32_t responseCode$ = 0;
	::java::net::http::HttpHeaders* headers$ = nullptr;
	::java::util::Map* privateMap = nullptr;
	::jdk::internal::net::http::Http1HeaderParser$State* state = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("CR")
#pragma pop_macro("HT")
#pragma pop_macro("LF")
#pragma pop_macro("SP")

#endif // _jdk_internal_net_http_Http1HeaderParser_h_