#!/bin/bash

# Download the nlohmann/json single-header lib
mkdir -p include
curl -L https://github.com/nlohmann/json/releases/download/v3.11.3/json.hpp -o include/json.hpp

# Compile the checker with JSON support
g++ -std=c++17 checker.cpp -o checker -Iinclude

