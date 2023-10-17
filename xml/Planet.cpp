#include "Planet.h"
#include "pugixml.hpp"

void Planet::save_to_xml(const std::string& filename)
{
    pugi::xml_document doc;
    pugi::xml_node planetNode = doc.append_child("Planet");

    planetNode.append_attribute("name") = name.c_str();
    planetNode.append_attribute("weight") = weight;
    planetNode.append_attribute("radius_km") = radius_km;
    planetNode.append_attribute("distance_to_earth_km") = distance_to_earth_km;

    for (const auto& satelite : satelites)
    {
        pugi::xml_node sateliteNode = planetNode.append_child("Satelite");
        sateliteNode.append_child(pugi::node_pcdata).set_value(satelite.c_str());
    }

    doc.save_file(filename.c_str());
}

void Planet::append_satelite(std::string satelite)
{
    this->satelites.push_back(satelite);
}
