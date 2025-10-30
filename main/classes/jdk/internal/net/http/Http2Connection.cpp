#include <jdk/internal/net/http/Http2Connection.h>

#include <java/io/EOFException.h>
#include <java/io/IOException.h>
#include <java/io/Serializable.h>
#include <java/io/UncheckedIOException.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/Math.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/InetSocketAddress.h>
#include <java/net/SocketAddress.h>
#include <java/net/URI.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpHeaders.h>
#include <java/nio/ByteBuffer.h>
#include <java/nio/channels/SocketChannel.h>
#include <java/nio/channels/spi/AbstractInterruptibleChannel.h>
#include <java/nio/charset/Charset.h>
#include <java/nio/charset/StandardCharsets.h>
#include <java/util/AbstractList.h>
#include <java/util/ArrayList.h>
#include <java/util/Collection.h>
#include <java/util/Iterator.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map$Entry.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/Set.h>
#include <java/util/concurrent/CompletableFuture.h>
#include <java/util/concurrent/CompletionStage.h>
#include <java/util/concurrent/ConcurrentHashMap.h>
#include <java/util/concurrent/ConcurrentMap.h>
#include <java/util/function/BiConsumer.h>
#include <java/util/function/Consumer.h>
#include <java/util/function/Function.h>
#include <java/util/function/Supplier.h>
#include <javax/net/ssl/SSLEngine.h>
#include <javax/net/ssl/SSLException.h>
#include <jdk/internal/net/http/AbstractAsyncSSLConnection.h>
#include <jdk/internal/net/http/Exchange$ConnectionAborter.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/ExchangeImpl.h>
#include <jdk/internal/net/http/Http2ClientImpl.h>
#include <jdk/internal/net/http/Http2Connection$ALPNException.h>
#include <jdk/internal/net/http/Http2Connection$ConnectionWindowUpdateSender.h>
#include <jdk/internal/net/http/Http2Connection$FramesController.h>
#include <jdk/internal/net/http/Http2Connection$HeaderDecoder.h>
#include <jdk/internal/net/http/Http2Connection$Http2TubeSubscriber.h>
#include <jdk/internal/net/http/Http2Connection$ValidatingHeadersConsumer.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpConnection$HttpPublisher.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/PushGroup.h>
#include <jdk/internal/net/http/Stream$PushedStream.h>
#include <jdk/internal/net/http/Stream.h>
#include <jdk/internal/net/http/WindowController.h>
#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture$ExceptionalSupplier.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/frame/ContinuationFrame.h>
#include <jdk/internal/net/http/frame/DataFrame.h>
#include <jdk/internal/net/http/frame/ErrorFrame.h>
#include <jdk/internal/net/http/frame/FramesDecoder$FrameProcessor.h>
#include <jdk/internal/net/http/frame/FramesDecoder.h>
#include <jdk/internal/net/http/frame/FramesEncoder.h>
#include <jdk/internal/net/http/frame/GoAwayFrame.h>
#include <jdk/internal/net/http/frame/HeaderFrame.h>
#include <jdk/internal/net/http/frame/HeadersFrame.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jdk/internal/net/http/frame/MalformedFrame.h>
#include <jdk/internal/net/http/frame/OutgoingHeaders.h>
#include <jdk/internal/net/http/frame/PingFrame.h>
#include <jdk/internal/net/http/frame/PushPromiseFrame.h>
#include <jdk/internal/net/http/frame/ResetFrame.h>
#include <jdk/internal/net/http/frame/SettingsFrame.h>
#include <jdk/internal/net/http/frame/WindowUpdateFrame.h>
#include <jdk/internal/net/http/hpack/Decoder.h>
#include <jdk/internal/net/http/hpack/DecodingCallback.h>
#include <jdk/internal/net/http/hpack/Encoder.h>
#include <jcpp.h>

#undef ACK
#undef BUFFER
#undef CLIENT_PREFACE
#undef DEBUG
#undef DEBUG_HPACK
#undef DEBUG_LOGGER
#undef DEFAULT_FRAME_SIZE
#undef EMPTY_TRIGGER
#undef END_HEADERS
#undef FLOW_CONTROL_ERROR
#undef HTTP_2
#undef MAX_CLIENT_STREAM_ID
#undef MAX_FRAME_SIZE
#undef MAX_SERVER_STREAM_ID
#undef NO_ERROR
#undef PREFACE_BYTES
#undef PROTOCOL_ERROR
#undef REFUSED_STREAM
#undef TYPE
#undef US
#undef UTF_8

