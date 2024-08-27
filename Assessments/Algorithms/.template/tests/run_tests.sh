#!/bin/bash

echo "Compiling test.cpp"

start_compile=$(date +%s%3N)
g++ test.cpp -o test
end_compile=$(date +%s%3N)
compile_time=$((end_compile - start_compile))

if [ -f test ]; then
    echo "Compilation completed in $compile_time ms."

    echo "Executing test.cpp"
    
    start_exec=$(date +%s%3N)
    ./test
    end_exec=$(date +%s%3N)
    exec_time=$((end_exec - start_exec))
    
    echo "Execution completed in $exec_time ms."
    
    rm test
    echo "Program Completed"
else
    echo "Compilation failed. test executable not found."
fi
