#include <jdk/internal/net/http/Http1HeaderParser.h>

#include <java/io/Serializable.h>
#include <java/lang/AssertionError.h>
#include <java/lang/CharSequence.h>
#include <java/lang/InternalError.h>
#include <java/lang/NumberFormatException.h>
#include <java/lang/invoke/CallSite.h>
#include <java/lang/invoke/LambdaMetafactory.h>
#include <java/lang/invoke/MethodHandle.h>
#include <java/lang/invoke/MethodHandles$Lookup.h>
#include <java/lang/invoke/MethodType.h>
#include <java/net/ProtocolException.h>
#include <java/net/http/HttpHeaders.h>
#include <java/nio/ByteBuffer.h>
#include <java/util/AbstractList.h>
#include <java/util/AbstractMap.h>
#include <java/util/ArrayList.h>
#include <java/util/HashMap.h>
#include <java/util/List.h>
#include <java/util/Locale.h>
#include <java/util/Map.h>
#include <java/util/Objects.h>
#include <java/util/function/BiPredicate.h>
#include <java/util/function/Function.h>
#include <jdk/internal/net/http/Http1HeaderParser$1.h>
#include <jdk/internal/net/http/Http1HeaderParser$State.h>
#include <jdk/internal/net/http/common/Utils.h>
#include <jcpp.h>

#undef ACCEPT_ALL
#undef CR
#undef FINISHED
#undef HEADER
#undef HEADER_FOUND_CR
#undef HEADER_FOUND_CR_LF
#undef HEADER_FOUND_CR_LF_CR
#undef HEADER_FOUND_LF
#undef HT
#undef INITIAL
#undef LF
#undef SP
#undef STATUS_LINE
#undef STATUS_LINE_END
#undef STATUS_LINE_END_CR
#undef STATUS_LINE_END_LF
#undef STATUS_LINE_FOUND_CR
#undef STATUS_LINE_FOUND_LF
#undef US

using $Serializable = ::java::io::Serializable;
using $AbstractStringBuilder = ::java::lang::AbstractStringBuilder;
using $AssertionError = ::java::lang::AssertionError;
using $CharSequence = ::java::lang::CharSequence;
using $Character = ::java::lang::Character;
using $ClassInfo = ::java::lang::ClassInfo;
using $Enum = ::java::lang::Enum;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $Integer = ::java::lang::Integer;
using $InternalError = ::java::lang::InternalError;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $NumberFormatException = ::java::lang::NumberFormatException;
using $CallSite = ::java::lang::invoke::CallSite;
using $LambdaMetafactory = ::java::lang::invoke::LambdaMetafactory;
using $MethodHandle = ::java::lang::invoke::MethodHandle;
using $MethodHandles$Lookup = ::java::lang::invoke::MethodHandles$Lookup;
using $MethodType = ::java::lang::invoke::MethodType;
using $ProtocolException = ::java::net::ProtocolException;
using $HttpHeaders = ::java::net::http::HttpHeaders;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $AbstractList = ::java::util::AbstractList;
using $AbstractMap = ::java::util::AbstractMap;
using $ArrayList = ::java::util::ArrayList;
using $HashMap = ::java::util::HashMap;
using $List = ::java::util::List;
using $Locale = ::java::util::Locale;
using $Map = ::java::util::Map;
using $Objects = ::java::util::Objects;
using $BiPredicate = ::java::util::function::BiPredicate;
using $Function = ::java::util::function::Function;
using $Http1HeaderParser$1 = ::jdk::internal::net::http::Http1HeaderParser$1;
using $Http1HeaderParser$State = ::jdk::internal::net::http::Http1HeaderParser$State;
using $Utils = ::jdk::internal::net::http::common::Utils;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

class Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0 : public $Function {
	$class(Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0, $NO_CLASS_INIT, $Function)
public:
	void init$() {
	}
	virtual $Object* apply(Object$* k) override {
		 return $of(Http1HeaderParser::lambda$addHeaderFromString$0($cast($String, k)));
	}
	static $Object* allocate$($Class* clazz) {
		return $of($alloc<Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0>());
	}
	static $MethodInfo methodInfos[3];
	static $ClassInfo classInfo$;
};
$MethodInfo Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0::methodInfos[3] = {
	{"<init>", "()V", nullptr, $PUBLIC, $method(static_cast<void(Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0::*)()>(&Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0::init$))},
	{"apply", "(Ljava/lang/Object;)Ljava/lang/Object;", nullptr, $PUBLIC},
	{}
};
$ClassInfo Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0::classInfo$ = {
	$PUBLIC | $FINAL,
	"jdk.internal.net.http.Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0",
	"java.lang.Object",
	"java.util.function.Function",
	nullptr,
	methodInfos
};
$Class* Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0::load$($String* name, bool initialize) {
	$loadClass(Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0, name, initialize, &classInfo$, allocate$);
	return class$;
}
$Class* Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0::class$ = nullptr;

