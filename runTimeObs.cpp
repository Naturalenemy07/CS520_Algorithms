#include <iostream>
#include <array>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector> // using vector since will handle large arrays

int main() {
    // Set (data_size) is number of ints in dataset, (range) is the range of that dataset, and (m_ints) is the sample size
    int data_size;
    int d_range;
    int m_ints;
    std::cout << "completed  consts" << std::endl;

    // Get user input on dataset size and sample size
    std::cout << "Enter data size: ";
    std::cin >> data_size;
    std::cout <<"Enter sample size: ";
    std::cin >> m_ints;
    d_range = 10*data_size;
    std::cout << "completed inputs" << std::endl;

    // Create empty static array of size (data_size) to hold entire dataset, 
    // and empty static array to hold integers that will be searched for in the dataset (sample_array)
    std::vector<int> data_array_v;
    std::vector<int> sample_array_v;
    std::cout << "completed vectors" << std::endl;
    // int data_array[data_size];
    // int sample_array[m_ints];

    // create array (linear_search_times, and binary_search_times) to store all search times, initialize (lin_num_found, and bin_num_found)
    std::vector<float> linear_search_times;
    // int linear_search_times[data_size];
    // int binary_search_times[data_size];
    int linear_found = 0;
    std::cout << "completed search vectors" << std::endl;

    // randomly generate (data_size) integers and save to array (data_array)
    // use of std::rand() is fine for this not serious purpose, and the range is 10x the data_size, to minimize prob of repeats
    for (int dummy_n = 0; dummy_n < data_size; dummy_n++) {
        data_array_v.push_back(std::rand() % d_range);
        // data_array[dummy_n] = (std::rand() % d_range);
    }
 
    // sort list of (n) integers
    std::cout << "Initiating sorting!" << std::endl;
    std::sort(data_array_v.begin(), data_array_v.end());
    std::cout << "Sorting completed!" << std::endl;

    // generate list of (m) integers to be searched and save to separate array (m_ints)
    for (int dummy_m = 0; dummy_m < m_ints; dummy_m++) {
        sample_array_v.push_back(std::rand() % d_range);
        std::cout << "generated sample int: " << dummy_m << std::endl;
        // sample_array[dummy_m] = (std::rand() % d_range);
    }

    ///////////////////////
    /////Linear Search/////
    ///////////////////////

    for (int dummy_j = 0; dummy_j < m_ints; dummy_j++) {
        std::cout << "Searching for " << dummy_j +1 << "/" << m_ints << std::endl;

        // Start time
        auto start = std::chrono::high_resolution_clock::now();

        // Search
        for (int dummy_k = 0; dummy_k < data_size; dummy_k++) {
            if (sample_array_v[dummy_j] == data_array_v[dummy_k]) {
                //End time if found, get search time, increase linear found
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> duration = end - start;
                linear_found++;

                // Push search time to array, go to next sample item
                linear_search_times.push_back(duration.count());
                break;
            }
        }

        // End time if not found, get search time
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        
        // Push search time to array, go to next sample item
        linear_search_times.push_back(duration.count());
    }

    // Calculate average search time. need to iterate through search times, 
    float average_linear_search = 0;
    for (int dummy_s = 0; dummy_s < m_ints; dummy_s++) {
        average_linear_search += linear_search_times[dummy_s];
    }

    // Print out results
    std::cout << "\nWith a data size of: " << data_size << ", and a sample size of: " << m_ints << std::endl;
    std::cout << "Average linear search time was: " << average_linear_search * 1000  << " milliseconds." << std::endl;
    std::cout << "The number of samples found were: " << linear_found << "\n" << std::endl;


    // for each number in M_ints, search using binary search method
    // // keep track of time to perform search using <chrono>, save the time (in milliseconds) to (search_times)

    // once completed, calculate average time to seach

    // print out (n), (m), number found and average time spent searching for each ex: 
    // (n): 100, (m): 50, (num found): #, (linear avg time): # secs, (binary avg time): # secs
}
