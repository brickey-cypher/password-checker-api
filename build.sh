#!/bin/bash

# Exit immediately if a command fails
set -e

echo ">>> Downloading json.hpp..."
mkdir -p include
curl -L https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp -o include/json.hpp

echo ">>> Compiling checker.cpp..."
g++ -std=c++17 checker.cpp -o checker -Iinclude

echo ">>> Setting execute permission on checker"
chmod +x checker

echo ">>> Build completed successfully."


