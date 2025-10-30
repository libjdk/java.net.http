#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitor.h>

#include <java/lang/InterruptedException.h>
#include <java/lang/ref/Reference.h>
#include <java/lang/ref/ReferenceQueue.h>
#include <java/lang/ref/WeakReference.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractSequentialList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collections.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitor$FinalMonitorable.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitorable.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate.h>
#include <jcpp.h>

using $PrintStream = ::java::io::PrintStream;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InterruptedException = ::java::lang::InterruptedException;
using $MethodInfo = ::java::lang::MethodInfo;
using $Reference = ::java::lang::ref::Reference;
using $ReferenceQueue = ::java::lang::ref::ReferenceQueue;
using $WeakReference = ::java::lang::ref::WeakReference;
using $AbstractList = ::java::util::AbstractList;
using $AbstractSequentialList = ::java::util::AbstractSequentialList;
using $ArrayList = ::java::util::ArrayList;
using $Collections = ::java::util::Collections;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $SSLFlowDelegate = ::jdk::internal::net::http::common::SSLFlowDelegate;
using $SSLFlowDelegate$Monitor$FinalMonitorable = ::jdk::internal::net::http::common::SSLFlowDelegate$Monitor$FinalMonitorable;
using $SSLFlowDelegate$Monitorable = ::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _SSLFlowDelegate$Monitor_FieldInfo_[] = {
	{"list", "Ljava/util/List;", "Ljava/util/List<Ljava/lang/ref/WeakReference<Ljdk/internal/net/http/common/SSLFlowDelegate$Monitorable;>;>;", $FINAL, $field(SSLFlowDelegate$Monitor, list)},
	{"finalList", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/net/http/common/SSLFlowDelegate$Monitor$FinalMonitorable;>;", $FINAL, $field(SSLFlowDelegate$Monitor, finalList)},
	{"queue", "Ljava/lang/ref/ReferenceQueue;", "Ljava/lang/ref/ReferenceQueue<Ljdk/internal/net/http/common/SSLFlowDelegate$Monitorable;>;", $FINAL, $field(SSLFlowDelegate$Monitor, queue)},
	{"themon", "Ljdk/internal/net/http/common/SSLFlowDelegate$Monitor;", nullptr, $STATIC, $staticField(SSLFlowDelegate$Monitor, themon)},
	{}
};

$MethodInfo _SSLFlowDelegate$Monitor_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(SSLFlowDelegate$Monitor::*)()>(&SSLFlowDelegate$Monitor::init$))},
	{"add", "(Ljdk/internal/net/http/common/SSLFlowDelegate$Monitorable;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($SSLFlowDelegate$Monitorable*)>(&SSLFlowDelegate$Monitor::add))},
	{"addTarget", "(Ljdk/internal/net/http/common/SSLFlowDelegate$Monitorable;)V", nullptr, 0},
	{"remove", "(Ljdk/internal/net/http/common/SSLFlowDelegate$Monitorable;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($SSLFlowDelegate$Monitorable*)>(&SSLFlowDelegate$Monitor::remove))},
	{"removeTarget", "(Ljdk/internal/net/http/common/SSLFlowDelegate$Monitorable;)V", nullptr, 0},
	{"run", "()V", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SSLFlowDelegate$Monitor_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.SSLFlowDelegate$Monitor", "jdk.internal.net.http.common.SSLFlowDelegate", "Monitor", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.common.SSLFlowDelegate$Monitor$FinalMonitorable", "jdk.internal.net.http.common.SSLFlowDelegate$Monitor", "FinalMonitorable", $FINAL},
	{}
};

$ClassInfo _SSLFlowDelegate$Monitor_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.common.SSLFlowDelegate$Monitor",
	"java.lang.Thread",
	nullptr,
	_SSLFlowDelegate$Monitor_FieldInfo_,
	_SSLFlowDelegate$Monitor_MethodInfo_,
	nullptr,
	nullptr,
	_SSLFlowDelegate$Monitor_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.SSLFlowDelegate"
};

$Object* allocate$SSLFlowDelegate$Monitor($Class* clazz) {
	return $of($alloc(SSLFlowDelegate$Monitor));
}

