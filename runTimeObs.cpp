#include <iostream>
#include <array>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <string>

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
    int data_array[data_size]; // actually a pointer to the data array std::cout returns memory address.
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

    // generate list of (m) integers to be searched and save to separate array (m_ints)
    for (int dummy_m = 0; dummy_m < m_ints; dummy_m++) {
        sample_array[dummy_m] = (std::rand() % d_range);
    }

    ///////////////////////
    /////Linear Search/////
    ///////////////////////

    for (int dummy_j = 0; dummy_j < m_ints; dummy_j++) {
        bool found_status;
        double search_time;

        // start time
        auto start = std::chrono::system_clock::now();

        //search
        for (int dummy_k = 0; dummy_k < data_size; dummy_k++) {
            if (sample_array[dummy_j] == data_array[dummy_k]) {
                
                found_status = true;

                //end time once found, get search time
                auto end = std::chrono::system_clock::now();
                std::chrono::duration<double> diff = end - start;
                search_time = diff.count();
                std::cout << "It took: " << search_time << " milliseconds to find." << std::endl;

                break;
            }
        }

        // Set status since interated through entire data_array and didnt find sample
        found_status = false;

        // End time
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> diff = end - start;
        search_time = diff.count();
        std::cout << "It took: " << search_time << " milliseconds, and it was not found." << std::endl;

    }

    // for each number in M_ints, search using binary search method
    // // keep track of time to perform search using <chrono>, save the time (in milliseconds) to (search_times)

    // once completed, calculate average time to seach

    // print out (n), (m), number found and average time spent searching for each ex: 
    // (n): 100, (m): 50, (num found): #, (linear avg time): # secs, (binary avg time): # secs
}
