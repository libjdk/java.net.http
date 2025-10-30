#include <java.net.http.test.h>

#include <jcpp.h>

class TestCases {
public:
	TestCases(int argc, char** argv) : argc(argc), argv(argv) {
		processedCount = 0;
		success = false;
	}

	bool isListAction() {
		for (int32_t i = 1; i < argc; i++) {
			$String* arg = $cstr(argv[i]);
			if ("-l"_s->equals(arg) || "--list"_s->equals(arg)) {
				return true;
			}
		}
		return false;
	}

	bool isSelectedOne() {
		bool exitsInclude = false;
		for (int32_t i = 1; i < argc; i++) {
			$String* arg = $cstr(argv[i]);
			if ("-l"_s->equals(arg) || "--list"_s->equals(arg)) {
				continue;
			} else if ("--include"_s->equals(arg)) {
				return false;
			} else if ("--exclude"_s->equals(arg)) {
				return false;
			} else {
				return true;
			}
		}
		return false;
	}

	bool isSelected(const char* caseName, bool excludeFromAll) {
		bool exitsInclude = false;
		for (int32_t i = 1; i < argc; i++) {
			$String* arg = $cstr(argv[i]);
			if ("-l"_s->equals(arg) || "--list"_s->equals(arg)) {
				continue;
			} else if ("--include"_s->equals(arg)) {
				i++;
				exitsInclude = true;
				if (i < argc) {
					$String* include = $cstr(argv[i]);
					$var($StringArray, includeArray, include->split(","_s));
					for (int32_t j = 0; j < includeArray->length; j++) {
						$String* includeItem = $arrayGet<$String>(includeArray, j);
						if ($(includeItem->trim())->equals(caseName)) {
							return true;
						}
					}
				}
			} else if ("--exclude"_s->equals(arg)) {
				i++;
				if (i < argc) {
					$String* exclude = $cstr(argv[i]);
					$var($StringArray, excludeArray, exclude->split(","_s));
					for (int32_t j = 0; j < excludeArray->length; j++) {
						$String* excludeItem = $arrayGet<$String>(excludeArray, j);
						if ($(excludeItem->trim())->equals(caseName)) {
							return false;
						}
					}
				}
			} else {
				exitsInclude = true;
				if (arg->equals(caseName)) {
					return true;
				}
			}
		}
		if (excludeFromAll) {
			return false;
		}
		return !exitsInclude;
	}

	template<typename T>
	void runCase(const char* caseName, bool excludeFromAll = false, $StringArray* args = nullptr) {
		if (isListAction()) {
			processedCount++;
			if (excludeFromAll) {
				$System::out->println($$str({ "#case "_s, $$str(processedCount), " "_s, $$str(caseName) }));
			} else {
				$System::out->println($$str({ "case "_s, $$str(processedCount), " "_s, $$str(caseName) }));
			}
		} else {
			if (isSelected(caseName, excludeFromAll)) {
				processedCount++;
				if (!isSelectedOne()) {
					$System::out->println($$str({ "case "_s, $$str(processedCount), " "_s, $$str(caseName) }));
				}
				int64_t beginMs = $System::currentTimeMillis();
				if (args != nullptr) {
					T::main(args);
				} else {
					T::main($$new($StringArray, 0));
				}
				int64_t endMs = $System::currentTimeMillis();
				$System::out->println($$str({ $$str(endMs - beginMs), "ms"_s }));
				if (!isSelectedOne()) {
					$System::out->println(""_s);
				}
			}
		}
	}

	template<typename T>
	void runCase(const char* caseName, $StringArray* args) {
		runCase<T>(caseName, false, args);
	}

	void runCases();
	int32_t isSuccess() {
		return success;
	}
private:
	int argc;
	char** argv;
	int32_t processedCount;
	bool success;
};

#define run(caseName, caseClass, ...) runCase<caseClass>(caseName, ##__VA_ARGS__);

void TestCases::runCases() {
	int64_t runCasesBeginMs = $System::currentTimeMillis();


	int64_t runCaseEndMs = $System::currentTimeMillis();
	if (processedCount > 1) {
		$System::out->println($$str({"runCases "_s, $$str(processedCount), " "_s, $$str(runCaseEndMs - runCasesBeginMs), "ms"_s}));
	}
	$System::out->flush();
	success = true;
}

int main(int argc, char** argv) {
	::java$net$http$test::init();
	TestCases testcases(argc, argv);
	try {
		testcases.runCases();
	} catch ($Throwable& e) {
		e->printStackTrace();
	}
	$System::deinit();
	return testcases.isSuccess() ? 0 : 1;
}