//11399 bubble sort
import java.util.Scanner;

public class BubbleSort {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[1002];
		for(int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		for(int i = 0; i < n-1; i++) {
			for(int j = 0; j < n-1-i; j++) {
				if(arr[j] > arr[j+1]) {
					int tmp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = tmp;
				}
			}
		}
		int res = 0;
		for(int i = 0; i < n; i++) {
			res += arr[i]*(n-i);
		}
		System.out.print(res);
		sc.close();
	}
}
