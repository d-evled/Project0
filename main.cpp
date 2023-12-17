#include <iostream>
#include <fstream>

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
    generateDotFile();
    // You can also launch an external viewer for the generated PNG file here.
    return 0;
}
