#ifndef _jdk_internal_net_http_common_FlowTube_h_
#define _jdk_internal_net_http_common_FlowTube_h_
//$ interface jdk.internal.net.http.common.FlowTube
//$ extends java.util.concurrent.Flow$Publisher,java.util.concurrent.Flow$Subscriber

#include <java/util/concurrent/Flow$Publisher.h>
#include <java/util/concurrent/Flow$Subscriber.h>

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {
					class FlowTube$TubePublisher;
					class FlowTube$TubeSubscriber;
				}
			}
		}
	}
}

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class $import FlowTube : public ::java::util::concurrent::Flow$Publisher, public ::java::util::concurrent::Flow$Subscriber {
	$interface(FlowTube, $NO_CLASS_INIT, ::java::util::concurrent::Flow$Publisher, ::java::util::concurrent::Flow$Subscriber)
public:
	static ::jdk::internal::net::http::common::FlowTube$TubePublisher* asTubePublisher(::java::util::concurrent::Flow$Publisher* p);
	static ::jdk::internal::net::http::common::FlowTube$TubeSubscriber* asTubeSubscriber(::java::util::concurrent::Flow$Subscriber* s);
	virtual $Object* clone() override;
	virtual void connectFlows(::jdk::internal::net::http::common::FlowTube$TubePublisher* writePublisher, ::jdk::internal::net::http::common::FlowTube$TubeSubscriber* readSubscriber);
	virtual bool equals(Object$* arg0) override;
	virtual void finalize() override;
	virtual int32_t hashCode() override;
	virtual bool isFinished() {return false;}
	virtual $String* toString() override;
};

				} // common
			} // http
		} // net
	} // internal
} // jdk

#endif // _jdk_internal_net_http_common_FlowTube_h_