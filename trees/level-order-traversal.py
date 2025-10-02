"""
Binary Tree Level Order Traversal

This algorithm traverses a binary tree level by level, from left to right,
visiting all the nodes at each level before moving to the next. The result is
a list of lists, where each inner list contains the values of nodes at a
particular level.

The algorithm uses a Breadth-First Search (BFS) approach, which is perfectly
suited for level-by-level traversal. A queue data structure is used to keep
track of the nodes to visit.

The process is as follows:
1. Initialize a queue and add the root node to it.
2. While the queue is not empty, determine the number of nodes at the current
   level (which is the current size of the queue).
3. Create a list to store the values for the current level.
4. Dequeue all nodes for the current level, add their values to the level list,
   and enqueue their children (if they exist).
5. Once all nodes for the level are processed, add the level list to the final
   result list.
6. Repeat until the queue is empty.

Time Complexity: O(N), where N is the number of nodes in the tree, as each node is visited exactly once.
Space Complexity: O(W), where W is the maximum width of the tree. In the worst-case scenario
(a complete binary tree), the last level can contain up to N/2 nodes, so the space complexity
can be O(N).
"""

from collections import deque
from typing import List, Optional

class TreeNode:
    """
    A class to represent a node in a binary tree.
    """
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        # Helper for printing node info
        return f"TreeNode({self.val})"


def level_order_traversal(root: Optional[TreeNode]) -> List[List[int]]:
    """
    Performs a level order traversal on a binary tree.

    Args:
        root: The root node of the binary tree.

    Returns:
        A list of lists, where each inner list contains node values at a level.
    """
    if not root:
        return []

    result = []
    queue = deque([root])

    while queue:
        # Number of nodes at the current level
        level_size = len(queue)
        current_level = []

        # Process all nodes for the current level
        for _ in range(level_size):
            node = queue.popleft()
            current_level.append(node.val)

            # Add children of the processed node to the queue for the next level
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        
        result.append(current_level)

    return result

# Test cases
if __name__ == "__main__":
    # Construct the following binary tree for testing:
    #        3
    #       / \
    #      9  20
    #        /  \
    #       15   7
    root1 = TreeNode(3)
    root1.left = TreeNode(9)
    root1.right = TreeNode(20, TreeNode(15), TreeNode(7))

    print("--- Test Case 1: Standard Tree ---")
    traversal1 = level_order_traversal(root1)
    print(f"Tree structure: A standard multi-level tree")
    print(f"Expected Traversal: [[3], [9, 20], [15, 7]]")
    print(f"Calculated Traversal: {traversal1}\n")

    # --- Test Case 2: A left-skewed tree ---
    #   1
    #  /
    # 2
    #  \
    #   3
    root2 = TreeNode(1)
    root2.left = TreeNode(2, None, TreeNode(3))
    print("--- Test Case 2: Skewed Tree ---")
    traversal2 = level_order_traversal(root2)
    print(f"Tree structure: A skewed tree")
    print(f"Expected Traversal: [[1], [2], [3]]")
    print(f"Calculated Traversal: {traversal2}\n")

    # --- Test Case 3: Tree with a single node ---
    root3 = TreeNode(42)
    print("--- Test Case 3: Single Node Tree ---")
    traversal3 = level_order_traversal(root3)
    print(f"Tree structure: A single node")
    print(f"Expected Traversal: [[42]]")
    print(f"Calculated Traversal: {traversal3}\n")

    # --- Test Case 4: Empty tree ---
    root4 = None
    print("--- Test Case 4: Empty Tree ---")
    traversal4 = level_order_traversal(root4)
    print(f"Tree structure: Empty (None)")
    print(f"Expected Traversal: []")
    print(f"Calculated Traversal: {traversal4}\n")

    # --- Test Case 5: A complete binary tree ---
    #        1
    #       / \
    #      2   3
    #     / \ / \
    #    4  5 6  7
    root5 = TreeNode(1)
    root5.left = TreeNode(2, TreeNode(4), TreeNode(5))
    root5.right = TreeNode(3, TreeNode(6), TreeNode(7))
    print("--- Test Case 5: Complete Binary Tree ---")
    traversal5 = level_order_traversal(root5)
    print(f"Tree structure: A complete binary tree")
    print(f"Expected Traversal: [[1], [2, 3], [4, 5, 6, 7]]")
    print(f"Calculated Traversal: {traversal5}\n")