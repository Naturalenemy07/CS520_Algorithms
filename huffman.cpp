#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct huffmanChar {
    char key;
    int count;
};

int main(){
    // Set variables, store information in vector
    std::string input_file;
    char char_from_file;
    std::ifstream input_file_data;
    std::vector<huffmanChar> text_vector;

    // // Open file
    // std::cout << "Name of file to open: ";
    // std::cin >> input_file;
    // input_file_data.open(input_file);

    // // Read data, print out characters
    // while (input_file_data.get(char_from_file)) {
    //     std::cout << char_from_file << ": " << char_from_file-0 << std::endl;
    // }

    // Test out manipulation of vector
    huffmanChar a_char, b_char;
    a_char.key = 97;
    a_char.count = 0;
    b_char.key = 98;
    b_char.count = 0;

    text_vector.push_back(a_char);
    text_vector.push_back(b_char);

    std::cout << a_char.key << ": " << a_char.count << std::endl;  
    std::cout << b_char.key << ": " << b_char.count << std::endl; 

    text_vector[0].count++;
    std::cout << text_vector[0].key << ": " << text_vector[0].count << std::endl;  

      
}
