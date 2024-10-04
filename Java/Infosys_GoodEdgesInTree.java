/*
    PROBLEM WAS ASKED IN INFOSYS SP EXAM FOR THE YEAR 2024 - Contributed by Sourasish Mondal
    
    Sample 2: Medium

    You are given a tree consisting of N nodes.
    You are also given two arrays A and P of size N each, where the
    value A[i] denotes the value written on the ith node and the
    value P[i] denotes that there is an edge between the
    node i and P[i].
    We say that an edge is considered good, if after deleting this
    edge (this will result in formation of 2 trees), the values in each of
    the nodes of the trees are distinct.
    Find the total number of good edges present in tree.
    Input Format
    1. The first line contains an integer, N, denoting the number of
    elements in A.
    2. Each line i of the N subsequent lines (where 0 ≤ i < N)
    contains an integer describing A[i].
    3. Each line i of the N subsequent lines (where 0 ≤ i < N)
    contains an integer describing P[i].

    Constraints
    • 1 <= 𝑁 <= 10^5
    • 1 <= 𝐴[𝑖] <= 10^5
    • 1 <= 𝑃[𝑖] <= 10^5

    Sample Input-1:
    2 
    1 1
    0 1

    Sample output-1:
    1

    Explanation-1:
    Given N = 2, A = [1, 1], P = [0, 1] The only
    edge between the node 1 - 2 is good. Hence,
    the answer is equal to 1.

    Sample Input-2:

    4 
    1 2 3 4
    0 1 2 3

    Sample output-2:
    3

    Explanation-2:
    Given N = 4, A = [1, 2, 3, 4], P = [0, 1, 2, 3] All of edges 1 - 2, 3 - 2, 3 - 4 are
    good edges. Hence, the answer is equal to 3.

    Sample Input-3:
    6 
    1 1 2 3 2 3 
    0 1 2 3 4 5

    Sample output-3:
    0

    Explanation-3:
    Given N = 6, A = [1, 1, 2, 3, 2, 3], P = [0, 1, 2,
    3, 4, 5] None of the edges are good. Hence, the
    answer is equal to 0.

 */

import java.util.*;

public class Infosys_GoodEdgesInTree {
    private static List<List<Integer>> tree;
    private static int[] values;
    private static int goodEdges;

    public static int countGoodEdges(int N, int[] A, int[] P) {
        tree = new ArrayList<>(N);
        values = A;
        goodEdges = 0;
        for (int i = 0; i < N; i++) {
            tree.add(new ArrayList<>());
        }
        // Build the tree
        for (int i = 1; i < N; i++) {
            tree.get(i).add(P[i]);
            tree.get(P[i]).add(i);
        }
        dfs(0, -1);
        return goodEdges;
    }
    private static Set<Integer> dfs(int node, int parent) {
        Set<Integer> nodeValues = new HashSet<>();
        nodeValues.add(values[node]);
        for (int child : tree.get(node)) {
            if (child != parent) {
                Set<Integer> childValues = dfs(child, node);
                if (Collections.disjoint(nodeValues, childValues)) {
                    goodEdges++;
                }
                nodeValues.addAll(childValues);
            }
        }
        return nodeValues;
    }
    public static void main(String[] args) {
        // Sample Input-1
        int N1 = 2;
        int[] A1 = {1, 1};
        int[] P1 = {0, 1};
        System.out.println(countGoodEdges(N1, A1, P1));  // Output: 0

        // Sample Input-2
        int N2 = 4;
        int[] A2 = {1, 2, 3, 4};
        int[] P2 = {0, 1, 2, 3};
        System.out.println(countGoodEdges(N2, A2, P2));  // Output: 3
    }
}