#include <jdk/internal/net/http/hpack/SimpleHeaderTable.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/util/List.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger$Level.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger.h>
#include <jdk/internal/net/http/hpack/SimpleHeaderTable$CircularBuffer.h>
#include <jdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField.h>
#include <jcpp.h>

#undef ENTRY_SIZE
#undef EXTRA
#undef NORMAL
#undef STATIC_TABLE_LENGTH

using $SimpleHeaderTable$HeaderFieldArray = $Array<::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField>;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Double = ::java::lang::Double;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $List = ::java::util::List;
using $Supplier = ::java::util::function::Supplier;
using $HPACK$Logger = ::jdk::internal::net::http::hpack::HPACK$Logger;
using $HPACK$Logger$Level = ::jdk::internal::net::http::hpack::HPACK$Logger$Level;
using $SimpleHeaderTable$CircularBuffer = ::jdk::internal::net::http::hpack::SimpleHeaderTable$CircularBuffer;
using $SimpleHeaderTable$HeaderField = ::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class SimpleHeaderTable$$Lambda$lambda$put$0 : public $Supplier {
	$class(SimpleHeaderTable$$Lambda$lambda$put$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$($SimpleHeaderTable$HeaderField* h) {
		$set(this, h, h);
	}
	virtual $Object* get() override {
		 return $of(SimpleHeaderTable::lambda$put$0(h));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SimpleHeaderTable$$Lambda$lambda$put$0>());
	}
	$SimpleHeaderTable$HeaderField* h = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SimpleHeaderTable$$Lambda$lambda$put$0::fieldInfos[2] = {
	{"h", "Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;", nullptr, $PUBLIC, $field(SimpleHeaderTable$$Lambda$lambda$put$0, h)},
	{}
};
$MethodInfo SimpleHeaderTable$$Lambda$lambda$put$0::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable$$Lambda$lambda$put$0::*)($SimpleHeaderTable$HeaderField*)>(&SimpleHeaderTable$$Lambda$lambda$put$0::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SimpleHeaderTable$$Lambda$lambda$put$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.SimpleHeaderTable$$Lambda$lambda$put$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SimpleHeaderTable$$Lambda$lambda$put$0::load$($String* name, bool initialize) {
	$loadClass(SimpleHeaderTable$$Lambda$lambda$put$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SimpleHeaderTable$$Lambda$lambda$put$0::class$ = nullptr;

class SimpleHeaderTable$$Lambda$lambda$put$1$1 : public $Supplier {
	$class(SimpleHeaderTable$$Lambda$lambda$put$1$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$($SimpleHeaderTable$HeaderField* h, int32_t entrySize) {
		$set(this, h, h);
		this->entrySize = entrySize;
	}
	virtual $Object* get() override {
		 return $of(SimpleHeaderTable::lambda$put$1(h, entrySize));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SimpleHeaderTable$$Lambda$lambda$put$1$1>());
	}
	$SimpleHeaderTable$HeaderField* h = nullptr;
	int32_t entrySize = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SimpleHeaderTable$$Lambda$lambda$put$1$1::fieldInfos[3] = {
	{"h", "Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;", nullptr, $PUBLIC, $field(SimpleHeaderTable$$Lambda$lambda$put$1$1, h)},
	{"entrySize", "I", nullptr, $PUBLIC, $field(SimpleHeaderTable$$Lambda$lambda$put$1$1, entrySize)},
	{}
};
$MethodInfo SimpleHeaderTable$$Lambda$lambda$put$1$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;I)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable$$Lambda$lambda$put$1$1::*)($SimpleHeaderTable$HeaderField*,int32_t)>(&SimpleHeaderTable$$Lambda$lambda$put$1$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SimpleHeaderTable$$Lambda$lambda$put$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.SimpleHeaderTable$$Lambda$lambda$put$1$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SimpleHeaderTable$$Lambda$lambda$put$1$1::load$($String* name, bool initialize) {
	$loadClass(SimpleHeaderTable$$Lambda$lambda$put$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SimpleHeaderTable$$Lambda$lambda$put$1$1::class$ = nullptr;

class SimpleHeaderTable$$Lambda$lambda$put$2$2 : public $Supplier {
	$class(SimpleHeaderTable$$Lambda$lambda$put$2$2, $NO_CLASS_INIT, $Supplier)
public:
	void init$(SimpleHeaderTable* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$put$2());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SimpleHeaderTable$$Lambda$lambda$put$2$2>());
	}
	SimpleHeaderTable* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SimpleHeaderTable$$Lambda$lambda$put$2$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SimpleHeaderTable$$Lambda$lambda$put$2$2, inst$)},
	{}
};
$MethodInfo SimpleHeaderTable$$Lambda$lambda$put$2$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable;)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable$$Lambda$lambda$put$2$2::*)(SimpleHeaderTable*)>(&SimpleHeaderTable$$Lambda$lambda$put$2$2::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SimpleHeaderTable$$Lambda$lambda$put$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.SimpleHeaderTable$$Lambda$lambda$put$2$2",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SimpleHeaderTable$$Lambda$lambda$put$2$2::load$($String* name, bool initialize) {
	$loadClass(SimpleHeaderTable$$Lambda$lambda$put$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SimpleHeaderTable$$Lambda$lambda$put$2$2::class$ = nullptr;

class SimpleHeaderTable$$Lambda$lambda$put$3$3 : public $Supplier {
	$class(SimpleHeaderTable$$Lambda$lambda$put$3$3, $NO_CLASS_INIT, $Supplier)
public:
	void init$($SimpleHeaderTable$HeaderField* h) {
		$set(this, h, h);
	}
	virtual $Object* get() override {
		 return $of(SimpleHeaderTable::lambda$put$3(h));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SimpleHeaderTable$$Lambda$lambda$put$3$3>());
	}
	$SimpleHeaderTable$HeaderField* h = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SimpleHeaderTable$$Lambda$lambda$put$3$3::fieldInfos[2] = {
	{"h", "Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;", nullptr, $PUBLIC, $field(SimpleHeaderTable$$Lambda$lambda$put$3$3, h)},
	{}
};
$MethodInfo SimpleHeaderTable$$Lambda$lambda$put$3$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable$$Lambda$lambda$put$3$3::*)($SimpleHeaderTable$HeaderField*)>(&SimpleHeaderTable$$Lambda$lambda$put$3$3::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SimpleHeaderTable$$Lambda$lambda$put$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.SimpleHeaderTable$$Lambda$lambda$put$3$3",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SimpleHeaderTable$$Lambda$lambda$put$3$3::load$($String* name, bool initialize) {
	$loadClass(SimpleHeaderTable$$Lambda$lambda$put$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SimpleHeaderTable$$Lambda$lambda$put$3$3::class$ = nullptr;

class SimpleHeaderTable$$Lambda$lambda$put$4$4 : public $Supplier {
	$class(SimpleHeaderTable$$Lambda$lambda$put$4$4, $NO_CLASS_INIT, $Supplier)
public:
	void init$($SimpleHeaderTable$HeaderField* h) {
		$set(this, h, h);
	}
	virtual $Object* get() override {
		 return $of(SimpleHeaderTable::lambda$put$4(h));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SimpleHeaderTable$$Lambda$lambda$put$4$4>());
	}
	$SimpleHeaderTable$HeaderField* h = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SimpleHeaderTable$$Lambda$lambda$put$4$4::fieldInfos[2] = {
	{"h", "Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;", nullptr, $PUBLIC, $field(SimpleHeaderTable$$Lambda$lambda$put$4$4, h)},
	{}
};
$MethodInfo SimpleHeaderTable$$Lambda$lambda$put$4$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable$$Lambda$lambda$put$4$4::*)($SimpleHeaderTable$HeaderField*)>(&SimpleHeaderTable$$Lambda$lambda$put$4$4::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SimpleHeaderTable$$Lambda$lambda$put$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.SimpleHeaderTable$$Lambda$lambda$put$4$4",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SimpleHeaderTable$$Lambda$lambda$put$4$4::load$($String* name, bool initialize) {
	$loadClass(SimpleHeaderTable$$Lambda$lambda$put$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SimpleHeaderTable$$Lambda$lambda$put$4$4::class$ = nullptr;

class SimpleHeaderTable$$Lambda$toString$5 : public $Supplier {
	$class(SimpleHeaderTable$$Lambda$toString$5, $NO_CLASS_INIT, $Supplier)
public:
	void init$(SimpleHeaderTable* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SimpleHeaderTable$$Lambda$toString$5>());
	}
	SimpleHeaderTable* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SimpleHeaderTable$$Lambda$toString$5::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(SimpleHeaderTable$$Lambda$toString$5, inst$)},
	{}
};
$MethodInfo SimpleHeaderTable$$Lambda$toString$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable;)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable$$Lambda$toString$5::*)(SimpleHeaderTable*)>(&SimpleHeaderTable$$Lambda$toString$5::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SimpleHeaderTable$$Lambda$toString$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.SimpleHeaderTable$$Lambda$toString$5",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SimpleHeaderTable$$Lambda$toString$5::load$($String* name, bool initialize) {
	$loadClass(SimpleHeaderTable$$Lambda$toString$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SimpleHeaderTable$$Lambda$toString$5::class$ = nullptr;

class SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6 : public $Supplier {
	$class(SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6, $NO_CLASS_INIT, $Supplier)
public:
	void init$($SimpleHeaderTable$HeaderField* f, int32_t s) {
		$set(this, f, f);
		this->s = s;
	}
	virtual $Object* get() override {
		 return $of(SimpleHeaderTable::lambda$evictEntry$5(f, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6>());
	}
	$SimpleHeaderTable$HeaderField* f = nullptr;
	int32_t s = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6::fieldInfos[3] = {
	{"f", "Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;", nullptr, $PUBLIC, $field(SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6, f)},
	{"s", "I", nullptr, $PUBLIC, $field(SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6, s)},
	{}
};
$MethodInfo SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;I)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6::*)($SimpleHeaderTable$HeaderField*,int32_t)>(&SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6::load$($String* name, bool initialize) {
	$loadClass(SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6::class$ = nullptr;

$FieldInfo _SimpleHeaderTable_FieldInfo_[] = {
	{"staticTable", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;>;", $PROTECTED | $STATIC | $FINAL, $staticField(SimpleHeaderTable, staticTable)},
	{"STATIC_TABLE_LENGTH", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $staticField(SimpleHeaderTable, STATIC_TABLE_LENGTH)},
	{"ENTRY_SIZE", "I", nullptr, $PROTECTED | $STATIC | $FINAL, $constField(SimpleHeaderTable, ENTRY_SIZE)},
	{"logger", "Ljdk/internal/net/http/hpack/HPACK$Logger;", nullptr, $PRIVATE | $FINAL, $field(SimpleHeaderTable, logger)},
	{"maxSize", "I", nullptr, $PRIVATE, $field(SimpleHeaderTable, maxSize$)},
	{"size", "I", nullptr, $PRIVATE, $field(SimpleHeaderTable, size$)},
	{"buffer", "Ljdk/internal/net/http/hpack/SimpleHeaderTable$CircularBuffer;", "Ljdk/internal/net/http/hpack/SimpleHeaderTable$CircularBuffer<Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;>;", $PRIVATE | $FINAL, $field(SimpleHeaderTable, buffer)},
	{}
};

$MethodInfo _SimpleHeaderTable_MethodInfo_[] = {
	{"<init>", "(ILjdk/internal/net/http/hpack/HPACK$Logger;)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable::*)(int32_t,$HPACK$Logger*)>(&SimpleHeaderTable::init$))},
	{"add", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;)V", nullptr, $PROTECTED},
	{"checkIndex", "(I)I", nullptr, $PRIVATE, $method(static_cast<int32_t(SimpleHeaderTable::*)(int32_t)>(&SimpleHeaderTable::checkIndex))},
	{"evictEntry", "()Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;", nullptr, 0},
	{"get", "(I)Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;", nullptr, 0},
	{"getStateString", "()Ljava/lang/String;", nullptr, 0},
	{"lambda$evictEntry$5", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($SimpleHeaderTable$HeaderField*,int32_t)>(&SimpleHeaderTable::lambda$evictEntry$5))},
	{"lambda$put$0", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($SimpleHeaderTable$HeaderField*)>(&SimpleHeaderTable::lambda$put$0))},
	{"lambda$put$1", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($SimpleHeaderTable$HeaderField*,int32_t)>(&SimpleHeaderTable::lambda$put$1))},
	{"lambda$put$2", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(SimpleHeaderTable::*)()>(&SimpleHeaderTable::lambda$put$2))},
	{"lambda$put$3", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($SimpleHeaderTable$HeaderField*)>(&SimpleHeaderTable::lambda$put$3))},
	{"lambda$put$4", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($SimpleHeaderTable$HeaderField*)>(&SimpleHeaderTable::lambda$put$4))},
	{"length", "()I", nullptr, $PUBLIC},
	{"maxSize", "()I", nullptr, $PUBLIC},
	{"put", "(Ljava/lang/CharSequence;Ljava/lang/CharSequence;)V", nullptr, 0},
	{"put", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;)V", nullptr, $PRIVATE, $method(static_cast<void(SimpleHeaderTable::*)($SimpleHeaderTable$HeaderField*)>(&SimpleHeaderTable::put))},
	{"remove", "()Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;", nullptr, $PROTECTED},
	{"setMaxSize", "(I)V", nullptr, 0},
	{"size", "()I", nullptr, $PUBLIC},
	{"sizeOf", "(Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;)I", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _SimpleHeaderTable_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.SimpleHeaderTable$CircularBuffer", "jdk.internal.net.http.hpack.SimpleHeaderTable", "CircularBuffer", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.SimpleHeaderTable$HeaderField", "jdk.internal.net.http.hpack.SimpleHeaderTable", "HeaderField", $PROTECTED | $STATIC | $FINAL},
	{}
};

$ClassInfo _SimpleHeaderTable_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.hpack.SimpleHeaderTable",
	"java.lang.Object",
	nullptr,
	_SimpleHeaderTable_FieldInfo_,
	_SimpleHeaderTable_MethodInfo_,
	nullptr,
	nullptr,
	_SimpleHeaderTable_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.SimpleHeaderTable$CircularBuffer,jdk.internal.net.http.hpack.SimpleHeaderTable$HeaderField"
};

