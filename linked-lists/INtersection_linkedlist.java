package linked-lists;

public class INtersection_linkedlist {

    // Definition for singly-linked list.
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    /**
     * Finds the intersection node of two singly linked lists.
     * If no intersection, returns null.
     * 
     * Time Complexity: O(m + n)
     * Space Complexity: O(1)
     * 
     * @param headA head of the first linked list
     * @param headB head of the second linked list
     * @return the intersection node or null if no intersection
     */
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;

        ListNode pointerA = headA;
        ListNode pointerB = headB;

        // Traverse both lists, switching heads when reaching the end
        while (pointerA != pointerB) {
            pointerA = (pointerA == null) ? headB : pointerA.next;
            pointerB = (pointerB == null) ? headA : pointerB.next;
        }

        // Either both pointers are null (no intersection) or at the intersection node
        return pointerA;
    }
    
}
