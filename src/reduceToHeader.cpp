#include "../lib/reduceToHeader.h"
#include <iostream>
#include <fstream>
#include <string>

// Changes input text file to only contain names of header (.h) files
void reduceToHeader(std::string openFile){
    std::ifstream inputFile;                         // Inital file, opened by string file name
    inputFile.open(openFile);          
    std::ofstream outputFile("../exe/replacement.txt");    // File to write to, will replace initial at end

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
        if(filename.find(".h") == static_cast<long long unsigned int>(absoluteIndexOfDotH))
        {
            outputFile << filename << std::endl;
        }
    }

    outputFile.close();
    inputFile.close();

    rename("../exe/replacement.txt", "../exe/headerFiles.txt");
}