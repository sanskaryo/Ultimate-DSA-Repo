# Tree Data Structure Questions

This document curates a comprehensive set of questions on tree data structures, focusing on traversals, binary trees, BST operations, height and diameter calculations, and interview-style problems. Questions are organized by category for clarity and future expansion.

## Basic Concepts

1. **What is a Tree Data Structure?**  
   Explain the definition, properties, and real-world applications of trees. Provide a suitable example.

2. **What is a Binary Tree?**  
   Describe the structure of a binary tree, including root, nodes, leaves, and the maximum number of children per node. Provide a suitable example.

3. **Types of Binary Trees**  
   Discuss full binary trees, complete binary trees, perfect binary trees, balanced binary trees, and degenerate trees. Provide a suitable example.

4. **Tree Terminology**  
   Define terms like root, parent, child, sibling, leaf, subtree, height, depth, and level. Provide a suitable example.

5. **Applications of Trees**  
   List common applications such as file systems, databases (B-trees), expression parsing, and decision trees. Provide a suitable example.

## Traversals

6. **Inorder Traversal**  
   Implement and explain inorder traversal (left-root-right) for a binary tree. Provide both recursive and iterative solutions.  
   **Example**: Tree: 1 (root), left: 2, right: 3; 2's left: 4. Inorder: 4, 2, 1, 3.  
   **Hint**: For recursive, visit left subtree, then root, then right. For iterative, use a stack to simulate the recursion.

7. **Preorder Traversal**  
   Implement and explain preorder traversal (root-left-right) for a binary tree. Provide both recursive and iterative solutions.  
   **Example**: Tree: 1 (root), left: 2, right: 3; 2's left: 4. Preorder: 1, 2, 4, 3.  
   **Hint**: For recursive, visit root, then left subtree, then right. For iterative, use a stack starting with root.

8. **Postorder Traversal**  
   Implement and explain postorder traversal (left-right-root) for a binary tree. Provide both recursive and iterative solutions.  
   **Example**: Tree: 1 (root), left: 2, right: 3; 2's left: 4. Postorder: 4, 2, 3, 1.  
   **Hint**: For recursive, visit left subtree, then right, then root. For iterative, use a stack and process children before root.

9. **Level Order Traversal**  
   Implement level order traversal (breadth-first) for a binary tree.  
   **Example**: Tree: 1 (root), left: 2, right: 3; 2's left: 4. Level order: 1, 2, 3, 4.  
   **Hint**: Use a queue to process nodes level by level, enqueue children as you dequeue parents.

10. **Zigzag Level Order Traversal**  
    Modify level order traversal to alternate directions per level (e.g., left to right, then right to left).  
    **Example**: Tree: 1 (root), left: 2, right: 3; 2's left: 4, 3's right: 5. Zigzag: [1], [3,2], [4,5].  
    **Related Problem**: Given a binary tree, return the zigzag level order traversal as a list of lists.

11. **Morris Traversal**  
    Implement inorder traversal without recursion or stack, using threaded binary trees (Morris method).  
    **Example**: Tree: 1 (root), left: 2, right: 3; 2's right: 4. Inorder: 2,4,1,3.  
    **Related Problem**: Implement preorder Morris traversal.

12. **Boundary Traversal**  
    Traverse the boundary of a binary tree: left boundary, leaves, and right boundary.  
    **Example**: Tree: 1 (root), left: 2, right: 3; 2's left: 4, right: 5; 3's right: 6. Boundary: 1,2,4,5,6,3.  
    **Related Problem**: Print the boundary in anti-clockwise direction.

## Binary Tree Operations

13. **Height of a Binary Tree**  
    Write a function to find the height of a binary tree.  
    **Example**: Tree: 1 (root), left: 2, right: 3; 2's left: 4. Height: 3 (1-2-4).  
    **Hint**: Recursively compute as 1 plus the maximum height of left and right subtrees, or 0 for null.

14. **Diameter of a Binary Tree**  
    Find the diameter (longest path between any two nodes) of a binary tree.  
    **Example**: Tree: 1 (root), left: 2, right: 3; 2's left: 4, right: 5. Diameter: 4 (4-2-1-3 or 4-2-5).  
    **Hint**: The diameter is the maximum of left height + right height + 1, or the diameters of subtrees. Compute heights and diameters in one pass.

15. **Check if Binary Tree is Balanced**  
    Determine if a binary tree is height-balanced (difference in heights of left and right subtrees ≤ 1).

16. **Lowest Common Ancestor (LCA)**  
    Find the LCA of two nodes in a binary tree. Provide solutions for binary trees and BSTs.

17. **Check if Two Trees are Identical**  
    Write a function to check if two binary trees are structurally identical and have the same node values.

18. **Mirror of a Binary Tree**  
    Create a mirror image of a binary tree by swapping left and right subtrees.

19. **Sum of All Nodes**  
    Calculate the sum of all node values in a binary tree.

20. **Count Leaves in a Binary Tree**  
    Count the number of leaf nodes in a binary tree.

21. **Path Sum**  
    Check if there exists a root-to-leaf path with a given sum.

