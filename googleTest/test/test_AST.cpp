#include <gtest/gtest.h>
#include "AST.h"
#include <memory>
#include <sstream>
#include <iostream>
using namespace std;

TEST(ASTNodeTest1, ConvertASTToMarkdownHeading) {
    ASTNode root("heading", "This is a heading");
    string markdown = convertASTToMarkdown(&root);
    EXPECT_EQ(markdown, "# This is a heading");
}

TEST(ASTNodeTest2, ConvertASTToMarkdownSubheading) {
    ASTNode root("subheading", "This is a subheading");
    string markdown = convertASTToMarkdown(&root);
    EXPECT_EQ(markdown, "## This is a subheading");
}

TEST(ASTNodeTest3, ConvertASTToMarkdownBold) {
    ASTNode root("bold", "This is bold text");
    string markdown = convertASTToMarkdown(&root);
    EXPECT_EQ(markdown, "**This is bold text**");
}

TEST(ASTNodeTest4, ConvertASTToMarkdownItalics) {
    ASTNode root("italics", "This is italic text");
    string markdown = convertASTToMarkdown(&root);
    EXPECT_EQ(markdown, "*This is italic text*");
}

TEST(ASTNodeTest5, ConvertASTToMarkdownUnorderedList) {
    ASTNode root("unordered_list", "");
    unique_ptr<ASTNode> item1 = make_unique<ASTNode>("list_item", "- Item 1");
    unique_ptr<ASTNode> item2 = make_unique<ASTNode>("list_item", "- Item 2");

    root.addChild(move(item1));
    root.addChild(move(item2));

    string markdown = convertASTToMarkdown(&root);

    EXPECT_EQ(markdown, "- Item 1\n- Item 2\n");
}

TEST(ASTNodeTest6, ConvertASTToMarkdownTable) {
    ASTNode root("table", "");
    unique_ptr<ASTNode> row1 = make_unique<ASTNode>("table_item", "| Column 1 | Column 2 |");
    unique_ptr<ASTNode> separator = make_unique<ASTNode>("table_separator", "|----------------------|----------------------|");
    unique_ptr<ASTNode> row2 = make_unique<ASTNode>("table_item", "| Data 1 | Data 2 |");

    root.addChild(move(row1));
    root.addChild(move(separator));
    root.addChild(move(row2));

    string markdown = convertASTToMarkdown(&root);

    string expected = "| Column 1 | Column 2 |\n|----------------------|----------------------|\n| Data 1 | Data 2 |\n";
    EXPECT_EQ(markdown, expected);
}

TEST(ASTNodeTest7, ConvertASTToMarkdownItalicsBold) {
    ASTNode root("italics_bold", "***This is italic and bold text***");
    string markdown = convertASTToMarkdown(&root);
    EXPECT_EQ(markdown, "***This is italic and bold text***");
}



