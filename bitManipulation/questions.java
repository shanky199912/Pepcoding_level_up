import java.util.*;
public class questions{
    public static void main(String[] args) {
        solve();
    }

    public static void rightMostSetBit(int n){
        int ans = (n & ((~n) +1));
        //?  (~n + 1) = (-n) => 2's compliment.
        System.out.println(ans);
    }

    public static void countSetBits_01(int n){
        int counter = 0;
        while(n != 0){
            int mask = (n & ((~n) + 1));
            n = (n & mask);
            counter++;
        }
        System.out.println(counter);
    }

    //* Kerninghan's Algo
    // * https://www.geeksforgeeks.org/count-set-bits-in-an-integer/
    public static void countSetBits_02(int n){
        
        int counter = 0;
        while(n != 0){
            n = ((n-1) & n);
            counter++;
        }
        System.out.println(counter);
    }

    //! -> arr milega jisme ki saare number repeat krte hai, except one. find that number. 
    //* prop of xor -> 1^1 = 0; 0^0 = 0; 1^0 = 1 => that a^a = 0; a^b = 1;
    public static void singleNumber1(int[] arr){
        //? -> arr = {1,3,4,5,3,1,4};
        //? -> 1^3^4^5^3^1^4; => 1^1^3^3^4^4^5;
        int ans = 0;
        for(int ele: arr)
            ans ^= ele;
        System.out.println(ans); 
    }

    public static void solve(){
        rightMostSetBit(27);
    }

}