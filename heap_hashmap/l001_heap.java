import java.util.ArrayList;

public class l001_heap {
    public static class heap {
        ArrayList<Integer> arr = new ArrayList<>();

        public heap(int[] list) {

            for (int ele : list)
                arr.add(ele);

            for (int i = arr.size() - 1; i >= 0; i--) {
                downHeapify(i, 0);
            }
        }

        public void swap(int x, int y) {

            int ele1 = arr.get(x);
            int ele2 = arr.get(y);

            arr.set(x, ele2);
            arr.set(y, ele1);
        }

        public void downHeapify(int pi, int n) {

            int lci = 2 * pi + 1;
            int rci = 2 * pi + 2;
            int maxIdx = pi;

            if (lci < n && arr.get(lci) > arr.get(maxIdx))
                maxIdx = lci;

            if (rci < n && arr.get(rci) > arr.get(maxIdx))
                maxIdx = rci;

            if (pi != maxIdx) {
                swap(maxIdx, pi);
                downHeapify(maxIdx, n);
            }
        }

        public void upHeapify(int ci) {

            int pi = (ci -1)/2;
            int minIdx = ci;

            if(pi >=0 && arr.get(pi) < arr.get(minIdx))
                minIdx = pi;

            if(minIdx != ci){
                swap(ci, minIdx);
                upHeapify(minIdx);
            }
        }

        public int size(){
            return arr.size();
        }

        public int top(){
            if(arr.size() == 0) return -1;

            return arr.get(0);
        }

        public boolean isEmpty(){
            return arr.size() == 0;
        }

        public void pop(){
            if(arr.size() == 0) return;

            swap(0, arr.size()-1);
            arr.remove(arr.size()-1);
            downHeapify(0, arr.size());
        }

        public void add(int data){
            arr.add(data);
            upHeapify(arr.size()-1);
        }

    }

    public static void main(String[] args) {
        int[] list = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13}; 
        heap pq = new heap(list);

        // pq.add(125);
        // pq.add(90);
        while(pq.size() != 0){
            System.out.print(pq.top() + " ");
            pq.pop();
        }
    }
}