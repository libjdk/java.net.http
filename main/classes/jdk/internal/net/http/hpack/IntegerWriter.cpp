#include <jdk/internal/net/http/hpack/IntegerWriter.h>

#include <java/lang/IllegalStateException.h>
#include <java/lang/InternalError.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/Arrays.h>
#include <jcpp.h>

#undef CONFIGURED
#undef DONE
#undef FIRST_BYTE_WRITTEN
#undef N
#undef NEW

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Arrays = ::java::util::Arrays;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _IntegerWriter_FieldInfo_[] = {
	{"NEW", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IntegerWriter, NEW)},
	{"CONFIGURED", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IntegerWriter, CONFIGURED)},
	{"FIRST_BYTE_WRITTEN", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IntegerWriter, FIRST_BYTE_WRITTEN)},
	{"DONE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(IntegerWriter, DONE)},
	{"state", "I", nullptr, $PRIVATE, $field(IntegerWriter, state)},
	{"payload", "I", nullptr, $PRIVATE, $field(IntegerWriter, payload)},
	{"N", "I", nullptr, $PRIVATE, $field(IntegerWriter, N)},
	{"value", "I", nullptr, $PRIVATE, $field(IntegerWriter, value)},
	{}
};

$MethodInfo _IntegerWriter_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(IntegerWriter::*)()>(&IntegerWriter::init$))},
	{"checkPrefix", "(I)V", nullptr, $PRIVATE | $STATIC, $method(static_cast<void(*)(int32_t)>(&IntegerWriter::checkPrefix))},
	{"configure", "(III)Ljdk/internal/net/http/hpack/IntegerWriter;", nullptr, $PUBLIC, $method(static_cast<IntegerWriter*(IntegerWriter::*)(int32_t,int32_t,int32_t)>(&IntegerWriter::configure))},
	{"reset", "()Ljdk/internal/net/http/hpack/IntegerWriter;", nullptr, $PUBLIC, $method(static_cast<IntegerWriter*(IntegerWriter::*)()>(&IntegerWriter::reset))},
	{"write", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PUBLIC, $method(static_cast<bool(IntegerWriter::*)($ByteBuffer*)>(&IntegerWriter::write))},
	{}
};

$ClassInfo _IntegerWriter_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.IntegerWriter",
	"java.lang.Object",
	nullptr,
	_IntegerWriter_FieldInfo_,
	_IntegerWriter_MethodInfo_
};

$Object* allocate$IntegerWriter($Class* clazz) {
	return $of($alloc(IntegerWriter));
}

void IntegerWriter::init$() {
	this->state = IntegerWriter::NEW;
}

IntegerWriter* IntegerWriter::configure(int32_t value, int32_t N, int32_t payload) {
	$useLocalCurrentObjectStackCache();
	if (this->state != IntegerWriter::NEW) {
		$throwNew($IllegalStateException, "Already configured"_s);
	}
	if (value < 0) {
		$throwNew($IllegalArgumentException, $$str({"value >= 0: value="_s, $$str(value)}));
	}
	checkPrefix(N);
	this->value = value;
	this->N = N;
	this->payload = (int32_t)(((int32_t)(payload & (uint32_t)255)) & (uint32_t)($sl(-1, N)));
	this->state = IntegerWriter::CONFIGURED;
	return this;
}

bool IntegerWriter::write($ByteBuffer* output) {
	$useLocalCurrentObjectStackCache();
	if (this->state == IntegerWriter::NEW) {
		$throwNew($IllegalStateException, "Configure first"_s);
	}
	if (this->state == IntegerWriter::DONE) {
		return true;
	}
	if (!$nc(output)->hasRemaining()) {
		return false;
	}
	if (this->state == IntegerWriter::CONFIGURED) {
		int32_t max = ($sl(2, this->N - 1)) - 1;
		if (this->value < max) {
			$nc(output)->put((int8_t)(this->payload | this->value));
			this->state = IntegerWriter::DONE;
			return true;
		}
		$nc(output)->put((int8_t)(this->payload | max));
		this->value -= max;
		this->state = IntegerWriter::FIRST_BYTE_WRITTEN;
	}
	if (this->state == IntegerWriter::FIRST_BYTE_WRITTEN) {
		while (this->value >= 128 && $nc(output)->hasRemaining()) {
			output->put((int8_t)(((int32_t)(this->value & (uint32_t)127)) + 128));
			this->value /= 128;
		}
		if (!$nc(output)->hasRemaining()) {
			return false;
		}
		$nc(output)->put((int8_t)this->value);
		this->state = IntegerWriter::DONE;
		return true;
	}
	$throwNew($InternalError, $($Arrays::toString($$new($ObjectArray, {
		$($of($Integer::valueOf(this->state))),
		$($of($Integer::valueOf(this->payload))),
		$($of($Integer::valueOf(this->N))),
		$($of($Integer::valueOf(this->value)))
	}))));
}

void IntegerWriter::checkPrefix(int32_t N) {
	$useLocalCurrentObjectStackCache();
	if (N < 1 || N > 8) {
		$throwNew($IllegalArgumentException, $$str({"1 <= N <= 8: N= "_s, $$str(N)}));
	}
}

IntegerWriter* IntegerWriter::reset() {
	this->state = IntegerWriter::NEW;
	return this;
}

IntegerWriter::IntegerWriter() {
}

$Class* IntegerWriter::load$($String* name, bool initialize) {
	$loadClass(IntegerWriter, name, initialize, &_IntegerWriter_ClassInfo_, allocate$IntegerWriter);
	return class$;
}

$Class* IntegerWriter::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk