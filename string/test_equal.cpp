//
//Test equality operator overloader
//

#include "string.hpp"

int main() {
	{
		String one;
		String two;

		assert(one == two);
	}
	{
		String one('a');
		String two('a');

		assert(one == two);
	}
	{
		String one('a');
		String two('b');

		assert(!(one == two));
	}
	{
		String one("I am you, father");
		String two("I am you, father");

		assert(one == two);
	}
	{
		String one("I Am Your Father");
		String two("i am your father");

		assert(!(one == two));
	}
	{
		String one("I no");
		String two("I yes");

		assert(!(one == two));
	}
	std::cout << "Done testing equal\n";
}
