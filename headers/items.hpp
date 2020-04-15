// Item Class
// Jonathan Hansen
// Last Updated: 2/22/2020

// Run item default constructor then run other constructors.

#ifndef __ITEMS_HPP__
#define __ITEMS_HPP__

#include "../string/string.hpp"
#include <vector>
#include <iostream>

namespace item {

	// Base Class
	class item {
	public:
		item() { static int ID = 0; id = ++ID;}
		String getName() const;
		String getDesc() const;
		int getID() const;
	protected:
		String name;
		String description;
		int id;
	};

	// Quality Types
	

	// Potion Item Class ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	class potion : public item {
		enum class Quality{Drunk, StrBoost, IntBoost, AgiBoost, RecoverHP, RecoverMP};
	public:
		potion(const String& _name, const String& _description, std::vector<String> quals);

		Quality qConvert(const String& str) const;

		friend std::ostream& operator<< (std::ostream& out, const potion& pot);
	private:
		String name;
		String description;
		std::vector<Quality> qualities;
	};

	// Weapon Item Class ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	class weapon : public item {
		enum class Quality{Poison, Holy, Unholy, Fire, Electric, Water};
		enum class Type{Ranged, Melee};
	public:
		weapon(const String& _name, const String& _description, int _damage, int _reach, const String& _type, std::vector<String> quals);

		Quality qConvert(const String& str) const;
		Type tConvert(const String& str) const;

		friend std::ostream& operator<< (std::ostream& out, const weapon& weap);
	private:
		String name;
		String description;
		int damage;
		int reach;
		Type type;
		std::vector<Quality> qualities;
	};

	// Armour Item Class ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	class armour : public item {
		enum class Quality{Poison, Holy, Unholy, Fire, Electric, Water};
		enum class Type{Helm, Chest, Arm, Wrist, Gloves, Legs, Boots};
		enum class Weight{Heavy, Medium, Light};
	public:
		armour(const String& _name, const String& _description, int _def, const String& _weight, const String& _type, std::vector<String> quals);

		Quality qConvert(const String& str) const;
		Type tConvert(const String& str) const;
		Weight wConvert(const String& str) const;

		friend std::ostream& operator<< (std::ostream& out, const armour& arm);
	private:
		String name;
		String description;
		int def;
		Weight weight;
		Type type;
		std::vector<Quality> qualities;
	};

#endif

}
