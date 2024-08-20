#ifndef AST_H
#define AST_H

#include <string>
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>

struct ASTNode {
    std::string type;
    std::string value;
    std::vector<std::unique_ptr<ASTNode>> children;

    ASTNode(const std::string& type, const std::string& value = "")
        : type(type), value(value) {}

    void addChild(std::unique_ptr<ASTNode> child);
};

void printASTToFile(const ASTNode* node, std::ofstream& outFile, int indent = 0);
std::string convertASTToMarkdown(const ASTNode* node);

#endif 
