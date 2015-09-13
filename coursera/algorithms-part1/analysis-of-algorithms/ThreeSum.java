/**
 * Coursera - Algorithms Part I
 * Week 1 - Interview Questions - Analysis of Algorithms
 *
 * Question 1: 3-SUM in quadratic time
 *
 * Design an algorithm for the 3-SUM problem that takes time proportional to N2
 * in the worst case. You may assume that you can sort the N integers in time
 * proportional to N2 or better.
 */

import java.util.Collections;
import java.util.ArrayList;
import java.util.Scanner;

class ThreeSum {

  public static void main(String[] args) {

    // initialize array
    ArrayList<Integer> data = new ArrayList<Integer>();
    Scanner scan = new Scanner(System.in);
    while (scan.hasNextInt()) {
      data.add(scan.nextInt());
    }

    // sort array
    Collections.sort(data);

    // compute all 3-sum combinations
    for (int i = 0; i < data.size()-2; ++i) {
      int j = i+1;
      int k = data.size()-1;

      while (j < k) {
        int sum = data.get(i)+data.get(j)+data.get(k);
        if (sum == 0) {
          System.out.println(i+":"+data.get(i)+", "+j+":"+data.get(j)+", "+k+":"+data.get(k));
        }
        if (sum >= 0) {
          --k;
        } else {
          ++j;
        }
      }
    }

  }

}
