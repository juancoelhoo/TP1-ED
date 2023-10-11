#ifndef BOOLEANEVALUATION_HPP
#define BOOLEANEVALUATION_HPP

#include <iostream>
#include <string>

class BooleanEvaluation{

    public:

    // Assignment of the string p values
    std::string variableAssignment(std::string& expression, const std::string& valuation);

    // Evaluates the boolean expression
    bool evaluateExpression(const std::string& expression, std::string valuation);

    // Evaluates the boolean expression
    bool evaluateExpression(const std::string& expression);

    // Determines whether there exists an assignment of truth values 
    void satisfiabilityProblem(std::string& expression, std::string& valuation);


};

#endif