$Object* allocate$SimpleHeaderTable($Class* clazz) {
	return $of($alloc(SimpleHeaderTable));
}

$List* SimpleHeaderTable::staticTable = nullptr;
int32_t SimpleHeaderTable::STATIC_TABLE_LENGTH = 0;

void SimpleHeaderTable::init$(int32_t maxSize, $HPACK$Logger* logger) {
	$set(this, buffer, $new($SimpleHeaderTable$CircularBuffer, 0));
	$set(this, logger, logger);
	setMaxSize(maxSize);
}

int32_t SimpleHeaderTable::size() {
	return this->size$;
}

int32_t SimpleHeaderTable::maxSize() {
	return this->maxSize$;
}

int32_t SimpleHeaderTable::length() {
	return SimpleHeaderTable::STATIC_TABLE_LENGTH + $nc(this->buffer)->size;
}

$SimpleHeaderTable$HeaderField* SimpleHeaderTable::get(int32_t index) {
	checkIndex(index);
	if (index <= SimpleHeaderTable::STATIC_TABLE_LENGTH) {
		return $cast($SimpleHeaderTable$HeaderField, $nc(SimpleHeaderTable::staticTable)->get(index));
	} else {
		return $cast($SimpleHeaderTable$HeaderField, $nc(this->buffer)->get(index - SimpleHeaderTable::STATIC_TABLE_LENGTH - 1));
	}
}

