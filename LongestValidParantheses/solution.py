class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """

        # check if s contains anything other than parantheses
        allowed_chars = {'(', ')'}
        self.input_checker(s, allowed_chars)

        stack = [-1]  # Initialize with -1 to handle base case of empty string
        max_len = 0

        for i, char in enumerate(s):
            if char == '(':
                stack.append(i)  # Push the index of '('
            else:
                stack.pop()  # Pop the last '(' index
                if stack:
                    max_len = max(max_len, i - stack[-1])  # Calculate the length of valid substring
                else:
                    stack.append(i)  # Reset the base index for the next valid substring

        return max_len


    def input_checker(self, input_string, allowed_chars):
        """
        :type input_string: str
        :type allowed_chars: set
        :rtype: none
        """
        
        for char in input_string:
            if char not in allowed_chars:
                print("Invalid character detected: '{}'. Shutting down...".format(char))
                sys.exit(1)  # Shut down w/ a non-zero exit code
        print("Input is valid.")
