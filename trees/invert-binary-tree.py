"""
Invert a Binary Tree

This algorithm inverts a binary tree by mirroring it. For every node in the tree,
its left and right children are swapped. This operation is performed recursively
for all nodes.

The process can be visualized as flipping the tree horizontally. It can be solved
using various tree traversal methods (pre-order, post-order, or even level-order),
but a recursive approach is often the most elegant and intuitive.

The recursive algorithm is as follows:
1. The base case for the recursion is a null node. If the node is null, we do nothing
   and simply return.
2. Recursively call the invert function on the left child.
3. Recursively call the invert function on the right child.
4. Swap the left and right children of the current node.
5. Return the root of the now-inverted tree.

This is a classic example of a post-order traversal, where we process the children
first before processing the parent node (in this case, "processing" is the swap).

Time Complexity: O(N), where N is the number of nodes, as each node is visited once.
Space Complexity: O(H), where H is the height of the tree, for the recursion stack.
In the worst case (a skewed tree), this is O(N). For a balanced tree, it's O(log N).
"""

from typing import Optional
from collections import deque

class TreeNode:
    """
    A class to represent a node in a binary tree.
    """
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def __repr__(self):
        return f"TreeNode({self.val})"

def invert_tree(root: Optional[TreeNode]) -> Optional[TreeNode]:
    """
    Inverts a binary tree by swapping the left and right children of all nodes.

    Args:
        root: The root node of the binary tree.

    Returns:
        The root node of the inverted binary tree.
    """
    # Base case: if the node is null, there's nothing to invert.
    if not root:
        return None

    # Recursively invert the left and right subtrees.
    invert_tree(root.left)
    invert_tree(root.right)

    # Swap the left and right children of the current node.
    root.left, root.right = root.right, root.left

    return root

# Helper function to print the tree in level order for verification
def print_level_order(root: Optional[TreeNode]):
    """Prints the tree level by level."""
    if not root:
        print("[]")
        return

    result = []
    queue = deque([root])
    while queue:
        level_size = len(queue)
        current_level = []
        for _ in range(level_size):
            node = queue.popleft()
            if node:
                current_level.append(node.val)
                queue.append(node.left)
                queue.append(node.right)
            else:
                # To represent the structure correctly, we can add None for null nodes
                # but for simplicity, we'll just show the values.
                pass
        if current_level:
             result.append(current_level)
    print(result)


# Test cases
if __name__ == "__main__":
    # --- Test Case 1: A standard tree ---
    # Original Tree:
    #        4
    #       / \
    #      2   7
    #     / \ / \
    #    1  3 6  9
    #
    # Inverted Tree:
    #        4
    #       / \
    #      7   2
    #     / \ / \
    #    9  6 3  1
    root1 = TreeNode(4)
    root1.left = TreeNode(2, TreeNode(1), TreeNode(3))
    root1.right = TreeNode(7, TreeNode(6), TreeNode(9))
    print("--- Test Case 1: Standard Tree ---")
    print("Original Tree:")
    print_level_order(root1)
    
    inverted_root1 = invert_tree(root1)
    print("Inverted Tree:")
    print("Expected: [[4], [7, 2], [9, 6, 3, 1]]")
    print("Got:      ", end="")
    print_level_order(inverted_root1)
    print()

    # --- Test Case 2: A smaller tree ---
    # Original Tree:
    #      2
    #     / \
    #    1   3
    #
    # Inverted Tree:
    #      2
    #     / \
    #    3   1
    root2 = TreeNode(2, TreeNode(1), TreeNode(3))
    print("--- Test Case 2: Small Tree ---")
    print("Original Tree:")
    print_level_order(root2)
    
    inverted_root2 = invert_tree(root2)
    print("Inverted Tree:")
    print("Expected: [[2], [3, 1]]")
    print("Got:      ", end="")
    print_level_order(inverted_root2)
    print()

    # --- Test Case 3: Empty Tree ---
    root3 = None
    print("--- Test Case 3: Empty Tree ---")
    print("Original Tree:")
    print_level_order(root3)
    
    inverted_root3 = invert_tree(root3)
    print("Inverted Tree:")
    print("Expected: []")
    print("Got:      ", end="")
    print_level_order(inverted_root3)
    print()
    
    # --- Test Case 4: Right-skewed tree ---
    # Original Tree:
    #    1
    #     \
    #      2
    #       \
    #        3
    #
    # Inverted Tree (becomes left-skewed):
    #      1
    #     /
    #    2
    #   /
    #  3
    root4 = TreeNode(1, None, TreeNode(2, None, TreeNode(3)))
    print("--- Test Case 4: Skewed Tree ---")
    print("Original Tree:")
    print_level_order(root4)
    
    inverted_root4 = invert_tree(root4)
    print("Inverted Tree:")
    print("Expected: [[1], [2], [3]]")
    print("Got:      ", end="")
    print_level_order(inverted_root4)
    print()
