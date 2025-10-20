#include <java.net.http.h>

#include <java.base.h>
#include <java/lang/ClassEntry.h>
#include <java/lang/Library.h>
#include <java/lang/ModuleInfo.h>
#include <java/lang/ResourceEntry.h>
#include <jcpp.h>
#include <module-info>

#include <java/net/http/HttpClient.h>
#include <java/net/http/HttpClient$Builder.h>
#include <java/net/http/HttpClient$Redirect.h>
#include <java/net/http/HttpClient$Version.h>
#include <java/net/http/HttpConnectTimeoutException.h>
#include <java/net/http/HttpHeaders.h>
#include <java/net/http/HttpRequest.h>
#include <java/net/http/HttpRequest$BodyPublisher.h>
#include <java/net/http/HttpRequest$BodyPublishers.h>
#include <java/net/http/HttpRequest$Builder.h>
#include <java/net/http/HttpResponse.h>
#include <java/net/http/HttpResponse$BodyHandler.h>
#include <java/net/http/HttpResponse$BodyHandlers.h>
#include <java/net/http/HttpResponse$BodySubscriber.h>
#include <java/net/http/HttpResponse$BodySubscribers.h>
#include <java/net/http/HttpResponse$PushPromiseHandler.h>
#include <java/net/http/HttpResponse$ResponseInfo.h>
#include <java/net/http/HttpTimeoutException.h>
#include <java/net/http/WebSocket.h>
#include <java/net/http/WebSocket$Builder.h>
#include <java/net/http/WebSocket$Listener.h>
#include <java/net/http/WebSocketHandshakeException.h>
#include <jdk/internal/net/http/AbstractAsyncSSLConnection.h>
#include <jdk/internal/net/http/AbstractSubscription.h>
#include <jdk/internal/net/http/AsyncEvent.h>
#include <jdk/internal/net/http/AsyncSSLConnection.h>
#include <jdk/internal/net/http/AsyncSSLTunnelConnection.h>
#include <jdk/internal/net/http/AsyncTriggerEvent.h>
#include <jdk/internal/net/http/AuthenticationFilter.h>
#include <jdk/internal/net/http/AuthenticationFilter$AuthInfo.h>
#include <jdk/internal/net/http/AuthenticationFilter$Cache.h>
#include <jdk/internal/net/http/AuthenticationFilter$CacheEntry.h>
#include <jdk/internal/net/http/BufferingSubscriber.h>
#include <jdk/internal/net/http/BufferingSubscriber$DownstreamSubscription.h>
#include <jdk/internal/net/http/BufferingSubscriber$DownstreamSubscription$PushDemandedTask.h>
#include <jdk/internal/net/http/ConnectionPool.h>
#include <jdk/internal/net/http/ConnectionPool$CacheKey.h>
#include <jdk/internal/net/http/ConnectionPool$CleanupTrigger.h>
#include <jdk/internal/net/http/ConnectionPool$ExpiryEntry.h>
#include <jdk/internal/net/http/ConnectionPool$ExpiryList.h>
#include <jdk/internal/net/http/CookieFilter.h>
#include <jdk/internal/net/http/Exchange.h>
#include <jdk/internal/net/http/Exchange$ConnectionAborter.h>
#include <jdk/internal/net/http/ExchangeImpl.h>
#include <jdk/internal/net/http/FilterFactory.h>
#include <jdk/internal/net/http/HeaderFilter.h>
#include <jdk/internal/net/http/HeaderParser.h>
#include <jdk/internal/net/http/HeaderParser$ParserIterator.h>
#include <jdk/internal/net/http/Http1AsyncReceiver.h>
#include <jdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegate.h>
#include <jdk/internal/net/http/Http1AsyncReceiver$Http1AsyncDelegateSubscription.h>
#include <jdk/internal/net/http/Http1AsyncReceiver$Http1TubeSubscriber.h>
#include <jdk/internal/net/http/Http1Exchange.h>
#include <jdk/internal/net/http/Http1Exchange$1.h>
#include <jdk/internal/net/http/Http1Exchange$DataPair.h>
#include <jdk/internal/net/http/Http1Exchange$Http1BodySubscriber.h>
#include <jdk/internal/net/http/Http1Exchange$Http1BodySubscriber$1.h>
#include <jdk/internal/net/http/Http1Exchange$Http1Publisher.h>
#include <jdk/internal/net/http/Http1Exchange$Http1Publisher$Http1WriteSubscription.h>
#include <jdk/internal/net/http/Http1Exchange$Http1Publisher$WriteTask.h>
#include <jdk/internal/net/http/Http1Exchange$State.h>
#include <jdk/internal/net/http/Http1HeaderParser.h>
#include <jdk/internal/net/http/Http1HeaderParser$1.h>
#include <jdk/internal/net/http/Http1HeaderParser$State.h>
#include <jdk/internal/net/http/Http1Request.h>
#include <jdk/internal/net/http/Http1Request$FixedContentSubscriber.h>
#include <jdk/internal/net/http/Http1Request$StreamSubscriber.h>
#include <jdk/internal/net/http/Http1Response.h>
#include <jdk/internal/net/http/Http1Response$1.h>
#include <jdk/internal/net/http/Http1Response$2.h>
#include <jdk/internal/net/http/Http1Response$BodyReader.h>
#include <jdk/internal/net/http/Http1Response$ClientRefCountTracker.h>
#include <jdk/internal/net/http/Http1Response$HeadersReader.h>
#include <jdk/internal/net/http/Http1Response$Http1BodySubscriber.h>
#include <jdk/internal/net/http/Http1Response$Receiver.h>
#include <jdk/internal/net/http/Http1Response$State.h>
#include <jdk/internal/net/http/Http2ClientImpl.h>
#include <jdk/internal/net/http/Http2Connection.h>
#include <jdk/internal/net/http/Http2Connection$ALPNException.h>
#include <jdk/internal/net/http/Http2Connection$ConnectionWindowUpdateSender.h>
#include <jdk/internal/net/http/Http2Connection$FramesController.h>
#include <jdk/internal/net/http/Http2Connection$HeaderDecoder.h>
#include <jdk/internal/net/http/Http2Connection$Http2TubeSubscriber.h>
#include <jdk/internal/net/http/Http2Connection$ValidatingHeadersConsumer.h>
#include <jdk/internal/net/http/HttpClientBuilderImpl.h>
#include <jdk/internal/net/http/HttpClientFacade.h>
#include <jdk/internal/net/http/HttpClientImpl.h>
#include <jdk/internal/net/http/HttpClientImpl$DefaultThreadFactory.h>
#include <jdk/internal/net/http/HttpClientImpl$DelegatingExecutor.h>
#include <jdk/internal/net/http/HttpClientImpl$HttpClientTracker.h>
#include <jdk/internal/net/http/HttpClientImpl$SSLDirectBufferSupplier.h>
#include <jdk/internal/net/http/HttpClientImpl$SelectorAttachment.h>
#include <jdk/internal/net/http/HttpClientImpl$SelectorManager.h>
#include <jdk/internal/net/http/HttpClientImpl$SingleFacadeFactory.h>
#include <jdk/internal/net/http/HttpConnection.h>
#include <jdk/internal/net/http/HttpConnection$HttpPublisher.h>
#include <jdk/internal/net/http/HttpConnection$PlainHttpPublisher.h>
#include <jdk/internal/net/http/HttpConnection$PlainHttpPublisher$HttpWriteSubscription.h>
#include <jdk/internal/net/http/HttpConnection$TrailingOperations.h>
#include <jdk/internal/net/http/HttpRequestBuilderImpl.h>
#include <jdk/internal/net/http/HttpRequestImpl.h>
#include <jdk/internal/net/http/HttpResponseImpl.h>
#include <jdk/internal/net/http/HttpResponseImpl$RawChannelProvider.h>
#include <jdk/internal/net/http/ImmutableHttpRequest.h>
#include <jdk/internal/net/http/LineSubscriberAdapter.h>
#include <jdk/internal/net/http/LineSubscriberAdapter$LineSubscription.h>
#include <jdk/internal/net/http/MultiExchange.h>
#include <jdk/internal/net/http/MultiExchange$CancelableRef.h>
#include <jdk/internal/net/http/MultiExchange$ConnectTimeoutTracker.h>
#include <jdk/internal/net/http/MultiExchange$NullSubscription.h>
#include <jdk/internal/net/http/PlainHttpConnection.h>
#include <jdk/internal/net/http/PlainHttpConnection$ConnectEvent.h>
#include <jdk/internal/net/http/PlainHttpConnection$ConnectState.h>
#include <jdk/internal/net/http/PlainHttpConnection$ConnectTimerEvent.h>
#include <jdk/internal/net/http/PlainProxyConnection.h>
#include <jdk/internal/net/http/PlainTunnelingConnection.h>
#include <jdk/internal/net/http/PrivilegedExecutor.h>
#include <jdk/internal/net/http/PrivilegedExecutor$PrivilegedRunnable.h>
#include <jdk/internal/net/http/ProxyAuthenticationRequired.h>
#include <jdk/internal/net/http/PullPublisher.h>
#include <jdk/internal/net/http/PullPublisher$Subscription.h>
#include <jdk/internal/net/http/PullPublisher$Subscription$PullTask.h>
#include <jdk/internal/net/http/PushGroup.h>
#include <jdk/internal/net/http/PushGroup$Acceptor.h>
#include <jdk/internal/net/http/PushGroup$AcceptorImpl.h>
#include <jdk/internal/net/http/RawChannelTube.h>
#include <jdk/internal/net/http/RawChannelTube$CleanupChecker.h>
#include <jdk/internal/net/http/RawChannelTube$ReadSubscriber.h>
#include <jdk/internal/net/http/RawChannelTube$WritePublisher.h>
#include <jdk/internal/net/http/RawChannelTube$WriteSubscription.h>
#include <jdk/internal/net/http/RedirectFilter.h>
#include <jdk/internal/net/http/RedirectFilter$1.h>
#include <jdk/internal/net/http/RequestPublishers.h>
#include <jdk/internal/net/http/RequestPublishers$AggregatePublisher.h>
#include <jdk/internal/net/http/RequestPublishers$AggregateSubscription.h>
#include <jdk/internal/net/http/RequestPublishers$ByteArrayPublisher.h>
#include <jdk/internal/net/http/RequestPublishers$EmptyPublisher.h>
#include <jdk/internal/net/http/RequestPublishers$FilePublisher.h>
#include <jdk/internal/net/http/RequestPublishers$InputStreamPublisher.h>
#include <jdk/internal/net/http/RequestPublishers$IterablePublisher.h>
#include <jdk/internal/net/http/RequestPublishers$IterablePublisher$ByteBufferIterator.h>
#include <jdk/internal/net/http/RequestPublishers$PublisherAdapter.h>
#include <jdk/internal/net/http/RequestPublishers$StreamIterator.h>
#include <jdk/internal/net/http/RequestPublishers$StringPublisher.h>
#include <jdk/internal/net/http/Response.h>
#include <jdk/internal/net/http/ResponseBodyHandlers.h>
#include <jdk/internal/net/http/ResponseBodyHandlers$FileDownloadBodyHandler.h>
#include <jdk/internal/net/http/ResponseBodyHandlers$PathBodyHandler.h>
#include <jdk/internal/net/http/ResponseBodyHandlers$PushPromisesHandlerWithMap.h>
#include <jdk/internal/net/http/ResponseContent.h>
#include <jdk/internal/net/http/ResponseContent$BodyParser.h>
#include <jdk/internal/net/http/ResponseContent$ChunkState.h>
#include <jdk/internal/net/http/ResponseContent$ChunkedBodyParser.h>
#include <jdk/internal/net/http/ResponseContent$FixedLengthBodyParser.h>
#include <jdk/internal/net/http/ResponseContent$UnknownLengthBodyParser.h>
#include <jdk/internal/net/http/ResponseInfoImpl.h>
#include <jdk/internal/net/http/ResponseSubscribers.h>
#include <jdk/internal/net/http/ResponseSubscribers$ByteArraySubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$ConsumerSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$HttpResponseInputStream.h>
#include <jdk/internal/net/http/ResponseSubscribers$MappingSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$NullSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$PathSubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$1.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriberRef.h>
#include <jdk/internal/net/http/ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef.h>
#include <jdk/internal/net/http/ResponseSubscribers$SubscriberAdapter.h>
#include <jdk/internal/net/http/ResponseSubscribers$TrustedSubscriber.h>
#include <jdk/internal/net/http/ResponseTimerEvent.h>
#include <jdk/internal/net/http/SocketTube.h>
#include <jdk/internal/net/http/SocketTube$BufferSource.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$InternalReadSubscription.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$ReadEvent.h>
#include <jdk/internal/net/http/SocketTube$InternalReadPublisher$ReadSubscription.h>
#include <jdk/internal/net/http/SocketTube$InternalWriteSubscriber.h>
#include <jdk/internal/net/http/SocketTube$InternalWriteSubscriber$WriteEvent.h>
#include <jdk/internal/net/http/SocketTube$InternalWriteSubscriber$WriteSubscription.h>
#include <jdk/internal/net/http/SocketTube$SSLDirectBufferSource.h>
#include <jdk/internal/net/http/SocketTube$SliceBufferSource.h>
#include <jdk/internal/net/http/SocketTube$SocketFlowEvent.h>
#include <jdk/internal/net/http/SocketTube$SocketFlowTask.h>
#include <jdk/internal/net/http/Stream.h>
#include <jdk/internal/net/http/Stream$HeadersConsumer.h>
#include <jdk/internal/net/http/Stream$PushedStream.h>
#include <jdk/internal/net/http/Stream$RequestSubscriber.h>
#include <jdk/internal/net/http/Stream$StreamWindowUpdateSender.h>
#include <jdk/internal/net/http/TimeoutEvent.h>
#include <jdk/internal/net/http/WindowController.h>
#include <jdk/internal/net/http/WindowUpdateSender.h>
#include <jdk/internal/net/http/common/BufferSupplier.h>
#include <jdk/internal/net/http/common/Cancelable.h>
#include <jdk/internal/net/http/common/ConnectionExpiredException.h>
#include <jdk/internal/net/http/common/DebugLogger.h>
#include <jdk/internal/net/http/common/Demand.h>
#include <jdk/internal/net/http/common/FlowTube.h>
#include <jdk/internal/net/http/common/FlowTube$AbstractTubePublisher.h>
#include <jdk/internal/net/http/common/FlowTube$AbstractTubePublisher$TubePublisherWrapper.h>
#include <jdk/internal/net/http/common/FlowTube$AbstractTubeSubscriber.h>
#include <jdk/internal/net/http/common/FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper.h>
#include <jdk/internal/net/http/common/FlowTube$TubePublisher.h>
#include <jdk/internal/net/http/common/FlowTube$TubeSubscriber.h>
#include <jdk/internal/net/http/common/HttpHeadersBuilder.h>
#include <jdk/internal/net/http/common/ImmutableExtendedSSLSession.h>
#include <jdk/internal/net/http/common/ImmutableSSLSession.h>
#include <jdk/internal/net/http/common/Log.h>
#include <jdk/internal/net/http/common/Logger.h>
#include <jdk/internal/net/http/common/MinimalFuture.h>
#include <jdk/internal/net/http/common/MinimalFuture$ExceptionalSupplier.h>
#include <jdk/internal/net/http/common/OperationTrackers.h>
#include <jdk/internal/net/http/common/OperationTrackers$Trackable.h>
#include <jdk/internal/net/http/common/OperationTrackers$Tracker.h>
#include <jdk/internal/net/http/common/Pair.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$1.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$EngineResult.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitor.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitor$FinalMonitorable.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Monitorable.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Reader.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Reader$ReaderDownstreamPusher.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Writer.h>
#include <jdk/internal/net/http/common/SSLFlowDelegate$Writer$WriterDownstreamPusher.h>
#include <jdk/internal/net/http/common/SSLTube.h>
#include <jdk/internal/net/http/common/SSLTube$DelegateWrapper.h>
#include <jdk/internal/net/http/common/SSLTube$SSLSubscriberWrapper.h>
#include <jdk/internal/net/http/common/SSLTube$SSLSubscriptionWrapper.h>
#include <jdk/internal/net/http/common/SSLTube$SSLTubeFlowDelegate.h>
#include <jdk/internal/net/http/common/SequentialScheduler.h>
#include <jdk/internal/net/http/common/SequentialScheduler$CompleteRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$DeferredCompleter.h>
#include <jdk/internal/net/http/common/SequentialScheduler$LockingRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$RestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$SchedulableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$SynchronizedRestartableTask.h>
#include <jdk/internal/net/http/common/SequentialScheduler$TryEndDeferredCompleter.h>
#include <jdk/internal/net/http/common/SubscriberWrapper.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$1.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$DownstreamPusher.h>
#include <jdk/internal/net/http/common/SubscriberWrapper$SchedulingAction.h>
#include <jdk/internal/net/http/common/SubscriptionBase.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jdk/internal/net/http/common/Utils$ProxyHeaders.h>
#include <jdk/internal/net/http/common/Utils$ServerName.h>
#include <jdk/internal/net/http/frame/ContinuationFrame.h>
#include <jdk/internal/net/http/frame/DataFrame.h>
#include <jdk/internal/net/http/frame/ErrorFrame.h>
#include <jdk/internal/net/http/frame/FramesDecoder.h>
#include <jdk/internal/net/http/frame/FramesDecoder$FrameProcessor.h>
#include <jdk/internal/net/http/frame/FramesEncoder.h>
#include <jdk/internal/net/http/frame/GoAwayFrame.h>
#include <jdk/internal/net/http/frame/HeaderFrame.h>
#include <jdk/internal/net/http/frame/HeadersFrame.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jdk/internal/net/http/frame/MalformedFrame.h>
#include <jdk/internal/net/http/frame/OutgoingHeaders.h>
#include <jdk/internal/net/http/frame/PingFrame.h>
#include <jdk/internal/net/http/frame/PriorityFrame.h>
#include <jdk/internal/net/http/frame/PushPromiseFrame.h>
#include <jdk/internal/net/http/frame/ResetFrame.h>
#include <jdk/internal/net/http/frame/SettingsFrame.h>
#include <jdk/internal/net/http/frame/WindowUpdateFrame.h>
#include <jdk/internal/net/http/hpack/BinaryRepresentationWriter.h>
#include <jdk/internal/net/http/hpack/BulkSizeUpdateWriter.h>
#include <jdk/internal/net/http/hpack/Decoder.h>
#include <jdk/internal/net/http/hpack/Decoder$1.h>
#include <jdk/internal/net/http/hpack/Decoder$State.h>
#include <jdk/internal/net/http/hpack/DecodingCallback.h>
#include <jdk/internal/net/http/hpack/Encoder.h>
#include <jdk/internal/net/http/hpack/HPACK.h>
#include <jdk/internal/net/http/hpack/HPACK$BufferUpdateConsumer.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger.h>
#include <jdk/internal/net/http/hpack/HPACK$Logger$Level.h>
#include <jdk/internal/net/http/hpack/HPACK$RootLogger.h>
#include <jdk/internal/net/http/hpack/HeaderTable.h>
#include <jdk/internal/net/http/hpack/Huffman.h>
#include <jdk/internal/net/http/hpack/Huffman$Reader.h>
#include <jdk/internal/net/http/hpack/Huffman$Writer.h>
#include <jdk/internal/net/http/hpack/ISO_8859_1.h>
#include <jdk/internal/net/http/hpack/ISO_8859_1$Reader.h>
#include <jdk/internal/net/http/hpack/ISO_8859_1$Writer.h>
#include <jdk/internal/net/http/hpack/IndexNameValueWriter.h>
#include <jdk/internal/net/http/hpack/IndexedWriter.h>
#include <jdk/internal/net/http/hpack/IntegerReader.h>
#include <jdk/internal/net/http/hpack/IntegerWriter.h>
#include <jdk/internal/net/http/hpack/LiteralNeverIndexedWriter.h>
#include <jdk/internal/net/http/hpack/LiteralWithIndexingWriter.h>
#include <jdk/internal/net/http/hpack/LiteralWriter.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman$1.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman$Code.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman$Node.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman$Reader.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman$Writer.h>
#include <jdk/internal/net/http/hpack/QuickHuffman.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$ImmutableNode.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$Node.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$Reader.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$TemporaryNode.h>
#include <jdk/internal/net/http/hpack/QuickHuffman$Writer.h>
#include <jdk/internal/net/http/hpack/SimpleHeaderTable.h>
#include <jdk/internal/net/http/hpack/SimpleHeaderTable$CircularBuffer.h>
#include <jdk/internal/net/http/hpack/SimpleHeaderTable$HeaderField.h>
#include <jdk/internal/net/http/hpack/SizeUpdateWriter.h>
#include <jdk/internal/net/http/hpack/StringReader.h>
#include <jdk/internal/net/http/hpack/StringWriter.h>
#include <jdk/internal/net/http/websocket/BuilderImpl.h>
#include <jdk/internal/net/http/websocket/CheckFailedException.h>
#include <jdk/internal/net/http/websocket/FailWebSocketException.h>
#include <jdk/internal/net/http/websocket/Frame.h>
#include <jdk/internal/net/http/websocket/Frame$Consumer.h>
#include <jdk/internal/net/http/websocket/Frame$HeaderWriter.h>
#include <jdk/internal/net/http/websocket/Frame$Masker.h>
#include <jdk/internal/net/http/websocket/Frame$Opcode.h>
#include <jdk/internal/net/http/websocket/Frame$Reader.h>
#include <jdk/internal/net/http/websocket/MessageDecoder.h>
#include <jdk/internal/net/http/websocket/MessageDecoder$1.h>
#include <jdk/internal/net/http/websocket/MessageEncoder.h>
#include <jdk/internal/net/http/websocket/MessageQueue.h>
#include <jdk/internal/net/http/websocket/MessageQueue$1.h>
#include <jdk/internal/net/http/websocket/MessageQueue$Message.h>
#include <jdk/internal/net/http/websocket/MessageQueue$QueueCallback.h>
#include <jdk/internal/net/http/websocket/MessageQueue$Type.h>
#include <jdk/internal/net/http/websocket/MessageStreamConsumer.h>
#include <jdk/internal/net/http/websocket/OpeningHandshake.h>
#include <jdk/internal/net/http/websocket/OpeningHandshake$Result.h>
#include <jdk/internal/net/http/websocket/RawChannel.h>
#include <jdk/internal/net/http/websocket/RawChannel$Provider.h>
#include <jdk/internal/net/http/websocket/RawChannel$RawEvent.h>
#include <jdk/internal/net/http/websocket/StatusCodes.h>
#include <jdk/internal/net/http/websocket/Transport.h>
#include <jdk/internal/net/http/websocket/TransportFactory.h>
#include <jdk/internal/net/http/websocket/TransportFactoryImpl.h>
#include <jdk/internal/net/http/websocket/TransportImpl.h>
#include <jdk/internal/net/http/websocket/TransportImpl$1.h>
#include <jdk/internal/net/http/websocket/TransportImpl$ChannelState.h>
#include <jdk/internal/net/http/websocket/TransportImpl$ReadEvent.h>
#include <jdk/internal/net/http/websocket/TransportImpl$ReceiveTask.h>
#include <jdk/internal/net/http/websocket/TransportImpl$SendTask.h>
#include <jdk/internal/net/http/websocket/TransportImpl$SendTask$1.h>
#include <jdk/internal/net/http/websocket/TransportImpl$SendTask$2.h>
#include <jdk/internal/net/http/websocket/TransportImpl$WriteEvent.h>
#include <jdk/internal/net/http/websocket/UTF8AccumulatingDecoder.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl$1.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl$ReceiveTask.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl$SignallingMessageConsumer.h>
#include <jdk/internal/net/http/websocket/WebSocketImpl$State.h>
#include <jdk/internal/net/http/websocket/WebSocketRequest.h>

