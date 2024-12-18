import java.util.Deque;
import java.util.LinkedList;

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int[] maxList = new int[nums.length - k + 1]; // stores max of each window
        Deque<Integer> deque = new LinkedList<>(); // double-ended queue: stores indices

        for (int i = 0; i < nums.length; i++) {
            // remove indices that are out of the current window
            if (!deque.isEmpty() && deque.peekFirst() < i - k + 1) {
                deque.pollFirst();
            }

            // remove elements from the deque that are smaller than the current element
            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) {
                deque.pollLast();
            }

            // add the index of the current element
            deque.offerLast(i);

            // if the window has reached size k, record the maximum element for the window
            if (i >= k - 1) {
                maxList[i - k + 1] = nums[deque.peekFirst()];
            }
        }

        return maxList;
    }
}