void SimpleHeaderTable::put($CharSequence* name, $CharSequence* value) {
	$useLocalCurrentObjectStackCache();
	$var($String, var$0, $nc(name)->toString());
	put($$new($SimpleHeaderTable$HeaderField, var$0, $($nc(value)->toString())));
}

void SimpleHeaderTable::put($SimpleHeaderTable$HeaderField* h) {
	$useLocalCurrentObjectStackCache();
	$init($HPACK$Logger$Level);
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
		$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(SimpleHeaderTable$$Lambda$lambda$put$0, h)));
	}
	int32_t entrySize = sizeOf(h);
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::EXTRA)) {
		$nc(this->logger)->log($HPACK$Logger$Level::EXTRA, static_cast<$Supplier*>($$new(SimpleHeaderTable$$Lambda$lambda$put$1$1, h, entrySize)));
	}
	while (entrySize > this->maxSize$ - this->size$ && this->size$ != 0) {
		if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::EXTRA)) {
			$nc(this->logger)->log($HPACK$Logger$Level::EXTRA, static_cast<$Supplier*>($$new(SimpleHeaderTable$$Lambda$lambda$put$2$2, this)));
		}
		evictEntry();
	}
	if (entrySize > this->maxSize$ - this->size$) {
		if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::EXTRA)) {
			$nc(this->logger)->log($HPACK$Logger$Level::EXTRA, static_cast<$Supplier*>($$new(SimpleHeaderTable$$Lambda$lambda$put$3$3, h)));
		}
		return;
	}
	this->size$ += entrySize;
	add(h);
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::EXTRA)) {
		$nc(this->logger)->log($HPACK$Logger$Level::EXTRA, static_cast<$Supplier*>($$new(SimpleHeaderTable$$Lambda$lambda$put$4$4, h)));
		$nc(this->logger)->log($HPACK$Logger$Level::EXTRA, static_cast<$Supplier*>($$new(SimpleHeaderTable$$Lambda$toString$5, this)));
	}
}

