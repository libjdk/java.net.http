#include <jdk/internal/net/http/hpack/Decoder.h>

#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/lang/AbstractStringBuilder.h>
#include <java/lang/Appendable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/lang/InternalError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/concurrent/atomic/AtomicLong.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/hpack/Decoder$1.h>
#include <jdk/internal/net/http/hpack/Decoder$State.h>
#include <jdk/internal/net/http/hpack/DecodingCallback.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger$Level.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger.h>
#include <jdk/internal/net/http/hpack/HPACK.h>
#include <jdk/internal/net/http/hpack/IntegerReader.h>
#include <jdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField.h>
#include <jdk/internal/net/http/hpack/SimpleHeaderTable.h>
#include <jdk/internal/net/http/hpack/StringReader.h>
#include <jcpp.h>

#undef DECODERS_IDS
#undef EXTRA
#undef INDEXED
#undef LITERAL
#undef LITERAL_NEVER_INDEXED
#undef LITERAL_WITH_INDEXING
#undef NORMAL
#undef READY
#undef SIZE_UPDATE

using $Decoder$StateArray = $Array<::jdk::internal::net::http::hpack::Decoder$State>;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $AbstractStringBuilder = ::java::lang::AbstractStringBuilder;
using $Appendable = ::java::lang::Appendable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $AtomicLong = ::java::util::concurrent::atomic::AtomicLong;
using $Supplier = ::java::util::function::Supplier;
using $Decoder$1 = ::jdk::internal::net::http::hpack::Decoder$1;
using $Decoder$State = ::jdk::internal::net::http::hpack::Decoder$State;
using $DecodingCallback = ::jdk::internal::net::http::hpack::DecodingCallback;
using $HPACK = ::jdk::internal::net::http::hpack::HPACK;
using $HPACK$Logger = ::jdk::internal::net::http::hpack::HPACK$Logger;
using $HPACK$Logger$Level = ::jdk::internal::net::http::hpack::HPACK$Logger$Level;
using $IntegerReader = ::jdk::internal::net::http::hpack::IntegerReader;
using $SimpleHeaderTable = ::jdk::internal::net::http::hpack::SimpleHeaderTable;
using $SimpleHeaderTable$HeaderField = ::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField;
using $StringReader = ::jdk::internal::net::http::hpack::StringReader;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class Decoder$$Lambda$lambda$new$0 : public $Supplier {
	$class(Decoder$$Lambda$lambda$new$0, $NO_CLASS_INIT, $Supplier)
public:
	void init$(int32_t capacity) {
		this->capacity = capacity;
	}
	virtual $Object* get() override {
		 return $of(Decoder::lambda$new$0(capacity));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$new$0>());
	}
	int32_t capacity = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$new$0::fieldInfos[2] = {
	{"capacity", "I", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$new$0, capacity)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$new$0::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$new$0::*)(int32_t)>(&Decoder$$Lambda$lambda$new$0::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$new$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$new$0",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$new$0::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$new$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$new$0::class$ = nullptr;

class Decoder$$Lambda$lambda$new$1$1 : public $Supplier {
	$class(Decoder$$Lambda$lambda$new$1$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Decoder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$new$1());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$new$1$1>());
	}
	Decoder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$new$1$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$new$1$1, inst$)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$new$1$1::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$new$1$1::*)(Decoder*)>(&Decoder$$Lambda$lambda$new$1$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$new$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$new$1$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$new$1$1::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$new$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$new$1$1::class$ = nullptr;

class Decoder$$Lambda$lambda$setMaxCapacity$2$2 : public $Supplier {
	$class(Decoder$$Lambda$lambda$setMaxCapacity$2$2, $NO_CLASS_INIT, $Supplier)
public:
	void init$(int32_t capacity) {
		this->capacity = capacity;
	}
	virtual $Object* get() override {
		 return $of(Decoder::lambda$setMaxCapacity$2(capacity));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$setMaxCapacity$2$2>());
	}
	int32_t capacity = 0;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$setMaxCapacity$2$2::fieldInfos[2] = {
	{"capacity", "I", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$setMaxCapacity$2$2, capacity)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$setMaxCapacity$2$2::methodInfos[3] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$setMaxCapacity$2$2::*)(int32_t)>(&Decoder$$Lambda$lambda$setMaxCapacity$2$2::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$setMaxCapacity$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$setMaxCapacity$2$2",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$setMaxCapacity$2$2::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$setMaxCapacity$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$setMaxCapacity$2$2::class$ = nullptr;

class Decoder$$Lambda$lambda$decode$3$3 : public $Supplier {
	$class(Decoder$$Lambda$lambda$decode$3$3, $NO_CLASS_INIT, $Supplier)
public:
	void init$($ByteBuffer* headerBlock, bool endOfHeaderBlock) {
		$set(this, headerBlock, headerBlock);
		this->endOfHeaderBlock = endOfHeaderBlock;
	}
	virtual $Object* get() override {
		 return $of(Decoder::lambda$decode$3(headerBlock, endOfHeaderBlock));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$decode$3$3>());
	}
	$ByteBuffer* headerBlock = nullptr;
	bool endOfHeaderBlock = false;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$decode$3$3::fieldInfos[3] = {
	{"headerBlock", "Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$decode$3$3, headerBlock)},
	{"endOfHeaderBlock", "Z", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$decode$3$3, endOfHeaderBlock)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$decode$3$3::methodInfos[3] = {
	{"<init>", "(Ljava/nio/ByteBuffer;Z)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$decode$3$3::*)($ByteBuffer*,bool)>(&Decoder$$Lambda$lambda$decode$3$3::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$decode$3$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$decode$3$3",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$decode$3$3::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$decode$3$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$decode$3$3::class$ = nullptr;

class Decoder$$Lambda$lambda$decode$4$4 : public $Supplier {
	$class(Decoder$$Lambda$lambda$decode$4$4, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Decoder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$decode$4());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$decode$4$4>());
	}
	Decoder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$decode$4$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$decode$4$4, inst$)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$decode$4$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$decode$4$4::*)(Decoder*)>(&Decoder$$Lambda$lambda$decode$4$4::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$decode$4$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$decode$4$4",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$decode$4$4::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$decode$4$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$decode$4$4::class$ = nullptr;

class Decoder$$Lambda$lambda$resumeReady$5$5 : public $Supplier {
	$class(Decoder$$Lambda$lambda$resumeReady$5$5, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Decoder$State* s, int32_t b) {
		$set(this, s, s);
		this->b = b;
	}
	virtual $Object* get() override {
		 return $of(Decoder::lambda$resumeReady$5(s, b));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$resumeReady$5$5>());
	}
	$Decoder$State* s = nullptr;
	int32_t b = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$resumeReady$5$5::fieldInfos[3] = {
	{"s", "Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeReady$5$5, s)},
	{"b", "I", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeReady$5$5, b)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$resumeReady$5$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder$State;I)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$resumeReady$5$5::*)($Decoder$State*,int32_t)>(&Decoder$$Lambda$lambda$resumeReady$5$5::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$resumeReady$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$resumeReady$5$5",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$resumeReady$5$5::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$resumeReady$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$resumeReady$5$5::class$ = nullptr;

class Decoder$$Lambda$lambda$resumeIndexed$6$6 : public $Supplier {
	$class(Decoder$$Lambda$lambda$resumeIndexed$6$6, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Decoder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$resumeIndexed$6());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$resumeIndexed$6$6>());
	}
	Decoder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$resumeIndexed$6$6::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeIndexed$6$6, inst$)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$resumeIndexed$6$6::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$resumeIndexed$6$6::*)(Decoder*)>(&Decoder$$Lambda$lambda$resumeIndexed$6$6::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$resumeIndexed$6$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$resumeIndexed$6$6",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$resumeIndexed$6$6::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$resumeIndexed$6$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$resumeIndexed$6$6::class$ = nullptr;

class Decoder$$Lambda$lambda$resumeLiteral$7$7 : public $Supplier {
	$class(Decoder$$Lambda$lambda$resumeLiteral$7$7, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Decoder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$resumeLiteral$7());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$resumeLiteral$7$7>());
	}
	Decoder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$resumeLiteral$7$7::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeLiteral$7$7, inst$)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$resumeLiteral$7$7::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$resumeLiteral$7$7::*)(Decoder*)>(&Decoder$$Lambda$lambda$resumeLiteral$7$7::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$resumeLiteral$7$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$resumeLiteral$7$7",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$resumeLiteral$7$7::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$resumeLiteral$7$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$resumeLiteral$7$7::class$ = nullptr;

class Decoder$$Lambda$lambda$resumeLiteral$8$8 : public $Supplier {
	$class(Decoder$$Lambda$lambda$resumeLiteral$8$8, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Decoder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$resumeLiteral$8());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$resumeLiteral$8$8>());
	}
	Decoder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$resumeLiteral$8$8::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeLiteral$8$8, inst$)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$resumeLiteral$8$8::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$resumeLiteral$8$8::*)(Decoder*)>(&Decoder$$Lambda$lambda$resumeLiteral$8$8::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$resumeLiteral$8$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$resumeLiteral$8$8",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$resumeLiteral$8$8::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$resumeLiteral$8$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$resumeLiteral$8$8::class$ = nullptr;

class Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9 : public $Supplier {
	$class(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Decoder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$resumeLiteralWithIndexing$9());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9>());
	}
	Decoder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9, inst$)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9::*)(Decoder*)>(&Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9::class$ = nullptr;

class Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10 : public $Supplier {
	$class(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Decoder* inst, $String* n) {
		$set(this, inst$, inst);
		$set(this, n, n);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$resumeLiteralWithIndexing$10(n));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10>());
	}
	Decoder* inst$ = nullptr;
	$String* n = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10, inst$)},
	{"n", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10, n)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10::*)(Decoder*,$String*)>(&Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10::class$ = nullptr;

class Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11 : public $Supplier {
	$class(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Decoder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$resumeLiteralNeverIndexed$11());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11>());
	}
	Decoder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11, inst$)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11::*)(Decoder*)>(&Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11::class$ = nullptr;

class Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12 : public $Supplier {
	$class(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Decoder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$resumeLiteralNeverIndexed$12());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12>());
	}
	Decoder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12, inst$)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12::*)(Decoder*)>(&Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12::class$ = nullptr;

class Decoder$$Lambda$lambda$resumeSizeUpdate$13$13 : public $Supplier {
	$class(Decoder$$Lambda$lambda$resumeSizeUpdate$13$13, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Decoder* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$resumeSizeUpdate$13());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Decoder$$Lambda$lambda$resumeSizeUpdate$13$13>());
	}
	Decoder* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Decoder$$Lambda$lambda$resumeSizeUpdate$13$13::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Decoder$$Lambda$lambda$resumeSizeUpdate$13$13, inst$)},
	{}
};
$MethodInfo Decoder$$Lambda$lambda$resumeSizeUpdate$13$13::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/Decoder;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder$$Lambda$lambda$resumeSizeUpdate$13$13::*)(Decoder*)>(&Decoder$$Lambda$lambda$resumeSizeUpdate$13$13::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Decoder$$Lambda$lambda$resumeSizeUpdate$13$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.Decoder$$Lambda$lambda$resumeSizeUpdate$13$13",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Decoder$$Lambda$lambda$resumeSizeUpdate$13$13::load$($String* name, bool initialize) {
	$loadClass(Decoder$$Lambda$lambda$resumeSizeUpdate$13$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Decoder$$Lambda$lambda$resumeSizeUpdate$13$13::class$ = nullptr;

$FieldInfo _Decoder_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Decoder, $assertionsDisabled)},
	{"logger", "Ljdk/internal/net/http/hpack/HPACK$Logger;", nullptr, $PRIVATE | $FINAL, $field(Decoder, logger)},
	{"DECODERS_IDS", "Ljava/util/concurrent/atomic/AtomicLong;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Decoder, DECODERS_IDS)},
	{"states", "Ljava/util/List;", "Ljava/util/List<Ljdk/internal/net/http/hpack/Decoder$State;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Decoder, states)},
	{"id", "J", nullptr, $PRIVATE | $FINAL, $field(Decoder, id)},
	{"table", "Ljdk/internal/net/http/hpack/SimpleHeaderTable;", nullptr, $PRIVATE | $FINAL, $field(Decoder, table)},
	{"state", "Ljdk/internal/net/http/hpack/Decoder$State;", nullptr, $PRIVATE, $field(Decoder, state)},
	{"integerReader", "Ljdk/internal/net/http/hpack/IntegerReader;", nullptr, $PRIVATE | $FINAL, $field(Decoder, integerReader)},
	{"stringReader", "Ljdk/internal/net/http/hpack/StringReader;", nullptr, $PRIVATE | $FINAL, $field(Decoder, stringReader)},
	{"name", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE | $FINAL, $field(Decoder, name)},
	{"value", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE | $FINAL, $field(Decoder, value)},
	{"intValue", "I", nullptr, $PRIVATE, $field(Decoder, intValue)},
	{"firstValueRead", "Z", nullptr, $PRIVATE, $field(Decoder, firstValueRead)},
	{"firstValueIndex", "Z", nullptr, $PRIVATE, $field(Decoder, firstValueIndex)},
	{"nameHuffmanEncoded", "Z", nullptr, $PRIVATE, $field(Decoder, nameHuffmanEncoded)},
	{"valueHuffmanEncoded", "Z", nullptr, $PRIVATE, $field(Decoder, valueHuffmanEncoded)},
	{"capacity", "I", nullptr, $PRIVATE, $field(Decoder, capacity)},
	{}
};

$MethodInfo _Decoder_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder::*)(int32_t)>(&Decoder::init$))},
	{"cleanUpAfterReading", "()V", nullptr, $PRIVATE, $method(static_cast<void(Decoder::*)()>(&Decoder::cleanUpAfterReading))},
	{"completeReading", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PRIVATE, $method(static_cast<bool(Decoder::*)($ByteBuffer*)>(&Decoder::completeReading)), "java.io.IOException"},
	{"decode", "(Ljava/nio/ByteBuffer;ZLjdk/internal/net/http/hpack/DecodingCallback;)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder::*)($ByteBuffer*,bool,$DecodingCallback*)>(&Decoder::decode)), "java.io.IOException"},
	{"getHeaderFieldAt", "(I)Ljdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField;", nullptr, $PRIVATE, $method(static_cast<$SimpleHeaderTable$HeaderField*(Decoder::*)(int32_t)>(&Decoder::getHeaderFieldAt)), "java.io.IOException"},
	{"getTable", "()Ljdk/internal/net/http/hpack/SimpleHeaderTable;", nullptr, 0, $method(static_cast<$SimpleHeaderTable*(Decoder::*)()>(&Decoder::getTable))},
	{"lambda$decode$3", "(Ljava/nio/ByteBuffer;Z)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($ByteBuffer*,bool)>(&Decoder::lambda$decode$3))},
	{"lambda$decode$4", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Decoder::*)()>(&Decoder::lambda$decode$4))},
	{"lambda$new$0", "(I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)(int32_t)>(&Decoder::lambda$new$0))},
	{"lambda$new$1", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Decoder::*)()>(&Decoder::lambda$new$1))},
	{"lambda$resumeIndexed$6", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Decoder::*)()>(&Decoder::lambda$resumeIndexed$6))},
	{"lambda$resumeLiteral$7", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Decoder::*)()>(&Decoder::lambda$resumeLiteral$7))},
	{"lambda$resumeLiteral$8", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Decoder::*)()>(&Decoder::lambda$resumeLiteral$8))},
	{"lambda$resumeLiteralNeverIndexed$11", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Decoder::*)()>(&Decoder::lambda$resumeLiteralNeverIndexed$11))},
	{"lambda$resumeLiteralNeverIndexed$12", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Decoder::*)()>(&Decoder::lambda$resumeLiteralNeverIndexed$12))},
	{"lambda$resumeLiteralWithIndexing$10", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Decoder::*)($String*)>(&Decoder::lambda$resumeLiteralWithIndexing$10))},
	{"lambda$resumeLiteralWithIndexing$9", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Decoder::*)()>(&Decoder::lambda$resumeLiteralWithIndexing$9))},
	{"lambda$resumeReady$5", "(Ljdk/internal/net/http/hpack/Decoder$State;I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($Decoder$State*,int32_t)>(&Decoder::lambda$resumeReady$5))},
	{"lambda$resumeSizeUpdate$13", "()Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Decoder::*)()>(&Decoder::lambda$resumeSizeUpdate$13))},
	{"lambda$setMaxCapacity$2", "(I)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)(int32_t)>(&Decoder::lambda$setMaxCapacity$2))},
	{"proceed", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/hpack/DecodingCallback;)V", nullptr, $PRIVATE, $method(static_cast<void(Decoder::*)($ByteBuffer*,$DecodingCallback*)>(&Decoder::proceed)), "java.io.IOException"},
	{"resumeIndexed", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/hpack/DecodingCallback;)V", nullptr, $PRIVATE, $method(static_cast<void(Decoder::*)($ByteBuffer*,$DecodingCallback*)>(&Decoder::resumeIndexed)), "java.io.IOException"},
	{"resumeLiteral", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/hpack/DecodingCallback;)V", nullptr, $PRIVATE, $method(static_cast<void(Decoder::*)($ByteBuffer*,$DecodingCallback*)>(&Decoder::resumeLiteral)), "java.io.IOException"},
	{"resumeLiteralNeverIndexed", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/hpack/DecodingCallback;)V", nullptr, $PRIVATE, $method(static_cast<void(Decoder::*)($ByteBuffer*,$DecodingCallback*)>(&Decoder::resumeLiteralNeverIndexed)), "java.io.IOException"},
	{"resumeLiteralWithIndexing", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/hpack/DecodingCallback;)V", nullptr, $PRIVATE, $method(static_cast<void(Decoder::*)($ByteBuffer*,$DecodingCallback*)>(&Decoder::resumeLiteralWithIndexing)), "java.io.IOException"},
	{"resumeReady", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Decoder::*)($ByteBuffer*)>(&Decoder::resumeReady))},
	{"resumeSizeUpdate", "(Ljava/nio/ByteBuffer;Ljdk/internal/net/http/hpack/DecodingCallback;)V", nullptr, $PRIVATE, $method(static_cast<void(Decoder::*)($ByteBuffer*,$DecodingCallback*)>(&Decoder::resumeSizeUpdate)), "java.io.IOException"},
	{"setMaxCapacity", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(Decoder::*)(int32_t)>(&Decoder::setMaxCapacity))},
	{"setMaxCapacity0", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(Decoder::*)(int32_t)>(&Decoder::setMaxCapacity0))},
	{}
};

