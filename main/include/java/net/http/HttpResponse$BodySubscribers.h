#ifndef _java_net_http_HttpResponse$BodySubscribers_h_
#define _java_net_http_HttpResponse$BodySubscribers_h_
//$ class java.net.http.HttpResponse$BodySubscribers
//$ extends java.lang.Object

#include <java/lang/Array.h>

namespace java {
	namespace lang {
		class Void;
	}
}
namespace java {
	namespace net {
		namespace http {
			class HttpResponse$BodySubscriber;
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
			class OpenOption;
			class Path;
		}
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			class Flow$Subscriber;
		}
	}
}
namespace java {
	namespace util {
		namespace function {
			class Consumer;
			class Function;
		}
	}
}

namespace java {
	namespace net {
		namespace http {

class $import HttpResponse$BodySubscribers : public ::java::lang::Object {
	$class(HttpResponse$BodySubscribers, $NO_CLASS_INIT, ::java::lang::Object)
public:
	HttpResponse$BodySubscribers();
	void init$();
	static ::java::net::http::HttpResponse$BodySubscriber* buffering(::java::net::http::HttpResponse$BodySubscriber* downstream, int32_t bufferSize);
	static ::java::net::http::HttpResponse$BodySubscriber* discarding();
	static ::java::net::http::HttpResponse$BodySubscriber* fromLineSubscriber(::java::util::concurrent::Flow$Subscriber* subscriber);
	static ::java::net::http::HttpResponse$BodySubscriber* fromLineSubscriber(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::function::Function* finisher, ::java::nio::charset::Charset* charset, $String* lineSeparator);
	static ::java::net::http::HttpResponse$BodySubscriber* fromSubscriber(::java::util::concurrent::Flow$Subscriber* subscriber);
	static ::java::net::http::HttpResponse$BodySubscriber* fromSubscriber(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::function::Function* finisher);
	static ::java::lang::Void* lambda$fromSubscriber$0(::java::util::concurrent::Flow$Subscriber* s);
	static $String* lambda$ofString$2(::java::nio::charset::Charset* charset, $bytes* bytes);
	static ::java::net::http::HttpResponse$BodySubscriber* mapping(::java::net::http::HttpResponse$BodySubscriber* upstream, ::java::util::function::Function* mapper);
	static ::java::net::http::HttpResponse$BodySubscriber* ofByteArray();
	static ::java::net::http::HttpResponse$BodySubscriber* ofByteArrayConsumer(::java::util::function::Consumer* consumer);
	static ::java::net::http::HttpResponse$BodySubscriber* ofFile(::java::nio::file::Path* file, $Array<::java::nio::file::OpenOption>* openOptions);
	static ::java::net::http::HttpResponse$BodySubscriber* ofFile(::java::nio::file::Path* file);
	static ::java::net::http::HttpResponse$BodySubscriber* ofInputStream();
	static ::java::net::http::HttpResponse$BodySubscriber* ofLines(::java::nio::charset::Charset* charset);
	static ::java::net::http::HttpResponse$BodySubscriber* ofPublisher();
	static ::java::net::http::HttpResponse$BodySubscriber* ofString(::java::nio::charset::Charset* charset);
	static ::java::net::http::HttpResponse$BodySubscriber* replacing(Object$* value);
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpResponse$BodySubscribers_h_