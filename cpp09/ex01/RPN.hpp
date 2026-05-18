#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
    private:
        std::stack<int> _stack;
    
    public:
        RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);
        ~RPN();

        int evaluate(const std::string &expression);

    private:
        bool    isOperator(const std::string &token) const;
        int     calculate(int a, int b, char sign) const;
};

#endif