SSLFlowDelegate$Monitor* SSLFlowDelegate$Monitor::themon = nullptr;

void SSLFlowDelegate$Monitor::init$() {
	$Thread::init$("Monitor"_s);
	$set(this, queue, $new($ReferenceQueue));
	setDaemon(true);
	$set(this, list, $Collections::synchronizedList($$new($LinkedList)));
	$set(this, finalList, $new($ArrayList));
}

void SSLFlowDelegate$Monitor::addTarget($SSLFlowDelegate$Monitorable* o) {
	$nc(this->list)->add($$new($WeakReference, o, this->queue));
}

void SSLFlowDelegate$Monitor::removeTarget($SSLFlowDelegate$Monitorable* o) {
	$useLocalCurrentObjectStackCache();
	$synchronized(this->list) {
		$var($Iterator, it, $nc(this->list)->iterator());
		while ($nc(it)->hasNext()) {
			$var($SSLFlowDelegate$Monitorable, m, $cast($SSLFlowDelegate$Monitorable, $nc(($cast($WeakReference, $(it->next()))))->get()));
			if (m == nullptr) {
				it->remove();
			}
			if (o == m) {
				it->remove();
				break;
			}
		}
		$var($SSLFlowDelegate$Monitor$FinalMonitorable, m, $new($SSLFlowDelegate$Monitor$FinalMonitorable, this, o));
		addTarget(m);
		$Reference::reachabilityFence(m);
	}
}

void SSLFlowDelegate$Monitor::add($SSLFlowDelegate$Monitorable* o) {
	$init(SSLFlowDelegate$Monitor);
	$nc(SSLFlowDelegate$Monitor::themon)->addTarget(o);
}

void SSLFlowDelegate$Monitor::remove($SSLFlowDelegate$Monitorable* o) {
	$init(SSLFlowDelegate$Monitor);
	$nc(SSLFlowDelegate$Monitor::themon)->removeTarget(o);
}

void SSLFlowDelegate$Monitor::run() {
	$useLocalCurrentObjectStackCache();
	$nc($System::out)->println("Monitor starting"_s);
	try {
		while (true) {
			$Thread::sleep(20 * 1000);
			$synchronized(this->list) {
				$var($Reference, expired, nullptr);
				while (($assign(expired, $nc(this->queue)->poll())) != nullptr) {
					$nc(this->list)->remove($of(expired));
				}
				{
					$var($Iterator, i$, $nc(this->list)->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($WeakReference, ref, $cast($WeakReference, i$->next()));
						{
							$var($SSLFlowDelegate$Monitorable, o, $cast($SSLFlowDelegate$Monitorable, $nc(ref)->get()));
							if (o == nullptr) {
								continue;
							}
							if ($instanceOf($SSLFlowDelegate$Monitor$FinalMonitorable, o)) {
								ref->enqueue();
							}
							$nc($System::out)->println($($nc(o)->getInfo()));
							$nc($System::out)->println("-------------------------"_s);
						}
					}
				}
			}
			$nc($System::out)->println("--o-o-o-o-o-o-o-o-o-o-o-o-o-o-"_s);
		}
	} catch ($InterruptedException& e) {
		$nc($System::out)->println($$str({"Monitor exiting with "_s, e}));
	}
}

void clinit$SSLFlowDelegate$Monitor($Class* class$) {
	{
		$assignStatic(SSLFlowDelegate$Monitor::themon, $new(SSLFlowDelegate$Monitor));
		$nc(SSLFlowDelegate$Monitor::themon)->start();
	}
}

SSLFlowDelegate$Monitor::SSLFlowDelegate$Monitor() {
}

$Class* SSLFlowDelegate$Monitor::load$($String* name, bool initialize) {
	$loadClass(SSLFlowDelegate$Monitor, name, initialize, &_SSLFlowDelegate$Monitor_ClassInfo_, clinit$SSLFlowDelegate$Monitor, allocate$SSLFlowDelegate$Monitor);
	return class$;
}

$Class* SSLFlowDelegate$Monitor::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk