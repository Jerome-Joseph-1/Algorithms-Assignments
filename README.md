# Algorithms-Assignments

This repository contains solutions and test cases for algorithm assignments. It provides organized code implementations, tools for generating inputs, and scripts for testing and validating algorithmic solutions.

## Getting Started

### Running the Program

1. **Prepare Input**:
   - Go to the `input` folder:
     ```bash
     cd input
     ```
   - Place your input data in the `file` file. Alternatively, generate random test cases using one of the following options:
     - **Option 1: Using Script**: Run `./generate_tc.sh` to automatically generate random test cases.  
       **OR**  
     - **Option 2: Manual Generation**: Compile and run the `generate_test_cases.cpp` file manually:
       ```bash
       g++ generate_test_cases.cpp -o generate_tc && ./generate_tc
       ```

2. **Run the Program**:
   - Go back to the main directory:
     ```bash
     cd ..
     ```
   - **Using Script**: Run `./run.sh` to compile and execute the program.
   - **Manual Compilation**: Alternatively, compile and run the program manually:
     ```bash
     g++ main.cpp -o main && ./main
     ```

3. **Test Against Brute Force**:
   - Go to the `tests` folder:
     ```bash
     cd tests
     ```
   - **Using Script**: Run `./run_tests.sh` to execute the tests.
   - **Manual Testing**: Or compile and run the `test.cpp` file manually:
     ```bash
     g++ test.cpp -o test && ./test
     ```
