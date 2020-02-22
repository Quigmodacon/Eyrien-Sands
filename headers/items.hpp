// Item Class
// Jonathan Hansen
// Last Updated: 2/22/2020

#ifndef __ITEMS_HPP__
#define __ITEMS_HPP__

#include "./string/string.hpp"
#include <vector>
#include <iostream>

namespace item {

	// Quality Types
	

	// Potion Item Class ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	class potion {
		enum class Quality{Drunk, StrBoost, IntBoost, AgiBoost,
			RecoverHP, RecoverMP};
	public:
		potion(const String& _name, const String& _description, vector<String> quals);

		Quality qConvert(const String& str) const;

		friend std::ostream& operator<< (std::ostream& out, const potion& pot) const;
	private:
		String name;
		String description;
		vector<Quality> qualities;
	};

	// Weapon Item Class ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	class weapon {
		enum class Quality{Poison, Holy, Unholy, Fire, Electric, Water};
		enum class Type{Ranged, Melee}
	public:
		potion(const String& _name, const String& _description, int _damage, int _reach, const String& _type, vector<String> quals);

		Quality qConvert(const String& str) const;
		Type tConvert(const String& str) const;

		friend std::ostream& operator<< (std::ostream& out, const weapon& weap);
	private:
		String name;
		String description;
		int damage;
		int reach;
		Type type;
		vector<Quality> qualities
	}

#endif

}