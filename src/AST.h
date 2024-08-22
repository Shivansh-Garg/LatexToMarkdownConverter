#ifndef AST_H
#define AST_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

struct ASTNode {
    string type;
    string value;
    vector<unique_ptr<ASTNode>> children;

    ASTNode(const string& type, const string& value = "")
        : type(type), value(value) {}

    void addChild(unique_ptr<ASTNode> child);
};

void printASTToFile(const ASTNode* node, ofstream& outFile, int indent = 0);
string convertASTToMarkdown(const ASTNode* node);
extern unique_ptr<ASTNode> root;

#endif 
