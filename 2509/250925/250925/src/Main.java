//1874 stack
import java.util.Scanner;
import java.util.EmptyStackException;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[] target = new int[n];
		int cur = 1;
		boolean pos = true;
		ArrayStack num = new ArrayStack(n);
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++) {
			target[i] = sc.nextInt();
			while(target[i] >= cur) {
				num.push(cur++);
				sb.append("+\n");
			}
			if(target[i] == (int)num.top()) {
				num.pop();
				sb.append("-\n");
			} else {
				pos = false;
				break;
			}
		}
		
		if(!pos) {
			System.out.print("NO");
		} else {
			System.out.print(sb);
		}
		
		
		sc.close();
	}
}