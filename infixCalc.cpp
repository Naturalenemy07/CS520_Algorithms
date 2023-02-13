// John Caruthers
// 12Feb23
// Hood College 
// CS520 Algorithms, Spring 2023
// Assignment 1

#include <iostream>
#include <stack>
#include <string>

bool checker(int numlp, int numrp, int numop) {
    //counter to determine return value
    int counter = 0;

    // Compares number of parenthesis type and operands
    if (numrp > numlp && numrp > numop) {
        std::cout << "INPUT ERROR: Please use infix format, verify that parenthesis are correctly oriented" << std::endl;
        counter++;
    }

    // Check for presence of operands
    if (numop == 0) {
        std::cout << "INPUT ERROR: No operands detected, please verify expression is correctly inputted in infix format." << std::endl;
        counter++;
    }

    // perform final check
    if (numrp != numlp || numrp != numop || numrp == 0 || numlp == 0) {
        std::cout << "INPUT ERROR: You are either missing or have extra parenthesis, please verify expression is correctly inputted in infix format." << std::endl;
        counter++;
    }

    if (counter > 0) {
        return false;
    } else {
        return true;
    }
}

int main() {
    // Create Stacks
    std::stack<float> value_stack;
    std::stack<char> operand_stack;

    // Initialize mathematical expression as a string, get length
    std::string math_exp;
    std::cout << "Enter a mathematical expression as a string: ";
    std::cin >> math_exp;
    int input_length = math_exp.size();

    //Initialize counter integers
    int lpar = 0;
    int rpar = 0;
    int oper = 0;

    // Initialize tempnum for pushing a float to value_stack
    // tempnumStr is to hold floats of multiple places temporarily as a string
    float tempnum;
    std::string tempnumStr;

    // Iterate through math_exp, pushing to approprate stack
    for (int i = 0; i < input_length; i++) {

        // If statement detects if nummber, if so, adds to temp string until hits operand or right parenthesis
        if (math_exp[i] >= '0' && math_exp[i] <= '9' || math_exp[i] == '.') {
            tempnumStr.push_back(math_exp[i]);

        // First else if detects if an operand, pushes to operand stack if true
        } else if (math_exp[i] == '+' || math_exp[i] == '-' || math_exp[i] == '*' || math_exp[i] == '/') {
            // Add to operant counter
            oper++;

            // Convert temp num string to integer and push to stack (once verified no more numbers)
            if (tempnumStr != "") {
                tempnum = std::stof(tempnumStr);
                tempnumStr = "";
                value_stack.push(tempnum);
            }

            // Push operand to stack
            operand_stack.push(math_exp[i]);

        // Last conditional detects if a right parenthesis, pops items, performs calculations, pushes result to value stack
        } else if (math_exp[i] == ')') {
            // add to rpar
            rpar++;

            // Convert temp num string to integer and push to stack (once verified no more numbers)
            if (tempnumStr != "") {
                tempnum = std::stof(tempnumStr);
                tempnumStr = "";
                value_stack.push(tempnum);
            }

            // Verifies that an operand exists, and that there are at least two values prior to performing calculations
            if (operand_stack.size() == 0 || value_stack.size() < 2) {
                std::cout << "INPUT ERROR: There are no operands or not enough values to perform calculations compared to the number of right parenthesis, verify input is correctly in infix format" << std::endl;
                return 3;
            }

            // Gets and pops items
            float value1 = value_stack.top();
            value_stack.pop();
            float char1 = operand_stack.top();
            operand_stack.pop();
            float value2 = value_stack.top();
            value_stack.pop();

            // Performs calculations
            if (char1 == '+') {
                value2 += value1;
            } else if (char1 == '-') {
                value2 -= value1;
            } else if (char1 == '*') {
                value2 *= value1;
            } else if (char1 == '/') {
                value2 /= value1;
            }

            // Push new value to value_stack
            value_stack.push(value2);

        // Count left parenthesis for error checking
        } else if (math_exp[i] == '(') {
            lpar++;

        // Detects illegal characters
        } else {
            std::cout << "INPUT ERROR: '" << math_exp[i] << "'" << " is not a valid character, please verify expression is correct." << std::endl;
            return 3;
        }
    }

    // Performs final checks, if good will print result, if not, will return error.
    if (checker(lpar, rpar, oper)) {
        std::cout << "Result of expression: " << value_stack.top() << std::endl;
        return 0;
    } else {
        return 3;
    }
}
