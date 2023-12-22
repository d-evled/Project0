#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

#include "../lib/reduceToHeader.h"
#include "../lib/generateDot.h"
namespace fs = std::filesystem;

int main() {
    std::string path = (fs::current_path()).generic_string(); // current_path() provides path to working directory
    std::ofstream outfile("../exe/headerFiles.txt");

    // Prints out all files within working directory using filesystem library
    for (const auto & entry : fs::directory_iterator(path))
        outfile << entry.path() << std::endl;
    outfile.close();

    reduceToHeader("../exe/headerFiles.txt");

    generateDotFile();

    // Runs the DOT command line to build the image
    system("dot -Tpng ../exe/inheritance_graph.dot -o ../exe/inheritance_graph.png");
    return 0;
}
