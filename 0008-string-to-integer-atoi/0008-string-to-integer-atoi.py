import re
MAX_INT = 2147483647
MIN_INT = -2147483648

class Solution:
    def myAtoi(self, s):
        result = 0
        sign = 1
        i = 0

        s = s.strip()

        if i < len(s) and (s[i] == '+' or s[i] == '-'):
            if s[i] == '-':
                sign = -1
            i += 1

        while i < len(s) and s[i].isdigit():
            result = result * 10 + int(s[i])
            i += 1

        result *= sign
        result = max(min(result, MAX_INT), MIN_INT)

        return result
