// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

bool confirmSorted(std::vector<int>& array_input, int len_input) {
    int sort_counter = 0;
    int int_counter = 0;
    while (sort_counter == 0 && int_counter < len_input-1) {
        if (array_input[int_counter] > array_input[int_counter + 1]) {
            sort_counter++;
            return false;
        }
        int_counter++;
    }
    return true;
}

int main () {

    // Create the vector array to store integers
    std::string input_text;
    std::string line;
    std::vector<int> data_array;
    int len;

    std::cout << "Name of file to open: ";
    std::cin >> input_text;

    std::ifstream myfile (input_text);
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            data_array.push_back(std::stoi(line));
            }
        myfile.close();
        }

    else std::cout << "Unable to open file";

    len = data_array.size();
    std::cout << "Reading data from: " << input_text << std::endl;

    // Ask what method want to sort
    std::string method;
    std::cout << "Choose method of sorting (S)Selection, (I)Insertion, (B)Bubble, (M)Merge, or (Q)Quick Sort: ";
    std::cin >> method;

    // See if sorted
    if (confirmSorted(data_array, len)) {
        std::cout << "Confirmed Sorted" <<std::endl;
    } else {
        std::cout << "Confirmed NOT Sorted" << std::endl;
    }

    ///////////////
    /// Methods ///
    ///////////////

    // Start time.
    auto start = std::chrono::high_resolution_clock::now();

    // Selection Sort
    if (method == "S") {
        std::cout << "Initiating Selection Sorting" << std::endl;
        // perform selection sort
        int min = 0;
        for (int i = 0; i < len; i++) {
            min = i;
            int j = i;
            while (j < len-1) {
                j++;
                if (data_array[j] < data_array[min]) {
                    min = j;
                } 
            }
            if (min != i) {
                int temp = data_array[i];
                data_array[i] = data_array[min];
                data_array[min] = temp;
            }
        }
    }

    // Insertion Sort
    if (method == "I") {
        for (int dum_i = 1; dum_i < len; dum_i++) {
        // compare array[dum_i] to item on left
            int temp = 0;
            int count = dum_i;
            // repeat while array[dum_i] is less than item to its left
            while (data_array[count] < data_array[count -1] && count > 0) {
                temp = data_array[count];
                data_array[count] = data_array[count-1];
                data_array[count-1] = temp;
                count--;
            }
        }
    }

    // Quicksort
    if (method == "Q") {
        
    }

    // Mergesort
    if (method == "M") {
        
    }

    // End time, get search time.
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << "It took " << (duration.count())*1000 << " milliseconds." << std::endl;


    // See if sorted
    if (confirmSorted(data_array, len)) {
        std::cout << "Confirmed Sorted" <<std::endl;
    } else {
        std::cout << "Confirmed NOT Sorted" << std::endl;
    }
}
