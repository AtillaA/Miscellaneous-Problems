class Solution {
    public int[] optimizedCopy(int[] arr1, int[] arr2) {
        int[] merged = new int[arr1.length + arr2.length];

        // Copy elements from both arrays
        System.arraycopy(arr1, 0, merged, 0, arr1.length);
        System.arraycopy(arr2, 0, merged, arr1.length, arr2.length);

        //System.out.println(Arrays.toString(merged));

        return merged;
    }

    // Pre-built quicksort algorithm
    public void quickSort(int arr[], int begin, int end) {
        if (begin < end) {
            int partitionIndex = partition(arr, begin, end);

            quickSort(arr, begin, partitionIndex - 1);
            quickSort(arr, partitionIndex + 1, end);
        }
    }

    private int partition(int arr[], int begin, int end) {
        // takes the last element as the pivot
        int pivot = arr[end];
        int i = (begin - 1);

        for (int j = begin; j < end; j++) {
            // if smaller: swap the element with the one before
            if (arr[j] <= pivot) {
                i++;

                int swapTemp = arr[i];
                arr[i] = arr[j];
                arr[j] = swapTemp;
            }
        }

        int swapTemp = arr[i+1];
        arr[i+1] = arr[end];
        arr[end] = swapTemp;

        return i + 1;
    }

    public double getMedian(int[] arr) {
        // if odd, median is the middle value | if even, average of the middle two
        if (arr.length % 2 == 1) { return arr[(arr.length / 2)]; } 
        else { return (arr[arr.length / 2 - 1] + arr[arr.length / 2]) / 2.0; }
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] totalArr = optimizedCopy(nums1, nums2); // merge the arrays

        quickSort(totalArr, 0, totalArr.length - 1); // sort elements

        //System.out.println(Arrays.toString(totalArr));

        return getMedian(totalArr); // calculate median
    }
}
