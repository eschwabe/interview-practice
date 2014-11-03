# Build and run practice problems

PROGS= src/removechars
PROGS+=src/stringpermutations
PROGS+=src/stringcombinations
PROGS+=src/stablesort
PROGS+=src/producerconsumer
PROGS+=src/philosophers
PROGS+=src/convert
PROGS+=src/reversewords
PROGS+=src/zeromatrix
PROGS+=src/libds

CXX=g++
CXXFLAGS=-Wall -Werror -std=c++11 -g -O0

.PRONY: all clean check

all: $(PROGS)

$(PROGS): % : %.cpp
	@echo ">> BUILD: $@"; \
	$(CXX) $(CXXFLAGS) $< -o $@; \
	if [ $$? != 0 ]; then \
		echo "\033[0;31mFailure\033[0m"; \
	else \
		echo "\033[0;32mSuccess\033[0m"; \
	fi; \

check: $(PROGS)
	@for PROG in $(PROGS); do \
		echo ">> TEST: $${PROG}"; \
		$${PROG}; \
		if [ $$? != 0 ]; then \
			echo "\033[0;31mFailure\033[0m"; \
		else \
			echo "\033[0;32mSuccess\033[0m"; \
		fi; \
	done

clean:
	@rm -r $(PROGS) src/*.dSYM >/dev/null 2>&1 || echo "\033[0;32mCleaned\033[0m"
