//24060 merge sort
import java.util.Scanner;

public class Main {
	static int[] tmp;
	static int k, cnt, res;
	
	public static void mergeSort(int[] arr, int s, int e) {
		if(s < e) {
			int m = (s+e)/2;
			mergeSort(arr, s, m);
			mergeSort(arr, m+1, e);
			merge(arr, s, e);
		}
	}
	
	public static void merge(int[] arr, int s, int e) {
		int m = (s+e)/2;
		int i = s, j = m+1, t = s;
		while(i <= m && j <= e) {
			if(arr[i] < arr[j]) {
				tmp[t++] = arr[i++];
			} else {
				tmp[t++] = arr[j++];
			}
		}
		while(i <= m) tmp[t++] = arr[i++];
		while(j <= e) tmp[t++] = arr[j++];

		for(int l = s; l <= e; l++) {
			arr[l] = tmp[l];
			cnt++;
			if(cnt == k) res = arr[l];
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		k = sc.nextInt();
		cnt = 0;
		res = -1;
		int[] arr = new int[n+1];
		tmp = new int[n];
		
		for(int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		
		mergeSort(arr, 0, n-1);
		
		System.out.print(res);
		
		sc.close();
	}
}
