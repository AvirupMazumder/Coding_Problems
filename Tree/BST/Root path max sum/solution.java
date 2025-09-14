import java.util.*;
import crio.ds.Tree.TreeNode;

/*
Definition of TreeNode

public class TreeNode {
    public long val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode (long x) {
        val = x;
        left = null;
        right = null;
    }
}

*/

class RootPathMaxSumDSAMOCK{
    public static long rootPathMaxSum(TreeNode root) {
        if(root == null) {
            return 0;
        }
        long leftSum = rootPathMaxSum(root.left);
        long rightSum = rootPathMaxSum(root.right);
        if(Math.max(leftSum,rightSum) < 0) {
            return root.val;
        } else {
            return Math.max(leftSum,rightSum) + root.val;
        }
    
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while (t-- > 0) {
            TreeNode root = TreeNode.readTreeReturnRoot(sc);

            long res = rootPathMaxSum(root);

            System.out.println(res);
        }
    }

}
