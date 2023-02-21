// John Caruthers
// 21Feb23
// Hood College 
// CS520 Algorithms, Spring 2023
// Assignment 2

#include <iostream>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>

int main() {
    // Set (data_size) is number of ints in dataset, (range) is the range of that dataset, 
    // and (m_ints) is the sample size.
    int data_size;
    int d_range;
    int m_ints;

    // Get user input on dataset size and sample size, range is 10x data size to minimize repeats.
    std::cout << "Enter data size: ";
    std::cin >> data_size;
    std::cout <<"Enter sample size: ";
    std::cin >> m_ints;
    d_range = 10*data_size;

    // Create empty static array of size (data_size) to hold entire dataset, 
    // and empty static array to hold integers that will be searched for in the dataset (sample_array).
    std::vector<int> data_array_v;
    std::vector<int> sample_array_v;

    // Create array (linear_search_times, and binary_search_times) to store all search times, 
    // initialize (lin_num_found, and bin_num_found)
    std::vector<float> linear_search_times;
    std::vector<float> binary_search_times;
    int linear_found = 0;
    int binary_found = 0;

    // Randomly generate (data_size) integers and save to array (data_array)
    // use of std::rand() is fine for not serious purpose such as this homework.
    for (int dummy_n = 0; dummy_n < data_size; dummy_n++) {
        data_array_v.push_back(std::rand() % d_range);
    }
 
    // Sort list of (n) integers.
    std::sort(data_array_v.begin(), data_array_v.end());

    // Generate list of (m) integers to be searched and save to separate array (m_ints).
    for (int dummy_m = 0; dummy_m < m_ints; dummy_m++) {
        sample_array_v.push_back(std::rand() % d_range);
    }

    // Initiate space allocation.
    float linear_space = sizeof(data_size);
    linear_space += sizeof(d_range);
    linear_space += sizeof(m_ints);
    linear_space += data_array_v.size() * sizeof(int);
    linear_space += sample_array_v.size() * sizeof(int);
    linear_space += sizeof(linear_found);
    float binary_space = linear_space - sizeof(linear_found) + sizeof(binary_found);

    ///////////////////////
    /////Linear Search/////
    ///////////////////////

    // Iterate through sample vector.
    for (int dummy_j = 0; dummy_j < m_ints; dummy_j++) {

        // Start time.
        auto start = std::chrono::high_resolution_clock::now();

        // Search Linear Method.
        for (int dummy_k = 0; dummy_k < data_size; dummy_k++) {
            if (sample_array_v[dummy_j] == data_array_v[dummy_k]) {
                // End time if found, get search time, increase linear found.
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> duration = end - start;
                linear_found++;

                // Push search time to array, go to next sample item.
                linear_search_times.push_back(duration.count());
                break;
            }
        }

        // End time if not found, get search time.
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> duration = end - start;
        
        // Push search time to array, go to next sample item.
        linear_search_times.push_back(duration.count());
    }

    // Calculate average search time.
    float average_linear_search = 0;
    for (int dummy_s = 0; dummy_s < m_ints; dummy_s++) {
        average_linear_search += linear_search_times[dummy_s];
    }
    average_linear_search /= m_ints;

    // Update space allocation for linear space
    linear_space += sizeof(average_linear_search);
    linear_space += linear_search_times.size() * sizeof(float);

    // Print out results
    std::cout << "\nWith a data size of: " << data_size << ", and a sample size of: " << m_ints << std::endl;
    std::cout << "Average linear search time was: " << average_linear_search * 1000  << " milliseconds." << std::endl;
    std::cout << "The number of samples found were: " << linear_found << std::endl;
    std::cout << "Space used for linear search is: " << linear_space /1000 << " kilobytes." << "\n" << std::endl;

    ///////////////////////
    /////Binary Search/////
    ///////////////////////

    // Iterate through sample vector
    for (int dummy_j = 0; dummy_j < m_ints; dummy_j++) {
        // std::cout << "Binary searching for " << dummy_j +1 << "/" << m_ints << std::endl;
        int begin = 0;
        int end = data_size;
        int guess;
        bool end_status = false;

        // Start time
        auto start = std::chrono::high_resolution_clock::now();

        while (end_status == false) {
            // Detect if at end of binary search
            if (end - begin == 1) {
                // End time, update variables
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> duration = end - start;
                binary_search_times.push_back(duration.count());
                end_status = true;
            }

            // Guess, then perform comparisons
            guess = (begin + end)/2;
            if (sample_array_v[dummy_j] == data_array_v[guess]) {
                // End time, update variables
                auto end = std::chrono::high_resolution_clock::now();
                std::chrono::duration<float> duration = end - start;
                binary_search_times.push_back(duration.count());
                binary_found++;
                end_status = true;
            } else if (sample_array_v[dummy_j] < data_array_v[guess]) {
                end = guess;
            } else {
                begin = guess;
            }
        }
    }

    // Calculate average search time. need to iterate through search times, 
    float average_binary_search = 0;
    for (int dummy_s = 0; dummy_s < m_ints; dummy_s++) {
        average_binary_search += binary_search_times[dummy_s];
    }
    average_binary_search /= m_ints;

        // Update space allocation for linear space
    binary_space += sizeof(average_binary_search);
    binary_space += binary_search_times.size() * sizeof(float);

    // Print out results
    std::cout << "\nWith a data size of: " << data_size << ", and a sample size of: " << m_ints << std::endl;
    std::cout << "Average binary search time was: " << average_binary_search * 1000  << " milliseconds." << std::endl;
    std::cout << "The number of samples found were: " << binary_found << std::endl;
    std::cout << "Space used for binary search is: " << binary_space / 1000<< " kilobytes." << "\n" << std::endl;
}
