/*
  Coursera - Algorithms Part II

  Week 1 - Interview Questions

  Question 3: Successor with delete.

  Given a set of N integers S={0,1,...,N−1} and a sequence of requests of the
  following form:
  - Remove x from S
  - Find the successor of x: the smallest y in S such that y≥x.

  Design a data type so that all operations (except construction) should take
  logarithmic time or better.
*/

/*
  Solution:
  Use union find data structure to mark successor of each integer. When an
  integer is removed, the union find data structure connects to the next
  integer in the list (which may be farther up the list). Must be careful with
  optimizations since connected component id is the successor integer.
*/

import edu.princeton.cs.algs4.QuickFindUF;

class SuccessorWithDelete {

  private QuickFindUF uf;

  public SuccessorWithDelete(int N) {
    uf = new QuickFindUF(N);
  }

  public void remove(int x) {
    uf.union(x, x+1);
  }

  public int successor(int x) {
    return uf.find(x);
  }

  public static void main(String[] args) {
    int N = 50;
    SuccessorWithDelete swd = new SuccessorWithDelete(50);
    System.out.println(swd.successor(10));
    swd.remove(11);
    swd.remove(13);
    swd.remove(12);
    swd.remove(10);
    swd.remove(9);
    swd.remove(15);
    System.out.println(swd.successor(8));
    System.out.println(swd.successor(9));
    System.out.println(swd.successor(10));
  }
}
