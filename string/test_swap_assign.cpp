//
// SWAP ASSIGN TEST
//

#include "string.hpp"

int main() {
	{
		String alpha("a");
		String beta;
		beta = alpha;
		assert(alpha == beta);
		assert(alpha == "a");
		assert(beta == "a");
	}
	{
		String alpha("abcdefghijklmnopqrstuvwxyz");
		String beta;
		beta = alpha;
		assert(alpha == beta);
		assert(alpha == "abcdefghijklmnopqrstuvwxyz");
		assert(beta == "abcdefghijklmnopqrstuvwxyz");
	}
	{
		String alpha("a");
		String beta("b");
		alpha = beta;
		assert(alpha == beta);
		assert(alpha == "b");
		assert(beta == "b");
	}
	{
		String alpha("abcdefghijklmnopqrstuvwxyz");
		String beta("You uzk");
		beta = alpha;
		assert(alpha == beta);
		assert(alpha == "abcdefghijklmnopqrstuvwxyz");
		assert(beta == "abcdefghijklmnopqrstuvwxyz");
	}
}
