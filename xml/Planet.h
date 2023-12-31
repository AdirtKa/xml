#pragma once
#include <string>
#include <vector>


class Planet
{
public:
	Planet() : name("Uknown name"), weight(0), satelites(), radius_km(0), distance_to_earth_km(0) {};
	Planet(std::string planet_name, double planet_weight, double radius, double distance, std::vector <std::string> planet_satelites = {}) :
		name(planet_name), weight(planet_weight), radius_km(radius), distance_to_earth_km(distance), satelites(planet_satelites) {};

	std::string get_name() { return this->name; };
	double get_weight() { return this->weight; };
	std::vector <std::string> get_satelites() { return this->satelites; };
	double get_radius_km() { return this->radius_km; };
	double get_distance_to_earth_km() { return this->distance_to_earth_km; };
	void save_to_xml(const std::string&);
	void append_satelite(std::string);

private:
	std::string name;
	double weight;
	std::vector <std::string> satelites;
	double radius_km;
	double distance_to_earth_km;

};

