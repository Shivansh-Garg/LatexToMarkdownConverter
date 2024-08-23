#!/bin/bash

# Check if exactly two arguments are provided
if [ "$#" -ne 2 ]; then
    echo "Usage: ./run.sh <input.tex> <output.md>"
    exit 1
fi

# Assign arguments to variables
input_file=$1
output_file=$2

# Check if the input file exists
if [ ! -f "$input_file" ]; then
    echo "Input file '$input_file' not found!"
    exit 1
fi

# Define the path to the executable
converter_executable="./build/latexToMarkdownConverter"

# Check if the converter executable exists
if [ ! -f "$converter_executable" ]; then
    echo "Executable '$converter_executable' not found!"
    echo "Make sure to build the project first."
    exit 1
fi

# Run the converter with the input and output files
"$converter_executable" "$input_file" "$output_file"

# Check if the converter was successful
if [ "$?" -ne 0 ]; then
    echo "Conversion failed!"
    exit 1
fi

echo "Conversion successful! Output written to '$output_file'"