$FieldInfo _Http1HeaderParser_FieldInfo_[] = {
	{"$assertionsDisabled", "Z", nullptr, $STATIC | $FINAL | $SYNTHETIC, $staticField(Http1HeaderParser, $assertionsDisabled)},
	{"CR", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Http1HeaderParser, CR)},
	{"LF", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Http1HeaderParser, LF)},
	{"HT", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Http1HeaderParser, HT)},
	{"SP", "C", nullptr, $PRIVATE | $STATIC | $FINAL, $constField(Http1HeaderParser, SP)},
	{"sb", "Ljava/lang/StringBuilder;", nullptr, $PRIVATE, $field(Http1HeaderParser, sb)},
	{"statusLine", "Ljava/lang/String;", nullptr, $PRIVATE, $field(Http1HeaderParser, statusLine$)},
	{"responseCode", "I", nullptr, $PRIVATE, $field(Http1HeaderParser, responseCode$)},
	{"headers", "Ljava/net/http/HttpHeaders;", nullptr, $PRIVATE, $field(Http1HeaderParser, headers$)},
	{"privateMap", "Ljava/util/Map;", "Ljava/util/Map<Ljava/lang/String;Ljava/util/List<Ljava/lang/String;>;>;", $PRIVATE, $field(Http1HeaderParser, privateMap)},
	{"state", "Ljdk/internal/net/http/Http1HeaderParser$State;", nullptr, $PRIVATE, $field(Http1HeaderParser, state)},
	{}
};

$MethodInfo _Http1HeaderParser_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(Http1HeaderParser::*)()>(&Http1HeaderParser::init$))},
	{"addHeaderFromString", "(Ljava/lang/String;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1HeaderParser::*)($String*)>(&Http1HeaderParser::addHeaderFromString)), "java.net.ProtocolException"},
	{"canContinueParsing", "(Ljava/nio/ByteBuffer;)Z", nullptr, $PRIVATE, $method(static_cast<bool(Http1HeaderParser::*)($ByteBuffer*)>(&Http1HeaderParser::canContinueParsing))},
	{"currentStateMessage", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{"get", "(Ljava/nio/ByteBuffer;)C", nullptr, $PRIVATE, $method(static_cast<char16_t(Http1HeaderParser::*)($ByteBuffer*)>(&Http1HeaderParser::get))},
	{"headers", "()Ljava/net/http/HttpHeaders;", nullptr, 0},
	{"lambda$addHeaderFromString$0", "(Ljava/lang/String;)Ljava/util/List;", nullptr, $PRIVATE | $STATIC | $SYNTHETIC, $method(static_cast<$List*(*)($String*)>(&Http1HeaderParser::lambda$addHeaderFromString$0))},
	{"maybeEndHeaders", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1HeaderParser::*)($ByteBuffer*)>(&Http1HeaderParser::maybeEndHeaders)), "java.net.ProtocolException"},
	{"maybeStartHeaders", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1HeaderParser::*)($ByteBuffer*)>(&Http1HeaderParser::maybeStartHeaders))},
	{"parse", "(Ljava/nio/ByteBuffer;)Z", nullptr, 0, nullptr, "java.net.ProtocolException"},
	{"protocolException", "(Ljava/lang/String;[Ljava/lang/Object;)Ljava/net/ProtocolException;", nullptr, $PRIVATE | $TRANSIENT, $method(static_cast<$ProtocolException*(Http1HeaderParser::*)($String*,$ObjectArray*)>(&Http1HeaderParser::protocolException))},
	{"readResumeHeader", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1HeaderParser::*)($ByteBuffer*)>(&Http1HeaderParser::readResumeHeader))},
	{"readResumeStatusLine", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1HeaderParser::*)($ByteBuffer*)>(&Http1HeaderParser::readResumeStatusLine))},
	{"readStatusLineFeed", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1HeaderParser::*)($ByteBuffer*)>(&Http1HeaderParser::readStatusLineFeed)), "java.net.ProtocolException"},
	{"responseCode", "()I", nullptr, 0},
	{"resumeOrEndHeaders", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1HeaderParser::*)($ByteBuffer*)>(&Http1HeaderParser::resumeOrEndHeaders)), "java.net.ProtocolException"},
	{"resumeOrLF", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1HeaderParser::*)($ByteBuffer*)>(&Http1HeaderParser::resumeOrLF))},
	{"resumeOrSecondCR", "(Ljava/nio/ByteBuffer;)V", nullptr, $PRIVATE, $method(static_cast<void(Http1HeaderParser::*)($ByteBuffer*)>(&Http1HeaderParser::resumeOrSecondCR)), "java.net.ProtocolException"},
	{"statusLine", "()Ljava/lang/String;", nullptr, 0},
	{}
};

