#ifndef _jdk_internal_net_http_frame_OutgoingHeaders_h_
#define _jdk_internal_net_http_frame_OutgoingHeaders_h_
//$ class jdk.internal.net.http.frame.OutgoingHeaders
//$ extends jdk.internal.net.http.frame.Http2Frame

#include <jdk/internal/net/http/frame/Http2Frame.h>

#pragma push_macro("PRIORITY")
#undef PRIORITY

namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

class $import OutgoingHeaders : public ::jdk::internal::net::http::frame::Http2Frame {
	$class(OutgoingHeaders, $NO_CLASS_INIT, ::jdk::internal::net::http::frame::Http2Frame)
public:
	OutgoingHeaders();
	void init$(::java::net::http::HttpHeaders* hdrs1, ::java::net::http::HttpHeaders* hdrs2, Object$* attachment);
	virtual $Object* getAttachment();
	virtual bool getExclusive();
	virtual int32_t getStreamDependency();
	virtual ::java::net::http::HttpHeaders* getSystemHeaders();
	virtual ::java::net::http::HttpHeaders* getUserHeaders();
	virtual int32_t getWeight();
	virtual void setPriority(int32_t streamDependency, bool exclusive, int32_t weight);
	int32_t streamDependency = 0;
	int32_t weight = 0;
	bool exclusive = false;
	$Object* attachment = nullptr;
	static const int32_t PRIORITY = 32;
	::java::net::http::HttpHeaders* user = nullptr;
	::java::net::http::HttpHeaders* system = nullptr;
};

				} // frame
			} // http
		} // net
	} // internal
} // jdk

#pragma pop_macro("PRIORITY")

#endif // _jdk_internal_net_http_frame_OutgoingHeaders_h_