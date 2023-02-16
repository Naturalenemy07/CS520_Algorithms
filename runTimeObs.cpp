#include <iostream>
#include <chrono>


int main() {
    //set variables (data_size) is number of ints, (range), and (m_ints) sample size
    int data_size;
    int d_range;
    int m_ints;

    std::cout << "Enter data size: ";
    std::cin >> data_size;
    std::cout <<"Enter sample size: ";
    std::cin >> m_ints;
    d_range = 10*data_size;

    // generate (n) integers and save to an array (n_ints)
    

    // sort list of (n) integers

    // generate list of (m) integers to be searched and save to seperate array (m_ints)

    // create array (linear_search_times, and binary_search_times) to store all search times, initialize (lin_num_found, and bin_num_found) to store numebr of integers found

    // for each number in M_ints, search using linear search method
    // // keep track of time to perform search using <chrono>, save the time (in milliseconds) to (search_times)

    // for each number in M_ints, search using binary search method
    // // keep track of time to perform search using <chrono>, save the time (in milliseconds) to (search_times)

    // once completed, calculate average time to seach

    // print out (n), (m), number found and average time spent searching for each ex: 
    // (n): 100, (m): 50, (num found): #, (linear avg time): # secs, (binary avg time): # secs
}
