public class questions {
    // Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    // Leetcode-876 =Middle of linkedlist
    // ===========================================
    public ListNode middleNode(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }

    // Class Question- Another version of Mid of LL => gives us the first mid in
    // case of even nodes.
    public ListNode middleNode_2(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode slow = head, fast = head;
        while (fast != null && fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }

    //Leetcode-206 - Reverse linked list - pointers only=====================
    public ListNode reverseList(ListNode head) {
        
    }

}