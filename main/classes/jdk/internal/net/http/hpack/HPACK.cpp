#include <jdk/internal/net/http/hpack/HPACK.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <java/lang/Math.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/nio/ByteBuffer.h>
#include <java/security/AccessController.h>
#include <java/security/PrivilegedAction.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <jdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger$Level.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger.h>
#include <jdk/internal/net/http/hpack/HPACK$RootLogger.h>
#include <jcpp.h>

#undef DEBUG
#undef EXTRA
#undef HPACK
#undef INFO
#undef LOGGER
#undef NONE
#undef NORMAL
#undef PROPERTY

using $Serializable = ::java::io::Serializable;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $InternalError = ::java::lang::InternalError;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AccessController = ::java::security::AccessController;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Collection = ::java::util::Collection;
using $Map = ::java::util::Map;
using $Set = ::java::util::Set;
using $Supplier = ::java::util::function::Supplier;
using $Collector = ::java::util::stream::Collector;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $HPACK$BufferUpdateConsumer = ::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer;
using $HPACK$Logger = ::jdk::internal::net::http::hpack::HPACK$Logger;
using $HPACK$Logger$Level = ::jdk::internal::net::http::hpack::HPACK$Logger$Level;
using $HPACK$RootLogger = ::jdk::internal::net::http::hpack::HPACK$RootLogger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

