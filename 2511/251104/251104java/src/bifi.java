import java.util.Scanner;

public class bifi {
	public static long[] fibo(long k) {
		if(k == 1) return new long[] {1, 0}; 
		long[] prev = fibo(k-1);
		return new long[] {prev[0] + prev[1], prev[0]};
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		System.out.print(fibo(n)[0]);
		sc.close();
	}
}
