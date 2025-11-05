import java.util.Scanner;
public class Sort {
	public static void swap(int[] arr, int i, int j) {
		int tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	public static int partition(int[] arr, int a, int b) {
		int pivot = arr[b];
		int l = a, r = b-1;
		while(true) {
			while(arr[l] < pivot) l++;
			while(r >= a && arr[r] > pivot) r--;
			if(l >= r) break;
			swap(arr, l, r);
		}
		swap(arr, l, b);
		return l;
	}
	public static void quickSort(int[] arr, int a, int b) {
		if(a >= b) return;
		int p = partition(arr, a, b);
		quickSort(arr, a, p-1);
		quickSort(arr, p+1, b);
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) {
			arr[i] = sc.nextInt();
		}
		quickSort(arr, 0, n-1);
		StringBuilder sb = new StringBuilder();
        for (int x : arr) sb.append(x).append('\n');
        System.out.print(sb);
		sc.close();
	}
}
