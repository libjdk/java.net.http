#include <jdk/internal/net/http/common/Utils.h>

#include <java/io/ByteArrayOutputStream.h>
#include <java/io/Closeable.h>
#include <java/io/IOException.h>
#include <java/io/OutputStream.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AbstractStringBuilder.h>
#include <java/lang/Appendable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Error.h>
#include <java/lang/InternalError.h>
#include <java/lang/SecurityException.h>
#include <java/lang/System$Logger$Level.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/ConnectException.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/SocketException.h>
#include <java/net/URI.h>
#include <java/net/URLPermission.h>
#include <java/net/http/HttpClient.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpTimeoutException.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/CharBuffer.h>
#include <java/nio/charset/CharacterCodingException.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/CharsetEncoder.h>
#include <java/nio/charset/CodingErrorAction.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/security/AccessController.h>
#include <java/security/AlgorithmConstraints.h>
#include <java/security/PrivilegedAction.h>
#include <java/text/Normalizer$Form.h>
#include <java/text/Normalizer.h>
#include <java/util/AbstractSet.h>
#include <java/util/Arrays.h>
#include <java/util/Collection.h>
#include <java/util/Collections.h>
#include <java/util/Comparator.h>
#include <java/util/HexFormat.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Optional.h>
#include <java/util/Set.h>
#include <java/util/TreeSet.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionException.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/ExecutionException.h>
#include <java/util/function/BiFunction.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Function.h>
#include <java/util/function/Predicate.h>
#include <java/util/function/Supplier.h>
#include <java/util/stream/Collector.h>
#include <java/util/stream/Collectors.h>
#include <java/util/stream/Stream.h>
#include <javax/net/ssl/ExtendedSSLSession.h>
#include <javax/net/ssl/SSLException.h>
#include <javax/net/ssl/SSLHandshakeException.h>
#include <javax/net/ssl/SSLParameters.h>
#include <javax/net/ssl/SSLSession.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/common/ConnectionExpiredException.h>
#include <jdk/internal/net/http/common/DebugLogger.h>
#include <jdk/internal/net/http/common/ImmutableExtendedSSLSession.h>
#include <jdk/internal/net/http/common/ImmutableSSLSession.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/Utils$ServerName.h>
#include <sun/net/NetProperties.h>
#include <sun/net/util/IPAddressUtil.h>
#include <sun/net/www/HeaderParser.h>
#include <jcpp.h>

#undef ACCEPT_ALL
#undef ALL
#undef ALLOWED_HEADERS
#undef ALL_HEADERS
#undef ASSERTIONSENABLED
#undef BUFSIZE
#undef CASE_INSENSITIVE_ORDER
#undef CONTEXT_RESTRICTED
#undef COPY_THRESHOLD
#undef DEBUG
#undef DEBUG_HPACK
#undef DEBUG_WS
#undef DEFAULT_BUFSIZE
#undef DISALLOWED_HEADERS_SET
#undef EMPTY_BB_ARRAY
#undef EMPTY_BB_LIST
#undef EMPTY_BYTEBUFFER
#undef HEADER_CONNECTION
#undef HEADER_UPGRADE
#undef HOST_RESTRICTED
#undef HPACK_NAME
#undef HTTP_NAME
#undef IS_HOST
#undef IS_PROXY_HEADER
#undef NFC
#undef NO_PROXY_HEADER
#undef NO_PROXY_HEADERS_FILTER
#undef OFF
#undef PROXY_AUTH_DISABLED_SCHEMES
#undef PROXY_AUTH_TUNNEL_DISABLED_SCHEMES
#undef PROXY_FILTER
#undef PROXY_TUNNEL_FILTER
#undef PROXY_TUNNEL_RESTRICTED
#undef REPORT
#undef TESTING
#undef US_ASCII
#undef UTF_8
#undef VALIDATE_USER_HEADER
#undef WSPACES
#undef WS_NAME

