//1406 Linked List
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		LinkedList ll = new LinkedList();
		String input = sc.nextLine();
		
		for(char c:input.toCharArray()) {
//			System.out.print(c);
			ll.addRight(ll.getTail(), c);
		}
		ll.addRight(ll.getTail(), 't');
		
		Node cur = ll.getTail();
		int n = sc.nextInt();
		for(int i = 0; i < n; i++) {
			String cmd = sc.next();
			switch(cmd) {
			case "L":
				if(cur != ll.getHead()) cur = cur.getPrev();
				break;
			case "D":
				if(cur != ll.getTail()) cur = cur.getNext();
				break;
			case "B":
				if(cur != ll.getHead()) ll.del(cur.getPrev());
				break;
			case "P":
				String data = sc.next();
				ll.addLeft(cur, data.charAt(0));
				break;				
			}
//			System.out.println(cur.getData());
		}
		
		StringBuilder sb = new StringBuilder();
		cur = ll.getHead();
		while (cur.getNext() != null) {
		    sb.append(cur.getData());
		    cur = cur.getNext();
		}
		System.out.print(sb.toString());
		
		sc.close();
	}
}