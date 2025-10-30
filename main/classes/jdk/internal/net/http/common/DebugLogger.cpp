#include <jdk/internal/net/http/common/DebugLogger.h>

#include <java/io/Serializable.h>
#include <java/lang/CharSequence.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/text/MessageFormat.h>
#include <java/util/Objects.h>
#include <java/util/ResourceBundle.h>
#include <java/util/function/Supplier.h>
#include <jcpp.h>

#undef DEBUG
#undef HPACK
#undef HPACK_NAME
#undef HTTP
#undef HTTP_NAME
#undef NO_HPACK_LOGGER
#undef NO_HTTP_LOGGER
#undef NO_WS_LOGGER
#undef OFF
#undef START_NANOS
#undef TRACE
#undef WS
#undef WS_NAME

using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $MessageFormat = ::java::text::MessageFormat;
using $Objects = ::java::util::Objects;
using $ResourceBundle = ::java::util::ResourceBundle;
using $Supplier = ::java::util::function::Supplier;
using $Logger = ::jdk::internal::net::http::common::Logger;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class DebugLogger$$Lambda$toString : public $Supplier {
	$class(DebugLogger$$Lambda$toString, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<DebugLogger$$Lambda$toString>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo DebugLogger$$Lambda$toString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(DebugLogger$$Lambda$toString, inst$)},
	{}
};
$MethodInfo DebugLogger$$Lambda$toString::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(DebugLogger$$Lambda$toString::*)($String*)>(&DebugLogger$$Lambda$toString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo DebugLogger$$Lambda$toString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.DebugLogger$$Lambda$toString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* DebugLogger$$Lambda$toString::load$($String* name, bool initialize) {
	$loadClass(DebugLogger$$Lambda$toString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* DebugLogger$$Lambda$toString::class$ = nullptr;

$FieldInfo _DebugLogger_FieldInfo_[] = {
	{"HTTP_NAME", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(DebugLogger, HTTP_NAME)},
	{"WS_NAME", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(DebugLogger, WS_NAME)},
	{"HPACK_NAME", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(DebugLogger, HPACK_NAME)},
	{"HTTP", "Ljava/lang/System$Logger;", nullptr, $STATIC | $FINAL, $staticField(DebugLogger, HTTP)},
	{"WS", "Ljava/lang/System$Logger;", nullptr, $STATIC | $FINAL, $staticField(DebugLogger, WS)},
	{"HPACK", "Ljava/lang/System$Logger;", nullptr, $STATIC | $FINAL, $staticField(DebugLogger, HPACK)},
	{"NO_HTTP_LOGGER", "Ljdk/internal/net/http/common/DebugLogger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DebugLogger, NO_HTTP_LOGGER)},
	{"NO_WS_LOGGER", "Ljdk/internal/net/http/common/DebugLogger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DebugLogger, NO_WS_LOGGER)},
	{"NO_HPACK_LOGGER", "Ljdk/internal/net/http/common/DebugLogger;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(DebugLogger, NO_HPACK_LOGGER)},
	{"START_NANOS", "J", nullptr, $STATIC | $FINAL, $staticField(DebugLogger, START_NANOS)},
	{"dbgTag", "Ljava/util/function/Supplier;", "Ljava/util/function/Supplier<Ljava/lang/String;>;", $PRIVATE | $FINAL, $field(DebugLogger, dbgTag)},
	{"errLevel", "Ljava/lang/System$Logger$Level;", nullptr, $PRIVATE | $FINAL, $field(DebugLogger, errLevel)},
	{"outLevel", "Ljava/lang/System$Logger$Level;", nullptr, $PRIVATE | $FINAL, $field(DebugLogger, outLevel)},
	{"logger", "Ljava/lang/System$Logger;", nullptr, $PRIVATE | $FINAL, $field(DebugLogger, logger)},
	{"debugOn", "Z", nullptr, $PRIVATE | $FINAL, $field(DebugLogger, debugOn)},
	{"traceOn", "Z", nullptr, $PRIVATE | $FINAL, $field(DebugLogger, traceOn)},
	{}
};

$MethodInfo _DebugLogger_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/System$Logger;Ljava/util/function/Supplier;Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger$Level;)V", "(Ljava/lang/System$Logger;Ljava/util/function/Supplier<Ljava/lang/String;>;Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger$Level;)V", $PRIVATE, $method(static_cast<void(DebugLogger::*)($System$Logger*,$Supplier*,$System$Logger$Level*,$System$Logger$Level*)>(&DebugLogger::init$))},
	{"createHpackLogger", "(Ljava/util/function/Supplier;Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/DebugLogger;", "(Ljava/util/function/Supplier<Ljava/lang/String;>;Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/DebugLogger;", $PUBLIC | $STATIC, $method(static_cast<DebugLogger*(*)($Supplier*,$System$Logger$Level*,$System$Logger$Level*)>(&DebugLogger::createHpackLogger))},
	{"createHttpLogger", "(Ljava/util/function/Supplier;Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/DebugLogger;", "(Ljava/util/function/Supplier<Ljava/lang/String;>;Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/DebugLogger;", $PUBLIC | $STATIC, $method(static_cast<DebugLogger*(*)($Supplier*,$System$Logger$Level*,$System$Logger$Level*)>(&DebugLogger::createHttpLogger))},
	{"createWebSocketLogger", "(Ljava/util/function/Supplier;Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/DebugLogger;", "(Ljava/util/function/Supplier<Ljava/lang/String;>;Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/DebugLogger;", $PUBLIC | $STATIC, $method(static_cast<DebugLogger*(*)($Supplier*,$System$Logger$Level*,$System$Logger$Level*)>(&DebugLogger::createWebSocketLogger))},
	{"decorate", "(Ljava/lang/StringBuilder;Ljava/lang/String;)Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $method(static_cast<$StringBuilder*(DebugLogger::*)($StringBuilder*,$String*)>(&DebugLogger::decorate))},
	{"format", "(Ljava/lang/StringBuilder;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $method(static_cast<$StringBuilder*(DebugLogger::*)($StringBuilder*,$String*,$ObjectArray*)>(&DebugLogger::format))},
	{"getFormat", "(Ljava/lang/StringBuilder;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $method(static_cast<$StringBuilder*(DebugLogger::*)($StringBuilder*,$String*,$ObjectArray*)>(&DebugLogger::getFormat))},
	{"getName", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"isEnabled", "(Ljava/lang/System$Logger$Level;)Z", nullptr, $PRIVATE, $method(static_cast<bool(DebugLogger::*)($System$Logger$Level*)>(&DebugLogger::isEnabled))},
	{"isLoggable", "(Ljava/lang/System$Logger$Level;)Z", nullptr, $PUBLIC},
	{"levelEnabledFor", "(Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger$Level;Ljava/lang/System$Logger;)Z", nullptr, $STATIC, $method(static_cast<bool(*)($System$Logger$Level*,$System$Logger$Level*,$System$Logger$Level*,$System$Logger*)>(&DebugLogger::levelEnabledFor))},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $TRANSIENT},
	{"log", "(Ljava/lang/System$Logger$Level;Ljava/util/ResourceBundle;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PUBLIC},
	{"on", "()Z", nullptr, $PUBLIC | $FINAL},
	{"print", "(Ljava/io/PrintStream;Ljava/lang/System$Logger$Level;Ljava/lang/String;[Ljava/lang/Object;Ljava/lang/Throwable;)V", nullptr, $PRIVATE, $method(static_cast<void(DebugLogger::*)($PrintStream*,$System$Logger$Level*,$String*,$ObjectArray*,$Throwable*)>(&DebugLogger::print))},
	{}
};

$ClassInfo _DebugLogger_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.DebugLogger",
	"java.lang.Object",
	"jdk.internal.net.http.common.Logger",
	_DebugLogger_FieldInfo_,
	_DebugLogger_MethodInfo_
};

$Object* allocate$DebugLogger($Class* clazz) {
	return $of($alloc(DebugLogger));
}

$String* DebugLogger::HTTP_NAME = nullptr;
$String* DebugLogger::WS_NAME = nullptr;
$String* DebugLogger::HPACK_NAME = nullptr;
$System$Logger* DebugLogger::HTTP = nullptr;
$System$Logger* DebugLogger::WS = nullptr;
$System$Logger* DebugLogger::HPACK = nullptr;
DebugLogger* DebugLogger::NO_HTTP_LOGGER = nullptr;
DebugLogger* DebugLogger::NO_WS_LOGGER = nullptr;
DebugLogger* DebugLogger::NO_HPACK_LOGGER = nullptr;
int64_t DebugLogger::START_NANOS = 0;

void DebugLogger::init$($System$Logger* logger, $Supplier* dbgTag, $System$Logger$Level* outLevel, $System$Logger$Level* errLevel) {
	$set(this, dbgTag, dbgTag);
	$set(this, errLevel, errLevel);
	$set(this, outLevel, outLevel);
	$set(this, logger, $cast($System$Logger, $Objects::requireNonNull(logger)));
	$init($System$Logger$Level);
	this->debugOn = isEnabled($System$Logger$Level::DEBUG);
	this->traceOn = isEnabled($System$Logger$Level::TRACE);
}

$String* DebugLogger::getName() {
	return $nc(this->logger)->getName();
}

bool DebugLogger::isEnabled($System$Logger$Level* level) {
	return levelEnabledFor(level, this->outLevel, this->errLevel, this->logger);
}

bool DebugLogger::on() {
	return this->debugOn;
}

bool DebugLogger::levelEnabledFor($System$Logger$Level* level, $System$Logger$Level* outLevel, $System$Logger$Level* errLevel, $System$Logger* logger) {
	$init(DebugLogger);
	$init($System$Logger$Level);
	if (level == $System$Logger$Level::OFF) {
		return false;
	}
	int32_t severity = $nc(level)->getSeverity();
	bool var$1 = severity >= $nc(errLevel)->getSeverity();
	bool var$0 = var$1 || severity >= $nc(outLevel)->getSeverity();
	return var$0 || $nc(logger)->isLoggable(level);
}

bool DebugLogger::isLoggable($System$Logger$Level* level) {
	$init($System$Logger$Level);
	if (level == $System$Logger$Level::DEBUG) {
		return this->debugOn;
	}
	if (level == $System$Logger$Level::TRACE) {
		return this->traceOn;
	}
	return isEnabled(level);
}

void DebugLogger::log($System$Logger$Level* level, $ResourceBundle* unused, $String* format, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	$init($System$Logger$Level);
	if (level == $System$Logger$Level::DEBUG && !this->debugOn) {
		return;
	}
	if (level == $System$Logger$Level::TRACE && !this->traceOn) {
		return;
	}
	int32_t severity = $nc(level)->getSeverity();
	if (this->errLevel != $System$Logger$Level::OFF && this->errLevel->getSeverity() <= severity) {
		print($System::err, level, format, params, nullptr);
	}
	if (this->outLevel != $System$Logger$Level::OFF && this->outLevel->getSeverity() <= severity) {
		print($System::out, level, format, params, nullptr);
	}
	if ($nc(this->logger)->isLoggable(level)) {
		$nc(this->logger)->log(level, unused, $($nc($(getFormat($$new($StringBuilder), format, params)))->toString()), params);
	}
}

void DebugLogger::log($System$Logger$Level* level, $ResourceBundle* unused, $String* msg, $Throwable* thrown) {
	$useLocalCurrentObjectStackCache();
	$init($System$Logger$Level);
	if (level == $System$Logger$Level::DEBUG && !this->debugOn) {
		return;
	}
	if (level == $System$Logger$Level::TRACE && !this->traceOn) {
		return;
	}
	bool var$0 = this->errLevel != $System$Logger$Level::OFF;
	if (var$0) {
		int32_t var$1 = this->errLevel->getSeverity();
		var$0 = var$1 <= $nc(level)->getSeverity();
	}
	if (var$0) {
		print($System::err, level, msg, nullptr, thrown);
	}
	bool var$2 = this->outLevel != $System$Logger$Level::OFF;
	if (var$2) {
		int32_t var$3 = this->outLevel->getSeverity();
		var$2 = var$3 <= $nc(level)->getSeverity();
	}
	if (var$2) {
		print($System::out, level, msg, nullptr, thrown);
	}
	if ($nc(this->logger)->isLoggable(level)) {
		$nc(this->logger)->log(level, unused, $($nc($(getFormat($$new($StringBuilder), msg, nullptr)))->toString()), thrown);
	}
}

void DebugLogger::print($PrintStream* out, $System$Logger$Level* level, $String* msg, $ObjectArray* params, $Throwable* t) {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($nc(level)->name()))->append(u':')->append(u' ');
	$assign(sb, format(sb, msg, params));
	if (t != nullptr) {
		$nc(sb)->append(u' ')->append($(t->toString()));
	}
	$nc(out)->println($($nc(sb)->toString()));
	if (t != nullptr) {
		t->printStackTrace(out);
	}
}

$StringBuilder* DebugLogger::decorate($StringBuilder* sb, $String* msg) {
	$useLocalCurrentObjectStackCache();
	$var($String, tag, this->dbgTag == nullptr ? ($String*)nullptr : $cast($String, $nc(this->dbgTag)->get()));
	$var($String, res, msg == nullptr ? ""_s : msg);
	int64_t elapsed = $System::nanoTime() - DebugLogger::START_NANOS;
	int64_t millis = elapsed / 0x000F4240;
	int64_t secs = millis / 1000;
	$nc(sb)->append(u'[')->append($($($Thread::currentThread())->getName()))->append(u']')->append(u' ')->append(u'[');
	if (secs > 0) {
		sb->append(secs)->append(u's');
	}
	millis = millis % 1000;
	if (millis > 0) {
		if (secs > 0) {
			sb->append(u' ');
		}
		sb->append(millis)->append("ms"_s);
	}
	sb->append(u']')->append(u' ');
	if (tag != nullptr) {
		sb->append(tag)->append(u' ');
	}
	sb->append(res);
	return sb;
}

$StringBuilder* DebugLogger::getFormat($StringBuilder* sb, $String* format, $ObjectArray* params) {
	if (format == nullptr || params == nullptr || $nc(params)->length == 0) {
		return decorate(sb, format);
	} else {
		bool var$1 = $nc(format)->contains("{0}"_s);
		if (var$1 || $nc(format)->contains("{1}"_s)) {
			return decorate(sb, format);
		} else {
			bool var$3 = format->contains("%s"_s);
			if (var$3 || format->contains("%d"_s)) {
				try {
					return decorate(sb, $($String::format(format, params)));
				} catch ($Throwable& t) {
					return decorate(sb, format);
				}
			} else {
				return decorate(sb, format);
			}
		}
	}
}

$StringBuilder* DebugLogger::format($StringBuilder* sb, $String* format, $ObjectArray* params) {
	$useLocalCurrentObjectStackCache();
	if (format == nullptr || params == nullptr || $nc(params)->length == 0) {
		return decorate(sb, format);
	} else {
		bool var$1 = $nc(format)->contains("{0}"_s);
		if (var$1 || $nc(format)->contains("{1}"_s)) {
			return decorate(sb, $($MessageFormat::format(format, params)));
		} else {
			bool var$3 = format->contains("%s"_s);
			if (var$3 || format->contains("%d"_s)) {
				try {
					return decorate(sb, $($String::format(format, params)));
				} catch ($Throwable& t) {
					return decorate(sb, format);
				}
			} else {
				return decorate(sb, format);
			}
		}
	}
}

DebugLogger* DebugLogger::createHttpLogger($Supplier* dbgTag, $System$Logger$Level* outLevel, $System$Logger$Level* errLevel) {
	$init(DebugLogger);
	$init($System$Logger$Level);
	if (levelEnabledFor($System$Logger$Level::DEBUG, outLevel, errLevel, DebugLogger::HTTP)) {
		return $new(DebugLogger, DebugLogger::HTTP, dbgTag, outLevel, errLevel);
	} else {
		return DebugLogger::NO_HTTP_LOGGER;
	}
}

DebugLogger* DebugLogger::createWebSocketLogger($Supplier* dbgTag, $System$Logger$Level* outLevel, $System$Logger$Level* errLevel) {
	$init(DebugLogger);
	$init($System$Logger$Level);
	if (levelEnabledFor($System$Logger$Level::DEBUG, outLevel, errLevel, DebugLogger::WS)) {
		return $new(DebugLogger, DebugLogger::WS, dbgTag, outLevel, errLevel);
	} else {
		return DebugLogger::NO_WS_LOGGER;
	}
}

DebugLogger* DebugLogger::createHpackLogger($Supplier* dbgTag, $System$Logger$Level* outLevel, $System$Logger$Level* errLevel) {
	$init(DebugLogger);
	$init($System$Logger$Level);
	if (levelEnabledFor($System$Logger$Level::DEBUG, outLevel, errLevel, DebugLogger::HPACK)) {
		return $new(DebugLogger, DebugLogger::HPACK, dbgTag, outLevel, errLevel);
	} else {
		return DebugLogger::NO_HPACK_LOGGER;
	}
}

void clinit$DebugLogger($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(DebugLogger::HTTP_NAME, "jdk.internal.httpclient.debug"_s);
	$assignStatic(DebugLogger::WS_NAME, "jdk.internal.httpclient.websocket.debug"_s);
	$assignStatic(DebugLogger::HPACK_NAME, "jdk.internal.httpclient.hpack.debug"_s);
	$beforeCallerSensitive();
	$assignStatic(DebugLogger::HTTP, $System::getLogger(DebugLogger::HTTP_NAME));
	$assignStatic(DebugLogger::WS, $System::getLogger(DebugLogger::WS_NAME));
	$assignStatic(DebugLogger::HPACK, $System::getLogger(DebugLogger::HPACK_NAME));
	$init($System$Logger$Level);
	$assignStatic(DebugLogger::NO_HTTP_LOGGER, $new(DebugLogger, DebugLogger::HTTP, static_cast<$Supplier*>($$new(DebugLogger$$Lambda$toString, static_cast<$String*>("HTTP"_s))), $System$Logger$Level::OFF, $System$Logger$Level::OFF));
	$assignStatic(DebugLogger::NO_WS_LOGGER, $new(DebugLogger, DebugLogger::HTTP, static_cast<$Supplier*>($$new(DebugLogger$$Lambda$toString, static_cast<$String*>("WS"_s))), $System$Logger$Level::OFF, $System$Logger$Level::OFF));
	$assignStatic(DebugLogger::NO_HPACK_LOGGER, $new(DebugLogger, DebugLogger::HTTP, static_cast<$Supplier*>($$new(DebugLogger$$Lambda$toString, static_cast<$String*>("HPACK"_s))), $System$Logger$Level::OFF, $System$Logger$Level::OFF));
	DebugLogger::START_NANOS = $System::nanoTime();
}

DebugLogger::DebugLogger() {
}

$Class* DebugLogger::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(DebugLogger$$Lambda$toString::classInfo$.name)) {
			return DebugLogger$$Lambda$toString::load$(name, initialize);
		}
	}
	$loadClass(DebugLogger, name, initialize, &_DebugLogger_ClassInfo_, clinit$DebugLogger, allocate$DebugLogger);
	return class$;
}

$Class* DebugLogger::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk