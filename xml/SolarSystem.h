#pragma once
#include "Planet.h"
#include "pugixml.hpp"
#include <iostream>
#include <iomanip>


class SolarSystem
{
public:
	SolarSystem() : solarFile("SolarSystem.xml") {};
	SolarSystem(std::string filePath);
	// –≈¿À»«Œ¬¿“‹ CRUD
	void print_system();
	void save_system(std::string filePath);
	void print_header();
	void print_planet();
	void append_planet();
	void delete_planet(int);


private:
	std::string solarFile;
	std::vector <Planet> planets;
};

