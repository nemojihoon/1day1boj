//1991 tree order
import java.util.Scanner;

public class Main {
	static int[][] arr = new int[30][3];
	public static void in(int cur, StringBuilder sb) {
		if(arr[cur][0] != -1) in(arr[cur][0], sb);
		sb.append((char)(cur + 'A'));
		if(arr[cur][1] != -1) in(arr[cur][1], sb);
	}
	
	public static void pre(int cur, StringBuilder sb) {
		sb.append((char)(cur + 'A'));
		if(arr[cur][0] != -1) pre(arr[cur][0], sb);
		if(arr[cur][1] != -1) pre(arr[cur][1], sb);
	}
	
	public static void post(int cur, StringBuilder sb) {
		if(arr[cur][0] != -1) post(arr[cur][0], sb);
		if(arr[cur][1] != -1) post(arr[cur][1], sb);
		sb.append((char)(cur + 'A'));
	} 
	
	public static void main(String[] args) {
		Scanner  sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i = 0; i < n; i++) {
			char cur = sc.next().charAt(0);
			char l = sc.next().charAt(0);
			char r = sc.next().charAt(0);
			
			arr[cur-'A'][0] = -1;
			arr[cur-'A'][1] = -1;
			if(l != '.') arr[cur-'A'][0] = l-'A';
			if(r != '.') arr[cur-'A'][1] = r-'A';
//			System.out.println(arr[cur-'A'][0] + " " + arr[cur-'A'][1]);
		}
		StringBuilder s1 = new StringBuilder();
		StringBuilder s2 = new StringBuilder();
		StringBuilder s3 = new StringBuilder();
		
		pre(0, s1);
		in(0, s2);
		post(0, s3);
		
		System.out.println(s1);
		System.out.println(s2);
		System.out.println(s3);
		sc.close();
	}
}
