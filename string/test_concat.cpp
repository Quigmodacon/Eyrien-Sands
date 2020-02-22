//
//Test concatenation
//

#include "string.hpp"

int main() {
	{
		String result;
		String one("I");
		String two(" love");

		result = one + two;
		
		assert(result == "I love");

		result = two + one;

		assert(result == " loveI");
	}
	{
		String result;
		String one("I");

		result = one + " love";
		
		assert(result == "I love");

		result = " love" + one;
		
		assert(result == " loveI");
	}
	{
		String result;
		String one("abcdefghijklmnopqrstuvwxyz");

		result = one + "abcdefghijklmnopqrstuvwxyz";
		
		assert(result == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");

		result = "abcdefghijklmnopqrstuvwxyz" + one;
		
		assert(result == "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
	}
	{
		String result;
		String one("banana");

		result = one + 's';
		assert(result == "bananas");

		result = 's' + one;
		assert(result == "sbanana");
	}
	std::cout << "Done testing concat\n";
}