void SimpleHeaderTable::setMaxSize(int32_t maxSize) {
	$useLocalCurrentObjectStackCache();
	if (maxSize < 0) {
		$throwNew($IllegalArgumentException, $$str({"maxSize >= 0: maxSize="_s, $$str(maxSize)}));
	}
	while (maxSize < this->size$ && this->size$ != 0) {
		evictEntry();
	}
	this->maxSize$ = maxSize;
	int32_t upperBound = $div(maxSize, SimpleHeaderTable::ENTRY_SIZE);
	$nc(this->buffer)->resize(upperBound);
}

$SimpleHeaderTable$HeaderField* SimpleHeaderTable::evictEntry() {
	$useLocalCurrentObjectStackCache();
	$var($SimpleHeaderTable$HeaderField, f, remove());
	int32_t s = sizeOf(f);
	this->size$ -= s;
	$init($HPACK$Logger$Level);
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::EXTRA)) {
		$nc(this->logger)->log($HPACK$Logger$Level::EXTRA, static_cast<$Supplier*>($$new(SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6, f, s)));
		$nc(this->logger)->log($HPACK$Logger$Level::EXTRA, static_cast<$Supplier*>($$new(SimpleHeaderTable$$Lambda$toString$5, this)));
	}
	return f;
}

$String* SimpleHeaderTable::toString() {
	$useLocalCurrentObjectStackCache();
	double used = this->maxSize$ == 0 ? (double)0 : 100 * (((double)this->size$) / this->maxSize$);
	return $String::format("dynamic length: %d, full length: %s, used space: %s/%s (%.1f%%)"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf($nc(this->buffer)->size))),
		$($of($Integer::valueOf(length()))),
		$($of($Integer::valueOf(this->size$))),
		$($of($Integer::valueOf(this->maxSize$))),
		$($of($Double::valueOf(used)))
	}));
}

