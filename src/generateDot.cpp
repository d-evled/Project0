#include "../lib/generateDot.h"
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

// Creates DOT file which describes how to make the graphic
void generateDotFile() {

    // debugging statements, delete later
    std::filesystem::path currentPath = std::filesystem::current_path();
    std::cout << "Current working directory: " << currentPath << std::endl;

    std::ofstream dotFile("../exe/inheritance_graph.dot");

    if (dotFile.is_open()) {
        dotFile << "digraph InheritanceGraph {\n";

        // Add edges for inheritance relationships
        dotFile << "  Animal -> Dog [label=\"inherits\"];\n";

        dotFile << "}\n";
        dotFile.close();
    } else {
        std::cerr << "Error: Unable to open DOT file." << std::endl;
    }
}