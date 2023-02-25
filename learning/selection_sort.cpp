#include<iostream>


int array_to_sort[10];

void print_array(int length) {
     std::cout << "Input Array: [";
     for (int i = 0; i < length - 1; i++) {
        std::cout << array_to_sort[i] << " ";
     }
     std::cout << array_to_sort[length];
     std::cout << "]" << std::endl;
}

void selection_sort() {
    
}

int main() {
    int len;
    // get user input
    std::cout << "Length: ";
    std::cin >> len;

    // create array
    for (int i = 0; i < len; i++) {
        array_to_sort[i] = rand() % 100;
    }

    // print input array
    print_array(len);

    // perform selection sort
}
