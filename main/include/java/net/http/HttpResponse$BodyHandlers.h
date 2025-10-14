#ifndef _java_net_http_HttpResponse$BodyHandlers_h_
#define _java_net_http_HttpResponse$BodyHandlers_h_
//$ class java.net.http.HttpResponse$BodyHandlers
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
			class HttpResponse$BodyHandler;
			class HttpResponse$BodySubscriber;
			class HttpResponse$ResponseInfo;
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

class $import HttpResponse$BodyHandlers : public ::java::lang::Object {
	$class(HttpResponse$BodyHandlers, $NO_CLASS_INIT, ::java::lang::Object)
public:
	HttpResponse$BodyHandlers();
	void init$();
	static ::java::net::http::HttpResponse$BodyHandler* buffering(::java::net::http::HttpResponse$BodyHandler* downstreamHandler, int32_t bufferSize);
	static ::java::net::http::HttpResponse$BodyHandler* discarding();
	static ::java::net::http::HttpResponse$BodyHandler* fromLineSubscriber(::java::util::concurrent::Flow$Subscriber* subscriber);
	static ::java::net::http::HttpResponse$BodyHandler* fromLineSubscriber(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::function::Function* finisher, $String* lineSeparator);
	static ::java::net::http::HttpResponse$BodyHandler* fromSubscriber(::java::util::concurrent::Flow$Subscriber* subscriber);
	static ::java::net::http::HttpResponse$BodyHandler* fromSubscriber(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::function::Function* finisher);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$buffering$15(::java::net::http::HttpResponse$BodyHandler* downstreamHandler, int32_t bufferSize, ::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$discarding$6(::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$fromLineSubscriber$4(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$fromLineSubscriber$5(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::function::Function* finisher, $String* lineSeparator, ::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::lang::Void* lambda$fromSubscriber$0(::java::util::concurrent::Flow$Subscriber* s);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$fromSubscriber$1(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$fromSubscriber$2(::java::util::concurrent::Flow$Subscriber* subscriber, ::java::util::function::Function* finisher, ::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$ofByteArray$12(::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$ofByteArrayConsumer$11(::java::util::function::Consumer* consumer, ::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$ofInputStream$9(::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$ofLines$10(::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$ofPublisher$14(::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$ofString$13(::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$ofString$8(::java::nio::charset::Charset* charset, ::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodySubscriber* lambda$replacing$7(Object$* value, ::java::net::http::HttpResponse$ResponseInfo* responseInfo);
	static ::java::net::http::HttpResponse$BodyHandler* ofByteArray();
	static ::java::net::http::HttpResponse$BodyHandler* ofByteArrayConsumer(::java::util::function::Consumer* consumer);
	static ::java::net::http::HttpResponse$BodyHandler* ofFile(::java::nio::file::Path* file, $Array<::java::nio::file::OpenOption>* openOptions);
	static ::java::net::http::HttpResponse$BodyHandler* ofFile(::java::nio::file::Path* file);
	static ::java::net::http::HttpResponse$BodyHandler* ofFileDownload(::java::nio::file::Path* directory, $Array<::java::nio::file::OpenOption>* openOptions);
	static ::java::net::http::HttpResponse$BodyHandler* ofInputStream();
	static ::java::net::http::HttpResponse$BodyHandler* ofLines();
	static ::java::net::http::HttpResponse$BodyHandler* ofPublisher();
	static ::java::net::http::HttpResponse$BodyHandler* ofString(::java::nio::charset::Charset* charset);
	static ::java::net::http::HttpResponse$BodyHandler* ofString();
	static ::java::net::http::HttpResponse$BodyHandler* replacing(Object$* value);
};

		} // http
	} // net
} // java

#endif // _java_net_http_HttpResponse$BodyHandlers_h_