#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
namespace fs = std::filesystem;

// Creates DOT file which describes how to make the graphic
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

// Changes input text file to only contain names of header (.h) files
void reduceToHeader(std::string openFile){
    std::ifstream inputFile;                         // Inital file, opened by string file name
    inputFile.open(openFile);          
    std::ofstream outputFile("replacement.txt");    // File to write to, will replace initial at end

    if(!inputFile.is_open())
    {
        std::cerr << "Error: Unable to open the file." << std::endl;
    }

    std::string line;
    while(std::getline(inputFile, line))
    {
        // Condenses file path to end file name
        line = line.substr(1, (line.length() - 1) - 1);                     // Removing quotation marks from file path
        int endIndex = line.length();                   
        int filenameIndex = line.find("/Project0/") + 10;                   // Offsetting by 10 characters in /Project0/
        int filenameLength = endIndex - filenameIndex;           
        std::string filename = line.substr(filenameIndex, filenameLength);      
        // Only output if header file
        int absoluteIndexOfDotH = filename.length() - 2;                    // ".h" is always start at 2nd last character of string i.e. "/User/abc/Project0/filename[.h]"
        if(filename.find(".h") == absoluteIndexOfDotH)
        {
            outputFile << filename << std::endl;
        }
    }

    outputFile.close();
    inputFile.close();

    rename("replacement.txt", "headerFiles.txt");
}

int main() {
    std::string path = (fs::current_path()).generic_string(); // current_path() provides path to working directory
    std::ofstream outfile("headerFiles.txt");

    // Prints out all files within working directory using filesystem library
    for (const auto & entry : fs::directory_iterator(path))
        outfile << entry.path() << std::endl;
    outfile.close();

    reduceToHeader("headerFiles.txt");

    generateDotFile();

    // Runs the DOT command line to build the image
    system("dot -Tpng inheritance_graph.dot -o inheritance_graph.png");
    return 0;
}