#undef HPACK

#define $classEntry(name, clazz) {name, clazz::load$, $getMark(clazz)}
::java::lang::ClassEntry _java$net$http_classes_[] = {
	$classEntry("java.net.http.HttpClient", ::java::net::http::HttpClient),
	$classEntry("java.net.http.HttpClient$Builder", ::java::net::http::HttpClient$Builder),
	$classEntry("java.net.http.HttpClient$Redirect", ::java::net::http::HttpClient$Redirect),
	$classEntry("java.net.http.HttpClient$Version", ::java::net::http::HttpClient$Version),
	$classEntry("java.net.http.HttpConnectTimeoutException", ::java::net::http::HttpConnectTimeoutException),
	$classEntry("java.net.http.HttpHeaders", ::java::net::http::HttpHeaders),
	$classEntry("java.net.http.HttpRequest", ::java::net::http::HttpRequest),
	$classEntry("java.net.http.HttpRequest$BodyPublisher", ::java::net::http::HttpRequest$BodyPublisher),
	$classEntry("java.net.http.HttpRequest$BodyPublishers", ::java::net::http::HttpRequest$BodyPublishers),
	$classEntry("java.net.http.HttpRequest$Builder", ::java::net::http::HttpRequest$Builder),
	$classEntry("java.net.http.HttpResponse", ::java::net::http::HttpResponse),
	$classEntry("java.net.http.HttpResponse$BodyHandler", ::java::net::http::HttpResponse$BodyHandler),
	$classEntry("java.net.http.HttpResponse$BodyHandlers", ::java::net::http::HttpResponse$BodyHandlers),
	$classEntry("java.net.http.HttpResponse$BodySubscriber", ::java::net::http::HttpResponse$BodySubscriber),
	$classEntry("java.net.http.HttpResponse$BodySubscribers", ::java::net::http::HttpResponse$BodySubscribers),
	$classEntry("java.net.http.HttpResponse$PushPromiseHandler", ::java::net::http::HttpResponse$PushPromiseHandler),
	$classEntry("java.net.http.HttpResponse$ResponseInfo", ::java::net::http::HttpResponse$ResponseInfo),
	$classEntry("java.net.http.HttpTimeoutException", ::java::net::http::HttpTimeoutException),
	$classEntry("java.net.http.WebSocket", ::java::net::http::WebSocket),
	$classEntry("java.net.http.WebSocket$Builder", ::java::net::http::WebSocket$Builder),
	$classEntry("java.net.http.WebSocket$Listener", ::java::net::http::WebSocket$Listener),
	$classEntry("java.net.http.WebSocketHandshakeException", ::java::net::http::WebSocketHandshakeException),
	$classEntry("jdk.internal.net.http.AbstractAsyncSSLConnection", ::jdk::internal::net::http::AbstractAsyncSSLConnection),
	$classEntry("jdk.internal.net.http.AbstractSubscription", ::jdk::internal::net::http::AbstractSubscription),
	$classEntry("jdk.internal.net.http.AsyncEvent", ::jdk::internal::net::http::AsyncEvent),
	$classEntry("jdk.internal.net.http.AsyncSSLConnection", ::jdk::internal::net::http::AsyncSSLConnection),
	$classEntry("jdk.internal.net.http.AsyncSSLTunnelConnection", ::jdk::internal::net::http::AsyncSSLTunnelConnection),
	$classEntry("jdk.internal.net.http.AsyncTriggerEvent", ::jdk::internal::net::http::AsyncTriggerEvent),
	$classEntry("jdk.internal.net.http.AuthenticationFilter", ::jdk::internal::net::http::AuthenticationFilter),
	$classEntry("jdk.internal.net.http.AuthenticationFilter$AuthInfo", ::jdk::internal::net::http::AuthenticationFilter$AuthInfo),
	$classEntry("jdk.internal.net.http.AuthenticationFilter$Cache", ::jdk::internal::net::http::AuthenticationFilter$Cache),
	$classEntry("jdk.internal.net.http.AuthenticationFilter$CacheEntry", ::jdk::internal::net::http::AuthenticationFilter$CacheEntry),
	$classEntry("jdk.internal.net.http.BufferingSubscriber", ::jdk::internal::net::http::BufferingSubscriber),
	$classEntry("jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription", ::jdk::internal::net::http::BufferingSubscriber$DownstreamSubscription),
	$classEntry("jdk.internal.net.http.BufferingSubscriber$DownstreamSubscription$PushDemandedTask", ::jdk::internal::net::http::BufferingSubscriber$DownstreamSubscription$PushDemandedTask),
	$classEntry("jdk.internal.net.http.ConnectionPool", ::jdk::internal::net::http::ConnectionPool),
	$classEntry("jdk.internal.net.http.ConnectionPool$CacheKey", ::jdk::internal::net::http::ConnectionPool$CacheKey),
	$classEntry("jdk.internal.net.http.ConnectionPool$CleanupTrigger", ::jdk::internal::net::http::ConnectionPool$CleanupTrigger),
	$classEntry("jdk.internal.net.http.ConnectionPool$ExpiryEntry", ::jdk::internal::net::http::ConnectionPool$ExpiryEntry),
	$classEntry("jdk.internal.net.http.ConnectionPool$ExpiryList", ::jdk::internal::net::http::ConnectionPool$ExpiryList),
	$classEntry("jdk.internal.net.http.CookieFilter", ::jdk::internal::net::http::CookieFilter),
	$classEntry("jdk.internal.net.http.Exchange", ::jdk::internal::net::http::Exchange),
	$classEntry("jdk.internal.net.http.Exchange$ConnectionAborter", ::jdk::internal::net::http::Exchange$ConnectionAborter),
	$classEntry("jdk.internal.net.http.ExchangeImpl", ::jdk::internal::net::http::ExchangeImpl),
	$classEntry("jdk.internal.net.http.FilterFactory", ::jdk::internal::net::http::FilterFactory),
	$classEntry("jdk.internal.net.http.HeaderFilter", ::jdk::internal::net::http::HeaderFilter),
	$classEntry("jdk.internal.net.http.HeaderParser", ::jdk::internal::net::http::HeaderParser),
	$classEntry("jdk.internal.net.http.HeaderParser$ParserIterator", ::jdk::internal::net::http::HeaderParser$ParserIterator),
	$classEntry("jdk.internal.net.http.Http1AsyncReceiver", ::jdk::internal::net::http::Http1AsyncReceiver),
	$classEntry("jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegate", ::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegate),
	$classEntry("jdk.internal.net.http.Http1AsyncReceiver$Http1AsyncDelegateSubscription", ::jdk::internal::net::http::Http1AsyncReceiver$Http1AsyncDelegateSubscription),
	$classEntry("jdk.internal.net.http.Http1AsyncReceiver$Http1TubeSubscriber", ::jdk::internal::net::http::Http1AsyncReceiver$Http1TubeSubscriber),
	$classEntry("jdk.internal.net.http.Http1Exchange", ::jdk::internal::net::http::Http1Exchange),
	$classEntry("jdk.internal.net.http.Http1Exchange$1", ::jdk::internal::net::http::Http1Exchange$1),
	$classEntry("jdk.internal.net.http.Http1Exchange$DataPair", ::jdk::internal::net::http::Http1Exchange$DataPair),
	$classEntry("jdk.internal.net.http.Http1Exchange$Http1BodySubscriber", ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber),
	$classEntry("jdk.internal.net.http.Http1Exchange$Http1BodySubscriber$1", ::jdk::internal::net::http::Http1Exchange$Http1BodySubscriber$1),
	$classEntry("jdk.internal.net.http.Http1Exchange$Http1Publisher", ::jdk::internal::net::http::Http1Exchange$Http1Publisher),
	$classEntry("jdk.internal.net.http.Http1Exchange$Http1Publisher$Http1WriteSubscription", ::jdk::internal::net::http::Http1Exchange$Http1Publisher$Http1WriteSubscription),
	$classEntry("jdk.internal.net.http.Http1Exchange$Http1Publisher$WriteTask", ::jdk::internal::net::http::Http1Exchange$Http1Publisher$WriteTask),
	$classEntry("jdk.internal.net.http.Http1Exchange$State", ::jdk::internal::net::http::Http1Exchange$State),
	$classEntry("jdk.internal.net.http.Http1HeaderParser", ::jdk::internal::net::http::Http1HeaderParser),
	$classEntry("jdk.internal.net.http.Http1HeaderParser$1", ::jdk::internal::net::http::Http1HeaderParser$1),
	$classEntry("jdk.internal.net.http.Http1HeaderParser$State", ::jdk::internal::net::http::Http1HeaderParser$State),
	$classEntry("jdk.internal.net.http.Http1Request", ::jdk::internal::net::http::Http1Request),
	$classEntry("jdk.internal.net.http.Http1Request$FixedContentSubscriber", ::jdk::internal::net::http::Http1Request$FixedContentSubscriber),
	$classEntry("jdk.internal.net.http.Http1Request$StreamSubscriber", ::jdk::internal::net::http::Http1Request$StreamSubscriber),
	$classEntry("jdk.internal.net.http.Http1Response", ::jdk::internal::net::http::Http1Response),
	$classEntry("jdk.internal.net.http.Http1Response$1", ::jdk::internal::net::http::Http1Response$1),
	$classEntry("jdk.internal.net.http.Http1Response$2", ::jdk::internal::net::http::Http1Response$2),
	$classEntry("jdk.internal.net.http.Http1Response$BodyReader", ::jdk::internal::net::http::Http1Response$BodyReader),
	$classEntry("jdk.internal.net.http.Http1Response$ClientRefCountTracker", ::jdk::internal::net::http::Http1Response$ClientRefCountTracker),
	$classEntry("jdk.internal.net.http.Http1Response$HeadersReader", ::jdk::internal::net::http::Http1Response$HeadersReader),
	$classEntry("jdk.internal.net.http.Http1Response$Http1BodySubscriber", ::jdk::internal::net::http::Http1Response$Http1BodySubscriber),
	$classEntry("jdk.internal.net.http.Http1Response$Receiver", ::jdk::internal::net::http::Http1Response$Receiver),
	$classEntry("jdk.internal.net.http.Http1Response$State", ::jdk::internal::net::http::Http1Response$State),
	$classEntry("jdk.internal.net.http.Http2ClientImpl", ::jdk::internal::net::http::Http2ClientImpl),
	$classEntry("jdk.internal.net.http.Http2Connection", ::jdk::internal::net::http::Http2Connection),
	$classEntry("jdk.internal.net.http.Http2Connection$ALPNException", ::jdk::internal::net::http::Http2Connection$ALPNException),
	$classEntry("jdk.internal.net.http.Http2Connection$ConnectionWindowUpdateSender", ::jdk::internal::net::http::Http2Connection$ConnectionWindowUpdateSender),
	$classEntry("jdk.internal.net.http.Http2Connection$FramesController", ::jdk::internal::net::http::Http2Connection$FramesController),
	$classEntry("jdk.internal.net.http.Http2Connection$HeaderDecoder", ::jdk::internal::net::http::Http2Connection$HeaderDecoder),
	$classEntry("jdk.internal.net.http.Http2Connection$Http2TubeSubscriber", ::jdk::internal::net::http::Http2Connection$Http2TubeSubscriber),
	$classEntry("jdk.internal.net.http.Http2Connection$ValidatingHeadersConsumer", ::jdk::internal::net::http::Http2Connection$ValidatingHeadersConsumer),
	$classEntry("jdk.internal.net.http.HttpClientBuilderImpl", ::jdk::internal::net::http::HttpClientBuilderImpl),
	$classEntry("jdk.internal.net.http.HttpClientFacade", ::jdk::internal::net::http::HttpClientFacade),
	$classEntry("jdk.internal.net.http.HttpClientImpl", ::jdk::internal::net::http::HttpClientImpl),
	$classEntry("jdk.internal.net.http.HttpClientImpl$DefaultThreadFactory", ::jdk::internal::net::http::HttpClientImpl$DefaultThreadFactory),
	$classEntry("jdk.internal.net.http.HttpClientImpl$DelegatingExecutor", ::jdk::internal::net::http::HttpClientImpl$DelegatingExecutor),
	$classEntry("jdk.internal.net.http.HttpClientImpl$HttpClientTracker", ::jdk::internal::net::http::HttpClientImpl$HttpClientTracker),
	$classEntry("jdk.internal.net.http.HttpClientImpl$SSLDirectBufferSupplier", ::jdk::internal::net::http::HttpClientImpl$SSLDirectBufferSupplier),
	$classEntry("jdk.internal.net.http.HttpClientImpl$SelectorAttachment", ::jdk::internal::net::http::HttpClientImpl$SelectorAttachment),
	$classEntry("jdk.internal.net.http.HttpClientImpl$SelectorManager", ::jdk::internal::net::http::HttpClientImpl$SelectorManager),
	$classEntry("jdk.internal.net.http.HttpClientImpl$SingleFacadeFactory", ::jdk::internal::net::http::HttpClientImpl$SingleFacadeFactory),
	$classEntry("jdk.internal.net.http.HttpConnection", ::jdk::internal::net::http::HttpConnection),
	$classEntry("jdk.internal.net.http.HttpConnection$HttpPublisher", ::jdk::internal::net::http::HttpConnection$HttpPublisher),
	$classEntry("jdk.internal.net.http.HttpConnection$PlainHttpPublisher", ::jdk::internal::net::http::HttpConnection$PlainHttpPublisher),
	$classEntry("jdk.internal.net.http.HttpConnection$PlainHttpPublisher$HttpWriteSubscription", ::jdk::internal::net::http::HttpConnection$PlainHttpPublisher$HttpWriteSubscription),
	$classEntry("jdk.internal.net.http.HttpConnection$TrailingOperations", ::jdk::internal::net::http::HttpConnection$TrailingOperations),
	$classEntry("jdk.internal.net.http.HttpRequestBuilderImpl", ::jdk::internal::net::http::HttpRequestBuilderImpl),
	$classEntry("jdk.internal.net.http.HttpRequestImpl", ::jdk::internal::net::http::HttpRequestImpl),
	$classEntry("jdk.internal.net.http.HttpResponseImpl", ::jdk::internal::net::http::HttpResponseImpl),
	$classEntry("jdk.internal.net.http.HttpResponseImpl$RawChannelProvider", ::jdk::internal::net::http::HttpResponseImpl$RawChannelProvider),
	$classEntry("jdk.internal.net.http.ImmutableHttpRequest", ::jdk::internal::net::http::ImmutableHttpRequest),
	$classEntry("jdk.internal.net.http.LineSubscriberAdapter", ::jdk::internal::net::http::LineSubscriberAdapter),
	$classEntry("jdk.internal.net.http.LineSubscriberAdapter$LineSubscription", ::jdk::internal::net::http::LineSubscriberAdapter$LineSubscription),
	$classEntry("jdk.internal.net.http.MultiExchange", ::jdk::internal::net::http::MultiExchange),
	$classEntry("jdk.internal.net.http.MultiExchange$CancelableRef", ::jdk::internal::net::http::MultiExchange$CancelableRef),
	$classEntry("jdk.internal.net.http.MultiExchange$ConnectTimeoutTracker", ::jdk::internal::net::http::MultiExchange$ConnectTimeoutTracker),
	$classEntry("jdk.internal.net.http.MultiExchange$NullSubscription", ::jdk::internal::net::http::MultiExchange$NullSubscription),
	$classEntry("jdk.internal.net.http.PlainHttpConnection", ::jdk::internal::net::http::PlainHttpConnection),
	$classEntry("jdk.internal.net.http.PlainHttpConnection$ConnectEvent", ::jdk::internal::net::http::PlainHttpConnection$ConnectEvent),
	$classEntry("jdk.internal.net.http.PlainHttpConnection$ConnectState", ::jdk::internal::net::http::PlainHttpConnection$ConnectState),
	$classEntry("jdk.internal.net.http.PlainHttpConnection$ConnectTimerEvent", ::jdk::internal::net::http::PlainHttpConnection$ConnectTimerEvent),
	$classEntry("jdk.internal.net.http.PlainProxyConnection", ::jdk::internal::net::http::PlainProxyConnection),
	$classEntry("jdk.internal.net.http.PlainTunnelingConnection", ::jdk::internal::net::http::PlainTunnelingConnection),
	$classEntry("jdk.internal.net.http.PrivilegedExecutor", ::jdk::internal::net::http::PrivilegedExecutor),
	$classEntry("jdk.internal.net.http.PrivilegedExecutor$PrivilegedRunnable", ::jdk::internal::net::http::PrivilegedExecutor$PrivilegedRunnable),
	$classEntry("jdk.internal.net.http.ProxyAuthenticationRequired", ::jdk::internal::net::http::ProxyAuthenticationRequired),
	$classEntry("jdk.internal.net.http.PullPublisher", ::jdk::internal::net::http::PullPublisher),
	$classEntry("jdk.internal.net.http.PullPublisher$Subscription", ::jdk::internal::net::http::PullPublisher$Subscription),
	$classEntry("jdk.internal.net.http.PullPublisher$Subscription$PullTask", ::jdk::internal::net::http::PullPublisher$Subscription$PullTask),
	$classEntry("jdk.internal.net.http.PushGroup", ::jdk::internal::net::http::PushGroup),
	$classEntry("jdk.internal.net.http.PushGroup$Acceptor", ::jdk::internal::net::http::PushGroup$Acceptor),
	$classEntry("jdk.internal.net.http.PushGroup$AcceptorImpl", ::jdk::internal::net::http::PushGroup$AcceptorImpl),
	$classEntry("jdk.internal.net.http.RawChannelTube", ::jdk::internal::net::http::RawChannelTube),
	$classEntry("jdk.internal.net.http.RawChannelTube$CleanupChecker", ::jdk::internal::net::http::RawChannelTube$CleanupChecker),
	$classEntry("jdk.internal.net.http.RawChannelTube$ReadSubscriber", ::jdk::internal::net::http::RawChannelTube$ReadSubscriber),
	$classEntry("jdk.internal.net.http.RawChannelTube$WritePublisher", ::jdk::internal::net::http::RawChannelTube$WritePublisher),
	$classEntry("jdk.internal.net.http.RawChannelTube$WriteSubscription", ::jdk::internal::net::http::RawChannelTube$WriteSubscription),
	$classEntry("jdk.internal.net.http.RedirectFilter", ::jdk::internal::net::http::RedirectFilter),
	$classEntry("jdk.internal.net.http.RedirectFilter$1", ::jdk::internal::net::http::RedirectFilter$1),
	$classEntry("jdk.internal.net.http.RequestPublishers", ::jdk::internal::net::http::RequestPublishers),
	$classEntry("jdk.internal.net.http.RequestPublishers$AggregatePublisher", ::jdk::internal::net::http::RequestPublishers$AggregatePublisher),
	$classEntry("jdk.internal.net.http.RequestPublishers$AggregateSubscription", ::jdk::internal::net::http::RequestPublishers$AggregateSubscription),
	$classEntry("jdk.internal.net.http.RequestPublishers$ByteArrayPublisher", ::jdk::internal::net::http::RequestPublishers$ByteArrayPublisher),
	$classEntry("jdk.internal.net.http.RequestPublishers$EmptyPublisher", ::jdk::internal::net::http::RequestPublishers$EmptyPublisher),
	$classEntry("jdk.internal.net.http.RequestPublishers$FilePublisher", ::jdk::internal::net::http::RequestPublishers$FilePublisher),
	$classEntry("jdk.internal.net.http.RequestPublishers$InputStreamPublisher", ::jdk::internal::net::http::RequestPublishers$InputStreamPublisher),
	$classEntry("jdk.internal.net.http.RequestPublishers$IterablePublisher", ::jdk::internal::net::http::RequestPublishers$IterablePublisher),
	$classEntry("jdk.internal.net.http.RequestPublishers$IterablePublisher$ByteBufferIterator", ::jdk::internal::net::http::RequestPublishers$IterablePublisher$ByteBufferIterator),
	$classEntry("jdk.internal.net.http.RequestPublishers$PublisherAdapter", ::jdk::internal::net::http::RequestPublishers$PublisherAdapter),
	$classEntry("jdk.internal.net.http.RequestPublishers$StreamIterator", ::jdk::internal::net::http::RequestPublishers$StreamIterator),
	$classEntry("jdk.internal.net.http.RequestPublishers$StringPublisher", ::jdk::internal::net::http::RequestPublishers$StringPublisher),
	$classEntry("jdk.internal.net.http.Response", ::jdk::internal::net::http::Response),
	$classEntry("jdk.internal.net.http.ResponseBodyHandlers", ::jdk::internal::net::http::ResponseBodyHandlers),
	$classEntry("jdk.internal.net.http.ResponseBodyHandlers$FileDownloadBodyHandler", ::jdk::internal::net::http::ResponseBodyHandlers$FileDownloadBodyHandler),
	$classEntry("jdk.internal.net.http.ResponseBodyHandlers$PathBodyHandler", ::jdk::internal::net::http::ResponseBodyHandlers$PathBodyHandler),
	$classEntry("jdk.internal.net.http.ResponseBodyHandlers$PushPromisesHandlerWithMap", ::jdk::internal::net::http::ResponseBodyHandlers$PushPromisesHandlerWithMap),
	$classEntry("jdk.internal.net.http.ResponseContent", ::jdk::internal::net::http::ResponseContent),
	$classEntry("jdk.internal.net.http.ResponseContent$BodyParser", ::jdk::internal::net::http::ResponseContent$BodyParser),
	$classEntry("jdk.internal.net.http.ResponseContent$ChunkState", ::jdk::internal::net::http::ResponseContent$ChunkState),
	$classEntry("jdk.internal.net.http.ResponseContent$ChunkedBodyParser", ::jdk::internal::net::http::ResponseContent$ChunkedBodyParser),
	$classEntry("jdk.internal.net.http.ResponseContent$FixedLengthBodyParser", ::jdk::internal::net::http::ResponseContent$FixedLengthBodyParser),
	$classEntry("jdk.internal.net.http.ResponseContent$UnknownLengthBodyParser", ::jdk::internal::net::http::ResponseContent$UnknownLengthBodyParser),
	$classEntry("jdk.internal.net.http.ResponseInfoImpl", ::jdk::internal::net::http::ResponseInfoImpl),
	$classEntry("jdk.internal.net.http.ResponseSubscribers", ::jdk::internal::net::http::ResponseSubscribers),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$ByteArraySubscriber", ::jdk::internal::net::http::ResponseSubscribers$ByteArraySubscriber),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$ConsumerSubscriber", ::jdk::internal::net::http::ResponseSubscribers$ConsumerSubscriber),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$HttpResponseInputStream", ::jdk::internal::net::http::ResponseSubscribers$HttpResponseInputStream),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$MappingSubscriber", ::jdk::internal::net::http::ResponseSubscribers$MappingSubscriber),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$NullSubscriber", ::jdk::internal::net::http::ResponseSubscribers$NullSubscriber),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$PathSubscriber", ::jdk::internal::net::http::ResponseSubscribers$PathSubscriber),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber", ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$1", ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$1),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriberRef", ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$SubscriberRef),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef", ::jdk::internal::net::http::ResponseSubscribers$PublishingBodySubscriber$SubscriptionRef),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$SubscriberAdapter", ::jdk::internal::net::http::ResponseSubscribers$SubscriberAdapter),
	$classEntry("jdk.internal.net.http.ResponseSubscribers$TrustedSubscriber", ::jdk::internal::net::http::ResponseSubscribers$TrustedSubscriber),
	$classEntry("jdk.internal.net.http.ResponseTimerEvent", ::jdk::internal::net::http::ResponseTimerEvent),
	$classEntry("jdk.internal.net.http.SocketTube", ::jdk::internal::net::http::SocketTube),
	$classEntry("jdk.internal.net.http.SocketTube$BufferSource", ::jdk::internal::net::http::SocketTube$BufferSource),
	$classEntry("jdk.internal.net.http.SocketTube$InternalReadPublisher", ::jdk::internal::net::http::SocketTube$InternalReadPublisher),
	$classEntry("jdk.internal.net.http.SocketTube$InternalReadPublisher$InternalReadSubscription", ::jdk::internal::net::http::SocketTube$InternalReadPublisher$InternalReadSubscription),
	$classEntry("jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadEvent", ::jdk::internal::net::http::SocketTube$InternalReadPublisher$ReadEvent),
	$classEntry("jdk.internal.net.http.SocketTube$InternalReadPublisher$ReadSubscription", ::jdk::internal::net::http::SocketTube$InternalReadPublisher$ReadSubscription),
	$classEntry("jdk.internal.net.http.SocketTube$InternalWriteSubscriber", ::jdk::internal::net::http::SocketTube$InternalWriteSubscriber),
	$classEntry("jdk.internal.net.http.SocketTube$InternalWriteSubscriber$WriteEvent", ::jdk::internal::net::http::SocketTube$InternalWriteSubscriber$WriteEvent),
	$classEntry("jdk.internal.net.http.SocketTube$InternalWriteSubscriber$WriteSubscription", ::jdk::internal::net::http::SocketTube$InternalWriteSubscriber$WriteSubscription),
	$classEntry("jdk.internal.net.http.SocketTube$SSLDirectBufferSource", ::jdk::internal::net::http::SocketTube$SSLDirectBufferSource),
	$classEntry("jdk.internal.net.http.SocketTube$SliceBufferSource", ::jdk::internal::net::http::SocketTube$SliceBufferSource),
	$classEntry("jdk.internal.net.http.SocketTube$SocketFlowEvent", ::jdk::internal::net::http::SocketTube$SocketFlowEvent),
	$classEntry("jdk.internal.net.http.SocketTube$SocketFlowTask", ::jdk::internal::net::http::SocketTube$SocketFlowTask),
	$classEntry("jdk.internal.net.http.Stream", ::jdk::internal::net::http::Stream),
	$classEntry("jdk.internal.net.http.Stream$HeadersConsumer", ::jdk::internal::net::http::Stream$HeadersConsumer),
	$classEntry("jdk.internal.net.http.Stream$PushedStream", ::jdk::internal::net::http::Stream$PushedStream),
	$classEntry("jdk.internal.net.http.Stream$RequestSubscriber", ::jdk::internal::net::http::Stream$RequestSubscriber),
	$classEntry("jdk.internal.net.http.Stream$StreamWindowUpdateSender", ::jdk::internal::net::http::Stream$StreamWindowUpdateSender),
	$classEntry("jdk.internal.net.http.TimeoutEvent", ::jdk::internal::net::http::TimeoutEvent),
	$classEntry("jdk.internal.net.http.WindowController", ::jdk::internal::net::http::WindowController),
	$classEntry("jdk.internal.net.http.WindowUpdateSender", ::jdk::internal::net::http::WindowUpdateSender),
	$classEntry("jdk.internal.net.http.common.BufferSupplier", ::jdk::internal::net::http::common::BufferSupplier),
	$classEntry("jdk.internal.net.http.common.Cancelable", ::jdk::internal::net::http::common::Cancelable),
	$classEntry("jdk.internal.net.http.common.ConnectionExpiredException", ::jdk::internal::net::http::common::ConnectionExpiredException),
	$classEntry("jdk.internal.net.http.common.DebugLogger", ::jdk::internal::net::http::common::DebugLogger),
	$classEntry("jdk.internal.net.http.common.Demand", ::jdk::internal::net::http::common::Demand),
	$classEntry("jdk.internal.net.http.common.FlowTube", ::jdk::internal::net::http::common::FlowTube),
	$classEntry("jdk.internal.net.http.common.FlowTube$AbstractTubePublisher", ::jdk::internal::net::http::common::FlowTube$AbstractTubePublisher),
	$classEntry("jdk.internal.net.http.common.FlowTube$AbstractTubePublisher$TubePublisherWrapper", ::jdk::internal::net::http::common::FlowTube$AbstractTubePublisher$TubePublisherWrapper),
	$classEntry("jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber", ::jdk::internal::net::http::common::FlowTube$AbstractTubeSubscriber),
	$classEntry("jdk.internal.net.http.common.FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper", ::jdk::internal::net::http::common::FlowTube$AbstractTubeSubscriber$TubeSubscriberWrapper),
	$classEntry("jdk.internal.net.http.common.FlowTube$TubePublisher", ::jdk::internal::net::http::common::FlowTube$TubePublisher),
	$classEntry("jdk.internal.net.http.common.FlowTube$TubeSubscriber", ::jdk::internal::net::http::common::FlowTube$TubeSubscriber),
	$classEntry("jdk.internal.net.http.common.HttpHeadersBuilder", ::jdk::internal::net::http::common::HttpHeadersBuilder),
	$classEntry("jdk.internal.net.http.common.ImmutableExtendedSSLSession", ::jdk::internal::net::http::common::ImmutableExtendedSSLSession),
	$classEntry("jdk.internal.net.http.common.ImmutableSSLSession", ::jdk::internal::net::http::common::ImmutableSSLSession),
	$classEntry("jdk.internal.net.http.common.Log", ::jdk::internal::net::http::common::Log),
	$classEntry("jdk.internal.net.http.common.Logger", ::jdk::internal::net::http::common::Logger),
	$classEntry("jdk.internal.net.http.common.MinimalFuture", ::jdk::internal::net::http::common::MinimalFuture),
	$classEntry("jdk.internal.net.http.common.MinimalFuture$ExceptionalSupplier", ::jdk::internal::net::http::common::MinimalFuture$ExceptionalSupplier),
	$classEntry("jdk.internal.net.http.common.OperationTrackers", ::jdk::internal::net::http::common::OperationTrackers),
	$classEntry("jdk.internal.net.http.common.OperationTrackers$Trackable", ::jdk::internal::net::http::common::OperationTrackers$Trackable),
	$classEntry("jdk.internal.net.http.common.OperationTrackers$Tracker", ::jdk::internal::net::http::common::OperationTrackers$Tracker),
	$classEntry("jdk.internal.net.http.common.Pair", ::jdk::internal::net::http::common::Pair),
	$classEntry("jdk.internal.net.http.common.SSLFlowDelegate", ::jdk::internal::net::http::common::SSLFlowDelegate),
	$classEntry("jdk.internal.net.http.common.SSLFlowDelegate$1", ::jdk::internal::net::http::common::SSLFlowDelegate$1),
	$classEntry("jdk.internal.net.http.common.SSLFlowDelegate$EngineResult", ::jdk::internal::net::http::common::SSLFlowDelegate$EngineResult),
	$classEntry("jdk.internal.net.http.common.SSLFlowDelegate$Monitor", ::jdk::internal::net::http::common::SSLFlowDelegate$Monitor),
	$classEntry("jdk.internal.net.http.common.SSLFlowDelegate$Monitor$FinalMonitorable", ::jdk::internal::net::http::common::SSLFlowDelegate$Monitor$FinalMonitorable),
	$classEntry("jdk.internal.net.http.common.SSLFlowDelegate$Monitorable", ::jdk::internal::net::http::common::SSLFlowDelegate$Monitorable),
	$classEntry("jdk.internal.net.http.common.SSLFlowDelegate$Reader", ::jdk::internal::net::http::common::SSLFlowDelegate$Reader),
	$classEntry("jdk.internal.net.http.common.SSLFlowDelegate$Reader$ReaderDownstreamPusher", ::jdk::internal::net::http::common::SSLFlowDelegate$Reader$ReaderDownstreamPusher),
	$classEntry("jdk.internal.net.http.common.SSLFlowDelegate$Writer", ::jdk::internal::net::http::common::SSLFlowDelegate$Writer),
	$classEntry("jdk.internal.net.http.common.SSLFlowDelegate$Writer$WriterDownstreamPusher", ::jdk::internal::net::http::common::SSLFlowDelegate$Writer$WriterDownstreamPusher),
	$classEntry("jdk.internal.net.http.common.SSLTube", ::jdk::internal::net::http::common::SSLTube),
	$classEntry("jdk.internal.net.http.common.SSLTube$DelegateWrapper", ::jdk::internal::net::http::common::SSLTube$DelegateWrapper),
	$classEntry("jdk.internal.net.http.common.SSLTube$SSLSubscriberWrapper", ::jdk::internal::net::http::common::SSLTube$SSLSubscriberWrapper),
	$classEntry("jdk.internal.net.http.common.SSLTube$SSLSubscriptionWrapper", ::jdk::internal::net::http::common::SSLTube$SSLSubscriptionWrapper),
	$classEntry("jdk.internal.net.http.common.SSLTube$SSLTubeFlowDelegate", ::jdk::internal::net::http::common::SSLTube$SSLTubeFlowDelegate),
	$classEntry("jdk.internal.net.http.common.SequentialScheduler", ::jdk::internal::net::http::common::SequentialScheduler),
	$classEntry("jdk.internal.net.http.common.SequentialScheduler$CompleteRestartableTask", ::jdk::internal::net::http::common::SequentialScheduler$CompleteRestartableTask),
	$classEntry("jdk.internal.net.http.common.SequentialScheduler$DeferredCompleter", ::jdk::internal::net::http::common::SequentialScheduler$DeferredCompleter),
	$classEntry("jdk.internal.net.http.common.SequentialScheduler$LockingRestartableTask", ::jdk::internal::net::http::common::SequentialScheduler$LockingRestartableTask),
	$classEntry("jdk.internal.net.http.common.SequentialScheduler$RestartableTask", ::jdk::internal::net::http::common::SequentialScheduler$RestartableTask),
	$classEntry("jdk.internal.net.http.common.SequentialScheduler$SchedulableTask", ::jdk::internal::net::http::common::SequentialScheduler$SchedulableTask),
	$classEntry("jdk.internal.net.http.common.SequentialScheduler$SynchronizedRestartableTask", ::jdk::internal::net::http::common::SequentialScheduler$SynchronizedRestartableTask),
	$classEntry("jdk.internal.net.http.common.SequentialScheduler$TryEndDeferredCompleter", ::jdk::internal::net::http::common::SequentialScheduler$TryEndDeferredCompleter),
	$classEntry("jdk.internal.net.http.common.SubscriberWrapper", ::jdk::internal::net::http::common::SubscriberWrapper),
	$classEntry("jdk.internal.net.http.common.SubscriberWrapper$1", ::jdk::internal::net::http::common::SubscriberWrapper$1),
	$classEntry("jdk.internal.net.http.common.SubscriberWrapper$DownstreamPusher", ::jdk::internal::net::http::common::SubscriberWrapper$DownstreamPusher),
	$classEntry("jdk.internal.net.http.common.SubscriberWrapper$SchedulingAction", ::jdk::internal::net::http::common::SubscriberWrapper$SchedulingAction),
	$classEntry("jdk.internal.net.http.common.SubscriptionBase", ::jdk::internal::net::http::common::SubscriptionBase),
	$classEntry("jdk.internal.net.http.common.Utils", ::jdk::internal::net::http::common::Utils),
	$classEntry("jdk.internal.net.http.common.Utils$ProxyHeaders", ::jdk::internal::net::http::common::Utils$ProxyHeaders),
	$classEntry("jdk.internal.net.http.common.Utils$ServerName", ::jdk::internal::net::http::common::Utils$ServerName),
	$classEntry("jdk.internal.net.http.frame.ContinuationFrame", ::jdk::internal::net::http::frame::ContinuationFrame),
	$classEntry("jdk.internal.net.http.frame.DataFrame", ::jdk::internal::net::http::frame::DataFrame),
	$classEntry("jdk.internal.net.http.frame.ErrorFrame", ::jdk::internal::net::http::frame::ErrorFrame),
	$classEntry("jdk.internal.net.http.frame.FramesDecoder", ::jdk::internal::net::http::frame::FramesDecoder),
	$classEntry("jdk.internal.net.http.frame.FramesDecoder$FrameProcessor", ::jdk::internal::net::http::frame::FramesDecoder$FrameProcessor),
	$classEntry("jdk.internal.net.http.frame.FramesEncoder", ::jdk::internal::net::http::frame::FramesEncoder),
	$classEntry("jdk.internal.net.http.frame.GoAwayFrame", ::jdk::internal::net::http::frame::GoAwayFrame),
	$classEntry("jdk.internal.net.http.frame.HeaderFrame", ::jdk::internal::net::http::frame::HeaderFrame),
	$classEntry("jdk.internal.net.http.frame.HeadersFrame", ::jdk::internal::net::http::frame::HeadersFrame),
	$classEntry("jdk.internal.net.http.frame.Http2Frame", ::jdk::internal::net::http::frame::Http2Frame),
	$classEntry("jdk.internal.net.http.frame.MalformedFrame", ::jdk::internal::net::http::frame::MalformedFrame),
	$classEntry("jdk.internal.net.http.frame.OutgoingHeaders", ::jdk::internal::net::http::frame::OutgoingHeaders),
	$classEntry("jdk.internal.net.http.frame.PingFrame", ::jdk::internal::net::http::frame::PingFrame),
	$classEntry("jdk.internal.net.http.frame.PriorityFrame", ::jdk::internal::net::http::frame::PriorityFrame),
	$classEntry("jdk.internal.net.http.frame.PushPromiseFrame", ::jdk::internal::net::http::frame::PushPromiseFrame),
	$classEntry("jdk.internal.net.http.frame.ResetFrame", ::jdk::internal::net::http::frame::ResetFrame),
	$classEntry("jdk.internal.net.http.frame.SettingsFrame", ::jdk::internal::net::http::frame::SettingsFrame),
	$classEntry("jdk.internal.net.http.frame.WindowUpdateFrame", ::jdk::internal::net::http::frame::WindowUpdateFrame),
	$classEntry("jdk.internal.net.http.hpack.BinaryRepresentationWriter", ::jdk::internal::net::http::hpack::BinaryRepresentationWriter),
	$classEntry("jdk.internal.net.http.hpack.BulkSizeUpdateWriter", ::jdk::internal::net::http::hpack::BulkSizeUpdateWriter),
	$classEntry("jdk.internal.net.http.hpack.Decoder", ::jdk::internal::net::http::hpack::Decoder),
	$classEntry("jdk.internal.net.http.hpack.Decoder$1", ::jdk::internal::net::http::hpack::Decoder$1),
	$classEntry("jdk.internal.net.http.hpack.Decoder$State", ::jdk::internal::net::http::hpack::Decoder$State),
	$classEntry("jdk.internal.net.http.hpack.DecodingCallback", ::jdk::internal::net::http::hpack::DecodingCallback),
	$classEntry("jdk.internal.net.http.hpack.Encoder", ::jdk::internal::net::http::hpack::Encoder),
	$classEntry("jdk.internal.net.http.hpack.HPACK", ::jdk::internal::net::http::hpack::HPACK),
	$classEntry("jdk.internal.net.http.hpack.HPACK$BufferUpdateConsumer", ::jdk::internal::net::http::hpack::HPACK$BufferUpdateConsumer),
	$classEntry("jdk.internal.net.http.hpack.HPACK$Logger", ::jdk::internal::net::http::hpack::HPACK$Logger),
	$classEntry("jdk.internal.net.http.hpack.HPACK$Logger$Level", ::jdk::internal::net::http::hpack::HPACK$Logger$Level),
	$classEntry("jdk.internal.net.http.hpack.HPACK$RootLogger", ::jdk::internal::net::http::hpack::HPACK$RootLogger),
	$classEntry("jdk.internal.net.http.hpack.HeaderTable", ::jdk::internal::net::http::hpack::HeaderTable),
	$classEntry("jdk.internal.net.http.hpack.Huffman", ::jdk::internal::net::http::hpack::Huffman),
	$classEntry("jdk.internal.net.http.hpack.Huffman$Reader", ::jdk::internal::net::http::hpack::Huffman$Reader),
	$classEntry("jdk.internal.net.http.hpack.Huffman$Writer", ::jdk::internal::net::http::hpack::Huffman$Writer),
	$classEntry("jdk.internal.net.http.hpack.ISO_8859_1", ::jdk::internal::net::http::hpack::ISO_8859_1),
	$classEntry("jdk.internal.net.http.hpack.ISO_8859_1$Reader", ::jdk::internal::net::http::hpack::ISO_8859_1$Reader),
	$classEntry("jdk.internal.net.http.hpack.ISO_8859_1$Writer", ::jdk::internal::net::http::hpack::ISO_8859_1$Writer),
	$classEntry("jdk.internal.net.http.hpack.IndexNameValueWriter", ::jdk::internal::net::http::hpack::IndexNameValueWriter),
	$classEntry("jdk.internal.net.http.hpack.IndexedWriter", ::jdk::internal::net::http::hpack::IndexedWriter),
	$classEntry("jdk.internal.net.http.hpack.IntegerReader", ::jdk::internal::net::http::hpack::IntegerReader),
	$classEntry("jdk.internal.net.http.hpack.IntegerWriter", ::jdk::internal::net::http::hpack::IntegerWriter),
	$classEntry("jdk.internal.net.http.hpack.LiteralNeverIndexedWriter", ::jdk::internal::net::http::hpack::LiteralNeverIndexedWriter),
	$classEntry("jdk.internal.net.http.hpack.LiteralWithIndexingWriter", ::jdk::internal::net::http::hpack::LiteralWithIndexingWriter),
	$classEntry("jdk.internal.net.http.hpack.LiteralWriter", ::jdk::internal::net::http::hpack::LiteralWriter),
	$classEntry("jdk.internal.net.http.hpack.NaiveHuffman", ::jdk::internal::net::http::hpack::NaiveHuffman),
	$classEntry("jdk.internal.net.http.hpack.NaiveHuffman$1", ::jdk::internal::net::http::hpack::NaiveHuffman$1),
	$classEntry("jdk.internal.net.http.hpack.NaiveHuffman$Code", ::jdk::internal::net::http::hpack::NaiveHuffman$Code),
	$classEntry("jdk.internal.net.http.hpack.NaiveHuffman$Node", ::jdk::internal::net::http::hpack::NaiveHuffman$Node),
	$classEntry("jdk.internal.net.http.hpack.NaiveHuffman$Reader", ::jdk::internal::net::http::hpack::NaiveHuffman$Reader),
	$classEntry("jdk.internal.net.http.hpack.NaiveHuffman$Writer", ::jdk::internal::net::http::hpack::NaiveHuffman$Writer),
	$classEntry("jdk.internal.net.http.hpack.QuickHuffman", ::jdk::internal::net::http::hpack::QuickHuffman),
	$classEntry("jdk.internal.net.http.hpack.QuickHuffman$ImmutableNode", ::jdk::internal::net::http::hpack::QuickHuffman$ImmutableNode),
	$classEntry("jdk.internal.net.http.hpack.QuickHuffman$Node", ::jdk::internal::net::http::hpack::QuickHuffman$Node),
	$classEntry("jdk.internal.net.http.hpack.QuickHuffman$Reader", ::jdk::internal::net::http::hpack::QuickHuffman$Reader),
	$classEntry("jdk.internal.net.http.hpack.QuickHuffman$TemporaryNode", ::jdk::internal::net::http::hpack::QuickHuffman$TemporaryNode),
	$classEntry("jdk.internal.net.http.hpack.QuickHuffman$Writer", ::jdk::internal::net::http::hpack::QuickHuffman$Writer),
	$classEntry("jdk.internal.net.http.hpack.SimpleHeaderTable", ::jdk::internal::net::http::hpack::SimpleHeaderTable),
	$classEntry("jdk.internal.net.http.hpack.SimpleHeaderTable$CircularBuffer", ::jdk::internal::net::http::hpack::SimpleHeaderTable$CircularBuffer),
	$classEntry("jdk.internal.net.http.hpack.SimpleHeaderTable$HeaderField", ::jdk::internal::net::http::hpack::SimpleHeaderTable$HeaderField),
	$classEntry("jdk.internal.net.http.hpack.SizeUpdateWriter", ::jdk::internal::net::http::hpack::SizeUpdateWriter),
	$classEntry("jdk.internal.net.http.hpack.StringReader", ::jdk::internal::net::http::hpack::StringReader),
	$classEntry("jdk.internal.net.http.hpack.StringWriter", ::jdk::internal::net::http::hpack::StringWriter),
	$classEntry("jdk.internal.net.http.websocket.BuilderImpl", ::jdk::internal::net::http::websocket::BuilderImpl),
	$classEntry("jdk.internal.net.http.websocket.CheckFailedException", ::jdk::internal::net::http::websocket::CheckFailedException),
	$classEntry("jdk.internal.net.http.websocket.FailWebSocketException", ::jdk::internal::net::http::websocket::FailWebSocketException),
	$classEntry("jdk.internal.net.http.websocket.Frame", ::jdk::internal::net::http::websocket::Frame),
	$classEntry("jdk.internal.net.http.websocket.Frame$Consumer", ::jdk::internal::net::http::websocket::Frame$Consumer),
	$classEntry("jdk.internal.net.http.websocket.Frame$HeaderWriter", ::jdk::internal::net::http::websocket::Frame$HeaderWriter),
	$classEntry("jdk.internal.net.http.websocket.Frame$Masker", ::jdk::internal::net::http::websocket::Frame$Masker),
	$classEntry("jdk.internal.net.http.websocket.Frame$Opcode", ::jdk::internal::net::http::websocket::Frame$Opcode),
	$classEntry("jdk.internal.net.http.websocket.Frame$Reader", ::jdk::internal::net::http::websocket::Frame$Reader),
	$classEntry("jdk.internal.net.http.websocket.MessageDecoder", ::jdk::internal::net::http::websocket::MessageDecoder),
	$classEntry("jdk.internal.net.http.websocket.MessageDecoder$1", ::jdk::internal::net::http::websocket::MessageDecoder$1),
	$classEntry("jdk.internal.net.http.websocket.MessageEncoder", ::jdk::internal::net::http::websocket::MessageEncoder),
	$classEntry("jdk.internal.net.http.websocket.MessageQueue", ::jdk::internal::net::http::websocket::MessageQueue),
	$classEntry("jdk.internal.net.http.websocket.MessageQueue$1", ::jdk::internal::net::http::websocket::MessageQueue$1),
	$classEntry("jdk.internal.net.http.websocket.MessageQueue$Message", ::jdk::internal::net::http::websocket::MessageQueue$Message),
	$classEntry("jdk.internal.net.http.websocket.MessageQueue$QueueCallback", ::jdk::internal::net::http::websocket::MessageQueue$QueueCallback),
	$classEntry("jdk.internal.net.http.websocket.MessageQueue$Type", ::jdk::internal::net::http::websocket::MessageQueue$Type),
	$classEntry("jdk.internal.net.http.websocket.MessageStreamConsumer", ::jdk::internal::net::http::websocket::MessageStreamConsumer),
	$classEntry("jdk.internal.net.http.websocket.OpeningHandshake", ::jdk::internal::net::http::websocket::OpeningHandshake),
	$classEntry("jdk.internal.net.http.websocket.OpeningHandshake$Result", ::jdk::internal::net::http::websocket::OpeningHandshake$Result),
	$classEntry("jdk.internal.net.http.websocket.RawChannel", ::jdk::internal::net::http::websocket::RawChannel),
	$classEntry("jdk.internal.net.http.websocket.RawChannel$Provider", ::jdk::internal::net::http::websocket::RawChannel$Provider),
	$classEntry("jdk.internal.net.http.websocket.RawChannel$RawEvent", ::jdk::internal::net::http::websocket::RawChannel$RawEvent),
	$classEntry("jdk.internal.net.http.websocket.StatusCodes", ::jdk::internal::net::http::websocket::StatusCodes),
	$classEntry("jdk.internal.net.http.websocket.Transport", ::jdk::internal::net::http::websocket::Transport),
	$classEntry("jdk.internal.net.http.websocket.TransportFactory", ::jdk::internal::net::http::websocket::TransportFactory),
	$classEntry("jdk.internal.net.http.websocket.TransportFactoryImpl", ::jdk::internal::net::http::websocket::TransportFactoryImpl),
	$classEntry("jdk.internal.net.http.websocket.TransportImpl", ::jdk::internal::net::http::websocket::TransportImpl),
	$classEntry("jdk.internal.net.http.websocket.TransportImpl$1", ::jdk::internal::net::http::websocket::TransportImpl$1),
	$classEntry("jdk.internal.net.http.websocket.TransportImpl$ChannelState", ::jdk::internal::net::http::websocket::TransportImpl$ChannelState),
	$classEntry("jdk.internal.net.http.websocket.TransportImpl$ReadEvent", ::jdk::internal::net::http::websocket::TransportImpl$ReadEvent),
	$classEntry("jdk.internal.net.http.websocket.TransportImpl$ReceiveTask", ::jdk::internal::net::http::websocket::TransportImpl$ReceiveTask),
	$classEntry("jdk.internal.net.http.websocket.TransportImpl$SendTask", ::jdk::internal::net::http::websocket::TransportImpl$SendTask),
	$classEntry("jdk.internal.net.http.websocket.TransportImpl$SendTask$1", ::jdk::internal::net::http::websocket::TransportImpl$SendTask$1),
	$classEntry("jdk.internal.net.http.websocket.TransportImpl$SendTask$2", ::jdk::internal::net::http::websocket::TransportImpl$SendTask$2),
	$classEntry("jdk.internal.net.http.websocket.TransportImpl$WriteEvent", ::jdk::internal::net::http::websocket::TransportImpl$WriteEvent),
	$classEntry("jdk.internal.net.http.websocket.UTF8AccumulatingDecoder", ::jdk::internal::net::http::websocket::UTF8AccumulatingDecoder),
	$classEntry("jdk.internal.net.http.websocket.WebSocketImpl", ::jdk::internal::net::http::websocket::WebSocketImpl),
	$classEntry("jdk.internal.net.http.websocket.WebSocketImpl$1", ::jdk::internal::net::http::websocket::WebSocketImpl$1),
	$classEntry("jdk.internal.net.http.websocket.WebSocketImpl$ReceiveTask", ::jdk::internal::net::http::websocket::WebSocketImpl$ReceiveTask),
	$classEntry("jdk.internal.net.http.websocket.WebSocketImpl$SignallingMessageConsumer", ::jdk::internal::net::http::websocket::WebSocketImpl$SignallingMessageConsumer),
	$classEntry("jdk.internal.net.http.websocket.WebSocketImpl$State", ::jdk::internal::net::http::websocket::WebSocketImpl$State),
	$classEntry("jdk.internal.net.http.websocket.WebSocketRequest", ::jdk::internal::net::http::websocket::WebSocketRequest)
};

