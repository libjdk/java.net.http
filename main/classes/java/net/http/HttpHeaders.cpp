#include <java/net/http/HttpHeaders.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/AbstractCollection.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Optional.h>
#include <java/util/OptionalLong.h>
#include <java/util/Set.h>
#include <java/util/TreeMap.h>
#include <java/util/TreeSet.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/ToLongFunction.h>
#include <java/util/stream/LongStream.h>
#include <java/util/stream/Stream.h>
#include <jcpp.h>

#undef CASE_INSENSITIVE_ORDER
#undef NO_HEADERS
#undef ROOT

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Iterable = ::java::lang::Iterable;
using $Long = ::java::lang::Long;
using $MethodInfo = ::java::lang::MethodInfo;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $AbstractCollection = ::java::util::AbstractCollection;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Optional = ::java::util::Optional;
using $OptionalLong = ::java::util::OptionalLong;
using $Set = ::java::util::Set;
using $TreeMap = ::java::util::TreeMap;
using $TreeSet = ::java::util::TreeSet;
using $BiConsumer = ::java::util::function::BiConsumer;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Consumer = ::java::util::function::Consumer;
using $ToLongFunction = ::java::util::function::ToLongFunction;
using $LongStream = ::java::util::stream::LongStream;
using $Stream = ::java::util::stream::Stream;

namespace java {
	namespace net {
		namespace http {

class HttpHeaders$$Lambda$valueOf : public $ToLongFunction {
	$class(HttpHeaders$$Lambda$valueOf, $NO_CLASS_INIT, $ToLongFunction)
public:
	void init$() {
	}
	virtual int64_t applyAsLong(Object$* arg0) override {
		 return $longValue($Long::valueOf($cast($String, arg0)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpHeaders$$Lambda$valueOf>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpHeaders$$Lambda$valueOf::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpHeaders$$Lambda$valueOf::*)()>(&HttpHeaders$$Lambda$valueOf::init$))},
	{"applyAsLong", "(Ljava/lang/Object;)J", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpHeaders$$Lambda$valueOf::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpHeaders$$Lambda$valueOf",
	"java.lang.Object",
	"java.util.function.ToLongFunction",
	nullptr,
	methodInfos
};
$Class* HttpHeaders$$Lambda$valueOf::load$($String* name, bool initialize) {
	$loadClass(HttpHeaders$$Lambda$valueOf, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpHeaders$$Lambda$valueOf::class$ = nullptr;

class HttpHeaders$$Lambda$lambda$headersOf$1$1 : public $BiConsumer {
	$class(HttpHeaders$$Lambda$lambda$headersOf$1$1, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($BiPredicate* filter, $ArrayList* tempList, $TreeMap* other, $TreeSet* notAdded) {
		$set(this, filter, filter);
		$set(this, tempList, tempList);
		$set(this, other, other);
		$set(this, notAdded, notAdded);
	}
	virtual void accept(Object$* key, Object$* value) override {
		HttpHeaders::lambda$headersOf$1(filter, tempList, other, notAdded, $cast($String, key), $cast($List, value));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpHeaders$$Lambda$lambda$headersOf$1$1>());
	}
	$BiPredicate* filter = nullptr;
	$ArrayList* tempList = nullptr;
	$TreeMap* other = nullptr;
	$TreeSet* notAdded = nullptr;
	static $FieldInfo fieldInfos[5];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpHeaders$$Lambda$lambda$headersOf$1$1::fieldInfos[5] = {
	{"filter", "Ljava/util/function/BiPredicate;", nullptr, $PUBLIC, $field(HttpHeaders$$Lambda$lambda$headersOf$1$1, filter)},
	{"tempList", "Ljava/util/ArrayList;", nullptr, $PUBLIC, $field(HttpHeaders$$Lambda$lambda$headersOf$1$1, tempList)},
	{"other", "Ljava/util/TreeMap;", nullptr, $PUBLIC, $field(HttpHeaders$$Lambda$lambda$headersOf$1$1, other)},
	{"notAdded", "Ljava/util/TreeSet;", nullptr, $PUBLIC, $field(HttpHeaders$$Lambda$lambda$headersOf$1$1, notAdded)},
	{}
};
$MethodInfo HttpHeaders$$Lambda$lambda$headersOf$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiPredicate;Ljava/util/ArrayList;Ljava/util/TreeMap;Ljava/util/TreeSet;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpHeaders$$Lambda$lambda$headersOf$1$1::*)($BiPredicate*,$ArrayList*,$TreeMap*,$TreeSet*)>(&HttpHeaders$$Lambda$lambda$headersOf$1$1::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpHeaders$$Lambda$lambda$headersOf$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpHeaders$$Lambda$lambda$headersOf$1$1",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* HttpHeaders$$Lambda$lambda$headersOf$1$1::load$($String* name, bool initialize) {
	$loadClass(HttpHeaders$$Lambda$lambda$headersOf$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpHeaders$$Lambda$lambda$headersOf$1$1::class$ = nullptr;

class HttpHeaders$$Lambda$lambda$headersOf$0$2 : public $Consumer {
	$class(HttpHeaders$$Lambda$lambda$headersOf$0$2, $NO_CLASS_INIT, $Consumer)
public:
	void init$($BiPredicate* filter, $String* headerName, $ArrayList* tempList) {
		$set(this, filter, filter);
		$set(this, headerName, headerName);
		$set(this, tempList, tempList);
	}
	virtual void accept(Object$* headerValue) override {
		HttpHeaders::lambda$headersOf$0(filter, headerName, tempList, $cast($String, headerValue));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpHeaders$$Lambda$lambda$headersOf$0$2>());
	}
	$BiPredicate* filter = nullptr;
	$String* headerName = nullptr;
	$ArrayList* tempList = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HttpHeaders$$Lambda$lambda$headersOf$0$2::fieldInfos[4] = {
	{"filter", "Ljava/util/function/BiPredicate;", nullptr, $PUBLIC, $field(HttpHeaders$$Lambda$lambda$headersOf$0$2, filter)},
	{"headerName", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HttpHeaders$$Lambda$lambda$headersOf$0$2, headerName)},
	{"tempList", "Ljava/util/ArrayList;", nullptr, $PUBLIC, $field(HttpHeaders$$Lambda$lambda$headersOf$0$2, tempList)},
	{}
};
$MethodInfo HttpHeaders$$Lambda$lambda$headersOf$0$2::methodInfos[3] = {
	{"<init>", "(Ljava/util/function/BiPredicate;Ljava/lang/String;Ljava/util/ArrayList;)V", nullptr, $PUBLIC, $method(static_cast<void(HttpHeaders$$Lambda$lambda$headersOf$0$2::*)($BiPredicate*,$String*,$ArrayList*)>(&HttpHeaders$$Lambda$lambda$headersOf$0$2::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpHeaders$$Lambda$lambda$headersOf$0$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"java.net.http.HttpHeaders$$Lambda$lambda$headersOf$0$2",
	"java.lang.Object",
	"java.util.function.Consumer",
	fieldInfos,
	methodInfos
};
$Class* HttpHeaders$$Lambda$lambda$headersOf$0$2::load$($String* name, bool initialize) {
	$loadClass(HttpHeaders$$Lambda$lambda$headersOf$0$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpHeaders$$Lambda$lambda$headersOf$0$2::class$ = nullptr;

$FieldInfo _HttpHeaders_FieldInfo_[] = {
	{"NO_HEADERS", "Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HttpHeaders, NO_HEADERS)},
	{"headers", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PRIVATE | $FINAL, $field(HttpHeaders, headers)},
	{}
};

$MethodInfo _HttpHeaders_MethodInfo_[] = {
	{"<init>", "(Ljava/util/Map;)V", "(Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;)V", $PRIVATE, $method(static_cast<void(HttpHeaders::*)($Map*)>(&HttpHeaders::init$))},
	{"allValues", "(Ljava/lang/String;)Ljava/util/List;", "(Ljava/lang/String;)Ljava/util/List<Ljava/lang/String;>;", $PUBLIC, $method(static_cast<$List*(HttpHeaders::*)($String*)>(&HttpHeaders::allValues))},
	{"entryHash", "(Ljava/util/Map$Entry;)I", "(Ljava/util/Map$Entry<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;)I", $PRIVATE | $STATIC | $FINAL, $method(static_cast<int32_t(*)($Map$Entry*)>(&HttpHeaders::entryHash))},
	{"equals", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC | $FINAL},
	{"firstValue", "(Ljava/lang/String;)Ljava/util/Optional;", "(Ljava/lang/String;)Ljava/util/Optional<Ljava/lang/String;>;", $PUBLIC, $method(static_cast<$Optional*(HttpHeaders::*)($String*)>(&HttpHeaders::firstValue))},
	{"firstValueAsLong", "(Ljava/lang/String;)Ljava/util/OptionalLong;", nullptr, $PUBLIC, $method(static_cast<$OptionalLong*(HttpHeaders::*)($String*)>(&HttpHeaders::firstValueAsLong))},
	{"hashCode", "()I", nullptr, $PUBLIC | $FINAL},
	{"headersOf", "(Ljava/util/Map;Ljava/util/function/BiPredicate;)Ljava/net/http/HttpHeaders;", "(Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;)Ljava/net/http/HttpHeaders;", $PRIVATE | $STATIC, $method(static_cast<HttpHeaders*(*)($Map*,$BiPredicate*)>(&HttpHeaders::headersOf))},
	{"lambda$headersOf$0", "(Ljava/util/function/BiPredicate;Ljava/lang/String;Ljava/util/ArrayList;Ljava/lang/String;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($BiPredicate*,$String*,$ArrayList*,$String*)>(&HttpHeaders::lambda$headersOf$0))},
	{"lambda$headersOf$1", "(Ljava/util/function/BiPredicate;Ljava/util/ArrayList;Ljava/util/TreeMap;Ljava/util/TreeSet;Ljava/lang/String;Ljava/util/List;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($BiPredicate*,$ArrayList*,$TreeMap*,$TreeSet*,$String*,$List*)>(&HttpHeaders::lambda$headersOf$1))},
	{"map", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PUBLIC, $method(static_cast<$Map*(HttpHeaders::*)()>(&HttpHeaders::map))},
	{"of", "(Ljava/util/Map;Ljava/util/function/BiPredicate;)Ljava/net/http/HttpHeaders;", "(Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;)Ljava/net/http/HttpHeaders;", $PUBLIC | $STATIC, $method(static_cast<HttpHeaders*(*)($Map*,$BiPredicate*)>(&HttpHeaders::of))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _HttpHeaders_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"java.net.http.HttpHeaders",
	"java.lang.Object",
	nullptr,
	_HttpHeaders_FieldInfo_,
	_HttpHeaders_MethodInfo_
};

$Object* allocate$HttpHeaders($Class* clazz) {
	return $of($alloc(HttpHeaders));
}

HttpHeaders* HttpHeaders::NO_HEADERS = nullptr;

$Optional* HttpHeaders::firstValue($String* name) {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($(allValues(name)))->stream()))->findFirst();
}

$OptionalLong* HttpHeaders::firstValueAsLong($String* name) {
	$useLocalCurrentObjectStackCache();
	return $nc($($nc($($nc($(allValues(name)))->stream()))->mapToLong(static_cast<$ToLongFunction*>($$new(HttpHeaders$$Lambda$valueOf)))))->findFirst();
}

$List* HttpHeaders::allValues($String* name) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull(name);
	$var($List, values, $cast($List, $nc($(map()))->get(name)));
	return values != nullptr ? values : $List::of();
}

$Map* HttpHeaders::map() {
	return this->headers;
}

bool HttpHeaders::equals(Object$* obj) {
	$useLocalCurrentObjectStackCache();
	if (!($instanceOf(HttpHeaders, obj))) {
		return false;
	}
	$var(HttpHeaders, that, $cast(HttpHeaders, obj));
	return $nc($(this->map()))->equals($($nc(that)->map()));
}

int32_t HttpHeaders::hashCode() {
	$useLocalCurrentObjectStackCache();
	int32_t h = 0;
	{
		$var($Iterator, i$, $nc($($nc($(map()))->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
			{
				h += entryHash(e);
			}
		}
	}
	return h;
}

$String* HttpHeaders::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($Object::toString()))->append(" { "_s);
	sb->append($($of(map())));
	sb->append(" }"_s);
	return sb->toString();
}

HttpHeaders* HttpHeaders::of($Map* headerMap, $BiPredicate* filter) {
	$init(HttpHeaders);
	$Objects::requireNonNull(headerMap);
	$Objects::requireNonNull(filter);
	return headersOf(headerMap, filter);
}

void HttpHeaders::init$($Map* headers) {
	$set(this, headers, headers);
}

int32_t HttpHeaders::entryHash($Map$Entry* e) {
	$init(HttpHeaders);
	$useLocalCurrentObjectStackCache();
	$var($String, key, $cast($String, $nc(e)->getKey()));
	$var($List, value, $cast($List, e->getValue()));
	$init($Locale);
	int32_t keyHash = $($nc(key)->toLowerCase($Locale::ROOT))->hashCode();
	int32_t valueHash = $nc(value)->hashCode();
	return keyHash ^ valueHash;
}

HttpHeaders* HttpHeaders::headersOf($Map* map, $BiPredicate* filter) {
	$init(HttpHeaders);
	$useLocalCurrentObjectStackCache();
	$var($TreeMap, other, $new($TreeMap, $String::CASE_INSENSITIVE_ORDER));
	$var($TreeSet, notAdded, $new($TreeSet, $String::CASE_INSENSITIVE_ORDER));
	$var($ArrayList, tempList, $new($ArrayList));
	$nc(map)->forEach(static_cast<$BiConsumer*>($$new(HttpHeaders$$Lambda$lambda$headersOf$1$1, filter, tempList, other, notAdded)));
	return other->isEmpty() ? HttpHeaders::NO_HEADERS : $new(HttpHeaders, $($Collections::unmodifiableMap(static_cast<$Map*>(static_cast<$AbstractMap*>(other)))));
}

void HttpHeaders::lambda$headersOf$1($BiPredicate* filter, $ArrayList* tempList, $TreeMap* other, $TreeSet* notAdded, $String* key, $List* value) {
	$init(HttpHeaders);
	$useLocalCurrentObjectStackCache();
	$var($String, headerName, $nc(($cast($String, $Objects::requireNonNull(key))))->trim());
	if (headerName->isEmpty()) {
		$throwNew($IllegalArgumentException, "empty key"_s);
	}
	$var($List, headerValues, $cast($List, $Objects::requireNonNull(value)));
	$nc(headerValues)->forEach(static_cast<$Consumer*>($$new(HttpHeaders$$Lambda$lambda$headersOf$0$2, filter, headerName, tempList)));
	if ($nc(tempList)->isEmpty()) {
		bool var$0 = $nc(other)->containsKey(headerName);
		$init($Locale);
		if (var$0 || $nc(notAdded)->contains($(headerName->toLowerCase($Locale::ROOT)))) {
			$throwNew($IllegalArgumentException, $$str({"duplicate key: "_s, headerName}));
		}
		$nc(notAdded)->add($(headerName->toLowerCase($Locale::ROOT)));
	} else if ($nc(other)->put(headerName, $($List::copyOf(static_cast<$Collection*>(static_cast<$AbstractCollection*>(static_cast<$AbstractList*>(tempList)))))) != nullptr) {
		$throwNew($IllegalArgumentException, $$str({"duplicate key: "_s, headerName}));
	}
	$nc(tempList)->clear();
}

void HttpHeaders::lambda$headersOf$0($BiPredicate* filter, $String* headerName, $ArrayList* tempList, $String* headerValue$renamed) {
	$init(HttpHeaders);
	$var($String, headerValue, headerValue$renamed);
	$assign(headerValue, $nc(($cast($String, $Objects::requireNonNull(headerValue))))->trim());
	if ($nc(filter)->test(headerName, headerValue)) {
		$nc(tempList)->add(headerValue);
	}
}

void clinit$HttpHeaders($Class* class$) {
	$assignStatic(HttpHeaders::NO_HEADERS, $new(HttpHeaders, $($Map::of())));
}

HttpHeaders::HttpHeaders() {
}

$Class* HttpHeaders::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpHeaders$$Lambda$valueOf::classInfo$.name)) {
			return HttpHeaders$$Lambda$valueOf::load$(name, initialize);
		}
		if (name->equals(HttpHeaders$$Lambda$lambda$headersOf$1$1::classInfo$.name)) {
			return HttpHeaders$$Lambda$lambda$headersOf$1$1::load$(name, initialize);
		}
		if (name->equals(HttpHeaders$$Lambda$lambda$headersOf$0$2::classInfo$.name)) {
			return HttpHeaders$$Lambda$lambda$headersOf$0$2::load$(name, initialize);
		}
	}
	$loadClass(HttpHeaders, name, initialize, &_HttpHeaders_ClassInfo_, clinit$HttpHeaders, allocate$HttpHeaders);
	return class$;
}

$Class* HttpHeaders::class$ = nullptr;

		} // http
	} // net
} // java