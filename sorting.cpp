/**
 * John Caruthers
 * 10Mar23
 * Hood College 
 * CS520 Algorithms, Spring 2023
 * Assignment 3
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <cstring>
#include <random>

int qs_median_of_three(std::vector<int>& array, int begin, int end) {
    /**
        * Input: Array of integers (pointer to array).
        * Output: Index of a chosen integer in the array.
        * Function: Randomly selects three integers in the input array, returns the index of the integer who is the median of the three integers.
    */

    // Random generator used (uniform distribution) for integer selection within array
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(begin, end);
    

    // Randomly selects index of three integers, stores in temp array
    int temp[] = {0,0,0};
    for (int i = 0; i < 3; i++) {
        int index = distrib(gen);
        temp[i] = index;
    }

    // chooses the median of the three values, returns the index(in input array) of that median
    int min = 0;
    int max = 0;
    for (int j = 1; j < 3; j++) {
        if (array[temp[j]] < array[temp[min]]) {
            min = j;
        }
        if (array[temp[j]] > array[temp[max]]) {
            max = j;
        }
    }
    return temp[3-(min+max)];
}

void swap(std::vector<int>& array, int index_a, int index_b) {
/**
    * Inputs: Array of integers (pointer to array), two indexes within array that need to have value swapped.
    * Outputs: Returns nothing.
    * Function: Swaps two values within an array, can perform without returning array since operates on array position in memory.
*/

int temp = array[index_a];
array[index_a] = array[index_b];
array[index_b] = temp;
}

int qs_partition(std::vector<int>& array, int begin, int end) {
    /**
        * Inputs: Array of integers (pointer to array), starting index for partition, end index for partition.
        * Outputs: Correct index of the pivot value (if the array was sorted).
        * Function: Uses Hoare's partition to segregate values based on comparison to pivot value. Pivot value is selected using Median of Three method.
    */

    // Create scanners
    int front_scan = begin;
    int rear_scan = end;
    
    // Use median of three method for selection of the pivot value
    int pivot_value_index = qs_median_of_three(array, begin, end);
    int pivot_value = array[pivot_value_index];

    // Swap the first value in subarray with pivot value
    swap(array, begin, pivot_value_index);

    // Partitioning Logic While loop
    while (true) {

        // Front scanner moves up, stopping at any value greater than the pivot value
        while (array[front_scan] <= pivot_value) {
            front_scan++;
            if (front_scan == end) {
                break;
            }
        }

        // Rear scanner moves down, stopping at any value less than the pivot value
        while (array[rear_scan] > pivot_value) {
            rear_scan--;
            if (rear_scan == begin) {
                break;
            }
        }

        /**
         * Makes sure scanners didn't cross, then swaps the front and rear scanner
         * If the scanners did cross, it swaps the pivot value with the value at the rear scanner
         * Swaps are performed in memory position of array
         */
        if (front_scan < rear_scan) {
            swap(array, front_scan, rear_scan);
        } else {
            swap(array, begin, rear_scan);
            break;
        }
    }   
    return rear_scan;
}

bool confirmSorted(std::vector<int>& array_input, int len_input) {
    /**
     * Inputs: Array of integers (pointer to array), length of array
     * Output: Boolean value TRUE if array is sorted, and FALSE if not sorted (in ascending order)
     * Function: Iterates through entire array and returns FALSE if a value is larger than value to its right, true if reaches end 
    */
    int int_counter = 0;
    while (int_counter < len_input-1) {
        if (array_input[int_counter] > array_input[int_counter + 1]) {
            return false;
        }
        int_counter++;
    }
    return true;
}

void selectionSort(std::vector<int>& array_input, int len_input) {
    /**
     * Inputs: Array of integers (pointer to array), length of array
     * Outputs: Returns nothing
     * Function: Iterates through array, selects smallest value and swaps with current index, 
     *           has to go through remaining array each iteration: Selection Sort
    */
    
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
            swap(array_input, i, min);
        }
    }
    return;
}

