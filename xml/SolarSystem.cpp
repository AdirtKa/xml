#include "SolarSystem.h"

SolarSystem::SolarSystem(std::string fileName)
{
	pugi::xml_document doc;
	doc.load_file(fileName.c_str());
	pugi::xml_node planets = doc.child("planets");
	for (pugi::xml_node xml_planet : planets) {
		Planet planet(
			xml_planet.attribute("name").value(),
			xml_planet.attribute("weight").as_double(),
			xml_planet.attribute("radius_km").as_double(),
			xml_planet.attribute("distance_to_earth_km").as_double()
			);

		for (pugi::xml_node satelite : xml_planet) {
			planet.append_satelite(satelite.attribute("satelite_name").value());
		}

		this->planets.push_back(planet);
	}
}



void SolarSystem::print_system()
{
	this->print_header();
	this->print_planet();
}

void SolarSystem::save_system(std::string doc_name)
{
	pugi::xml_document doc;
	pugi::xml_node planets = doc.append_child("planets");



	for (Planet planet: this->planets)
	{
		pugi::xml_node planetNode = planets.append_child("planet");

		planetNode.append_attribute("name") = planet.get_name().data();
		planetNode.append_attribute("weight") = planet.get_weight();
		planetNode.append_attribute("radius_km") = planet.get_radius_km();
		planetNode.append_attribute("distance_to_earth_km") = planet.get_distance_to_earth_km();


		for (const std::string satelite : planet.get_satelites())
		{
			pugi::xml_node sateliteNode = planetNode.append_child("satelite");
			sateliteNode.append_attribute("satelite_name") = satelite.data();
		}
	}

	doc.save_file(doc_name.c_str());
}

void SolarSystem::print_header()
{
	std::cout
		<< " -----------------------------------------------------------------------------------------------------\n"
		<< "|                                         База Данных Студентов                                       |\n"
		<< " -----------------------------------------------------------------------------------------------------\n"
		<< "|  Название  |      Масса       |     Радиус (км)     |  Расстояние до земли(км)  |  Кол-во спутников |\n"
		<< " -----------------------------------------------------------------------------------------------------\n";
}

void SolarSystem::print_planet()
{
	for (Planet planet : this->planets) {
		std::cout 
			<< '|' << std::setw(12) << planet.get_name()
			<< '|' << std::setw(18) << planet.get_weight()
			<< '|' << std::setw(21) << planet.get_radius_km()
			<< '|' << std::setw(27) << planet.get_distance_to_earth_km()
			<< '|' << std::setw(19) << planet.get_satelites().size() << "|\n"
			<< " -----------------------------------------------------------------------------------------------------\n";
	}
}

void SolarSystem::append_planet()
{
	double weight, radius, distance_to_earth;
	std::string name, satelite;
	std::vector <std::string> satelites;
	int satelites_count;

	std::cout << "Введите название планеты: "; std::cin >> name;
	std::cout << "Введите массу планеты: "; std::cin >> weight;
	std::cout << "Введите радиус планеты в км: "; std::cin >> radius;
	std::cout << "Введите расстояние от планеты до земли в км: "; std::cin >> distance_to_earth;
	std::cout << "Введите кол-во спутников планеты: "; std::cin >> satelites_count;

	for (size_t i = 0; i < satelites_count; i++)
	{
		std::cout << "Введите имя спутника: "; std::cin >> satelite;
		satelites.push_back(satelite);
	}

	this->planets.push_back(Planet(
		name,
		weight,
		radius,
		distance_to_earth,
		satelites
	));


}

void SolarSystem::delete_planet(int index)
{
	this->planets.erase(this->planets.begin() + index);
}
