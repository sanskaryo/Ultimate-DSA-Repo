# Trees

## Overview

Trees are a fundamental non-linear data structure that represents hierarchical data. They consist of nodes connected by edges. Each tree has a root node, and every node (except the root) has one parent. Nodes can have zero or more children. Binary trees, where each node has at most two children, are a particularly common and important type.

## Key Concepts

- **Nodes & Edges**: A tree is a collection of nodes and the edges that connect them.
- **Root**: The top-most node in the tree.
- **Parent/Child**: A node that has a child is a parent; the node it points to is its child.
- **Leaf**: A node with no children.
- **Traversal**: The process of visiting (checking or updating) each node in a tree. Common methods include:
  - Depth-First Search (DFS: Pre-order, In-order, Post-order)
  - Breadth-First Search (BFS: Level-order)
- **Height/Depth**: The height of a tree is the length of the longest path from the root to a leaf. The depth of a node is the length of the path from the root to that node.
- **Binary Search Tree (BST)**: A specific type of binary tree where for each node, all values in its left subtree are lesser, and all values in its right subtree are greater.

## Common Problems

1. Diameter of a Binary Tree
2. Lowest Common Ancestor (LCA)
3. Level Order Traversal (BFS)
4. Validate Binary Search Tree
5. Invert a Binary Tree

## Time Complexities (for a Balanced Binary Search Tree)

| Operation       | Time Complexity |
| --------------- | --------------- |
| Access (Search) | O(log n)        |
| Search          | O(log n)        |
| Insertion       | O(log n)        |
| Deletion        | O(log n)        |
| Traversal (all) | O(n)            |

> **Note**: For an unbalanced tree, the worst-case time complexity for access, search, insertion, and deletion becomes O(n).

## Files in this directory

- `tree-diameter.py` - Calculates the longest path between any two nodes in a tree.
- `lca.py` - Finds the lowest common ancestor of two given nodes.
- `level-order-traversal.py` - Traverses the tree level by level using BFS.
- `validate-binary-search-tree.py` - Checks if a tree is a valid Binary Search Tree.
- `invert-binary-tree.py` - Mirrors a binary tree by swapping left and right children.

