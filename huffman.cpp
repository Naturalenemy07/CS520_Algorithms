#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

struct huffmanCharFreq {
    char key;
    int count;
};

struct huffmanNode {
    char key;
    int weight;
    huffmanNode* parent;
    huffmanNode* left_child;
    huffmanNode* right_child;
};

void emptyVector(std::vector<huffmanCharFreq>& input_vector, int size) {
    /**
     * Inputs: vector of structures (huffmanCharFreq), and integer that designates size of vector
     * Output: None
     * Function: builds a vector of size "size", key is the index in vector, count is 0
    */

    huffmanCharFreq empty_char;
    empty_char.key = 0;
    empty_char.count = 0;
    for (int i = 0; i < size; i++) {
        empty_char.key = i;
        input_vector.push_back(empty_char);
    }
    return;
}

void printVector(std::vector<huffmanCharFreq>& input_vector) {
    /**
     * Input: vector of structures (huffmanCharFreq)
     * Output: None
     * Function: prints out vector contents
    */

    int len = input_vector.size();
    for (int j = 0; j < len; j++) {
        std::cout << input_vector[j].key << "  " << input_vector[j].count << std::endl;
    }
    return;
}

void cleanVector(std::vector<huffmanCharFreq>& input_vector) {
    /**
     * Input: vector of structures (huffmanCharFreq)
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

std::vector<huffmanCharFreq> freqTableGen(bool print_table = true){
    /**
     * Input: None
     * Output: returns frequency table as a vector of huffmanCharFreq structures
     * Function: generates frequency table
    */
    // Set variables, store information in vector
    int end = 123;
    std::string input_file;
    char char_from_file;
    std::ifstream input_file_data;
    std::vector<huffmanCharFreq> text_vector;

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
            text_vector[45].count++;
        } else { 
            text_vector[char_from_file].count++;
        }
    }

    // Clean up vector, remove elements not used
    cleanVector(text_vector);

    // Print vector contents, return
    if (print_table == true) {
        printVector(text_vector);
    }
    std::cout << "Generated Frequency Table" << std::endl;
    return text_vector;
}

int main() {
    // std::vector<huffmanCharFreq> freqTablesVector;
    // // Create Frequency Table
    // freqTablesVector = freqTableGen(true);

    // Manually create nodes to test huffman tree algorithm
    std::vector<huffmanNode> huffmanNodesVector;

    huffmanNode n1, n2, n3, n4, n5, n6;
    n1.key = 97;
    n2.key = 98;
    n3.key = 99;
    n4.key = 100;
    n5.key = 114;
    n6.key = 33;

    n1.weight = 5;
    n2.weight = 2;
    n3.weight = 1;
    n4.weight = 1;
    n5.weight = 2;
    n6.weight = 1;

    // push back onto vector
    huffmanNodesVector.push_back(n1);
    huffmanNodesVector.push_back(n2);
    huffmanNodesVector.push_back(n3);
    huffmanNodesVector.push_back(n4);
    huffmanNodesVector.push_back(n5);
    huffmanNodesVector.push_back(n6);

    // try to sort
    std::sort(huffmanNodesVector.begin(), huffmanNodesVector.end());

    // print vector
    for (int i = 0; i < huffmanNodesVector.size(); i++) {
        std::cout << huffmanNodesVector[i].key << ": " << huffmanNodesVector[i].weight << std::endl; 
    }

    // // How to 
    // n1.left_child = &n2;
    // n2.parent = &n1;
}
