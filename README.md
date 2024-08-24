**LaTeX to Markdown Converter** 

**Overview** 
The latexToMarkdownConverter is a C++ project that converts LaTeX documents into Markdown format. This project is built using Flex and Bison to generate a lexer and parser, which parse the LaTeX document, generate an abstract syntax tree (AST), and then convert the AST into Markdown.

**Features** 
Lexer: Tokenizes the LaTeX input using Flex. 
Parser: Parses the tokenized input to generate an AST using Bison. 
AST Generation: Represents the structure of the LaTeX document. 
Markdown Conversion: Converts the AST into a Markdown format. 

**Features Implemented (i.e the features which can be converted from Latex to Markdown):**
- Sections and subsections
- Italics and bold
- Horizontal line (\hrule)
- Paragraph (\par)
- Code blocks (\verbatim)
- Hyperlink
- Images
- Ordered and unordered Lists
- Tables
- Nested Lists

**Directory** \par
src/: Contains all the source files for the project. 
main.cpp: Entry point of the application.
AST.cpp: Implementation of the AST-related functions. 
AST.h: Header file for the AST classes and functions. 
lexer.l: Flex file for lexical analysis. 
parser.y: Bison file for parsing and AST generation. 

**Build Instructions**

*Clone the repository:*

[git clone https://github.com/yourusername/latexToMarkdownConverter.git](https://github.com/Shivansh-Garg/LatexToMarkdownConverter.git)
```
cd latexToMarkdownConverter
```

*Create a build directory and run CMake:*
```
mkdir build
cd build
cmake ..
```

*Compile the project:*
```
make
cd ..
```

*Run the converter:*
```
./run.sh <input_file.tex> <output_file.md>
```

**Testing** 
Unit tests can be written using Google Test. Tests are added to ensure that the Markdown conversion is correct, particularly for various LaTeX constructs like headings, lists, and more.

**To run the tests:** 
Ensure Google Test is installed and properly configured in your project. 
Add your test cases to the test files.
Build and run the tests.

**Acknowledgements**
Flex and Bison for lexical and syntactic analysis tools.
Google Test for providing a robust testing framework.
