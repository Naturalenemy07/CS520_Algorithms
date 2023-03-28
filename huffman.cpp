#include <iostream>
#include <fstream>
#include <string>

int main(){
// Opens and reads file, displays error message if file path incorrect or does not exist
    std::string input_text;
    std::cout << "Name of file to open: ";
    std::cin >> input_text;
    std::ifstream myfile (input_text);
    if (myfile.is_open()) {
        while (getline(myfile,line)) {
            data_array.push_back(std::stoi(line));
            }
        myfile.close();
    } else {
        std::cout << "INPUT ERROR: Unable to open file, check file name or path." << std::endl;
        return 1;
    }

    len = data_array.size();
    std::cout << "Reading data from: " << input_text << std::endl;
}
