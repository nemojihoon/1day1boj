//1697 dp
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n, m, t;
		final int MAX = 150005;
		
		n = sc.nextInt();
		m = sc.nextInt();
	
		Queue<Integer> q = new LinkedList<>();
		int[] vi = new int[MAX];
		
		q.add(n);
		vi[n] = 1;
		
		while(vi[m] == 0) {
			t = q.poll();
			if(t > 0 && vi[t-1] == 0) {
				vi[t-1] = vi[t] + 1;
				q.add(t-1);
			}
			if(t+1 < MAX && vi[t+1] == 0) {
				vi[t+1] = vi[t] + 1;
				q.add(t+1);
			}
			if(2*t < MAX && vi[2*t] == 0) {
				vi[2*t] = vi[t] + 1;
				q.add(2*t);
			}
		}
		
		System.out.print(vi[m] -1);
		
		sc.close();
	}
}