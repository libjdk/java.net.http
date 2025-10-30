#include <jdk/internal/net/http/hpack/NaiveHuffman$Reader.h>

#include <java/io/IOException.h>
#include <java/lang/Appendable.h>
#include <java/lang/IllegalStateException.h>
#include <java/nio/ByteBuffer.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman$Node.h>
#include <jdk/internal/net/http/hpack/NaiveHuffman.h>
#include <jcpp.h>

#undef INSTANCE

using $IOException = ::java::io::IOException;
using $Appendable = ::java::lang::Appendable;
using $ClassInfo = ::java::lang::ClassInfo;
using $Exception = ::java::lang::Exception;
using $FieldInfo = ::java::lang::FieldInfo;
using $IllegalStateException = ::java::lang::IllegalStateException;
using $InnerClassInfo = ::java::lang::InnerClassInfo;
using $MethodInfo = ::java::lang::MethodInfo;
using $NullPointerException = ::java::lang::NullPointerException;
using $RuntimeException = ::java::lang::RuntimeException;
using $Buffer = ::java::nio::Buffer;
using $ByteBuffer = ::java::nio::ByteBuffer;
using $Huffman$Reader = ::jdk::internal::net::http::hpack::Huffman$Reader;
using $NaiveHuffman = ::jdk::internal::net::http::hpack::NaiveHuffman;
using $NaiveHuffman$Node = ::jdk::internal::net::http::hpack::NaiveHuffman$Node;

namespace jdk {
	namespace internal {
		namespace net {
			namespace http {
				namespace hpack {

$FieldInfo _NaiveHuffman$Reader_FieldInfo_[] = {
	{"curr", "Ljdk/internal/net/http/hpack/NaiveHuffman$Node;", nullptr, $PRIVATE, $field(NaiveHuffman$Reader, curr)},
	{"len", "I", nullptr, $PRIVATE, $field(NaiveHuffman$Reader, len)},
	{"p", "I", nullptr, $PRIVATE, $field(NaiveHuffman$Reader, p)},
	{}
};

$MethodInfo _NaiveHuffman$Reader_MethodInfo_[] = {
	{"<init>", "()V", nullptr, 0, $method(static_cast<void(NaiveHuffman$Reader::*)()>(&NaiveHuffman$Reader::init$))},
	{"read", "(Ljava/nio/ByteBuffer;Ljava/lang/Appendable;Z)V", nullptr, $PUBLIC, nullptr, "java.io.IOException"},
	{"read", "(Ljava/nio/ByteBuffer;Ljava/lang/Appendable;ZZ)V", nullptr, 0, $method(static_cast<void(NaiveHuffman$Reader::*)($ByteBuffer*,$Appendable*,bool,bool)>(&NaiveHuffman$Reader::read)), "java.io.IOException"},
	{"reset", "()V", nullptr, $PUBLIC},
	{"resetProbe", "()V", nullptr, $PRIVATE, $method(static_cast<void(NaiveHuffman$Reader::*)()>(&NaiveHuffman$Reader::resetProbe))},
	{}
};

$InnerClassInfo _NaiveHuffman$Reader_InnerClassesInfo_[] = {
	{"jdk.internal.net.http.hpack.NaiveHuffman$Reader", "jdk.internal.net.http.hpack.NaiveHuffman", "Reader", $STATIC | $FINAL},
	{"jdk.internal.net.http.hpack.Huffman$Reader", "jdk.internal.net.http.hpack.Huffman", "Reader", $PUBLIC | $STATIC | $INTERFACE | $ABSTRACT},
	{}
};

$ClassInfo _NaiveHuffman$Reader_ClassInfo_ = {
	$FINAL | $ACC_SUPER,
	"jdk.internal.net.http.hpack.NaiveHuffman$Reader",
	"java.lang.Object",
	"jdk.internal.net.http.hpack.Huffman$Reader",
	_NaiveHuffman$Reader_FieldInfo_,
	_NaiveHuffman$Reader_MethodInfo_,
	nullptr,
	nullptr,
	_NaiveHuffman$Reader_InnerClassesInfo_,
	nullptr,
	nullptr,
	nullptr,
	"jdk.internal.net.http.hpack.NaiveHuffman"
};

$Object* allocate$NaiveHuffman$Reader($Class* clazz) {
	return $of($alloc(NaiveHuffman$Reader));
}

void NaiveHuffman$Reader::init$() {
	{
		reset();
	}
}

void NaiveHuffman$Reader::read($ByteBuffer* source, $Appendable* destination, bool isLast) {
	read(source, destination, true, isLast);
}

void NaiveHuffman$Reader::read($ByteBuffer* source, $Appendable* destination, bool reportEOS, bool isLast) {
	$useLocalCurrentObjectStackCache();
	$var($NaiveHuffman$Node, c, this->curr);
	int32_t l = this->len;
	int32_t pos = $nc(source)->position();
	while (source->hasRemaining()) {
		int32_t d = source->get();
		for (; this->p != 0; this->p >>= 1) {
			$assign(c, $nc(c)->getChild((int32_t)(this->p & (uint32_t)d)));
			++l;
			if (c->isLeaf()) {
				if (reportEOS && c->isEOSPath) {
					$throwNew($IOException, "Encountered EOS"_s);
				}
				char16_t ch = 0;
				try {
					ch = c->getChar();
				} catch ($IllegalStateException& e) {
					source->position(pos);
					$throwNew($IOException, static_cast<$Throwable*>(e));
				}
				try {
					$nc(destination)->append(ch);
				} catch ($IOException& e) {
					source->position(pos);
					$throw(e);
				}
				$init($NaiveHuffman);
				$assign(c, $nc($NaiveHuffman::INSTANCE)->root);
				l = 0;
			}
			$set(this, curr, c);
			this->len = l;
		}
		resetProbe();
		++pos;
	}
	if (!isLast) {
		return;
	}
	if ($nc(c)->isLeaf()) {
		return;
	}
	if ($nc(c)->isEOSPath && this->len <= 7) {
		return;
	}
	if ($nc(c)->isEOSPath) {
		$throwNew($IOException, $$str({"Padding is too long (len="_s, $$str(this->len), ") or unexpected end of data"_s}));
	}
	$throwNew($IOException, "Not a EOS prefix padding or unexpected end of data"_s);
}

void NaiveHuffman$Reader::reset() {
	$init($NaiveHuffman);
	$set(this, curr, $nc($NaiveHuffman::INSTANCE)->root);
	this->len = 0;
	resetProbe();
}

void NaiveHuffman$Reader::resetProbe() {
	this->p = 128;
}

NaiveHuffman$Reader::NaiveHuffman$Reader() {
}

$Class* NaiveHuffman$Reader::load$($String* name, bool initialize) {
	$loadClass(NaiveHuffman$Reader, name, initialize, &_NaiveHuffman$Reader_ClassInfo_, allocate$NaiveHuffman$Reader);
	return class$;
}

$Class* NaiveHuffman$Reader::class$ = nullptr;

				} // hpack
			} // http
		} // net
	} // internal
} // jdk