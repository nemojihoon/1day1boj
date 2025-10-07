public class Node {
	private char data;
	private Node prev;
	private Node next;
	
	Node(char d, Node p, Node n){
		data = d;
		prev = p;
		next = n;
	}
	
	void setData(char d) {
		data = d;
	}
	
	void setNext(Node n) {
		next = n;
	}
	
	void setPrev(Node p) {
		prev = p;
	}
	
	char getData() { return data; }
	Node getPrev() { return prev; }
	Node getNext() { return next; }
}