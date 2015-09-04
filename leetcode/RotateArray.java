// Leetcode
// Rotate Array
// Only rotation to the right is supported

public class RotateArray {
  public void rotate(int[] nums, int k) {
    if (k < 0) {
      return;
    }
    int rotate = k % nums.length;
    int[] tmp = new int[nums.length];
    for (int i = 0; i < nums.length; ++i) {
      tmp[i] = nums[i];
    }
    int pos = 0;
    for (int i = nums.length - rotate; i < nums.length; ++i) {
      nums[pos++] = tmp[i];
    }
    for (int i = 0; i < nums.length - rotate; ++i) {
      nums[pos++] = tmp[i];
    }
  }

  public void printArray(int[] nums) {
    for (int i = 0; i < nums.length; ++i) {
      System.out.print(nums[i]);
      System.out.print(' ');
    }
    System.out.println();
  }

  public static void main(String[] args) {
    int[] test = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };

    RotateArray s = new RotateArray();

    System.out.println("Original");
    s.printArray(test);
    s.rotate(test, 1);
    s.printArray(test);
    s.rotate(test, test.length);
    s.printArray(test);
    s.rotate(test, test.length+1);
    s.printArray(test);
    s.rotate(test, 5);
    s.printArray(test);
    s.rotate(test, -1);
    s.printArray(test);
  }
}
