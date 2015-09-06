// Leetcode
// Ugly Number

public class UglyNumber {
    public boolean isUgly(int num) {
        if (num == 0) {
            return false;
        } else if (num == 1) {
            return true;
        }
        
        while (num != 2 && num != 3 && num != 5) {
            if (num % 2 == 0) {
                num = num / 2;
            } else if (num % 3 == 0) {
                num = num / 3;
            } else if (num % 5 == 0) {
                num = num / 5;
            } else {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) {
        UglyNumber ugly = new UglyNumber();
        
        System.out.println(ugly.isUgly(3));
        System.out.println(ugly.isUgly(4));
        System.out.println(ugly.isUgly(7));
        System.out.println(ugly.isUgly(1000));
        System.out.println(ugly.isUgly(134));
    }
}