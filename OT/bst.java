import java.util.*;
import java.io.*;

class bst {

    public static PrintWriter out;
    static class FastReader {
        BufferedReader br;
        FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException err) {
                err.printStackTrace();
            }
            return str;
        }
    }

    class Node {
        int data;
        Node left, right;
        Node(int item) {
            data = item;
            left = right = null;
        }
    }

    // insert
    // delete
    // search
    // traversal

    Node newNode(int key) {
        Node newNode = new Node(key);
        return newNode;
    }

    Node insert(Node root, int key) {

        if (root == null) {
            root = newNode(key);
            return root;
        }
        else if (root.data > key) {
            insert(root.left, key);
        }
        else if (root.data < key) {
            insert(root.right, key);
        }

        return root;

    }

    Node deleteNode(Node root, int key) {

        if (root.data > key) {
            deleteNode(root.left, key);
        }
        else if (root.data < key) {
            deleteNode(root.right, key);
        }
        else {
            // root is node to be deleted

            if (root.left == null) {
                return root.right;
            }
            else if (root.right == null) {
                return root.left;
            }

            root.data = minValue(root);
            root.right = deleteNode(root.right, root.data);
        }

        return root;

    }

    int minValue(Node root) {
        while(root.left != null) {
            root = root.left;
        }
        return root.data;
    }

    public static void main(String[] args) {

        FastReader in = new FastReader();
        out = new PrintWriter(System.out);

        

    }

}