void insertionSort(std::vector<int>& array_input, int len_input) {
    /**
     * Inputs: Array of integers (pointer to array), length of array
     * Outputs: Returns nothing
     * Function: Iterates through array, compares index with values before it until it reaches a value 
     *           smaller than itself, inserting at that index: Insertion Sort
    */

    for (int i = 1; i < len_input; i++) {
    // compare array[dum_i] to item on left
        int temp = 0;
        int count = i;
        // repeat while array[dum_i] is less than item to its left
        while (array_input[count] < array_input[count -1] && count > 0) {
            swap(array_input, count, count-1);
            count--;
        }
    }
}

void quickSort(std::vector<int>& array_input, int low, int high) {
    /**
        * Inputs: Array of integers (pointer to array), starting index to sort, ending index to sort within array
        * Outputs: Returns nothing
        * Function: Recursively calling function that sorts using divide and conquer strategy: Quicksort
    */
    
    // Makes sure high and low value are not the same, or switched
    if (high <= low) {
        return;
    }

    // If high and low are next to each other, just swap values in array if appropriate
    if (high - low == 1) {
        if (array_input[low] > array_input[high]) {
            swap(array_input, low, high);
            return;
        }
        return;
    }

    /**
        * Recursive logic that first finds index of pivot value (i-th index in sorted array is the pivot value)
        * This partitions the array, recursively sorts left side (values that are less than pivot value)
        * Then recursively sorts right side (values that are greater than pivot value)
    */
    int pivoted = qs_partition(array_input, low, high);
    quickSort(array_input, low, pivoted-1);
    quickSort(array_input, pivoted+1, high);
}

int main () {

    // Create the vector array to store integers
    std::string input_text;
    std::string line;
    std::vector<int> data_array;
    int len;

    // Opens and reads file, displays error messaage if file path incorrect or does not exist
    std::cout << "Name of file to open: ";
    std::cin >> input_text;
    std::ifstream myfile (input_text);
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            data_array.push_back(std::stoi(line));
            }
        myfile.close();
    } else {
        std::cout << "INPUT ERROR: Unable to open file, check file name or path." << std::endl;
        return 1;
    }

    len = data_array.size();
    std::cout << "Reading data from: " << input_text << std::endl;

    // Ask what method want to sort, throws error message if incorrect input recieved
    char method[] = "";
    std::cout << "Choose method of sorting (S)Selection, (I)Insertion, or (Q)Quick Sort: ";
    std::cin >> method;
    if (std::strcmp(method, "S") != 0 && std::strcmp(method, "I") != 0 && std::strcmp(method, "M") != 0 && std::strcmp(method, "Q") != 0) {
        std::cout << "INPUT ERROR: '" << method << "'" << " is not a valid method, please try again." << std::endl;
        return 1;
    }

    // See if sorted
    if (confirmSorted(data_array, len)) {
        std::cout << "Confirmed Sorted!" <<std::endl;
    } else {
        std::cout << "Confirmed NOT Sorted" << std::endl;
    }

    // Starts timer
    auto start = std::chrono::high_resolution_clock::now();

    // Sorting algorithm selection, timer start
    if (std::strcmp(method, "S") == 0) {
        std::cout << "Initiating Selection Sort" << std::endl;
        selectionSort(data_array, len);
    } else if (std::strcmp(method, "I") == 0) {
        std::cout << "Initiating Insertion Sort" << std::endl;
        insertionSort(data_array, len);
    } else if (std::strcmp(method, "Q") == 0) {
        std::cout << "Initiating Quick Sort" << std::endl;
        quickSort(data_array, 0, len-1);
    }

    // End time, get search time.
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duration = end - start;
    std::cout << "It took " << (duration.count())*1000 << " milliseconds." << std::endl;


    // See if sorted
    if (confirmSorted(data_array, len)) {
        std::cout << "Confirmed Sorted!" <<std::endl;
    } else {
        std::cout << "Confirmed NOT Sorted" << std::endl;
    }
}
