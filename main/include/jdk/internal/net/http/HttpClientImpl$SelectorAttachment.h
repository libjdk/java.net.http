#ifndef _jdk_internal_net_http_HttpClientImpl$SelectorAttachment_h_
#define _jdk_internal_net_http_HttpClientImpl$SelectorAttachment_h_
//$ class jdk.internal.net.http.HttpClientImpl$SelectorAttachment
//$ extends java.lang.Object

#include <java/lang/Object.h>

namespace java {
	namespace lang {
		class Throwable;
	}
}
namespace java {
	namespace nio {
		namespace channels {
			class SelectableChannel;
			class Selector;
		}
	}
}
namespace java {
	namespace util {
		class Set;
	}
}
namespace java {
	namespace util {
		namespace stream {
			class Stream;
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				class AsyncEvent;
			}
		}
	}
}
namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class Logger;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $import HttpClientImpl$SelectorAttachment : public ::java::lang::Object {
	$class(HttpClientImpl$SelectorAttachment, 0, ::java::lang::Object)
public:
	HttpClientImpl$SelectorAttachment();
	void init$(::java::nio::channels::SelectableChannel* chan, ::java::nio::channels::Selector* selector);
	virtual void abortPending($Throwable* x);
	virtual ::java::util::stream::Stream* events(int32_t interestOps);
	static bool lambda$events$0(int32_t interestOps, ::jdk::internal::net::http::AsyncEvent* ev);
	virtual void register$(::jdk::internal::net::http::AsyncEvent* e);
	virtual void resetInterestOps(int32_t interestOps);
	static bool $assertionsDisabled;
	::java::nio::channels::SelectableChannel* chan = nullptr;
	::java::nio::channels::Selector* selector = nullptr;
	::java::util::Set* pending = nullptr;
	static ::jdk::internal::net::http::common::Logger* debug;
	int32_t interestOps = 0;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_HttpClientImpl$SelectorAttachment_h_