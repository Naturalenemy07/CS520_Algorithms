#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

struct huffmanNode {
    char key;
    int weight;
    huffmanNode* parent;
    huffmanNode* left_child;
    huffmanNode* right_child;
};

struct { 
    // This structure is necessary to compare the weights of huffmanNodes as elements of the priority queue
    // It ensures that the sort uses the weights and prioritizes the smallest weight
    bool operator() (huffmanNode a, huffmanNode b) {
        return (a.weight > b.weight); 
    }
} queueCompareFunct;

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
    return text_vector; // returns address of text vector (original storage that should be manipulated further)
}

void huffmanBinaryTreeBuilder(std::vector<huffmanNode>& input_vector, unsigned long *huffmanQueue) {

    // Push items from input vector into priority queue
    for(int i = 0; i < input_vector.size(); i++) {
        *huffmanQueue.push(input_vector[i]);
    }
    
    // create the left and right children
    huffmanNode leftchild = huffmanQueue.top();
    std::cout << "huffman Queue top " << huffmanQueue.top().key << " " << huffmanQueue.top().weight << std::endl;
    std::cout << "left child " << leftchild.key << " " << leftchild.weight << std::endl;
    huffmanQueue.pop();
    huffmanNode rightchild = huffmanQueue.top();
    std::cout << "huffman Queue top " << huffmanQueue.top().key << " " << huffmanQueue.top().weight << std::endl;
    std::cout << "right child " << rightchild.key << " " << rightchild.weight << std::endl;
    huffmanQueue.pop();

    // create parent node
    huffmanNode parent_node = {0, leftchild.weight + rightchild.weight, NULL, &leftchild, &rightchild};
    std::cout << "Parent information: " << parent_node.weight << std::endl;

    // add parent node to priority queue, requirement for huffman coding
    huffmanQueue.push(parent_node);

    // print the queue
    std::cout << "huffmanQueue" << std::endl;
    while(huffmanQueue.size() != 0) {
        std::cout << huffmanQueue.top().key << " " << huffmanQueue.top().weight << std::endl;
        huffmanQueue.pop();
    }

    return;
}

int main() {
    
    std::vector<huffmanNode> inputVector;
    std::priority_queue huffmanQueue(inputVector.begin(), inputVector.end(), queueCompareFunct);

    // Create Frequency Table, this will be the input to our Huffman binary tree generator
    inputVector = freqTableGen(false);

    // Generate Huffman binary tree
    huffmanBinaryTreeBuilder(inputVector, &huffmanQueue);

    // // Sort Vector using Count as criteria, a requirement for Huffman coding
    // std::sort(inputVector.begin(), inputVector.end(), mysortfunction);
}
