import java.util.Scanner;

public class number_pal {
    public static boolean checkPal(int n) {
        int temp = 0, num = n;
        while(num > 0) {
            temp = temp*10 + num%10;
            num /= 10;
        }
        return n == temp;
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int y = sc.nextInt();

        for(int i=x; i<=y; i++) {
            boolean ans = checkPal(i);
            if(ans == true) System.out.print(i + " ");
        } 
    }
}
