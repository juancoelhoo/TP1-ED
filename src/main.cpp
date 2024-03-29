#include "../include/BooleanEvaluation.hpp"
#include "../include/Stack.hpp"
#include "../include/BinaryTree.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void parse_args(int argc, char* argv[], string problem_Type)
/**
 * @brief Parses command-line arguments and performs boolean expression evaluation or satisfiability check.
 *
 * This function takes command-line arguments, extracts the boolean expression and valuation,
 * and based on the specified problem type, either evaluates the boolean expression or checks
 * its satisfiability. It catches and handles exceptions, providing informative messages
 * in case of errors.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @param problem_Type A string indicating the type of problem ("-a" for expression evaluation, "-s" for satisfiability).
 */
{
    if (argc != 4)
    {
        cerr << "Usage: ./Executable_name <Problem type> <Representation formula> <Valuation>" << endl;
        return;
    }

    string expression (argv[2]);  // String that represents the formula
    string valuation  (argv[3]);  // String that represents the variable values in the forumla

    if (expression.size() > 1000000){
         throw invalid_argument("Error: invalid string p size!");
    }
    if (valuation.size() > 100){
         throw invalid_argument("Error: invalid string s size!");
    }

     for (char ch : expression)
    {
        if (!isdigit(ch) && !isalpha(ch) && ch != '|' && ch != '&' && ch != '~' && ch != '(' && ch != ')' && ch != ' ')
        {
            throw invalid_argument("Invalid character in expression. Allowed characters are digits, letters, '|', '&', '~', '(', and ')'.");
        }
    }

    // Check if the expression has a number larger than the size of valuation
    for (char ch : expression)
    {
        if (isdigit(ch))
        {
            int num = ch - '0';
            if (num >= valuation.size())
            {
                throw invalid_argument("Error: a number in the expression is larger than the size of valuation.");
            }
        }
    }


    try
    {
        if (problem_Type == "-a")
        {
            cout << "Problema escolhido: Avaliacao de expressoes" << endl;

            BooleanEvaluation avaliacao;
            cout << "Result: " << avaliacao.evaluateExpression(expression, valuation) << endl;
        }
        else if (problem_Type == "-s")
        {
            cout << "Problema escolhido: Satisfabilidade" << endl;

            BooleanEvaluation avaliacao;
            avaliacao.satisfiabilityProblem(expression, valuation);
        }
        else
        {
            throw invalid_argument("Invalid problem type. Use '-a' for expression evaluation or '-s' for satisfiability.");
        }
    }
    catch (const exception &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
    }
}

int main(int argc, char *argv[])
{
    string problem_Type (argv[1]);

    parse_args(argc, argv, problem_Type);

    return 0;
}