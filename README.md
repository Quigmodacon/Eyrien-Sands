# Eyrien-Sands
Laresh laments his home's destruction and leaves to find retribution.

Travel through all of the Ahmeshian Diarchy.
Descriptions of every location, with cities having shops and homes you can enter.
Currency control, with price changes.
gain abilities through the Genie. (Sand, Sun, and Freedom)
Destroy the Capital to finish main story.
Save and quit to continue any time.
fight wild creatures and eat them to survive in the desert.

~~~Psuedocode~~~

~MAP~
vector of vectors of mapTile pointers.
mapTiles{
	int x, y
	string Description
	string Name
	string Type
	vector<items>
	itemps<loot>
	
}
desert and scrub tiles will have generally the same description.

~ITEMS~

items {
	string description
	string name
	string type
}

~Monsters~

monsters {
	int health
	int stre
	int agil
	int inte
	items equipped
	items loot
}

~Player~ {
	int health
	int stre
	int agil
	int inte
	items equipped
	items inve
	mapTiles* location
}