//
//Test greater thaaaaan operator overloader
//

#include "string.hpp"

int main() {
	{
		String one;
		String two;

		assert(!(one > two));
	}
	{
		String one('b');
		String two('a');

		assert(one > two);
	}
	{
		String one("appletart");
		String two("apple");

		assert(one > two);
	}
	{
		String one("missile");
		String two("mixer");

		assert(!(one > two));
	}
	{
		String one("r");
		String two("a");

		assert(one > two);
	}
	{
		String one('a');
		String two('a');

		assert(one >= two);
	}
	{
		String one('b');
		String two('a');

		assert(one >= two);
	}
	{
		String one("loveme");
		
		assert(one > "love");
		assert(one >= "love");
		assert(one >= "loveme");
	}
	std::cout << "Done testing greater than\n";
}
