#!/bin/bash

echo "Compiling main.cpp"

start_compile=$(date +%s%3N)
g++ main.cpp -o main
end_compile=$(date +%s%3N)
compile_time=$((end_compile - start_compile))

if [ -f main ]; then
    echo "Compilation completed in $compile_time ms."

    echo "Executing main.cpp"
    
    start_exec=$(date +%s%3N)
    ./main
    end_exec=$(date +%s%3N)
    exec_time=$((end_exec - start_exec))    
    
    echo "Execution completed in $exec_time ms."
    
    rm main
    echo "Program Completed"
else
    echo "Compilation failed. main executable not found."
fi