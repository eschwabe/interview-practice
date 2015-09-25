/**
 * Coursera - Algorithms Part I
 * Week 2 - Interview Questions - Stacks and Queues
 *
 * Question 4: Detect cycle in a linked list
 * Detect cycle in a linked list. A singly-linked data structure is a data
 * structure made up of nodes where each node has a pointer to the next node
 * (or a pointer to null). Suppose that you have a pointer to the first node of
 * a singly-linked list data structure:
 *
 * -Determine whether a singly-linked data structure contains a cycle. You may
 * 	use only two pointers into the list (and no other variables). The running
 * 	time of your algorithm should be linear in the number of nodes in the data
 * 	structure.
 *
 * -If a singly-linked data structure contains a cycle, determine the first
 * 	node that participates in the cycle. you may use only a constant number
 * 	of pointers into the list (and no other variables). The running time of
 * 	your algorithm should be linear in the number of nodes in the data structure.
 *
 * 	You may not modify the structure of the linked list.
 */

class LinkedListCycle {

  public static class Node {
    public int value;
    public Node next;

    public Node(int value) {
      this.value = value;
      this.next = null;
    }
  }

  public static Node cycleFirstNode(Node root) {
    if (root == null || root.next == null) {
      return null;
    }

    Node p1 = root;
    Node p2 = root;

    // find cycle in loop where pointers cross
    // p1 increments one node per iteration
    // p2 increments two nodes per iteration
    do {
      if (p1 == null || p2 == null || p2.next == null) {
        return null;
      }
      p1 = p1.next;
      p2 = p2.next.next;
    } while (p1 != p2);

    // find cycle start by resetting p1 to beginning
    // increment pointers until they meet again
    p1 = root;
    while (p1 != p2) {
      p1 = p1.next;
      p2 = p2.next;
    }

    return p1;
  }

  public static void main(String[] args) {

    Node root = new Node(0);
    Node current = root;
    Node cycle = null;

    // generate list
    int total = 20;
    int count = 1;
    while (count < total) {
      Node newNode = new Node(count);
      current.next = newNode;
      current = newNode;
      ++count;
      if (count == 3) {
        cycle = current;
      }
    }

    // create cycle
    System.out.println("Cycle inserted at: " + cycle.value);
    current.next = cycle;

    // locate cycle
    Node found = cycleFirstNode(root);
    if (cycle == null) {
      System.out.println("No Cycle");
    } else {
      System.out.println("Cycle located at: " + found.value);
    }
  }

}
