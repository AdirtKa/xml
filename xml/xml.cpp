#include <iostream>
#include "SolarSystem.h"
#include <Windows.h>
#include <fstream>
#include "pugixml.hpp"
#include <Windows.h>

Planet get_planet() {
    return Planet();
}

int main(int argc, const char* argv[]) {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    
    std::string doc_name = "Planets.xml";

    SolarSystem test(doc_name);
    test.print_system();
    test.save_system(doc_name);

    return 0;
}
