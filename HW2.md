# About runTimeObs.cpp 

The program (runTimeObs.cpp) is used to demonstrate the runtime (in milliseconds) of the linear and binary search algorithms.  The user has the ability to manually input data sizes and sample sizes.  It will return the runtimes for the linear search algorithm and binary search algorithm, number of samples found, and the space used on the computer in kilobytes.

## Download
This program was built with C++ standard: C++17 and the gcc++ compilier version of 12.2.0. It was compiled in Visual Studio Code on a machine running Windows 11.  It can be run on Windows or Linux operating systems.

Check your C++ standard with code below, as the libraries are not backwards compatible:
```cpp
#include <iostream>

int main() {
    std::cout << __cplusplus << std::endl;
}
```
If compatible, download the file "runTimeObs.cpp". If using Windows 11, you could also just download the executable file "runTimeObs.exe. You don't need a C++ compiler to run the executable file on Windows 11.  Linux can run the program without a problem.  See below for how to run on command lines.  Alternatively, the program can be run in your compiler (VS Code, etc.)

On Windows(Command Prompt):
```bash
C:\<File Path>\runTimeObs.exe
```
On Linux:
```bash
name@computer-name:~/<File Path>$ ./runTimeObs
```

## How to Run
When the program is initiated, it will ask two questions: first the data size (n):

```bash
Enter data size: 
```
And then the sample size (m):
```bash
Enter sample size:
```
Once you input the data size and sample size, the program will print out the results.  For example, on my computer, using a data size of 10,000 and a sample size of 1,000: 
```bash
Enter data size: 10000
Enter sample size: 1000

With a data size of: 10000, and a sample size of: 1000
Average linear search time was: 0.0223638 milliseconds.
The number of samples found were: 262
Space used for linear search is: 49.068 kilobytes


With a data size of: 10000, and a sample size of: 1000
Average binary search time was: 0.000207101 milliseconds.
The number of samples found were: 262
Space used for binary search is: 48.02 kilobytes
```
