#pragma once
#include "Planet.h"
#include "pugixml.hpp"


class SolarSystem
{
public:
	SolarSystem() : solarFile("SolarSystem.xml") {};
	SolarSystem(std::string filePath);
	// –≈¿À»«Œ¬¿“‹ CRUD


private:
	std::string solarFile;
	std::vector <Planet> planets;
};

