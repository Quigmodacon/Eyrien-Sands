//
// Char ctor test
//

#include "string.hpp"

int main() {
	{
		String one('a');
		std::cout << one << std::endl;
	}
	{
		String one('b');
		std::cout << one << std::endl;
	}
	{
		String one('y');
		std::cout << one << std::endl;
	}
	{
		String one('U');
		std::cout << one << std::endl;
	}
}
