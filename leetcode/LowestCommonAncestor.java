// Leetcode
// Rotate Array
// Only rotation to the right is supported

public class LowestCommonAncestor {

  public static class TreeNode {
     int val;
     TreeNode left;
     TreeNode right;
     TreeNode(int x) { val = x; }
  }

  private class Nodes {
      TreeNode pNode;
      TreeNode qNode;
      TreeNode aNode;

      public Nodes() {
          qNode = null;
          pNode = null;
          aNode = null;
      }
  }

  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
      return lowestCommonAncestorHelper(root, p, q).aNode;
  }

  private Nodes lowestCommonAncestorHelper(TreeNode root, TreeNode p, TreeNode q) {
      if (root == null) {
          return new Nodes();
      } else {
          Nodes l = lowestCommonAncestorHelper(root.left, p, q);
          Nodes r = lowestCommonAncestorHelper(root.right, p, q);

          Nodes local = l;
          if (local.pNode == null) { local.pNode = r.pNode; }
          if (local.pNode == null && root == p) { local.pNode = root; }
          if (local.qNode == null) { local.qNode = r.qNode; }
          if (local.qNode == null && root == q) { local.qNode = root; }
          if (local.aNode == null) { local.aNode = r.aNode; }
          if (local.aNode == null && (local.pNode != null && local.qNode != null) ) {
              local.aNode = root;
          }
          return local;
      }
  }

  public static void main(String[] args) {
    TreeNode root = new TreeNode(1);
    root.left = new TreeNode(2);
    root.right = new TreeNode(3);
    root.right.right = new TreeNode(4);

    LowestCommonAncestor ancestor = new LowestCommonAncestor();

    System.out.println(ancestor.lowestCommonAncestor(root, root.right.right, root.left).val);
    System.out.println(ancestor.lowestCommonAncestor(root, root.right.right, root.right).val);
  }
}
