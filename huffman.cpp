#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct huffmanChar {
    char key;
    int count;
};

void emptyVector(std::vector<huffmanChar>& input_vector, int size) {
    /**
     * Inputs: vector of structures (huffmanChar), and integer that designates size of vector
     * Output: None
     * Function: builds a vector of size "size", key is the index in vector, count is 0
    */

    huffmanChar empty_char;
    empty_char.key = 0;
    empty_char.count = 0;
    for (int i = 0; i < size; i++) {
        empty_char.key = i;
        input_vector.push_back(empty_char);
    }
    return;
}

void printVector(std::vector<huffmanChar>& input_vector) {
    /**
     * Input: vector of structures (huffmanChar)
     * Output: None
     * Function: prints out vector contents
    */

    int len = input_vector.size();
    for (int j = 0; j < len; j++) {
        std::cout << input_vector[j].key << ": " << input_vector[j].count << std::endl;
    }
}

void cleanVector(std::vector<huffmanChar>& input_vector) {
    /**
     * Input: vector of structures (huffmanChar)
     * Output: None
     * Function: Cleans up the vector, removes all unneeded characters, sets special characters per HW 4: `-' for space, `.' for period, `!' for new line. (no EOM for my system)
    */

   // May not do this, would not be efficient.  Would need to swap, the pop out


}

int main(){
    // Set variables, store information in vector
    int end = 123;
    std::string input_file;
    char char_from_file;
    std::ifstream input_file_data;
    std::vector<huffmanChar> text_vector;

    // Fill vector with empty spaces, index indicates ascii character
    emptyVector(text_vector, end);

    // Open file
    std::cout << "Name of file to open: ";
    std::cin >> input_file;
    input_file_data.open(input_file);

    // Read data, update count of characters in text_vector
    while (input_file_data.get(char_from_file)) {
        // If upper case of letter is detected, add to the lower case letter
        if (text_vector[char_from_file].key > 64 && text_vector[char_from_file].key < 91) {
            text_vector[char_from_file + 32].count++;
        } else { 
            text_vector[char_from_file].count++;
        }
    }

    // Print vector contents
    printVector(text_vector);
}
