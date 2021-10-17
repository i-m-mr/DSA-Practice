import java.lang.*;
import java.util.*;

public class coprime_divisible {
    public static int gcd(int x, int y) {
        if(y == 0) return x;
        return gcd(y, x%y);
    }
    public static void solve(int x, int y) {
        for(int l=x; l<y; l++) {
            if(gcd(x, l) == 1 && y%l == 0) 
                System.out.print(l + " ");
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int x = sc.nextInt();
        int y = sc.nextInt();

        solve(x, y);
        
    }
}