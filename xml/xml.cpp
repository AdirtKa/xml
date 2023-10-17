#include <iostream>
#include "Planet.h"
#include <Windows.h>
#include <fstream>
#include "pugixml.hpp"

Planet get_planet() {
    return Planet();
}

int main(int argc, const char* argv[]) {
    std::string doc_name = "Planets.xml";
    pugi::xml_document doc;
    

    //std::ifstream file(doc_name);
    /*if (file)
    {
        pugi::xml_parse_result result = doc.load_file(doc_name.c_str());
        std::cout << doc.child("Planet").attribute("Name").value();
    }*/
    
    pugi::xml_node planets = doc.append_child("planets");



    Planet earth("Earth", 5.972e24, 6371, 384400, { "Moon", "imaginary satelite" });
    pugi::xml_node planetNode = planets.append_child("planet");


    planetNode.append_attribute("name") = earth.get_name().data();
    planetNode.append_attribute("weight") = earth.get_weight();
    planetNode.append_attribute("radius_km") = earth.get_radius_km();
    planetNode.append_attribute("distance_to_earth_km") = earth.get_distance_to_earth_km();


    for (const auto& satelite : earth.get_satelites())
    {
        pugi::xml_node sateliteNode = planetNode.append_child("Satelite");
        sateliteNode.append_attribute("satelite_name") = satelite.data();
    }

    doc.save_file(doc_name.c_str());

    return 0;
}
