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

    // perform selection sort
    int min = 0;

    for (int i = 0; i < len; i++) {
        min = i;
        int j = i;
        while (j < len-1) {
            j++;
            if (array_to_sort[j] < array_to_sort[min]) {
                min = j;
            } 
        }
        if (min != i) {
            int temp = array_to_sort[i];
            array_to_sort[i] = array_to_sort[min];
            array_to_sort[min] = temp;
        }
    }

    // print result after selection sort
    std::cout << "\nAfter selection sort" << std::endl;

    // print input array
    std::cout << "[";
     for (int i = 0; i < len; i++) {
        std::cout << array_to_sort[i] << " ";
     }
     std::cout << "]" << std::endl;
}
