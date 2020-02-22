//
//Test find string
//

#include "string.hpp"

int main() {
	String alpha("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz");
	assert(alpha.findstr(0, "abc") == 0);
	assert(alpha.findstr(0, "zab") == 25);
	assert(alpha.findstr(10, "abc") == 26);
	assert(alpha.findstr(26, "abc") == 26);

	std::cout << "Done testing find string\n";
}
