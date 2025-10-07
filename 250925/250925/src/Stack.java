import java.util.EmptyStackException;

public interface Stack {
    int size();
    boolean isEmpty();
    Object top() throws EmptyStackException;
    void push(Object element) throws FullStackException;
    Object pop() throws EmptyStackException;
}