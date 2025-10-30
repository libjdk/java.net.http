#include <jdk/internal/net/http/FilterFactory.h>

#include <java/lang/InternalError.h>
#include <java/lang/ReflectiveOperationException.h>
#include <java/lang/reflect/Constructor.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <jdk/internal/net/http/HeaderFilter.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $ReflectiveOperationException = ::java::lang::ReflectiveOperationException;
using $Constructor = ::java::lang::reflect::Constructor;
using $AbstractSequentialList = ::java::util::AbstractSequentialList;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $HeaderFilter = ::jdk::internal::net::http::HeaderFilter;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _FilterFactory_FieldInfo_[] = {
	{"filterClasses", "Ljava/util/LinkedList;", "Ljava/util/LinkedList<Ljava/lang/Class<+Ljdk/internal/net/http/HeaderFilter;>;>;", $FINAL, $field(FilterFactory, filterClasses)},
	{}
};

$MethodInfo _FilterFactory_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(FilterFactory::*)()>(&FilterFactory::init$))},
	{"addFilter", "(Ljava/lang/Class;)V", "(Ljava/lang/Class<+Ljdk/internal/net/http/HeaderFilter;>;)V", $PUBLIC},
	{"getFilterChain", "()Ljava/util/LinkedList;", "()Ljava/util/LinkedList<Ljdk/internal/net/http/HeaderFilter;>;", 0},
	{}
};

$ClassInfo _FilterFactory_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.FilterFactory",
	"java.lang.Object",
	nullptr,
	_FilterFactory_FieldInfo_,
	_FilterFactory_MethodInfo_
};

$Object* allocate$FilterFactory($Class* clazz) {
	return $of($alloc(FilterFactory));
}

void FilterFactory::init$() {
	$set(this, filterClasses, $new($LinkedList));
}

void FilterFactory::addFilter($Class* type) {
	$nc(this->filterClasses)->add(type);
}

$LinkedList* FilterFactory::getFilterChain() {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	$var($LinkedList, l, $new($LinkedList));
	{
		$var($Iterator, i$, $nc(this->filterClasses)->iterator());
		for (; $nc(i$)->hasNext();) {
			$Class* clazz = $cast($Class, i$->next());
			{
				try {
					$var($HeaderFilter, headerFilter, $cast($HeaderFilter, $nc($($nc(clazz)->getConstructor($$new($ClassArray, 0))))->newInstance($$new($ObjectArray, 0))));
					l->add(headerFilter);
				} catch ($ReflectiveOperationException& e) {
					$throwNew($InternalError, static_cast<$Throwable*>(e));
				}
			}
		}
	}
	return l;
}

FilterFactory::FilterFactory() {
}

$Class* FilterFactory::load$($String* name, bool initialize) {
	$loadClass(FilterFactory, name, initialize, &_FilterFactory_ClassInfo_, allocate$FilterFactory);
	return class$;
}

$Class* FilterFactory::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk