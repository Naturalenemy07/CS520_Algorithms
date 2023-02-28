// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

bool confirmSorted() {
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

    // Ask what method want to sort
    std::string method;
    std::cout << "Choose method of sorting (S)Selection, (I)Insertion, (B)Bubble, (M)Merge, or (Q)Quick Sort: ";
    std::cin >> method;

    ///////////////
    /// Methods ///
    ///////////////

    // Selection Sort
    if (method == "S") {
        std::cout << "Initiating Selection Sorting" << std::endl;
        // perform selection sort
        int min = 0;
        for (int i = 0; i < len; i++) {
            std::cout << i << std::endl;
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
}
