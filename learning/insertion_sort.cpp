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
     for (int i = 0; i < len; i++) {
        std::cout << array_to_sort[i] << " ";
     }
     std::cout << "" << std::endl;

    // perform insertion sort
    for (int dum_i = 1; dum_i < len; dum_i++) {
        // compare array[dum_i] to item on left
            int temp = 0;
            int count = dum_i;
            // repeat while array[dum_i] is less than item to its left
            while (array_to_sort[count] < array_to_sort[count -1] && count > 0) {
                temp = array_to_sort[count];
                array_to_sort[count] = array_to_sort[count-1];
                array_to_sort[count-1] = temp;
                count--;
            }
    }

    // print result after selection sort
    std::cout << "\nAfter insertion sort" << std::endl;

    // print input array
     for (int i = 0; i < len; i++) {
        std::cout << array_to_sort[i] << " ";
     }
     std::cout << "" << std::endl;
}
