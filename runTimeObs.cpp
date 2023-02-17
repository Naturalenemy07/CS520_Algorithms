#include <iostream>
#include <array>
#include <chrono>
#include <cstdlib>
#include <algorithm>


int main() {
    // Set (data_size) is number of ints in dataset, (range) is the range of that dataset, and (m_ints) is the sample size
    int data_size;
    int d_range;
    int m_ints;

    // Get user input on dataset size and sample size
    std::cout << "Enter data size: ";
    std::cin >> data_size;
    std::cout <<"Enter sample size: ";
    std::cin >> m_ints;
    d_range = 10*data_size;

    // Create empty static array of size (data_size) to hold entire dataset, 
    // and empty static array to hold integers that will be searched for in the dataset (sample_array)
    int data_array[data_size];
    int sample_array[m_ints];

    // create array (linear_search_times, and binary_search_times) to store all search times, initialize (lin_num_found, and bin_num_found)
    int linear_search_times[data_size];
    int binary_search_times[data_size];
    int lin_num_found;
    int bin_num_found;

    // randomly generate (data_size) integers and save to array (data_array)
    // use of std::rand() is fine for this not serious purpose, and the range is 10x the data_size, to minimize prob of repeats
    for (int dummy_n = 0; dummy_n < data_size; dummy_n++) {
        data_array[dummy_n] = (std::rand() % d_range);
    }

    // sort list of (n) integers
    std::sort(data_array,data_array + data_size);

    // generate list of (m) integers to be searched and save to seperate array (m_ints)
    for (int dummy_m = 0; dummy_m < data_size; dummy_m++) {
        sample_array[dummy_m] = (std::rand() % d_range);
    }

    // create array (linear_search_times, and binary_search_times) to store all search times, initialize (lin_num_found, and bin_num_found) to store numebr of integers found

    // for each number in M_ints, search using linear search method
    // // keep track of time to perform search using <chrono>, save the time (in milliseconds) to (search_times)

    // for each number in M_ints, search using binary search method
    // // keep track of time to perform search using <chrono>, save the time (in milliseconds) to (search_times)

    // once completed, calculate average time to seach

    // print out (n), (m), number found and average time spent searching for each ex: 
    // (n): 100, (m): 50, (num found): #, (linear avg time): # secs, (binary avg time): # secs
}
