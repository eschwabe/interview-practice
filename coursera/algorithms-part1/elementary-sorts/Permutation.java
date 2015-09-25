/**
 * Coursera - Algorithms Part I
 * Week 2 - Interview Questions - Elementary Sorts
 *
 * Question 2: Permutation
 * Given two integer arrays of size N, design a subquadratic algorithm to
 * determine whether one is a permutation of the other. That is, do they
 * contain exactly the same entries but, possibly, in a different order.
 *
 * Solution:
 *
 * Sort each integer array and run a linear comparison. If any integer does
 * not align with the other array, then they are not a permutation of each
 * other.
 */

import java.util.Arrays;

class Permutation {

  private static boolean isPermutation(int[] a, int[] b) {
    int[] a1 = new int[a.length];
    int[] b1 = new int[b.length];
    System.arraycopy(a, 0, a1, 0, a.length);
    System.arraycopy(b, 0, b1, 0, b.length);

    Arrays.sort(a1);
    Arrays.sort(b1);

    for (int i = 0; i < a1.length; ++i) {
      if (a1[i] != b1[i]) {
        return false;
      }
    }

    return true;
  }

  public static void main(String[] args) {
    int[] a = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int[] b = { 1, 3, 4, 6 };
    int[] c = { 1, 3, 5, 7, 9, 2, 4, 6, 8 };
    System.out.println(isPermutation(a, b));
    System.out.println(isPermutation(a, c));
    System.out.println(isPermutation(a, a));
    System.out.println(isPermutation(b, c));
  }
}
