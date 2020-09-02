import java.util.Collections;
import java.util.PriorityQueue;

public class questionsHeap {
    
    public static void main(String[] args) {
        
    }

    public static int klargestElement(int[] arr, int k){

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(int ele: arr)
        {
            pq.add(ele);
            if(pq.size() > k)
            {
                pq.remove();
            }
        }

        return pq.peek();
    }

    public static int kSmallestElement(int[] arr, int k){

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());

        for(int ele: arr)
        {
            pq.add(ele);
            if(pq.size() > k)
            {
                pq.remove();
            }
        }

        return pq.peek();
    }

    class KthLargest {

        PriorityQueue<Integer> pq = new PriorityQueue<>();

        public KthLargest(int k, int[] nums) {

            for(int ele: nums)
            {
                add(ele);
            }
        }
        
        public int add(int val) {
            
            if(pq.size() > k)
            {
                pq.remove();
            }
            else{
                pq.add(val);
            }

            return pq.peek();
        }
    }

    //*Leetcode - 378 =============================================
    public int kthSmallest(int[][] matrix, int k) {
        
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b)->{
            return a[0] - b[0];    //this-other //default ->min pq.
        }); //val, i, j;
        
        int n = matrix.length;
        int m = matrix[0].length;
        
        int ksmall = 0;
        for(int i=0; i<n; i++)
        {
            pq.add(new int[]{matrix[i][0], i, 0});
        }
        
        while(k-- >1)
        {
            int[] arr = pq.remove();
            int j = arr[2];
            int i = arr[1];
            
            if(j < m-1)
                pq.add(new int[]{matrix[i][j+1], i, j+1});
        }
        
        ksmall =  pq.remove()[0];
        return ksmall;
    }
}