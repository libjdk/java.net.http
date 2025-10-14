#ifndef _jdk_internal_net_http_RawChannelTube$CleanupChecker_h_
#define _jdk_internal_net_http_RawChannelTube$CleanupChecker_h_
//$ class jdk.internal.net.http.RawChannelTube$CleanupChecker
//$ extends java.lang.Runnable

#include <java/lang/Runnable.h>

namespace java {
	namespace lang {
		class System$Logger;
	}
}
namespace java {
	namespace util {
		namespace concurrent {
			namespace atomic {
				class AtomicBoolean;
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class $export RawChannelTube$CleanupChecker : public ::java::lang::Runnable {
	$class(RawChannelTube$CleanupChecker, $NO_CLASS_INIT, ::java::lang::Runnable)
public:
	RawChannelTube$CleanupChecker();
	void init$(::java::util::concurrent::atomic::AtomicBoolean* closed, ::java::lang::System$Logger* debug);
	virtual void run() override;
	::java::util::concurrent::atomic::AtomicBoolean* closed = nullptr;
	::java::lang::System$Logger* debug = nullptr;
};

			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_RawChannelTube$CleanupChecker_h_