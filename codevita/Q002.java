import java.util.*;
public class Q002{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();

        ArrayList<Integer> list1 = new ArrayList();
        list1.add(n1);
        factors(n1, list1);
        ArrayList<Integer> list2 = new ArrayList();
        list2.add(n2);
        factors(n2, list2);

        int len = 0;
        if(list1.size() > list2.size()){
            for(int i =0; i<list2.size(); i++){
                if(list1.contains(list2.get(i))){
                    int idx = list1.indexOf(list2.get(i));
                    len = i + idx;
                    break;
                }
            }
        }
        else{
            for(int i =0; i<list1.size(); i++){
                if(list2.contains(list1.get(i))){
                    int idx = list2.indexOf(list1.get(i));
                    len = i + idx;
                    break;
                }
            }
        }

        System.out.println(len);
    }

    public static void factors(int n, ArrayList<Integer> list){

        while(true){

            int gcd = 1;
            for(int i=1; i< n; i++){
                if(n % i == 0){
                    if(i > gcd)
                        gcd = i;
                }
            }

            if(gcd == 1)
                break;
            else{
                n = gcd;
                list.add(gcd);
            }
        }

        list.add(1);
    }
}