$InnerClassInfo _Decoder_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.Decoder$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.net.http.hpack.Decoder$State", "jdk.internal.net.http.hpack.Decoder", "State", $PRIVATE | $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _Decoder_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.Decoder",
	"java.lang.Object",
	nullptr,
	_Decoder_FieldInfo_,
	_Decoder_MethodInfo_,
	nullptr,
	nullptr,
	_Decoder_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.Decoder$1,jdk.internal.net.http.hpack.Decoder$State"
};

$Object* allocate$Decoder($Class* clazz) {
	return $of($alloc(Decoder));
}

bool Decoder::$assertionsDisabled = false;
$AtomicLong* Decoder::DECODERS_IDS = nullptr;
$List* Decoder::states = nullptr;

void Decoder::init$(int32_t capacity) {
	$useLocalCurrentObjectStackCache();
	$init($Decoder$State);
	$set(this, state, $Decoder$State::READY);
	this->id = $nc(Decoder::DECODERS_IDS)->incrementAndGet();
	$set(this, logger, $nc($($HPACK::getLogger()))->subLogger($$str({"Decoder#"_s, $$str(this->id)})));
	$init($HPACK$Logger$Level);
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
		$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$new$0, capacity)));
	}
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
		$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$new$1$1, this)));
	}
	setMaxCapacity0(capacity);
	$set(this, table, $new($SimpleHeaderTable, capacity, $($nc(this->logger)->subLogger("HeaderTable"_s))));
	$set(this, integerReader, $new($IntegerReader));
	$set(this, stringReader, $new($StringReader));
	$set(this, name, $new($StringBuilder, 512));
	$set(this, value, $new($StringBuilder, 1024));
}

