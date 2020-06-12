public class l001{
    public static class linkedlist{
        public class Node{
            int data = 0;
            Node next = null;

            public Node(int data){
                this.data = data;
            }
        }

        Node head = null;
        Node tail = null;
        int size = 0;

        public int size() {return this.size;}

        public boolean isEmpty() {return this.size == 0;}

        public void addFirst(int data){
            Node node = new Node(data);
            addFirstNode(node);
        }

        private void addFirstNode(Node node){
            if(this.size == 0){
                this.head = node;
                this.tail = node;
            }
            else{
                node.next = this.head;
                this.head = node;
            }
            this.size++;
        }

        public void addLast(int data){
            Node node = new Node(data);
            addLastNode(node);
        }

        private void addLastNode(Node node){
            if(this.size == 0){
                this.head = node;
                this.tail = node;
            }
            else{
                this.tail.next = node;
                this.tail = node;
            }
            this.size++;
        }

        private void addAtNode(Node node, int pos){
            if(pos == 0){
                addFirstNode(node);
            }
            else if(pos == this.size){
                addLastNode(node);
            }
            else{
                Node prev = getNodeAt(pos-1);
                Node temp = prev.next;

                prev.next = node;
                node.next = temp;
                this.size++;
            }
        }

        public void addAt(int data, int pos){
            if(pos <0 || pos > this.size ){
                System.out.println("Invalid position");
                return;
            }

            Node node = new Node(data);
            addAtNode(node, pos);
        }

        public Node getNodeAt(int pos){
            Node curr = this.head;
            while(pos-- > 0){
                curr = curr.next;
            }
            return curr;
        }

        public int removeFirst(){
            if(this.size == 0){
                System.out.println("Empty list");
                return -1;
            }

            Node rnode = this.head;
            if(this.size == 1){
                this.head = null;
                this.tail = null;
            }
            else{
                this.head = this.head.next;
                rnode.next = null;
            }

            this.size--;
            return rnode.data;
        }

        public int removeLast(){
            if(this.size == 0){
                System.out.println("Empty list");
                return -1;
            }

            Node rnode = this.tail;
            if(this.size == 1){
                this.head == null;
                this.tail == null;
            }
            else{
                Node secondLastNode = getNodeAt(this.size()-2);
                secondLastNode.next = null;
                this.tail = secondLastNode;
            }

            this.size--;
            return rnode.data;
        }

        private int removeAtNode(int pos){
            if(pos == 0) removeFirst();
            else if(pos == this.size-1) removeLast();
            else{
                
            }
        }

        public int removeAt(int pos){
            if(pos <0 || pos >= this.size){
                System.out.println("Invalid pos");
                return -1;
            }

            return removeAtNode(pos);
        }

        public int getFirst(){

        }

        public int getLast(){

        }

        

        @Override
        public String toString(){
            Node curr = this.head;
            String str = "";
            while(curr != null){
                str += curr.data + " -> ";
                curr = curr.next;
            }
            return str;
        }
    }

    public static void main(String[] args){
        linkedlist ll = new linkedlist();
        ll.addFirst(10);
        ll.addFirst(20);
        ll.addLast(30);
        System.out.println(ll);

    }
}