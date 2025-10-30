#include <jdk/internal/net/http/SocketTube$SliceBufferSource.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/List.h>
#include <java/util/Objects.h>
#include <java/util/function/Supplier.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
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
using $List = ::java::util::List;
using $Objects = ::java::util::Objects;
using $Supplier = ::java::util::function::Supplier;
using $SocketTube = ::jdk::internal::net::http::SocketTube;
using $SocketTube$BufferSource = ::jdk::internal::net::http::SocketTube$BufferSource;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class SocketTube$SliceBufferSource$$Lambda$getBuffer : public $Supplier {
	$class(SocketTube$SliceBufferSource$$Lambda$getBuffer, $NO_CLASS_INIT, $Supplier)
public:
	void init$() {
	}
	virtual $Object* get() override {
		 return $of($Utils::getBuffer());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<SocketTube$SliceBufferSource$$Lambda$getBuffer>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo SocketTube$SliceBufferSource$$Lambda$getBuffer::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$SliceBufferSource$$Lambda$getBuffer::*)()>(&SocketTube$SliceBufferSource$$Lambda$getBuffer::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo SocketTube$SliceBufferSource$$Lambda$getBuffer::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.SocketTube$SliceBufferSource$$Lambda$getBuffer",
	"java.lang.Object",
	"java.util.function.Supplier",
	nullptr,
	methodInfos
};
$Class* SocketTube$SliceBufferSource$$Lambda$getBuffer::load$($String* name, bool initialize) {
	$loadClass(SocketTube$SliceBufferSource$$Lambda$getBuffer, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* SocketTube$SliceBufferSource$$Lambda$getBuffer::class$ = nullptr;

$FieldInfo _SocketTube$SliceBufferSource_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(SocketTube$SliceBufferSource, $assertionsDisabled)},
	{"factory", "Ljava/util/function/Supplier;", "Ljava/util/function/Supplier<Ljava/nio/ByteBuffer;>;", $PRIVATE | $FINAL, $field(SocketTube$SliceBufferSource, factory)},
	{"current", "Ljava/nio/ByteBuffer;", nullptr, $PRIVATE | $VOLATILE, $field(SocketTube$SliceBufferSource, current)},
	{}
};

$MethodInfo _SocketTube$SliceBufferSource_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SocketTube$SliceBufferSource::*)()>(&SocketTube$SliceBufferSource::init$))},
	{"<init>", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/nio/ByteBuffer;>;)V", $PUBLIC, $method(static_cast<void(SocketTube$SliceBufferSource::*)($Supplier*)>(&SocketTube$SliceBufferSource::init$))},
	{"append", "(Ljava/util/List;Ljava/nio/ByteBuffer;I)Ljava/util/List;", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Ljava/nio/ByteBuffer;I)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PUBLIC | $FINAL},
	{"getBuffer", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _SocketTube$SliceBufferSource_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.SocketTube$SliceBufferSource", "jdk.internal.net.http.SocketTube", "SliceBufferSource", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.SocketTube$BufferSource", "jdk.internal.net.http.SocketTube", "BufferSource", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _SocketTube$SliceBufferSource_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.SocketTube$SliceBufferSource",
	"java.lang.Object",
	"jdk.internal.net.http.SocketTube$BufferSource",
	_SocketTube$SliceBufferSource_FieldInfo_,
	_SocketTube$SliceBufferSource_MethodInfo_,
	nullptr,
	nullptr,
	_SocketTube$SliceBufferSource_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.SocketTube"
};

$Object* allocate$SocketTube$SliceBufferSource($Class* clazz) {
	return $of($alloc(SocketTube$SliceBufferSource));
}

bool SocketTube$SliceBufferSource::$assertionsDisabled = false;

void SocketTube$SliceBufferSource::init$() {
	SocketTube$SliceBufferSource::init$(static_cast<$Supplier*>($$new(SocketTube$SliceBufferSource$$Lambda$getBuffer)));
}

void SocketTube$SliceBufferSource::init$($Supplier* factory) {
	$set(this, factory, $cast($Supplier, $Objects::requireNonNull(factory)));
}

$ByteBuffer* SocketTube$SliceBufferSource::getBuffer() {
	$var($ByteBuffer, buf, this->current);
	$assign(buf, (buf == nullptr || !$nc(buf)->hasRemaining()) ? ($set(this, current, $cast($ByteBuffer, $nc(this->factory)->get()))) : buf);
	if (!SocketTube$SliceBufferSource::$assertionsDisabled && !$nc(buf)->hasRemaining()) {
		$throwNew($AssertionError);
	}
	return buf;
}

$List* SocketTube$SliceBufferSource::append($List* list, $ByteBuffer* buf, int32_t start) {
	$useLocalCurrentObjectStackCache();
	int32_t limit = $nc(buf)->limit();
	buf->limit(buf->position());
	buf->position(start);
	$var($ByteBuffer, slice, buf->slice());
	buf->position(buf->limit());
	buf->limit(limit);
	return $SocketTube::listOf(list, $($nc(slice)->asReadOnlyBuffer()));
}

void clinit$SocketTube$SliceBufferSource($Class* class$) {
	$load($SocketTube);
	SocketTube$SliceBufferSource::$assertionsDisabled = !$SocketTube::class$->desiredAssertionStatus();
}

SocketTube$SliceBufferSource::SocketTube$SliceBufferSource() {
}

$Class* SocketTube$SliceBufferSource::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(SocketTube$SliceBufferSource$$Lambda$getBuffer::classInfo$.name)) {
			return SocketTube$SliceBufferSource$$Lambda$getBuffer::load$(name, initialize);
		}
	}
	$loadClass(SocketTube$SliceBufferSource, name, initialize, &_SocketTube$SliceBufferSource_ClassInfo_, clinit$SocketTube$SliceBufferSource, allocate$SocketTube$SliceBufferSource);
	return class$;
}

$Class* SocketTube$SliceBufferSource::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk