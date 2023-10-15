#include <iostream>
#include "Planet.h"
#include <Windows.h>


Planet get_planet() {
    return Planet();
}

int main(int argc, const char* argv[]) {
    std::string doc_name = "Planets.xml";

    Planet earth("Earth", 5.972e24, { "Moon", "imaginary satelite"}, 6371, 384400);
    earth.save_to_xml("Uknown.xml");


    return 0;
}