void Decoder::setMaxCapacity(int32_t capacity) {
	$init($HPACK$Logger$Level);
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
		$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$setMaxCapacity$2$2, capacity)));
	}
	setMaxCapacity0(capacity);
}

void Decoder::setMaxCapacity0(int32_t capacity) {
	$useLocalCurrentObjectStackCache();
	if (capacity < 0) {
		$throwNew($IllegalArgumentException, $$str({"capacity >= 0: "_s, $$str(capacity)}));
	}
	this->capacity = capacity;
}

void Decoder::decode($ByteBuffer* headerBlock, bool endOfHeaderBlock, $DecodingCallback* consumer) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(headerBlock), "headerBlock"_s);
	$Objects::requireNonNull($of(consumer), "consumer"_s);
	$init($HPACK$Logger$Level);
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
		$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$decode$3$3, headerBlock, endOfHeaderBlock)));
	}
	while ($nc(headerBlock)->hasRemaining()) {
		proceed(headerBlock, consumer);
	}
	$init($Decoder$State);
	if (endOfHeaderBlock && this->state != $Decoder$State::READY) {
		$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$decode$4$4, this)));
		$throwNew($IOException, "Unexpected end of header block"_s);
	}
}

void Decoder::proceed($ByteBuffer* input, $DecodingCallback* action) {
	$init($Decoder$1);
	switch ($nc($Decoder$1::$SwitchMap$jdk$internal$net$http$hpack$Decoder$State)->get($nc((this->state))->ordinal())) {
	case 1:
		{
			resumeReady(input);
			break;
		}
	case 2:
		{
			resumeIndexed(input, action);
			break;
		}
	case 3:
		{
			resumeLiteral(input, action);
			break;
		}
	case 4:
		{
			resumeLiteralWithIndexing(input, action);
			break;
		}
	case 5:
		{
			resumeLiteralNeverIndexed(input, action);
			break;
		}
	case 6:
		{
			resumeSizeUpdate(input, action);
			break;
		}
	default:
		{
			$throwNew($InternalError, $$str({"Unexpected decoder state: "_s, this->state}));
		}
	}
}

