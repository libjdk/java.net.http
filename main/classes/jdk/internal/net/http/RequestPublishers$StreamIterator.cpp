#include <jdk/internal/net/http/RequestPublishers$StreamIterator.h>

#include <java/io/IOException.h>
#include <java/io/InputStream.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/NoSuchElementException.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $IOException = ::java::io::IOException;
using $InputStream = ::java::io::InputStream;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Iterator = ::java::util::Iterator;
using $NoSuchElementException = ::java::util::NoSuchElementException;
using $Supplier = ::java::util::function::Supplier;
using $RequestPublishers = ::jdk::internal::net::http::RequestPublishers;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class RequestPublishers$StreamIterator$$Lambda$getBuffer : public $Supplier {
	$class(RequestPublishers$StreamIterator$$Lambda$getBuffer, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($Utils::getBuffer());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<RequestPublishers$StreamIterator$$Lambda$getBuffer>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo RequestPublishers$StreamIterator$$Lambda$getBuffer::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(RequestPublishers$StreamIterator$$Lambda$getBuffer::*)()>(&RequestPublishers$StreamIterator$$Lambda$getBuffer::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo RequestPublishers$StreamIterator$$Lambda$getBuffer::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.RequestPublishers$StreamIterator$$Lambda$getBuffer",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* RequestPublishers$StreamIterator$$Lambda$getBuffer::load$($String* name, bool initialize) {
	$loadClass(RequestPublishers$StreamIterator$$Lambda$getBuffer, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* RequestPublishers$StreamIterator$$Lambda$getBuffer::class$ = nullptr;

$FieldInfo _RequestPublishers$StreamIterator_FieldInfo_[] = {
	{"is", "Ljava/io/InputStream;", nullptr, $FINAL, $field(RequestPublishers$StreamIterator, is)},
	{"bufSupplier", "Ljava/util/function/Supplier;", "Ljava/util/function/Supplier<+Ljava/nio/ByteBuffer;>;", $FINAL, $field(RequestPublishers$StreamIterator, bufSupplier)},
	{"eof", "Z", nullptr, $PRIVATE | $VOLATILE, $field(RequestPublishers$StreamIterator, eof)},
	{"nextBuffer", "Ljava/nio/ByteBuffer;", nullptr, $VOLATILE, $field(RequestPublishers$StreamIterator, nextBuffer)},
	{"need2Read", "Z", nullptr, $VOLATILE, $field(RequestPublishers$StreamIterator, need2Read)},
	{"haveNext", "Z", nullptr, $VOLATILE, $field(RequestPublishers$StreamIterator, haveNext)},
	{}
};

$MethodInfo _RequestPublishers$StreamIterator_MethodInfo_[] = {
	{"<init>", "(Ljava/io/InputStream;)V", nullptr, 0, $method(static_cast<void(RequestPublishers$StreamIterator::*)($InputStream*)>(&RequestPublishers$StreamIterator::init$))},
	{"<init>", "(Ljava/io/InputStream;Ljava/util/function/Supplier;)V", "(Ljava/io/InputStream;Ljava/util/function/Supplier<+Ljava/nio/ByteBuffer;>;)V", 0, $method(static_cast<void(RequestPublishers$StreamIterator::*)($InputStream*,$Supplier*)>(&RequestPublishers$StreamIterator::init$))},
	{"closeStream", "()V", nullptr, $PRIVATE, $method(static_cast<void(RequestPublishers$StreamIterator::*)()>(&RequestPublishers$StreamIterator::closeStream))},
	{"hasNext", "()Z", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"next", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"read", "()I", nullptr, $PRIVATE, $method(static_cast<int32_t(RequestPublishers$StreamIterator::*)()>(&RequestPublishers$StreamIterator::read)), "java.io.IOException"},
	{}
};

$InnerClassInfo _RequestPublishers$StreamIterator_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.RequestPublishers$StreamIterator", "jdk.internal.net.http.RequestPublishers", "StreamIterator", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _RequestPublishers$StreamIterator_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.RequestPublishers$StreamIterator",
	"java.lang.Object",
	"java.util.Iterator",
	_RequestPublishers$StreamIterator_FieldInfo_,
	_RequestPublishers$StreamIterator_MethodInfo_,
	"Ljava/lang/Object;Ljava/util/Iterator<Ljava/nio/ByteBuffer;>;",
	nullptr,
	_RequestPublishers$StreamIterator_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.RequestPublishers"
};

$Object* allocate$RequestPublishers$StreamIterator($Class* clazz) {
	return $of($alloc(RequestPublishers$StreamIterator));
}

void RequestPublishers$StreamIterator::init$($InputStream* is) {
	RequestPublishers$StreamIterator::init$(is, static_cast<$Supplier*>($$new(RequestPublishers$StreamIterator$$Lambda$getBuffer)));
}

void RequestPublishers$StreamIterator::init$($InputStream* is, $Supplier* bufSupplier) {
	this->need2Read = true;
	$set(this, is, is);
	$set(this, bufSupplier, bufSupplier);
}

int32_t RequestPublishers$StreamIterator::read() {
	if (this->eof) {
		return -1;
	}
	$set(this, nextBuffer, $cast($ByteBuffer, $nc(this->bufSupplier)->get()));
	$nc(this->nextBuffer)->clear();
	$var($bytes, buf, $cast($bytes, $nc(this->nextBuffer)->array()));
	int32_t offset = $nc(this->nextBuffer)->arrayOffset();
	int32_t cap = $nc(this->nextBuffer)->capacity();
	int32_t n = $nc(this->is)->read(buf, offset, cap);
	if (n == -1) {
		this->eof = true;
		return -1;
	}
	$nc(this->nextBuffer)->limit(n);
	$nc(this->nextBuffer)->position(0);
	return n;
}

void RequestPublishers$StreamIterator::closeStream() {
	try {
		$nc(this->is)->close();
	} catch ($IOException& e) {
		$throwNew($UncheckedIOException, e);
	}
}

bool RequestPublishers$StreamIterator::hasNext() {
	$synchronized(this) {
		if (this->need2Read) {
			{
				$var($Throwable, var$0, nullptr);
				try {
					try {
						this->haveNext = read() != -1;
						if (this->haveNext) {
							this->need2Read = false;
						}
					} catch ($IOException& e) {
						this->haveNext = false;
						this->need2Read = false;
						$throwNew($UncheckedIOException, e);
					}
				} catch ($Throwable& var$1) {
					$assign(var$0, var$1);
				} /*finally*/ {
					if (!this->haveNext) {
						closeStream();
					}
				}
				if (var$0 != nullptr) {
					$throw(var$0);
				}
			}
		}
		return this->haveNext;
	}
}

$Object* RequestPublishers$StreamIterator::next() {
	$synchronized(this) {
		if (!hasNext()) {
			$throwNew($NoSuchElementException);
		}
		this->need2Read = true;
		return $of(this->nextBuffer);
	}
}

RequestPublishers$StreamIterator::RequestPublishers$StreamIterator() {
}

$Class* RequestPublishers$StreamIterator::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(RequestPublishers$StreamIterator$$Lambda$getBuffer::classInfo$.name)) {
			return RequestPublishers$StreamIterator$$Lambda$getBuffer::load$(name, initialize);
		}
	}
	$loadClass(RequestPublishers$StreamIterator, name, initialize, &_RequestPublishers$StreamIterator_ClassInfo_, allocate$RequestPublishers$StreamIterator);
	return class$;
}

$Class* RequestPublishers$StreamIterator::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk