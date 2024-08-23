#!/bin/bash
# Author Shivansh Garg

if [ "$#" -ne 2 ]; then
    echo "Usage: ./run.sh <input.tex> <output.md>"
    exit 1
fi

inputFile=$1
outputFile=$2

if [ ! -f "$inputFile" ]; then
    echo "Input file '$inputFile' not found!"
    exit 1
fi

# Define the path to the executable
converterExecuter="./build/latexToMarkdownConverter"

# Check if the converter executable exists
if [ ! -f "$converterExecuter" ]; then
    echo "Executable '$converterExecuter' not found!"
    echo "Make sure to build the project first."
    exit 1
fi

"$converterExecuter" "$inputFile" "$outputFile"

# Check if the converter was successful
if [ "$?" -ne 0 ]; then
    echo "Conversion failed!"
    exit 1
fi

echo "Conversion successful! Output written to '$outputFile'"