int32_t SimpleHeaderTable::checkIndex(int32_t index) {
	$useLocalCurrentObjectStackCache();
	int32_t len = length();
	if (index < 1 || index > len) {
		$throwNew($IndexOutOfBoundsException, $($String::format("1 <= index <= length(): index=%s, length()=%s"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(index))),
			$($of($Integer::valueOf(len)))
		}))));
	}
	return index;
}

int32_t SimpleHeaderTable::sizeOf($SimpleHeaderTable$HeaderField* f) {
	int32_t var$0 = $nc($nc(f)->name)->length();
	return var$0 + $nc(f->value)->length() + SimpleHeaderTable::ENTRY_SIZE;
}

$String* SimpleHeaderTable::getStateString() {
	$useLocalCurrentObjectStackCache();
	if (this->size$ == 0) {
		return "empty."_s;
	}
	$var($StringBuilder, b, $new($StringBuilder));
	{
		int32_t i = 1;
		int32_t size = $nc(this->buffer)->size;
		for (; i <= size; ++i) {
			$var($SimpleHeaderTable$HeaderField, e, $cast($SimpleHeaderTable$HeaderField, $nc(this->buffer)->get(i - 1)));
			b->append($($String::format("[%3d] (s = %3d) %s: %s\n"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(i))),
				$($of($Integer::valueOf(sizeOf(e)))),
				$of($nc(e)->name),
				$of(e->value)
			}))));
		}
	}
	b->append($($String::format("      Table size:%4s"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->size$)))}))));
	return b->toString();
}