using $CloseableArray = $Array<::java::io::Closeable>;
using $ByteBufferArray = $Array<::java::nio::ByteBuffer>;
using $ByteArrayOutputStream = ::java::io::ByteArrayOutputStream;
using $Closeable = ::java::io::Closeable;
using $IOException = ::java::io::IOException;
using $OutputStream = ::java::io::OutputStream;
using $PrintStream = ::java::io::PrintStream;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AbstractStringBuilder = ::java::lang::AbstractStringBuilder;
using $Appendable = ::java::lang::Appendable;
using $AssertionError = ::java::lang::AssertionError;
using $Boolean = ::java::lang::Boolean;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Error = ::java::lang::Error;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $SecurityException = ::java::lang::SecurityException;
using $System$Logger$Level = ::java::lang::System$Logger$Level;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ConnectException = ::java::net::ConnectException;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $SocketException = ::java::net::SocketException;
using $URI = ::java::net::URI;
using $URLPermission = ::java::net::URLPermission;
using $HttpClient = ::java::net::http::HttpClient;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $HttpTimeoutException = ::java::net::http::HttpTimeoutException;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $CharBuffer = ::java::nio::CharBuffer;
using $CharacterCodingException = ::java::nio::charset::CharacterCodingException;
using $Charset = ::java::nio::charset::Charset;
using $CharsetEncoder = ::java::nio::charset::CharsetEncoder;
using $CodingErrorAction = ::java::nio::charset::CodingErrorAction;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AccessController = ::java::security::AccessController;
using $AlgorithmConstraints = ::java::security::AlgorithmConstraints;
using $PrivilegedAction = ::java::security::PrivilegedAction;
using $Normalizer = ::java::text::Normalizer;
using $Normalizer$Form = ::java::text::Normalizer$Form;
using $AbstractSet = ::java::util::AbstractSet;
using $Arrays = ::java::util::Arrays;
using $Collection = ::java::util::Collection;
using $Collections = ::java::util::Collections;
using $Comparator = ::java::util::Comparator;
using $HexFormat = ::java::util::HexFormat;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Optional = ::java::util::Optional;
using $Set = ::java::util::Set;
using $TreeSet = ::java::util::TreeSet;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionException = ::java::util::concurrent::CompletionException;
using $ExecutionException = ::java::util::concurrent::ExecutionException;
using $BiFunction = ::java::util::function::BiFunction;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Function = ::java::util::function::Function;
using $Predicate = ::java::util::function::Predicate;
using $Supplier = ::java::util::function::Supplier;
using $Collector = ::java::util::stream::Collector;
using $Collectors = ::java::util::stream::Collectors;
using $Stream = ::java::util::stream::Stream;
using $ExtendedSSLSession = ::javax::net::ssl::ExtendedSSLSession;
using $SSLException = ::javax::net::ssl::SSLException;
using $SSLHandshakeException = ::javax::net::ssl::SSLHandshakeException;
using $SSLParameters = ::javax::net::ssl::SSLParameters;
using $SSLSession = ::javax::net::ssl::SSLSession;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $ConnectionExpiredException = ::jdk::internal::net::http::common::ConnectionExpiredException;
using $DebugLogger = ::jdk::internal::net::http::common::DebugLogger;
using $ImmutableExtendedSSLSession = ::jdk::internal::net::http::common::ImmutableExtendedSSLSession;
using $ImmutableSSLSession = ::jdk::internal::net::http::common::ImmutableSSLSession;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $Utils$ServerName = ::jdk::internal::net::http::common::Utils$ServerName;
using $NetProperties = ::sun::net::NetProperties;
using $IPAddressUtil = ::sun::net::util::IPAddressUtil;
using $HeaderParser = ::sun::net::www::HeaderParser;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace common {

class Utils$$Lambda$lambda$static$0 : public $BiPredicate {
	$class(Utils$$Lambda$lambda$static$0, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$() {
	}
	virtual bool test(Object$* x, Object$* y) override {
		 return Utils::lambda$static$0($cast($String, x), $cast($String, y));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$static$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$lambda$static$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$static$0::*)()>(&Utils$$Lambda$lambda$static$0::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$static$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$static$0",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$lambda$static$0::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$static$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$static$0::class$ = nullptr;

class Utils$$Lambda$lambda$static$1$1 : public $BiPredicate {
	$class(Utils$$Lambda$lambda$static$1$1, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$() {
	}
	virtual bool test(Object$* header, Object$* unused) override {
		 return Utils::lambda$static$1($cast($String, header), $cast($String, unused));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$static$1$1>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$lambda$static$1$1::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$static$1$1::*)()>(&Utils$$Lambda$lambda$static$1$1::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$static$1$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$static$1$1",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$lambda$static$1$1::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$static$1$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$static$1$1::class$ = nullptr;

class Utils$$Lambda$lambda$static$2$2 : public $BiPredicate {
	$class(Utils$$Lambda$lambda$static$2$2, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$() {
	}
	virtual bool test(Object$* name, Object$* value) override {
		 return Utils::lambda$static$2($cast($String, name), $cast($String, value));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$static$2$2>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$lambda$static$2$2::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$static$2$2::*)()>(&Utils$$Lambda$lambda$static$2$2::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$static$2$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$static$2$2",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$lambda$static$2$2::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$static$2$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$static$2$2::class$ = nullptr;

class Utils$$Lambda$lambda$static$4$3 : public $BiPredicate {
	$class(Utils$$Lambda$lambda$static$4$3, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$() {
	}
	virtual bool test(Object$* k, Object$* v) override {
		 return Utils::lambda$static$4($cast($String, k), $cast($String, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$static$4$3>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$lambda$static$4$3::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$static$4$3::*)()>(&Utils$$Lambda$lambda$static$4$3::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$static$4$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$static$4$3",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$lambda$static$4$3::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$static$4$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$static$4$3::class$ = nullptr;

class Utils$$Lambda$equalsIgnoreCase$4 : public $Predicate {
	$class(Utils$$Lambda$equalsIgnoreCase$4, $NO_CLASS_INIT, $Predicate)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual bool test(Object$* arg0) override {
		 return $nc(inst$)->equalsIgnoreCase($cast($String, arg0));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$equalsIgnoreCase$4>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Utils$$Lambda$equalsIgnoreCase$4::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Utils$$Lambda$equalsIgnoreCase$4, inst$)},
	{}
};
$MethodInfo Utils$$Lambda$equalsIgnoreCase$4::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$equalsIgnoreCase$4::*)($String*)>(&Utils$$Lambda$equalsIgnoreCase$4::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$equalsIgnoreCase$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$equalsIgnoreCase$4",
	"java.lang.Object",
	"java.util.function.Predicate",
	fieldInfos,
	methodInfos
};
$Class* Utils$$Lambda$equalsIgnoreCase$4::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$equalsIgnoreCase$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$equalsIgnoreCase$4::class$ = nullptr;

class Utils$$Lambda$lambda$static$5$5 : public $Predicate {
	$class(Utils$$Lambda$lambda$static$5$5, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* k) override {
		 return Utils::lambda$static$5($cast($String, k));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$static$5$5>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$lambda$static$5$5::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$static$5$5::*)()>(&Utils$$Lambda$lambda$static$5$5::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$static$5$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$static$5$5",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$lambda$static$5$5::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$static$5$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$static$5$5::class$ = nullptr;

class Utils$$Lambda$lambda$static$6$6 : public $Predicate {
	$class(Utils$$Lambda$lambda$static$6$6, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* s) override {
		 return Utils::lambda$static$6($cast($String, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$static$6$6>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$lambda$static$6$6::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$static$6$6::*)()>(&Utils$$Lambda$lambda$static$6$6::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$static$6$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$static$6$6",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$lambda$static$6$6::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$static$6$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$static$6$6::class$ = nullptr;

class Utils$$Lambda$lambda$static$10$7 : public $BiPredicate {
	$class(Utils$$Lambda$lambda$static$10$7, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$() {
	}
	virtual bool test(Object$* s, Object$* v) override {
		 return Utils::lambda$static$10($cast($String, s), $cast($String, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$static$10$7>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$lambda$static$10$7::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$static$10$7::*)()>(&Utils$$Lambda$lambda$static$10$7::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$static$10$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$static$10$7",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$lambda$static$10$7::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$static$10$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$static$10$7::class$ = nullptr;

class Utils$$Lambda$lambda$static$11$8 : public $BiPredicate {
	$class(Utils$$Lambda$lambda$static$11$8, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$() {
	}
	virtual bool test(Object$* s, Object$* v) override {
		 return Utils::lambda$static$11($cast($String, s), $cast($String, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$static$11$8>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$lambda$static$11$8::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$static$11$8::*)()>(&Utils$$Lambda$lambda$static$11$8::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$static$11$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$static$11$8",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$lambda$static$11$8::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$static$11$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$static$11$8::class$ = nullptr;

class Utils$$Lambda$lambda$static$12$9 : public $BiPredicate {
	$class(Utils$$Lambda$lambda$static$12$9, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$() {
	}
	virtual bool test(Object$* n, Object$* v) override {
		 return Utils::lambda$static$12($cast($String, n), $cast($String, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$static$12$9>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$lambda$static$12$9::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$static$12$9::*)()>(&Utils$$Lambda$lambda$static$12$9::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$static$12$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$static$12$9",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$lambda$static$12$9::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$static$12$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$static$12$9::class$ = nullptr;

class Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10 : public $BiPredicate {
	$class(Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10, $NO_CLASS_INIT, $BiPredicate)
public:
	void init$($HttpClient* client) {
		$set(this, client, client);
	}
	virtual bool test(Object$* k, Object$* v) override {
		 return Utils::lambda$CONTEXT_RESTRICTED$3(client, $cast($String, k), $cast($String, v));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10>());
	}
	$HttpClient* client = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10::fieldInfos[2] = {
	{"client", "Ljava/net/http/HttpClient;", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10, client)},
	{}
};
$MethodInfo Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10::methodInfos[3] = {
	{"<init>", "(Ljava/net/http/HttpClient;)V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10::*)($HttpClient*)>(&Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10::init$))},
	{"test", "(Ljava/lang/Object;Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10",
	"java.lang.Object",
	"java.util.function.BiPredicate",
	fieldInfos,
	methodInfos
};
$Class* Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10::class$ = nullptr;

class Utils$$Lambda$lambda$wrapForDebug$9$11 : public $BiFunction {
	$class(Utils$$Lambda$lambda$wrapForDebug$9$11, $NO_CLASS_INIT, $BiFunction)
public:
	void init$($Logger* logger, $String* name, $CompletableFuture* cf) {
		$set(this, logger, logger);
		$set(this, name, name);
		$set(this, cf, cf);
	}
	virtual $Object* apply(Object$* r, Object$* t) override {
		 return $of(Utils::lambda$wrapForDebug$9(logger, name, cf, r, $cast($Throwable, t)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$wrapForDebug$9$11>());
	}
	$Logger* logger = nullptr;
	$String* name = nullptr;
	$CompletableFuture* cf = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Utils$$Lambda$lambda$wrapForDebug$9$11::fieldInfos[4] = {
	{"logger", "Ljdk/internal/net/http/common/Logger;", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$wrapForDebug$9$11, logger)},
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$wrapForDebug$9$11, name)},
	{"cf", "Ljava/util/concurrent/CompletableFuture;", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$wrapForDebug$9$11, cf)},
	{}
};
$MethodInfo Utils$$Lambda$lambda$wrapForDebug$9$11::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/common/Logger;Ljava/lang/String;Ljava/util/concurrent/CompletableFuture;)V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$wrapForDebug$9$11::*)($Logger*,$String*,$CompletableFuture*)>(&Utils$$Lambda$lambda$wrapForDebug$9$11::init$))},
	{"apply", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$wrapForDebug$9$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$wrapForDebug$9$11",
	"java.lang.Object",
	"java.util.function.BiFunction",
	fieldInfos,
	methodInfos
};
$Class* Utils$$Lambda$lambda$wrapForDebug$9$11::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$wrapForDebug$9$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$wrapForDebug$9$11::class$ = nullptr;

class Utils$$Lambda$lambda$getIntegerNetProperty$13$12 : public $PrivilegedAction {
	$class(Utils$$Lambda$lambda$getIntegerNetProperty$13$12, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* name, int32_t defaultValue) {
		$set(this, name, name);
		this->defaultValue = defaultValue;
	}
	virtual $Object* run() override {
		 return $of(Utils::lambda$getIntegerNetProperty$13(name, defaultValue));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$getIntegerNetProperty$13$12>());
	}
	$String* name = nullptr;
	int32_t defaultValue = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Utils$$Lambda$lambda$getIntegerNetProperty$13$12::fieldInfos[3] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$getIntegerNetProperty$13$12, name)},
	{"defaultValue", "I", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$getIntegerNetProperty$13$12, defaultValue)},
	{}
};
$MethodInfo Utils$$Lambda$lambda$getIntegerNetProperty$13$12::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$getIntegerNetProperty$13$12::*)($String*,int32_t)>(&Utils$$Lambda$lambda$getIntegerNetProperty$13$12::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$getIntegerNetProperty$13$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$getIntegerNetProperty$13$12",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Utils$$Lambda$lambda$getIntegerNetProperty$13$12::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$getIntegerNetProperty$13$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$getIntegerNetProperty$13$12::class$ = nullptr;

class Utils$$Lambda$lambda$getNetProperty$14$13 : public $PrivilegedAction {
	$class(Utils$$Lambda$lambda$getNetProperty$14$13, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* name) {
		$set(this, name, name);
	}
	virtual $Object* run() override {
		 return $of(Utils::lambda$getNetProperty$14(name));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$getNetProperty$14$13>());
	}
	$String* name = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Utils$$Lambda$lambda$getNetProperty$14$13::fieldInfos[2] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$getNetProperty$14$13, name)},
	{}
};
$MethodInfo Utils$$Lambda$lambda$getNetProperty$14$13::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$getNetProperty$14$13::*)($String*)>(&Utils$$Lambda$lambda$getNetProperty$14$13::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$getNetProperty$14$13::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$getNetProperty$14$13",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Utils$$Lambda$lambda$getNetProperty$14$13::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$getNetProperty$14$13, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$getNetProperty$14$13::class$ = nullptr;

class Utils$$Lambda$lambda$getBooleanProperty$15$14 : public $PrivilegedAction {
	$class(Utils$$Lambda$lambda$getBooleanProperty$15$14, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* name, bool def) {
		$set(this, name, name);
		this->def = def;
	}
	virtual $Object* run() override {
		 return $of(Utils::lambda$getBooleanProperty$15(name, def));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$getBooleanProperty$15$14>());
	}
	$String* name = nullptr;
	bool def = false;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Utils$$Lambda$lambda$getBooleanProperty$15$14::fieldInfos[3] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$getBooleanProperty$15$14, name)},
	{"def", "Z", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$getBooleanProperty$15$14, def)},
	{}
};
$MethodInfo Utils$$Lambda$lambda$getBooleanProperty$15$14::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;Z)V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$getBooleanProperty$15$14::*)($String*,bool)>(&Utils$$Lambda$lambda$getBooleanProperty$15$14::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$getBooleanProperty$15$14::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$getBooleanProperty$15$14",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Utils$$Lambda$lambda$getBooleanProperty$15$14::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$getBooleanProperty$15$14, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$getBooleanProperty$15$14::class$ = nullptr;

class Utils$$Lambda$lambda$getProperty$16$15 : public $PrivilegedAction {
	$class(Utils$$Lambda$lambda$getProperty$16$15, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* name) {
		$set(this, name, name);
	}
	virtual $Object* run() override {
		 return $of(Utils::lambda$getProperty$16(name));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$getProperty$16$15>());
	}
	$String* name = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Utils$$Lambda$lambda$getProperty$16$15::fieldInfos[2] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$getProperty$16$15, name)},
	{}
};
$MethodInfo Utils$$Lambda$lambda$getProperty$16$15::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$getProperty$16$15::*)($String*)>(&Utils$$Lambda$lambda$getProperty$16$15::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$getProperty$16$15::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$getProperty$16$15",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Utils$$Lambda$lambda$getProperty$16$15::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$getProperty$16$15, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$getProperty$16$15::class$ = nullptr;

class Utils$$Lambda$lambda$getIntegerProperty$17$16 : public $PrivilegedAction {
	$class(Utils$$Lambda$lambda$getIntegerProperty$17$16, $NO_CLASS_INIT, $PrivilegedAction)
public:
	void init$($String* name, int32_t defaultValue) {
		$set(this, name, name);
		this->defaultValue = defaultValue;
	}
	virtual $Object* run() override {
		 return $of(Utils::lambda$getIntegerProperty$17(name, defaultValue));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$getIntegerProperty$17$16>());
	}
	$String* name = nullptr;
	int32_t defaultValue = 0;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Utils$$Lambda$lambda$getIntegerProperty$17$16::fieldInfos[3] = {
	{"name", "Ljava/lang/String;", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$getIntegerProperty$17$16, name)},
	{"defaultValue", "I", nullptr, $PUBLIC, $field(Utils$$Lambda$lambda$getIntegerProperty$17$16, defaultValue)},
	{}
};
$MethodInfo Utils$$Lambda$lambda$getIntegerProperty$17$16::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;I)V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$getIntegerProperty$17$16::*)($String*,int32_t)>(&Utils$$Lambda$lambda$getIntegerProperty$17$16::init$))},
	{"run", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$getIntegerProperty$17$16::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$getIntegerProperty$17$16",
	"java.lang.Object",
	"java.security.PrivilegedAction",
	fieldInfos,
	methodInfos
};
$Class* Utils$$Lambda$lambda$getIntegerProperty$17$16::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$getIntegerProperty$17$16, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$getIntegerProperty$17$16::class$ = nullptr;

class Utils$$Lambda$trim$17 : public $Function {
	$class(Utils$$Lambda$trim$17, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* inst$) override {
		 return $of($sure($String, inst$)->trim());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$trim$17>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$trim$17::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$trim$17::*)()>(&Utils$$Lambda$trim$17::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$trim$17::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$trim$17",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$trim$17::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$trim$17, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$trim$17::class$ = nullptr;

class Utils$$Lambda$lambda$static$7$18 : public $Predicate {
	$class(Utils$$Lambda$lambda$static$7$18, $NO_CLASS_INIT, $Predicate)
public:
	void init$() {
	}
	virtual bool test(Object$* s) override {
		 return Utils::lambda$static$7($cast($String, s));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Utils$$Lambda$lambda$static$7$18>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Utils$$Lambda$lambda$static$7$18::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Utils$$Lambda$lambda$static$7$18::*)()>(&Utils$$Lambda$lambda$static$7$18::init$))},
	{"test", "(Ljava/lang/Object;)Z", nullptr, $PUBLIC},
	{}
};
$ClassInfo Utils$$Lambda$lambda$static$7$18::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.common.Utils$$Lambda$lambda$static$7$18",
	"java.lang.Object",
	"java.util.function.Predicate",
	nullptr,
	methodInfos
};
$Class* Utils$$Lambda$lambda$static$7$18::load$($String* name, bool initialize) {
	$loadClass(Utils$$Lambda$lambda$static$7$18, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Utils$$Lambda$lambda$static$7$18::class$ = nullptr;

$FieldInfo _Utils_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Utils, $assertionsDisabled)},
	{"ASSERTIONSENABLED", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Utils, ASSERTIONSENABLED)},
	{"DEBUG", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Utils, DEBUG)},
	{"DEBUG_WS", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Utils, DEBUG_WS)},
	{"DEBUG_HPACK", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Utils, DEBUG_HPACK)},
	{"TESTING", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Utils, TESTING)},
	{"isHostnameVerificationDisabled", "Z", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Utils, isHostnameVerificationDisabled$)},
	{"DEFAULT_BUFSIZE", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Utils, DEFAULT_BUFSIZE)},
	{"BUFSIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Utils, BUFSIZE)},
	{"ACCEPT_ALL", "Ljava/util/function/BiPredicate;", "Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(Utils, ACCEPT_ALL)},
	{"DISALLOWED_HEADERS_SET", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Utils, DISALLOWED_HEADERS_SET)},
	{"ALLOWED_HEADERS", "Ljava/util/function/BiPredicate;", "Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(Utils, ALLOWED_HEADERS)},
	{"VALIDATE_USER_HEADER", "Ljava/util/function/BiPredicate;", "Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(Utils, VALIDATE_USER_HEADER)},
	{"HOST_RESTRICTED", "Ljava/util/function/BiPredicate;", "Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Utils, HOST_RESTRICTED)},
	{"IS_HOST", "Ljava/util/function/Predicate;", "Ljava/util/function/Predicate<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Utils, IS_HOST)},
	{"IS_PROXY_HEADER", "Ljava/util/function/Predicate;", "Ljava/util/function/Predicate<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Utils, IS_PROXY_HEADER)},
	{"NO_PROXY_HEADER", "Ljava/util/function/Predicate;", "Ljava/util/function/Predicate<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Utils, NO_PROXY_HEADER)},
	{"ALL_HEADERS", "Ljava/util/function/Predicate;", "Ljava/util/function/Predicate<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Utils, ALL_HEADERS)},
	{"PROXY_AUTH_DISABLED_SCHEMES", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Utils, PROXY_AUTH_DISABLED_SCHEMES)},
	{"PROXY_AUTH_TUNNEL_DISABLED_SCHEMES", "Ljava/util/Set;", "Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC | $FINAL, $staticField(Utils, PROXY_AUTH_TUNNEL_DISABLED_SCHEMES)},
	{"WSPACES", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Utils, WSPACES)},
	{"PROXY_TUNNEL_FILTER", "Ljava/util/function/BiPredicate;", "Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(Utils, PROXY_TUNNEL_FILTER)},
	{"PROXY_FILTER", "Ljava/util/function/BiPredicate;", "Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(Utils, PROXY_FILTER)},
	{"NO_PROXY_HEADERS_FILTER", "Ljava/util/function/BiPredicate;", "Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $staticField(Utils, NO_PROXY_HEADERS_FILTER)},
	{"HEADER_CONNECTION", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Utils, HEADER_CONNECTION)},
	{"HEADER_UPGRADE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Utils, HEADER_UPGRADE)},
	{"tchar", "[Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Utils, tchar)},
	{"fieldvchar", "[Z", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Utils, fieldvchar)},
	{"COPY_THRESHOLD", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Utils, COPY_THRESHOLD)},
	{"EMPTY_BYTEBUFFER", "Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Utils, EMPTY_BYTEBUFFER)},
	{"EMPTY_BB_ARRAY", "[Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC | $FINAL, $staticField(Utils, EMPTY_BB_ARRAY)},
	{"EMPTY_BB_LIST", "Ljava/util/List;", "Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PUBLIC | $STATIC | $FINAL, $staticField(Utils, EMPTY_BB_LIST)},
	{}
};

$MethodInfo _Utils_MethodInfo_[] = {
	{"<init>", "()V", nullptr, $PRIVATE, $method(static_cast<void(Utils::*)()>(&Utils::init$))},
	{"CONTEXT_RESTRICTED", "(Ljava/net/http/HttpClient;)Ljava/util/function/BiPredicate;", "(Ljava/net/http/HttpClient;)Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $method(static_cast<$BiPredicate*(*)($HttpClient*)>(&Utils::CONTEXT_RESTRICTED))},
	{"PROXY_TUNNEL_RESTRICTED", "(Ljava/net/http/HttpClient;)Ljava/util/function/BiPredicate;", "(Ljava/net/http/HttpClient;)Ljava/util/function/BiPredicate<Ljava/lang/String;Ljava/lang/String;>;", $PUBLIC | $STATIC | $FINAL, $method(static_cast<$BiPredicate*(*)($HttpClient*)>(&Utils::PROXY_TUNNEL_RESTRICTED))},
	{"accumulateBuffers", "(Ljava/util/List;Ljava/util/List;)J", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;Ljava/util/List<Ljava/nio/ByteBuffer;>;)J", $PUBLIC | $STATIC, $method(static_cast<int64_t(*)($List*,$List*)>(&Utils::accumulateBuffers))},
	{"charsetFrom", "(Ljava/net/http/HttpHeaders;)Ljava/nio/charset/Charset;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Charset*(*)($HttpHeaders*)>(&Utils::charsetFrom))},
	{"close", "([Ljava/io/Closeable;)V", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<void(*)($CloseableArray*)>(&Utils::close))},
	{"copy", "(Ljava/nio/ByteBuffer;Ljava/nio/ByteBuffer;)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($ByteBuffer*,$ByteBuffer*)>(&Utils::copy))},
	{"copy", "(Ljava/nio/ByteBuffer;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ByteBuffer*(*)($ByteBuffer*)>(&Utils::copy))},
	{"copyAligned", "(Ljava/nio/ByteBuffer;)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ByteBuffer*(*)($ByteBuffer*)>(&Utils::copyAligned))},
	{"copySSLParameters", "(Ljavax/net/ssl/SSLParameters;)Ljavax/net/ssl/SSLParameters;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$SSLParameters*(*)($SSLParameters*)>(&Utils::copySSLParameters))},
	{"dump", "([Ljava/lang/Object;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<$String*(*)($ObjectArray*)>(&Utils::dump))},
	{"encode", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($String*)>(&Utils::encode))},
	{"flipToMark", "(Ljava/nio/ByteBuffer;I)V", nullptr, $PUBLIC | $STATIC, $method(static_cast<void(*)($ByteBuffer*,int32_t)>(&Utils::flipToMark))},
	{"getBooleanProperty", "(Ljava/lang/String;Z)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)($String*,bool)>(&Utils::getBooleanProperty))},
	{"getBuffer", "()Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ByteBuffer*(*)()>(&Utils::getBuffer))},
	{"getCancelCause", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Throwable*(*)($Throwable*)>(&Utils::getCancelCause))},
	{"getCompletionCause", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Throwable*(*)($Throwable*)>(&Utils::getCompletionCause))},
	{"getDebugLogger", "(Ljava/util/function/Supplier;)Ljdk/internal/net/http/common/Logger;", "(Ljava/util/function/Supplier<Ljava/lang/String;>;)Ljdk/internal/net/http/common/Logger;", $PUBLIC | $STATIC, $method(static_cast<$Logger*(*)($Supplier*)>(&Utils::getDebugLogger))},
	{"getDebugLogger", "(Ljava/util/function/Supplier;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/Logger;", "(Ljava/util/function/Supplier<Ljava/lang/String;>;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/Logger;", $STATIC, $method(static_cast<$Logger*(*)($Supplier*,$System$Logger$Level*)>(&Utils::getDebugLogger))},
	{"getDebugLogger", "(Ljava/util/function/Supplier;Z)Ljdk/internal/net/http/common/Logger;", "(Ljava/util/function/Supplier<Ljava/lang/String;>;Z)Ljdk/internal/net/http/common/Logger;", $PUBLIC | $STATIC, $method(static_cast<$Logger*(*)($Supplier*,bool)>(&Utils::getDebugLogger))},
	{"getDisallowedHeaders", "()Ljava/util/Set;", "()Ljava/util/Set<Ljava/lang/String;>;", $PRIVATE | $STATIC, $method(static_cast<$Set*(*)()>(&Utils::getDisallowedHeaders))},
	{"getHpackLogger", "(Ljava/util/function/Supplier;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/Logger;", "(Ljava/util/function/Supplier<Ljava/lang/String;>;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/Logger;", $PUBLIC | $STATIC, $method(static_cast<$Logger*(*)($Supplier*,$System$Logger$Level*)>(&Utils::getHpackLogger))},
	{"getHpackLogger", "(Ljava/util/function/Supplier;Z)Ljdk/internal/net/http/common/Logger;", "(Ljava/util/function/Supplier<Ljava/lang/String;>;Z)Ljdk/internal/net/http/common/Logger;", $PUBLIC | $STATIC, $method(static_cast<$Logger*(*)($Supplier*,bool)>(&Utils::getHpackLogger))},
	{"getIOException", "(Ljava/lang/Throwable;)Ljava/io/IOException;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$IOException*(*)($Throwable*)>(&Utils::getIOException))},
	{"getIntegerNetProperty", "(Ljava/lang/String;I)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($String*,int32_t)>(&Utils::getIntegerNetProperty))},
	{"getIntegerProperty", "(Ljava/lang/String;I)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($String*,int32_t)>(&Utils::getIntegerProperty))},
	{"getNetProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($String*)>(&Utils::getNetProperty))},
	{"getProperty", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($String*)>(&Utils::getProperty))},
	{"getServerName", "(Ljava/net/InetSocketAddress;)Ljdk/internal/net/http/common/Utils$ServerName;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Utils$ServerName*(*)($InetSocketAddress*)>(&Utils::getServerName))},
	{"getWebSocketLogger", "(Ljava/util/function/Supplier;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/Logger;", "(Ljava/util/function/Supplier<Ljava/lang/String;>;Ljava/lang/System$Logger$Level;)Ljdk/internal/net/http/common/Logger;", $PUBLIC | $STATIC, $method(static_cast<$Logger*(*)($Supplier*,$System$Logger$Level*)>(&Utils::getWebSocketLogger))},
	{"getWebSocketLogger", "(Ljava/util/function/Supplier;Z)Ljdk/internal/net/http/common/Logger;", "(Ljava/util/function/Supplier<Ljava/lang/String;>;Z)Ljdk/internal/net/http/common/Logger;", $PUBLIC | $STATIC, $method(static_cast<$Logger*(*)($Supplier*,bool)>(&Utils::getWebSocketLogger))},
	{"hasRemaining", "(Ljava/util/List;)Z", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)Z", $PUBLIC | $STATIC, $method(static_cast<bool(*)($List*)>(&Utils::hasRemaining))},
	{"hostString", "(Ljdk/internal/net/http/HttpRequestImpl;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($HttpRequestImpl*)>(&Utils::hostString))},
	{"hostnameVerificationDisabledValue", "()Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)()>(&Utils::hostnameVerificationDisabledValue))},
	{"immutableSession", "(Ljavax/net/ssl/SSLSession;)Ljavax/net/ssl/SSLSession;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$SSLSession*(*)($SSLSession*)>(&Utils::immutableSession))},
	{"isAllowedForProxy", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Set;Ljava/util/function/Predicate;)Z", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Set<Ljava/lang/String;>;Ljava/util/function/Predicate<Ljava/lang/String;>;)Z", $PRIVATE | $STATIC | $FINAL, $method(static_cast<bool(*)($String*,$String*,$Set*,$Predicate*)>(&Utils::isAllowedForProxy))},
	{"isHostnameVerificationDisabled", "()Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)()>(&Utils::isHostnameVerificationDisabled))},
	{"isLoopbackLiteral", "([B)Z", nullptr, $PRIVATE | $STATIC, $method(static_cast<bool(*)($bytes*)>(&Utils::isLoopbackLiteral))},
	{"isValidName", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)($String*)>(&Utils::isValidName))},
	{"isValidValue", "(Ljava/lang/String;)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)($String*)>(&Utils::isValidValue))},
	{"lambda$CONTEXT_RESTRICTED$3", "(Ljava/net/http/HttpClient;Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($HttpClient*,$String*,$String*)>(&Utils::lambda$CONTEXT_RESTRICTED$3))},
	{"lambda$getBooleanProperty$15", "(Ljava/lang/String;Z)Ljava/lang/Boolean;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Boolean*(*)($String*,bool)>(&Utils::lambda$getBooleanProperty$15))},
	{"lambda$getIntegerNetProperty$13", "(Ljava/lang/String;I)Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Integer*(*)($String*,int32_t)>(&Utils::lambda$getIntegerNetProperty$13))},
	{"lambda$getIntegerProperty$17", "(Ljava/lang/String;I)Ljava/lang/Integer;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$Integer*(*)($String*,int32_t)>(&Utils::lambda$getIntegerProperty$17))},
	{"lambda$getNetProperty$14", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($String*)>(&Utils::lambda$getNetProperty$14))},
	{"lambda$getProperty$16", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($String*)>(&Utils::lambda$getProperty$16))},
	{"lambda$static$0", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*,$String*)>(&Utils::lambda$static$0))},
	{"lambda$static$1", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*,$String*)>(&Utils::lambda$static$1))},
	{"lambda$static$10", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*,$String*)>(&Utils::lambda$static$10))},
	{"lambda$static$11", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*,$String*)>(&Utils::lambda$static$11))},
	{"lambda$static$12", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*,$String*)>(&Utils::lambda$static$12))},
	{"lambda$static$2", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*,$String*)>(&Utils::lambda$static$2))},
	{"lambda$static$4", "(Ljava/lang/String;Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*,$String*)>(&Utils::lambda$static$4))},
	{"lambda$static$5", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*)>(&Utils::lambda$static$5))},
	{"lambda$static$6", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*)>(&Utils::lambda$static$6))},
	{"lambda$static$7", "(Ljava/lang/String;)Z", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<bool(*)($String*)>(&Utils::lambda$static$7))},
	{"lambda$wrapForDebug$9", "(Ljdk/internal/net/http/common/Logger;Ljava/lang/String;Ljava/util/concurrent/CompletableFuture;Ljava/lang/Object;Ljava/lang/Throwable;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$CompletableFuture*(*)($Logger*,$String*,$CompletableFuture*,Object$*,$Throwable*)>(&Utils::lambda$wrapForDebug$9))},
	{"newIAE", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/IllegalArgumentException;", nullptr, $PUBLIC | $STATIC | $TRANSIENT, $method(static_cast<$IllegalArgumentException*(*)($String*,$ObjectArray*)>(&Utils::newIAE))},
	{"permissionForProxy", "(Ljava/net/InetSocketAddress;)Ljava/net/URLPermission;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$URLPermission*(*)($InetSocketAddress*)>(&Utils::permissionForProxy))},
	{"permissionForServer", "(Ljava/net/URI;Ljava/lang/String;Ljava/util/stream/Stream;)Ljava/net/URLPermission;", "(Ljava/net/URI;Ljava/lang/String;Ljava/util/stream/Stream<Ljava/lang/String;>;)Ljava/net/URLPermission;", $PUBLIC | $STATIC, $method(static_cast<$URLPermission*(*)($URI*,$String*,$Stream*)>(&Utils::permissionForServer))},
	{"pow2Size", "(I)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)(int32_t)>(&Utils::pow2Size))},
	{"proxyHasDisabledSchemes", "(Z)Z", nullptr, $PUBLIC | $STATIC, $method(static_cast<bool(*)(bool)>(&Utils::proxyHasDisabledSchemes))},
	{"remaining", "([Ljava/nio/ByteBuffer;)J", nullptr, $PUBLIC | $STATIC, $method(static_cast<int64_t(*)($ByteBufferArray*)>(&Utils::remaining))},
	{"remaining", "(Ljava/util/List;)J", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)J", $PUBLIC | $STATIC, $method(static_cast<int64_t(*)($List*)>(&Utils::remaining))},
	{"remaining", "(Ljava/util/List;I)I", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;I)I", $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($List*,int32_t)>(&Utils::remaining))},
	{"remaining", "([Ljava/nio/ByteBuffer;I)I", nullptr, $PUBLIC | $STATIC, $method(static_cast<int32_t(*)($ByteBufferArray*,int32_t)>(&Utils::remaining))},
	{"resolveAddress", "(Ljava/net/InetSocketAddress;)Ljava/net/InetSocketAddress;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$InetSocketAddress*(*)($InetSocketAddress*)>(&Utils::resolveAddress))},
	{"setWebSocketUpgradeHeaders", "(Ljdk/internal/net/http/HttpRequestImpl;)V", nullptr, $PUBLIC | $STATIC | $FINAL, $method(static_cast<void(*)($HttpRequestImpl*)>(&Utils::setWebSocketUpgradeHeaders))},
	{"sliceWithLimitedCapacity", "(Ljava/nio/ByteBuffer;I)Ljava/nio/ByteBuffer;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$ByteBuffer*(*)($ByteBuffer*,int32_t)>(&Utils::sliceWithLimitedCapacity))},
	{"stackTrace", "(Ljava/lang/Throwable;)Ljava/lang/String;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$String*(*)($Throwable*)>(&Utils::stackTrace))},
	{"stringOf", "(Ljava/util/Collection;)Ljava/lang/String;", "(Ljava/util/Collection<*>;)Ljava/lang/String;", $PUBLIC | $STATIC, $method(static_cast<$String*(*)($Collection*)>(&Utils::stringOf))},
	{"synchronizedRemaining", "(Ljava/util/List;)J", "(Ljava/util/List<Ljava/nio/ByteBuffer;>;)J", $PUBLIC | $STATIC, $method(static_cast<int64_t(*)($List*)>(&Utils::synchronizedRemaining))},
	{"toConnectException", "(Ljava/lang/Throwable;)Ljava/lang/Throwable;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$Throwable*(*)($Throwable*)>(&Utils::toConnectException))},
	{"unchecked", "(Ljava/io/IOException;)Ljava/io/UncheckedIOException;", nullptr, $PUBLIC | $STATIC, $method(static_cast<$UncheckedIOException*(*)($IOException*)>(&Utils::unchecked))},
	{"wrapForDebug", "(Ljdk/internal/net/http/common/Logger;Ljava/lang/String;Ljava/util/concurrent/CompletableFuture;)Ljava/util/concurrent/CompletableFuture;", "<T:Ljava/lang/Object;>(Ljdk/internal/net/http/common/Logger;Ljava/lang/String;Ljava/util/concurrent/CompletableFuture<TT;>;)Ljava/util/concurrent/CompletableFuture<TT;>;", $PUBLIC | $STATIC, $method(static_cast<$CompletableFuture*(*)($Logger*,$String*,$CompletableFuture*)>(&Utils::wrapForDebug))},
	{"wrapWithExtraDetail", "(Ljava/lang/Throwable;Ljava/util/function/Supplier;)Ljava/lang/Throwable;", "(Ljava/lang/Throwable;Ljava/util/function/Supplier<Ljava/lang/String;>;)Ljava/lang/Throwable;", $PUBLIC | $STATIC, $method(static_cast<$Throwable*(*)($Throwable*,$Supplier*)>(&Utils::wrapWithExtraDetail))},
	{}
};

$InnerClassInfo _Utils_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.common.Utils$ServerName", "jdk.internal.net.http.common.Utils", "ServerName", $PUBLIC | $STATIC},
	{"jdk.internal.net.http.common.Utils$ProxyHeaders", "jdk.internal.net.http.common.Utils", "ProxyHeaders", $PUBLIC | $STATIC | $FINAL},
	{}
};

$ClassInfo _Utils_ClassInfo_ = {
	$PUBLIC | $FINAL | $ACC_SUPER,
	"jdk.internal.net.http.common.Utils",
	"java.lang.Object",
	nullptr,
	_Utils_FieldInfo_,
	_Utils_MethodInfo_,
	nullptr,
	nullptr,
	_Utils_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.common.Utils$ServerName,jdk.internal.net.http.common.Utils$ProxyHeaders"
};

$Object* allocate$Utils($Class* clazz) {
	return $of($alloc(Utils));
}

bool Utils::$assertionsDisabled = false;
bool Utils::ASSERTIONSENABLED = false;
bool Utils::DEBUG = false;
bool Utils::DEBUG_WS = false;
bool Utils::DEBUG_HPACK = false;
bool Utils::TESTING = false;
bool Utils::isHostnameVerificationDisabled$ = false;
int32_t Utils::BUFSIZE = 0;
$BiPredicate* Utils::ACCEPT_ALL = nullptr;
$Set* Utils::DISALLOWED_HEADERS_SET = nullptr;
$BiPredicate* Utils::ALLOWED_HEADERS = nullptr;
$BiPredicate* Utils::VALIDATE_USER_HEADER = nullptr;
$BiPredicate* Utils::HOST_RESTRICTED = nullptr;
$Predicate* Utils::IS_HOST = nullptr;
$Predicate* Utils::IS_PROXY_HEADER = nullptr;
$Predicate* Utils::NO_PROXY_HEADER = nullptr;
$Predicate* Utils::ALL_HEADERS = nullptr;
$Set* Utils::PROXY_AUTH_DISABLED_SCHEMES = nullptr;
$Set* Utils::PROXY_AUTH_TUNNEL_DISABLED_SCHEMES = nullptr;
$String* Utils::WSPACES = nullptr;
$BiPredicate* Utils::PROXY_TUNNEL_FILTER = nullptr;
$BiPredicate* Utils::PROXY_FILTER = nullptr;
$BiPredicate* Utils::NO_PROXY_HEADERS_FILTER = nullptr;
$String* Utils::HEADER_CONNECTION = nullptr;
$String* Utils::HEADER_UPGRADE = nullptr;
$booleans* Utils::tchar = nullptr;
$booleans* Utils::fieldvchar = nullptr;
$ByteBuffer* Utils::EMPTY_BYTEBUFFER = nullptr;
$ByteBufferArray* Utils::EMPTY_BB_ARRAY = nullptr;
$List* Utils::EMPTY_BB_LIST = nullptr;

bool Utils::hostnameVerificationDisabledValue() {
	$init(Utils);
	$var($String, prop, getProperty("jdk.internal.httpclient.disableHostnameVerification"_s));
	if (prop == nullptr) {
		return false;
	}
	return $nc(prop)->isEmpty() ? true : $Boolean::parseBoolean(prop);
}

$Set* Utils::getDisallowedHeaders() {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$var($Set, headers, static_cast<$Set*>(static_cast<$AbstractSet*>($new($TreeSet, $String::CASE_INSENSITIVE_ORDER))));
	headers->addAll($($Set::of("connection"_s, "content-length"_s, "expect"_s, "host"_s, "upgrade"_s)));
	$var($String, v, getNetProperty("jdk.httpclient.allowRestrictedHeaders"_s));
	if (v != nullptr) {
		$var($StringArray, tokens, $(v->trim())->split(","_s));
		{
			$var($StringArray, arr$, tokens);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				$var($String, token, arr$->get(i$));
				{
					headers->remove(token);
				}
			}
		}
		return $Collections::unmodifiableSet(headers);
	} else {
		return $Collections::unmodifiableSet(headers);
	}
}

$BiPredicate* Utils::CONTEXT_RESTRICTED($HttpClient* client) {
	$init(Utils);
	return static_cast<$BiPredicate*>($new(Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10, client));
}

$BiPredicate* Utils::PROXY_TUNNEL_RESTRICTED($HttpClient* client) {
	$init(Utils);
	return $nc($(CONTEXT_RESTRICTED(client)))->and$(Utils::HOST_RESTRICTED);
}

$CompletableFuture* Utils::wrapForDebug($Logger* logger, $String* name, $CompletableFuture* cf) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	if ($nc(logger)->on()) {
		return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc(cf)->handle(static_cast<$BiFunction*>($$new(Utils$$Lambda$lambda$wrapForDebug$9$11, logger, name, cf))))))->thenCompose($($Function::identity())));
	} else {
		return cf;
	}
}

bool Utils::isAllowedForProxy($String* name, $String* value, $Set* disabledSchemes, $Predicate* allowedKeys) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	if (!$nc(allowedKeys)->test(name)) {
		return false;
	}
	if ($nc(disabledSchemes)->isEmpty()) {
		return true;
	}
	if ($nc(name)->equalsIgnoreCase("proxy-authorization"_s)) {
		if ($nc(value)->isEmpty()) {
			return false;
		}
		{
			$var($Iterator, i$, $nc(disabledSchemes)->iterator());
			for (; $nc(i$)->hasNext();) {
				$var($String, scheme, $cast($String, i$->next()));
				{
					int32_t slen = $nc(scheme)->length();
					int32_t vlen = $nc(value)->length();
					if (vlen == slen) {
						if (value->equalsIgnoreCase(scheme)) {
							return false;
						}
					} else if (vlen > slen) {
						if ($(value->substring(0, slen))->equalsIgnoreCase(scheme)) {
							int32_t c = value->codePointAt(slen);
							bool var$1 = $nc(Utils::WSPACES)->indexOf(c) > -1;
							bool var$0 = var$1 || $Character::isSpaceChar(c);
							if (var$0 || $Character::isWhitespace(c)) {
								return false;
							}
						}
					}
				}
			}
		}
	}
	return true;
}

bool Utils::proxyHasDisabledSchemes(bool tunnel) {
	$init(Utils);
	return tunnel ? !$nc(Utils::PROXY_AUTH_TUNNEL_DISABLED_SCHEMES)->isEmpty() : !$nc(Utils::PROXY_AUTH_DISABLED_SCHEMES)->isEmpty();
}

void Utils::setWebSocketUpgradeHeaders($HttpRequestImpl* request) {
	$init(Utils);
	$nc(request)->setSystemHeader(Utils::HEADER_UPGRADE, "websocket"_s);
	request->setSystemHeader(Utils::HEADER_CONNECTION, "Upgrade"_s);
}

$IllegalArgumentException* Utils::newIAE($String* message, $ObjectArray* args) {
	$init(Utils);
	return $new($IllegalArgumentException, $($String::format(message, args)));
}

$ByteBuffer* Utils::getBuffer() {
	$init(Utils);
	return $ByteBuffer::allocate(Utils::BUFSIZE);
}

$Throwable* Utils::getCompletionCause($Throwable* x) {
	$init(Utils);
	$var($Throwable, cause, x);
	while (($instanceOf($CompletionException, cause)) || ($instanceOf($ExecutionException, cause))) {
		$assign(cause, $nc(cause)->getCause());
	}
	if (cause == nullptr && cause != x) {
		$throwNew($InternalError, "Unexpected null cause"_s, x);
	}
	return cause;
}

$Throwable* Utils::getCancelCause($Throwable* x) {
	$init(Utils);
	$var($Throwable, cause, getCompletionCause(x));
	if ($instanceOf($ConnectionExpiredException, cause)) {
		$assign(cause, $nc(cause)->getCause());
	}
	return cause;
}

$IOException* Utils::getIOException($Throwable* t) {
	$init(Utils);
	if ($instanceOf($IOException, t)) {
		return $cast($IOException, t);
	}
	$var($Throwable, cause, $nc(t)->getCause());
	if (cause != nullptr) {
		return getIOException(cause);
	}
	return $new($IOException, t);
}

$Throwable* Utils::wrapWithExtraDetail($Throwable* t$renamed, $Supplier* messageSupplier) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$var($Throwable, t, t$renamed);
	if (!($instanceOf($IOException, t))) {
		return t;
	}
	if ($instanceOf($SSLHandshakeException, t)) {
		return t;
	}
	$var($String, msg, $cast($String, $nc(messageSupplier)->get()));
	if (msg == nullptr) {
		return t;
	}
	if ($instanceOf($ConnectionExpiredException, t)) {
		if ($instanceOf($SSLHandshakeException, $($nc(t)->getCause()))) {
			return t;
		}
		$var($IOException, ioe, $new($IOException, msg, $($nc(t)->getCause())));
		$assign(t, $new($ConnectionExpiredException, ioe));
	} else {
		$var($IOException, ioe, $new($IOException, msg, t));
		$assign(t, ioe);
	}
	return t;
}

void Utils::init$() {
}

$URLPermission* Utils::permissionForProxy($InetSocketAddress* proxyAddress) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	if (proxyAddress == nullptr) {
		return nullptr;
	}
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("socket://"_s)->append($($nc(proxyAddress)->getHostString()))->append(":"_s)->append($nc(proxyAddress)->getPort());
	$var($String, urlString, sb->toString());
	return $new($URLPermission, urlString, "CONNECT"_s);
}

$URLPermission* Utils::permissionForServer($URI* uri, $String* method, $Stream* headers) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$var($String, urlString, $$new($StringBuilder)->append($($nc(uri)->getScheme()))->append("://"_s)->append($($nc(uri)->getRawAuthority()))->append($($nc(uri)->getRawPath()))->toString());
	$var($StringBuilder, actionStringBuilder, $new($StringBuilder, method));
	$var($String, collected, $cast($String, $nc(headers)->collect($($Collectors::joining(","_s)))));
	if (!$nc(collected)->isEmpty()) {
		actionStringBuilder->append(":"_s)->append(collected);
	}
	return $new($URLPermission, urlString, $(actionStringBuilder->toString()));
}

bool Utils::isValidName($String* token) {
	$init(Utils);
	for (int32_t i = 0; i < $nc(token)->length(); ++i) {
		char16_t c = token->charAt(i);
		if (c > 255 || !$nc(Utils::tchar)->get(c)) {
			return false;
		}
	}
	return !$nc(token)->isEmpty();
}

$Utils$ServerName* Utils::getServerName($InetSocketAddress* addr) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$var($String, host, $nc(addr)->getHostString());
	$var($bytes, literal, $IPAddressUtil::textToNumericFormatV4(host));
	if (literal == nullptr) {
		$assign(literal, $IPAddressUtil::textToNumericFormatV6(host));
		return $new($Utils$ServerName, host, literal != nullptr);
	} else {
		return $new($Utils$ServerName, host, true);
	}
}

bool Utils::isLoopbackLiteral($bytes* bytes) {
	$init(Utils);
	if ($nc(bytes)->length == 4) {
		return bytes->get(0) == 127;
	} else if (bytes->length == 16) {
		for (int32_t i = 0; i < 14; ++i) {
			if (bytes->get(i) != 0) {
				return false;
			}
		}
		if (bytes->get(15) != 1) {
			return false;
		}
		return true;
	} else {
		$throwNew($InternalError);
	}
}

bool Utils::isValidValue($String* token) {
	$init(Utils);
	for (int32_t i = 0; i < $nc(token)->length(); ++i) {
		char16_t c = token->charAt(i);
		if (c > 255) {
			return false;
		}
		if (c == u' ' || c == u'\t') {
			continue;
		} else {
			if (!$nc(Utils::fieldvchar)->get(c)) {
				return false;
			}
		}
	}
	return true;
}

int32_t Utils::getIntegerNetProperty($String* name, int32_t defaultValue) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	return $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(Utils$$Lambda$lambda$getIntegerNetProperty$13$12, name, defaultValue)))))))->intValue();
}

$String* Utils::getNetProperty($String* name) {
	$init(Utils);
	$beforeCallerSensitive();
	return $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(Utils$$Lambda$lambda$getNetProperty$14$13, name))));
}

bool Utils::getBooleanProperty($String* name, bool def) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	return $nc(($cast($Boolean, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(Utils$$Lambda$lambda$getBooleanProperty$15$14, name, def)))))))->booleanValue();
}

$String* Utils::getProperty($String* name) {
	$init(Utils);
	$beforeCallerSensitive();
	return $cast($String, $AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(Utils$$Lambda$lambda$getProperty$16$15, name))));
}

int32_t Utils::getIntegerProperty($String* name, int32_t defaultValue) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$beforeCallerSensitive();
	return $nc(($cast($Integer, $($AccessController::doPrivileged(static_cast<$PrivilegedAction*>($$new(Utils$$Lambda$lambda$getIntegerProperty$17$16, name, defaultValue)))))))->intValue();
}

$SSLParameters* Utils::copySSLParameters($SSLParameters* p) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$var($SSLParameters, p1, $new($SSLParameters));
	p1->setAlgorithmConstraints($($nc(p)->getAlgorithmConstraints()));
	p1->setCipherSuites($($nc(p)->getCipherSuites()));
	p1->setEnableRetransmissions($nc(p)->getEnableRetransmissions());
	p1->setMaximumPacketSize($nc(p)->getMaximumPacketSize());
	p1->setEndpointIdentificationAlgorithm($($nc(p)->getEndpointIdentificationAlgorithm()));
	p1->setNeedClientAuth($nc(p)->getNeedClientAuth());
	$var($StringArray, protocols, $nc(p)->getProtocols());
	if (protocols != nullptr) {
		p1->setProtocols($cast($StringArray, $(protocols->clone())));
	}
	p1->setSNIMatchers($(p->getSNIMatchers()));
	p1->setServerNames($(p->getServerNames()));
	p1->setUseCipherSuitesOrder(p->getUseCipherSuitesOrder());
	p1->setWantClientAuth(p->getWantClientAuth());
	return p1;
}

void Utils::flipToMark($ByteBuffer* buffer, int32_t mark) {
	$init(Utils);
	$nc(buffer)->limit(buffer->position());
	buffer->position(mark);
}

$String* Utils::stackTrace($Throwable* t) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$var($ByteArrayOutputStream, bos, $new($ByteArrayOutputStream));
	$init($StandardCharsets);
	$var($PrintStream, p, $new($PrintStream, static_cast<$OutputStream*>(bos), true, $StandardCharsets::US_ASCII));
	$nc(t)->printStackTrace(p);
	return bos->toString($StandardCharsets::US_ASCII);
}

int32_t Utils::copy($ByteBuffer* src, $ByteBuffer* dst) {
	$init(Utils);
	int32_t srcLen = $nc(src)->remaining();
	int32_t dstLen = $nc(dst)->remaining();
	if (srcLen > dstLen) {
		int32_t diff = srcLen - dstLen;
		int32_t limit = src->limit();
		src->limit(limit - diff);
		dst->put(src);
		src->limit(limit);
	} else {
		dst->put(src);
	}
	return srcLen - src->remaining();
}

int64_t Utils::accumulateBuffers($List* currentList, $List* buffersToAdd) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	int64_t accumulatedBytes = 0;
	{
		$var($Iterator, i$, $nc(buffersToAdd)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ByteBuffer, bufferToAdd, $cast($ByteBuffer, i$->next()));
			{
				int32_t remaining = $nc(bufferToAdd)->remaining();
				if (remaining <= 0) {
					continue;
				}
				int32_t listSize = $nc(currentList)->size();
				if (listSize == 0) {
					currentList->add(bufferToAdd);
					accumulatedBytes = remaining;
					continue;
				}
				$var($ByteBuffer, lastBuffer, $cast($ByteBuffer, currentList->get(listSize - 1)));
				int32_t var$0 = $nc(lastBuffer)->capacity();
				int32_t freeSpace = var$0 - lastBuffer->limit();
				if (remaining <= Utils::COPY_THRESHOLD && freeSpace >= remaining) {
					int32_t position = lastBuffer->position();
					int32_t limit = lastBuffer->limit();
					lastBuffer->position(limit);
					lastBuffer->limit(limit + remaining);
					lastBuffer->put(bufferToAdd);
					lastBuffer->position(position);
				} else {
					currentList->add(bufferToAdd);
				}
				accumulatedBytes += remaining;
			}
		}
	}
	return accumulatedBytes;
}

