// Leetcode
// Queue implemented using a stack

import java.util.Stack;

class QueueUsingStack {

    private Stack<Integer> stack = new Stack<Integer>();

    // Push element x to the back of queue.
    public void push(int x) {
        Stack<Integer> tmp = new Stack<Integer>();
        while(!stack.empty()) {
            tmp.push(stack.peek());
            stack.pop();
        }
        stack.push(x);
        while(!tmp.empty()) {
            stack.push(tmp.peek());
            tmp.pop();
        }
    }

    // Removes the element from in front of queue.
    public void pop() {
        stack.pop();
    }

    // Get the front element.
    public int peek() {
        return stack.peek();
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return stack.empty();
    }

    public static void main(String[] args) {
      QueueUsingStack queue = new QueueUsingStack();

      System.out.println(queue.empty());
      queue.push(1);
      queue.push(2);
      queue.push(3);
      queue.push(4);
      System.out.println(queue.empty());
      System.out.println(queue.peek());
      queue.pop();
      System.out.println(queue.peek());
      queue.pop();
      System.out.println(queue.peek());
      queue.pop();
      System.out.println(queue.peek());
      queue.pop();
      System.out.println(queue.empty());
    }
}
