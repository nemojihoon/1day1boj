import java.util.Scanner;

public class QuadTree {
	static StringBuilder sb = new StringBuilder("");
	static int[][] arr = new int[65][65];
	
	public static void f(int x, int y, int k) {
		if(k == 1) {
			sb.append(arr[x][y]);
			return;
		}
		for(int i = x; i < x+k; i++) {
			for(int j = y; j < y+k; j++) {
				if(arr[i][j] != arr[x][y]) {
					sb.append("(");
					f(x, y, k/2); f(x, y+k/2, k/2);
					f(x+k/2, y, k/2); f(x+k/2, y+k/2, k/2);
					sb.append(")");
					return;
				}
			}
		}
		sb.append(arr[x][y]);
		return;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 0; i < n; i++) {
			String line = sc.next();
			for(int j = 0; j < n; j++) {
				arr[i][j] = line.charAt(j) - '0';
			}
		}
		f(0, 0, n);
		System.out.print(sb);
		sc.close();
	}
}
