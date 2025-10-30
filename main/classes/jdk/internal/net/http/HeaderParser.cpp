#include <jdk/internal/net/http/HeaderParser.h>

#include <java/util/Iterator.h>
#include <java/util/Locale.h>
#include <jdk/internal/net/http/HeaderParser$ParserIterator.h>
#include <jcpp.h>

#undef US

using $StringArray2 = $Array<::java::lang::String, 2>;
using $ClassInfo = ::java::lang::ClassInfo;
using $FieldInfo = ::java::lang::FieldInfo;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $Iterator = ::java::util::Iterator;
using $Locale = ::java::util::Locale;
using $HeaderParser$ParserIterator = ::jdk::internal::net::http::HeaderParser$ParserIterator;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {

$FieldInfo _HeaderParser_FieldInfo_[] = {
	{"raw", "Ljava/lang/String;", nullptr, 0, $field(HeaderParser, raw)},
	{"tab", "[[Ljava/lang/String;", nullptr, 0, $field(HeaderParser, tab)},
	{"nkeys", "I", nullptr, 0, $field(HeaderParser, nkeys)},
	{"asize", "I", nullptr, 0, $field(HeaderParser, asize)},
	{}
};

$MethodInfo _HeaderParser_MethodInfo_[] = {
	{"<init>", "(Ljava/lang/String;)V", nullptr, $PUBLIC, $method(static_cast<void(HeaderParser::*)($String*)>(&HeaderParser::init$))},
	{"findKey", "(I)Ljava/lang/String;", nullptr, $PUBLIC},
	{"findValue", "(I)Ljava/lang/String;", nullptr, $PUBLIC},
	{"findValue", "(Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"findValue", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", nullptr, $PUBLIC},
	{"keys", "()Ljava/util/Iterator;", "()Ljava/util/Iterator<Ljava/lang/String;>;", $PUBLIC},
	{"parse", "()V", nullptr, $PRIVATE, $method(static_cast<void(HeaderParser::*)()>(&HeaderParser::parse))},
	{"toString", "()Ljava/lang/String;", nullptr, $PUBLIC},
	{}
};

$InnerClassInfo _HeaderParser_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.HeaderParser$ParserIterator", "jdk.internal.net.http.HeaderParser", "ParserIterator", 0},
	{}
};

$ClassInfo _HeaderParser_ClassInfo_ = {
	$ACC_SUPER,
	"jdk.internal.net.http.HeaderParser",
	"java.lang.Object",
	nullptr,
	_HeaderParser_FieldInfo_,
	_HeaderParser_MethodInfo_,
	nullptr,
	nullptr,
	_HeaderParser_InnerClassesInfo_,
	nullptr,
	nullptr,
	"jdk.internal.net.http.HeaderParser$ParserIterator"
};

$Object* allocate$HeaderParser($Class* clazz) {
	return $of($alloc(HeaderParser));
}

void HeaderParser::init$($String* raw) {
	this->asize = 10;
	$set(this, raw, raw);
	$set(this, tab, $new($StringArray2, this->asize, 2));
	parse();
}