$InnerClassInfo _Http1HeaderParser_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.Http1HeaderParser$1", nullptr, nullptr, $STATIC | $SYNTHETIC},
	{"jdk.internal.net.http.Http1HeaderParser$State", "jdk.internal.net.http.Http1HeaderParser", "State", $STATIC | $FINAL | $ENUM},
	{}
};

$ClassInfo _Http1HeaderParser_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.Http1HeaderParser",
	"java.lang.Object",
	nullptr,
	_Http1HeaderParser_FieldInfo_,
	_Http1HeaderParser_MethodInfo_,
	nullptr,
	nullptr,
	_Http1HeaderParser_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.Http1HeaderParser$1,jdk.internal.net.http.Http1HeaderParser$State"
};

$Object* allocate$Http1HeaderParser($Class* clazz) {
	return $of($alloc(Http1HeaderParser));
}

bool Http1HeaderParser::$assertionsDisabled = false;

void Http1HeaderParser::init$() {
	$set(this, sb, $new($StringBuilder));
	$set(this, privateMap, $new($HashMap));
	$init($Http1HeaderParser$State);
	$set(this, state, $Http1HeaderParser$State::INITIAL);
}

$String* Http1HeaderParser::statusLine() {
	return this->statusLine$;
}

int32_t Http1HeaderParser::responseCode() {
	return this->responseCode$;
}

$HttpHeaders* Http1HeaderParser::headers() {
	$init($Http1HeaderParser$State);
	if (!Http1HeaderParser::$assertionsDisabled && !(this->state == $Http1HeaderParser$State::FINISHED)) {
		$throwNew($AssertionError, $of($$str({"Unexpected state "_s, this->state})));
	}
	return this->headers$;
}

$String* Http1HeaderParser::currentStateMessage() {
	$useLocalCurrentObjectStackCache();
	$var($String, stateName, $nc(this->state)->name());
	$var($String, msg, nullptr);
	if ($nc(stateName)->contains("INITIAL"_s)) {
		return $String::format("HTTP/1.1 header parser received no bytes"_s, $$new($ObjectArray, 0));
	} else if (stateName->contains("STATUS"_s)) {
		$assign(msg, $String::format("parsing HTTP/1.1 status line, receiving [%s]"_s, $$new($ObjectArray, {$($of($nc(this->sb)->toString()))})));
	} else if (stateName->contains("HEADER"_s)) {
		$var($String, headerName, $nc(this->sb)->toString());
		if ($nc(headerName)->indexOf((int32_t)u':') != -1) {
			$assign(headerName, $str({$(headerName->substring(0, headerName->indexOf((int32_t)u':') + 1)), "..."_s}));
		}
		$assign(msg, $String::format("parsing HTTP/1.1 header, receiving [%s]"_s, $$new($ObjectArray, {$of(headerName)})));
	} else {
		$assign(msg, $String::format("HTTP/1.1 parser receiving [%s]"_s, $$new($ObjectArray, {$($of($nc(this->sb)->toString()))})));
	}
	return $String::format("%s, parser state [%s]"_s, $$new($ObjectArray, {
		$of(msg),
		$of(this->state)
	}));
}

