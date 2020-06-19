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

    // Leetcode-206 - Reverse linked list - pointers only=====================
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode forw = curr.next;

            curr.next = prev;
            prev = curr;
            curr = forw;
        }

        head = prev;
        return head;
    }

    public ListNode reverseList_recursive(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode curr = head;
        return reverseList_(curr, null);
    }

    // public ListNode reverseList_(ListNode curr, ListNode prev){
    // if(curr.next == null) return curr;

    // ListNode forw = curr.next;
    // reverseList_(forw, curr);

    // }

    public ListNode reverseList_2(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode curr = head;
        ListNode midNode = middleNode(curr);

        ListNode nhead = midNode.next;
        midNode.next = null;

        nhead = reverseList(nhead);
        ListNode curr1 = nhead;

        while (curr != null && curr1 != null) {
            int temp = curr.val;
            curr.val = curr1.val;
            curr1.val = temp;

            curr = curr.next;
            curr1 = curr1.next;
        }

        nhead = reverseList(nhead);
        midNode.next = nhead;

        return head;
    }

    // Leetcode -234 ============================================
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null)
            return true;

        ListNode curr = head;
        ListNode midNode = middleNode_2(curr); // yahan 2nd method lagega mid node ka

        ListNode nhead = midNode.next;
        midNode.next = null;

        nhead = reverseList(nhead);
        ListNode curr1 = nhead;

        while (curr != null && curr1 != null) {
            if (curr.val != curr1.val)
                return false;
            curr = curr.next;
            curr1 = curr1.next;
        }

        nhead = reverseList(nhead);
        midNode.next = nhead;
        return true;
    }

    public void reorderList(ListNode head) {
        if (head == null || head.next == null)
            return;

        ListNode curr1 = head;
        ListNode midNode = middleNode_2(head);

        ListNode nhead = midNode.next;
        midNode.next = null;

        nhead = reverseList(nhead);
        ListNode curr2 = nhead;

        while (curr1 != null && curr2 != null) {
            ListNode forw1 = curr1.next;
            ListNode forw2 = curr2.next;

            curr1.next = curr2;
            curr2.next = forw1;

            curr1 = forw1;
            curr2 = forw2;
        }
    }

    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode c1 = head;
        ListNode nhead = head.next;
        ListNode c2 = nhead;

        while (c1.next != null && c2.next != null) {
            c1.next = c2.next;
            c1 = c2.next;

            c2.next = c1.next;
            c2 = c1.next;
        }

        c1.next = nhead;
        return head;
    }

    public ListNode EvenOddList(ListNode head) {
        if (head == null || head.next == null)
            return head;

        ListNode c1 = head;
        ListNode nhead = head.next;
        ListNode c2 = nhead;

        while (c1.next != null && c2.next != null) {
            c1.next = c2.next;
            c1 = c2.next;

            if (c1.next != null) {
                c2.next = c1.next;
                c2 = c1.next;
            }
        }

        c2.next = head;
        return nhead;
    }

    // Leetcode -21 merge 2 sorted lists
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null || l2 == null)
            return l1 == null ? l2 : l1;

        ListNode dummy = new ListNode(-1);
        ListNode head = dummy;
        ListNode prev = dummy;

        ListNode c1 = l1;
        ListNode c2 = l2;

        while (c1 != null && c2 != null) {
            if (c1.val <= c2.val) {
                ListNode forw = c1.next;
                prev.next = c1;
                prev = c1;
                c1 = forw;
            } else {
                ListNode forw = c2.next;
                prev.next = c2;
                prev = c2;
                c2 = forw;
            }
        }

        if (c1 != null)
            prev.next = c1;

        if (c2 != null)
            prev.next = c2;

        head = head.next;
        return head;
    }

    //Leetcode - linked list - cycle
    public boolean hasCycle(ListNode head) {
        if(head == null) return false;
        
        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast) return true;
        }

        return false;
    }

    //leetcode - detect cycle point.
    public ListNode detectCycle(ListNode head) {
        if(head == null || head.next == null) return null;

        ListNode slow = head;
        ListNode fast = head;

        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast) break;
        }

        //I will come out of the loop coz of 2 reasons -> 
        // 1. i got my meeting point -> i.e fast meets slow.
        //2. there is no cycle in the LL.
        if(slow !=  fast) return null; // it simply means that no cycle is present in LL.

        slow = head;
        while(slow != fast){
            slow = slow.next;
            fast = fast.next;
        }

        return slow;
    }


    public ListNode removeElements(ListNode head, int val) {
        if(head == null) return head;
        if(head.next == null){
            if(head.val == val) return head.next;
            else return head;
        }

        ListNode curr = head;
        ListNode prev = null;
        
        while(curr != null){
            if(curr.val == val){
                if(prev == null){
                    ListNode forw = head.next;
                    head.next = null;
                    head = forw;
                    curr = head;
                    continue;
                }
                else{
                    ListNode forw = curr.next;
                    prev.next = forw;
                    curr.next = null;
                    curr = prev;
                }
            }

            prev = curr;
            curr = curr.next;
        }

        return head;
    }

    public ListNode removeElements_2(ListNode head, int val) {
        if(head == null) return head;
        if(head.next == null && head.val != val) return head;
        
        while(head != null && head.val == val){
            head = head.next;
        }

        ListNode curr = head;
        while(curr != null){
            if(curr.next != null && curr.next.val == val){
                ListNode forw = curr.next.next;
                ListNode nextNode  = curr.next;
                nextNode.next = null;
                curr.next.next = forw;
            }
            else{
                curr = curr.next;
            }
        }

        return head;
    }

}