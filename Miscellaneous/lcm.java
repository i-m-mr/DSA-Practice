import java.util.Scanner;

public class lcm {
    public static int gcd(int num1, int num2) {
        if(num2 == 0) return num1;
        return gcd(num2, num1%num2);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int num1 = sc.nextInt();
        int num2 = sc.nextInt();

        int gcd = gcd(num1, num2);
        int ans = (num1*num2) / gcd;

        System.out.println("LCM of " + num1 + " and " + num2 + " is " + ans );
    }
}