22. **Maximum Path Sum**  
    Find the maximum path sum between any two nodes in a binary tree (can be non-root).

23. **Serialize and Deserialize a Binary Tree**  
    Convert a binary tree to a string (serialize) and reconstruct it from the string (deserialize).

24. **Construct Binary Tree from Traversals**  
    Build a binary tree from given inorder and preorder traversals, or inorder and postorder.

25. **Convert Binary Tree to Doubly Linked List**  
    Flatten a binary tree into a doubly linked list in-place using inorder traversal.

## Binary Search Tree (BST) Operations

26. **Validate BST**  
    Check if a given binary tree is a valid BST (left subtree < root < right subtree).

27. **Insert into a Binary Search Tree**  
    Implement insertion into a BST.  
    **Example**: Insert 5 into BST with root 3 (left: 1, right: 4). Result: 3 (left:1, right:4 (right:5)).  
    **Hint**: Traverse the tree comparing values; insert at the appropriate leaf position where the new node fits.

28. **Delete from BST**  
    Delete a node from a BST, handling cases with 0, 1, or 2 children.

29. **Search in BST**  
    Search for a value in a BST. Discuss time complexity.

30. **Find Minimum/Maximum in BST**  
    Locate the minimum and maximum values in a BST.

31. **Inorder Successor/Predecessor**  
    Find the inorder successor or predecessor of a given node in a BST.

32. **Convert BST to Sorted Doubly Linked List**  
    Transform a BST into a sorted doubly linked list in-place.

33. **Check if BST Contains Dead End**  
    Determine if a BST has a dead end (a node with no children and value = min or max possible).

## Advanced Tree Problems

34. **AVL Tree Insertion**  
    Implement insertion in an AVL tree with rotations to maintain balance.

35. **Red-Black Tree Properties**  
    Explain the properties of red-black trees and their self-balancing mechanism.

36. **Trie (Prefix Tree)**  
    Implement a trie for string operations like insert, search, and delete.

37. **Segment Tree**  
    Build a segment tree for range queries (e.g., range sum, range min/max).

38. **Fenwick Tree (Binary Indexed Tree)**  
    Implement a Fenwick tree for prefix sum queries and updates.

39. **B-Tree**  
    Discuss B-trees, their properties, and applications in databases.

40. **Expression Tree**  
    Construct and evaluate an expression tree from a postfix expression.

41. **Threaded Binary Tree**  
    Explain and implement threaded binary trees for efficient traversals.

42. **Convert General Tree to Binary Tree**  
    Convert a general tree (n-ary) to a binary tree representation.  
    **Example**: General tree: A (children: B, C); B (children: D, E). Binary: A (left: B, right: C); B (left: D, right: E).  
    **Hint**: Use the first child as left child, and siblings as right children in the binary tree.

## Interview-Style Questions

43. **Burning Tree**  
    Find the minimum time to burn a tree starting from a given node, considering fire spreads to adjacent nodes.

44. **Kth Smallest Element in a BST**  
    Find the kth smallest element in a BST.  
    **Example**: BST: 3 (left:1 (right:2), right:4). 2nd smallest: 2.  
    **Hint**: Perform inorder traversal (which gives sorted order) and keep a counter to find the kth element.

45. **Vertical Sum in Binary Tree**  
    Calculate the sum of nodes at each vertical level in a binary tree.

46. **Diagonal Sum in Binary Tree**  
    Compute the sum of nodes for each diagonal in a binary tree.

47. **Top View of Binary Tree**  
    Print the top view (first node at each horizontal distance) of a binary tree.

48. **Bottom View of Binary Tree**  
    Print the bottom view (last node at each horizontal distance) of a binary tree.

49. **Right View of Binary Tree**  
    Print the rightmost node at each level in a binary tree.

50. **Left View of Binary Tree**  
    Print the leftmost node at each level in a binary tree.

51. **Sum of Nodes at Kth Level**  
    Calculate the sum of all nodes at the kth level in a binary tree.

52. **Count Nodes in Complete Binary Tree**  
    Efficiently count the number of nodes in a complete binary tree.

53. **Check if Subtree**  
    Check if a given binary tree is a subtree of another binary tree.

54. **Merge Two Binary Trees**  
    Merge two binary trees by summing overlapping nodes.

55. **Binary Tree Cameras**  
    Place the minimum number of cameras to monitor all nodes in a binary tree.

56. **All Nodes Distance K**  
    Find all nodes at distance K from a given node in a binary tree.

57. **House Robber III**  
    Maximize the amount of money robbed from a binary tree without robbing adjacent nodes.

58. **Unique Binary Search Trees**  
    Count the number of structurally unique BSTs with n nodes.

59. **Recover Binary Search Tree**  
    Correct a BST where two nodes are swapped.

60. **Binary Tree Maximum Width**  
    Find the maximum width of a binary tree (maximum number of nodes at any level).

## Additional Resources

- Practice on platforms like LeetCode, GeeksforGeeks, and InterviewBit.
- Focus on time/space complexities and edge cases (empty trees, single nodes, skewed trees).
- Implement both recursive and iterative solutions where applicable.
