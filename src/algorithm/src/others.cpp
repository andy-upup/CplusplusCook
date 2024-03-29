#include "others.h"

namespace algo {

int JuiceNum(const int n) {
    int total = n;
    int empty = n;
    int carry = 0;
    while (empty >= 1) {
        empty += carry;
        carry = (empty & 1);
        empty >>= 1;
        total += empty;
    }
    return total;
}

static void Calculate(
    std::stack<double>& digits,
    std::stack<char>& ops) {
    double x = digits.top();
    digits.pop();
    double y = digits.top();
    digits.pop();
    char op = ops.top();
    ops.pop();
    if (op == '+') {
        digits.push(y + x);
    } else if (op == '-') {
        digits.push(y - x);
    } else if (op == '*') {
        digits.push(y * x);
    } else if (op == '/') {
        digits.push(y / x);
    }
    return;
}

// Whether the priority of top is higher than current, or equal.
static bool CmpX(char top, char current) {
    // Indicates that the corresponding right bracket has not been reached yet.
    if (top == '(') {
        return false;
    } else if ((top == '+' || top == '-') && (current == '*' || current == '/')) {
        return false;
    }
    return true;
}

static bool Cmp(char top, char current) {
    if ((top == '+' || top == '-') && (current == '*' || current == '/')) {
        return false;
    }
    return true;
}

void CalculatorWithBrackets(std::string& input) {
    std::stack<double> digits;
    std::stack<char> ops;
    ops.push('(');
        input += ')';
    bool is_next_op = false;
    const int size = static_cast<int>(input.size());
    for (int i = 0; i < size; ++i) {
        if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
            ops.push('(');
        } else if (input[i] == ')' || input[i] == ']' || input[i] == '}') {
            while (ops.top() != '(') {
                Calculate(digits, ops);
            }
            ops.pop();
        } else if (is_next_op) {
            while (CmpX(ops.top(), input[i])) {
                Calculate(digits, ops);
            }
            ops.push(input[i]);
            is_next_op = false;
        } else { // Get digits
            int j = i;
            // '+' or '-' maybe a sign
            if (input[i] == '+' || input[i] == '-') {
                ++i;
            }
            while (input[i] >= '0' && input[i] <= '9') {
                ++i;
            }
            digits.push(static_cast<double>(std::stoi(input.substr(j, i - j))));
            --i;
            // Next charactor is an operator
            is_next_op = true;
        }
    }
    std::cout << digits.top() << std::endl;
}

void Calculator(std::string& input) {
    std::stack<double> digits;
    std::stack<char> ops;

    bool is_next_op = false;
    const int size = static_cast<int>(input.size());
    for (int i = 0; i < size; ++i) {
        if (is_next_op) {
            while (!ops.empty() && Cmp(ops.top(), input[i])) {
                Calculate(digits, ops);
            }
            ops.push(input[i]);
            is_next_op = false;
        } else {
            int j = i;
            if (input[i] == '+' || input[i] == '-') {
                ++i;
            }
            while (input[i] >= '0' && input[i] <= '9') {
                ++i;
            }
            digits.push(static_cast<double>(std::stoi(input.substr(j, i - j))));
            --i;
            if (i == size - 1) {
                while (!ops.empty()) {
                    Calculate(digits, ops);
                }
            }
            is_next_op = true;
        }
    }
    std::cout << digits.top() << std::endl;
}

int NotRepeatDigit(const std::vector<int>& nums) {
    if ((nums.empty()) || (nums.size() % 2 != 1)) {
        return -1;
    }
    if (nums.size() == 1) {
        return nums[0];
    }

    const int size = static_cast<int>(nums.size());
    int digit = nums[0];
    for (int i = 1; i < size; ++i) {
        digit ^= nums[i];
    }
    return digit;
}

} // namespace algo