$ByteBuffer* Utils::copy($ByteBuffer* src) {
	$init(Utils);
	$var($ByteBuffer, dst, $ByteBuffer::allocate($nc(src)->remaining()));
	$nc(dst)->put(src);
	dst->flip();
	return dst;
}

$ByteBuffer* Utils::copyAligned($ByteBuffer* src) {
	$init(Utils);
	int32_t len = $nc(src)->remaining();
	int32_t size = ((len + 7) >> 3) << 3;
	if (!Utils::$assertionsDisabled && !(size >= len)) {
		$throwNew($AssertionError);
	}
	$var($ByteBuffer, dst, $ByteBuffer::allocate(size));
	$nc(dst)->put(src);
	dst->flip();
	return dst;
}

$String* Utils::dump($ObjectArray* objects) {
	$init(Utils);
	return $Arrays::toString(objects);
}

$String* Utils::stringOf($Collection* source) {
	$init(Utils);
	return $Arrays::toString($($nc(source)->toArray()));
}

int64_t Utils::remaining($ByteBufferArray* bufs) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	int64_t remain = 0;
	{
		$var($ByteBufferArray, arr$, bufs);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($ByteBuffer, buf, arr$->get(i$));
			{
				remain += $nc(buf)->remaining();
			}
		}
	}
	return remain;
}