void SimpleHeaderTable::add($SimpleHeaderTable$HeaderField* f) {
	$nc(this->buffer)->add(f);
}

$SimpleHeaderTable$HeaderField* SimpleHeaderTable::remove() {
	return $cast($SimpleHeaderTable$HeaderField, $nc(this->buffer)->remove());
}

$String* SimpleHeaderTable::lambda$evictEntry$5($SimpleHeaderTable$HeaderField* f, int32_t s) {
	$init(SimpleHeaderTable);
	$useLocalCurrentObjectStackCache();
	return $String::format("evicted entry (\'%s\', \'%s\') of size %s"_s, $$new($ObjectArray, {
		$of($nc(f)->name),
		$of(f->value),
		$($of($Integer::valueOf(s)))
	}));
}

$String* SimpleHeaderTable::lambda$put$4($SimpleHeaderTable$HeaderField* h) {
	$init(SimpleHeaderTable);
	return $String::format("(\'%s, \'%s\') added"_s, $$new($ObjectArray, {
		$of($nc(h)->name),
		$of(h->value)
	}));
}

$String* SimpleHeaderTable::lambda$put$3($SimpleHeaderTable$HeaderField* h) {
	$init(SimpleHeaderTable);
	return $String::format("not adding (\'%s, \'%s\'), too big"_s, $$new($ObjectArray, {
		$of($nc(h)->name),
		$of(h->value)
	}));
}

$String* SimpleHeaderTable::lambda$put$2() {
	$useLocalCurrentObjectStackCache();
	return $String::format("insufficient space %s, must evict entry"_s, $$new($ObjectArray, {$($of($Integer::valueOf((this->maxSize$ - this->size$))))}));
}

$String* SimpleHeaderTable::lambda$put$1($SimpleHeaderTable$HeaderField* h, int32_t entrySize) {
	$init(SimpleHeaderTable);
	$useLocalCurrentObjectStackCache();
	return $String::format("size of (\'%s\', \'%s\') is %s"_s, $$new($ObjectArray, {
		$of($nc(h)->name),
		$of(h->value),
		$($of($Integer::valueOf(entrySize)))
	}));
}

