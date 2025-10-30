#include <jdk/internal/net/http/ConnectionPool$CleanupTrigger.h>

#include <java/io/IOException.h>
#include <java/util/List.h>
#include <java/util/concurrent/Flow$Subscriber.h>
#include <java/util/concurrent/Flow$Subscription.h>
#include <jdk/internal/net/http/ConnectionPool.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $List = ::java::util::List;
using $Flow$Subscriber = ::java::util::concurrent::Flow$Subscriber;
using $Flow$Subscription = ::java::util::concurrent::Flow$Subscription;
using $ConnectionPool = ::jdk::internal::net::http::ConnectionPool;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _ConnectionPool$CleanupTrigger_FieldInfo_[] = {
	{"this$0", "Ljdk/internal/net/http/ConnectionPool;", nullptr, $FINAL | $SYNTHETIC, $field(ConnectionPool$CleanupTrigger, this$0)},
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $PRIVATE | $FINAL, $field(ConnectionPool$CleanupTrigger, connection)},
	{"done", "Z", nullptr, $PRIVATE | $VOLATILE, $field(ConnectionPool$CleanupTrigger, done)},
	{}
};

$MethodInfo _ConnectionPool$CleanupTrigger_MethodInfo_[] = {
	{"*clone", "()Ljava/lang/Object;", nullptr, $PROTECTED | $NATIVE},
	{"*equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{"*finalize", "()V", nullptr, $PROTECTED | $DEPRECATED},
	{"*hashCode", "()I", nullptr, $PUBLIC | $NATIVE},
	{"<init>", "(Ljdk/internal/net/http/ConnectionPool;Ljdk/internal/net/http/HttpConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(ConnectionPool$CleanupTrigger::*)($ConnectionPool*,$HttpConnection*)>(&ConnectionPool$CleanupTrigger::init$))},
	{"cancel", "()V", nullptr, $PUBLIC},
	{"isDone", "()Z", nullptr, $PUBLIC, $method(static_cast<bool(ConnectionPool$CleanupTrigger::*)()>(&ConnectionPool$CleanupTrigger::isDone))},
	{"onComplete", "()V", nullptr, $PUBLIC},
	{"onError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"onNext", "(Ljava/util/List;)V", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(ConnectionPool$CleanupTrigger::*)($List*)>(&ConnectionPool$CleanupTrigger::onNext))},
	{"onNext", "(Ljava/lang/Object;)V", nullptr, $PUBLIC | $VOLATILE | $SYNTHETIC},
	{"onSubscribe", "(Ljava/util/concurrent/Flow$Subscription;)V", nullptr, $PUBLIC},
	{"request", "(J)V", nullptr, $PUBLIC},
	{"subscribe", "(Ljava/util/concurrent/Flow$Subscriber;)V", "(Ljava/util/concurrent/Flow$Subscriber<-Ljava/util/List<Ljava/nio/ByteBuffer;>;>;)V", $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"triggerCleanup", "(Ljava/lang/Throwable;)V", nullptr, $PRIVATE, $method(static_cast<void(ConnectionPool$CleanupTrigger::*)($Throwable*)>(&ConnectionPool$CleanupTrigger::triggerCleanup))},
	{}
};

$InnerClassInfo _ConnectionPool$CleanupTrigger_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.ConnectionPool$CleanupTrigger", "jdk.internal.net.http.ConnectionPool", "CleanupTrigger", $PRIVATE | $FINAL},
	{"jdk.internal.net.http.common.FlowTube$TubeSubscriber", "jdk.internal.net.http.common.FlowTube", "TubeSubscriber", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.common.FlowTube$TubePublisher", "jdk.internal.net.http.common.FlowTube", "TubePublisher", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{"java.util.concurrent.Flow$Subscription", "java.util.concurrent.Flow", "Subscription", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _ConnectionPool$CleanupTrigger_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.ConnectionPool$CleanupTrigger",
	"java.lang.Object",
	"jdk.internal.net.http.common.FlowTube$TubeSubscriber,jdk.internal.net.http.common.FlowTube$TubePublisher,java.util.concurrent.Flow$Subscription",
	_ConnectionPool$CleanupTrigger_FieldInfo_,
	_ConnectionPool$CleanupTrigger_MethodInfo_,
	nullptr,
	nullptr,
	_ConnectionPool$CleanupTrigger_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.ConnectionPool"
};

$Object* allocate$ConnectionPool$CleanupTrigger($Class* clazz) {
	return $of($alloc(ConnectionPool$CleanupTrigger));
}

int32_t ConnectionPool$CleanupTrigger::hashCode() {
	 return this->$FlowTube$TubeSubscriber::hashCode();
}

bool ConnectionPool$CleanupTrigger::equals(Object$* arg0) {
	 return this->$FlowTube$TubeSubscriber::equals(arg0);
}

$Object* ConnectionPool$CleanupTrigger::clone() {
	 return this->$FlowTube$TubeSubscriber::clone();
}

void ConnectionPool$CleanupTrigger::finalize() {
	this->$FlowTube$TubeSubscriber::finalize();
}

void ConnectionPool$CleanupTrigger::init$($ConnectionPool* this$0, $HttpConnection* connection) {
	$set(this, this$0, this$0);
	$set(this, connection, connection);
}

bool ConnectionPool$CleanupTrigger::isDone() {
	return this->done;
}

void ConnectionPool$CleanupTrigger::triggerCleanup($Throwable* error) {
	this->done = true;
	this->this$0->cleanup(this->connection, error);
}

void ConnectionPool$CleanupTrigger::request(int64_t n) {
}

void ConnectionPool$CleanupTrigger::cancel() {
}

void ConnectionPool$CleanupTrigger::onSubscribe($Flow$Subscription* subscription) {
	$nc(subscription)->request(1);
}

void ConnectionPool$CleanupTrigger::onError($Throwable* error) {
	triggerCleanup(error);
}

void ConnectionPool$CleanupTrigger::onComplete() {
	triggerCleanup(nullptr);
}

void ConnectionPool$CleanupTrigger::onNext($List* item) {
	triggerCleanup($$new($IOException, "Data received while in pool"_s));
}

void ConnectionPool$CleanupTrigger::subscribe($Flow$Subscriber* subscriber) {
	$nc(subscriber)->onSubscribe(this);
}

$String* ConnectionPool$CleanupTrigger::toString() {
	return $str({"CleanupTrigger("_s, $($nc(this->connection)->getConnectionFlow()), ")"_s});
}

void ConnectionPool$CleanupTrigger::onNext(Object$* item) {
	this->onNext($cast($List, item));
}

ConnectionPool$CleanupTrigger::ConnectionPool$CleanupTrigger() {
}

$Class* ConnectionPool$CleanupTrigger::load$($String* name, bool initialize) {
	$loadClass(ConnectionPool$CleanupTrigger, name, initialize, &_ConnectionPool$CleanupTrigger_ClassInfo_, allocate$ConnectionPool$CleanupTrigger);
	return class$;
}

$Class* ConnectionPool$CleanupTrigger::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk