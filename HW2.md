# About runTimeObs.cpp 

The program (runTimeObs.cpp) is used to demonstrate the runtime of the linear and binary search algorithms at progressively larger data inputs. It shows that a linear search algorithm has an exponential complexity, while the binary search algorithm is linearithmic in complexity.

## Download
This program was built with C++ standard: C++17 and the gcc++ compilier version of 12.2.0. It was compiled in Visual Studio Code on a machine running Windows 11.  

Check your C++ standard with code below, as the libraries are not backwards compatible:
```cpp
#include <iostream>

int main() {
    std::cout << __cplusplus << std::endl;
}
```

If compatible, download the file "runTimeObs.cpp". If using Windows 11, you could also just download the executable file "runTimeObs.exe. You don't need a C++ compiler to run the executable file on Windows 11. 

## How to Run
When the program is initiated, it will ask two questions: first the data size (n):

```bash
Enter data size: 
```
And then the sample size (m):
```bash
Enter sample size:
```
Once you input the data size and sample size, the program will print out the results, including the average search time for linear and binary search methods as well as the number of sampels found.  For example, on my computer, with a data size of 10000 and a sample size of 1000 were entered: 
```bash
Enter data size: 10000
Enter sample size: 1000

With a data size of: 10000, and a sample size of: 1000
Average linear search time was: 22.6982 milliseconds.
The number of samples found were: 262


With a data size of: 10000, and a sample size of: 1000
Average binary search time was: 0.169001 milliseconds.
The number of samples found were: 262
```
