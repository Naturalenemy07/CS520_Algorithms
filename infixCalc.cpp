// John Caruthers
// CS520 Algorithms, Spring 2023
// Hood College 
// 07Feb23
// Homework 1

#include <iostream>
#include <stack>
#include <string>

int main() {
    // Create Stacks
    std::stack<int> value_stack;
    std::stack<char> operand_stack;

    // Initialize mathematical expression as a string, get length
    std::string math_exp;
    std::cout << "Enter a mathematical expression as a string: ";
    std::cin >> math_exp;
    int input_length = math_exp.size();

    // Initialize tempnum for pushing an integer to value_stack
    // tempnumStr is to hold integers of multiple places
    int tempnum;
    std::string tempnumStr;

    // Iterate through math_exp, pushing to approprate stack
    for (int i = 0; i < input_length; i++) {
        // If statment detects if an integer, saves as integer to tempnum, pushes to value stack if true
        if (math_exp[i] >= '0' && math_exp[i] <= '9') {
            if (tempnumStr.size() > 0) {
                tempnumStr.append(math_exp[i]);
            }
            tempnumStr = math_exp[i];
            tempnum = math_exp[i] - '0';
            value_stack.push(tempnum);

        // First else if detects if an operand, pushes to operand stack if true
        } else if (math_exp[i] == '+' || math_exp[i] == '-' || math_exp[i] == '*' || math_exp[i] == '/' || math_exp[i] == '%') {
            operand_stack.push(math_exp[i]);

        // Last conditional detects if a right parenthesis, pops items, performs calculations, pushes result to value stack
        } else if (math_exp[i] == ')') {
            // gets and pops items
            int value1 = value_stack.top();
            value_stack.pop();
            char char1 = operand_stack.top();
            operand_stack.pop();
            int value2 = value_stack.top();
            value_stack.pop();

            // performs calculations
            if (char1 == '+') {
                value2 += value1;
            } else if (char1 == '-') {
                value2 -= value1;
            } else if (char1 == '*') {
                value2 *= value1;
            } else if (char1 == '/') {
                value2 /= value1;
            } else {
                value2 %= value1;
            }

            // push new value to value_stack
            value_stack.push(value2);
        }
    }

    // Once iterated through entire math_exp, print out result
    std::cout << "Result of expression: " << value_stack.top() << std::endl;
    return 0;
}
