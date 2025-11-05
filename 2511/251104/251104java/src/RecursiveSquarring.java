import java.util.Scanner;

public class RecursiveSquarring {
	public static long pow(long a, long b, long c) {
		if(b == 0) return 1;
		if(b == 1) return a % c;
		if(b % 2 == 1) {
			long tmp = pow(a, (b - 1) / 2, c);
			return (((tmp * tmp) % c) * a) % c;
		} else {
			long tmp = pow(a, b / 2, c);
			return (tmp * tmp) % c;
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long c = sc.nextLong();
		System.out.print(pow(a, b, c));
		sc.close();
	}
}