void HeaderParser::parse() {
	$useLocalCurrentObjectStackCache();
	if (this->raw != nullptr) {
		$set(this, raw, $nc(this->raw)->trim());
		$var($chars, ca, $nc(this->raw)->toCharArray());
		int32_t beg = 0;
		int32_t end = 0;
		int32_t i = 0;
		bool inKey = true;
		bool inQuote = false;
		int32_t len = ca->length;
		while (end < len) {
			char16_t c = ca->get(end);
			if ((c == u'=') && !inQuote) {
				$init($Locale);
				$nc($nc(this->tab)->get(i))->set(0, $($$new($String, ca, beg, end - beg)->toLowerCase($Locale::US)));
				inKey = false;
				++end;
				beg = end;
			} else if (c == u'\"') {
				if (inQuote) {
					$nc($nc(this->tab)->get(i++))->set(1, $$new($String, ca, beg, end - beg));
					inQuote = false;
					do {
						++end;
					} while (end < len && (ca->get(end) == u' ' || ca->get(end) == u','));
					inKey = true;
					beg = end;
				} else {
					inQuote = true;
					++end;
					beg = end;
				}
			} else if (c == u' ' || c == u',') {
				if (inQuote) {
					++end;
					continue;
				} else if (inKey) {
					$init($Locale);
					$nc($nc(this->tab)->get(i++))->set(0, $(($$new($String, ca, beg, end - beg))->toLowerCase($Locale::US)));
				} else {
					$nc($nc(this->tab)->get(i++))->set(1, ($$new($String, ca, beg, end - beg)));
				}
				while (end < len && (ca->get(end) == u' ' || ca->get(end) == u',')) {
					++end;
				}
				inKey = true;
				beg = end;
			} else {
				++end;
			}
			if (i == this->asize) {
				this->asize = this->asize * 2;
				$var($StringArray2, ntab, $new($StringArray2, this->asize, 2));
				$System::arraycopy(this->tab, 0, ntab, 0, $nc(this->tab)->length);
				$set(this, tab, ntab);
			}
		}
		if (--end > beg) {
			if (!inKey) {
				if (ca->get(end) == u'\"') {
					$nc($nc(this->tab)->get(i++))->set(1, ($$new($String, ca, beg, end - beg)));
				} else {
					$nc($nc(this->tab)->get(i++))->set(1, ($$new($String, ca, beg, end - beg + 1)));
				}
			} else {
				$init($Locale);
				$nc($nc(this->tab)->get(i++))->set(0, $(($$new($String, ca, beg, end - beg + 1))->toLowerCase($Locale::US)));
			}
		} else if (end == beg) {
			if (!inKey) {
				if (ca->get(end) == u'\"') {
					$nc($nc(this->tab)->get(i++))->set(1, $($String::valueOf(ca->get(end - 1))));
				} else {
					$nc($nc(this->tab)->get(i++))->set(1, $($String::valueOf(ca->get(end))));
				}
			} else {
				$init($Locale);
				$nc($nc(this->tab)->get(i++))->set(0, $($($String::valueOf(ca->get(end)))->toLowerCase($Locale::US)));
			}
		}
		this->nkeys = i;
	}
}

$String* HeaderParser::findKey(int32_t i) {
	if (i < 0 || i > this->asize) {
		return nullptr;
	}
	return $nc($nc(this->tab)->get(i))->get(0);
}

$String* HeaderParser::findValue(int32_t i) {
	if (i < 0 || i > this->asize) {
		return nullptr;
	}
	return $nc($nc(this->tab)->get(i))->get(1);
}

$String* HeaderParser::findValue($String* key) {
	return findValue(key, nullptr);
}

$String* HeaderParser::findValue($String* k$renamed, $String* Default) {
	$var($String, k, k$renamed);
	if (k == nullptr) {
		return Default;
	}
	$init($Locale);
	$assign(k, $nc(k)->toLowerCase($Locale::US));
	for (int32_t i = 0; i < this->asize; ++i) {
		if ($nc($nc(this->tab)->get(i))->get(0) == nullptr) {
			return Default;
		} else if (k->equals($nc($nc(this->tab)->get(i))->get(0))) {
			return $nc($nc(this->tab)->get(i))->get(1);
		}
	}
	return Default;
}

$Iterator* HeaderParser::keys() {
	return $new($HeaderParser$ParserIterator, this, false);
}

$String* HeaderParser::toString() {
	$useLocalCurrentObjectStackCache();
	$var($Iterator, k, keys());
	$var($StringBuilder, sb, $new($StringBuilder));
	sb->append("{size="_s)->append(this->asize)->append(" nkeys="_s)->append(this->nkeys)->append(u' ');
	for (int32_t i = 0; $nc(k)->hasNext(); ++i) {
		$var($String, key, $cast($String, k->next()));
		$var($String, val, findValue(i));
		if (val != nullptr && ""_s->equals(val)) {
			$assign(val, nullptr);
		}
		sb->append(" {"_s)->append(key)->append(val == nullptr ? ""_s : $$str({","_s, val}))->append(u'}');
		if (k->hasNext()) {
			sb->append(u',');
		}
	}
	sb->append(" }"_s);
	return sb->toString();
}

HeaderParser::HeaderParser() {
}

$Class* HeaderParser::load$($String* name, bool initialize) {
	$loadClass(HeaderParser, name, initialize, &_HeaderParser_ClassInfo_, allocate$HeaderParser);
	return class$;
}

$Class* HeaderParser::class$ = nullptr;

			} // http
		} // net
	} // internal
} // jdk