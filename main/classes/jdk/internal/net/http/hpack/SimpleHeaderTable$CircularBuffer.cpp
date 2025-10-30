#include <jdk/internal/net/http/hpack/SimpleHeaderTable$CircularBuffer.h>

#include <java/lang/IllegalStateException.h>
#include <java/lang/IndexOutOfBoundsException.h>
#include <java/util/NoSuchElementException.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/hpack/SimpleHeaderTable.h>
#include <jcpp.h>

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $IndexOutOfBoundsException = ::java::lang::IndexOutOfBoundsException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $SimpleHeaderTable = ::jdk::internal::net::http::hpack::SimpleHeaderTable;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _SimpleHeaderTable$CircularBuffer_FieldInfo_[] = {
	{"tail", "I", nullptr, 0, $field(SimpleHeaderTable$CircularBuffer, tail)},
	{"head", "I", nullptr, 0, $field(SimpleHeaderTable$CircularBuffer, head)},
	{"size", "I", nullptr, 0, $field(SimpleHeaderTable$CircularBuffer, size)},
	{"capacity", "I", nullptr, 0, $field(SimpleHeaderTable$CircularBuffer, capacity)},
	{"elements", "[Ljava/lang/Object;", nullptr, 0, $field(SimpleHeaderTable$CircularBuffer, elements)},
	{}
};

$MethodInfo _SimpleHeaderTable$CircularBuffer_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, 0, $method(static_cast<void(SimpleHeaderTable$CircularBuffer::*)(int32_t)>(&SimpleHeaderTable$CircularBuffer::init$))},
	{"add", "(Ljava/lang/Object;)V", "(TE;)V", 0, $method(static_cast<void(SimpleHeaderTable$CircularBuffer::*)(Object$*)>(&SimpleHeaderTable$CircularBuffer::add))},
	{"get", "(I)Ljava/lang/Object;", "(I)TE;", 0, $method(static_cast<$Object*(SimpleHeaderTable$CircularBuffer::*)(int32_t)>(&SimpleHeaderTable$CircularBuffer::get))},
	{"remove", "()Ljava/lang/Object;", "()TE;", 0, $method(static_cast<$Object*(SimpleHeaderTable$CircularBuffer::*)()>(&SimpleHeaderTable$CircularBuffer::remove))},
	{"resize", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(SimpleHeaderTable$CircularBuffer::*)(int32_t)>(&SimpleHeaderTable$CircularBuffer::resize))},
	{}
};

$InnerClassInfo _SimpleHeaderTable$CircularBuffer_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.SimpleHeaderTable$CircularBuffer", "jdk.internal.net.http.hpack.SimpleHeaderTable", "CircularBuffer", $STATIC | $FINAL},
	{}
};

$ClassInfo _SimpleHeaderTable$CircularBuffer_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.SimpleHeaderTable$CircularBuffer",
	"java.lang.Object",
	nullptr,
	_SimpleHeaderTable$CircularBuffer_FieldInfo_,
	_SimpleHeaderTable$CircularBuffer_MethodInfo_,
	"<E:Ljava/lang/Object;>Ljava/lang/Object;",
	nullptr,
	_SimpleHeaderTable$CircularBuffer_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.SimpleHeaderTable"
};

$Object* allocate$SimpleHeaderTable$CircularBuffer($Class* clazz) {
	return $of($alloc(SimpleHeaderTable$CircularBuffer));
}

void SimpleHeaderTable$CircularBuffer::init$(int32_t capacity) {
	this->capacity = $Utils::pow2Size(capacity);
	$set(this, elements, $new($ObjectArray, this->capacity));
}

void SimpleHeaderTable$CircularBuffer::add(Object$* elem) {
	$useLocalCurrentObjectStackCache();
	if (this->size == this->capacity) {
		$throwNew($IllegalStateException, $($String::format("No room for \'%s\': capacity=%s"_s, $$new($ObjectArray, {
			elem,
			$($of($Integer::valueOf(this->capacity)))
		}))));
	}
	$nc(this->elements)->set(this->head, elem);
	this->head = (int32_t)((this->head + 1) & (uint32_t)(this->capacity - 1));
	++this->size;
}

$Object* SimpleHeaderTable$CircularBuffer::remove() {
	if (this->size == 0) {
		$throwNew($NoSuchElementException, "Empty"_s);
	}
	$var($Object, elem, $nc(this->elements)->get(this->tail));
	$nc(this->elements)->set(this->tail, nullptr);
	this->tail = (int32_t)((this->tail + 1) & (uint32_t)(this->capacity - 1));
	--this->size;
	return $of(elem);
}

$Object* SimpleHeaderTable$CircularBuffer::get(int32_t index) {
	$useLocalCurrentObjectStackCache();
	if (index < 0 || index >= this->size) {
		$throwNew($IndexOutOfBoundsException, $($String::format("0 <= index <= capacity: index=%s, capacity=%s"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(index))),
			$($of($Integer::valueOf(this->capacity)))
		}))));
	}
	int32_t idx = (int32_t)((this->tail + (this->size - index - 1)) & (uint32_t)(this->capacity - 1));
	return $of($nc(this->elements)->get(idx));
}

void SimpleHeaderTable$CircularBuffer::resize(int32_t newCapacity) {
	$useLocalCurrentObjectStackCache();
	if (newCapacity < this->size) {
		$throwNew($IllegalStateException, $($String::format("newCapacity >= size: newCapacity=%s, size=%s"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf(newCapacity))),
			$($of($Integer::valueOf(this->size)))
		}))));
	}
	int32_t capacity = $Utils::pow2Size(newCapacity);
	$var($ObjectArray, newElements, $new($ObjectArray, capacity));
	if (this->tail < this->head || this->size == 0) {
		$System::arraycopy(this->elements, this->tail, newElements, 0, this->size);
	} else {
		$System::arraycopy(this->elements, this->tail, newElements, 0, $nc(this->elements)->length - this->tail);
		$System::arraycopy(this->elements, 0, newElements, $nc(this->elements)->length - this->tail, this->head);
	}
	$set(this, elements, newElements);
	this->tail = 0;
	this->head = this->size;
	this->capacity = capacity;
}

SimpleHeaderTable$CircularBuffer::SimpleHeaderTable$CircularBuffer() {
}

$Class* SimpleHeaderTable$CircularBuffer::load$($String* name, bool initialize) {
	$loadClass(SimpleHeaderTable$CircularBuffer, name, initialize, &_SimpleHeaderTable$CircularBuffer_ClassInfo_, allocate$SimpleHeaderTable$CircularBuffer);
	return class$;
}

$Class* SimpleHeaderTable$CircularBuffer::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk