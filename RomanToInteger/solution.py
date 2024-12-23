class Solution:
    def romanToInt(self, s: str) -> int:
        # dictionary of roman numerals
        roman_map = {
            'I': 1, 'V': 5, 'X': 10, 'L': 50,
            'C': 100, 'D': 500, 'M': 1000
        }

        result = 0

        # iterate through string per char
        for i in range(len(s)):
            # if curr has a next && compare the integer value of curr and next
            # subtract the value if (curr numeral < next numeral)
            if i + 1 < len(s) and roman_map[s[i]] < roman_map[s[i + 1]]:
                result -= roman_map[s[i]]
            else:
                # otherwise, add it to the result
                result += roman_map[s[i]]

        return result
