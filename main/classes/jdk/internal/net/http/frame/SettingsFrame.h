#ifndef _jdk_internal_net_http_frame_SettingsFrame_h_
#define _jdk_internal_net_http_frame_SettingsFrame_h_
//$ class jdk.internal.net.http.frame.SettingsFrame
//$ extends jdk.internal.net.http.frame.Http2Frame

#include <java/lang/Array.h>
#include <java/lang/Integer.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>

#pragma push_macro("ACK")
#undef ACK
#pragma push_macro("DEFAULT_ENABLE_PUSH")
#undef DEFAULT_ENABLE_PUSH
#pragma push_macro("DEFAULT_HEADER_TABLE_SIZE")
#undef DEFAULT_HEADER_TABLE_SIZE
#pragma push_macro("DEFAULT_INITIAL_WINDOW_SIZE")
#undef DEFAULT_INITIAL_WINDOW_SIZE
#pragma push_macro("DEFAULT_MAX_CONCURRENT_STREAMS")
#undef DEFAULT_MAX_CONCURRENT_STREAMS
#pragma push_macro("DEFAULT_MAX_FRAME_SIZE")
#undef DEFAULT_MAX_FRAME_SIZE
#pragma push_macro("ENABLE_PUSH")
#undef ENABLE_PUSH
#pragma push_macro("HEADER_TABLE_SIZE")
#undef HEADER_TABLE_SIZE
#pragma push_macro("INITIAL_WINDOW_SIZE")
#undef INITIAL_WINDOW_SIZE
#pragma push_macro("K")
#undef K
#pragma push_macro("MAX_CONCURRENT_STREAMS")
#undef MAX_CONCURRENT_STREAMS
#pragma push_macro("MAX_FRAME_SIZE")
#undef MAX_FRAME_SIZE
#pragma push_macro("MAX_HEADER_LIST_SIZE")
#undef MAX_HEADER_LIST_SIZE
#pragma push_macro("MAX_PARAM")
#undef MAX_PARAM
#pragma push_macro("MAX_VALUE")
#undef MAX_VALUE
#pragma push_macro("TYPE")
#undef TYPE

namespace java {
	namespace nio {
		class ByteBuffer;
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $export SettingsFrame : public ::jdk::internal::net::http::frame::Http2Frame {
	$class(SettingsFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::Http2Frame)
public:
	SettingsFrame();
	void init$(int32_t flags);
	void init$();
	void init$(::jdk::internal::net::http::frame::SettingsFrame* other);
	static ::jdk::internal::net::http::frame::SettingsFrame* defaultRFCSettings();
	virtual $String* flagAsString(int32_t flag) override;
	virtual int32_t getParameter(int32_t paramID);
	virtual int32_t length() override;
	$String* name(int32_t i);
	virtual ::jdk::internal::net::http::frame::SettingsFrame* setParameter(int32_t paramID, int32_t value);
	virtual $bytes* toByteArray();
	virtual void toByteBuffer(::java::nio::ByteBuffer* buf);
	virtual $String* toString() override;
	virtual int32_t type() override;
	virtual void update(::jdk::internal::net::http::frame::SettingsFrame* updated);
	$ints* parameters = nullptr;
	static const int32_t TYPE = 4;
	static const int32_t ACK = 1;
	static const int32_t HEADER_TABLE_SIZE = 1;
	static const int32_t ENABLE_PUSH = 2;
	static const int32_t MAX_CONCURRENT_STREAMS = 3;
	static const int32_t INITIAL_WINDOW_SIZE = 4;
	static const int32_t MAX_FRAME_SIZE = 5;
	static const int32_t MAX_HEADER_LIST_SIZE = 6;
	static const int32_t MAX_PARAM = 6;
	static const int32_t K = 1024;
	static const int32_t DEFAULT_HEADER_TABLE_SIZE = 4096; // 4 * K
	static const int32_t DEFAULT_ENABLE_PUSH = 1;
	static const int32_t DEFAULT_MAX_CONCURRENT_STREAMS = ::java::lang::Integer::MAX_VALUE;
	static const int32_t DEFAULT_INITIAL_WINDOW_SIZE = 65535; // 64 * K - 1
	static const int32_t DEFAULT_MAX_FRAME_SIZE = 16384; // 16 * K
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("ACK")
#pragma pop_macro("DEFAULT_ENABLE_PUSH")
#pragma pop_macro("DEFAULT_HEADER_TABLE_SIZE")
#pragma pop_macro("DEFAULT_INITIAL_WINDOW_SIZE")
#pragma pop_macro("DEFAULT_MAX_CONCURRENT_STREAMS")
#pragma pop_macro("DEFAULT_MAX_FRAME_SIZE")
#pragma pop_macro("ENABLE_PUSH")
#pragma pop_macro("HEADER_TABLE_SIZE")
#pragma pop_macro("INITIAL_WINDOW_SIZE")
#pragma pop_macro("K")
#pragma pop_macro("MAX_CONCURRENT_STREAMS")
#pragma pop_macro("MAX_FRAME_SIZE")
#pragma pop_macro("MAX_HEADER_LIST_SIZE")
#pragma pop_macro("MAX_PARAM")
#pragma pop_macro("MAX_VALUE")
#pragma pop_macro("TYPE")

#endif // _jdk_internal_net_http_frame_SettingsFrame_h_