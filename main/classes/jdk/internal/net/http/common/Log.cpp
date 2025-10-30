#include <jdk/internal/net/http/common/Log.h>

#include <java/lang/System$Logger$Level.h>
#include <java/lang/System$Logger.h>
#include <java/net/http/HttpHeaders.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Set.h>
#include <java/util/function/Supplier.h>
#include <javax/net/ssl/SNIServerName.h>
#include <javax/net/ssl/SSLParameters.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/frame/DataFrame.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jdk/internal/net/http/frame/WindowUpdateFrame.h>
#include <jcpp.h>

#undef ALL
#undef CHANNEL
#undef CONTENT
#undef CONTROL
#undef DATA
#undef ERRORS
#undef FRAMES
#undef HEADERS
#undef INFO
#undef OFF
#undef REQUESTS
#undef SSL
#undef TRACE
#undef US
#undef WINDOW_UPDATES

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $System$Logger = ::java::lang::System$Logger;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Set = ::java::util::Set;
using $Supplier = ::java::util::function::Supplier;
using $SNIServerName = ::javax::net::ssl::SNIServerName;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $DataFrame = ::jdk::internal::net::http::frame::DataFrame;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;
using $WindowUpdateFrame = ::jdk::internal::net::http::frame::WindowUpdateFrame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