const char* _java$net$http_packages_[] = {
	"java.net.http",
	"jdk.internal.net.http",
	"jdk.internal.net.http.common",
	"jdk.internal.net.http.frame",
	"jdk.internal.net.http.hpack",
	"jdk.internal.net.http.websocket"
};

void java$net$http$PreloadClass(void* eventData) {
	::java::lang::PreloadClassEvent* event = (::java::lang::PreloadClassEvent*)eventData;
	int32_t length = $lengthOf(_java$net$http_classes_);
	for (int i = 0; i < length; i++) {
		::java::lang::ClassEntry* classEntry = &_java$net$http_classes_[i];
		if (event->preinit) {
			if ($hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, true);
				continue;
			}
		}
		if (event->preload) {
			if ($hasFlag(classEntry->mark, $PRELOAD) || $hasFlag(classEntry->mark, $PREINIT)) {
				classEntry->loader(nullptr, false);
			}
		}
	}
}

void java$net$http$LibEventAction(int32_t eventType, void* eventData) {
	if (eventType == JCPP_LIB_EVENT_TYPE_PRELOAD_CLASS) {
		java$net$http$PreloadClass(eventData);
	}
	if (eventType == JCPP_LIB_EVENT_TYPE_THREAD_START) {
		$onLibThreadStart(eventData);
	}
}