$String* SimpleHeaderTable::lambda$put$0($SimpleHeaderTable$HeaderField* h) {
	$init(SimpleHeaderTable);
	return $String::format("adding (\'%s\', \'%s\')"_s, $$new($ObjectArray, {
		$of($nc(h)->name),
		$of(h->value)
	}));
}

void clinit$SimpleHeaderTable($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(SimpleHeaderTable::staticTable, $List::of($$new($SimpleHeaderTable$HeaderFieldArray, {
		$$new($SimpleHeaderTable$HeaderField, ""_s),
		$$new($SimpleHeaderTable$HeaderField, ":authority"_s),
		$$new($SimpleHeaderTable$HeaderField, ":method"_s, "GET"_s),
		$$new($SimpleHeaderTable$HeaderField, ":method"_s, "POST"_s),
		$$new($SimpleHeaderTable$HeaderField, ":path"_s, "/"_s),
		$$new($SimpleHeaderTable$HeaderField, ":path"_s, "/index.html"_s),
		$$new($SimpleHeaderTable$HeaderField, ":scheme"_s, "http"_s),
		$$new($SimpleHeaderTable$HeaderField, ":scheme"_s, "https"_s),
		$$new($SimpleHeaderTable$HeaderField, ":status"_s, "200"_s),
		$$new($SimpleHeaderTable$HeaderField, ":status"_s, "204"_s),
		$$new($SimpleHeaderTable$HeaderField, ":status"_s, "206"_s),
		$$new($SimpleHeaderTable$HeaderField, ":status"_s, "304"_s),
		$$new($SimpleHeaderTable$HeaderField, ":status"_s, "400"_s),
		$$new($SimpleHeaderTable$HeaderField, ":status"_s, "404"_s),
		$$new($SimpleHeaderTable$HeaderField, ":status"_s, "500"_s),
		$$new($SimpleHeaderTable$HeaderField, "accept-charset"_s),
		$$new($SimpleHeaderTable$HeaderField, "accept-encoding"_s, "gzip, deflate"_s),
		$$new($SimpleHeaderTable$HeaderField, "accept-language"_s),
		$$new($SimpleHeaderTable$HeaderField, "accept-ranges"_s),
		$$new($SimpleHeaderTable$HeaderField, "accept"_s),
		$$new($SimpleHeaderTable$HeaderField, "access-control-allow-origin"_s),
		$$new($SimpleHeaderTable$HeaderField, "age"_s),
		$$new($SimpleHeaderTable$HeaderField, "allow"_s),
		$$new($SimpleHeaderTable$HeaderField, "authorization"_s),
		$$new($SimpleHeaderTable$HeaderField, "cache-control"_s),
		$$new($SimpleHeaderTable$HeaderField, "content-disposition"_s),
		$$new($SimpleHeaderTable$HeaderField, "content-encoding"_s),
		$$new($SimpleHeaderTable$HeaderField, "content-language"_s),
		$$new($SimpleHeaderTable$HeaderField, "content-length"_s),
		$$new($SimpleHeaderTable$HeaderField, "content-location"_s),
		$$new($SimpleHeaderTable$HeaderField, "content-range"_s),
		$$new($SimpleHeaderTable$HeaderField, "content-type"_s),
		$$new($SimpleHeaderTable$HeaderField, "cookie"_s),
		$$new($SimpleHeaderTable$HeaderField, "date"_s),
		$$new($SimpleHeaderTable$HeaderField, "etag"_s),
		$$new($SimpleHeaderTable$HeaderField, "expect"_s),
		$$new($SimpleHeaderTable$HeaderField, "expires"_s),
		$$new($SimpleHeaderTable$HeaderField, "from"_s),
		$$new($SimpleHeaderTable$HeaderField, "host"_s),
		$$new($SimpleHeaderTable$HeaderField, "if-match"_s),
		$$new($SimpleHeaderTable$HeaderField, "if-modified-since"_s),
		$$new($SimpleHeaderTable$HeaderField, "if-none-match"_s),
		$$new($SimpleHeaderTable$HeaderField, "if-range"_s),
		$$new($SimpleHeaderTable$HeaderField, "if-unmodified-since"_s),
		$$new($SimpleHeaderTable$HeaderField, "last-modified"_s),
		$$new($SimpleHeaderTable$HeaderField, "link"_s),
		$$new($SimpleHeaderTable$HeaderField, "location"_s),
		$$new($SimpleHeaderTable$HeaderField, "max-forwards"_s),
		$$new($SimpleHeaderTable$HeaderField, "proxy-authenticate"_s),
		$$new($SimpleHeaderTable$HeaderField, "proxy-authorization"_s),
		$$new($SimpleHeaderTable$HeaderField, "range"_s),
		$$new($SimpleHeaderTable$HeaderField, "referer"_s),
		$$new($SimpleHeaderTable$HeaderField, "refresh"_s),
		$$new($SimpleHeaderTable$HeaderField, "retry-after"_s),
		$$new($SimpleHeaderTable$HeaderField, "server"_s),
		$$new($SimpleHeaderTable$HeaderField, "set-cookie"_s),
		$$new($SimpleHeaderTable$HeaderField, "strict-transport-security"_s),
		$$new($SimpleHeaderTable$HeaderField, "transfer-encoding"_s),
		$$new($SimpleHeaderTable$HeaderField, "user-agent"_s),
		$$new($SimpleHeaderTable$HeaderField, "vary"_s),
		$$new($SimpleHeaderTable$HeaderField, "via"_s),
		$$new($SimpleHeaderTable$HeaderField, "www-authenticate"_s)
	})));
	SimpleHeaderTable::STATIC_TABLE_LENGTH = $nc(SimpleHeaderTable::staticTable)->size() - 1;
}

