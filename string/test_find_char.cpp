//
// Test find ch
//

#include "string.hpp"

int main() {
	String alpha("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
	assert(alpha.findch(0, 'a') == 0);
	assert(alpha.findch(20, 'a') == 26);
	assert(alpha.findch(30, 'a') == -1);
	assert(alpha.findch(0, 'z') == 25);
	assert(alpha.findch(25, 'z') == 25);
	assert(alpha.findch(26, 'z') == 51);
	std::cout << "Done testing find char\n";
}
