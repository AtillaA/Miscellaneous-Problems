using System;
using System.Collections.Generic;

public class Solution {
    public IList<int> LexicalOrder(int n) {
        IList<int> lexgr = new List<int>();
        
        // start from 1 to 9 and apply Depth-First Search (DFS) approach
        for (int i = 1; i <= 9; i++) { DFS(i, n, lexgr); }
        return lexgr; // return the final list
    }

    // recursion to explore in the order of e.g. 1 -> 10 -> 100 -> ...
    // for the purpose of achieving lexicographical order
    private void DFS(int current, int n, IList<int> lexgr) {
        if (current > n) return;           // base case (limit is n)

        lexgr.Add(current);                // add to the list

        // generate by appending digits 0 to 9
        for (int j = 0; j <= 9; j++) {
            int next = current * 10 + j;   // append
            if (next > n) break;           // if exceeds, stop exploration
            DFS(next, n, lexgr);           // recurse with the new number
        }
    }
}
