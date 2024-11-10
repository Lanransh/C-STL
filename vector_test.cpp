#include <iostream>

#if 0
    #include <vector>
	template<typename T>
	using TestVector = std::vector<T>;
#else 
    #include "vector.h"
    template<typename T>
    using TestVector = vector<T>;

#endif
	

void vector_test0() {
	TestVector<int> v = { 0, 1, 2, 3, 4 };
	for (int i : v) {
		std::cout << i << std::endl;
	}
}

int main() {
	vector_test0();
}