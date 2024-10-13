def isValid(s: str) -> bool:
    # Dictionary to hold the mapping of opening and closing brackets
    bracket_map = {')': '(', '}': '{', ']': '['}
    # Initialize a stack to keep track of opening brackets
    stack = []
    
    # Iterate through each character in the string
    for char in s:
        # If it's a closing bracket
        if char in bracket_map:
            # Pop the topmost element from the stack if it's not empty
            # Otherwise, assign a dummy value
            top_element = stack.pop() if stack else '#'
            # Check if the popped element matches the corresponding opening bracket
            if bracket_map[char] != top_element:
                return False
        else:
            # If it's an opening bracket, push onto the stack
            stack.append(char)

    # In the end, the stack should be empty if all brackets are valid
    return not stack

# Example usage
if __name__ == "__main__":
    test_cases = [
        "()",         # True
        "()[]{}",     # True
        "(]",         # False
        "([)]",       # False
        "{[]}",       # True
    ]

    for test in test_cases:
        print(f"Input: {test}, Output: {isValid(test)}")
