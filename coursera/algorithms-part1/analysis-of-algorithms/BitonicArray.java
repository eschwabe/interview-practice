/**
 * Coursera - Algorithms Part I
 * Week 1 - Interview Questions - Union Find
 *
 * Question 2: Search in a bitonic array
 * An array is bitonic if it is comprised of an increasing sequence of integers
 * followed immediately by a decreasing sequence of integers. Write a program
 * that, given a bitonic array of N distinct integer values, determines whether
 * a given integer is in the array.
 *
 * Standard version: Use ~3lgN compares in the worst case.
 * Signing bonus: Use ~2lgN compares in the worst case (and prove that no
 * algorithm can guarantee to perform fewer than ~2lgN compares in the worst case).
 */

/**
 * Solution:
 *
 * Use three binary searches.
 * 1) Locate the point in the array where ascending switchines to descending
 * 2) Perform binary search on each half of the array for the target integer
 *
 */

class BitonicArray {

  private static boolean bitonicSearch(int[] array, int start, int end, int target, boolean desc) {
    int mid = (start + end) / 2;
    if (array[mid] == target) {
      return true;
    }
    if (start > end) {
      return false;
    }

    if ((desc && array[mid] < target) || (!desc && array[mid] > target)) {
      return bitonicSearch(array, start, mid-1, target, desc);
    } else {
      return bitonicSearch(array, mid+1, end, target, desc);
    }
  }

  private static int binarySearchPeak(int[] array, int start, int end) {
    int mid = (start + end) / 2;
    if (start == end) {
      return mid;
    } else if (array[mid] < array[mid+1]) {
      return binarySearchPeak(array, mid+1, end);
    } else {
      return binarySearchPeak(array, start, mid);
    }
  }

  private static boolean find(int[] array, int peak, int target) {
    return bitonicSearch(array, 0, peak, target, false) ||
      bitonicSearch(array, peak, array.length-1, target, true);
  }

  public static void main(String[] args) {
    int[] array = { 1, 2, 3, 4, 5, 15, 10, 9, 8, 7, 6 };
    int target = 0;

    int peak = binarySearchPeak(array, 0, array.length-1);
    System.out.println(target + ": " + find(array, peak, target));
    target = 1;
    System.out.println(target + ": " + find(array, peak, target));
    target = 8;
    System.out.println(target + ": " + find(array, peak, target));
    target = 20;
    System.out.println(target + ": " + find(array, peak, target));
  }
}
