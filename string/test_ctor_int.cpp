//
// INT CTOR TEST
//

#include "string.hpp"

int main() {
	{
		String alpha(10);
		assert(alpha.capacity() == 9);
		assert(alpha.length() == 0);
	}
	{
		String alpha(24);
		assert(alpha.capacity() == 23);
		assert(alpha.length() == 0);
	}
	{
		String alpha(1);
		assert(alpha.capacity() == 0);
		assert(alpha.length() == 0);
	}
}
