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

void selectionSort(std::vector<int>& array_input, int len_input) {
    std::cout << "Initiating Selection Sorting" << std::endl;
    // perform selection sort
    int min = 0;
    for (int i = 0; i < len_input; i++) {
        min = i;
        int j = i;
        while (j < len_input-1) {
            j++;
            if (array_input[j] < array_input[min]) {
                min = j;
            } 
        }
        if (min != i) {
            int temp = array_input[i];
            array_input[i] = array_input[min];
            array_input[min] = temp;
        }
    }
    return;
}

void insertionSort(std::vector<int>& array_input, int len_input) {
    for (int i = 1; i < len_input; i++) {
    // compare array[dum_i] to item on left
        int temp = 0;
        int count = i;
        // repeat while array[dum_i] is less than item to its left
        while (array_input[count] < array_input[count -1] && count > 0) {
            temp = array_input[count];
            array_input[count] = array_input[count-1];
            array_input[count-1] = temp;
            count--;
        }
    }
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
    std::cout << "Choose method of sorting (S)Selection, (I)Insertion, (M)Merge, or (Q)Quick Sort: ";
    std::cin >> method;
    std::cout << '\n';

    // Check validity of selection
    if (method != "S" || method != "I" || method != "M" || method != "Q" || method != "s" || method != "i" || method != "m" || method != "q") {
        std::cout << "'" << method << "'" << " is not a proper sorting algorithm, please run program again, and select proper sorting algorithm." << std::endl;
        return 1;
    }

    // See if sorted
    if (confirmSorted(data_array, len)) {
        std::cout << "Confirmed Sorted" <<std::endl;
    } else {
        std::cout << "Confirmed NOT Sorted" << std::endl;
    }

    // Start time.
    auto start = std::chrono::high_resolution_clock::now();

    // Sorting algorithm selection
    if (method == "S" || method == "s") {
        selectionSort(data_array, len);
    } else if (method == "I") {
        insertionSort(data_array, len);
    } else if (method == "Q") {
        std::cout << "in progress";
    } else {
        std::cout << "in progress";
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
