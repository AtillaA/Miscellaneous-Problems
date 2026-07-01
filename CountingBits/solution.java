import java.util.*;

class Solution {
    public static List<Integer> getOneBits(int n) {
      // convert to binary string
      String binaryStr = Integer.toBinaryString(n);
      List<Integer> positions = new ArrayList<>();

      // find 1-bits and record their index (left to right)
      for (int i = 0; i < binaryStr.length(); i++) {
        if (binaryStr.charAt(i) == '1') {
          positions.add(i + 1);
        }
      }

      List<Integer> result = new ArrayList<>();
      result.add(positions.size()); // add the count of 1-bits
      result.addAll(positions); // add all indexes of 1-bits

      return result;  
    }
}