class HPACK$$Lambda$lambda$static$0 : public $PrivilegedAction {
	$class(HPACK$$Lambda$lambda$static$0, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* PROPERTY) {
		$set(this, PROPERTY, PROPERTY);
	}
	virtual $Object* run() override {
		 return $of(HPACK::lambda$static$0(PROPERTY));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HPACK$$Lambda$lambda$static$0>());
	}
	$String* PROPERTY = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HPACK$$Lambda$lambda$static$0::fieldInfos[2] = {
	{"PROPERTY", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HPACK$$Lambda$lambda$static$0, PROPERTY)},
	{}
};
$MethodInfo HPACK$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(HPACK$$Lambda$lambda$static$0::*)($String*)>(&HPACK$$Lambda$lambda$static$0::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HPACK$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.HPACK$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* HPACK$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(HPACK$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HPACK$$Lambda$lambda$static$0::class$ = nullptr;

class HPACK$$Lambda$lambda$static$1$1 : public $Supplier {
	$class(HPACK$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* PROPERTY, $String* value) {
		$set(this, PROPERTY, PROPERTY);
		$set(this, value, value);
	}
	virtual $Object* get() override {
		 return $of(HPACK::lambda$static$1(PROPERTY, value));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HPACK$$Lambda$lambda$static$1$1>());
	}
	$String* PROPERTY = nullptr;
	$String* value = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HPACK$$Lambda$lambda$static$1$1::fieldInfos[3] = {
	{"PROPERTY", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HPACK$$Lambda$lambda$static$1$1, PROPERTY)},
	{"value", "Ljava/lang/String;", nullptr, $PUBLIC, $field(HPACK$$Lambda$lambda$static$1$1, value)},
	{}
};
$MethodInfo HPACK$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(HPACK$$Lambda$lambda$static$1$1::*)($String*,$String*)>(&HPACK$$Lambda$lambda$static$1$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HPACK$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.HPACK$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* HPACK$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(HPACK$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HPACK$$Lambda$lambda$static$1$1::class$ = nullptr;

class HPACK$$Lambda$lambda$static$2$2 : public $Supplier {
	$class(HPACK$$Lambda$lambda$static$2$2, $NO_CLASS_INIT, $Supplier)
public:
	void init$($HPACK$Logger$Level* l) {
		$set(this, l, l);
	}
	virtual $Object* get() override {
		 return $of(HPACK::lambda$static$2(l));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<HPACK$$Lambda$lambda$static$2$2>());
	}
	$HPACK$Logger$Level* l = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo HPACK$$Lambda$lambda$static$2$2::fieldInfos[2] = {
	{"l", "Ljdk/internal/net/http/hpack/HPACK$Logger$Level;", nullptr, $PUBLIC, $field(HPACK$$Lambda$lambda$static$2$2, l)},
	{}
};
$MethodInfo HPACK$$Lambda$lambda$static$2$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/hpack/HPACK$Logger$Level;)V", nullptr, $PUBLIC, $method(static_cast<void(HPACK$$Lambda$lambda$static$2$2::*)($HPACK$Logger$Level*)>(&HPACK$$Lambda$lambda$static$2$2::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo HPACK$$Lambda$lambda$static$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.hpack.HPACK$$Lambda$lambda$static$2$2",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* HPACK$$Lambda$lambda$static$2$2::load$($String* name, bool initialize) {
	$loadClass(HPACK$$Lambda$lambda$static$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* HPACK$$Lambda$lambda$static$2$2::class$ = nullptr;

$FieldInfo _HPACK_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(HPACK, $assertionsDisabled)},
	{"LOGGER", "Ljdk/internal/net/http/hpack/HPACK$RootLogger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(HPACK, LOGGER)},
	{"logLevels", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljdk/internal/net/http/hpack/HPACK$Logger$Level;>;", $PRIVATE | $STATIC | $FINAL, $staticField(HPACK, logLevels)},
	{}
};

$MethodInfo _HPACK_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(HPACK::*)()>(&HPACK::init$))},
	{"bytesForBits", "(I)I", nullptr, $STATIC, $method(static_cast<int32_t(*)(int32_t)>(&HPACK::bytesForBits))},
	{"getLogger", "()Ljdk/internal/net/http/hpack/HPACK$Logger;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$HPACK$Logger*(*)()>(&HPACK::getLogger))},
	{"lambda$static$0", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($String*)>(&HPACK::lambda$static$0))},
	{"lambda$static$1", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($String*,$String*)>(&HPACK::lambda$static$1))},
	{"lambda$static$2", "(Ljdk/internal/net/http/hpack/HPACK$Logger$Level;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($HPACK$Logger$Level*)>(&HPACK::lambda$static$2))},
	{"read", "(Ljava/nio/ByteBuffer;JILjdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer;)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($ByteBuffer*,int64_t,int32_t,$HPACK$BufferUpdateConsumer*)>(&HPACK::read))},
	{"write", "(JILjdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer;Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)(int64_t,int32_t,$HPACK$BufferUpdateConsumer*,$ByteBuffer*)>(&HPACK::write))},
	{}
};

$InnerClassInfo _HPACK_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.HPACK$BufferUpdateConsumer", "jdk.internal.net.http.hpack.HPACK", "BufferUpdateConsumer", $STATIC | $INTERFACE | $ABSTRACT},
	{"jdk.internal.net.http.hpack.HPACK$RootLogger", "jdk.internal.net.http.hpack.HPACK", "RootLogger", $PRIVATE | $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.HPACK$Logger", "jdk.internal.net.http.hpack.HPACK", "Logger", $PUBLIC | $STATIC},
	{}
};

$ClassInfo _HPACK_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.HPACK",
	"java.lang.Object",
	nullptr,
	_HPACK_FieldInfo_,
	_HPACK_MethodInfo_,
	nullptr,
	nullptr,
	_HPACK_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.HPACK$BufferUpdateConsumer,jdk.internal.net.http.hpack.HPACK$RootLogger,jdk.internal.net.http.hpack.HPACK$Logger,jdk.internal.net.http.hpack.HPACK$Logger$Level"
};

$Object* allocate$HPACK($Class* clazz) {
	return $of($alloc(HPACK));
}

bool HPACK::$assertionsDisabled = false;
$HPACK$RootLogger* HPACK::LOGGER = nullptr;
$Map* HPACK::logLevels = nullptr;

$HPACK$Logger* HPACK::getLogger() {
	$init(HPACK);
	return HPACK::LOGGER;
}

void HPACK::init$() {
}

int32_t HPACK::read($ByteBuffer* source, int64_t buffer, int32_t bufferLen, $HPACK$BufferUpdateConsumer* consumer) {
	$init(HPACK);
	int32_t nBytes = $Math::min((64 - bufferLen) >> 3, $nc(source)->remaining());
	switch (nBytes) {
	case 0:
		{
			break;
		}
	case 3:
		{
			buffer |= ($sl((int64_t)($nc(source)->get() & (uint64_t)(int64_t)255), 56 - bufferLen));
			bufferLen += 8;
		}
	case 2:
		{
			buffer |= ($sl((int64_t)($nc(source)->get() & (uint64_t)(int64_t)255), 56 - bufferLen));
			bufferLen += 8;
		}
	case 1:
		{
			buffer |= ($sl((int64_t)($nc(source)->get() & (uint64_t)(int64_t)255), 56 - bufferLen));
			bufferLen += 8;
			$nc(consumer)->accept(buffer, bufferLen);
			break;
		}
	case 7:
		{
			buffer |= ($sl((int64_t)($nc(source)->get() & (uint64_t)(int64_t)255), 56 - bufferLen));
			bufferLen += 8;
		}
	case 6:
		{
			buffer |= ($sl((int64_t)($nc(source)->get() & (uint64_t)(int64_t)255), 56 - bufferLen));
			bufferLen += 8;
		}
	case 5:
		{
			buffer |= ($sl((int64_t)($nc(source)->get() & (uint64_t)(int64_t)255), 56 - bufferLen));
			bufferLen += 8;
		}
	case 4:
		{
			buffer |= ($sl((int64_t)($nc(source)->getInt() & (uint64_t)(int64_t)0x00000000FFFFFFFF), 32 - bufferLen));
			bufferLen += 32;
			$nc(consumer)->accept(buffer, bufferLen);
			break;
		}
	case 8:
		{
			buffer = $nc(source)->getLong();
			bufferLen = 64;
			$nc(consumer)->accept(buffer, bufferLen);
			break;
		}
	default:
		{
			$throwNew($InternalError, $($String::valueOf(nBytes)));
		}
	}
	return nBytes;
}

int32_t HPACK::write(int64_t buffer, int32_t bufferLen, $HPACK$BufferUpdateConsumer* consumer, $ByteBuffer* destination) {
	$init(HPACK);
	int32_t nBytes = $Math::min(bufferLen >> 3, $nc(destination)->remaining());
	switch (nBytes) {
	case 0:
		{
			break;
		}
	case 3:
		{
			$nc(destination)->put((int8_t)((int64_t)((uint64_t)buffer >> 56)));
			buffer <<= 8;
			bufferLen -= 8;
		}
	case 2:
		{
			$nc(destination)->put((int8_t)((int64_t)((uint64_t)buffer >> 56)));
			buffer <<= 8;
			bufferLen -= 8;
		}
	case 1:
		{
			$nc(destination)->put((int8_t)((int64_t)((uint64_t)buffer >> 56)));
			buffer <<= 8;
			bufferLen -= 8;
			$nc(consumer)->accept(buffer, bufferLen);
			break;
		}
	case 7:
		{
			$nc(destination)->put((int8_t)((int64_t)((uint64_t)buffer >> 56)));
			buffer <<= 8;
			bufferLen -= 8;
		}
	case 6:
		{
			$nc(destination)->put((int8_t)((int64_t)((uint64_t)buffer >> 56)));
			buffer <<= 8;
			bufferLen -= 8;
		}
	case 5:
		{
			$nc(destination)->put((int8_t)((int64_t)((uint64_t)buffer >> 56)));
			buffer <<= 8;
			bufferLen -= 8;
		}
	case 4:
		{
			$nc(destination)->putInt((int32_t)((int64_t)((uint64_t)buffer >> 32)));
			buffer <<= 32;
			bufferLen -= 32;
			$nc(consumer)->accept(buffer, bufferLen);
			break;
		}
	case 8:
		{
			$nc(destination)->putLong(buffer);
			buffer = 0;
			bufferLen = 0;
			$nc(consumer)->accept(buffer, bufferLen);
			break;
		}
	default:
		{
			$throwNew($InternalError, $($String::valueOf(nBytes)));
		}
	}
	return nBytes;
}

int32_t HPACK::bytesForBits(int32_t n) {
	$init(HPACK);
	if (!HPACK::$assertionsDisabled && !((n / 8 + (n % 8 != 0 ? 1 : 0)) == (n + 7) / 8 && (n + 7) / 8 == ((n + 7) >> 3))) {
		$throwNew($AssertionError, n);
	}
	return (n + 7) >> 3;
}

$String* HPACK::lambda$static$2($HPACK$Logger$Level* l) {
	$init(HPACK);
	return $String::format("logging level %s"_s, $$new($ObjectArray, {$of(l)}));
}

$String* HPACK::lambda$static$1($String* PROPERTY, $String* value) {
	$init(HPACK);
	$useLocalCurrentObjectStackCache();
	return $String::format("%s value \'%s\' not recognized (use %s); logging disabled"_s, $$new($ObjectArray, {
		$of(PROPERTY),
		$of(value),
		$($nc($($nc($($nc(HPACK::logLevels)->keySet()))->stream()))->collect($($Collectors::joining(", "_s))))
	}));
}

$String* HPACK::lambda$static$0($String* PROPERTY) {
	$init(HPACK);
	return $System::getProperty(PROPERTY);
}

void clinit$HPACK($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	HPACK::$assertionsDisabled = !HPACK::class$->desiredAssertionStatus();
	$init($HPACK$Logger$Level);
	$assignStatic(HPACK::logLevels, $Map::of("NORMAL"_s, $HPACK$Logger$Level::NORMAL, "EXTRA"_s, $HPACK$Logger$Level::EXTRA));
	{
		$var($String, PROPERTY, "jdk.internal.httpclient.hpack.log.level"_s);
		$var($String, value, $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(HPACK$$Lambda$lambda$static$0, PROPERTY)))));
		if (value == nullptr) {
			$assignStatic(HPACK::LOGGER, $new($HPACK$RootLogger, $HPACK$Logger$Level::NONE));
		} else {
			$var($String, upperCasedValue, $nc(value)->toUpperCase());
			$HPACK$Logger$Level* l = $cast($HPACK$Logger$Level, $nc(HPACK::logLevels)->get(upperCasedValue));
			if (l == nullptr) {
				$assignStatic(HPACK::LOGGER, $new($HPACK$RootLogger, $HPACK$Logger$Level::NONE));
				$init($System$Logger$Level);
				$nc(HPACK::LOGGER)->log($System$Logger$Level::INFO, static_cast<$Supplier*>($$new(HPACK$$Lambda$lambda$static$1$1, PROPERTY, value)));
			} else {
				$assignStatic(HPACK::LOGGER, $new($HPACK$RootLogger, l));
				$init($System$Logger$Level);
				$nc(HPACK::LOGGER)->log($System$Logger$Level::DEBUG, static_cast<$Supplier*>($$new(HPACK$$Lambda$lambda$static$2$2, l)));
			}
		}
	}
}

HPACK::HPACK() {
}

$Class* HPACK::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(HPACK$$Lambda$lambda$static$0::classInfo$.name)) {
			return HPACK$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(HPACK$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return HPACK$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
		if (name->equals(HPACK$$Lambda$lambda$static$2$2::classInfo$.name)) {
			return HPACK$$Lambda$lambda$static$2$2::load$(name, initialize);
		}
	}
	$loadClass(HPACK, name, initialize, &_HPACK_ClassInfo_, clinit$HPACK, allocate$HPACK);
	return class$;
}

$Class* HPACK::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk