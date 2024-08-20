// JAVA
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

import java.util.*;

public class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        // TreeMap to store column index as key and another TreeMap as value
        TreeMap<Integer, TreeMap<Integer, List<Integer>>> columnMap = new TreeMap<>();
        // Queue to perform BFS
        Queue<Pair<TreeNode, Pair<Integer, Integer>>> nodeQueue = new LinkedList<>();
        nodeQueue.add(new Pair<>(root, new Pair<>(0, 0)));

        while (!nodeQueue.isEmpty()) {
            Pair<TreeNode, Pair<Integer, Integer>> curr = nodeQueue.poll();
            TreeNode node = curr.getKey();
            int row = curr.getValue().getKey();
            int col = curr.getValue().getValue();

            // Add node value to the columnMap
            columnMap.putIfAbsent(col, new TreeMap<>());
            columnMap.get(col).putIfAbsent(row, new ArrayList<>());
            columnMap.get(col).get(row).add(node.val);

            // Add left and right children to the queue
            if (node.left != null) {
                nodeQueue.add(new Pair<>(node.left, new Pair<>(row + 1, col - 1)));
            }
            if (node.right != null) {
                nodeQueue.add(new Pair<>(node.right, new Pair<>(row + 1, col + 1)));
            }
        }

        List<List<Integer>> result = new ArrayList<>();
        for (TreeMap<Integer, List<Integer>> rows : columnMap.values()) {
            List<Integer> column = new ArrayList<>();
            for (List<Integer> nodes : rows.values()) {
                Collections.sort(nodes);
                column.addAll(nodes);
            }
            result.add(column);
        }

        return result;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        Solution solution = new Solution();
        List<List<Integer>> verticalOrder = solution.verticalTraversal(root);

        System.out.println("Vertical Order Traversal:");
        for (List<Integer> column : verticalOrder) {
            for (Integer node : column) {
                System.out.print(node + " ");
            }
            System.out.println();
        }
    }
}

// Utility class for pairs
class Pair<K, V> {
    private K key;
    private V value;
    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }
    public K getKey() {
        return key;
    }
    public V getValue() {
        return value;
    }
}







// CPP

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> columnMap;
        queue<pair<TreeNode*, pair<int, int>>> nodeQueue;
        nodeQueue.push({root, {0, 0}});

        while (!nodeQueue.empty()) {
            auto curr = nodeQueue.front();
            nodeQueue.pop();
            TreeNode* node = curr.first;
            int row = curr.second.first;
            int col = curr.second.second;

            columnMap[col][row].push_back(node->val);

            if (node->left) {
                nodeQueue.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                nodeQueue.push({node->right, {row + 1, col + 1}});
            }
        }

        vector<vector<int>> result;
        for (const auto& colPair : columnMap) {
            vector<int> column;
            for (const auto& rowPair : colPair.second) {
                vector<int> nodes = rowPair.second;
                sort(nodes.begin(), nodes.end());
                column.insert(column.end(), nodes.begin(), nodes.end());
            }
            result.push_back(column);
        }

        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;
    vector<vector<int>> verticalOrder = solution.verticalTraversal(root);

    cout << "Vertical Order Traversal:" << endl;
    for (const auto& column : verticalOrder) {
        for (const auto& node : column) {
            cout << node << " ";
        }
        cout << endl;
    }

    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
