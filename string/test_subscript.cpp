//
//Test subscript operator
//

#include "string.hpp"

int main() {
	String alpha("abcdefghijklmnopqrstuvwxyz");
	assert(alpha[0] == 'a');
	assert(alpha[25] == 'z');
	assert(alpha[10] == 'k');
	alpha[0] = 'z';
	assert(alpha[0] == 'z');
	alpha[10] = 'a';
	assert(alpha[10] == 'a');

	std::cout << "Done testing subscript operator\n";
}
