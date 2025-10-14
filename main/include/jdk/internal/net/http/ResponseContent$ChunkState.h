#ifndef _jdk_internal_net_http_ResponseContent$ChunkState_h_
#define _jdk_internal_net_http_ResponseContent$ChunkState_h_
//$ class jdk.internal.net.http.ResponseContent$ChunkState
//$ extends java.lang.Enum

#include <java/lang/Array.h>
#include <java/lang/Enum.h>

#pragma push_macro("DONE")
#undef DONE
#pragma push_macro("READING_DATA")
#undef READING_DATA
#pragma push_macro("READING_LENGTH")
#undef READING_LENGTH

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import ResponseContent$ChunkState : public ::java::lang::Enum {
	$class(ResponseContent$ChunkState, 0, ::java::lang::Enum)
public:
	ResponseContent$ChunkState();
	static $Array<::jdk::internal::net::http::ResponseContent$ChunkState>* $values();
	void init$($String* $enum$name, int32_t $enum$ordinal);
	static ::jdk::internal::net::http::ResponseContent$ChunkState* valueOf($String* name);
	static $Array<::jdk::internal::net::http::ResponseContent$ChunkState>* values();
	static ::jdk::internal::net::http::ResponseContent$ChunkState* READING_LENGTH;
	static ::jdk::internal::net::http::ResponseContent$ChunkState* READING_DATA;
	static ::jdk::internal::net::http::ResponseContent$ChunkState* DONE;
	static $Array<::jdk::internal::net::http::ResponseContent$ChunkState>* $VALUES;
};

			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("DONE")
#pragma pop_macro("READING_DATA")
#pragma pop_macro("READING_LENGTH")

#endif // _jdk_internal_net_http_ResponseContent$ChunkState_h_