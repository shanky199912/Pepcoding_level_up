public class Code{
    public static void main(String[] args) {
        
        solve();
    }

    static void solve(){

        //set1();
        set2();
    }

    static void set1(){
        //System.out.println("Hello from java");
        System.out.println(Fact(5));

    }

    public static void set2(){
        // int[] arr=new int[10];  
        // for(int i=0;i<arr.length;i++){
        //   arr[i]=scn.nextInt();
        // }

        int[] arr={1,234,34,7,2,1,23,4,5,6,3,2,5,7,32};
        display(arr,0);
    }

    //-----------------------set1--------------

    public static int Fact(int n){
        if(n<=1) return 1;
 
        int smallAns=Fact(n-1);
        return smallAns*n;
 
         // return n<=1?1:Fact(n-1)*n;
     }
 
     public static int power(int a,int b){
       if(b==0) return 1;
 
       int smallAns=power(a,b-1);
       return smallAns*a;
     }
 
     public static int powerBtr(int a,int b){
         if(b==0) return 1;
 
         int smallAns=powerBtr(a,b/2);
         smallAns*=smallAns;
 
         return b%2==0?smallAns:smallAns*a;
     }
 
     public static int calls(int n) {  // n=5
         if (n <= 1) {
             System.out.println("base: " + n);
             return n + 1;
         }
 
         int count = 0;
 
         System.out.println("Pre: " + n);
         count += calls(n - 1);
 
         System.out.println("In: " + n);
 
         count += calls(n - 2);
         System.out.println("Post: " + n);
 
         return count + 3;
     }
 
     //set2.====================================================
     
     public static void display(int[] arr,int vidx){
         if(vidx==arr.length) return;
 
         System.out.print(arr[vidx] + " ");
         display(arr,vidx+1);
     }
 
     public static boolean find_01(int[] arr,int vidx,int data){
         if(vidx==arr.length) return false;
         
         if(arr[vidx]==data) return true;  // work in pre area.
         return find_01(arr,vidx+1,data);
     }
 
     
     public static boolean find_02(int[] arr,int vidx,int data){
         if(vidx==arr.length) return false;
         
         
         boolean ans=find_02(arr,vidx+1,data);
         if(ans) return true;   //work in post area.
         else
            return arr[vidx]==data;
     }
     
     
     public static int maximum(int[] arr,int vidx){
         if(vidx==arr.length-1) return arr[vidx];
        
         int maxele=maximum(arr,vidx+1);
         return Math.max(maxele,arr[vidx]); // max(a,b); for c++
     }
 
     static int max_=-1;
     public static void maximum_02(int[] arr,int vidx){
         if(vidx==arr.length-1) return ;
         
         max_=Math.max(arr[vidx],max_);
         maximum_02(arr,vidx);
     }
 
     public static int minimum(int[] arr,int vidx){
         if(vidx==arr.length-1) return arr[vidx];
        
         int maxele=minimum(arr,vidx+1);
         return Math.min(maxele,arr[vidx]);  // min(a,b); for c++
     }
}