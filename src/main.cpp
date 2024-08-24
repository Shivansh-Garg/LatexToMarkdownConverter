/**
 * @file main.cpp
 * @author Shivansh Garg(mcs242450@iitd.ac.in)
 * @brief It sets up the lexer and parser, processes the LaTeX file to generate an AST, and checks for parsing errors.
 * @version 0.1
 * @date 2024-08-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include "parser.hpp"
#include "AST.h"

using namespace std;

// Global variables
extern unique_ptr<ASTNode> root;  
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

    // Open the input file
    FILE* fileInputPointer = fopen(inputFilePath, "r");
    if (fileInputPointer == nullptr) {
        cerr << "Error: Unable to open Latex File\n";
        return 1; 
    }

    // Open the output file 
    ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open Markdown File\n";
        fclose(fileInputPointer); 
        return 1; 
    }

    // Set lexer 
    yyin = fileInputPointer;

    // Start parsing
    cout << "Starting parsing..." << endl;
    if (yyparse() != 0) { 
        cerr << "Parsing failed." << endl;
        fclose(fileInputPointer); 
        return 1; 
    }

    cout << "Parsing succeeded." << endl;

    // Check root
    if (!root) {
        cerr << "AST root is not set. Parsing may have failed." << endl;
        fclose(fileInputPointer); 
        return 1; 
    }

    // Print AST
    ofstream astFile("astOutput.txt");
    if (astFile.is_open()) {
        printASTToFile(root.get(), astFile);
        astFile.close();
        cout << "AST successfully written to: astOutput.txt" << endl;
    } else {
        cerr << "Error opening file to write AST." << endl;
    }

    // Converting AST to MARKDOWN
    string markdown = convertASTToMarkdown(root.get());
    if (outputFile.is_open()) {
        outputFile << markdown;
        outputFile.close();
        cout << "Markdown successfully written to: " << outputFilePath << endl;
    } else {
        cerr << "Error opening output file: " << outputFilePath << endl;
    }

    fclose(fileInputPointer);

    return 0;
}