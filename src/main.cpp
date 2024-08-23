#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include "parser.hpp"
#include "AST.h"

using namespace std;

// Global variables
unique_ptr<ASTNode> root = nullptr;  
extern int yyparse();             
extern int yylex();               
extern void yyerror(const char* s); 
extern FILE* yyin; 

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Error USAGE: " << argv[0] << " <input.txt> <output.md>\n";
        return 1; // Exit with an error code
    }

    const char* inputFilePath = argv[1];
    const char* outputFilePath = argv[2];

    // Open the input file in read mode
    FILE* fileInputPointer = fopen(inputFilePath, "r");
    if (fileInputPointer == nullptr) {
        cerr << "Error: Unable to open Latex File\n";
        return 1; 
    }

    // Open the output file in write mode
    ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open Markdown File\n";
        fclose(fileInputPointer); 
        return 1; 
    }

    // Set the lexer input to the input file
    yyin = fileInputPointer;

    // Start parsing
    cout << "Starting parsing..." << endl;
    if (yyparse() != 0) { 
        cerr << "Parsing failed." << endl;
        fclose(fileInputPointer); 
        return 1; 
    }

    cout << "Parsing succeeded." << endl;

    // Check if the root is correctly set
    if (!root) {
        cerr << "AST root is not set. Parsing may have failed." << endl;
        fclose(fileInputPointer); 
        return 1; 
    }

    // Print the AST to a file
    ofstream astFile("astOutput.txt");
    if (astFile.is_open()) {
        printASTToFile(root.get(), astFile);
        astFile.close();
        cout << "AST successfully written to: astOutput.txt" << endl;
    } else {
        cerr << "Error opening file to write AST." << endl;
    }

    // Convert AST to Markdown and write it to the output file
    string markdown = convertASTToMarkdown(root.get());
    if (outputFile.is_open()) {
        outputFile << markdown;
        outputFile.close();
        cout << "Markdown successfully written to: " << outputFilePath << endl;
    } else {
        cerr << "Error opening output file: " << outputFilePath << endl;
    }

    // Close the input file
    fclose(fileInputPointer);

    return 0;
}