bool Utils::hasRemaining($List* bufs) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	{
		$var($Iterator, i$, $nc(bufs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ByteBuffer, buf, $cast($ByteBuffer, i$->next()));
			{
				if ($nc(buf)->hasRemaining()) {
					return true;
				}
			}
		}
	}
	return false;
}

int64_t Utils::remaining($List* bufs) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	int64_t remain = 0;
	{
		$var($Iterator, i$, $nc(bufs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ByteBuffer, buf, $cast($ByteBuffer, i$->next()));
			{
				remain += $nc(buf)->remaining();
			}
		}
	}
	return remain;
}

int64_t Utils::synchronizedRemaining($List* bufs) {
	$init(Utils);
	$synchronized(bufs) {
		return remaining(bufs);
	}
}

int32_t Utils::remaining($List* bufs, int32_t max) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	int64_t remain = 0;
	{
		$var($Iterator, i$, $nc(bufs)->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($ByteBuffer, buf, $cast($ByteBuffer, i$->next()));
			{
				remain += $nc(buf)->remaining();
				if (remain > max) {
					$throwNew($IllegalArgumentException, "too many bytes"_s);
				}
			}
		}
	}
	return (int32_t)remain;
}

int32_t Utils::remaining($ByteBufferArray* refs, int32_t max) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	int64_t remain = 0;
	{
		$var($ByteBufferArray, arr$, refs);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($ByteBuffer, b, arr$->get(i$));
			{
				remain += $nc(b)->remaining();
				if (remain > max) {
					$throwNew($IllegalArgumentException, "too many bytes"_s);
				}
			}
		}
	}
	return (int32_t)remain;
}

