//
// Test for split function
//

#include "string.hpp"

int main() {
	String alpha("abc ef gh");
	String beta("-a--b-");
	std::vector<String> one = alpha.split(' ');
	for (std::vector<String>::const_iterator i = one.begin(); i != one.end(); ++i)
   		std::cout << *i << ' ';
	std::cout << std::endl;
	std::vector<String> two = beta.split('-');
	for (std::vector<String>::const_iterator i = two.begin(); i != two.end(); ++i)
   		std::cout << *i << ' ';
	std::cout << std::endl;


	{
		String test("O");
		std::vector<String> testV {"O"};
		std::vector<String> result = test.split(' ');
		assert(result[0] == testV[0]);
	}
	{
		String test(" O ");
		std::vector<String> testV {"", "O", ""};
		std::vector<String> result = test.split(' ');
		assert(result.size() == testV.size());
		assert(result[0] == testV[0]);
	}
	{
		String test("Op e nin g");
		std::vector<String> testV {"Op", "e", "nin", "g"};
		std::vector<String> result = test.split(' ');
		assert(result.size() == testV.size());
		assert(result == testV);
	}
	{
		String test("  a  b  c  de  ");
		std::vector<String> testV {"", "", "a", "", "b", "", "c", "", "de", "", ""};
		std::vector<String> result = test.split(' ');
		assert(result.size() == testV.size());
		assert(result[0] == testV[0]);
	}
	{
		String test(" Or acl");
		std::vector<String> testV {"", "Or", "acl"};
		std::vector<String> result = test.split(' ');
		assert(result[2] == testV[2]);
	}
	{
		String test("Or cle ");
		std::vector<String> testV {"Or", "cle", ""};
		std::vector<String> result = test.split(' ');
		assert(result[2] == testV[2]);
	}
	{
		String test(" ");
		std::vector<String> testV {"", ""};
		std::vector<String> result = test.split(' ');
		assert(result.size() == testV.size());
		assert(result[0] == testV[0]);
		assert(result[1] == testV[1]);
	}
	{
		String test("a\nb\nc\nd");
		std::vector<String> testV {"a", "b", "c", "d"};
		std::vector<String> result = test.split('\n');
		
		std::cout << result.size() << std::endl;
		for (std::vector<String>::const_iterator i = result.begin(); i != result.end(); ++i)
   			std::cout << '"' << *i << '"' << ' ';
		std::cout << std::endl;

		assert(result.size() == testV.size());
		assert(result == testV);
	}
}