void Decoder::resumeReady($ByteBuffer* input) {
	$useLocalCurrentObjectStackCache();
	int32_t b = (int32_t)($nc(input)->get(input->position()) & (uint32_t)255);
	$Decoder$State* s = $cast($Decoder$State, $nc(Decoder::states)->get(b));
	$init($HPACK$Logger$Level);
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::EXTRA)) {
		$nc(this->logger)->log($HPACK$Logger$Level::EXTRA, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$resumeReady$5$5, s, b)));
	}
	$init($Decoder$1);
	switch ($nc($Decoder$1::$SwitchMap$jdk$internal$net$http$hpack$Decoder$State)->get($nc((s))->ordinal())) {
	case 2:
		{
			$nc(this->integerReader)->configure(7);
			$init($Decoder$State);
			$set(this, state, $Decoder$State::INDEXED);
			this->firstValueIndex = true;
			break;
		}
	case 3:
		{
			$init($Decoder$State);
			$set(this, state, $Decoder$State::LITERAL);
			this->firstValueIndex = ((int32_t)(b & (uint32_t)15)) != 0;
			if (this->firstValueIndex) {
				$nc(this->integerReader)->configure(4);
			}
			break;
		}
	case 4:
		{
			$init($Decoder$State);
			$set(this, state, $Decoder$State::LITERAL_WITH_INDEXING);
			this->firstValueIndex = ((int32_t)(b & (uint32_t)63)) != 0;
			if (this->firstValueIndex) {
				$nc(this->integerReader)->configure(6);
			}
			break;
		}
	case 5:
		{
			$init($Decoder$State);
			$set(this, state, $Decoder$State::LITERAL_NEVER_INDEXED);
			this->firstValueIndex = ((int32_t)(b & (uint32_t)15)) != 0;
			if (this->firstValueIndex) {
				$nc(this->integerReader)->configure(4);
			}
			break;
		}
	case 6:
		{
			$nc(this->integerReader)->configure(5);
			$init($Decoder$State);
			$set(this, state, $Decoder$State::SIZE_UPDATE);
			this->firstValueIndex = true;
			break;
		}
	default:
		{
			$throwNew($InternalError, $($String::valueOf($of(s))));
		}
	}
	if (!this->firstValueIndex) {
		input->get();
	}
}

