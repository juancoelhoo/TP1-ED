#include "BooleanEvaluation.hpp"
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

bool BooleanEvaluation::evaluateExpression(const std::string& expression, const std::string& valuation){
        std::stack<char> operators;
        std::stack<bool> values;

        std::unordered_map<int, bool> variableMap;

        // Populate the map with variable-value pairs
        for (unsigned int i = 0; i < valuation.size(); ++i) {
            variableMap[i] = (valuation[i] == '1');
        }

        for (char ch : expression) {
            if (ch == ' ') {
                continue; // Skip spaces
            } else if (ch == '(' || ch == '&' || ch == '|' || ch == '~') {
                operators.push(ch);
            } else if (ch == ')') {
                // Handle closing parenthesis
                while (!operators.empty() && operators.top() != '(') {
                    char op = operators.top();
                    operators.pop();

                    if (op == '~') {
                        bool operand = values.top();
                        values.pop();
                        values.push(!operand); // Apply NOT operation
                    } else {
                        bool operand2 = values.top();
                        values.pop();
                        bool operand1 = values.top();
                        values.pop();

                        if (op == '&') {
                            values.push(operand1 && operand2);
                        } else if (op == '|') {
                            values.push(operand1 || operand2);
                        }
                    }
                }
                operators.pop(); // Pop the '('
            } else {
                // Handle variables
                int variable = ch - '0';
                values.push(variableMap.at(variable));
            }
        }

        // Handle remaining operators
        while (!operators.empty()) {
            char op = operators.top();
            operators.pop();

            if (op == '~') {
                bool operand = values.top();
                values.pop();
                values.push(!operand);
            } else {
                bool operand2 = values.top();
                values.pop();
                bool operand1 = values.top();
                values.pop();

                if (op == '&') {
                    values.push(operand1 && operand2);
                } else if (op == '|') {
                    values.push(operand1 || operand2);
                }
            }
        }

    return values.top();
}

bool BooleanEvaluation::satisfiabilityProblem(const std::string& expression, const std::string& valuation){

    std::unordered_map<int, char> variableMap;
        // Populate the map with variable-value pairs
        for (unsigned int i = 0; i < valuation.size(); ++i){
            variableMap[i] = valuation[i];
        }
    for (const auto& pair : variableMap) {
        char value = pair.second;

    


}