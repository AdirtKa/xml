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
	// ����������� CRUD
	void print_system();
	void save_system(std::string filePath);
	void print_header();
	void print_planet();


private:
	std::string solarFile;
	std::vector <Planet> planets;
};

