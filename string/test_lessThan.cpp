//
//Test less thaaaaan operator overloader
//

#include "string.hpp"

int main() {
	{
		String one;
		String two;

		assert(!(one < two));
	}
	{
		String one('a');
		String two('b');

		assert(one < two);
	}
	{
		String one('a');
		String two("apple");

		assert(one < two);
	}
	{
		String one("missile");
		String two("mixer");

		assert(one < two);
	}
	{
		String one("r");
		String two("a");

		assert(!(one < two));
	}
	{
		String one('a');
		String two('a');

		assert(one <= two);
	}
	{
		String one('a');
		String two('b');

		assert(one <= two);
	}
	{
		String one('a');
		
		assert(one < 'b');
	}
	{
		String one('b');
		
		assert(!(one < 'a'));
	}
	{
		String one('a');
		
		assert(one <= 'b');
	}
	{
		String one('b');
		
		assert(!(one <= 'a'));
	}
	{
		String one('a');
		
		assert(one <= 'a');
	}
	{
		String one('a');
		
		assert(one < "balogna");
	}
	std::cout << "Done testing less than\n";
}
