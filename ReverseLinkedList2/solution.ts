/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function reverseBetween(head: ListNode | null, left: number, right: number): ListNode | null {
    // base case
    if (!head || left === right) return head;

    const dummy = new ListNode(0, head); // dummy pointer
    let prev = dummy; // to track prev node

    // reach the node just before inversion (advance 'prev' to exactly before 'left')
    for (let i = 0; i < left - 1; i++) { prev = prev.next!; }

    // init pointers for the inversion
    const curr = prev.next!; // set to start of the section to be reversed
    let nextNode: ListNode | null = null; // temp to hold the reference of shift

    // swap all nodes in the sublist iteratively
    for (let i = 0; i < right - left; i++) {
        nextNode = curr.next!; // save the node after curr
        curr.next = nextNode.next; // bypass 'nextNode' by linking 'curr' to subsequent node
        nextNode.next = prev.next; // point 'nextNode.next' to current start of the reversed sublist
        prev.next = nextNode; // connect 'prev' to 'nextNode', moving it to the front of sublist
    }

    return dummy.next; // return the modified list, starting from original head position
}
