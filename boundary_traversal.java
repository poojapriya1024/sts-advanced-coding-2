import java.util.*;

class Node {

    int data;
    Node left, right;

    Node(int val)
    {
        this.data = val;
        left = null;
        right = null;
    }
}


public class boundary_traversal {

    static boolean isLeaf(Node root)
    {
        if(root == null)
            return false;
        
            return root.left == null && root.right == null;
    }
    
    static void getLeftNodes(Node root, List<Integer> solution)
    {
        if(isLeaf(root))
            return;

        solution.add(root.data);

        if(root.left != null)
            getLeftNodes(root.left, solution);
        else if(root.right != null)
            getLeftNodes(root.right, solution);
    }

    static void getRightNodes(Node root, List<Integer> solution)
    {
        if(isLeaf(root))
            return;

        solution.add(root.data);

        if(root.right != null)
            getLeftNodes(root.right, solution);
        else if(root.left != null)
            getLeftNodes(root.left, solution);
    }

    static void inOrderTraversal(Node root, List<Integer> solution)
    {
        if(root == null)
            return;

        if(isLeaf(root))
        {
            solution.add(root.data);
            return;
        }

        inOrderTraversal(root.left, solution);
        inOrderTraversal(root.right, solution);
    }

    static void printList(List<Integer> list)
    {
        for(int i: list)
            System.out.print(i + " ");
        
        System.out.println();
    }
    static List<Integer> boundary(Node root)
    {
        List<Integer> solution = new ArrayList<>();
        solution.add(root.data);

        if(isLeaf(root))
            return solution;
        
        if(root.left != null)
            getLeftNodes(root.left, solution);
        
        inOrderTraversal(root, solution);

        List<Integer> rightNodes = new ArrayList<>();

        if(root.right != null)
            getRightNodes(root.right, rightNodes);

        if(!rightNodes.isEmpty())
        {
            for(int i=rightNodes.size() - 1;i>=0; i--)
                solution.add(rightNodes.get(i));
        }

        return solution;
    }
    public static void main(String args[])
    {
        Node root = new Node(2);
        Node leftNode = new Node(4);
        Node rightNode = new Node(8);
        rightNode.right = new Node(15);

        leftNode.left = new Node(16);
        leftNode.right = new Node(3);

        leftNode.right.left = new Node(9);
        leftNode.right.right = new Node(12);

        root.left = leftNode;
        root.right = rightNode;

        List<Integer> solution = boundary(root);
        printList(solution);
    }
}

