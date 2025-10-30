#include <jdk/internal/net/http/hpack/HeaderTable.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/AbstractMap.h>
#include <java/util/Collection.h>
#include <java/util/Deque.h>
#include <java/util/HashMap.h>
#include <java/util/Iterator.h>
#include <java/util/LinkedList.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger.h>
#include <jdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField.h>
#include <jdk/internal/net/http/hpack/SimpleHeaderTable.h>
#include <jcpp.h>

#undef STATIC_TABLE_LENGTH

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $Integer = ::java::lang::Integer;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AbstractMap = ::java::util::AbstractMap;
using $Collection = ::java::util::Collection;
using $Deque = ::java::util::Deque;
using $HashMap = ::java::util::HashMap;
using $Iterator = ::java::util::Iterator;
using $LinkedList = ::java::util::LinkedList;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Function = ::java::util::function::Function;
using $HPACK$Logger = ::jdk::internal::net::http::hpack::HPACK$Logger;
using $SimpleHeaderTable = ::jdk::internal::net::http::hpack::SimpleHeaderTable;
using $SimpleHeaderTable$HeaderField = ::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class HeaderTable$$Lambda$lambda$static$0 : public $Function {
	$class(HeaderTable$$Lambda$lambda$static$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* k) override {
		 return $of(HeaderTable::lambda$static$0($cast($String, k)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HeaderTable$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HeaderTable$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HeaderTable$$Lambda$lambda$static$0::*)()>(&HeaderTable$$Lambda$lambda$static$0::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HeaderTable$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.HeaderTable$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* HeaderTable$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(HeaderTable$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HeaderTable$$Lambda$lambda$static$0::class$ = nullptr;

class HeaderTable$$Lambda$lambda$add$2$1 : public $Function {
	$class(HeaderTable$$Lambda$lambda$add$2$1, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* k) override {
		 return $of(HeaderTable::lambda$add$2($cast($String, k)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HeaderTable$$Lambda$lambda$add$2$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HeaderTable$$Lambda$lambda$add$2$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HeaderTable$$Lambda$lambda$add$2$1::*)()>(&HeaderTable$$Lambda$lambda$add$2$1::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HeaderTable$$Lambda$lambda$add$2$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.HeaderTable$$Lambda$lambda$add$2$1",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* HeaderTable$$Lambda$lambda$add$2$1::load$($String* name, bool initialize) {
	$loadClass(HeaderTable$$Lambda$lambda$add$2$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HeaderTable$$Lambda$lambda$add$2$1::class$ = nullptr;

$FieldInfo _HeaderTable_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HeaderTable, $assertionsDisabled)},
	{"staticIndexes", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/lang/Integer;>;>;", $PRIVATE | $STATIC | $FINAL, $staticField(HeaderTable, staticIndexes)},
	{"map", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/Map<Ljava/lang/String;Ljava/util/Deque<Ljava/lang/Long;>;>;>;", $PRIVATE | $FINAL, $field(HeaderTable, map)},
	{"counter", "J", nullptr, $PRIVATE, $field(HeaderTable, counter)},
	{}
};

$MethodInfo _HeaderTable_MethodInfo_[] = {
	{"<init>", "(ILjdk/internal/net/http/hpack/HPACK$Logger;)V", nullptr, $PUBLIC, $method(static_cast<void(HeaderTable::*)(int32_t,$HPACK$Logger*)>(&HeaderTable::init$))},
	{"add", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;)V", nullptr, $PROTECTED},
	{"indexOf", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)I", nullptr, $PUBLIC, $method(static_cast<int32_t(HeaderTable::*)($CharSequence*,$CharSequence*)>(&HeaderTable::indexOf))},
	{"indexesUniqueAndOrdered", "(Ljava/util/Deque;)Z", "(Ljava/util/Deque<Ljava/lang/Long;>;)Z", $PRIVATE, $method(static_cast<bool(HeaderTable::*)($Deque*)>(&HeaderTable::indexesUniqueAndOrdered))},
	{"lambda$add$2", "(Ljava/lang/String;)Ljava/util/Deque;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Deque*(*)($String*)>(&HeaderTable::lambda$add$2))},
	{"lambda$static$0", "(Ljava/lang/String;)Ljava/util/Map;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Map*(*)($String*)>(&HeaderTable::lambda$static$0))},
	{"remove", "()Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;", nullptr, $PROTECTED},
	{"search", "(Ljava/lang/String;Ljava/lang/String;)I", nullptr, 0, $method(static_cast<int32_t(HeaderTable::*)($String*,$String*)>(&HeaderTable::search))},
	{}
};

$ClassInfo _HeaderTable_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.HeaderTable",
	"jdk.internal.net.http.hpack.SimpleHeaderTable",
	nullptr,
	_HeaderTable_FieldInfo_,
	_HeaderTable_MethodInfo_
};

$Object* allocate$HeaderTable($Class* clazz) {
	return $of($alloc(HeaderTable));
}

bool HeaderTable::$assertionsDisabled = false;
$Map* HeaderTable::staticIndexes = nullptr;

void HeaderTable::init$(int32_t maxSize, $HPACK$Logger* logger) {
	$SimpleHeaderTable::init$(maxSize, logger);
	this->counter = 1;
	$set(this, map, $new($HashMap));
}

int32_t HeaderTable::indexOf($CharSequence* name, $CharSequence* value) {
	$useLocalCurrentObjectStackCache();
	$var($String, n, $nc(name)->toString());
	$var($String, v, $nc(value)->toString());
	$var($Map, values, $cast($Map, $nc(HeaderTable::staticIndexes)->get(n)));
	if (values != nullptr) {
		$var($Integer, idx, $cast($Integer, values->get(v)));
		if (idx != nullptr) {
			return idx->intValue();
		}
	}
	int32_t didx = search(n, v);
	if (didx > 0) {
		$init($SimpleHeaderTable);
		return $SimpleHeaderTable::STATIC_TABLE_LENGTH + didx;
	} else if (didx < 0) {
		if (values != nullptr) {
			return -$nc(($cast($Integer, $($nc($($nc($(values->values()))->iterator()))->next()))))->intValue();
		} else {
			$init($SimpleHeaderTable);
			return -$SimpleHeaderTable::STATIC_TABLE_LENGTH + didx;
		}
	} else if (values != nullptr) {
		return -$nc(($cast($Integer, $($nc($($nc($(values->values()))->iterator()))->next()))))->intValue();
	} else {
		return 0;
	}
}

void HeaderTable::add($SimpleHeaderTable$HeaderField* f) {
	$useLocalCurrentObjectStackCache();
	$SimpleHeaderTable::add(f);
	$var($Map, values, $cast($Map, $nc(this->map)->computeIfAbsent($nc(f)->name, static_cast<$Function*>($$new(HeaderTable$$Lambda$lambda$static$0)))));
	$var($Deque, indexes, $cast($Deque, $nc(values)->computeIfAbsent($nc(f)->value, static_cast<$Function*>($$new(HeaderTable$$Lambda$lambda$add$2$1)))));
	int64_t counterSnapshot = this->counter++;
	$nc(indexes)->add($($Long::valueOf(counterSnapshot)));
	if (!HeaderTable::$assertionsDisabled && !indexesUniqueAndOrdered(indexes)) {
		$throwNew($AssertionError);
	}
}

bool HeaderTable::indexesUniqueAndOrdered($Deque* indexes) {
	$useLocalCurrentObjectStackCache();
	int64_t maxIndexSoFar = -1;
	{
		$var($Iterator, i$, $nc(indexes)->iterator());
		for (; $nc(i$)->hasNext();) {
			int64_t l = $nc(($cast($Long, $(i$->next()))))->longValue();
			{
				if (l <= maxIndexSoFar) {
					return false;
				} else {
					maxIndexSoFar = l;
				}
			}
		}
	}
	return true;
}

int32_t HeaderTable::search($String* name, $String* value) {
	$useLocalCurrentObjectStackCache();
	$var($Map, values, $cast($Map, $nc(this->map)->get(name)));
	if (values == nullptr) {
		return 0;
	}
	$var($Deque, indexes, $cast($Deque, $nc(values)->get(value)));
	if (indexes != nullptr) {
		return (int32_t)(this->counter - $nc(($cast($Long, $(indexes->peekLast()))))->longValue());
	} else {
		if (!HeaderTable::$assertionsDisabled && ! !values->isEmpty()) {
			$throwNew($AssertionError);
		}
		$var($Long, any, $cast($Long, $nc(($cast($Deque, $($nc($($nc($(values->values()))->iterator()))->next()))))->peekLast()));
		return -(int32_t)(this->counter - $nc(any)->longValue());
	}
}

$SimpleHeaderTable$HeaderField* HeaderTable::remove() {
	$useLocalCurrentObjectStackCache();
	$var($SimpleHeaderTable$HeaderField, f, $SimpleHeaderTable::remove());
	$var($Map, values, $cast($Map, $nc(this->map)->get($nc(f)->name)));
	$var($Deque, indexes, $cast($Deque, $nc(values)->get($nc(f)->value)));
	$var($Long, index, $cast($Long, $nc(indexes)->pollFirst()));
	if (indexes->isEmpty()) {
		values->remove($nc(f)->value);
	}
	if (!HeaderTable::$assertionsDisabled && !(index != nullptr)) {
		$throwNew($AssertionError);
	}
	if (values->isEmpty()) {
		$nc(this->map)->remove($nc(f)->name);
	}
	return f;
}

$Deque* HeaderTable::lambda$add$2($String* k) {
	$init(HeaderTable);
	return $new($LinkedList);
}

$Map* HeaderTable::lambda$static$0($String* k) {
	$init(HeaderTable);
	return $new($HashMap);
}

void clinit$HeaderTable($Class* class$) {
	$useLocalCurrentObjectStackCache();
	HeaderTable::$assertionsDisabled = !HeaderTable::class$->desiredAssertionStatus();
	{
		$init($SimpleHeaderTable);
		$var($Map, map, $new($HashMap, $SimpleHeaderTable::STATIC_TABLE_LENGTH));
		for (int32_t i = 1; i <= $SimpleHeaderTable::STATIC_TABLE_LENGTH; ++i) {
			$var($SimpleHeaderTable$HeaderField, f, $cast($SimpleHeaderTable$HeaderField, $nc($SimpleHeaderTable::staticTable)->get(i)));
			$var($Map, values, $cast($Map, map->computeIfAbsent($nc(f)->name, static_cast<$Function*>($$new(HeaderTable$$Lambda$lambda$static$0)))));
			$nc(values)->put($nc(f)->value, $($Integer::valueOf(i)));
		}
		$var($Map, copy, $new($HashMap, map->size()));
		{
			$var($Iterator, i$, $nc($(map->entrySet()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
				{
					$var($Object, var$0, $cast($String, $nc(e)->getKey()));
					copy->put(var$0, $($Map::copyOf($cast($Map, $(e->getValue())))));
				}
			}
		}
		$assignStatic(HeaderTable::staticIndexes, $Map::copyOf(copy));
	}
}

HeaderTable::HeaderTable() {
}

$Class* HeaderTable::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HeaderTable$$Lambda$lambda$static$0::classInfo$.name)) {
			return HeaderTable$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(HeaderTable$$Lambda$lambda$add$2$1::classInfo$.name)) {
			return HeaderTable$$Lambda$lambda$add$2$1::load$(name, initialize);
		}
	}
	$loadClass(HeaderTable, name, initialize, &_HeaderTable_ClassInfo_, clinit$HeaderTable, allocate$HeaderTable);
	return class$;
}

$Class* HeaderTable::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk