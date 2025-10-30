#include <jdk/internal/net/http/common/HttpHeadersBuilder.h>

#include <java/io/Serializable.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/http/HttpHeaders.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Comparator.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/TreeMap.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef ACCEPT_ALL
#undef CASE_INSENSITIVE_ORDER

using $Serializable = ::java::io::Serializable;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Comparator = ::java::util::Comparator;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $TreeMap = ::java::util::TreeMap;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Function = ::java::util::function::Function;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class HttpHeadersBuilder$$Lambda$lambda$addHeader$0 : public $Function {
	$class(HttpHeadersBuilder$$Lambda$lambda$addHeader$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* k) override {
		 return $of(HttpHeadersBuilder::lambda$addHeader$0($cast($String, k)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HttpHeadersBuilder$$Lambda$lambda$addHeader$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo HttpHeadersBuilder$$Lambda$lambda$addHeader$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpHeadersBuilder$$Lambda$lambda$addHeader$0::*)()>(&HttpHeadersBuilder$$Lambda$lambda$addHeader$0::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HttpHeadersBuilder$$Lambda$lambda$addHeader$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.HttpHeadersBuilder$$Lambda$lambda$addHeader$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* HttpHeadersBuilder$$Lambda$lambda$addHeader$0::load$($String* name, bool initialize) {
	$loadClass(HttpHeadersBuilder$$Lambda$lambda$addHeader$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HttpHeadersBuilder$$Lambda$lambda$addHeader$0::class$ = nullptr;

$FieldInfo _HttpHeadersBuilder_FieldInfo_[] = {
	{"headersMap", "Ljava/util/TreeMap;", "Ljava/util/TreeMap<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PRIVATE | $FINAL, $field(HttpHeadersBuilder, headersMap)},
	{}
};

$MethodInfo _HttpHeadersBuilder_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(HttpHeadersBuilder::*)()>(&HttpHeadersBuilder::init$))},
	{"addHeader", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"build", "()Ljava/net/http/HttpHeaders;", nullptr, $PUBLIC},
	{"clear", "()V", nullptr, $PUBLIC},
	{"lambda$addHeader$0", "(Ljava/lang/String;)Ljava/util/List;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$List*(*)($String*)>(&HttpHeadersBuilder::lambda$addHeader$0))},
	{"map", "()Ljava/util/Map;", "()Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PUBLIC},
	{"setHeader", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC},
	{"structuralCopy", "()Ljdk/internal/net/http/common/HttpHeadersBuilder;", nullptr, $PUBLIC},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$ClassInfo _HttpHeadersBuilder_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.common.HttpHeadersBuilder",
	"java.lang.Object",
	nullptr,
	_HttpHeadersBuilder_FieldInfo_,
	_HttpHeadersBuilder_MethodInfo_
};

$Object* allocate$HttpHeadersBuilder($Class* clazz) {
	return $of($alloc(HttpHeadersBuilder));
}

void HttpHeadersBuilder::init$() {
	$set(this, headersMap, $new($TreeMap, $String::CASE_INSENSITIVE_ORDER));
}

HttpHeadersBuilder* HttpHeadersBuilder::structuralCopy() {
	$useLocalCurrentObjectStackCache();
	$var(HttpHeadersBuilder, builder, $new(HttpHeadersBuilder));
	{
		$var($Iterator, i$, $nc($($nc(this->headersMap)->entrySet()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
			{
				$var($List, valuesCopy, $new($ArrayList, $cast($Collection, $($nc(entry)->getValue()))));
				$nc(builder->headersMap)->put($cast($String, $($nc(entry)->getKey())), valuesCopy);
			}
		}
	}
	return builder;
}

void HttpHeadersBuilder::addHeader($String* name, $String* value) {
	$useLocalCurrentObjectStackCache();
	$nc(($cast($List, $($nc(this->headersMap)->computeIfAbsent(name, static_cast<$Function*>($$new(HttpHeadersBuilder$$Lambda$lambda$addHeader$0)))))))->add(value);
}

void HttpHeadersBuilder::setHeader($String* name, $String* value) {
	$var($List, values, $new($ArrayList, 1));
	values->add(value);
	$nc(this->headersMap)->put(name, values);
}

void HttpHeadersBuilder::clear() {
	$nc(this->headersMap)->clear();
}

$Map* HttpHeadersBuilder::map() {
	return static_cast<$Map*>(static_cast<$AbstractMap*>(this->headersMap));
}

$HttpHeaders* HttpHeadersBuilder::build() {
	$init($Utils);
	return $HttpHeaders::of(static_cast<$Map*>(static_cast<$AbstractMap*>(this->headersMap)), $Utils::ACCEPT_ALL);
}

$String* HttpHeadersBuilder::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($Object::toString()))->append(" { "_s);
	sb->append($($of(map())));
	sb->append(" }"_s);
	return sb->toString();
}

$List* HttpHeadersBuilder::lambda$addHeader$0($String* k) {
	return $new($ArrayList, 1);
}

HttpHeadersBuilder::HttpHeadersBuilder() {
}

$Class* HttpHeadersBuilder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HttpHeadersBuilder$$Lambda$lambda$addHeader$0::classInfo$.name)) {
			return HttpHeadersBuilder$$Lambda$lambda$addHeader$0::load$(name, initialize);
		}
	}
	$loadClass(HttpHeadersBuilder, name, initialize, &_HttpHeadersBuilder_ClassInfo_, allocate$HttpHeadersBuilder);
	return class$;
}

$Class* HttpHeadersBuilder::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk