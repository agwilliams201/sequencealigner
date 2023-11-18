.PHONY: clean
test: sequencealigner.h sequencealigner.c sequencealigner_tests.c
	clang -Wall -o test sequencealigner.c sequencealigner_tests.c -lcriterion -lm
clean:
	rm -rf a.out test