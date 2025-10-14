#ifndef _java_net_http_HttpRequest_h_
#define _java_net_http_HttpRequest_h_
//$ class java.net.http.HttpRequest
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace net {
		class URI;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpHeaders;
			class HttpRequest$BodyPublisher;
			class HttpRequest$Builder;
		}
	}
}
namespace java {
	namespace util {
		class List;
		class Optional;
	}
}
namespace java {
	namespace util {
		namespace function {
			class BiPredicate;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $export HttpRequest : public ::java::lang::Object {
	$class(HttpRequest, $NO_CLASS_INIT, ::java::lang::Object)
public:
	HttpRequest();
	void init$();
	virtual ::java::util::Optional* bodyPublisher() {return nullptr;}
	virtual bool equals(Object$* obj) override;
	virtual bool expectContinue() {return false;}
	virtual int32_t hashCode() override;
	virtual ::java::net::http::HttpHeaders* headers() {return nullptr;}
	static void lambda$newBuilder$0(::java::net::http::HttpRequest$Builder* builder, $String* name, $String* value);
	static void lambda$newBuilder$1(::java::net::http::HttpRequest$Builder* builder, $String* name, ::java::util::List* values);
	static void lambda$newBuilder$2(::java::net::http::HttpRequest$Builder* builder, $String* method, ::java::net::http::HttpRequest$BodyPublisher* bodyPublisher);
	static void lambda$newBuilder$3($String* method, ::java::net::http::HttpRequest$Builder* builder);
	virtual $String* method() {return nullptr;}
	static ::java::net::http::HttpRequest$Builder* newBuilder(::java::net::URI* uri);
	static ::java::net::http::HttpRequest$Builder* newBuilder(::java::net::http::HttpRequest* request, ::java::util::function::BiPredicate* filter);
	static ::java::net::http::HttpRequest$Builder* newBuilder();
	virtual ::java::util::Optional* timeout() {return nullptr;}
	virtual ::java::net::URI* uri() {return nullptr;}
	virtual ::java::util::Optional* version() {return nullptr;}
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpRequest_h_