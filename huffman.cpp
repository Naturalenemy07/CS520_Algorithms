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
        std::cout << input_vector[j].key << "  " << input_vector[j].count << std::endl;
    }
    return;
}

void cleanVector(std::vector<huffmanChar>& input_vector) {
    /**
     * Input: vector of structures (huffmanChar)
     * Output: None
     * Function: Cleans up the vector, removes all unneeded characters(no EOF or '/n' detected)
    */

   // delete all elements prior to 33 (before "!" in ascii)
   input_vector.erase(input_vector.begin(), input_vector.begin()+33);
   input_vector.erase(input_vector.begin()+1, input_vector.begin()+12);

   //delete everything except for lower case letters and "space"
   input_vector.erase(input_vector.begin()+3, input_vector.begin()+53);
   return;
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
        // If space detected, will add to "-" (45 in ascii)
        if (text_vector[char_from_file].key > 64 && text_vector[char_from_file].key < 91) {
            text_vector[char_from_file + 32].count++;
        } else if (text_vector[char_from_file].key == 32) {
            text_vector[45].count++;
        } else { 
            text_vector[char_from_file].count++;
        }
    }

    // Clean up vector, remove elements not used
    cleanVector(text_vector);

    // Print vector contents
    printVector(text_vector);
}
