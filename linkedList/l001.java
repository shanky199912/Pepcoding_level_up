public class l001 {

    public static class linkedlist { // Our own linkedlist stl class.. make this when someone ask you to make ur own
                                     // stl linkedlist.
        public class Node {
            int data = 0;
            Node next = null;

            public Node(int data) {
                this.data = data;
            }
        }

        Node head = null;
        Node tail = null;
        int size = 0;

        public int size() {
            return this.size;
        }

        public boolean isEmpty() {
            return this.size == 0;
        }

        public Node getNodeAt(int pos) {
            Node curr = this.head;
            while (pos-- > 0) {
                curr = curr.next;
            }
            return curr;
        }

        private void addLastNode(Node node) {
            if (this.size == 0) {
                this.head = node;
                this.tail = node;
            } else {
                this.tail.next = node;
                this.tail = node;
            }
            this.size++;
        }

        public void addLast(int data) {
            Node node = new Node(data);
            addLastNode(node);
        }

        private void addFirstNode(Node node) {
            if (this.size == 0) {
                this.head = node;
                this.tail = node;
            } else {
                node.next = this.head;
                this.head = node;
            }
            this.size++;
        }

        public void addFirst(int data) {
            Node node = new Node(data);
            addFirstNode(node);
        }

        private void addAtNode(Node node, int pos) {
            if (pos == 0) {
                addFirstNode(node);
            } else if (pos == this.size) {
                addLastNode(node);
            } else {
                Node prevNode = getNodeAt(pos - 1);
                Node temp = prevNode.next;
                prevNode.next = node;
                node.next = temp;

                this.size++;
            }
        }

        public void addAt(int data, int pos) {
            if (pos < 0 || pos > this.size)
                return;

            Node node = new Node(data);
            addAtNode(node, pos);
        }

        public int removeFirst() {
            if (this.size == 0) {
                System.out.println("Empty list");
            }

            Node rnode = this.head;
            if (this.size == 1) {
                this.head = null;
                this.tail = null;
            } else {
                this.head = this.head.next;
                rnode.next = null;
            }

            this.size--;
            return rnode.data;
        }

        public int removeLast() {
            if (this.size == 0) {
                System.out.println("Empty list");
            }

            Node rnode = this.head;
            if (this.size == 1) {
                this.head = null;
                this.tail = null;
            } else {
                Node secondLastNode = getNodeAt(this.size() - 2);
                secondLastNode.next = null;
                this.tail = secondLastNode;
            }

            this.size--;
            return rnode.data;
        }

        public int removeAt(int pos) {
            if(pos < 0 || pos >= this.size()){ System.out.println("Invalid pos"); return -1;}
            else if(pos == 0) return removeFirst();
            else if(pos == this.size()-1) return removeLast();
            else{
                Node prevNode = getNodeAt(pos-1);
                Node rnode = prevNode.next;
                Node temp = rnode.next;

                prevNode.next = temp;
                rnode.next = null;

                this.size--;
                return rnode.data;
            }
        }

        public int getFirst() {
            if (this.size == 0) {
                System.out.println("EmptyList!");
                return -1;
            }
            return this.head.data;
        }

        public int getLast() {
            if (this.size == 0) {
                System.out.println("EmptyList!");
                return -1;
            }
            return this.tail.data;
        }

        public int getAt(int pos) {
            if (pos >= this.size || pos < 0) {
                System.out.println("NullPointException!");
                return -1;
            }

            return 0;
        }

        @Override
        public String toString() {
            String str = "";
            Node curr = this.head;
            while (curr != null) {
                str += curr.data + " -> ";
                curr = curr.next;
            }
            return str;
        }

    }

    public static void main(String[] args) {
        linkedlist ll = new linkedlist();
        for (int i = 1; i < 10; i++) {
            ll.addLast(i * 10);
        }
        ll.addAt(120, 5);
        ll.addAt(150, 3);
        System.out.println(ll);
        System.out.println(ll.removeAt(3));
        System.out.println(ll);
    }
}