//
// Test ctor charArray
//

#include "string.hpp"

int main() {
	{
		String one("likeme");
		std::cout << one << std::endl;
	}
	{
		String one("why do you not like me mister it is really very rude");
		std::cout << one << std::endl;
	}
	{
		String one("p");
		std::cout << one << std::endl;
	}
}