using $HttpHeadersArray = $Array<::java::net::http::HttpHeaders>;
using $EOFException = ::java::io::EOFException;
using $IOException = ::java::io::IOException;
using $Serializable = ::java::io::Serializable;
using $UncheckedIOException = ::java::io::UncheckedIOException;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $Iterable = ::java::lang::Iterable;
using $Long = ::java::lang::Long;
using $Math = ::java::lang::Math;
using $MethodInfo = ::java::lang::MethodInfo;
using $RuntimeException = ::java::lang::RuntimeException;
using $Void = ::java::lang::Void;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $InetSocketAddress = ::java::net::InetSocketAddress;
using $SocketAddress = ::java::net::SocketAddress;
using $URI = ::java::net::URI;
using $HttpClient$Version = ::java::net::http::HttpClient$Version;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $SocketChannel = ::java::nio::channels::SocketChannel;
using $AbstractInterruptibleChannel = ::java::nio::channels::spi::AbstractInterruptibleChannel;
using $Charset = ::java::nio::charset::Charset;
using $StandardCharsets = ::java::nio::charset::StandardCharsets;
using $AbstractList = ::java::util::AbstractList;
using $ArrayList = ::java::util::ArrayList;
using $Collection = ::java::util::Collection;
using $Iterator = ::java::util::Iterator;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Map$Entry = ::java::util::Map$Entry;
using $Objects = ::java::util::Objects;
using $Set = ::java::util::Set;
using $CompletableFuture = ::java::util::concurrent::CompletableFuture;
using $CompletionStage = ::java::util::concurrent::CompletionStage;
using $ConcurrentHashMap = ::java::util::concurrent::ConcurrentHashMap;
using $ConcurrentMap = ::java::util::concurrent::ConcurrentMap;
using $BiConsumer = ::java::util::function::BiConsumer;
using $Consumer = ::java::util::function::Consumer;
using $Function = ::java::util::function::Function;
using $Supplier = ::java::util::function::Supplier;
using $SSLEngine = ::javax::net::ssl::SSLEngine;
using $SSLException = ::javax::net::ssl::SSLException;
using $AbstractAsyncSSLConnection = ::jdk::internal::net::http::AbstractAsyncSSLConnection;
using $Exchange = ::jdk::internal::net::http::Exchange;
using $Exchange$ConnectionAborter = ::jdk::internal::net::http::Exchange$ConnectionAborter;
using $ExchangeImpl = ::jdk::internal::net::http::ExchangeImpl;
using $Http2ClientImpl = ::jdk::internal::net::http::Http2ClientImpl;
using $Http2Connection$ALPNException = ::jdk::internal::net::http::Http2Connection$ALPNException;
using $Http2Connection$ConnectionWindowUpdateSender = ::jdk::internal::net::http::Http2Connection$ConnectionWindowUpdateSender;
using $Http2Connection$FramesController = ::jdk::internal::net::http::Http2Connection$FramesController;
using $Http2Connection$HeaderDecoder = ::jdk::internal::net::http::Http2Connection$HeaderDecoder;
using $Http2Connection$Http2TubeSubscriber = ::jdk::internal::net::http::Http2Connection$Http2TubeSubscriber;
using $Http2Connection$ValidatingHeadersConsumer = ::jdk::internal::net::http::Http2Connection$ValidatingHeadersConsumer;
using $HttpClientImpl = ::jdk::internal::net::http::HttpClientImpl;
using $HttpConnection = ::jdk::internal::net::http::HttpConnection;
using $HttpConnection$HttpPublisher = ::jdk::internal::net::http::HttpConnection$HttpPublisher;
using $HttpRequestImpl = ::jdk::internal::net::http::HttpRequestImpl;
using $MultiExchange = ::jdk::internal::net::http::MultiExchange;
using $PushGroup = ::jdk::internal::net::http::PushGroup;
using $Stream = ::jdk::internal::net::http::Stream;
using $Stream$PushedStream = ::jdk::internal::net::http::Stream$PushedStream;
using $WindowController = ::jdk::internal::net::http::WindowController;
using $WindowUpdateSender = ::jdk::internal::net::http::WindowUpdateSender;
using $FlowTube = ::jdk::internal::net::http::common::FlowTube;
using $FlowTube$TubePublisher = ::jdk::internal::net::http::common::FlowTube$TubePublisher;
using $FlowTube$TubeSubscriber = ::jdk::internal::net::http::common::FlowTube$TubeSubscriber;
using $Log = ::jdk::internal::net::http::common::Log;
using $Logger = ::jdk::internal::net::http::common::Logger;
using $MinimalFuture = ::jdk::internal::net::http::common::MinimalFuture;
using $MinimalFuture$ExceptionalSupplier = ::jdk::internal::net::http::common::MinimalFuture$ExceptionalSupplier;
using $Utils = ::jdk::internal::net::http::common::Utils;
using $ContinuationFrame = ::jdk::internal::net::http::frame::ContinuationFrame;
using $DataFrame = ::jdk::internal::net::http::frame::DataFrame;
using $ErrorFrame = ::jdk::internal::net::http::frame::ErrorFrame;
using $FramesDecoder = ::jdk::internal::net::http::frame::FramesDecoder;
using $FramesDecoder$FrameProcessor = ::jdk::internal::net::http::frame::FramesDecoder$FrameProcessor;
using $FramesEncoder = ::jdk::internal::net::http::frame::FramesEncoder;
using $GoAwayFrame = ::jdk::internal::net::http::frame::GoAwayFrame;
using $HeaderFrame = ::jdk::internal::net::http::frame::HeaderFrame;
using $HeadersFrame = ::jdk::internal::net::http::frame::HeadersFrame;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;
using $MalformedFrame = ::jdk::internal::net::http::frame::MalformedFrame;
using $OutgoingHeaders = ::jdk::internal::net::http::frame::OutgoingHeaders;
using $PingFrame = ::jdk::internal::net::http::frame::PingFrame;
using $PushPromiseFrame = ::jdk::internal::net::http::frame::PushPromiseFrame;
using $ResetFrame = ::jdk::internal::net::http::frame::ResetFrame;
using $SettingsFrame = ::jdk::internal::net::http::frame::SettingsFrame;
using $WindowUpdateFrame = ::jdk::internal::net::http::frame::WindowUpdateFrame;
using $Decoder = ::jdk::internal::net::http::hpack::Decoder;
using $DecodingCallback = ::jdk::internal::net::http::hpack::DecodingCallback;
using $Encoder = ::jdk::internal::net::http::hpack::Encoder;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http2Connection$$Lambda$dbgString : public $Supplier {
	$class(Http2Connection$$Lambda$dbgString, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Http2Connection* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->dbgString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$dbgString>());
	}
	Http2Connection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$dbgString::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$dbgString, inst$)},
	{}
};
$MethodInfo Http2Connection$$Lambda$dbgString::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http2Connection;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$dbgString::*)(Http2Connection*)>(&Http2Connection$$Lambda$dbgString::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$dbgString::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$dbgString",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$dbgString::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$dbgString, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$dbgString::class$ = nullptr;

class Http2Connection$$Lambda$toString$1 : public $Supplier {
	$class(Http2Connection$$Lambda$toString$1, $NO_CLASS_INIT, $Supplier)
public:
	void init$($String* inst) {
		$set(this, inst$, inst);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->toString());
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$toString$1>());
	}
	$String* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$toString$1::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$toString$1, inst$)},
	{}
};
$MethodInfo Http2Connection$$Lambda$toString$1::methodInfos[3] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$toString$1::*)($String*)>(&Http2Connection$$Lambda$toString$1::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$toString$1::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$toString$1",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$toString$1::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$toString$1, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$toString$1::class$ = nullptr;

class Http2Connection$$Lambda$processFrame$2 : public $FramesDecoder$FrameProcessor {
	$class(Http2Connection$$Lambda$processFrame$2, $NO_CLASS_INIT, $FramesDecoder$FrameProcessor)
public:
	void init$(Http2Connection* inst) {
		$set(this, inst$, inst);
	}
	virtual void processFrame($Http2Frame* frame) override {
		$nc(inst$)->processFrame(frame);
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$processFrame$2>());
	}
	Http2Connection* inst$ = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$processFrame$2::fieldInfos[2] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$processFrame$2, inst$)},
	{}
};
$MethodInfo Http2Connection$$Lambda$processFrame$2::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http2Connection;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$processFrame$2::*)(Http2Connection*)>(&Http2Connection$$Lambda$processFrame$2::init$))},
	{"processFrame", "(Ljdk/internal/net/http/frame/Http2Frame;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$processFrame$2::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$processFrame$2",
	"java.lang.Object",
	"jdk.internal.net.http.frame.FramesDecoder$FrameProcessor",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$processFrame$2::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$processFrame$2, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$processFrame$2::class$ = nullptr;

class Http2Connection$$Lambda$lambda$createAsync$0$3 : public $MinimalFuture$ExceptionalSupplier {
	$class(Http2Connection$$Lambda$lambda$createAsync$0$3, $NO_CLASS_INIT, $MinimalFuture$ExceptionalSupplier)
public:
	void init$($HttpConnection* connection, $Http2ClientImpl* client2, $Exchange* exchange, $Supplier* initial) {
		$set(this, connection, connection);
		$set(this, client2, client2);
		$set(this, exchange, exchange);
		$set(this, initial, initial);
	}
	virtual $Object* get() override {
		 return $of(Http2Connection::lambda$createAsync$0(connection, client2, exchange, initial));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$lambda$createAsync$0$3>());
	}
	$HttpConnection* connection = nullptr;
	$Http2ClientImpl* client2 = nullptr;
	$Exchange* exchange = nullptr;
	$Supplier* initial = nullptr;
	static $FieldInfo fieldInfos[5];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$lambda$createAsync$0$3::fieldInfos[5] = {
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$createAsync$0$3, connection)},
	{"client2", "Ljdk/internal/net/http/Http2ClientImpl;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$createAsync$0$3, client2)},
	{"exchange", "Ljdk/internal/net/http/Exchange;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$createAsync$0$3, exchange)},
	{"initial", "Ljava/util/function/Supplier;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$createAsync$0$3, initial)},
	{}
};
$MethodInfo Http2Connection$$Lambda$lambda$createAsync$0$3::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/Exchange;Ljava/util/function/Supplier;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$lambda$createAsync$0$3::*)($HttpConnection*,$Http2ClientImpl*,$Exchange*,$Supplier*)>(&Http2Connection$$Lambda$lambda$createAsync$0$3::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$lambda$createAsync$0$3::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$lambda$createAsync$0$3",
	"java.lang.Object",
	"jdk.internal.net.http.common.MinimalFuture$ExceptionalSupplier",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$lambda$createAsync$0$3::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$lambda$createAsync$0$3, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$lambda$createAsync$0$3::class$ = nullptr;

class Http2Connection$$Lambda$lambda$createAsync$1$4 : public $Function {
	$class(Http2Connection$$Lambda$lambda$createAsync$1$4, $NO_CLASS_INIT, $Function)
public:
	void init$($AbstractAsyncSSLConnection* connection) {
		$set(this, connection, connection);
	}
	virtual $Object* apply(Object$* unused) override {
		 return $of(Http2Connection::lambda$createAsync$1(connection, $cast($Void, unused)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$lambda$createAsync$1$4>());
	}
	$AbstractAsyncSSLConnection* connection = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$lambda$createAsync$1$4::fieldInfos[2] = {
	{"connection", "Ljdk/internal/net/http/AbstractAsyncSSLConnection;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$createAsync$1$4, connection)},
	{}
};
$MethodInfo Http2Connection$$Lambda$lambda$createAsync$1$4::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/AbstractAsyncSSLConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$lambda$createAsync$1$4::*)($AbstractAsyncSSLConnection*)>(&Http2Connection$$Lambda$lambda$createAsync$1$4::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$lambda$createAsync$1$4::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$lambda$createAsync$1$4",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$lambda$createAsync$1$4::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$lambda$createAsync$1$4, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$lambda$createAsync$1$4::class$ = nullptr;

class Http2Connection$$Lambda$lambda$createAsync$2$5 : public $Function {
	$class(Http2Connection$$Lambda$lambda$createAsync$2$5, $NO_CLASS_INIT, $Function)
public:
	void init$($AbstractAsyncSSLConnection* connection) {
		$set(this, connection, connection);
	}
	virtual $Object* apply(Object$* unused) override {
		 return $of(Http2Connection::lambda$createAsync$2(connection, $cast($Void, unused)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$lambda$createAsync$2$5>());
	}
	$AbstractAsyncSSLConnection* connection = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$lambda$createAsync$2$5::fieldInfos[2] = {
	{"connection", "Ljdk/internal/net/http/AbstractAsyncSSLConnection;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$createAsync$2$5, connection)},
	{}
};
$MethodInfo Http2Connection$$Lambda$lambda$createAsync$2$5::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/AbstractAsyncSSLConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$lambda$createAsync$2$5::*)($AbstractAsyncSSLConnection*)>(&Http2Connection$$Lambda$lambda$createAsync$2$5::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$lambda$createAsync$2$5::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$lambda$createAsync$2$5",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$lambda$createAsync$2$5::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$lambda$createAsync$2$5, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$lambda$createAsync$2$5::class$ = nullptr;

class Http2Connection$$Lambda$lambda$createAsync$3$6 : public $Function {
	$class(Http2Connection$$Lambda$lambda$createAsync$3$6, $NO_CLASS_INIT, $Function)
public:
	void init$($HttpRequestImpl* request, $Http2ClientImpl* h2client, $AbstractAsyncSSLConnection* connection) {
		$set(this, request, request);
		$set(this, h2client, h2client);
		$set(this, connection, connection);
	}
	virtual $Object* apply(Object$* notused) override {
		 return $of(Http2Connection::lambda$createAsync$3(request, h2client, connection, notused));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$lambda$createAsync$3$6>());
	}
	$HttpRequestImpl* request = nullptr;
	$Http2ClientImpl* h2client = nullptr;
	$AbstractAsyncSSLConnection* connection = nullptr;
	static $FieldInfo fieldInfos[4];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$lambda$createAsync$3$6::fieldInfos[4] = {
	{"request", "Ljdk/internal/net/http/HttpRequestImpl;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$createAsync$3$6, request)},
	{"h2client", "Ljdk/internal/net/http/Http2ClientImpl;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$createAsync$3$6, h2client)},
	{"connection", "Ljdk/internal/net/http/AbstractAsyncSSLConnection;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$createAsync$3$6, connection)},
	{}
};
$MethodInfo Http2Connection$$Lambda$lambda$createAsync$3$6::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/AbstractAsyncSSLConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$lambda$createAsync$3$6::*)($HttpRequestImpl*,$Http2ClientImpl*,$AbstractAsyncSSLConnection*)>(&Http2Connection$$Lambda$lambda$createAsync$3$6::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$lambda$createAsync$3$6::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$lambda$createAsync$3$6",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$lambda$createAsync$3$6::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$lambda$createAsync$3$6, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$lambda$createAsync$3$6::class$ = nullptr;

class Http2Connection$$Lambda$lambda$checkSSLConfig$4$7 : public $Function {
	$class(Http2Connection$$Lambda$lambda$checkSSLConfig$4$7, $NO_CLASS_INIT, $Function)
public:
	void init$($AbstractAsyncSSLConnection* aconn) {
		$set(this, aconn, aconn);
	}
	virtual $Object* apply(Object$* alpn) override {
		 return $of(Http2Connection::lambda$checkSSLConfig$4(aconn, $cast($String, alpn)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$lambda$checkSSLConfig$4$7>());
	}
	$AbstractAsyncSSLConnection* aconn = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$lambda$checkSSLConfig$4$7::fieldInfos[2] = {
	{"aconn", "Ljdk/internal/net/http/AbstractAsyncSSLConnection;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$checkSSLConfig$4$7, aconn)},
	{}
};
$MethodInfo Http2Connection$$Lambda$lambda$checkSSLConfig$4$7::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/AbstractAsyncSSLConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$lambda$checkSSLConfig$4$7::*)($AbstractAsyncSSLConnection*)>(&Http2Connection$$Lambda$lambda$checkSSLConfig$4$7::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$lambda$checkSSLConfig$4$7::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$lambda$checkSSLConfig$4$7",
	"java.lang.Object",
	"java.util.function.Function",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$lambda$checkSSLConfig$4$7::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$lambda$checkSSLConfig$4$7, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$lambda$checkSSLConfig$4$7::class$ = nullptr;

class Http2Connection$$Lambda$lambda$checkSSLConfig$5$8 : public $BiConsumer {
	$class(Http2Connection$$Lambda$lambda$checkSSLConfig$5$8, $NO_CLASS_INIT, $BiConsumer)
public:
	void init$($AbstractAsyncSSLConnection* aconn) {
		$set(this, aconn, aconn);
	}
	virtual void accept(Object$* r, Object$* t) override {
		Http2Connection::lambda$checkSSLConfig$5(aconn, $cast($String, r), $cast($Throwable, t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$lambda$checkSSLConfig$5$8>());
	}
	$AbstractAsyncSSLConnection* aconn = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$lambda$checkSSLConfig$5$8::fieldInfos[2] = {
	{"aconn", "Ljdk/internal/net/http/AbstractAsyncSSLConnection;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$checkSSLConfig$5$8, aconn)},
	{}
};
$MethodInfo Http2Connection$$Lambda$lambda$checkSSLConfig$5$8::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/AbstractAsyncSSLConnection;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$lambda$checkSSLConfig$5$8::*)($AbstractAsyncSSLConnection*)>(&Http2Connection$$Lambda$lambda$checkSSLConfig$5$8::init$))},
	{"accept", "(Ljava/lang/Object;Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$lambda$checkSSLConfig$5$8::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$lambda$checkSSLConfig$5$8",
	"java.lang.Object",
	"java.util.function.BiConsumer",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$lambda$checkSSLConfig$5$8::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$lambda$checkSSLConfig$5$8, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$lambda$checkSSLConfig$5$8::class$ = nullptr;

class Http2Connection$$Lambda$lambda$asyncReceive$6$9 : public $Supplier {
	$class(Http2Connection$$Lambda$lambda$asyncReceive$6$9, $NO_CLASS_INIT, $Supplier)
public:
	void init$(int64_t c, $ByteBuffer* b) {
		this->c = c;
		$set(this, b, b);
	}
	virtual $Object* get() override {
		 return $of(Http2Connection::lambda$asyncReceive$6(c, b));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$lambda$asyncReceive$6$9>());
	}
	int64_t c = 0;
	$ByteBuffer* b = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$lambda$asyncReceive$6$9::fieldInfos[3] = {
	{"c", "J", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$asyncReceive$6$9, c)},
	{"b", "Ljava/nio/ByteBuffer;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$asyncReceive$6$9, b)},
	{}
};
$MethodInfo Http2Connection$$Lambda$lambda$asyncReceive$6$9::methodInfos[3] = {
	{"<init>", "(JLjava/nio/ByteBuffer;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$lambda$asyncReceive$6$9::*)(int64_t,$ByteBuffer*)>(&Http2Connection$$Lambda$lambda$asyncReceive$6$9::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$lambda$asyncReceive$6$9::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$lambda$asyncReceive$6$9",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$lambda$asyncReceive$6$9::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$lambda$asyncReceive$6$9, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$lambda$asyncReceive$6$9::class$ = nullptr;

class Http2Connection$$Lambda$lambda$shutdown$7$10 : public $Supplier {
	$class(Http2Connection$$Lambda$lambda$shutdown$7$10, $NO_CLASS_INIT, $Supplier)
public:
	void init$(Http2Connection* inst, $Throwable* t) {
		$set(this, inst$, inst);
		$set(this, t, t);
	}
	virtual $Object* get() override {
		 return $of($nc(inst$)->lambda$shutdown$7(t));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$lambda$shutdown$7$10>());
	}
	Http2Connection* inst$ = nullptr;
	$Throwable* t = nullptr;
	static $FieldInfo fieldInfos[3];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$lambda$shutdown$7$10::fieldInfos[3] = {
	{"inst$", "Ljava/lang/Object;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$shutdown$7$10, inst$)},
	{"t", "Ljava/lang/Throwable;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$shutdown$7$10, t)},
	{}
};
$MethodInfo Http2Connection$$Lambda$lambda$shutdown$7$10::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/Http2Connection;Ljava/lang/Throwable;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$lambda$shutdown$7$10::*)(Http2Connection*,$Throwable*)>(&Http2Connection$$Lambda$lambda$shutdown$7$10::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$lambda$shutdown$7$10::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$lambda$shutdown$7$10",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$lambda$shutdown$7$10::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$lambda$shutdown$7$10, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$lambda$shutdown$7$10::class$ = nullptr;

class Http2Connection$$Lambda$lambda$processFrame$8$11 : public $Supplier {
	$class(Http2Connection$$Lambda$lambda$processFrame$8$11, $NO_CLASS_INIT, $Supplier)
public:
	void init$($Http2Frame* frame) {
		$set(this, frame, frame);
	}
	virtual $Object* get() override {
		 return $of(Http2Connection::lambda$processFrame$8(frame));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$lambda$processFrame$8$11>());
	}
	$Http2Frame* frame = nullptr;
	static $FieldInfo fieldInfos[2];
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$FieldInfo Http2Connection$$Lambda$lambda$processFrame$8$11::fieldInfos[2] = {
	{"frame", "Ljdk/internal/net/http/frame/Http2Frame;", nullptr, $PUBLIC, $field(Http2Connection$$Lambda$lambda$processFrame$8$11, frame)},
	{}
};
$MethodInfo Http2Connection$$Lambda$lambda$processFrame$8$11::methodInfos[3] = {
	{"<init>", "(Ljdk/internal/net/http/frame/Http2Frame;)V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$lambda$processFrame$8$11::*)($Http2Frame*)>(&Http2Connection$$Lambda$lambda$processFrame$8$11::init$))},
	{"get", "()Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$lambda$processFrame$8$11::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$lambda$processFrame$8$11",
	"java.lang.Object",
	"java.util.function.Supplier",
	fieldInfos,
	methodInfos
};
$Class* Http2Connection$$Lambda$lambda$processFrame$8$11::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$lambda$processFrame$8$11, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$lambda$processFrame$8$11::class$ = nullptr;

class Http2Connection$$Lambda$lambda$encodeFrames$9$12 : public $Consumer {
	$class(Http2Connection$$Lambda$lambda$encodeFrames$9$12, $NO_CLASS_INIT, $Consumer)
public:
	void init$() {
	}
	virtual void accept(Object$* f) override {
		Http2Connection::lambda$encodeFrames$9($cast($HeaderFrame, f));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http2Connection$$Lambda$lambda$encodeFrames$9$12>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Http2Connection$$Lambda$lambda$encodeFrames$9$12::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Http2Connection$$Lambda$lambda$encodeFrames$9$12::*)()>(&Http2Connection$$Lambda$lambda$encodeFrames$9$12::init$))},
	{"accept", "(Ljava/lang/Object;)V", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http2Connection$$Lambda$lambda$encodeFrames$9$12::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http2Connection$$Lambda$lambda$encodeFrames$9$12",
	"java.lang.Object",
	"java.util.function.Consumer",
	nullptr,
	methodInfos
};
$Class* Http2Connection$$Lambda$lambda$encodeFrames$9$12::load$($String* name, bool initialize) {
	$loadClass(Http2Connection$$Lambda$lambda$encodeFrames$9$12, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http2Connection$$Lambda$lambda$encodeFrames$9$12::class$ = nullptr;

$FieldInfo _Http2Connection_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http2Connection, $assertionsDisabled)},
	{"debug", "Ljdk/internal/net/http/common/Logger;", nullptr, $FINAL, $field(Http2Connection, debug)},
	{"DEBUG_LOGGER", "Ljdk/internal/net/http/common/Logger;", nullptr, $STATIC | $FINAL, $staticField(Http2Connection, DEBUG_LOGGER)},
	{"debugHpack", "Ljdk/internal/net/http/common/Logger;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, debugHpack)},
	{"EMPTY_TRIGGER", "Ljava/nio/ByteBuffer;", nullptr, $STATIC | $FINAL, $staticField(Http2Connection, EMPTY_TRIGGER)},
	{"MAX_CLIENT_STREAM_ID", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Http2Connection, MAX_CLIENT_STREAM_ID)},
	{"MAX_SERVER_STREAM_ID", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Http2Connection, MAX_SERVER_STREAM_ID)},
	{"BUFFER", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Http2Connection, BUFFER)},
	{"finalStream", "Z", nullptr, $PRIVATE, $field(Http2Connection, finalStream$)},
	{"closed", "Z", nullptr, $VOLATILE, $field(Http2Connection, closed)},
	{"connection", "Ljdk/internal/net/http/HttpConnection;", nullptr, $FINAL, $field(Http2Connection, connection)},
	{"client2", "Ljdk/internal/net/http/Http2ClientImpl;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, client2)},
	{"streams", "Ljava/util/concurrent/ConcurrentMap;", "Ljava/util/concurrent/ConcurrentMap<Ljava/lang/Integer;Ljdk/internal/net/http/Stream<*>;>;", $PRIVATE | $FINAL, $field(Http2Connection, streams)},
	{"nextstreamid", "I", nullptr, $PRIVATE, $field(Http2Connection, nextstreamid)},
	{"nextPushStream", "I", nullptr, $PRIVATE, $field(Http2Connection, nextPushStream)},
	{"lastReservedClientStreamid", "I", nullptr, $PRIVATE, $field(Http2Connection, lastReservedClientStreamid)},
	{"lastReservedServerStreamid", "I", nullptr, $PRIVATE, $field(Http2Connection, lastReservedServerStreamid)},
	{"numReservedClientStreams", "I", nullptr, $PRIVATE, $field(Http2Connection, numReservedClientStreams)},
	{"numReservedServerStreams", "I", nullptr, $PRIVATE, $field(Http2Connection, numReservedServerStreams)},
	{"hpackOut", "Ljdk/internal/net/http/hpack/Encoder;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, hpackOut)},
	{"hpackIn", "Ljdk/internal/net/http/hpack/Decoder;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, hpackIn)},
	{"clientSettings", "Ljdk/internal/net/http/frame/SettingsFrame;", nullptr, $FINAL, $field(Http2Connection, clientSettings)},
	{"serverSettings", "Ljdk/internal/net/http/frame/SettingsFrame;", nullptr, $PRIVATE | $VOLATILE, $field(Http2Connection, serverSettings)},
	{"key", "Ljava/lang/String;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, key$)},
	{"framesDecoder", "Ljdk/internal/net/http/frame/FramesDecoder;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, framesDecoder)},
	{"framesEncoder", "Ljdk/internal/net/http/frame/FramesEncoder;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, framesEncoder)},
	{"windowController", "Ljdk/internal/net/http/WindowController;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, windowController)},
	{"framesController", "Ljdk/internal/net/http/Http2Connection$FramesController;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, framesController)},
	{"subscriber", "Ljdk/internal/net/http/Http2Connection$Http2TubeSubscriber;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, subscriber)},
	{"windowUpdater", "Ljdk/internal/net/http/Http2Connection$ConnectionWindowUpdateSender;", nullptr, $FINAL, $field(Http2Connection, windowUpdater)},
	{"cause", "Ljava/lang/Throwable;", nullptr, $PRIVATE | $VOLATILE, $field(Http2Connection, cause)},
	{"initial", "Ljava/util/function/Supplier;", "Ljava/util/function/Supplier<Ljava/nio/ByteBuffer;>;", $PRIVATE | $VOLATILE, $field(Http2Connection, initial)},
	{"DEFAULT_FRAME_SIZE", "I", nullptr, $STATIC | $FINAL, $constField(Http2Connection, DEFAULT_FRAME_SIZE)},
	{"count", "J", nullptr, 0, $field(Http2Connection, count)},
	{"CLIENT_PREFACE", "Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Http2Connection, CLIENT_PREFACE)},
	{"PREFACE_BYTES", "[B", nullptr, $PRIVATE | $STATIC | $FINAL, $staticField(Http2Connection, PREFACE_BYTES)},
	{"sendlock", "Ljava/lang/Object;", nullptr, $PRIVATE | $FINAL, $field(Http2Connection, sendlock)},
	{}
};

$MethodInfo _Http2Connection_MethodInfo_[] = {
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Http2ClientImpl;ILjava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)($HttpConnection*,$Http2ClientImpl*,int32_t,$String*)>(&Http2Connection::init$))},
	{"<init>", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/Exchange;Ljava/util/function/Supplier;)V", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/Exchange<*>;Ljava/util/function/Supplier<Ljava/nio/ByteBuffer;>;)V", $PRIVATE, $method(static_cast<void(Http2Connection::*)($HttpConnection*,$Http2ClientImpl*,$Exchange*,$Supplier*)>(&Http2Connection::init$)), "java.io.IOException,java.lang.InterruptedException"},
	{"<init>", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/HttpConnection;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)($HttpRequestImpl*,$Http2ClientImpl*,$HttpConnection*)>(&Http2Connection::init$)), "java.io.IOException"},
	{"asyncReceive", "(Ljava/nio/ByteBuffer;)V", nullptr, $FINAL, $method(static_cast<void(Http2Connection::*)($ByteBuffer*)>(&Http2Connection::asyncReceive))},
	{"checkSSLConfig", "(Ljdk/internal/net/http/AbstractAsyncSSLConnection;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/AbstractAsyncSSLConnection;)Ljava/util/concurrent/CompletableFuture<*>;", $PRIVATE | $STATIC, $method(static_cast<$CompletableFuture*(*)($AbstractAsyncSSLConnection*)>(&Http2Connection::checkSSLConfig))},
	{"client", "()Ljdk/internal/net/http/HttpClientImpl;", nullptr, $FINAL, $method(static_cast<$HttpClientImpl*(Http2Connection::*)()>(&Http2Connection::client))},
	{"close", "()V", nullptr, 0},
	{"closeStream", "(I)V", nullptr, 0},
	{"connectFlows", "(Ljdk/internal/net/http/HttpConnection;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)($HttpConnection*)>(&Http2Connection::connectFlows))},
	{"createAsync", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/Exchange;Ljava/util/function/Supplier;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/Exchange<*>;Ljava/util/function/Supplier<Ljava/nio/ByteBuffer;>;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http2Connection;>;", $STATIC, $method(static_cast<$CompletableFuture*(*)($HttpConnection*,$Http2ClientImpl*,$Exchange*,$Supplier*)>(&Http2Connection::createAsync))},
	{"createAsync", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/Exchange;)Ljava/util/concurrent/CompletableFuture;", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/Exchange<*>;)Ljava/util/concurrent/CompletableFuture<Ljdk/internal/net/http/Http2Connection;>;", $STATIC, $method(static_cast<$CompletableFuture*(*)($HttpRequestImpl*,$Http2ClientImpl*,$Exchange*)>(&Http2Connection::createAsync))},
	{"createPushStream", "(Ljdk/internal/net/http/Stream;Ljdk/internal/net/http/Exchange;)Ljdk/internal/net/http/Stream$PushedStream;", "<T:Ljava/lang/Object;>(Ljdk/internal/net/http/Stream<TT;>;Ljdk/internal/net/http/Exchange<TT;>;)Ljdk/internal/net/http/Stream$PushedStream<TT;>;", 0},
	{"createStream", "(Ljdk/internal/net/http/Exchange;)Ljdk/internal/net/http/Stream;", "<T:Ljava/lang/Object;>(Ljdk/internal/net/http/Exchange<TT;>;)Ljdk/internal/net/http/Stream<TT;>;", $FINAL, $method(static_cast<$Stream*(Http2Connection::*)($Exchange*)>(&Http2Connection::createStream))},
	{"dbgString", "()Ljava/lang/String;", nullptr, $FINAL, $method(static_cast<$String*(Http2Connection::*)()>(&Http2Connection::dbgString))},
	{"decodeHeaders", "(Ljdk/internal/net/http/frame/HeaderFrame;Ljdk/internal/net/http/hpack/DecodingCallback;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)($HeaderFrame*,$DecodingCallback*)>(&Http2Connection::decodeHeaders)), "java.io.IOException"},
	{"decrementStreamsCount", "(I)V", nullptr, $SYNCHRONIZED},
	{"dropDataFrame", "(Ljdk/internal/net/http/frame/DataFrame;)V", nullptr, $FINAL, $method(static_cast<void(Http2Connection::*)($DataFrame*)>(&Http2Connection::dropDataFrame))},
	{"encodeFrame", "(Ljdk/internal/net/http/frame/Http2Frame;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/Http2Frame;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(Http2Connection::*)($Http2Frame*)>(&Http2Connection::encodeFrame))},
	{"encodeFrames", "(Ljava/util/List;)Ljava/util/List;", "(Ljava/util/List<Ljdk/internal/net/http/frame/HeaderFrame;>;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(Http2Connection::*)($List*)>(&Http2Connection::encodeFrames))},
	{"encodeHeaders", "(Ljdk/internal/net/http/frame/OutgoingHeaders;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/OutgoingHeaders<Ljdk/internal/net/http/Stream<*>;>;)Ljava/util/List<Ljdk/internal/net/http/frame/HeaderFrame;>;", $PRIVATE, $method(static_cast<$List*(Http2Connection::*)($OutgoingHeaders*)>(&Http2Connection::encodeHeaders))},
	{"encodeHeaders", "(Ljdk/internal/net/http/frame/OutgoingHeaders;Ljdk/internal/net/http/Stream;)Ljava/util/List;", "(Ljdk/internal/net/http/frame/OutgoingHeaders<Ljdk/internal/net/http/Stream<*>;>;Ljdk/internal/net/http/Stream<*>;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE, $method(static_cast<$List*(Http2Connection::*)($OutgoingHeaders*,$Stream*)>(&Http2Connection::encodeHeaders))},
	{"encodeHeadersImpl", "(I[Ljava/net/http/HttpHeaders;)Ljava/util/List;", "(I[Ljava/net/http/HttpHeaders;)Ljava/util/List<Ljava/nio/ByteBuffer;>;", $PRIVATE | $TRANSIENT, $method(static_cast<$List*(Http2Connection::*)(int32_t,$HttpHeadersArray*)>(&Http2Connection::encodeHeadersImpl))},
	{"ensureWindowUpdated", "(Ljdk/internal/net/http/frame/DataFrame;)V", nullptr, $FINAL, $method(static_cast<void(Http2Connection::*)($DataFrame*)>(&Http2Connection::ensureWindowUpdated))},
	{"finalStream", "()Z", nullptr, $SYNCHRONIZED},
	{"getHeaderBuffer", "(I)Ljava/nio/ByteBuffer;", nullptr, $PRIVATE, $method(static_cast<$ByteBuffer*(Http2Connection::*)(int32_t)>(&Http2Connection::getHeaderBuffer))},
	{"getInitialSendWindowSize", "()I", nullptr, $FINAL, $method(static_cast<int32_t(Http2Connection::*)()>(&Http2Connection::getInitialSendWindowSize))},
	{"getMaxReceiveFrameSize", "()I", nullptr, $PUBLIC},
	{"getMaxSendFrameSize", "()I", nullptr, $PUBLIC},
	{"getRecordedCause", "()Ljava/lang/Throwable;", nullptr, 0},
	{"getStream", "(I)Ljdk/internal/net/http/Stream;", "<T:Ljava/lang/Object;>(I)Ljdk/internal/net/http/Stream<TT;>;", 0},
	{"handleConnectionFrame", "(Ljdk/internal/net/http/frame/Http2Frame;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)($Http2Frame*)>(&Http2Connection::handleConnectionFrame)), "java.io.IOException"},
	{"handleGoAway", "(Ljdk/internal/net/http/frame/GoAwayFrame;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)($GoAwayFrame*)>(&Http2Connection::handleGoAway)), "java.io.IOException"},
	{"handlePing", "(Ljdk/internal/net/http/frame/PingFrame;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)($PingFrame*)>(&Http2Connection::handlePing)), "java.io.IOException"},
	{"handlePushPromise", "(Ljdk/internal/net/http/Stream;Ljdk/internal/net/http/frame/PushPromiseFrame;)V", "<T:Ljava/lang/Object;>(Ljdk/internal/net/http/Stream<TT;>;Ljdk/internal/net/http/frame/PushPromiseFrame;)V", $PRIVATE, $method(static_cast<void(Http2Connection::*)($Stream*,$PushPromiseFrame*)>(&Http2Connection::handlePushPromise)), "java.io.IOException"},
	{"handleSettings", "(Ljdk/internal/net/http/frame/SettingsFrame;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)($SettingsFrame*)>(&Http2Connection::handleSettings)), "java.io.IOException"},
	{"handleWindowUpdate", "(Ljdk/internal/net/http/frame/WindowUpdateFrame;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)($WindowUpdateFrame*)>(&Http2Connection::handleWindowUpdate)), "java.io.IOException"},
	{"isActive", "()Z", nullptr, $SYNCHRONIZED},
	{"isServerInitiatedStream", "(I)Z", nullptr, $PRIVATE | $STATIC | $FINAL, $method(static_cast<bool(*)(int32_t)>(&Http2Connection::isServerInitiatedStream))},
	{"key", "()Ljava/lang/String;", nullptr, 0},
	{"keyFor", "(Ljdk/internal/net/http/HttpConnection;)Ljava/lang/String;", nullptr, $STATIC, $method(static_cast<$String*(*)($HttpConnection*)>(&Http2Connection::keyFor))},
	{"keyFor", "(Ljava/net/URI;Ljava/net/InetSocketAddress;)Ljava/lang/String;", nullptr, $STATIC, $method(static_cast<$String*(*)($URI*,$InetSocketAddress*)>(&Http2Connection::keyFor))},
	{"keyString", "(ZLjava/net/InetSocketAddress;Ljava/lang/String;I)Ljava/lang/String;", nullptr, $STATIC, $method(static_cast<$String*(*)(bool,$InetSocketAddress*,$String*,int32_t)>(&Http2Connection::keyString))},
	{"lambda$asyncReceive$6", "(JLjava/nio/ByteBuffer;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)(int64_t,$ByteBuffer*)>(&Http2Connection::lambda$asyncReceive$6))},
	{"lambda$checkSSLConfig$4", "(Ljdk/internal/net/http/AbstractAsyncSSLConnection;Ljava/lang/String;)Ljava/util/concurrent/CompletableFuture;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$CompletableFuture*(*)($AbstractAsyncSSLConnection*,$String*)>(&Http2Connection::lambda$checkSSLConfig$4))},
	{"lambda$checkSSLConfig$5", "(Ljdk/internal/net/http/AbstractAsyncSSLConnection;Ljava/lang/String;Ljava/lang/Throwable;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($AbstractAsyncSSLConnection*,$String*,$Throwable*)>(&Http2Connection::lambda$checkSSLConfig$5))},
	{"lambda$createAsync$0", "(Ljdk/internal/net/http/HttpConnection;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/Exchange;Ljava/util/function/Supplier;)Ljdk/internal/net/http/Http2Connection;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<Http2Connection*(*)($HttpConnection*,$Http2ClientImpl*,$Exchange*,$Supplier*)>(&Http2Connection::lambda$createAsync$0)), "java.lang.Throwable"},
	{"lambda$createAsync$1", "(Ljdk/internal/net/http/AbstractAsyncSSLConnection;Ljava/lang/Void;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$CompletionStage*(*)($AbstractAsyncSSLConnection*,$Void*)>(&Http2Connection::lambda$createAsync$1))},
	{"lambda$createAsync$2", "(Ljdk/internal/net/http/AbstractAsyncSSLConnection;Ljava/lang/Void;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$CompletionStage*(*)($AbstractAsyncSSLConnection*,$Void*)>(&Http2Connection::lambda$createAsync$2))},
	{"lambda$createAsync$3", "(Ljdk/internal/net/http/HttpRequestImpl;Ljdk/internal/net/http/Http2ClientImpl;Ljdk/internal/net/http/AbstractAsyncSSLConnection;Ljava/lang/Object;)Ljava/util/concurrent/CompletionStage;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$CompletionStage*(*)($HttpRequestImpl*,$Http2ClientImpl*,$AbstractAsyncSSLConnection*,Object$*)>(&Http2Connection::lambda$createAsync$3))},
	{"lambda$encodeFrames$9", "(Ljdk/internal/net/http/frame/HeaderFrame;)V", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<void(*)($HeaderFrame*)>(&Http2Connection::lambda$encodeFrames$9))},
	{"lambda$processFrame$8", "(Ljdk/internal/net/http/frame/Http2Frame;)Ljava/lang/String;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$String*(*)($Http2Frame*)>(&Http2Connection::lambda$processFrame$8))},
	{"lambda$shutdown$7", "(Ljava/lang/Throwable;)Ljava/lang/String;", nullptr, $PRIVATE | $SYNTHETIC, $method(static_cast<$String*(Http2Connection::*)($Throwable*)>(&Http2Connection::lambda$shutdown$7))},
	{"markStream", "(II)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)(int32_t,int32_t)>(&Http2Connection::markStream))},
	{"maxConcurrentClientInitiatedStreams", "()I", nullptr, $FINAL, $method(static_cast<int32_t(Http2Connection::*)()>(&Http2Connection::maxConcurrentClientInitiatedStreams))},
	{"maxConcurrentServerInitiatedStreams", "()I", nullptr, $FINAL, $method(static_cast<int32_t(Http2Connection::*)()>(&Http2Connection::maxConcurrentServerInitiatedStreams))},
	{"offerConnection", "()Z", nullptr, 0},
	{"processFrame", "(Ljdk/internal/net/http/frame/Http2Frame;)V", nullptr, 0, nullptr, "java.io.IOException"},
	{"protocolError", "(I)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)(int32_t)>(&Http2Connection::protocolError)), "java.io.IOException"},
	{"protocolError", "(ILjava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)(int32_t,$String*)>(&Http2Connection::protocolError)), "java.io.IOException"},
	{"publisher", "()Ljdk/internal/net/http/HttpConnection$HttpPublisher;", nullptr, $PRIVATE, $method(static_cast<$HttpConnection$HttpPublisher*(Http2Connection::*)()>(&Http2Connection::publisher))},
	{"putStream", "(Ljdk/internal/net/http/Stream;I)V", "<T:Ljava/lang/Object;>(Ljdk/internal/net/http/Stream<TT;>;I)V", 0},
	{"registerNewStream", "(Ljdk/internal/net/http/frame/OutgoingHeaders;)Ljdk/internal/net/http/Stream;", "(Ljdk/internal/net/http/frame/OutgoingHeaders<Ljdk/internal/net/http/Stream<*>;>;)Ljdk/internal/net/http/Stream<*>;", $PRIVATE, $method(static_cast<$Stream*(Http2Connection::*)($OutgoingHeaders*)>(&Http2Connection::registerNewStream))},
	{"reserveStream", "(Z)Z", nullptr, $SYNCHRONIZED, nullptr, "java.io.IOException"},
	{"resetStream", "(II)V", nullptr, 0},
	{"sendConnectionPreface", "()V", nullptr, $PRIVATE, $method(static_cast<void(Http2Connection::*)()>(&Http2Connection::sendConnectionPreface)), "java.io.IOException"},
	{"sendDataFrame", "(Ljdk/internal/net/http/frame/DataFrame;)V", nullptr, 0},
	{"sendFrame", "(Ljdk/internal/net/http/frame/Http2Frame;)V", nullptr, 0},
	{"sendUnorderedFrame", "(Ljdk/internal/net/http/frame/Http2Frame;)V", nullptr, 0},
	{"setFinalStream", "()V", nullptr, $SYNCHRONIZED},
	{"shutdown", "(Ljava/lang/Throwable;)V", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC | $FINAL},
	{}
};

$InnerClassInfo _Http2Connection_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http2Connection$ALPNException", "jdk.internal.net.http.Http2Connection", "ALPNException", $STATIC | $FINAL},
	{"jdk.internal.net.http.Http2Connection$ConnectionWindowUpdateSender", "jdk.internal.net.http.Http2Connection", "ConnectionWindowUpdateSender", $STATIC | $FINAL},
	{"jdk.internal.net.http.Http2Connection$ValidatingHeadersConsumer", "jdk.internal.net.http.Http2Connection", "ValidatingHeadersConsumer", $STATIC},
	{"jdk.internal.net.http.Http2Connection$HeaderDecoder", "jdk.internal.net.http.Http2Connection", "HeaderDecoder", $STATIC},
	{"jdk.internal.net.http.Http2Connection$Http2TubeSubscriber", "jdk.internal.net.http.Http2Connection", "Http2TubeSubscriber", $FINAL},
	{"jdk.internal.net.http.Http2Connection$FramesController", "jdk.internal.net.http.Http2Connection", "FramesController", $PRIVATE | $FINAL},
	{}
};

$ClassInfo _Http2Connection_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Http2Connection",
	"java.lang.Object",
	nullptr,
	_Http2Connection_FieldInfo_,
	_Http2Connection_MethodInfo_,
	nullptr,
	nullptr,
	_Http2Connection_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http2Connection$ALPNException,jdk.internal.net.http.Http2Connection$ConnectionWindowUpdateSender,jdk.internal.net.http.Http2Connection$ValidatingHeadersConsumer,jdk.internal.net.http.Http2Connection$HeaderDecoder,jdk.internal.net.http.Http2Connection$Http2TubeSubscriber,jdk.internal.net.http.Http2Connection$FramesController"
};

$Object* allocate$Http2Connection($Class* clazz) {
	return $of($alloc(Http2Connection));
}

bool Http2Connection::$assertionsDisabled = false;
$Logger* Http2Connection::DEBUG_LOGGER = nullptr;
$ByteBuffer* Http2Connection::EMPTY_TRIGGER = nullptr;
$String* Http2Connection::CLIENT_PREFACE = nullptr;
$bytes* Http2Connection::PREFACE_BYTES = nullptr;

void Http2Connection::init$($HttpConnection* connection, $Http2ClientImpl* client2, int32_t nextstreamid, $String* key) {
	$useLocalCurrentObjectStackCache();
	$init($Utils);
	$set(this, debug, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Http2Connection$$Lambda$dbgString, this)), $Utils::DEBUG));
	$set(this, debugHpack, $Utils::getHpackLogger(static_cast<$Supplier*>($$new(Http2Connection$$Lambda$dbgString, this)), $Utils::DEBUG_HPACK));
	$set(this, streams, $new($ConcurrentHashMap));
	this->nextPushStream = 2;
	this->lastReservedClientStreamid = 1;
	this->lastReservedServerStreamid = 0;
	this->numReservedClientStreams = 0;
	this->numReservedServerStreams = 0;
	$set(this, framesEncoder, $new($FramesEncoder));
	$set(this, windowController, $new($WindowController));
	$set(this, framesController, $new($Http2Connection$FramesController, this));
	$set(this, sendlock, $new($Object));
	$set(this, connection, connection);
	$set(this, client2, client2);
	$set(this, subscriber, $new($Http2Connection$Http2TubeSubscriber, this, $($nc(client2)->client())));
	this->nextstreamid = nextstreamid;
	$set(this, key$, key);
	$set(this, clientSettings, $nc(this->client2)->getClientSettings());
	$var($FramesDecoder$FrameProcessor, var$0, static_cast<$FramesDecoder$FrameProcessor*>($new(Http2Connection$$Lambda$processFrame$2, this)));
	$set(this, framesDecoder, $new($FramesDecoder, var$0, $nc(this->clientSettings)->getParameter($SettingsFrame::MAX_FRAME_SIZE)));
	$set(this, serverSettings, $SettingsFrame::defaultRFCSettings());
	$set(this, hpackOut, $new($Encoder, $nc(this->serverSettings)->getParameter(1)));
	$set(this, hpackIn, $new($Decoder, $nc(this->clientSettings)->getParameter(1)));
	if ($nc(this->debugHpack)->on()) {
		$nc(this->debugHpack)->log($$str({"For the record:"_s, $($Object::toString())}));
		$nc(this->debugHpack)->log("Decoder created: %s"_s, $$new($ObjectArray, {$of(this->hpackIn)}));
		$nc(this->debugHpack)->log("Encoder created: %s"_s, $$new($ObjectArray, {$of(this->hpackOut)}));
	}
	$set(this, windowUpdater, $new($Http2Connection$ConnectionWindowUpdateSender, this, $nc(client2)->getConnectionWindowSize(this->clientSettings)));
}

void Http2Connection::init$($HttpConnection* connection, $Http2ClientImpl* client2, $Exchange* exchange, $Supplier* initial) {
	$useLocalCurrentObjectStackCache();
	Http2Connection::init$(connection, client2, 3, $(keyFor(connection)));
	reserveStream(true);
	$Log::logTrace("Connection send window size {0} "_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(this->windowController)->connectionWindowSize())))}));
	$var($Stream, initialStream, createStream(exchange));
	bool opened = $nc(initialStream)->registerStream(1, true);
	if ($nc(this->debug)->on() && !opened) {
		$nc(this->debug)->log("Initial stream was cancelled - but connection is maintained: reset frame will need to be sent later"_s);
	}
	$nc(this->windowController)->registerStream(1, getInitialSendWindowSize());
	initialStream->requestSent();
	$set(this, initial, initial);
	connectFlows(connection);
	sendConnectionPreface();
	if (!opened) {
		$nc(this->debug)->log("ensure reset frame is sent to cancel initial stream"_s);
		initialStream->sendCancelStreamFrame();
	}
}

$CompletableFuture* Http2Connection::createAsync($HttpConnection* connection, $Http2ClientImpl* client2, $Exchange* exchange, $Supplier* initial) {
	$init(Http2Connection);
	return $MinimalFuture::supply(static_cast<$MinimalFuture$ExceptionalSupplier*>($$new(Http2Connection$$Lambda$lambda$createAsync$0$3, connection, client2, exchange, initial)));
}

$CompletableFuture* Http2Connection::createAsync($HttpRequestImpl* request, $Http2ClientImpl* h2client, $Exchange* exchange) {
	$init(Http2Connection);
	$useLocalCurrentObjectStackCache();
	if (!Http2Connection::$assertionsDisabled && !$nc(request)->secure()) {
		$throwNew($AssertionError);
	}
	$var($InetSocketAddress, var$0, $nc(request)->getAddress());
	$init($HttpClient$Version);
	$var($AbstractAsyncSSLConnection, connection, $cast($AbstractAsyncSSLConnection, $HttpConnection::getConnection(var$0, $($nc(h2client)->client()), request, $HttpClient$Version::HTTP_2)));
	$nc($nc(exchange)->connectionAborter)->connection(connection);
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($($nc(connection)->connectAsync(exchange)))->thenCompose(static_cast<$Function*>($$new(Http2Connection$$Lambda$lambda$createAsync$1$4, connection))))))->thenCompose(static_cast<$Function*>($$new(Http2Connection$$Lambda$lambda$createAsync$2$5, connection))))))->thenCompose(static_cast<$Function*>($$new(Http2Connection$$Lambda$lambda$createAsync$3$6, request, h2client, connection))));
}

void Http2Connection::init$($HttpRequestImpl* request, $Http2ClientImpl* h2client, $HttpConnection* connection) {
	$useLocalCurrentObjectStackCache();
	$var($URI, var$0, $nc(request)->uri());
	Http2Connection::init$(connection, h2client, 1, $(keyFor(var$0, $(request->proxy()))));
	$Log::logTrace("Connection send window size {0} "_s, $$new($ObjectArray, {$($of($Integer::valueOf($nc(this->windowController)->connectionWindowSize())))}));
	connectFlows(connection);
	sendConnectionPreface();
}

void Http2Connection::connectFlows($HttpConnection* connection) {
	$useLocalCurrentObjectStackCache();
	$var($FlowTube, tube, $nc(connection)->getConnectionFlow());
	$nc(tube)->connectFlows($(connection->publisher()), this->subscriber);
}

$HttpClientImpl* Http2Connection::client() {
	return $nc(this->client2)->client();
}

bool Http2Connection::reserveStream(bool clientInitiated) {
	$synchronized(this) {
		if (this->finalStream$) {
			return false;
		}
		if (clientInitiated && (this->lastReservedClientStreamid + 2) >= Http2Connection::MAX_CLIENT_STREAM_ID) {
			setFinalStream();
			$nc(this->client2)->deleteConnection(this);
			return false;
		} else if (!clientInitiated && (this->lastReservedServerStreamid + 2) >= Http2Connection::MAX_SERVER_STREAM_ID) {
			setFinalStream();
			$nc(this->client2)->deleteConnection(this);
			return false;
		}
		if (clientInitiated) {
			this->lastReservedClientStreamid += 2;
		} else {
			this->lastReservedServerStreamid += 2;
		}
		if (!Http2Connection::$assertionsDisabled && !(this->numReservedClientStreams >= 0)) {
			$throwNew($AssertionError);
		}
		if (!Http2Connection::$assertionsDisabled && !(this->numReservedServerStreams >= 0)) {
			$throwNew($AssertionError);
		}
		if (clientInitiated && this->numReservedClientStreams >= maxConcurrentClientInitiatedStreams()) {
			$throwNew($IOException, "too many concurrent streams"_s);
		} else if (clientInitiated) {
			++this->numReservedClientStreams;
		}
		if (!clientInitiated && this->numReservedServerStreams >= maxConcurrentServerInitiatedStreams()) {
			return false;
		} else if (!clientInitiated) {
			++this->numReservedServerStreams;
		}
		return true;
	}
}

$CompletableFuture* Http2Connection::checkSSLConfig($AbstractAsyncSSLConnection* aconn) {
	$init(Http2Connection);
	$useLocalCurrentObjectStackCache();
	if (!Http2Connection::$assertionsDisabled && !$nc(aconn)->isSecure()) {
		$throwNew($AssertionError);
	}
	$var($Function, checkAlpnCF, static_cast<$Function*>($new(Http2Connection$$Lambda$lambda$checkSSLConfig$4$7, aconn)));
	return $cast($CompletableFuture, $nc($($cast($CompletableFuture, $nc($($nc(aconn)->getALPN()))->whenComplete(static_cast<$BiConsumer*>($$new(Http2Connection$$Lambda$lambda$checkSSLConfig$5$8, aconn))))))->thenCompose(checkAlpnCF));
}

bool Http2Connection::finalStream() {
	$synchronized(this) {
		return this->finalStream$;
	}
}

void Http2Connection::setFinalStream() {
	$synchronized(this) {
		this->finalStream$ = true;
	}
}

$String* Http2Connection::keyFor($HttpConnection* connection) {
	$init(Http2Connection);
	$useLocalCurrentObjectStackCache();
	bool isProxy = $nc(connection)->isProxied();
	bool isSecure = connection->isSecure();
	$var($InetSocketAddress, addr, connection->address());
	$var($InetSocketAddress, proxyAddr, connection->proxy());
	if (!Http2Connection::$assertionsDisabled && !(isProxy == (proxyAddr != nullptr))) {
		$throwNew($AssertionError);
	}
	bool var$0 = isSecure;
	$var($InetSocketAddress, var$1, proxyAddr);
	$var($String, var$2, $nc(addr)->getHostString());
	return keyString(var$0, var$1, var$2, addr->getPort());
}

$String* Http2Connection::keyFor($URI* uri, $InetSocketAddress* proxy) {
	$init(Http2Connection);
	$useLocalCurrentObjectStackCache();
	bool isSecure = $nc($($nc(uri)->getScheme()))->equalsIgnoreCase("https"_s);
	$var($String, host, uri->getHost());
	int32_t port = uri->getPort();
	return keyString(isSecure, proxy, host, port);
}

$String* Http2Connection::keyString(bool secure, $InetSocketAddress* proxy, $String* host, int32_t port) {
	$init(Http2Connection);
	$useLocalCurrentObjectStackCache();
	if (secure && port == -1) {
		port = 443;
	} else if (!secure && port == -1) {
		port = 80;
	}
	$var($String, key, secure ? "S:"_s : "C:"_s);
	if (proxy != nullptr && !secure) {
		$var($String, var$0, $$str({key, "P:"_s, $(proxy->getHostString()), ":"_s}));
		$assign(key, $concat(var$0, $$str(proxy->getPort())));
	} else if (proxy == nullptr) {
		$assign(key, $str({key, "H:"_s, host, ":"_s, $$str(port)}));
	} else {
		$var($String, var$1, $$str({key, "T:H:"_s, host, ":"_s, $$str(port), ";P:"_s, $(proxy->getHostString()), ":"_s}));
		$assign(key, $concat(var$1, $$str(proxy->getPort())));
	}
	return key;
}

$String* Http2Connection::key() {
	return this->key$;
}

bool Http2Connection::offerConnection() {
	return $nc(this->client2)->offerConnection(this);
}

$HttpConnection$HttpPublisher* Http2Connection::publisher() {
	return $nc(this->connection)->publisher();
}

void Http2Connection::decodeHeaders($HeaderFrame* frame, $DecodingCallback* decoder) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debugHpack)->on()) {
		$nc(this->debugHpack)->log("decodeHeaders(%s)"_s, $$new($ObjectArray, {$of(decoder)}));
	}
	bool endOfHeaders = $nc(frame)->getFlag($HeaderFrame::END_HEADERS);
	$var($List, buffers, frame->getHeaderBlock());
	int32_t len = $nc(buffers)->size();
	for (int32_t i = 0; i < len; ++i) {
		$var($ByteBuffer, b, $cast($ByteBuffer, buffers->get(i)));
		$nc(this->hpackIn)->decode(b, endOfHeaders && (i == len - 1), decoder);
	}
}

int32_t Http2Connection::getInitialSendWindowSize() {
	return $nc(this->serverSettings)->getParameter(4);
}

int32_t Http2Connection::maxConcurrentClientInitiatedStreams() {
	return $nc(this->serverSettings)->getParameter(3);
}

int32_t Http2Connection::maxConcurrentServerInitiatedStreams() {
	return $nc(this->clientSettings)->getParameter(3);
}

void Http2Connection::close() {
	$useLocalCurrentObjectStackCache();
	$Log::logTrace("Closing HTTP/2 connection: to {0}"_s, $$new($ObjectArray, {$($of($nc(this->connection)->address()))}));
	$init($StandardCharsets);
	$var($GoAwayFrame, f, $new($GoAwayFrame, 0, $ErrorFrame::NO_ERROR, $("Requested by user"_s->getBytes($StandardCharsets::UTF_8))));
	sendFrame(f);
}

void Http2Connection::asyncReceive($ByteBuffer* buffer) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($Supplier, bs, this->initial);
		if (bs != nullptr) {
			$set(this, initial, nullptr);
			$var($ByteBuffer, b, $cast($ByteBuffer, bs->get()));
			if ($nc(b)->hasRemaining()) {
				int64_t c = ++this->count;
				if ($nc(this->debug)->on()) {
					$nc(this->debug)->log(static_cast<$Supplier*>($$new(Http2Connection$$Lambda$lambda$asyncReceive$6$9, c, b)));
				}
				$nc(this->framesController)->processReceivedData(this->framesDecoder, b);
			}
		}
		$var($ByteBuffer, b, buffer);
		if (b == Http2Connection::EMPTY_TRIGGER) {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("H2 Received EMPTY_TRIGGER"_s);
			}
			bool prefaceSent = $nc(this->framesController)->prefaceSent;
			if (!Http2Connection::$assertionsDisabled && !prefaceSent) {
				$throwNew($AssertionError);
			}
			$nc(this->framesController)->processReceivedData(this->framesDecoder, buffer);
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("H2 processed buffered data"_s);
			}
		} else {
			int64_t c = ++this->count;
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("H2 Receiving(%d): %d"_s, $$new($ObjectArray, {
					$($of($Long::valueOf(c))),
					$($of($Integer::valueOf($nc(b)->remaining())))
				}));
			}
			$nc(this->framesController)->processReceivedData(this->framesDecoder, buffer);
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("H2 processed(%d)"_s, $$new($ObjectArray, {$($of($Long::valueOf(c)))}));
			}
		}
	} catch ($Throwable& e) {
		$var($String, msg, $Utils::stackTrace(e));
		$Log::logTrace(msg, $$new($ObjectArray, 0));
		shutdown(e);
	}
}

$Throwable* Http2Connection::getRecordedCause() {
	return this->cause;
}

void Http2Connection::shutdown($Throwable* t) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log(static_cast<$Supplier*>($$new(Http2Connection$$Lambda$lambda$shutdown$7$10, this, t)));
	}
	if (this->closed == true) {
		return;
	}
	$synchronized(this) {
		if (this->closed == true) {
			return;
		}
		this->closed = true;
	}
	if ($Log::errors()) {
		if (!($instanceOf($EOFException, t)) || isActive()) {
			$Log::logError(t);
		} else if (t != nullptr) {
			$Log::logError("Shutting down connection: {0}"_s, $$new($ObjectArray, {$($of(t->getMessage()))}));
		}
	}
	$var($Throwable, initialCause, this->cause);
	if (initialCause == nullptr) {
		$set(this, cause, t);
	}
	$nc(this->client2)->deleteConnection(this);
	{
		$var($Iterator, i$, $nc($($nc(this->streams)->values()))->iterator());
		for (; $nc(i$)->hasNext();) {
			$var($Stream, s, $cast($Stream, i$->next()));
			{
				try {
					$nc(s)->connectionClosing(t);
				} catch ($Throwable& e) {
					$Log::logError("Failed to close stream {0}: {1}"_s, $$new($ObjectArray, {
						$($of($Integer::valueOf($nc(s)->streamid))),
						$of(e)
					}));
				}
			}
		}
	}
	$nc(this->connection)->close();
}

bool Http2Connection::isServerInitiatedStream(int32_t streamid) {
	$init(Http2Connection);
	return ((int32_t)(streamid & (uint32_t)1)) == 0;
}

void Http2Connection::processFrame($Http2Frame* frame) {
	$useLocalCurrentObjectStackCache();
	$Log::logFrames(frame, "IN"_s);
	int32_t streamid = $nc(frame)->streamid();
	if ($instanceOf($MalformedFrame, frame)) {
		$Log::logError($($nc(($cast($MalformedFrame, frame)))->getMessage()), $$new($ObjectArray, 0));
		if (streamid == 0) {
			$nc(this->framesDecoder)->close("Malformed frame on stream 0"_s);
			int32_t var$0 = $nc(($cast($MalformedFrame, frame)))->getErrorCode();
			protocolError(var$0, $(($cast($MalformedFrame, frame))->getMessage()));
		} else {
			if ($nc(this->debug)->on()) {
				$nc(this->debug)->log(static_cast<$Supplier*>($$new(Http2Connection$$Lambda$lambda$processFrame$8$11, frame)));
			}
			resetStream(streamid, $nc(($cast($MalformedFrame, frame)))->getErrorCode());
		}
		return;
	}
	if (streamid == 0) {
		handleConnectionFrame(frame);
	} else {
		if ($instanceOf($SettingsFrame, frame)) {
			$nc(this->framesDecoder)->close("The stream identifier for a SETTINGS frame MUST be zero"_s);
			protocolError($GoAwayFrame::PROTOCOL_ERROR);
			return;
		}
		$var($Stream, stream, getStream(streamid));
		if (stream == nullptr) {
			if ($instanceOf($HeaderFrame, frame)) {
				$var($DecodingCallback, decoder, $new($Http2Connection$ValidatingHeadersConsumer));
				try {
					decodeHeaders($cast($HeaderFrame, frame), decoder);
				} catch ($UncheckedIOException& e) {
					protocolError($ResetFrame::PROTOCOL_ERROR, $(e->getMessage()));
					return;
				}
			}
			if (!($instanceOf($ResetFrame, frame))) {
				if ($instanceOf($DataFrame, frame)) {
					dropDataFrame($cast($DataFrame, frame));
				}
				if (isServerInitiatedStream(streamid)) {
					if (streamid < this->nextPushStream) {
						$Log::logTrace($$str({"Ignoring cancelled push promise frame "_s, frame}), $$new($ObjectArray, 0));
					} else {
						resetStream(streamid, $ResetFrame::PROTOCOL_ERROR);
					}
				} else if (streamid >= this->nextstreamid) {
					resetStream(streamid, $ResetFrame::PROTOCOL_ERROR);
				}
			}
			return;
		}
		if ($instanceOf($PushPromiseFrame, frame)) {
			$var($PushPromiseFrame, pp, $cast($PushPromiseFrame, frame));
			try {
				handlePushPromise(stream, pp);
			} catch ($UncheckedIOException& e) {
				protocolError($ResetFrame::PROTOCOL_ERROR, $(e->getMessage()));
				return;
			}
		} else if ($instanceOf($HeaderFrame, frame)) {
			try {
				decodeHeaders($cast($HeaderFrame, frame), $($nc(stream)->rspHeadersConsumer()));
			} catch ($UncheckedIOException& e) {
				$nc(this->debug)->log($$str({"Error decoding headers: "_s, $(e->getMessage())}), static_cast<$Throwable*>(e));
				protocolError($ResetFrame::PROTOCOL_ERROR, $(e->getMessage()));
				return;
			}
			$nc(stream)->incoming(frame);
		} else {
			$nc(stream)->incoming(frame);
		}
	}
}

void Http2Connection::dropDataFrame($DataFrame* df) {
	$useLocalCurrentObjectStackCache();
	if (this->closed) {
		return;
	}
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Dropping data frame for stream %d (%d payload bytes)"_s, $$new($ObjectArray, {
			$($of($Integer::valueOf($nc(df)->streamid()))),
			$($of($Integer::valueOf($nc(df)->payloadLength())))
		}));
	}
	ensureWindowUpdated(df);
}

void Http2Connection::ensureWindowUpdated($DataFrame* df) {
	try {
		if (this->closed) {
			return;
		}
		int32_t length = $nc(df)->payloadLength();
		if (length > 0) {
			$nc(this->windowUpdater)->update(length);
		}
	} catch ($Throwable& t) {
		$Log::logError("Unexpected exception while updating window: {0}"_s, $$new($ObjectArray, {$of(t)}));
	}
}

void Http2Connection::handlePushPromise($Stream* parent, $PushPromiseFrame* pp) {
	$useLocalCurrentObjectStackCache();
	$var($Http2Connection$HeaderDecoder, decoder, $new($Http2Connection$HeaderDecoder));
	decodeHeaders(pp, decoder);
	$var($HttpRequestImpl, parentReq, $nc(parent)->request);
	int32_t promisedStreamid = $nc(pp)->getPromisedStream();
	if (promisedStreamid != this->nextPushStream) {
		resetStream(promisedStreamid, $ResetFrame::PROTOCOL_ERROR);
		return;
	} else if (!reserveStream(false)) {
		resetStream(promisedStreamid, $ResetFrame::REFUSED_STREAM);
		return;
	} else {
		this->nextPushStream += 2;
	}
	$var($HttpHeaders, headers, decoder->headers());
	$var($HttpRequestImpl, pushReq, $HttpRequestImpl::createPushRequest(parentReq, headers));
	$var($Exchange, pushExch, $new($Exchange, pushReq, $nc(parent->exchange)->multi));
	$var($Stream$PushedStream, pushStream, createPushStream(parent, pushExch));
	$set(pushExch, exchImpl, pushStream);
	$nc(pushStream)->registerStream(promisedStreamid, true);
	parent->incoming_pushPromise(pushReq, pushStream);
}

void Http2Connection::handleConnectionFrame($Http2Frame* frame) {
	switch ($nc(frame)->type()) {
	case $SettingsFrame::TYPE:
		{
			handleSettings($cast($SettingsFrame, frame));
			break;
		}
	case $PingFrame::TYPE:
		{
			handlePing($cast($PingFrame, frame));
			break;
		}
	case $GoAwayFrame::TYPE:
		{
			handleGoAway($cast($GoAwayFrame, frame));
			break;
		}
	case $WindowUpdateFrame::TYPE:
		{
			handleWindowUpdate($cast($WindowUpdateFrame, frame));
			break;
		}
	default:
		{
			protocolError($ErrorFrame::PROTOCOL_ERROR);
			break;
		}
	}
}

void Http2Connection::resetStream(int32_t streamid, int32_t code) {
	$useLocalCurrentObjectStackCache();
	{
		$var($Throwable, var$0, nullptr);
		try {
			if ($nc($($nc(this->connection)->channel()))->isOpen()) {
				$Log::logError("Resetting stream {0,number,integer} with error code {1,number,integer}"_s, $$new($ObjectArray, {
					$($of($Integer::valueOf(streamid))),
					$($of($Integer::valueOf(code)))
				}));
				markStream(streamid, code);
				$var($ResetFrame, frame, $new($ResetFrame, streamid, code));
				sendFrame(frame);
			} else if ($nc(this->debug)->on()) {
				$nc(this->debug)->log("Channel already closed, no need to reset stream %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(streamid)))}));
			}
		} catch ($Throwable& var$1) {
			$assign(var$0, var$1);
		} /*finally*/ {
			decrementStreamsCount(streamid);
			closeStream(streamid);
		}
		if (var$0 != nullptr) {
			$throw(var$0);
		}
	}
}

void Http2Connection::markStream(int32_t streamid, int32_t code) {
	$useLocalCurrentObjectStackCache();
	$var($Stream, s, $cast($Stream, $nc(this->streams)->get($($Integer::valueOf(streamid)))));
	if (s != nullptr) {
		s->markStream(code);
	}
}

void Http2Connection::decrementStreamsCount(int32_t streamid) {
	$synchronized(this) {
		$useLocalCurrentObjectStackCache();
		$var($Stream, s, $cast($Stream, $nc(this->streams)->get($($Integer::valueOf(streamid)))));
		if (s == nullptr || !$nc(s)->deRegister()) {
			return;
		}
		if (streamid % 2 == 1) {
			--this->numReservedClientStreams;
			if (!Http2Connection::$assertionsDisabled && !(this->numReservedClientStreams >= 0)) {
				$throwNew($AssertionError, $of($$str({"negative client stream count for stream="_s, $$str(streamid)})));
			}
		} else {
			--this->numReservedServerStreams;
			if (!Http2Connection::$assertionsDisabled && !(this->numReservedServerStreams >= 0)) {
				$throwNew($AssertionError, $of($$str({"negative server stream count for stream="_s, $$str(streamid)})));
			}
		}
	}
}

void Http2Connection::closeStream(int32_t streamid) {
	$useLocalCurrentObjectStackCache();
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Closed stream %d"_s, $$new($ObjectArray, {$($of($Integer::valueOf(streamid)))}));
	}
	bool isClient = (streamid % 2) == 1;
	$var($Stream, s, $cast($Stream, $nc(this->streams)->remove($($Integer::valueOf(streamid)))));
	if (s != nullptr) {
		$nc($(client()))->streamUnreference();
	}
	if (s != nullptr && !($instanceOf($Stream$PushedStream, s))) {
		$nc(this->windowController)->removeStream(streamid);
	}
	bool var$0 = finalStream();
	if (var$0 && $nc(this->streams)->isEmpty()) {
		close();
	}
}

void Http2Connection::handleWindowUpdate($WindowUpdateFrame* f) {
	int32_t amount = $nc(f)->getUpdate();
	if (amount <= 0) {
	} else {
		bool success = $nc(this->windowController)->increaseConnectionWindow(amount);
		if (!success) {
			protocolError($ErrorFrame::FLOW_CONTROL_ERROR);
		}
	}
}

void Http2Connection::protocolError(int32_t errorCode) {
	protocolError(errorCode, nullptr);
}

void Http2Connection::protocolError(int32_t errorCode, $String* msg) {
	$useLocalCurrentObjectStackCache();
	$var($GoAwayFrame, frame, $new($GoAwayFrame, 0, errorCode));
	sendFrame(frame);
	shutdown($$new($IOException, $$str({"protocol error"_s, (msg == nullptr ? ""_s : ($$str({": "_s, msg})))})));
}

void Http2Connection::handleSettings($SettingsFrame* frame) {
	if (!Http2Connection::$assertionsDisabled && !($nc(frame)->streamid() == 0)) {
		$throwNew($AssertionError);
	}
	if (!$nc(frame)->getFlag($SettingsFrame::ACK)) {
		int32_t newWindowSize = frame->getParameter(4);
		if (newWindowSize != -1) {
			int32_t oldWindowSize = $nc(this->serverSettings)->getParameter(4);
			int32_t diff = newWindowSize - oldWindowSize;
			if (diff != 0) {
				$nc(this->windowController)->adjustActiveStreams(diff);
			}
		}
		$nc(this->serverSettings)->update(frame);
		sendFrame($$new($SettingsFrame, $SettingsFrame::ACK));
	}
}

void Http2Connection::handlePing($PingFrame* frame) {
	$nc(frame)->setFlag($PingFrame::ACK);
	sendUnorderedFrame(frame);
}

void Http2Connection::handleGoAway($GoAwayFrame* frame) {
	$useLocalCurrentObjectStackCache();
	shutdown($$new($IOException, $$str({$($String::valueOf($($of($nc($($nc(this->connection)->channel()))->getLocalAddress())))), ": GOAWAY received"_s})));
}

int32_t Http2Connection::getMaxSendFrameSize() {
	int32_t param = $nc(this->serverSettings)->getParameter(5);
	if (param == -1) {
		param = Http2Connection::DEFAULT_FRAME_SIZE;
	}
	return param;
}

int32_t Http2Connection::getMaxReceiveFrameSize() {
	return $nc(this->clientSettings)->getParameter(5);
}

void Http2Connection::sendConnectionPreface() {
	$useLocalCurrentObjectStackCache();
	$Log::logTrace("{0}: start sending connection preface to {1}"_s, $$new($ObjectArray, {
		$($of($nc($($nc(this->connection)->channel()))->getLocalAddress())),
		$($of($nc(this->connection)->address()))
	}));
	$var($SettingsFrame, sf, $new($SettingsFrame, this->clientSettings));
	$var($ByteBuffer, buf, $nc(this->framesEncoder)->encodeConnectionPreface(Http2Connection::PREFACE_BYTES, sf));
	$Log::logFrames(sf, "OUT"_s);
	$var($HttpConnection$HttpPublisher, publisher, this->publisher());
	$nc(publisher)->enqueueUnordered($($List::of($of(buf))));
	publisher->signalEnqueued();
	$nc(this->framesController)->markPrefaceSent();
	$Log::logTrace("PREFACE_BYTES sent"_s, $$new($ObjectArray, 0));
	$Log::logTrace("Settings Frame sent"_s, $$new($ObjectArray, 0));
	int32_t len = $nc(this->windowUpdater)->initialWindowSize - 0x0000FFFF;
	if (len != 0) {
		if ($Log::channel()) {
			$Log::logChannel("Sending initial connection window update frame: {0} ({1} - {2})"_s, $$new($ObjectArray, {
				$($of($Integer::valueOf(len))),
				$($of($Integer::valueOf($nc(this->windowUpdater)->initialWindowSize))),
				$($of($Integer::valueOf(0x0000FFFF)))
			}));
		}
		$nc(this->windowUpdater)->sendWindowUpdate(len);
	}
	$Log::logTrace("finished sending connection preface"_s, $$new($ObjectArray, 0));
	if ($nc(this->debug)->on()) {
		$nc(this->debug)->log("Triggering processing of buffered data after sending connection preface"_s);
	}
	$nc(this->subscriber)->onNext($($List::of($of(Http2Connection::EMPTY_TRIGGER))));
}

$Stream* Http2Connection::getStream(int32_t streamid) {
	return $cast($Stream, $nc(this->streams)->get($($Integer::valueOf(streamid))));
}

$Stream* Http2Connection::createStream($Exchange* exchange) {
	$var($Stream, stream, $new($Stream, this, exchange, this->windowController));
	return stream;
}

$Stream$PushedStream* Http2Connection::createPushStream($Stream* parent, $Exchange* pushEx) {
	$var($PushGroup, pg, $nc($nc(parent)->exchange)->getPushGroup());
	return $new($Stream$PushedStream, pg, this, pushEx);
}

void Http2Connection::putStream($Stream* stream, int32_t streamid) {
	$useLocalCurrentObjectStackCache();
	$nc($(client()))->streamReference();
	$nc(this->streams)->put($($Integer::valueOf(streamid)), stream);
}

$List* Http2Connection::encodeHeaders($OutgoingHeaders* frame) {
	$useLocalCurrentObjectStackCache();
	int32_t bufferSize = $Math::min($Math::max(getMaxSendFrameSize(), 1024), Http2Connection::DEFAULT_FRAME_SIZE);
	$var($List, buffers, encodeHeadersImpl(bufferSize, $$new($HttpHeadersArray, {
		$($nc(($cast($Stream, $($nc(frame)->getAttachment()))))->getRequestPseudoHeaders()),
		$(frame->getUserHeaders()),
		$(frame->getSystemHeaders())
	})));
	$var($List, frames, $new($ArrayList, $nc(buffers)->size()));
	$var($Iterator, bufIterator, $nc(buffers)->iterator());
	int32_t var$0 = $nc(frame)->streamid();
	int32_t var$1 = frame->getFlags();
	$var($HeaderFrame, oframe, $new($HeadersFrame, var$0, var$1, $cast($ByteBuffer, $($nc(bufIterator)->next()))));
	frames->add(oframe);
	while ($nc(bufIterator)->hasNext()) {
		int32_t var$2 = $nc(frame)->streamid();
		$assign(oframe, $new($ContinuationFrame, var$2, $cast($ByteBuffer, $(bufIterator->next()))));
		frames->add(oframe);
	}
	oframe->setFlag($HeaderFrame::END_HEADERS);
	return frames;
}

$ByteBuffer* Http2Connection::getHeaderBuffer(int32_t size) {
	$var($ByteBuffer, buf, $ByteBuffer::allocate(size));
	$nc(buf)->limit(size);
	return buf;
}

$List* Http2Connection::encodeHeadersImpl(int32_t bufferSize, $HttpHeadersArray* headers) {
	$useLocalCurrentObjectStackCache();
	$var($ByteBuffer, buffer, getHeaderBuffer(bufferSize));
	$var($List, buffers, $new($ArrayList));
	{
		$var($HttpHeadersArray, arr$, headers);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			$var($HttpHeaders, header, arr$->get(i$));
			{
				{
					$var($Iterator, i$, $nc($($nc($($nc(header)->map()))->entrySet()))->iterator());
					for (; $nc(i$)->hasNext();) {
						$var($Map$Entry, e, $cast($Map$Entry, i$->next()));
						{
							$init($Locale);
							$var($String, lKey, $nc(($cast($String, $($nc(e)->getKey()))))->toLowerCase($Locale::US));
							$var($List, values, $cast($List, e->getValue()));
							{
								$var($Iterator, i$, $nc(values)->iterator());
								for (; $nc(i$)->hasNext();) {
									$var($String, value, $cast($String, i$->next()));
									{
										$nc(this->hpackOut)->header(lKey, value);
										while (!$nc(this->hpackOut)->encode(buffer)) {
											$nc(buffer)->flip();
											buffers->add(buffer);
											$assign(buffer, getHeaderBuffer(bufferSize));
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
	$nc(buffer)->flip();
	buffers->add(buffer);
	return buffers;
}

$List* Http2Connection::encodeHeaders($OutgoingHeaders* oh, $Stream* stream) {
	$useLocalCurrentObjectStackCache();
	$nc(oh)->streamid($nc(stream)->streamid);
	if ($Log::headers()) {
		$var($StringBuilder, sb, $new($StringBuilder, "HEADERS FRAME (stream="_s));
		sb->append($nc(stream)->streamid)->append(")\n"_s);
		$Log::dumpHeaders(sb, "    "_s, $($nc(($cast($Stream, $(oh->getAttachment()))))->getRequestPseudoHeaders()));
		$Log::dumpHeaders(sb, "    "_s, $(oh->getSystemHeaders()));
		$Log::dumpHeaders(sb, "    "_s, $(oh->getUserHeaders()));
		$Log::logHeaders($(sb->toString()), $$new($ObjectArray, 0));
	}
	$var($List, frames, encodeHeaders(oh));
	return encodeFrames(frames);
}

$List* Http2Connection::encodeFrames($List* frames) {
	if ($Log::frames()) {
		$nc(frames)->forEach(static_cast<$Consumer*>($$new(Http2Connection$$Lambda$lambda$encodeFrames$9$12)));
	}
	return $nc(this->framesEncoder)->encodeFrames(frames);
}

$Stream* Http2Connection::registerNewStream($OutgoingHeaders* oh) {
	$useLocalCurrentObjectStackCache();
	$var($Stream, stream, $cast($Stream, $nc(oh)->getAttachment()));
	if (!Http2Connection::$assertionsDisabled && !($nc(stream)->streamid == 0)) {
		$throwNew($AssertionError);
	}
	int32_t streamid = this->nextstreamid;
	if ($nc(stream)->registerStream(streamid, false)) {
		this->nextstreamid += 2;
		$nc(this->windowController)->registerStream(streamid, getInitialSendWindowSize());
		return stream;
	} else {
		stream->cancelImpl($$new($IOException, "Request cancelled"_s));
		bool var$0 = finalStream();
		if (var$0 && $nc(this->streams)->isEmpty()) {
			close();
		}
		return nullptr;
	}
}

void Http2Connection::sendFrame($Http2Frame* frame) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($HttpConnection$HttpPublisher, publisher, this->publisher());
		$synchronized(this->sendlock) {
			if ($instanceOf($OutgoingHeaders, frame)) {
				$var($OutgoingHeaders, oh, $cast($OutgoingHeaders, frame));
				$var($Stream, stream, registerNewStream(oh));
				if (stream != nullptr) {
					$nc(publisher)->enqueue($(encodeHeaders(oh, stream)));
				}
			} else {
				$nc(publisher)->enqueue($(encodeFrame(frame)));
			}
		}
		$nc(publisher)->signalEnqueued();
	} catch ($IOException& e) {
		if (!this->closed) {
			$Log::logError(e);
			shutdown(e);
		}
	}
}

$List* Http2Connection::encodeFrame($Http2Frame* frame) {
	$Log::logFrames(frame, "OUT"_s);
	return $nc(this->framesEncoder)->encodeFrame(frame);
}

void Http2Connection::sendDataFrame($DataFrame* frame) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($HttpConnection$HttpPublisher, publisher, this->publisher());
		$nc(publisher)->enqueue($(encodeFrame(frame)));
		publisher->signalEnqueued();
	} catch ($IOException& e) {
		if (!this->closed) {
			$Log::logError(e);
			shutdown(e);
		}
	}
}

void Http2Connection::sendUnorderedFrame($Http2Frame* frame) {
	$useLocalCurrentObjectStackCache();
	try {
		$var($HttpConnection$HttpPublisher, publisher, this->publisher());
		$nc(publisher)->enqueueUnordered($(encodeFrame(frame)));
		publisher->signalEnqueued();
	} catch ($IOException& e) {
		if (!this->closed) {
			$Log::logError(e);
			shutdown(e);
		}
	}
}

bool Http2Connection::isActive() {
	$synchronized(this) {
		return this->numReservedClientStreams > 0 || this->numReservedServerStreams > 0;
	}
}

$String* Http2Connection::toString() {
	return dbgString();
}

$String* Http2Connection::dbgString() {
	return $str({"Http2Connection("_s, $($nc(this->connection)->getConnectionFlow()), ")"_s});
}

void Http2Connection::lambda$encodeFrames$9($HeaderFrame* f) {
	$init(Http2Connection);
	$Log::logFrames(f, "OUT"_s);
}

$String* Http2Connection::lambda$processFrame$8($Http2Frame* frame) {
	$init(Http2Connection);
	return $str({"Reset stream: "_s, $($nc(($cast($MalformedFrame, frame)))->getMessage())});
}

$String* Http2Connection::lambda$shutdown$7($Throwable* t) {
	return $str({"Shutting down h2c (closed="_s, $$str(this->closed), "): "_s, t});
}

$String* Http2Connection::lambda$asyncReceive$6(int64_t c, $ByteBuffer* b) {
	$init(Http2Connection);
	$useLocalCurrentObjectStackCache();
	return $str({"H2 Receiving Initial("_s, $$str(c), "): "_s, $$str($nc(b)->remaining())});
}

void Http2Connection::lambda$checkSSLConfig$5($AbstractAsyncSSLConnection* aconn, $String* r, $Throwable* t) {
	$init(Http2Connection);
	if (t != nullptr && $instanceOf($SSLException, t)) {
		$nc(aconn)->close();
	}
}

$CompletableFuture* Http2Connection::lambda$checkSSLConfig$4($AbstractAsyncSSLConnection* aconn, $String* alpn) {
	$init(Http2Connection);
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, cf, $new($MinimalFuture));
	$var($SSLEngine, engine, $nc(aconn)->getEngine());
	$var($String, engineAlpn, $nc(engine)->getApplicationProtocol());
	if (!Http2Connection::$assertionsDisabled && !$Objects::equals(alpn, engineAlpn)) {
		$throwNew($AssertionError, $($of("alpn: %s, engine: %s"_s->formatted($$new($ObjectArray, {
			$of(alpn),
			$of(engineAlpn)
		})))));
	}
	$nc(Http2Connection::DEBUG_LOGGER)->log("checkSSLConfig: alpn: %s"_s, $$new($ObjectArray, {$of(alpn)}));
	if (alpn == nullptr || !$nc(alpn)->equals("h2"_s)) {
		$var($String, msg, nullptr);
		if (alpn == nullptr) {
			$Log::logSSL("ALPN not supported"_s, $$new($ObjectArray, 0));
			$assign(msg, "ALPN not supported"_s);
		} else {
			{
				$var($String, s21471$, alpn);
				int32_t tmp21471$ = -1;
				switch (s21471$->hashCode()) {
				case 0:
					{
						if (s21471$->equals(""_s)) {
							tmp21471$ = 0;
						}
						break;
					}
				case (int32_t)0xF7FF9FAD:
					{
						if (s21471$->equals("http/1.1"_s)) {
							tmp21471$ = 1;
						}
						break;
					}
				}
				switch (tmp21471$) {
				case 0:
					{
						$Log::logSSL($assign(msg, "No ALPN negotiated"_s), $$new($ObjectArray, 0));
						break;
					}
				case 1:
					{
						$Log::logSSL($assign(msg, "HTTP/1.1 ALPN returned"_s), $$new($ObjectArray, 0));
						break;
					}
				default:
					{
						$Log::logSSL($assign(msg, $str({"Unexpected ALPN: "_s, alpn})), $$new($ObjectArray, 0));
						cf->completeExceptionally($$new($IOException, msg));
					}
				}
			}
		}
		cf->completeExceptionally($$new($Http2Connection$ALPNException, msg, aconn));
		return cf;
	}
	cf->complete(nullptr);
	return cf;
}

$CompletionStage* Http2Connection::lambda$createAsync$3($HttpRequestImpl* request, $Http2ClientImpl* h2client, $AbstractAsyncSSLConnection* connection, Object$* notused) {
	$init(Http2Connection);
	$useLocalCurrentObjectStackCache();
	$var($CompletableFuture, cf, $new($MinimalFuture));
	try {
		$var(Http2Connection, hc, $new(Http2Connection, request, h2client, connection));
		cf->complete(hc);
	} catch ($IOException& e) {
		cf->completeExceptionally(e);
	}
	return cf;
}

$CompletionStage* Http2Connection::lambda$createAsync$2($AbstractAsyncSSLConnection* connection, $Void* unused) {
	$init(Http2Connection);
	return checkSSLConfig(connection);
}

$CompletionStage* Http2Connection::lambda$createAsync$1($AbstractAsyncSSLConnection* connection, $Void* unused) {
	$init(Http2Connection);
	return $nc(connection)->finishConnect();
}

Http2Connection* Http2Connection::lambda$createAsync$0($HttpConnection* connection, $Http2ClientImpl* client2, $Exchange* exchange, $Supplier* initial) {
	$init(Http2Connection);
	return $new(Http2Connection, connection, client2, exchange, initial);
}

void clinit$Http2Connection($Class* class$) {
	$assignStatic(Http2Connection::CLIENT_PREFACE, "PRI * HTTP/2.0\r\n\r\nSM\r\n\r\n"_s);
	Http2Connection::$assertionsDisabled = !Http2Connection::class$->desiredAssertionStatus();
	$init($Utils);
	$assignStatic(Http2Connection::DEBUG_LOGGER, $Utils::getDebugLogger(static_cast<$Supplier*>($$new(Http2Connection$$Lambda$toString$1, static_cast<$String*>("Http2Connection"_s))), $Utils::DEBUG));
	$assignStatic(Http2Connection::EMPTY_TRIGGER, $ByteBuffer::allocate(0));
	$init($StandardCharsets);
	$assignStatic(Http2Connection::PREFACE_BYTES, $nc(Http2Connection::CLIENT_PREFACE)->getBytes($StandardCharsets::ISO_8859_1));
}

Http2Connection::Http2Connection() {
}

$Class* Http2Connection::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http2Connection$$Lambda$dbgString::classInfo$.name)) {
			return Http2Connection$$Lambda$dbgString::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$toString$1::classInfo$.name)) {
			return Http2Connection$$Lambda$toString$1::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$processFrame$2::classInfo$.name)) {
			return Http2Connection$$Lambda$processFrame$2::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$lambda$createAsync$0$3::classInfo$.name)) {
			return Http2Connection$$Lambda$lambda$createAsync$0$3::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$lambda$createAsync$1$4::classInfo$.name)) {
			return Http2Connection$$Lambda$lambda$createAsync$1$4::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$lambda$createAsync$2$5::classInfo$.name)) {
			return Http2Connection$$Lambda$lambda$createAsync$2$5::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$lambda$createAsync$3$6::classInfo$.name)) {
			return Http2Connection$$Lambda$lambda$createAsync$3$6::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$lambda$checkSSLConfig$4$7::classInfo$.name)) {
			return Http2Connection$$Lambda$lambda$checkSSLConfig$4$7::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$lambda$checkSSLConfig$5$8::classInfo$.name)) {
			return Http2Connection$$Lambda$lambda$checkSSLConfig$5$8::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$lambda$asyncReceive$6$9::classInfo$.name)) {
			return Http2Connection$$Lambda$lambda$asyncReceive$6$9::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$lambda$shutdown$7$10::classInfo$.name)) {
			return Http2Connection$$Lambda$lambda$shutdown$7$10::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$lambda$processFrame$8$11::classInfo$.name)) {
			return Http2Connection$$Lambda$lambda$processFrame$8$11::load$(name, initialize);
		}
		if (name->equals(Http2Connection$$Lambda$lambda$encodeFrames$9$12::classInfo$.name)) {
			return Http2Connection$$Lambda$lambda$encodeFrames$9$12::load$(name, initialize);
		}
	}
	$loadClass(Http2Connection, name, initialize, &_Http2Connection_ClassInfo_, clinit$Http2Connection, allocate$Http2Connection);
	return class$;
}

$Class* Http2Connection::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk