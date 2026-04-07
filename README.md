# Name
Alexander Kim (UFID: 71075724)

# Compilation

``` bash
make
```

# Testing and Running
All results are sent to output/out.txt.
You might first need to make the scripts executable
``` bash
chmod +x run.sh example.sh
```

### Running the Example
``` bash
./example.sh
```
This script runs the hvlcs executable on the input from example.in and compares it to example.out.
The result will either be a message saying the files match, or the differences between the two.

### Running Other Inputs
``` bash
./run.sh <filename-in-/data>
```
This script runs the hvlcs executable on the input from the given file argument.
Note, this file must be in the /data directory.
The ten files used to answer question 1 are available to test.

# Assumptipons
This project was developed on a mac and is intended to run in a Unix-like environment.

The project requires the following tools:
- g++ with C++17 support
- make
- bash

The HVLCS.cpp program also expects the text in the input files to exactly match 
the format specified in the assignment.

# Question 1: Empirical Comparison
![Alt Text](images/runtime.png)
