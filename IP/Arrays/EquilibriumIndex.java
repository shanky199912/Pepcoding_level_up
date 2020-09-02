import java.util.*;
import java.lang.*;
import java.io.*;

class EquilibriumIndex {
	public static void main (String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		
		while(t-- >0){
		    int n = s.nextInt();
		    int[] arr = new int[n];
		    
		    for(int i=0; i<n; i++)
		        arr[i] = s.nextInt();
		    
		    // find equilibrium Index.
		    int leftSum = 0;
		    int sum = 0;
		    
		    for(int ele: arr)
		        sum += ele;
		    
		    int ans = -1;
		    for(int i=0; i<n; i++){
		        //right sum calc
		        sum -= arr[i];
		        
		        //when lsum == rightsum
		        if(leftSum == sum)
		            ans = i+1;
		        
		        //update leftSum
		        leftSum += arr[i];
		    }
		    
		    if(ans != -1)
		        System.out.println(ans);
		    else
		        System.out.println(-1);
		}
	}
}