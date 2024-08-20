#include "AST.h"

void ASTNode::addChild(std::unique_ptr<ASTNode> child) {
    children.push_back(std::move(child));
}

void printASTToFile(const ASTNode* node, std::ofstream& outFile, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; ++i) outFile << "  ";
    outFile << node->type << ": " << node->value << std::endl;
    for (const auto& child : node->children) {
        printASTToFile(child.get(), outFile, indent + 1);
    }
}

std::string convertASTToMarkdown(const ASTNode* node) {
    if (!node) return "";
    std::string markdown;

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
        markdown += "```python\n" + node->value + "\n```\n";
    } else if (node->type == "link") {
        markdown += node->value;
    } else if (node->type == "unordered_list" || node->type == "ordered_list") {
        // do nothing.
    } else if (node->type == "list_item") {
        markdown += node->value + "\n";
    } else if (node->type == "image") {
        markdown += node->value + "\n";
    } else if (node->type == "content") {
        markdown += node->value;
    }else if (node->type == "newline") {
        markdown += "\n";
    }

    for (const auto& child : node->children) {
        markdown += convertASTToMarkdown(child.get());
    }

    return markdown;
}
