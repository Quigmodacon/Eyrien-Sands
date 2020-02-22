//
// INT CTOR TEST
//

#include "string.hpp"

int main() {
	{
		String alpha(10, "abc");
		assert(alpha.capacity() == 9);
		assert(alpha.length() == 3);
		std::cout << alpha << '\n';
		assert(alpha == "abc");
	}
	{
		String alpha(5, "abcd");
		assert(alpha.capacity() == 4);
		assert(alpha.length() == 4);
		assert(alpha == "abc");
	}
	{
		String alpha(36, "abc");
		assert(alpha.capacity() == 35);
		assert(alpha.length() == 3);
		assert(alpha == "abc");
	}
}
