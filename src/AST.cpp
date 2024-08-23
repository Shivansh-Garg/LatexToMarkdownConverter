#include "AST.h"
#include <iostream>
using namespace std;

void ASTNode::addChild(unique_ptr<ASTNode> child) {
    children.push_back(move(child));
}

void printASTToFile(const ASTNode* node, ofstream& outFile, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; ++i){outFile << "       ";}
    outFile << node->type << endl;
    for (const auto& child : node->children) {
        printASTToFile(child.get(), outFile, indent + 1);
    }
}

string convertASTToMarkdown(const ASTNode* node) {
    if (node == nullptr) {return "";}
    string markdown;

    if (node->type == "heading") {
        markdown += "# " + node->value;
    } else if (node->type == "subheading") {
        markdown += "## " + node->value;
    } else if (node->type == "subsubheading") {
        markdown += "### " + node->value;
    } else if (node->type == "bold") {
        markdown += "**" + node->value + "**";
    } else if (node->type == "italics") {
        markdown += "*" + node->value + "*";
    } else if (node->type == "horizontal_line") {
        markdown += "---";
    } else if (node->type == "paragraph") {
        markdown += "\n";
    } else if (node->type == "codeblock") {
        markdown += "```python" + node->value + "```\n";
    } else if (node->type == "link") {
        markdown += node->value;
    } else if (node->type == "unordered_list" || node->type == "ordered_list") {
        // do nothing otherwise will print 2 times
    } else if (node->type == "list_item") {
        markdown += node->value + "\n";
    } else if (node->type == "image") {
        markdown += node->value + "\n";
    } else if (node->type == "content") {
        markdown += node->value;
    }else if (node->type == "newline") {
        markdown += "\n";
    }else if (node->type == "table") {
        // do nothing otherwise will print 2 times
    } else if (node->type == "table_item") {
        markdown += node->value + "\n";  
    } else if (node->type == "table_end"){
        markdown += node->value ;
    }else if (node->type == "table_separator"){
        markdown += node->value + "\n" ;
    }

    for (const auto& child : node->children) {
        markdown += convertASTToMarkdown(child.get());
    }

    return markdown;
}
