import java.util.EmptyStackException;

public class ArrayStack implements Stack {
	private Object[] array;
	private int size = 0;
	
	public ArrayStack(int capacity) {
		array = new Object[capacity];
	}
	
	public boolean isEmpty() { return (size == 0); }
	public int size() { return size; }
	public void push(Object item) {
		if(size == array.length) {
			throw new FullStackException();
		}
		array[size++] = item;
	}
	public Object pop() {
		if(size == 0) {
			throw new EmptyStackException();
		}
		Object res = array[size-1];
		array[--size] = null;
		return res;
	}
	public Object top() {
		if(size == 0) {
			throw new EmptyStackException();
		}
		return array[size-1];
	}
}