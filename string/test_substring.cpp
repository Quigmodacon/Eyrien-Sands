//
//Test substring function
//

#include "string.hpp"

int main() {
	String result;
	String alpha("abcdefghijklmnopqrstuvwxyz");
	
	result = alpha.substr(0, 25);
	assert(result == "abcdefghijklmnopqrstuvwxyz");
	
	result = alpha.substr(0,5);
	assert(result == "abcdef");

	result = alpha.substr(10, 10);
	assert(result == "k");

	result = alpha.substr(20, 25);
	assert(result == "uvwxyz");

	result = alpha.substr(0, 0);
	assert(result == "a");

	std::cout << "Done testing substring\n";
}
