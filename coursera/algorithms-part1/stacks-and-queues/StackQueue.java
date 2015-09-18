/**
 * Coursera - Algorithms Part I
 * Week 2 - Interview Questions - Stacks and Queues
 *
 * Question 1: Queue with two stacks
 *
 * Implement a queue with two stacks so that each queue operations takes a
 * constant amortized number of stack operations.
 */

/**
 * Solution:
 *
 * Use one stack for keeping track of elements queued up and another for
 * tracking elements to be dequeued. When the dequeue stack if empty, the
 * elements from the enqueue stack are popped and pushed into the dequeue
 * stack. This operation reverses the order of elements so they are in FIFO.
 *
 * The dequeue stack cannot be populated until depleated, otherwise elements
 * would be out of order.
 */

import java.util.Stack;

class StackQueue<Item> {

  private Stack<Item> input = new Stack<Item>();
  private Stack<Item> output = new Stack<Item>();

  public StackQueue() {

  }

  public int size() {
    return input.size() + output.size();
  }

  public boolean isEmpty() {
    return (size() == 0);
  }

  public void enqueue(Item item) {
    if (item == null) {
      throw new java.lang.NullPointerException();
    }
    input.push(item);
  }

  public Item dequeue() {
    if (isEmpty()) {
      throw new java.util.NoSuchElementException();
    }

    if (output.isEmpty()) {
      while (!input.isEmpty()) {
        output.push(input.pop());
      }
    }

    return output.pop();
  }

  // unit testing
  public static void main(String[] args) {
    StackQueue<Integer> squeue = new StackQueue<Integer>();
    int i = 0;
    int N = 100;

    System.out.println("Size: " + squeue.size());
    squeue.enqueue(i);
    while (i <= N) {
      if (i % 3 == 0) {
        System.out.println("Dequeue: " + squeue.dequeue());
      } else {
        squeue.enqueue(i);
        System.out.println("Enqueue: " + i);
      }
      ++i;
    }
    System.out.println("Size: " + squeue.size());
    while (!squeue.isEmpty()) {
        System.out.println("Dequeue: " + squeue.dequeue());
    }
    System.out.println("Size: " + squeue.size());
  }

}
