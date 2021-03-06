import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Code{
    public static void main(String[] args) {
        
        solve();
        // System.out.println(printStr_cont_codes("26",""));
        System.out.println(numTilePossibilities("AAB",""));
    }

    static void solve(){

        //set1();  
        // set2();
    }

    static void set1(){
       // System.out.println("Hello from java in lecture 2");
        //System.out.println(getSS("abc"));
        //printSS("abc", "");

        // sort in lexicographic order.
        ArrayList<String> res = getSS("abcd");
        Collections.sort(res);
        System.out.println(res);
    }

    static void set2(){

        //System.out.println(getKeyPadCodes_Basic("34"));
        //System.out.println(getKeyPadCodes_Medium("11"));
        //System.out.println(printkpc("34", ""));
        //System.out.println(getPermutation_withDuplicates("aba"));
        //System.out.println(print_Permutation_withDuplicates("aba", ""));
        System.out.println(permuation_withoutDupli("abc",""));
    }

    //set1 ------------------------------------------------

    //return type method.
    public static ArrayList<String> getSS(String str){
        if(str.length()==0){
            ArrayList<String> bres = new ArrayList<>();
            bres.add("");
            return bres;
        }
        char ch = str.charAt(0); //a
        String ros = str.substring(1);
        ArrayList<String> mr = new ArrayList<>();
        ArrayList<String> faith = getSS(ros); //ros = bc , faith ke andar bc ke saare subseq a gye.

        mr.addAll(faith);

        for(String rrs:faith){
            // mr.add(rrs);
            mr.add(ch+rrs);
        }

        return mr;
    }

    //void type vala method
    public static int printSS(String str,String asf){
        if(str.length()==0){
            System.out.println(asf);
            return 1;
        }

        int count = 0;
        //ayega 
        count += printSS(str.substring(1), asf + str.charAt(0));
        // nhi ayega
        count += printSS(str.substring(1), asf);

        return count;
    }

    //set2-----------------------------------
    static String[] codes = { " ", "@%$", "abc", "def", "ghi", "jkl" ,
                             "mno", "pqrs" , "tuv", "wxyz" ,"/:;","+-*" };
                        
    public static ArrayList<String> getKeyPadCodes_Basic(String str){

        if(str.length() == 0){
            ArrayList<String> bres = new ArrayList<>();
            bres.add("");
            return bres;
        }

        if(str.charAt(0) == '-'){
            ArrayList<String> bres = new ArrayList<>();
            return bres;
        }

        char ch = str.charAt(0);
        String ros = str.substring(1);
        ArrayList<String> mr = new ArrayList<>();
        ArrayList<String> faith = getKeyPadCodes_Basic(ros);

        String code = codes[ch -'0'];
        for(int i=0;i<code.length();i++){
            char chh = code.charAt(i);

            for(String rrs:faith){
                mr.add(chh+rrs);
            }
        }
        return mr;
    }

    public static int printkpc(String str, String asf){

        if(str.length() == 0){
            System.out.println(asf);
            return 1;
        }

        int count = 0;
        char ch = str.charAt(0);
        String code = codes[ch-'0'];
        for(int i =0;i<code.length();i++){
            char chh = code.charAt(i);
            count += printkpc(str.substring(1), asf+chh);
        }

        return count;
    }

    //Given a long vector of strings, print the strings that contain the strings
    // generated by numeric string str.
    static String[] searchIn = {
        "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
        "utkarsh", "divyam", "vidhi", "sparsh", "akku","coding"
    };
    //For example, if the input is 26 and the string is coding, 
    //then output should be coding since 26 can produce co which is contained in coding.

    public static int printStr_cont_codes(String str, String asf){

        if(str.length() == 0){
           for(String ss:searchIn){
               if(ss.contains(asf)){
                   System.out.println(ss);
                   return 1;
               }
           }
           return 0;
        }

        int count = 0;
        char ch = str.charAt(0);
        String code = codes[ch-'0'];
        for(int i =0;i<code.length();i++){
            char chh = code.charAt(i);
            count += printStr_cont_codes(str.substring(1), asf + chh);
        }
        return count;
    }

    public static ArrayList<String> getKeyPadCodes_Medium(String str){

        if(str.length() == 0){
            ArrayList<String> bres = new ArrayList<>();
            bres.add("");
            return bres;
        }
        else if(str.length() == 1){
            char ch = str.charAt(0);
            String ros = str.substring(1);
            ArrayList<String> mr = new ArrayList<>();
            ArrayList<String> faith = getKeyPadCodes_Medium(ros);

            String code = codes[ch -'0'];
            for(int i=0;i<code.length();i++){
                char chh = code.charAt(i);

                for(String rrs:faith){
                    mr.add(chh+rrs);
                }
            }
            return mr;
        }
        else {
            char ch = str.charAt(0);
            String ros = str.substring(1);
            ArrayList<String> mr = new ArrayList<>();
            if(ch!=0){
                ArrayList<String> faith = getKeyPadCodes_Medium(ros);
                String code = codes[ch -'0'];
                for(int i=0;i<code.length();i++){
                    char chh = code.charAt(i);

                    for(String rrs:faith){
                        mr.add(chh+rrs);
                    }
                }
            }

            char ch1 = str.charAt(1);
            String ros1 = str.substring(2);
            if(ch !=0){
                int num = (ch-'0') * 10 + (ch1-'0');
                if(num>=10 && num<=11){
                    ArrayList<String> faith1 = getKeyPadCodes_Medium(ros1);
                    String code1 = codes[num];
                    for(int i=0;i<code1.length();i++){
                        char chh = code1.charAt(i);
        
                        for(String rrs:faith1){
                            mr.add(chh+rrs);
                        }
                    }  
                }
            }
            return mr;
        }
    }

    public static ArrayList<String> getPermutation_withDuplicates(String str){

        if(str.length() == 0){
            ArrayList<String> br = new ArrayList<>();
            br.add("");
            return br;
        }

        ArrayList<String> mr = new ArrayList<>();

        char ch = str.charAt(0);
        String ros = str.substring(1);

        ArrayList<String> rr = getPermutation_withDuplicates(ros);

        for(String rrs:rr){

            for(int i=0;i<=rrs.length();i++){
                //add
                mr.add(rrs.substring(0,i) + ch + rrs.substring(i));
            }
        }

        return mr;
    }
    
    public static int print_Permutation_withDuplicates(String str,String asf){
        if(str.length()==0){
            System.out.println(asf);
            return 1;
        }

        int count = 0;
       
        for(int i = 0; i<str.length();i++){
            
            char ch = str.charAt(i); //  ek ek karke a , b, c nikal lo (abc)
            String ros = str.substring(0,i) + str.substring(i+1); // agar ch = b, to subs(0,1) = a , subst(i+1) = c
            //hence total ros = "ac";
            count += print_Permutation_withDuplicates(ros, asf + ch);
        }

        return count;
    }

    public static int permuation_withoutDupli(String str,String ans){
        if(str.length()==0){
            System.out.println(ans);
            return 1;
        }

        int count=0;
        boolean[] vis=new boolean[26];
        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            if(!vis[ch-'a']){
               vis[ch-'a']=true;
               String nstr=str.substring(0,i) + str.substring(i+1);
               count+=permuation_withoutDupli(nstr,ans+ch);
           }
        }

        return count;
    }

    //leetcode.
    public static int numTilePossibilities(String str,String ans){
        if(str.length()==0){ 
            System.out.println(ans);
            return 1;
        }

        int count=0;
        if(ans.length() !=0){
            count++;
            System.out.println(ans);
        }
        boolean[] vis=new boolean[26];
        for(int i=0;i<str.length();i++){
            char ch=str.charAt(i);
            if(!vis[ch-'A']){
                // System.out.println(ch);
               vis[ch-'A']=true;
               String nstr=str.substring(0,i) + str.substring(i+1);
               count+=numTilePossibilities(nstr,ans+ch);
           }
        }

        return count;
    }

    static void printencoding(String str, String asf) {

		if (str.length() == 0) {
			// len = 0 so print asf as it is.
			System.out.println(asf);
			return;
		} else if (str.length() == 1) {
			// len = 1 , then print codes for that single char.
			char ch = str.charAt(0);
			String ros = str.substring(1);

			if (ch != '0') {

				int num = ch - 48;
				char code = (char) ('a' + num - 1);
				printencoding(ros, asf + code);
			}
		} else {
			// len = 2 or > , then do
			char ch0 = str.charAt(0);
			String ros0 = str.substring(1);

			if (ch0 != '0') {
				int num = ch0 - 48;
				char code = (char) ('a' + num - 1);
				printencoding(ros0, asf + code);
			}

			// yahan pe hum apne 2nd char ka kaam krnege.
			char ch1 = str.charAt(1);
			String ros1 = str.substring(2);

			if (ch0 != '0') {
				int num = (ch0 - 48) * 10 + (ch1 - 48);

				if (num >= 10 && num <= 26) {

					char code = (char) ('a' + num - 1);
					printencoding(ros1, asf + code);
				}
			}

		}
	}
}