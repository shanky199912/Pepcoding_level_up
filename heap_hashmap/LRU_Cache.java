import java.util.*;

public class LRU_Cache{

    class Node{

        int key = 0;
        int value = 0;

        Node prev = null;
        Node next = null;

        public Node(int key, int value, Node prev, Node next){
            this.key = key;
            this.value = value;
            this.prev = prev;
            this.next = next;
        }
    }

    //Two pointers head and tail , head will point to the first node in ll and tail will point to the last node in ll.
    public Node head = null; 
    public Node tail = null;

    public HashMap<Integer, Node> map; // HashMap to store all the keys present in our cache.

    public int get(int key){ //Need to achieve get function in O(1) -> thats why created hashmap for it.

        
    }


}