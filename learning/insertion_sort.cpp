#include<iostream>

int main() {
    // get user input
    int len;
    std::cout << "Length: ";
    std::cin >> len;
    int array_to_sort[len];

    // create array
    for (int i = 0; i < len; i++) {
        array_to_sort[i] = rand() % (len * 10);
    }

    // print input array
    std::cout << "[";
     for (int i = 0; i < len; i++) {
        std::cout << array_to_sort[i] << " ";
     }
     std::cout << "]" << std::endl;

    // perform insertion sort
    

    // print result after selection sort
    std::cout << "\nAfter insertion sort" << std::endl;

    // print input array
    std::cout << "[";
     for (int i = 0; i < len; i++) {
        std::cout << array_to_sort[i] << " ";
     }
     std::cout << "]" << std::endl;
}