void Decoder::resumeIndexed($ByteBuffer* input, $DecodingCallback* action) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(this->integerReader)->read(input)) {
		return;
	}
	this->intValue = $nc(this->integerReader)->get();
	$nc(this->integerReader)->reset();
	$init($HPACK$Logger$Level);
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
		$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$resumeIndexed$6$6, this)));
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($SimpleHeaderTable$HeaderField, f, getHeaderFieldAt(this->intValue));
			$nc(action)->onIndexed(this->intValue, $nc(f)->name, f->value);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$init($Decoder$State);
			$set(this, state, $Decoder$State::READY);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

$SimpleHeaderTable$HeaderField* Decoder::getHeaderFieldAt(int32_t index) {
	$var($SimpleHeaderTable$HeaderField, f, nullptr);
	try {
		$assign(f, $nc(this->table)->get(index));
	} catch ($IndexOutOfBoundsException& e) {
		$throwNew($IOException, "header fields table index"_s, e);
	}
	return f;
}

void Decoder::resumeLiteral($ByteBuffer* input, $DecodingCallback* action) {
	$useLocalCurrentObjectStackCache();
	if (!completeReading(input)) {
		return;
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (this->firstValueIndex) {
				$init($HPACK$Logger$Level);
				if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
					$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$resumeLiteral$7$7, this)));
				}
				$var($SimpleHeaderTable$HeaderField, f, getHeaderFieldAt(this->intValue));
				$nc(action)->onLiteral(this->intValue, static_cast<$CharSequence*>($nc(f)->name), static_cast<$CharSequence*>(this->value), this->valueHuffmanEncoded);
			} else {
				$init($HPACK$Logger$Level);
				if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
					$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$resumeLiteral$8$8, this)));
				}
				$nc(action)->onLiteral(static_cast<$CharSequence*>(this->name), this->nameHuffmanEncoded, static_cast<$CharSequence*>(this->value), this->valueHuffmanEncoded);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			cleanUpAfterReading();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Decoder::resumeLiteralWithIndexing($ByteBuffer* input, $DecodingCallback* action) {
	$useLocalCurrentObjectStackCache();
	if (!completeReading(input)) {
		return;
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			$var($String, n, nullptr);
			$var($String, v, $nc(this->value)->toString());
			if (this->firstValueIndex) {
				$init($HPACK$Logger$Level);
				if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
					$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9, this)));
				}
				$var($SimpleHeaderTable$HeaderField, f, getHeaderFieldAt(this->intValue));
				$assign(n, $nc(f)->name);
				$nc(action)->onLiteralWithIndexing(this->intValue, static_cast<$CharSequence*>(n), static_cast<$CharSequence*>(v), this->valueHuffmanEncoded);
			} else {
				$assign(n, $nc(this->name)->toString());
				$init($HPACK$Logger$Level);
				if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
					$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10, this, n)));
				}
				$nc(action)->onLiteralWithIndexing(static_cast<$CharSequence*>(n), this->nameHuffmanEncoded, static_cast<$CharSequence*>(v), this->valueHuffmanEncoded);
			}
			$nc(this->table)->put(n, v);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			cleanUpAfterReading();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Decoder::resumeLiteralNeverIndexed($ByteBuffer* input, $DecodingCallback* action) {
	$useLocalCurrentObjectStackCache();
	if (!completeReading(input)) {
		return;
	}
	{
		$var($Throwable, var$0, nullptr);
		try {
			if (this->firstValueIndex) {
				$init($HPACK$Logger$Level);
				if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
					$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11, this)));
				}
				$var($SimpleHeaderTable$HeaderField, f, getHeaderFieldAt(this->intValue));
				$nc(action)->onLiteralNeverIndexed(this->intValue, static_cast<$CharSequence*>($nc(f)->name), static_cast<$CharSequence*>(this->value), this->valueHuffmanEncoded);
			} else {
				$init($HPACK$Logger$Level);
				if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
					$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12, this)));
				}
				$nc(action)->onLiteralNeverIndexed(static_cast<$CharSequence*>(this->name), this->nameHuffmanEncoded, static_cast<$CharSequence*>(this->value), this->valueHuffmanEncoded);
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			cleanUpAfterReading();
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Decoder::resumeSizeUpdate($ByteBuffer* input, $DecodingCallback* action) {
	$useLocalCurrentObjectStackCache();
	if (!$nc(this->integerReader)->read(input)) {
		return;
	}
	this->intValue = $nc(this->integerReader)->get();
	$init($HPACK$Logger$Level);
	if ($nc(this->logger)->isLoggable($HPACK$Logger$Level::NORMAL)) {
		$nc(this->logger)->log($HPACK$Logger$Level::NORMAL, static_cast<$Supplier*>($$new(Decoder$$Lambda$lambda$resumeSizeUpdate$13$13, this)));
	}
	if (!Decoder::$assertionsDisabled && !(this->intValue >= 0)) {
		$throwNew($AssertionError);
	}
	if (this->intValue > this->capacity) {
		$throwNew($IOException, $($String::format("Received capacity exceeds expected: capacity=%s, expected=%s"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(this->intValue))),
			$($of($Integer::valueOf(this->capacity)))
		}))));
	}
	$nc(this->integerReader)->reset();
	{
		$var($Throwable, var$0, nullptr);
		try {
			$nc(action)->onSizeUpdate(this->intValue);
			$nc(this->table)->setMaxSize(this->intValue);
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			$init($Decoder$State);
			$set(this, state, $Decoder$State::READY);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

bool Decoder::completeReading($ByteBuffer* input) {
	if (!this->firstValueRead) {
		if (this->firstValueIndex) {
			if (!$nc(this->integerReader)->read(input)) {
				return false;
			}
			this->intValue = $nc(this->integerReader)->get();
			$nc(this->integerReader)->reset();
		} else {
			if (!$nc(this->stringReader)->read(input, this->name)) {
				return false;
			}
			this->nameHuffmanEncoded = $nc(this->stringReader)->isHuffmanEncoded();
			$nc(this->stringReader)->reset();
		}
		this->firstValueRead = true;
		return false;
	} else if (!$nc(this->stringReader)->read(input, this->value)) {
		return false;
	}
	this->valueHuffmanEncoded = $nc(this->stringReader)->isHuffmanEncoded();
	$nc(this->stringReader)->reset();
	return true;
}

void Decoder::cleanUpAfterReading() {
	$nc(this->name)->setLength(0);
	$nc(this->value)->setLength(0);
	this->firstValueRead = false;
	$init($Decoder$State);
	$set(this, state, $Decoder$State::READY);
}

$SimpleHeaderTable* Decoder::getTable() {
	return this->table;
}

$String* Decoder::lambda$resumeSizeUpdate$13() {
	$useLocalCurrentObjectStackCache();
	return $String::format("dynamic table size update %s"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->intValue)))}));
}

