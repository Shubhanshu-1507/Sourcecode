#include <iostream>
#include <stack>
#include <unordered_map>

bool isValid(const std::string& s) {
    std::stack<char> stack;
    std::unordered_map<char, char> bracket_map = {{')', '('}, {'}', '{'}, {']', '['}};
    
    for (char c : s) {
        if (bracket_map.find(c) != bracket_map.end()) {
            char top_element = stack.empty() ? '#' : stack.top();
            stack.pop();
            if (bracket_map[c] != top_element) {
                return false;
            }
        } else {
            stack.push(c);
        }
    }
    
    return stack.empty();
}

int main() {
    std::string s = "{[()]}";
    bool result = isValid(s);
    
    std::cout << "Valid Parentheses Result: " << (result ? "True" : "False") << std::endl;  // Output should be True
    
    return 0;
}