$FieldInfo _Log_FieldInfo_[] = {
	{"logProp", "Ljava/lang/String;", nullptr, $STATIC | $FINAL, $staticField(Log, logProp)},
	{"OFF", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, OFF)},
	{"ERRORS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, ERRORS)},
	{"REQUESTS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, REQUESTS)},
	{"HEADERS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, HEADERS)},
	{"CONTENT", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, CONTENT)},
	{"FRAMES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, FRAMES)},
	{"SSL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, SSL)},
	{"TRACE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, TRACE)},
	{"CHANNEL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, CHANNEL)},
	{"logging", "I", nullptr, $STATIC, $staticField(Log, logging)},
	{"CONTROL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, CONTROL)},
	{"DATA", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, DATA)},
	{"WINDOW_UPDATES", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, WINDOW_UPDATES)},
	{"ALL", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(Log, ALL)},
	{"frametypes", "I", nullptr, $STATIC, $staticField(Log, frametypes)},
	{"logger", "Ljava/lang/System$Logger;", nullptr, $STATIC | $FINAL, $staticField(Log, logger)},
	{}
};

$MethodInfo _Log_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Log::*)()>(&Log::init$))},
	{"channel", "()Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)()>(&Log::channel))},
	{"dumpHeaders", "(Ljava/lang/StringBuilder;Ljava/lang/String;Ljava/net/http/HttpHeaders;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($StringBuilder*,$String*,$HttpHeaders*)>(&Log::dumpHeaders))},
	{"errors", "()Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)()>(&Log::errors))},
	{"frames", "()Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)()>(&Log::frames))},
	{"headers", "()Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)()>(&Log::headers))},
	{"logChannel", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<void(*)($String*,$ObjectArray*)>(&Log::logChannel))},
	{"logChannel", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC | $STATIC, $method(static_cast<void(*)($Supplier*)>(&Log::logChannel))},
	{"logError", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<void(*)($String*,$ObjectArray*)>(&Log::logError))},
	{"logError", "(Ljava/lang/Throwable;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($Throwable*)>(&Log::logError))},
	{"logFrames", "(Ljdk/internal/net/http/frame/Http2Frame;Ljava/lang/String;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($Http2Frame*,$String*)>(&Log::logFrames))},
	{"logHeaders", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<void(*)($String*,$ObjectArray*)>(&Log::logHeaders))},
	{"logParams", "(Ljavax/net/ssl/SSLParameters;)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($SSLParameters*)>(&Log::logParams))},
	{"logRequest", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<void(*)($String*,$ObjectArray*)>(&Log::logRequest))},
	{"logResponse", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC | $STATIC, $method(static_cast<void(*)($Supplier*)>(&Log::logResponse))},
	{"logSSL", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<void(*)($String*,$ObjectArray*)>(&Log::logSSL))},
	{"logSSL", "(Ljava/util/function/Supplier;)V", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)V", $PUBLIC | $STATIC, $method(static_cast<void(*)($Supplier*)>(&Log::logSSL))},
	{"logTrace", "(Ljava/lang/String;[Ljava/lang/Object;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<void(*)($String*,$ObjectArray*)>(&Log::logTrace))},
	{"loggingFrame", "(Ljava/lang/Class;)Z", "(Ljava/lang/Class<+Ljdk/internal/net/http/frame/Http2Frame;>;)Z", $PUBLIC | $STATIC, $method(static_cast<bool(*)($Class*)>(&Log::loggingFrame))},
	{"requests", "()Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)()>(&Log::requests))},
	{"ssl", "()Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)()>(&Log::ssl))},
	{"trace", "()Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)()>(&Log::trace))},
	{}
};

$InnerClassInfo _Log_InnerClassesInfo_[] = {
	{"java.lang.System$Logger", "java.lang.System", "Logger", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _Log_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER | $ABSTRACT,
	"jdk.internal.net.http.common.Log",
	"java.lang.Object",
	"java.lang.System$Logger",
	_Log_FieldInfo_,
	_Log_MethodInfo_,
	nullptr,
	nullptr,
	_Log_InnerClassesInfo_
};

$Object* allocate$Log($Class* clazz) {
	return $of($alloc(Log));
}

$String* Log::logProp = nullptr;
int32_t Log::logging = 0;
int32_t Log::frametypes = 0;
$System$Logger* Log::logger = nullptr;

bool Log::errors() {
	$init(Log);
	return ((int32_t)(Log::logging & (uint32_t)Log::ERRORS)) != 0;
}

bool Log::requests() {
	$init(Log);
	return ((int32_t)(Log::logging & (uint32_t)Log::REQUESTS)) != 0;
}

bool Log::headers() {
	$init(Log);
	return ((int32_t)(Log::logging & (uint32_t)Log::HEADERS)) != 0;
}

bool Log::trace() {
	$init(Log);
	return ((int32_t)(Log::logging & (uint32_t)Log::TRACE)) != 0;
}

bool Log::ssl() {
	$init(Log);
	return ((int32_t)(Log::logging & (uint32_t)Log::SSL)) != 0;
}

bool Log::frames() {
	$init(Log);
	return ((int32_t)(Log::logging & (uint32_t)Log::FRAMES)) != 0;
}

bool Log::channel() {
	$init(Log);
	return ((int32_t)(Log::logging & (uint32_t)Log::CHANNEL)) != 0;
}

void Log::logError($String* s, $ObjectArray* s1) {
	$init(Log);
	if (errors()) {
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, $$str({"ERROR: "_s, s}), s1);
	}
}

void Log::logError($Throwable* t) {
	$init(Log);
	$useLocalCurrentObjectStackCache();
	if (errors()) {
		$var($String, s, $Utils::stackTrace(t));
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, $$str({"ERROR: "_s, s}));
	}
}

void Log::logSSL($String* s, $ObjectArray* s1) {
	$init(Log);
	if (ssl()) {
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, $$str({"SSL: "_s, s}), s1);
	}
}

void Log::logSSL($Supplier* msgSupplier) {
	$init(Log);
	$useLocalCurrentObjectStackCache();
	if (ssl()) {
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, $$str({"SSL: "_s, $cast($String, $($nc(msgSupplier)->get()))}));
	}
}

void Log::logChannel($String* s, $ObjectArray* s1) {
	$init(Log);
	if (channel()) {
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, $$str({"CHANNEL: "_s, s}), s1);
	}
}

void Log::logChannel($Supplier* msgSupplier) {
	$init(Log);
	$useLocalCurrentObjectStackCache();
	if (channel()) {
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, $$str({"CHANNEL: "_s, $cast($String, $($nc(msgSupplier)->get()))}));
	}
}

void Log::logTrace($String* s, $ObjectArray* s1) {
	$init(Log);
	if (trace()) {
		$var($String, format, $str({"MISC: "_s, s}));
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, format, s1);
	}
}

void Log::logRequest($String* s, $ObjectArray* s1) {
	$init(Log);
	if (requests()) {
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, $$str({"REQUEST: "_s, s}), s1);
	}
}

void Log::logResponse($Supplier* supplier) {
	$init(Log);
	$useLocalCurrentObjectStackCache();
	if (requests()) {
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, $$str({"RESPONSE: "_s, $cast($String, $($nc(supplier)->get()))}));
	}
}

void Log::logHeaders($String* s, $ObjectArray* s1) {
	$init(Log);
	if (headers()) {
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, $$str({"HEADERS: "_s, s}), s1);
	}
}

bool Log::loggingFrame($Class* clazz) {
	$init(Log);
	if (Log::frametypes == Log::ALL) {
		return true;
	}
	$load($DataFrame);
	if (clazz == $DataFrame::class$) {
		return ((int32_t)(Log::frametypes & (uint32_t)Log::DATA)) != 0;
	} else {
		$load($WindowUpdateFrame);
		if (clazz == $WindowUpdateFrame::class$) {
			return ((int32_t)(Log::frametypes & (uint32_t)Log::WINDOW_UPDATES)) != 0;
		} else {
			return ((int32_t)(Log::frametypes & (uint32_t)Log::CONTROL)) != 0;
		}
	}
}

