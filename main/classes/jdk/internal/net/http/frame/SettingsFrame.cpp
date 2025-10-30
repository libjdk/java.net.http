#include <jdk/internal/net/http/frame/SettingsFrame.h>

#include <java/nio/ByteBuffer.h>
#include <java/util/Arrays.h>
#include <jdk/internal/net/http/frame/Http2Frame.h>
#include <jcpp.h>

#undef ACK
#undef DEFAULT_ENABLE_PUSH
#undef DEFAULT_HEADER_TABLE_SIZE
#undef DEFAULT_INITIAL_WINDOW_SIZE
#undef DEFAULT_MAX_CONCURRENT_STREAMS
#undef DEFAULT_MAX_FRAME_SIZE
#undef ENABLE_PUSH
#undef HEADER_TABLE_SIZE
#undef INITIAL_WINDOW_SIZE
#undef K
#undef MAX_CONCURRENT_STREAMS
#undef MAX_FRAME_SIZE
#undef MAX_HEADER_LIST_SIZE
#undef MAX_PARAM
#undef TYPE

using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalArgumentException = ::java::lang::IllegalArgumentException;
using $Integer = ::java::lang::Integer;
using $MethodInfo = ::java::lang::MethodInfo;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Arrays = ::java::util::Arrays;
using $Http2Frame = ::jdk::internal::net::http::frame::Http2Frame;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace frame {

$FieldInfo _SettingsFrame_FieldInfo_[] = {
	{"parameters", "[I", nullptr, $PRIVATE | $FINAL, $field(SettingsFrame, parameters)},
	{"TYPE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, TYPE)},
	{"ACK", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, ACK)},
	{"HEADER_TABLE_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, HEADER_TABLE_SIZE)},
	{"ENABLE_PUSH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, ENABLE_PUSH)},
	{"MAX_CONCURRENT_STREAMS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, MAX_CONCURRENT_STREAMS)},
	{"INITIAL_WINDOW_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, INITIAL_WINDOW_SIZE)},
	{"MAX_FRAME_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, MAX_FRAME_SIZE)},
	{"MAX_HEADER_LIST_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, MAX_HEADER_LIST_SIZE)},
	{"MAX_PARAM", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, MAX_PARAM)},
	{"K", "I", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(SettingsFrame, K)},
	{"DEFAULT_HEADER_TABLE_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, DEFAULT_HEADER_TABLE_SIZE)},
	{"DEFAULT_ENABLE_PUSH", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, DEFAULT_ENABLE_PUSH)},
	{"DEFAULT_MAX_CONCURRENT_STREAMS", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, DEFAULT_MAX_CONCURRENT_STREAMS)},
	{"DEFAULT_INITIAL_WINDOW_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, DEFAULT_INITIAL_WINDOW_SIZE)},
	{"DEFAULT_MAX_FRAME_SIZE", "I", nullptr, $PUBLIC | $STATIC | $FINAL, $constField(SettingsFrame, DEFAULT_MAX_FRAME_SIZE)},
	{}
};

$MethodInfo _SettingsFrame_MethodInfo_[] = {
	{"<init>", "(I)V", nullptr, $PUBLIC, $method(static_cast<void(SettingsFrame::*)(int32_t)>(&SettingsFrame::init$))},
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(SettingsFrame::*)()>(&SettingsFrame::init$))},
	{"<init>", "(Ljdk/internal/net/http/frame/SettingsFrame;)V", nullptr, $PUBLIC, $method(static_cast<void(SettingsFrame::*)(SettingsFrame*)>(&SettingsFrame::init$))},
	{"defaultRFCSettings", "()Ljdk/internal/net/http/frame/SettingsFrame;", nullptr, $PUBLIC | $STATIC, $method(static_cast<SettingsFrame*(*)()>(&SettingsFrame::defaultRFCSettings))},
	{"flagAsString", "(I)Ljava/lang/String;", nullptr, $PUBLIC},
	{"getParameter", "(I)I", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"length", "()I", nullptr, 0},
	{"name", "(I)Ljava/lang/String;", nullptr, $PRIVATE, $method(static_cast<$String*(SettingsFrame::*)(int32_t)>(&SettingsFrame::name))},
	{"setParameter", "(II)Ljdk/internal/net/http/frame/SettingsFrame;", nullptr, $PUBLIC | $SYNCHRONIZED},
	{"toByteArray", "()[B", nullptr, $PUBLIC},
	{"toByteBuffer", "(Ljava/nio/ByteBuffer;)V", nullptr, 0},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"type", "()I", nullptr, $PUBLIC},
	{"update", "(Ljdk/internal/net/http/frame/SettingsFrame;)V", nullptr, $PUBLIC | $SYNCHRONIZED},
	{}
};

$ClassInfo _SettingsFrame_ClassInfo_ = {
	$PUBLIC | $ACC_SUPER,
	"jdk.internal.net.http.frame.SettingsFrame",
	"jdk.internal.net.http.frame.Http2Frame",
	nullptr,
	_SettingsFrame_FieldInfo_,
	_SettingsFrame_MethodInfo_
};

$Object* allocate$SettingsFrame($Class* clazz) {
	return $of($alloc(SettingsFrame));
}

$String* SettingsFrame::flagAsString(int32_t flag) {

	$var($String, var$0, nullptr)
	switch (flag) {
	case SettingsFrame::ACK:
		{
			$assign(var$0, "ACK"_s);
			break;
		}
	default:
		{
			$assign(var$0, $Http2Frame::flagAsString(flag));
			break;
		}
	}
	return var$0;
}

$String* SettingsFrame::toString() {
	$useLocalCurrentObjectStackCache();
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append($($Http2Frame::toString()))->append(" Settings: "_s);
	for (int32_t i = 0; i < SettingsFrame::MAX_PARAM; ++i) {
		if ($nc(this->parameters)->get(i) != -1) {
			sb->append($(name(i)))->append("="_s)->append($($Integer::toString($nc(this->parameters)->get(i))))->append(u' ');
		}
	}
	return sb->toString();
}

$String* SettingsFrame::name(int32_t i) {

	$var($String, var$0, nullptr)
	switch (i + 1) {
	case SettingsFrame::HEADER_TABLE_SIZE:
		{
			$assign(var$0, "HEADER_TABLE_SIZE"_s);
			break;
		}
	case SettingsFrame::ENABLE_PUSH:
		{
			$assign(var$0, "ENABLE_PUSH"_s);
			break;
		}
	case SettingsFrame::MAX_CONCURRENT_STREAMS:
		{
			$assign(var$0, "MAX_CONCURRENT_STREAMS"_s);
			break;
		}
	case SettingsFrame::INITIAL_WINDOW_SIZE:
		{
			$assign(var$0, "INITIAL_WINDOW_SIZE"_s);
			break;
		}
	case SettingsFrame::MAX_FRAME_SIZE:
		{
			$assign(var$0, "MAX_FRAME_SIZE"_s);
			break;
		}
	case SettingsFrame::MAX_HEADER_LIST_SIZE:
		{
			$assign(var$0, "MAX_HEADER_LIST_SIZE"_s);
			break;
		}
	default:
		{
			$assign(var$0, "unknown parameter"_s);
			break;
		}
	}
	return var$0;
}

void SettingsFrame::init$(int32_t flags) {
	$Http2Frame::init$(0, flags);
	$set(this, parameters, $new($ints, SettingsFrame::MAX_PARAM));
	$Arrays::fill(this->parameters, -1);
}

void SettingsFrame::init$() {
	SettingsFrame::init$(0);
}

void SettingsFrame::init$(SettingsFrame* other) {
	$Http2Frame::init$(0, $nc(other)->flags);
	$set(this, parameters, $Arrays::copyOf($nc(other)->parameters, SettingsFrame::MAX_PARAM));
}

int32_t SettingsFrame::type() {
	return SettingsFrame::TYPE;
}

int32_t SettingsFrame::getParameter(int32_t paramID) {
	$synchronized(this) {
		if (paramID > SettingsFrame::MAX_PARAM) {
			$throwNew($IllegalArgumentException, "illegal parameter"_s);
		}
		return $nc(this->parameters)->get(paramID - 1);
	}
}

SettingsFrame* SettingsFrame::setParameter(int32_t paramID, int32_t value) {
	$synchronized(this) {
		if (paramID > SettingsFrame::MAX_PARAM) {
			$throwNew($IllegalArgumentException, "illegal parameter"_s);
		}
		$nc(this->parameters)->set(paramID - 1, value);
		return this;
	}
}

int32_t SettingsFrame::length() {
	int32_t len = 0;
	{
		$var($ints, arr$, this->parameters);
		int32_t len$ = $nc(arr$)->length;
		int32_t i$ = 0;
		for (; i$ < len$; ++i$) {
			int32_t i = arr$->get(i$);
			{
				if (i != -1) {
					len += 6;
				}
			}
		}
	}
	return len;
}

void SettingsFrame::toByteBuffer($ByteBuffer* buf) {
	for (int32_t i = 0; i < SettingsFrame::MAX_PARAM; ++i) {
		if ($nc(this->parameters)->get(i) != -1) {
			$nc(buf)->putShort((int16_t)(i + 1));
			buf->putInt($nc(this->parameters)->get(i));
		}
	}
}

$bytes* SettingsFrame::toByteArray() {
	$useLocalCurrentObjectStackCache();
	$var($bytes, bytes, $new($bytes, length()));
	$var($ByteBuffer, buf, $ByteBuffer::wrap(bytes));
	toByteBuffer(buf);
	return bytes;
}

void SettingsFrame::update(SettingsFrame* updated) {
	$synchronized(this) {
		for (int32_t i = 0; i < SettingsFrame::MAX_PARAM; ++i) {
			if ($nc($nc(updated)->parameters)->get(i) != -1) {
				$nc(this->parameters)->set(i, $nc(updated->parameters)->get(i));
			}
		}
	}
}

SettingsFrame* SettingsFrame::defaultRFCSettings() {
	$init(SettingsFrame);
	$var(SettingsFrame, f, $new(SettingsFrame));
	f->setParameter(SettingsFrame::ENABLE_PUSH, SettingsFrame::DEFAULT_ENABLE_PUSH);
	f->setParameter(SettingsFrame::HEADER_TABLE_SIZE, SettingsFrame::DEFAULT_HEADER_TABLE_SIZE);
	f->setParameter(SettingsFrame::MAX_CONCURRENT_STREAMS, SettingsFrame::DEFAULT_MAX_CONCURRENT_STREAMS);
	f->setParameter(SettingsFrame::INITIAL_WINDOW_SIZE, SettingsFrame::DEFAULT_INITIAL_WINDOW_SIZE);
	f->setParameter(SettingsFrame::MAX_FRAME_SIZE, SettingsFrame::DEFAULT_MAX_FRAME_SIZE);
	return f;
}

SettingsFrame::SettingsFrame() {
}

$Class* SettingsFrame::load$($String* name, bool initialize) {
	$loadClass(SettingsFrame, name, initialize, &_SettingsFrame_ClassInfo_, allocate$SettingsFrame);
	return class$;
}

$Class* SettingsFrame::class$ = nullptr;

				} // frame
			} // http
		} // net
	} // internal
} // jdk