$String* Decoder::lambda$resumeLiteralNeverIndexed$12() {
	$useLocalCurrentObjectStackCache();
	return $String::format("literal never indexed (\'%s\', huffman=%b, \'%s\', huffman=%b)"_s, $$new($ObjectArray, {
		$of(this->name),
		$($of($Boolean::valueOf(this->nameHuffmanEncoded))),
		$of(this->value),
		$($of($Boolean::valueOf(this->valueHuffmanEncoded)))
	}));
}

$String* Decoder::lambda$resumeLiteralNeverIndexed$11() {
	$useLocalCurrentObjectStackCache();
	return $String::format("literal never indexed (%s, \'%s\', huffman=%b)"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(this->intValue))),
		$of(this->value),
		$($of($Boolean::valueOf(this->valueHuffmanEncoded)))
	}));
}

$String* Decoder::lambda$resumeLiteralWithIndexing$10($String* n) {
	$useLocalCurrentObjectStackCache();
	return $String::format("literal with incremental indexing (\'%s\', huffman=%b, \'%s\', huffman=%b)"_s, $$new($ObjectArray, {
		$of(n),
		$($of($Boolean::valueOf(this->nameHuffmanEncoded))),
		$of(this->value),
		$($of($Boolean::valueOf(this->valueHuffmanEncoded)))
	}));
}