void Log::logFrames($Http2Frame* f, $String* direction) {
	$init(Log);
	$useLocalCurrentObjectStackCache();
	bool var$0 = frames();
	if (var$0 && loggingFrame($nc($of(f))->getClass())) {
		$init($System$Logger$Level);
		$nc(Log::logger)->log($System$Logger$Level::INFO, $$str({"FRAME: "_s, direction, ": "_s, $($nc(f)->toString())}));
	}
}

void Log::logParams($SSLParameters* p) {
	$init(Log);
	$useLocalCurrentObjectStackCache();
	if (!Log::ssl()) {
		return;
	}
	if (p == nullptr) {
		Log::logSSL("SSLParameters: Null params"_s, $$new($ObjectArray, 0));
		return;
	}
	$var($StringBuilder, sb, $new($StringBuilder, "SSLParameters:"_s));
	$var($List, params, $new($ArrayList));
	if ($nc(p)->getCipherSuites() != nullptr) {
		{
			$var($StringArray, arr$, p->getCipherSuites());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, cipher, arr$->get(i$));
				{
					sb->append("\n    cipher: {"_s)->append(params->size())->append("}"_s);
					params->add(cipher);
				}
			}
		}
	}
	{
		$var($StringArray, arr$, $nc(p)->getApplicationProtocols());
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($String, approto, arr$->get(i$));
			{
				sb->append("\n    application protocol: {"_s)->append(params->size())->append("}"_s);
				params->add(approto);
			}
		}
	}
	if (p->getProtocols() != nullptr) {
		{
			$var($StringArray, arr$, p->getProtocols());
			int32_t len$ = $nc(arr$)->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, protocol, arr$->get(i$));
				{
					sb->append("\n    protocol: {"_s)->append(params->size())->append("}"_s);
					params->add(protocol);
				}
			}
		}
	}
	if (p->getEndpointIdentificationAlgorithm() != nullptr) {
		sb->append("\n    endpointIdAlg: {"_s)->append(params->size())->append("}"_s);
		params->add($(p->getEndpointIdentificationAlgorithm()));
	}
	if (p->getServerNames() != nullptr) {
		{
			$var($Iterator, i$, $nc($(p->getServerNames()))->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($SNIServerName, sname, $cast($SNIServerName, i$->next()));
				{
					sb->append("\n    server name: {"_s)->append(params->size())->append("}"_s);
					params->add($($nc(sname)->toString()));
				}
			}
		}
	}
	sb->append(u'\n');
	$var($String, var$0, sb->toString());
	Log::logSSL(var$0, $(params->toArray()));
}

void Log::dumpHeaders($StringBuilder* sb, $String* prefix, $HttpHeaders* headers) {
	$init(Log);
	$useLocalCurrentObjectStackCache();
	if (headers != nullptr) {
		$var($Map, h, headers->map());
		$var($Set, entries, $nc(h)->entrySet());
		$var($String, sep, ""_s);
		{
			$var($Iterator, i$, $nc(entries)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($Map$Entry, entry, $cast($Map$Entry, i$->next()));
				{
					$var($String, key, $cast($String, $nc(entry)->getKey()));
					$var($List, values, $cast($List, entry->getValue()));
					if (values == nullptr || $nc(values)->isEmpty()) {
						$nc(sb)->append(sep);
						sb->append(prefix)->append(key)->append(u':');
						$assign(sep, "\n"_s);
						continue;
					}
					{
						$var($Iterator, i$, $nc(values)->iterator());
						for (; $nc(i$)->hasNext();) {
							$var($String, value, $cast($String, i$->next()));
							{
								$nc(sb)->append(sep);
								sb->append(prefix)->append(key)->append(u':');
								sb->append(u' ')->append(value);
								$assign(sep, "\n"_s);
							}
						}
					}
				}
			}
		}
		$nc(sb)->append(u'\n');
	}
}

void Log::init$() {
}