bool Http1HeaderParser::parse($ByteBuffer* input) {
	$useLocalCurrentObjectStackCache();
	$Objects::requireNonNull($of(input), "null input"_s);
	while (canContinueParsing(input)) {
		$init($Http1HeaderParser$1);
		switch ($nc($Http1HeaderParser$1::$SwitchMap$jdk$internal$net$http$Http1HeaderParser$State)->get($nc((this->state))->ordinal())) {
		case 1:
			{
				$init($Http1HeaderParser$State);
				$set(this, state, $Http1HeaderParser$State::STATUS_LINE);
				break;
			}
		case 2:
			{
				readResumeStatusLine(input);
				break;
			}
		case 3:
			{}
		case 4:
			{
				readStatusLineFeed(input);
				break;
			}
		case 5:
			{
				maybeStartHeaders(input);
				break;
			}
		case 6:
			{}
		case 7:
			{
				maybeEndHeaders(input);
				break;
			}
		case 8:
			{
				readResumeHeader(input);
				break;
			}
		case 9:
			{}
		case 10:
			{
				resumeOrLF(input);
				break;
			}
		case 11:
			{
				resumeOrSecondCR(input);
				break;
			}
		case 12:
			{
				resumeOrEndHeaders(input);
				break;
			}
		default:
			{
				$throwNew($InternalError, $$str({"Unexpected state: "_s, this->state}));
			}
		}
	}
	$init($Http1HeaderParser$State);
	return this->state == $Http1HeaderParser$State::FINISHED;
}

bool Http1HeaderParser::canContinueParsing($ByteBuffer* buffer) {
	$init($Http1HeaderParser$1);

	bool var$0 = false;
	switch ($nc($Http1HeaderParser$1::$SwitchMap$jdk$internal$net$http$Http1HeaderParser$State)->get($nc((this->state))->ordinal())) {
	case 13:
		{
			var$0 = false;
			break;
		}
	case 4:
		{}
	case 7:
		{}
	case 10:
		{
			var$0 = true;
			break;
		}
	default:
		{
			var$0 = $nc(buffer)->hasRemaining();
			break;
		}
	}
	return var$0;
}

char16_t Http1HeaderParser::get($ByteBuffer* input) {
	return (char16_t)((int32_t)($nc(input)->get() & (uint32_t)255));
}

void Http1HeaderParser::readResumeStatusLine($ByteBuffer* input) {
	char16_t c = (char16_t)0;
	while (true) {
		bool var$0 = $nc(input)->hasRemaining();
		if (!(var$0 && (c = get(input)) != Http1HeaderParser::CR)) {
			break;
		}
		{
			if (c == Http1HeaderParser::LF) {
				break;
			}
			$nc(this->sb)->append(c);
		}
	}
	if (c == Http1HeaderParser::CR) {
		$init($Http1HeaderParser$State);
		$set(this, state, $Http1HeaderParser$State::STATUS_LINE_FOUND_CR);
	} else if (c == Http1HeaderParser::LF) {
		$init($Http1HeaderParser$State);
		$set(this, state, $Http1HeaderParser$State::STATUS_LINE_FOUND_LF);
	}
}

void Http1HeaderParser::readStatusLineFeed($ByteBuffer* input) {
	$useLocalCurrentObjectStackCache();
	$init($Http1HeaderParser$State);
	char16_t c = this->state == $Http1HeaderParser$State::STATUS_LINE_FOUND_LF ? Http1HeaderParser::LF : get(input);
	if (c != Http1HeaderParser::LF) {
		$throw($(protocolException("Bad trailing char, \"%s\", when parsing status line, \"%s\""_s, $$new($ObjectArray, {
			$($of($Character::valueOf(c))),
			$($of($nc(this->sb)->toString()))
		}))));
	}
	$set(this, statusLine$, $nc(this->sb)->toString());
	$set(this, sb, $new($StringBuilder));
	if (!$nc(this->statusLine$)->startsWith("HTTP/1."_s)) {
		$throw($(protocolException("Invalid status line: \"%s\""_s, $$new($ObjectArray, {$of(this->statusLine$)}))));
	}
	if ($nc(this->statusLine$)->length() < 12) {
		$throw($(protocolException("Invalid status line: \"%s\""_s, $$new($ObjectArray, {$of(this->statusLine$)}))));
	}
	try {
		this->responseCode$ = $Integer::parseInt($($nc(this->statusLine$)->substring(9, 12)));
	} catch ($NumberFormatException& nfe) {
		$throw($(protocolException("Invalid status line: \"%s\""_s, $$new($ObjectArray, {$of(this->statusLine$)}))));
	}
	if (this->responseCode$ < 100) {
		$throw($(protocolException("Invalid status line: \"%s\""_s, $$new($ObjectArray, {$of(this->statusLine$)}))));
	}
	$set(this, state, $Http1HeaderParser$State::STATUS_LINE_END);
}

