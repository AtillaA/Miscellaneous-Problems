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

function addTwoNumbers(l1: ListNode | null, l2: ListNode | null): ListNode | null {
    const dummyHead = new ListNode(0); // placeholder for result
    let current = dummyHead; // track the pointer
    let carry = 0; // if the result has more digits

    // main loop
    while (l1 !== null || l2 !== null || carry > 0) {
        let sum = carry;

        // check l1
        if (l1 !== null) {
            sum += l1.val; // add value to sum
            l1 = l1.next; // move to next node in l1
        }

        // check l2
        if (l2 !== null) {
            sum += l2.val; // add value to sum
            l2 = l2.next; // move to next node in l2
        }

        // calc new carry and digit value for current pos
        carry = Math.floor(sum / 10); // extract the tens digit as carry (0 or 1)
        current.next = new ListNode(sum % 10); // extract the ones digit and create a new node
        current = current.next; // move to the new result node
    }

    return dummyHead.next; // returns the actual start
}
