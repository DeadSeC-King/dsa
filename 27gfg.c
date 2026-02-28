/*
class Node {
    public int data;
    public Node next;
    public Node(int val) {
        data = val;
        next = null;
    }
}
*/

class Solution {
    public void removeLoop(Node head) {
        if (head == null || head.next == null)
            return;

        Node slow = head, fast = head;
        bool hasLoop = false;

        // Step 1: Detect loop
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;

            if (slow == fast) {
                hasLoop = true;
                break;
            }
        }

        if (!hasLoop) return;

        // Step 2: Find start of loop
        slow = head;

        // Case 1: Loop starts at head
        if (slow == fast) {
            while (fast.next != slow)
                fast = fast.next;
        }
        else {
            while (slow.next != fast.next) {
                slow = slow.next;
                fast = fast.next;
            }
        }

        // Step 3: Break loop
        fast.next = null;
    }
}