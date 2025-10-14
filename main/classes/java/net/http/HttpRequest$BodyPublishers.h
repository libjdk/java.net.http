#ifndef _java_net_http_HttpRequest$BodyPublishers_h_
#define _java_net_http_HttpRequest$BodyPublishers_h_
//$ class java.net.http.HttpRequest$BodyPublishers
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class Iterable;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpRequest$BodyPublisher;
		}
	}
}
namespace java {
	namespace nio {
		namespace charset {
			class Charset;
		}
	}
}
namespace java {
	namespace nio {
		namespace file {
			class Path;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Publisher;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Supplier;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $export HttpRequest$BodyPublishers : public ::java::lang::Object {
	$class(HttpRequest$BodyPublishers, $NO_CLASS_INIT, ::java::lang::Object)
public:
	HttpRequest$BodyPublishers();
	void init$();
	static ::java::net::http::HttpRequest$BodyPublisher* concat($Array<::java::net::http::HttpRequest$BodyPublisher>* publishers);
	static ::java::net::http::HttpRequest$BodyPublisher* fromPublisher(::java::util::concurrent::Flow$Publisher* publisher);
	static ::java::net::http::HttpRequest$BodyPublisher* fromPublisher(::java::util::concurrent::Flow$Publisher* publisher, int64_t contentLength);
	static ::java::net::http::HttpRequest$BodyPublisher* noBody();
	static ::java::net::http::HttpRequest$BodyPublisher* ofByteArray($bytes* buf);
	static ::java::net::http::HttpRequest$BodyPublisher* ofByteArray($bytes* buf, int32_t offset, int32_t length);
	static ::java::net::http::HttpRequest$BodyPublisher* ofByteArrays(::java::lang::Iterable* iter);
	static ::java::net::http::HttpRequest$BodyPublisher* ofFile(::java::nio::file::Path* path);
	static ::java::net::http::HttpRequest$BodyPublisher* ofInputStream(::java::util::function::Supplier* streamSupplier);
	static ::java::net::http::HttpRequest$BodyPublisher* ofString($String* body);
	static ::java::net::http::HttpRequest$BodyPublisher* ofString($String* s, ::java::nio::charset::Charset* charset);
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpRequest$BodyPublishers_h_