SimpleHeaderTable::SimpleHeaderTable() {
}

$Class* SimpleHeaderTable::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SimpleHeaderTable$$Lambda$lambda$put$0::classInfo$.name)) {
			return SimpleHeaderTable$$Lambda$lambda$put$0::load$(name, initialize);
		}
		if (name->equals(SimpleHeaderTable$$Lambda$lambda$put$1$1::classInfo$.name)) {
			return SimpleHeaderTable$$Lambda$lambda$put$1$1::load$(name, initialize);
		}
		if (name->equals(SimpleHeaderTable$$Lambda$lambda$put$2$2::classInfo$.name)) {
			return SimpleHeaderTable$$Lambda$lambda$put$2$2::load$(name, initialize);
		}
		if (name->equals(SimpleHeaderTable$$Lambda$lambda$put$3$3::classInfo$.name)) {
			return SimpleHeaderTable$$Lambda$lambda$put$3$3::load$(name, initialize);
		}
		if (name->equals(SimpleHeaderTable$$Lambda$lambda$put$4$4::classInfo$.name)) {
			return SimpleHeaderTable$$Lambda$lambda$put$4$4::load$(name, initialize);
		}
		if (name->equals(SimpleHeaderTable$$Lambda$toString$5::classInfo$.name)) {
			return SimpleHeaderTable$$Lambda$toString$5::load$(name, initialize);
		}
		if (name->equals(SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6::classInfo$.name)) {
			return SimpleHeaderTable$$Lambda$lambda$evictEntry$5$6::load$(name, initialize);
		}
	}
	$loadClass(SimpleHeaderTable, name, initialize, &_SimpleHeaderTable_ClassInfo_, clinit$SimpleHeaderTable, allocate$SimpleHeaderTable);
	return class$;
}

$Class* SimpleHeaderTable::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk