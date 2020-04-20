import java.util.HashSet;
public class Code{
    public static void main(String[] args){

        solve();
    }

    public static void solve(){
        wordbreak();
        crypto();
        crossword();
    }

    static HashSet<String> map = new HashSet<>();

    public static void wordbreak(){
        String[] dic = {"i","like","ilike","sam","sung","samsung","and","man","go","mango"};
        for(String str:dic){
            map.add(str);
        }

        String str = "ilikesamsungandmango";
        System.out.println(wordbreak_(str,""));
    }

    public static int wordbreak_(String str, String ans){

        if(str.length() == 0){
            System.out.println(ans);
            return 1;
        }
        
        int count = 0;
        for(int i=1; i<=str.length(); i++){
            //find the prefix
            String prefix = str.substring(0,i);

            if(map.contains(prefix)){
                String ros = str.substring(i);
                count += wordbreak_(ros, ans + prefix + "-");
            }
        }
        return count;
    }

    public static void crypto(){

    }

    public static void crossword(){

    }
}