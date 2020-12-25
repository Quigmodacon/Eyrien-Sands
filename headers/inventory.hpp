// Inventory class
// Contains 3 maps for each of the 3 item types + gold counter;
// Jonathan Hansen
// Last Updated: 2/22/2020

#include <map>
#include "../string/string.hpp"

#ifndef _INVENTORY_HPP_
#define _INVENTORY_HPP_

namespace inventory {
	
	template <typename u>
	class inventory {
	public:
		inventory();
		u getItemCount(String itemName) const;
		void addItem(u item);
	private:
		std::map<u, int> itemList;
	};

}

#endif
