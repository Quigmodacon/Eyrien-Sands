//
//Test length and capacity functions
//

#include "string.hpp"

int main() {
	{
		String one;
		assert(one.length() == 0);
		assert(one.capacity() == 0);
	}
	{
		String one('a');
		assert(one.length() == 1);
		assert(one.capacity() == 1);
	}
	{
		String one("ab");
		assert(one.length() == 2);
		assert(one.capacity() == 2);
	}
	{
		String one("abcdeghijk");
		assert(one.length() == 10);
		assert(one.capacity() == 10);
	}
	{
		String one("abcdefghijklmnopqrstuvwxyz");
		assert(one.length() == 26);
		assert(one.capacity() == 26);
	}
	std::cout << "Done testing length and capacity\n";
}