$StringArray* java$net$http$GetPackages() {
	int32_t length = $lengthOf(_java$net$http_packages_);
	$var($StringArray, packages, $new($StringArray, length));
	for (int32_t i = 0; i < length; i++) {
		packages->set(i, $str(_java$net$http_packages_[i]));
	}
	return packages;
}

::java::lang::ClassEntry* java$net$http$GetClassEntry($String* name) {
	int32_t begin = 0;
	int32_t end = $lengthOf(_java$net$http_classes_) - 1;
	while (begin <= end) {
		int32_t mid = begin + (end - begin) / 2;
		::java::lang::ClassEntry* classEntry = &_java$net$http_classes_[mid];
		int32_t ret = name->compareTo(classEntry->name);
		if (ret < 0) {
			end = mid - 1;
		} else if (ret > 0) {
			begin = mid + 1;
		} else {
			return classEntry;
		}
	}
	return nullptr;
}

$bytes* java$net$http$GetResource($String* name) {
	return nullptr;
}

void java$net$http::init() {
	::java$base::init();
	::java::lang::Library lib = {
		"java.net.http", "17.35", "",
		&_java$net$http_ModuleInfo_,
		java$net$http$LibEventAction,
		java$net$http$GetPackages,
		java$net$http$GetClassEntry,
		java$net$http$GetResource
	};
	$System::addLibrary(&lib);
}