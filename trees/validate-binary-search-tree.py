"""
Validate Binary Search Tree (BST)

This algorithm determines if a given binary tree is a valid Binary Search Tree.
A Binary Search Tree has the following properties:
- The left subtree of a node contains only nodes with values less than the node's value.
- The right subtree of a node contains only nodes with values greater than the node's value.
- Both the left and right subtrees must also be binary search trees.

A common pitfall is to only check if `node.left.val < node.val` and
`node.right.val > node.val`. This is not sufficient, as it doesn't ensure that all
nodes in the left subtree are smaller or all nodes in the right subtree are larger.
For example, a node deep in the left subtree must still be greater than the root's
grandparent if it's in the grandparent's right subtree.

The correct approach is to use a recursive Depth First Search (DFS) and verify
that each node's value falls within a valid range [min_val, max_val].
- When we traverse to a left child, the child's value must be less than its
  parent's value. So, the parent's value becomes the new `max_val` for the left subtree.
- When we traverse to a right child, the child's value must be greater than its
  parent's value. So, the parent's value becomes the new `min_val` for the right subtree.

Time Complexity: O(N), where N is the number of nodes in the tree, as we visit each node once.
Space Complexity: O(H), where H is the height of the tree, for the recursion stack.
In the worst case (a skewed tree), this can be O(N).
"""

from typing import Optional

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


def is_valid_bst(root: Optional[TreeNode]) -> bool:
    """
    Checks if a binary tree is a valid Binary Search Tree.

    Args:
        root: The root node of the binary tree.

    Returns:
        True if the tree is a valid BST, False otherwise.
    """
    # Helper function to perform the validation with a min/max range.
    # We initialize the range with negative and positive infinity.
    def validate(node, low=-float('inf'), high=float('inf')):
        # An empty tree or a null leaf is considered a valid BST.
        if not node:
            return True

        # The current node's value must be within the valid range.
        if not (low < node.val < high):
            return False

        # Recursively validate the left and right subtrees, updating the range.
        # For the left child, the new upper bound is the current node's value.
        # For the right child, the new lower bound is the current node's value.
        return (validate(node.left, low, node.val) and
                validate(node.right, node.val, high))

    return validate(root)

# Test cases
if __name__ == "__main__":
    # --- Test Case 1: A valid BST ---
    #        5
    #       / \
    #      3   7
    #     / \ / \
    #    2  4 6  8
    root1 = TreeNode(5)
    root1.left = TreeNode(3, TreeNode(2), TreeNode(4))
    root1.right = TreeNode(7, TreeNode(6), TreeNode(8))
    print("--- Test Case 1: Valid BST ---")
    print(f"Is valid BST? Expected: True, Got: {is_valid_bst(root1)}\n")

    # --- Test Case 2: An invalid BST ---
    # The node with value 6 is in the left subtree of the root (5), which is invalid.
    #        5
    #       / \
    #      1   6
    #         / \
    #        3   7
    root2 = TreeNode(5)
    root2.left = TreeNode(1)
    root2.right = TreeNode(6, TreeNode(3), TreeNode(7))
    print("--- Test Case 2: Invalid BST (Right subtree violation) ---")
    print(f"Is valid BST? Expected: False, Got: {is_valid_bst(root2)}\n")

    # --- Test Case 3: A simple valid BST ---
    #      2
    #     / \
    #    1   3
    root3 = TreeNode(2, TreeNode(1), TreeNode(3))
    print("--- Test Case 3: Simple Valid BST ---")
    print(f"Is valid BST? Expected: True, Got: {is_valid_bst(root3)}\n")

    # --- Test Case 4: Invalid because of equality ---
    # A BST does not allow duplicate values.
    #      2
    #     / \
    #    2   2
    root4 = TreeNode(2, TreeNode(2), TreeNode(2))
    print("--- Test Case 4: Invalid due to duplicate values ---")
    print(f"Is valid BST? Expected: False, Got: {is_valid_bst(root4)}\n")

    # --- Test Case 5: Empty Tree ---
    root5 = None
    print("--- Test Case 5: Empty Tree ---")
    print(f"Is valid BST? Expected: True, Got: {is_valid_bst(root5)}\n")

    # --- Test Case 6: Single Node Tree ---
    root6 = TreeNode(10)
    print("--- Test Case 6: Single Node Tree ---")
    print(f"Is valid BST? Expected: True, Got: {is_valid_bst(root6)}\n")
    
    # --- Test Case 7: Another invalid BST ---
    # The node with value 20 is greater than the root (10), but its child 8 is not.
    #        10
    #       /  \
    #      5   20
    #         /  \
    #        8    25
    root7 = TreeNode(10)
    root7.left = TreeNode(5)
    root7.right = TreeNode(20, TreeNode(8), TreeNode(25))
    print("--- Test Case 7: Invalid BST (Deeper violation) ---")
    print(f"Is valid BST? Expected: False, Got: {is_valid_bst(root7)}\n")