void Utils::close($CloseableArray* closeables) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	{
		$var($CloseableArray, arr$, closeables);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($Closeable, c, arr$->get(i$));
			{
				try {
					$nc(c)->close();
				} catch ($IOException& ignored) {
				}
			}
		}
	}
}

$ByteBuffer* Utils::sliceWithLimitedCapacity($ByteBuffer* buffer, int32_t amount) {
	$init(Utils);
	int32_t index = $nc(buffer)->position() + amount;
	int32_t limit = buffer->limit();
	if (index != limit) {
		buffer->limit(index);
	} else {
		buffer->limit(buffer->capacity());
	}
	$var($ByteBuffer, newb, buffer->slice());
	buffer->position(index);
	buffer->limit(limit);
	$nc(newb)->limit(amount);
	return newb;
}

$Charset* Utils::charsetFrom($HttpHeaders* headers) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$var($String, type, $cast($String, $nc($($nc(headers)->firstValue("Content-type"_s)))->orElse("text/html; charset=utf-8"_s)));
	int32_t i = $nc(type)->indexOf(";"_s);
	if (i >= 0) {
		$assign(type, type->substring(i + 1));
	}
	try {
		$var($HeaderParser, parser, $new($HeaderParser, type));
		$var($String, value, parser->findValue("charset"_s));
		if (value == nullptr) {
			$init($StandardCharsets);
			return $StandardCharsets::UTF_8;
		}
		return $Charset::forName(value);
	} catch ($Throwable& x) {
		$Log::logTrace("Can\'t find charset in \"{0}\" ({1})"_s, $$new($ObjectArray, {
			$of(type),
			$of(x)
		}));
		$init($StandardCharsets);
		return $StandardCharsets::UTF_8;
	}
	$shouldNotReachHere();
}

$UncheckedIOException* Utils::unchecked($IOException* e) {
	$init(Utils);
	return $new($UncheckedIOException, e);
}

$Logger* Utils::getDebugLogger($Supplier* dbgTag) {
	$init(Utils);
	return getDebugLogger(dbgTag, Utils::DEBUG);
}

$Logger* Utils::getDebugLogger($Supplier* dbgTag, $System$Logger$Level* errLevel) {
	$init(Utils);
	$init($System$Logger$Level);
	return $DebugLogger::createHttpLogger(dbgTag, $System$Logger$Level::OFF, errLevel);
}

$Logger* Utils::getDebugLogger($Supplier* dbgTag, bool on) {
	$init(Utils);
	$init($System$Logger$Level);
	$System$Logger$Level* errLevel = on ? $System$Logger$Level::ALL : $System$Logger$Level::OFF;
	return getDebugLogger(dbgTag, errLevel);
}

$String* Utils::hostString($HttpRequestImpl* request) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$var($URI, uri, $nc(request)->uri());
	int32_t port = $nc(uri)->getPort();
	$var($String, host, uri->getHost());
	bool defaultPort = false;
	if (port == -1) {
		defaultPort = true;
	} else if ($nc($(uri->getScheme()))->equalsIgnoreCase("https"_s)) {
		defaultPort = port == 443;
	} else {
		defaultPort = port == 80;
	}
	if (defaultPort) {
		return host;
	} else {
		return $str({host, ":"_s, $($Integer::toString(port))});
	}
}

$Logger* Utils::getHpackLogger($Supplier* dbgTag, $System$Logger$Level* errLevel) {
	$init(Utils);
	$init($System$Logger$Level);
	$System$Logger$Level* outLevel = $System$Logger$Level::OFF;
	return $DebugLogger::createHpackLogger(dbgTag, outLevel, errLevel);
}

$Logger* Utils::getHpackLogger($Supplier* dbgTag, bool on) {
	$init(Utils);
	$init($System$Logger$Level);
	$System$Logger$Level* errLevel = on ? $System$Logger$Level::ALL : $System$Logger$Level::OFF;
	return getHpackLogger(dbgTag, errLevel);
}

$Logger* Utils::getWebSocketLogger($Supplier* dbgTag, $System$Logger$Level* errLevel) {
	$init(Utils);
	$init($System$Logger$Level);
	$System$Logger$Level* outLevel = $System$Logger$Level::OFF;
	return $DebugLogger::createWebSocketLogger(dbgTag, outLevel, errLevel);
}

$Logger* Utils::getWebSocketLogger($Supplier* dbgTag, bool on) {
	$init(Utils);
	$init($System$Logger$Level);
	$System$Logger$Level* errLevel = on ? $System$Logger$Level::ALL : $System$Logger$Level::OFF;
	return getWebSocketLogger(dbgTag, errLevel);
}

$SSLSession* Utils::immutableSession($SSLSession* session) {
	$init(Utils);
	if ($instanceOf($ExtendedSSLSession, session)) {
		return $new($ImmutableExtendedSSLSession, $cast($ExtendedSSLSession, session));
	} else {
		return $new($ImmutableSSLSession, session);
	}
}

bool Utils::isHostnameVerificationDisabled() {
	$init(Utils);
	return Utils::isHostnameVerificationDisabled$;
}

$InetSocketAddress* Utils::resolveAddress($InetSocketAddress* address$renamed) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$var($InetSocketAddress, address, address$renamed);
	if (address != nullptr && address->isUnresolved()) {
		$var($String, var$0, address->getHostString());
		$assign(address, $new($InetSocketAddress, var$0, address->getPort()));
	}
	return address;
}

$Throwable* Utils::toConnectException($Throwable* e$renamed) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	$var($Throwable, e, e$renamed);
	if (e == nullptr) {
		return nullptr;
	}
	$assign(e, getCompletionCause(e));
	if ($instanceOf($ConnectException, e)) {
		return e;
	}
	if ($instanceOf($SecurityException, e)) {
		return e;
	}
	if ($instanceOf($SSLException, e)) {
		return e;
	}
	if ($instanceOf($Error, e)) {
		return e;
	}
	if ($instanceOf($HttpTimeoutException, e)) {
		return e;
	}
	$var($Throwable, cause, e);
	$assign(e, $new($ConnectException, $($nc(e)->getMessage())));
	e->initCause(cause);
	return e;
}

int32_t Utils::pow2Size(int32_t n) {
	$init(Utils);
	if (n < 0) {
		$throwNew($IllegalArgumentException);
	} else if (n == 0) {
		return 1;
	} else if (n >= (1 << 30)) {
		return 1 << 30;
	} else {
		return $sl(1, 32 - $Integer::numberOfLeadingZeros(n - 1));
	}
}

$String* Utils::encode($String* s) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	int32_t n = $nc(s)->length();
	if (n == 0) {
		return s;
	}
	for (int32_t i = 0;;) {
		if (s->charAt(i) >= (char16_t)0x80) {
			break;
		}
		if (++i >= n) {
			return s;
		}
	}
	$init($Normalizer$Form);
	$var($String, ns, $Normalizer::normalize(s, $Normalizer$Form::NFC));
	$var($ByteBuffer, bb, nullptr);
	try {
		$init($StandardCharsets);
		$init($CodingErrorAction);
		$assign(bb, $nc($($nc($($nc($($nc($StandardCharsets::UTF_8)->newEncoder()))->onMalformedInput($CodingErrorAction::REPORT)))->onUnmappableCharacter($CodingErrorAction::REPORT)))->encode($($CharBuffer::wrap(static_cast<$CharSequence*>(ns)))));
	} catch ($CharacterCodingException& x) {
		if (!Utils::$assertionsDisabled) {
			$throwNew($AssertionError, $of(x));
		}
	}
	$var($HexFormat, format, $nc($($HexFormat::of()))->withUpperCase());
	$var($StringBuilder, sb, $new($StringBuilder));
	while ($nc(bb)->hasRemaining()) {
		int32_t b = (int32_t)(bb->get() & (uint32_t)255);
		if (b >= 128) {
			sb->append(u'%');
			$nc(format)->toHexDigits(static_cast<$Appendable*>(sb), (int8_t)b);
		} else {
			sb->append((char16_t)b);
		}
	}
	return sb->toString();
}

$Integer* Utils::lambda$getIntegerProperty$17($String* name, int32_t defaultValue) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	return $Integer::valueOf($Integer::parseInt($($System::getProperty(name, $($String::valueOf(defaultValue))))));
}

$String* Utils::lambda$getProperty$16($String* name) {
	$init(Utils);
	return $System::getProperty(name);
}

$Boolean* Utils::lambda$getBooleanProperty$15($String* name, bool def) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	return $Boolean::valueOf($Boolean::parseBoolean($($System::getProperty(name, $($String::valueOf(def))))));
}

$String* Utils::lambda$getNetProperty$14($String* name) {
	$init(Utils);
	return $NetProperties::get(name);
}

$Integer* Utils::lambda$getIntegerNetProperty$13($String* name, int32_t defaultValue) {
	$init(Utils);
	return $NetProperties::getInteger(name, defaultValue);
}

bool Utils::lambda$static$12($String* n, $String* v) {
	$init(Utils);
	return $nc(Utils::NO_PROXY_HEADER)->test(n);
}

bool Utils::lambda$static$11($String* s, $String* v) {
	$init(Utils);
	return isAllowedForProxy(s, v, Utils::PROXY_AUTH_DISABLED_SCHEMES, Utils::ALL_HEADERS);
}

bool Utils::lambda$static$10($String* s, $String* v) {
	$init(Utils);
	return isAllowedForProxy(s, v, Utils::PROXY_AUTH_TUNNEL_DISABLED_SCHEMES, $($nc(Utils::IS_PROXY_HEADER)->or$(Utils::IS_HOST)));
}

$CompletableFuture* Utils::lambda$wrapForDebug$9($Logger* logger, $String* name, $CompletableFuture* cf, Object$* r, $Throwable* t) {
	$init(Utils);
	$nc(logger)->log("%s completed %s"_s, $$new($ObjectArray, {
		$of(name),
		t == nullptr ? $of("successfully"_s) : $of(t)
	}));
	return cf;
}

bool Utils::lambda$static$7($String* s) {
	$init(Utils);
	return !$nc(s)->isEmpty();
}

bool Utils::lambda$static$6($String* s) {
	$init(Utils);
	return true;
}

