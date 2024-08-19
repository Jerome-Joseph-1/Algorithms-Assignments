#!/bin/bash

g++ generate_test_cases.cpp -o tc
if [ -f tc ]; then 
    ./tc 
    rm tc 
fi 
