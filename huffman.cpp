#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct huffmanNode {
    char key;
    int weight;
    huffmanNode* parent;
    huffmanNode* left_child;
    huffmanNode* right_child;
};

bool mysortfunction(huffmanNode a, huffmanNode b) {
    return (a.weight < b.weight);
}

void emptyVector(std::vector<huffmanNode>& input_vector, int size) {
    /**
     * Inputs: vector of structures (huffmanNodes), and integer that designates size of vector
     * Output: None
     * Function: builds a vector of size "size", key is the index in vector, count is 0
    */

    huffmanNode empty_char;
    empty_char.key = 0;
    empty_char.weight = 0;
    for (int i = 0; i < size; i++) {
        empty_char.key = i;
        input_vector.push_back(empty_char);
    }
    return;
}

void printVector(std::vector<huffmanNode>& input_vector) {
    /**
     * Input: vector of structures (huffmanNodes)
     * Output: None
     * Function: prints out vector contents
    */

    int len = input_vector.size();
    for (int j = 0; j < len; j++) {
        std::cout << input_vector[j].key << "  " << input_vector[j].weight << std::endl;
    }
    return;
}

void cleanVector(std::vector<huffmanNode>& input_vector) {
    /**
     * Input: vector of structures (huffmanNodes)
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

std::vector<huffmanNode> freqTableGen(bool print_table = true){
    /**
     * Input: None
     * Output: returns frequency table as a vector of huffmanNodes structures
     * Function: generates frequency table
    */
    // Set variables, store information in vector
    int end = 123;
    std::string input_file;
    char char_from_file;
    std::ifstream input_file_data;
    std::vector<huffmanNode> text_vector;

    // Fill vector with empty spaces, index indicates ascii character
    emptyVector(text_vector, end);

    // Open file
    std::cout << "Name of file to open: ";
    std::cin >> input_file;
    input_file_data.open(input_file);

    // Read data, update count of characters in text_vector (assuming no upper case)
    while (input_file_data.get(char_from_file)) {
        // If space detected, will add to "-" (45 in ascii)
        if (text_vector[char_from_file].key == 32) {
            text_vector[45].weight++;
        } else { 
            text_vector[char_from_file].weight++;
        }
    }

    // Clean up vector, remove elements not used, now the index and ASCII designation no longer match
    cleanVector(text_vector);

    // Print vector contents, return
    if (print_table == true) {
        printVector(text_vector);
    }
    std::cout << "Generated Frequency Table" << std::endl;
    std::cout << "text_vector address: " << &text_vector << std::endl;
    return text_vector; // returns address of text vector (original storage that should be manipulated further)
}

int main() {
    std::vector<huffmanNode> freqTablesVector;
    // Create Frequency Table
    freqTablesVector = freqTableGen(true);
    std::cout << "freqTablesVector Address: " << &freqTablesVector << std::endl;

    // // Sort Vector using Count as criteria
    // std::sort(freqTablesVector.begin(), freqTablesVector.end(), mysortfunction);

    // printVector(freqTablesVector);

    // // Manually create nodes to test huffman tree algorithm.  Need two vectors 
    // std::vector<huffmanNode> InputVector;
    // std::vector<huffmanNode> huffmanInternalNodesVector;
    // std::vector<huffmanNode> huffmanTree;

    // huffmanNode n1, n2, n3, n4;
    // n1.key = 97;
    // n2.key = 98;
    // n3.key = 99;
    // n4.key = 100;

    // n1.weight = 5;
    // n2.weight = 2;
    // n3.weight = 1;
    // n4.weight = 1;

    // // push back onto vector
    // InputVector.push_back(n1);
    // InputVector.push_back(n2);
    // InputVector.push_back(n3);
    // InputVector.push_back(n4);

    // // sort
    // std::sort(InputVector.begin(), InputVector.end(), mysortfunction);

    // //copy vector
    // huffmanInternalNodesVector = huffmanLeafNodesVector
}