void clinit$Log($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(Log::logProp, "jdk.httpclient.HttpClient.log"_s);
	$beforeCallerSensitive();
	{
		$var($String, s, $Utils::getNetProperty(Log::logProp));
		if (s == nullptr) {
			Log::logging = Log::OFF;
		} else {
			$var($StringArray, vals, $nc(s)->split(","_s));
			{
				$var($StringArray, arr$, vals);
				int32_t len$ = arr$->length;
				int32_t i$ = 0;
				for (; i$ < len$; ++i$) {
					$var($String, val, arr$->get(i$));
					{
						{
							$init($Locale);
							$var($String, s3196$, $nc(val)->toLowerCase($Locale::US));
							int32_t tmp3196$ = -1;
							switch (s3196$->hashCode()) {
							case (int32_t)0xB2D56F6B:
								{
									if (s3196$->equals("errors"_s)) {
										tmp3196$ = 0;
									}
									break;
								}
							case (int32_t)0xE88F5FC4:
								{
									if (s3196$->equals("requests"_s)) {
										tmp3196$ = 1;
									}
									break;
								}
							case 0x2F676F86:
								{
									if (s3196$->equals("headers"_s)) {
										tmp3196$ = 2;
									}
									break;
								}
							case 0x38B73479:
								{
									if (s3196$->equals("content"_s)) {
										tmp3196$ = 3;
									}
									break;
								}
							case 0x0001BE0C:
								{
									if (s3196$->equals("ssl"_s)) {
										tmp3196$ = 4;
									}
									break;
								}
							case 0x2C0B7D03:
								{
									if (s3196$->equals("channel"_s)) {
										tmp3196$ = 5;
									}
									break;
								}
							case 0x0697F145:
								{
									if (s3196$->equals("trace"_s)) {
										tmp3196$ = 6;
									}
									break;
								}
							case 0x000179A1:
								{
									if (s3196$->equals("all"_s)) {
										tmp3196$ = 7;
									}
									break;
								}
							}
							switch (tmp3196$) {
							case 0:
								{
									Log::logging |= Log::ERRORS;
									break;
								}
							case 1:
								{
									Log::logging |= Log::REQUESTS;
									break;
								}
							case 2:
								{
									Log::logging |= Log::HEADERS;
									break;
								}
							case 3:
								{
									Log::logging |= Log::CONTENT;
									break;
								}
							case 4:
								{
									Log::logging |= Log::SSL;
									break;
								}
							case 5:
								{
									Log::logging |= Log::CHANNEL;
									break;
								}
							case 6:
								{
									Log::logging |= Log::TRACE;
									break;
								}
							case 7:
								{
									Log::logging |= ((((((Log::CONTENT | Log::HEADERS) | Log::REQUESTS) | Log::FRAMES) | Log::ERRORS) | Log::TRACE) | Log::SSL) | Log::CHANNEL;
									Log::frametypes |= Log::ALL;
									break;
								}
							default:
								{}
							}
						}
						if ($nc(val)->startsWith("frames"_s)) {
							Log::logging |= Log::FRAMES;
							$var($StringArray, types, val->split(":"_s));
							if (types->length == 1) {
								Log::frametypes = (Log::CONTROL | Log::DATA) | Log::WINDOW_UPDATES;
							} else {
								{
									$var($StringArray, arr$, types);
									int32_t len$ = arr$->length;
									int32_t i$ = 0;
									for (; i$ < len$; ++i$) {
										$var($String, type, arr$->get(i$));
										{
											{
												$init($Locale);
												$var($String, s4655$, $nc(type)->toLowerCase($Locale::US));
												int32_t tmp4655$ = -1;
												switch (s4655$->hashCode()) {
												case 0x38B7655D:
													{
														if (s4655$->equals("control"_s)) {
															tmp4655$ = 0;
														}
														break;
													}
												case 0x002EEFAA:
													{
														if (s4655$->equals("data"_s)) {
															tmp4655$ = 1;
														}
														break;
													}
												case (int32_t)0xD10BDBF0:
													{
														if (s4655$->equals("window"_s)) {
															tmp4655$ = 2;
														}
														break;
													}
												case 0x000179A1:
													{
														if (s4655$->equals("all"_s)) {
															tmp4655$ = 3;
														}
														break;
													}
												}
												switch (tmp4655$) {
												case 0:
													{
														Log::frametypes |= Log::CONTROL;
														break;
													}
												case 1:
													{
														Log::frametypes |= Log::DATA;
														break;
													}
												case 2:
													{
														Log::frametypes |= Log::WINDOW_UPDATES;
														break;
													}
												case 3:
													{
														Log::frametypes = Log::ALL;
														break;
													}
												default:
													{}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		if (Log::logging != Log::OFF) {
			$assignStatic(Log::logger, $System::getLogger("jdk.httpclient.HttpClient"_s));
		} else {
			$assignStatic(Log::logger, nullptr);
		}
	}
}

Log::Log() {
}

$Class* Log::load$($String* name, bool initialize) {
	$loadClass(Log, name, initialize, &_Log_ClassInfo_, clinit$Log, allocate$Log);
	return class$;
}

$Class* Log::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk