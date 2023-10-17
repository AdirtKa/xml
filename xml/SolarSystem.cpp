#include "SolarSystem.h"

SolarSystem::SolarSystem(std::string filePath)
{
	pugi::xml_document doc;
	doc.load_file(filePath.c_str());
	pugi::xml_node planets = doc.child("planets");
	for (pugi::xml_node planet : planets) {
		Planet(
			planet.attribute("name").value(),
			planet.attribute("weight").as_double(),
			planet.attribute("radius").as_double(),
			planet.attribute("distance").as_double(),
			{"ads"});
	};
}