$String* Decoder::lambda$resumeLiteralWithIndexing$9() {
	$useLocalCurrentObjectStackCache();
	return $String::format("literal with incremental indexing (%s, \'%s\', huffman=%b)"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(this->intValue))),
		$of(this->value),
		$($of($Boolean::valueOf(this->valueHuffmanEncoded)))
	}));
}

$String* Decoder::lambda$resumeLiteral$8() {
	$useLocalCurrentObjectStackCache();
	return $String::format("literal without indexing (\'%s\', huffman=%b, \'%s\', huffman=%b)"_s, $$new($ObjectArray, {
		$of(this->name),
		$($of($Boolean::valueOf(this->nameHuffmanEncoded))),
		$of(this->value),
		$($of($Boolean::valueOf(this->valueHuffmanEncoded)))
	}));
}

$String* Decoder::lambda$resumeLiteral$7() {
	$useLocalCurrentObjectStackCache();
	return $String::format("literal without indexing (%s, \'%s\', huffman=%b)"_s, $$new($ObjectArray, {
		$($of($Integer::valueOf(this->intValue))),
		$of(this->value),
		$($of($Boolean::valueOf(this->valueHuffmanEncoded)))
	}));
}

$String* Decoder::lambda$resumeIndexed$6() {
	$useLocalCurrentObjectStackCache();
	return $String::format("indexed %s"_s, $$new($ObjectArray, {$($of($Integer::valueOf(this->intValue)))}));
}

$String* Decoder::lambda$resumeReady$5($Decoder$State* s, int32_t b) {
	$init(Decoder);
	$useLocalCurrentObjectStackCache();
	return $String::format("next binary representation %s (first byte 0x%02x)"_s, $$new($ObjectArray, {
		$of(s),
		$($of($Integer::valueOf(b)))
	}));
}

