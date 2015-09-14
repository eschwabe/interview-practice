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
 * Note: Code below is an unoptomized example solution. Does not handle many
 * edge cases.
 */

class BitonicArray {

  private static boolean binarySearchAsc(int[] array, int start, int end, int target) {
    int mid = ((end - start) / 2) + start;
    if (array[mid] == target) {
      return true;
    } else if (array[mid] > target && start != mid) {
      return binarySearchAsc(array, start, mid-1, target);
    } else if (array[mid] < target && start != mid) {
      return binarySearchAsc(array, mid+1, end, target);
    } else {
      return false;
    }
  }

  private static boolean binarySearchDesc(int[] array, int start, int end, int target) {
    int mid = ((end - start) / 2) + start;
    if (array[mid] == target) {
      return true;
    } else if (array[mid] < target && start != mid) {
      return binarySearchDesc(array, start, mid-1, target);
    } else if (array[mid] > target && start != mid) {
      return binarySearchDesc(array, mid+1, end, target);
    } else {
      return false;
    }
  }

  private static int binarySearchPeak(int[] array, int start, int end) {
    int mid = ((end - start) / 2) + start;
    if (array[mid] > array[mid-1] && array[mid] > array[mid+1]) {
      return mid;
    } else if (start == end) {
      return -1;
    } else if (array[mid] > array[mid+1]) {
      return binarySearchPeak(array, start, mid-1);
    } else if (array[mid] < array[mid+1]) {
      return binarySearchPeak(array, mid+1, end);
    } else {
      return -1;
    }
  }

  private static boolean find(int[] array, int peak, int target) {
    return binarySearchAsc(array, 0, peak, target) ||
      binarySearchDesc(array, peak+1, array.length-1, target);
  }

  public static void main(String[] args) {
    int[] array = { 1, 2, 3, 4, 5, 10, 9, 8, 7, 6 };
    int target = 0;

    int peak = binarySearchPeak(array, 0, array.length-1);
    if (peak == -1) {
      System.out.println("Invalid bitonic array");
    } else {
      System.out.println(target + ": " + find(array, peak, target));
      target = 1;
      System.out.println(target + ": " + find(array, peak, target));
      target = 8;
      System.out.println(target + ": " + find(array, peak, target));
      target = 20;
      System.out.println(target + ": " + find(array, peak, target));
    }
  }
}
