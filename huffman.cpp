#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

struct huffmanNode {
    char key;
    int weight;
    std::string binaryrep;
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

void encoding(huffmanNode &input_node, std::vector<huffmanNode>& input_vector, std::string code) {
    /**
     * Inputs: Root node (from binary tree), input vector, and code
     * Outputs: None
     * Function: Recursively goes through binary tree tracking left and right movements (0 for left, 1 for right)
     * Function(2): Once reaches leaf node, will search through input vector and update the binary encoding 
    */
    if(&input_node == NULL) {
        return;
    }

    if(input_node.key != 0) {
        // std::cout << input_node.key << " " << code << std::endl;
        for(int i = 0; i < input_vector.size(); i++) {
            if(input_node.key == input_vector[i].key) {
                input_vector[i].binaryrep = code;
            }
        }
    }

    encoding(*input_node.left_child, input_vector, code + "0");
    encoding(*input_node.right_child, input_vector, code + "1");
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
    empty_char.binaryrep = "";
    empty_char.left_child = NULL;
    empty_char.right_child = NULL;
    for (int i = 0; i < size; i++) {
        empty_char.key = i;
        input_vector.push_back(empty_char);
    }
    return;
}

void printVector(std::vector<huffmanNode>& input_vector, bool print_freq = true, bool print_binary = true) {
    /**
     * Input: vector of structures (huffmanNodes)
     * Output: None
     * Function: prints out vector contents based on input(either frequency or binary encoding)
    */

    int len = input_vector.size();
    if(print_freq == true) {
        for (int j = 0; j < len; j++) {
            std::cout << input_vector[j].key << "  " << input_vector[j].weight << std::endl;
        }
    }
    if(print_binary == true) {
        for (int j = 0; j < len; j++) {
            std::cout << input_vector[j].key << "  " << input_vector[j].binaryrep << std::endl;
        }
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

    //delete everything that has a frequency of zero, need to copy vector since cannot operate on same vector in loop
    std::vector<huffmanNode> input_vector_copy = input_vector;
    int size = input_vector.size();
    for(int i = size; i > 0; i--) {
        if(input_vector_copy[i].weight == 0) {
            input_vector.erase(input_vector.begin() + i);
        }
    }

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

int main() {
    std::vector<huffmanNode> inputVector;
    std::priority_queue huffmanQueue(inputVector.begin(), inputVector.end(), queueCompareFunct);

    // Create Frequency Table, this vector will be the input to our Huffman binary tree generator, and store the binary encoding
    inputVector = freqTableGen(false);

    // Push items from input vector into priority queue (these are the leaf nodes)
    for(int i = 0; i < inputVector.size(); i++) {
        huffmanQueue.push(inputVector[i]);
    }

    // The while loop creates the huffman binary tree using a priority queue.  The remaining node in the queue is the root node of the tree.  
    while(huffmanQueue.size() > 1) {
        // create the left and right children, need to ensure a new memory location for each node
        huffmanNode *leftchild = new huffmanNode;
        *leftchild = huffmanQueue.top();
        huffmanQueue.pop();
        huffmanNode *rightchild = new huffmanNode;
        *rightchild = huffmanQueue.top();
        huffmanQueue.pop();

        // create parent node
        int weight = leftchild->weight + rightchild->weight;
        huffmanNode parent_node = {0, weight, "", leftchild, rightchild};

        // add parent node to priority queue, requirement for huffman coding
        huffmanQueue.push(parent_node);
    }

    // Need to create a new node to pass into encoding function, requires the memory address
    huffmanNode *root_node = new huffmanNode;
    *root_node = huffmanQueue.top();

    // Print out encoding
    encoding(*root_node, inputVector, "");
    std::cout << "Generated Binary encoding using Huffman Coding" << std::endl;
    printVector(inputVector, false, true);
}