$String* Decoder::lambda$decode$4() {
	return $String::format("unexpected end of %s representation"_s, $$new($ObjectArray, {$of(this->state)}));
}

$String* Decoder::lambda$decode$3($ByteBuffer* headerBlock, bool endOfHeaderBlock) {
	$init(Decoder);
	$useLocalCurrentObjectStackCache();
	return $String::format("reading %s, end of header block? %s"_s, $$new($ObjectArray, {
		$of(headerBlock),
		$($of($Boolean::valueOf(endOfHeaderBlock)))
	}));
}

$String* Decoder::lambda$setMaxCapacity$2(int32_t capacity) {
	$init(Decoder);
	$useLocalCurrentObjectStackCache();
	return $String::format("setting maximum table size to %s"_s, $$new($ObjectArray, {$($of($Integer::valueOf(capacity)))}));
}

$String* Decoder::lambda$new$1() {
	$useLocalCurrentObjectStackCache();
	$var($String, hashCode, $Integer::toHexString($System::identityHashCode(this)));
	return $String::format("toString=\'%s\', identityHashCode=%s"_s, $$new($ObjectArray, {
		$($of(toString())),
		$of(hashCode)
	}));
}

$String* Decoder::lambda$new$0(int32_t capacity) {
	$init(Decoder);
	$useLocalCurrentObjectStackCache();
	return $String::format("new decoder with maximum table size %s"_s, $$new($ObjectArray, {$($of($Integer::valueOf(capacity)))}));
}

void clinit$Decoder($Class* class$) {
	$useLocalCurrentObjectStackCache();
	Decoder::$assertionsDisabled = !Decoder::class$->desiredAssertionStatus();
	$assignStatic(Decoder::DECODERS_IDS, $new($AtomicLong));
	{
		$var($Decoder$StateArray, s, $new($Decoder$StateArray, 256));
		for (int32_t i = 0; i < s->length; ++i) {
			if (((int32_t)(i & (uint32_t)128)) == 128) {
				$init($Decoder$State);
				s->set(i, $Decoder$State::INDEXED);
			} else if (((int32_t)(i & (uint32_t)192)) == 64) {
				$init($Decoder$State);
				s->set(i, $Decoder$State::LITERAL_WITH_INDEXING);
			} else if (((int32_t)(i & (uint32_t)224)) == 32) {
				$init($Decoder$State);
				s->set(i, $Decoder$State::SIZE_UPDATE);
			} else if (((int32_t)(i & (uint32_t)240)) == 16) {
				$init($Decoder$State);
				s->set(i, $Decoder$State::LITERAL_NEVER_INDEXED);
			} else if (((int32_t)(i & (uint32_t)240)) == 0) {
				$init($Decoder$State);
				s->set(i, $Decoder$State::LITERAL);
			} else {
				$throwNew($InternalError, $($String::valueOf(i)));
			}
		}
		$assignStatic(Decoder::states, $List::of(s));
	}
}

Decoder::Decoder() {
}

$Class* Decoder::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Decoder$$Lambda$lambda$new$0::classInfo$.name)) {
			return Decoder$$Lambda$lambda$new$0::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$new$1$1::classInfo$.name)) {
			return Decoder$$Lambda$lambda$new$1$1::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$setMaxCapacity$2$2::classInfo$.name)) {
			return Decoder$$Lambda$lambda$setMaxCapacity$2$2::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$decode$3$3::classInfo$.name)) {
			return Decoder$$Lambda$lambda$decode$3$3::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$decode$4$4::classInfo$.name)) {
			return Decoder$$Lambda$lambda$decode$4$4::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$resumeReady$5$5::classInfo$.name)) {
			return Decoder$$Lambda$lambda$resumeReady$5$5::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$resumeIndexed$6$6::classInfo$.name)) {
			return Decoder$$Lambda$lambda$resumeIndexed$6$6::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$resumeLiteral$7$7::classInfo$.name)) {
			return Decoder$$Lambda$lambda$resumeLiteral$7$7::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$resumeLiteral$8$8::classInfo$.name)) {
			return Decoder$$Lambda$lambda$resumeLiteral$8$8::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9::classInfo$.name)) {
			return Decoder$$Lambda$lambda$resumeLiteralWithIndexing$9$9::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10::classInfo$.name)) {
			return Decoder$$Lambda$lambda$resumeLiteralWithIndexing$10$10::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11::classInfo$.name)) {
			return Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$11$11::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12::classInfo$.name)) {
			return Decoder$$Lambda$lambda$resumeLiteralNeverIndexed$12$12::load$(name, initialize);
		}
		if (name->equals(Decoder$$Lambda$lambda$resumeSizeUpdate$13$13::classInfo$.name)) {
			return Decoder$$Lambda$lambda$resumeSizeUpdate$13$13::load$(name, initialize);
		}
	}
	$loadClass(Decoder, name, initialize, &_Decoder_ClassInfo_, clinit$Decoder, allocate$Decoder);
	return class$;
}

$Class* Decoder::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk