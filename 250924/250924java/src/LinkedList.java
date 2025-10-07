public class LinkedList {
	private Node head;
	private Node tail;
	
	void addLeft(Node cur, char d) {
		if(head == null) {
			Node newNode = new Node(d, null, null);
			head = newNode;
			tail = newNode;
			return;
		}
		Node newNode = new Node(d, cur.getPrev(), cur);
		if(cur.getPrev() == null) {
			head = newNode;
		} else {
			cur.getPrev().setNext(newNode);
		}
		cur.setPrev(newNode);
	}
	
	void addRight(Node cur, char d) {
		if(head == null) {
			Node newNode = new Node(d, null, null);
			head = newNode;
			tail = newNode;
			return;
		}
		Node newNode = new Node(d, cur, cur.getNext());
		if(cur.getNext() == null) {
			tail = newNode;
		} else {
			cur.getNext().setPrev(newNode);
		}
		cur.setNext(newNode);
	}
	
	void del(Node cur) {
		if(head == null) {
			return;
		}
		if(head == tail) {
			head = null;
			tail = null;
		} else if(cur.getPrev() == null) {
			head = cur.getNext();
			cur.getNext().setPrev(null);
		} else if(cur.getNext() == null) {
			tail = cur.getPrev();
			cur.getPrev().setNext(null);
		} else {
			Node prev = cur.getPrev();
			Node next = cur.getNext();
			prev.setNext(next);
			next.setPrev(prev);
		}
	}
	
	Node getHead() { return head; }
	Node getTail() { return tail; }
}