bool Utils::lambda$static$5($String* k) {
	$init(Utils);
	bool var$0 = k != nullptr && k->length() > 6;
	return var$0 && "proxy-"_s->equalsIgnoreCase($(k->substring(0, 6)));
}

bool Utils::lambda$static$4($String* k, $String* v) {
	$init(Utils);
	return !"host"_s->equalsIgnoreCase(k);
}

bool Utils::lambda$CONTEXT_RESTRICTED$3($HttpClient* client, $String* k, $String* v) {
	$init(Utils);
	bool var$0 = !$nc($($nc(client)->authenticator()))->isPresent();
	if (!var$0) {
		bool var$1 = !$nc(k)->equalsIgnoreCase("Authorization"_s);
		var$0 = (var$1 && !k->equalsIgnoreCase("Proxy-Authorization"_s));
	}
	return var$0;
}

bool Utils::lambda$static$2($String* name, $String* value) {
	$init(Utils);
	$useLocalCurrentObjectStackCache();
	if (!Utils::$assertionsDisabled && !(name != nullptr)) {
		$throwNew($AssertionError, $of("null header name"_s));
	}
	if (!Utils::$assertionsDisabled && !(value != nullptr)) {
		$throwNew($AssertionError, $of("null header value"_s));
	}
	if (!isValidName(name)) {
		$throw($(newIAE("invalid header name: \"%s\""_s, $$new($ObjectArray, {$of(name)}))));
	}
	if (!$nc(Utils::ALLOWED_HEADERS)->test(name, nullptr)) {
		$throw($(newIAE("restricted header name: \"%s\""_s, $$new($ObjectArray, {$of(name)}))));
	}
	if (!isValidValue(value)) {
		$throw($(newIAE("invalid header value for %s: \"%s\""_s, $$new($ObjectArray, {
			$of(name),
			$of(value)
		}))));
	}
	return true;
}

bool Utils::lambda$static$1($String* header, $String* unused) {
	$init(Utils);
	return !$nc(Utils::DISALLOWED_HEADERS_SET)->contains(header);
}

bool Utils::lambda$static$0($String* x, $String* y) {
	$init(Utils);
	return true;
}

void clinit$Utils($Class* class$) {
	$useLocalCurrentObjectStackCache();
	$assignStatic(Utils::WSPACES, " \t\r\n"_s);
	$assignStatic(Utils::HEADER_CONNECTION, "Connection"_s);
	$assignStatic(Utils::HEADER_UPGRADE, "Upgrade"_s);
	Utils::$assertionsDisabled = !Utils::class$->desiredAssertionStatus();
	{
		bool enabled = false;
		if (!Utils::$assertionsDisabled && !(enabled = true)) {
			$throwNew($AssertionError);
		}
		Utils::ASSERTIONSENABLED = enabled;
	}
	$init($DebugLogger);
	Utils::DEBUG = Utils::getBooleanProperty($DebugLogger::HTTP_NAME, false);
	Utils::DEBUG_WS = Utils::getBooleanProperty($DebugLogger::WS_NAME, false);
	Utils::DEBUG_HPACK = Utils::getBooleanProperty($DebugLogger::HPACK_NAME, false);
	Utils::TESTING = Utils::DEBUG;
	Utils::isHostnameVerificationDisabled$ = Utils::hostnameVerificationDisabledValue();
	Utils::BUFSIZE = Utils::getIntegerNetProperty("jdk.httpclient.bufsize"_s, Utils::DEFAULT_BUFSIZE);
	$assignStatic(Utils::ACCEPT_ALL, static_cast<$BiPredicate*>($new(Utils$$Lambda$lambda$static$0)));
	$assignStatic(Utils::DISALLOWED_HEADERS_SET, Utils::getDisallowedHeaders());
	$assignStatic(Utils::ALLOWED_HEADERS, static_cast<$BiPredicate*>($new(Utils$$Lambda$lambda$static$1$1)));
	$assignStatic(Utils::VALIDATE_USER_HEADER, static_cast<$BiPredicate*>($new(Utils$$Lambda$lambda$static$2$2)));
	$assignStatic(Utils::HOST_RESTRICTED, static_cast<$BiPredicate*>($new(Utils$$Lambda$lambda$static$4$3)));
	$assignStatic(Utils::IS_HOST, static_cast<$Predicate*>($new(Utils$$Lambda$equalsIgnoreCase$4, static_cast<$String*>("host"_s))));
	$assignStatic(Utils::IS_PROXY_HEADER, static_cast<$Predicate*>($new(Utils$$Lambda$lambda$static$5$5)));
	$assignStatic(Utils::NO_PROXY_HEADER, $nc(Utils::IS_PROXY_HEADER)->negate());
	$assignStatic(Utils::ALL_HEADERS, static_cast<$Predicate*>($new(Utils$$Lambda$lambda$static$6$6)));
	{
		$var($String, proxyAuthDisabled, Utils::getNetProperty("jdk.http.auth.proxying.disabledSchemes"_s));
		$var($String, proxyAuthTunnelDisabled, Utils::getNetProperty("jdk.http.auth.tunneling.disabledSchemes"_s));
		$assignStatic(Utils::PROXY_AUTH_DISABLED_SCHEMES, proxyAuthDisabled == nullptr ? $Set::of() : $cast($Set, $nc($($nc($($nc($($Stream::of($($nc(proxyAuthDisabled)->split(","_s)))))->map(static_cast<$Function*>($$new(Utils$$Lambda$trim$17)))))->filter(static_cast<$Predicate*>($$new(Utils$$Lambda$lambda$static$7$18)))))->collect($($Collectors::toUnmodifiableSet()))));
		$assignStatic(Utils::PROXY_AUTH_TUNNEL_DISABLED_SCHEMES, proxyAuthTunnelDisabled == nullptr ? $Set::of() : $cast($Set, $nc($($nc($($nc($($Stream::of($($nc(proxyAuthTunnelDisabled)->split(","_s)))))->map(static_cast<$Function*>($$new(Utils$$Lambda$trim$17)))))->filter(static_cast<$Predicate*>($$new(Utils$$Lambda$lambda$static$7$18)))))->collect($($Collectors::toUnmodifiableSet()))));
	}
	$assignStatic(Utils::PROXY_TUNNEL_FILTER, static_cast<$BiPredicate*>($new(Utils$$Lambda$lambda$static$10$7)));
	$assignStatic(Utils::PROXY_FILTER, static_cast<$BiPredicate*>($new(Utils$$Lambda$lambda$static$11$8)));
	$assignStatic(Utils::NO_PROXY_HEADERS_FILTER, static_cast<$BiPredicate*>($new(Utils$$Lambda$lambda$static$12$9)));
	$assignStatic(Utils::tchar, $new($booleans, 256));
	$assignStatic(Utils::fieldvchar, $new($booleans, 256));
	{
		$var($chars, allowedTokenChars, ("!#$%&\'*+-.^_`|~0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"_s)->toCharArray());
		{
			$var($chars, arr$, allowedTokenChars);
			int32_t len$ = arr$->length;
			int32_t i$ = 0;
			for (; i$ < len$; ++i$) {
				char16_t c = arr$->get(i$);
				{
					$nc(Utils::tchar)->set(c, true);
				}
			}
		}
		for (char16_t c = (char16_t)33; c <= 255; ++c) {
			$nc(Utils::fieldvchar)->set(c, true);
		}
		$nc(Utils::fieldvchar)->set(127, false);
	}
	$assignStatic(Utils::EMPTY_BYTEBUFFER, $ByteBuffer::allocate(0));
	$assignStatic(Utils::EMPTY_BB_ARRAY, $new($ByteBufferArray, 0));
	$assignStatic(Utils::EMPTY_BB_LIST, $List::of());
}

Utils::Utils() {
}

$Class* Utils::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Utils$$Lambda$lambda$static$0::classInfo$.name)) {
			return Utils$$Lambda$lambda$static$0::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$static$1$1::classInfo$.name)) {
			return Utils$$Lambda$lambda$static$1$1::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$static$2$2::classInfo$.name)) {
			return Utils$$Lambda$lambda$static$2$2::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$static$4$3::classInfo$.name)) {
			return Utils$$Lambda$lambda$static$4$3::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$equalsIgnoreCase$4::classInfo$.name)) {
			return Utils$$Lambda$equalsIgnoreCase$4::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$static$5$5::classInfo$.name)) {
			return Utils$$Lambda$lambda$static$5$5::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$static$6$6::classInfo$.name)) {
			return Utils$$Lambda$lambda$static$6$6::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$static$10$7::classInfo$.name)) {
			return Utils$$Lambda$lambda$static$10$7::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$static$11$8::classInfo$.name)) {
			return Utils$$Lambda$lambda$static$11$8::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$static$12$9::classInfo$.name)) {
			return Utils$$Lambda$lambda$static$12$9::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10::classInfo$.name)) {
			return Utils$$Lambda$lambda$CONTEXT_RESTRICTED$3$10::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$wrapForDebug$9$11::classInfo$.name)) {
			return Utils$$Lambda$lambda$wrapForDebug$9$11::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$getIntegerNetProperty$13$12::classInfo$.name)) {
			return Utils$$Lambda$lambda$getIntegerNetProperty$13$12::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$getNetProperty$14$13::classInfo$.name)) {
			return Utils$$Lambda$lambda$getNetProperty$14$13::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$getBooleanProperty$15$14::classInfo$.name)) {
			return Utils$$Lambda$lambda$getBooleanProperty$15$14::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$getProperty$16$15::classInfo$.name)) {
			return Utils$$Lambda$lambda$getProperty$16$15::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$getIntegerProperty$17$16::classInfo$.name)) {
			return Utils$$Lambda$lambda$getIntegerProperty$17$16::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$trim$17::classInfo$.name)) {
			return Utils$$Lambda$trim$17::load$(name, initialize);
		}
		if (name->equals(Utils$$Lambda$lambda$static$7$18::classInfo$.name)) {
			return Utils$$Lambda$lambda$static$7$18::load$(name, initialize);
		}
	}
	$loadClass(Utils, name, initialize, &_Utils_ClassInfo_, clinit$Utils, allocate$Utils);
	return class$;
}

$Class* Utils::class$ = nullptr;

				} // common
			} // http
		} // net
	} // internal
} // jdk