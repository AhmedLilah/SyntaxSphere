#include <cstdio>

template <auto ... Args>
void printTypeAndValue(Args ... args) {
	@meta for (int i=0; i<sizeof...(Args); ++i) {
		printf("%s", Args...[0].string);
	}
}

auto main() -> int {
	printTypeAndValue(505, 5.0, 'c', "char");
	return 0;
}
