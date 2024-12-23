/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(matrix, k) {
    const n = matrix.length;
    const minHeap = new MinPriorityQueue({ priority: (a) => a[0] });

    // add the first elt of each row into min-heap
    for (let i = 0; i < n; i++) {
        minHeap.enqueue([matrix[i][0], i, 0]);  // [value, row, col]
    }

    let count = 0;
    let result = 0;

    // extract elts from heap [k times]
    while (count < k) {
        const [val, row, col] = minHeap.dequeue().element;  // get the smallest elt

        // push the next element from the same row until k extractions
        if (col + 1 < n) {
            minHeap.enqueue([matrix[row][col + 1], row, col + 1]);
        }

        // update after each extraction
        result = val;
        count++;
    }

    return result;    
};
