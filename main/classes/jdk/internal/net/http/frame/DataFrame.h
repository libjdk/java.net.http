#ifndef _jdk_internal_net_http_frame_DataFrame_h_
#define _jdk_internal_net_http_frame_DataFrame_h_
//$ class jdk.internal.net.http.frame.DataFrame
//$ extends jdk.internal.net.http.frame.Http2Frame

#include <jdk/internal/net/http/frame/Http2Frame.h>

#pragma push_macro("END_STREAM")
#undef END_STREAM
#pragma push_macro("PADDED")
#undef PADDED
#pragma push_macro("TYPE")
#undef TYPE

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
				namespace frame {

class $export DataFrame : public ::jdk::internal::net::http::frame::Http2Frame {
	$class(DataFrame, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::Http2Frame)
public:
	DataFrame();
	void init$(int32_t streamid, int32_t flags, ::java::nio::ByteBuffer* data);
	void init$(int32_t streamid, int32_t flags, ::java::util::List* data);
	void init$(int32_t streamid, int32_t flags, ::java::util::List* data, int32_t padLength);
	virtual $String* flagAsString(int32_t flag) override;
	virtual ::java::util::List* getData();
	virtual int32_t getDataLength();
	virtual int32_t getPadLength();
	virtual int32_t length() override;
	virtual int32_t payloadLength();
	virtual void setPadLength(int32_t padLength);
	virtual int32_t type() override;
	static const int32_t TYPE = 0;
	static const int32_t END_STREAM = 1;
	static const int32_t PADDED = 8;
	int32_t padLength = 0;
	::java::util::List* data = nullptr;
	int32_t dataLength = 0;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("END_STREAM")
#pragma pop_macro("PADDED")
#pragma pop_macro("TYPE")

#endif // _jdk_internal_net_http_frame_DataFrame_h_