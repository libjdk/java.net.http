#ifndef _jdk_internal_net_http_frame_Http2Frame_h_
#define _jdk_internal_net_http_frame_Http2Frame_h_
//$ class jdk.internal.net.http.frame.Http2Frame
//$ extends java.lang.Object

#include <java/lang/Object.h>

#pragma push_macro("FRAME_HEADER_SIZE")
#undef FRAME_HEADER_SIZE

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $import Http2Frame : public ::java::lang::Object {
	$class(Http2Frame, $NO_CLASS_INIT, ::java::lang::Object)
public:
	Http2Frame();
	void init$(int32_t streamid, int32_t flags);
	static $String* asString(int32_t type);
	virtual $String* flagAsString(int32_t f);
	virtual bool getFlag(int32_t flag);
	virtual int32_t getFlags();
	virtual int32_t length();
	virtual void setFlag(int32_t flag);
	virtual int32_t streamid();
	virtual void streamid(int32_t streamid);
	virtual $String* toString() override;
	virtual int32_t type();
	$String* typeAsString();
	static const int32_t FRAME_HEADER_SIZE = 9;
	int32_t streamid$ = 0;
	int32_t flags = 0;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("FRAME_HEADER_SIZE")

#endif // _jdk_internal_net_http_frame_Http2Frame_h_