using System;
using System.Collections.Generic;

public class Solution {
    public IList<int> LexicalOrder(int n) {
        IList<int> lexgr = new List<int>();
        
        // start from 1 to 9 and apply Depth-First Search (DFS) approach
        for (int i = 1; i <= 9; i++) { DFS(i, n, lexgr); }
        return lexgr; // return the final list
    }

    private void DFS(int current, int n, IList<int> lexgr) {
        if (current > n) return;  // base case (limit is n)

        lexgr.Add(current);  // add to the list

        // generate by appending digits 0 to 9
        for (int i = 0; i <= 9; i++) {
            int next = current * 10 + i;  // append
            if (next > n) break;  // if exceeds, stop exploration
            DFS(next, n, lexgr);  // recurse with the new number
        }
    }
}
