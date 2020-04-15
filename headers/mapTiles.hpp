// Map Class
// Jonathan Hansen
// Last Updated: 2/22/2020

#ifndef __MAP_TILES_HPP__
#define __MAP_TILES_HPP__

#include "point.hpp"
#include "../string/string.hpp"
#include <vector>
#include "inventory.hpp"

namespace mapTiles {
	// Creates tiles for map class
	class mapTiles {
		enum class Type{Desert, Plains, Beach, Lake, City, Town, Village, Forest};
	public:
		mapTiles();
		mapTiles(point::point coords, String name, String description, Type type);
		inventory::inventory* lootArea();
	private:
		point::point coords;
		String name;
		String description;
		Type type;
		inventory::inventory loot;
	};
};

#endif