#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

void generateDotFile() {
    std::ofstream dotFile("inheritance_graph.dot");

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

int main() {
    fs::path path = fs::current_path(); // current_path() provides path to working directory
    std::string pathStr = path.u8string();

    // Prints out all files within working directory using filesystem library
    for (const auto & entry : fs::directory_iterator(path))
        std::cout << entry.path() << std::endl;


    generateDotFile();

    // Runs the DOT command line to build the image
    system("dot -Tpng inheritance_graph.dot -o inheritance_graph.png");
    return 0;
}
