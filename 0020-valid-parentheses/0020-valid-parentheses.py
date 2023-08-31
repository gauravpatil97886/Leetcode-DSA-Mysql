class Solution(object):
    def isValid(self, s):
        stack = []  # Create an empty stack to store opening brackets
        
        # Loop through each character in the string
        for c in s:
            if c in '([{':  # If the character is an opening bracket
                stack.append(c)  # Push it onto the stack
            else:  # If the character is a closing bracket
                if not stack:
                    return False  # No corresponding opening bracket, so return False
                
                # Check if the top of the stack matches the current closing bracket
                if (c == ')' and stack[-1] != '(') or \
                   (c == '}' and stack[-1] != '{') or \
                   (c == ']' and stack[-1] != '['):
                    return False  # Mismatched brackets, so return False
                
                stack.pop()  # Corresponding opening bracket found, pop it from the stack
        
        return not stack  # If the stack is empty, all brackets are matched, so return True; otherwise, return False