void Http1HeaderParser::maybeStartHeaders($ByteBuffer* input) {
	$init($Http1HeaderParser$State);
	if (!Http1HeaderParser::$assertionsDisabled && !(this->state == $Http1HeaderParser$State::STATUS_LINE_END)) {
		$throwNew($AssertionError);
	}
	if (!Http1HeaderParser::$assertionsDisabled && !($nc(this->sb)->length() == 0)) {
		$throwNew($AssertionError);
	}
	char16_t c = get(input);
	if (c == Http1HeaderParser::CR) {
		$set(this, state, $Http1HeaderParser$State::STATUS_LINE_END_CR);
	} else if (c == Http1HeaderParser::LF) {
		$set(this, state, $Http1HeaderParser$State::STATUS_LINE_END_LF);
	} else {
		$nc(this->sb)->append(c);
		$set(this, state, $Http1HeaderParser$State::HEADER);
	}
}

void Http1HeaderParser::maybeEndHeaders($ByteBuffer* input) {
	$useLocalCurrentObjectStackCache();
	$init($Http1HeaderParser$State);
	if (!Http1HeaderParser::$assertionsDisabled && !(this->state == $Http1HeaderParser$State::STATUS_LINE_END_CR || this->state == $Http1HeaderParser$State::STATUS_LINE_END_LF)) {
		$throwNew($AssertionError);
	}
	if (!Http1HeaderParser::$assertionsDisabled && !($nc(this->sb)->length() == 0)) {
		$throwNew($AssertionError);
	}
	char16_t c = this->state == $Http1HeaderParser$State::STATUS_LINE_END_LF ? Http1HeaderParser::LF : get(input);
	if (c == Http1HeaderParser::LF) {
		$init($Utils);
		$set(this, headers$, $HttpHeaders::of(this->privateMap, $Utils::ACCEPT_ALL));
		$set(this, privateMap, nullptr);
		$set(this, state, $Http1HeaderParser$State::FINISHED);
	} else {
		$throw($(protocolException("Unexpected \"%s\", after status line CR"_s, $$new($ObjectArray, {$($of($Character::valueOf(c)))}))));
	}
}

void Http1HeaderParser::readResumeHeader($ByteBuffer* input) {
	$init($Http1HeaderParser$State);
	if (!Http1HeaderParser::$assertionsDisabled && !(this->state == $Http1HeaderParser$State::HEADER)) {
		$throwNew($AssertionError);
	}
	if (!Http1HeaderParser::$assertionsDisabled && !$nc(input)->hasRemaining()) {
		$throwNew($AssertionError);
	}
	while ($nc(input)->hasRemaining()) {
		char16_t c = get(input);
		if (c == Http1HeaderParser::CR) {
			$set(this, state, $Http1HeaderParser$State::HEADER_FOUND_CR);
			break;
		} else if (c == Http1HeaderParser::LF) {
			$set(this, state, $Http1HeaderParser$State::HEADER_FOUND_LF);
			break;
		}
		if (c == Http1HeaderParser::HT) {
			c = Http1HeaderParser::SP;
		}
		$nc(this->sb)->append(c);
	}
}

void Http1HeaderParser::addHeaderFromString($String* headerString) {
	$useLocalCurrentObjectStackCache();
	if (!Http1HeaderParser::$assertionsDisabled && !($nc(this->sb)->length() == 0)) {
		$throwNew($AssertionError);
	}
	int32_t idx = $nc(headerString)->indexOf((int32_t)u':');
	if (idx == -1) {
		return;
	}
	$var($String, name, headerString->substring(0, idx));
	if (name->isEmpty()) {
		return;
	}
	if (!$Utils::isValidName(name)) {
		$throw($(protocolException("Invalid header name \"%s\""_s, $$new($ObjectArray, {$of(name)}))));
	}
	$var($String, value, $(headerString->substring(idx + 1))->trim());
	if (!$Utils::isValidValue(value)) {
		$throw($(protocolException("Invalid header value \"%s: %s\""_s, $$new($ObjectArray, {
			$of(name),
			$of(value)
		}))));
	}
	$init($Locale);
	$var($Object, var$0, $of(name->toLowerCase($Locale::US)));
	$nc(($cast($List, $($nc(this->privateMap)->computeIfAbsent(var$0, static_cast<$Function*>($$new(Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0)))))))->add(value);
}

void Http1HeaderParser::resumeOrLF($ByteBuffer* input) {
	$init($Http1HeaderParser$State);
	if (!Http1HeaderParser::$assertionsDisabled && !(this->state == $Http1HeaderParser$State::HEADER_FOUND_CR || this->state == $Http1HeaderParser$State::HEADER_FOUND_LF)) {
		$throwNew($AssertionError);
	}
	char16_t c = this->state == $Http1HeaderParser$State::HEADER_FOUND_LF ? Http1HeaderParser::LF : get(input);
	if (c == Http1HeaderParser::LF) {
		$set(this, state, $Http1HeaderParser$State::HEADER_FOUND_CR_LF);
	} else if (c == Http1HeaderParser::SP || c == Http1HeaderParser::HT) {
		$nc(this->sb)->append(Http1HeaderParser::SP);
		$set(this, state, $Http1HeaderParser$State::HEADER);
	} else {
		$set(this, sb, $new($StringBuilder));
		$nc(this->sb)->append(c);
		$set(this, state, $Http1HeaderParser$State::HEADER);
	}
}

void Http1HeaderParser::resumeOrSecondCR($ByteBuffer* input) {
	$useLocalCurrentObjectStackCache();
	$init($Http1HeaderParser$State);
	if (!Http1HeaderParser::$assertionsDisabled && !(this->state == $Http1HeaderParser$State::HEADER_FOUND_CR_LF)) {
		$throwNew($AssertionError);
	}
	char16_t c = get(input);
	if (c == Http1HeaderParser::CR || c == Http1HeaderParser::LF) {
		if ($nc(this->sb)->length() > 0) {
			$var($String, headerString, $nc(this->sb)->toString());
			$set(this, sb, $new($StringBuilder));
			addHeaderFromString(headerString);
		}
		if (c == Http1HeaderParser::CR) {
			$set(this, state, $Http1HeaderParser$State::HEADER_FOUND_CR_LF_CR);
		} else {
			$set(this, state, $Http1HeaderParser$State::FINISHED);
			$init($Utils);
			$set(this, headers$, $HttpHeaders::of(this->privateMap, $Utils::ACCEPT_ALL));
			$set(this, privateMap, nullptr);
		}
	} else if (c == Http1HeaderParser::SP || c == Http1HeaderParser::HT) {
		if (!Http1HeaderParser::$assertionsDisabled && !($nc(this->sb)->length() != 0)) {
			$throwNew($AssertionError);
		}
		$nc(this->sb)->append(Http1HeaderParser::SP);
		$set(this, state, $Http1HeaderParser$State::HEADER);
	} else {
		if ($nc(this->sb)->length() > 0) {
			$var($String, headerString, $nc(this->sb)->toString());
			$set(this, sb, $new($StringBuilder));
			addHeaderFromString(headerString);
		}
		$nc(this->sb)->append(c);
		$set(this, state, $Http1HeaderParser$State::HEADER);
	}
}

void Http1HeaderParser::resumeOrEndHeaders($ByteBuffer* input) {
	$useLocalCurrentObjectStackCache();
	$init($Http1HeaderParser$State);
	if (!Http1HeaderParser::$assertionsDisabled && !(this->state == $Http1HeaderParser$State::HEADER_FOUND_CR_LF_CR)) {
		$throwNew($AssertionError);
	}
	char16_t c = get(input);
	if (c == Http1HeaderParser::LF) {
		$set(this, state, $Http1HeaderParser$State::FINISHED);
		$init($Utils);
		$set(this, headers$, $HttpHeaders::of(this->privateMap, $Utils::ACCEPT_ALL));
		$set(this, privateMap, nullptr);
	} else {
		$throw($(protocolException("Unexpected \"%s\", after CR LF CR"_s, $$new($ObjectArray, {$($of($Character::valueOf(c)))}))));
	}
}

$ProtocolException* Http1HeaderParser::protocolException($String* format, $ObjectArray* args) {
	return $new($ProtocolException, $($String::format(format, args)));
}

$List* Http1HeaderParser::lambda$addHeaderFromString$0($String* k) {
	$init(Http1HeaderParser);
	return $new($ArrayList);
}

void clinit$Http1HeaderParser($Class* class$) {
	Http1HeaderParser::$assertionsDisabled = !Http1HeaderParser::class$->desiredAssertionStatus();
}

Http1HeaderParser::Http1HeaderParser() {
}

$Class* Http1HeaderParser::load$($String* name, bool initialize) {
	if (name != nullptr) {
		if (name->equals(Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0::classInfo$.name)) {
			return Http1HeaderParser$$Lambda$lambda$addHeaderFromString$0::load$(name, initialize);
		}
	}
	$loadClass(Http1HeaderParser, name, initialize, &_Http1HeaderParser_ClassInfo_, clinit$Http1HeaderParser, allocate$Http1HeaderParser);
	return class$;
}

$Class* Http1HeaderParser::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk