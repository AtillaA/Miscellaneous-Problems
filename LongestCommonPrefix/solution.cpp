#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // base case
        if (strs.empty()) return "";
        
        // iterate through each char
        for (int i = 0; i < strs[0].length(); ++i) {
            char c = strs[0][i];
            
            // compare w/ the same pos in others
            for (int j = 1; j < strs.size(); ++j) {
                // if end of string or a char mismatch
                if (i == strs[j].length() || strs[j][i] != c) {
                    // return the substring up to the current index
                    return strs[0].substr(0, i);
                }
            }
        }
        
        // if the entire string is a common prefix
        return strs[0];
    }
};
