"""
Diameter of a Binary Tree

The diameter of a binary tree is the length of the longest path between any two nodes
in a tree. This path may or may not pass through the root. The length of a path
between two nodes is represented by the number of edges between them.

The algorithm uses a Depth First Search (DFS) approach. For each node, it calculates:
1. The height of the left subtree.
2. The height of the right subtree.

The potential diameter passing through the current node is the sum of the heights of its
left and right subtrees. The overall diameter of the tree is the maximum of these
potential diameters calculated for every node.

To do this efficiently, we use a post-order traversal. A helper function calculates
the height of a subtree rooted at a given node. While calculating the height, it also
updates a non-local variable that tracks the maximum diameter found so far.

Time Complexity: O(N), where N is the number of nodes in the tree, as we visit each node exactly once.
Space Complexity: O(H), where H is the height of the tree. This is for the recursion stack.
In the worst-case scenario (a skewed tree), H can be N, so the space complexity becomes O(N).
For a balanced tree, it's O(log N).
"""

class TreeNode:
    """
    A class to represent a node in a binary tree.
    """
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def diameter_of_binary_tree(root: TreeNode) -> int:
    """
    Calculates the diameter of a binary tree.

    The main function initializes a variable to store the diameter and calls the
    recursive helper function.

    Args:
        root: The root node of the binary tree.

    Returns:
        int: The diameter (number of edges in the longest path) of the tree.
    """
    # We use a list to pass the diameter by reference, as integers are immutable in Python.
    # diameter[0] will store the maximum diameter found.
    diameter = [0]
    calculate_height(root, diameter)
    return diameter[0]

def calculate_height(node: TreeNode, diameter: list) -> int:
    """
    A helper function to recursively calculate the height of a node and update the diameter.

    This function performs a post-order traversal. For each node, it computes the
    height of its left and right subtrees. It then uses these heights to update the
    global diameter and returns the height of the subtree rooted at the current node.

    Args:
        node: The current node in the traversal.
        diameter: A list containing a single integer, used to track the maximum diameter.

    Returns:
        int: The height of the subtree rooted at the given node.
    """
    if not node:
        return 0

    # Recursively find the height of the left and right subtrees.
    left_height = calculate_height(node.left, diameter)
    right_height = calculate_height(node.right, diameter)

    # The diameter at the current node is the sum of the heights of its left and right subtrees.
    # We update the maximum diameter found so far.
    current_diameter = left_height + right_height
    diameter[0] = max(diameter[0], current_diameter)

    # The height of the current node's subtree is 1 + the height of its tallest child subtree.
    return 1 + max(left_height, right_height)

# Test cases
if __name__ == "__main__":
    # Test Case 1: Diameter passes through the root
    #       1
    #      / \
    #     2   3
    #    / \
    #   4   5
    # Longest path: 4 -> 2 -> 1 -> 3 (or 5 -> 2 -> 1 -> 3), Diameter = 3
    print("--- Test Case 1: Diameter through root ---")
    root1 = TreeNode(1)
    root1.left = TreeNode(2, TreeNode(4), TreeNode(5))
    root1.right = TreeNode(3)
    print(f"Expected Diameter: 3")
    print(f"Calculated Diameter: {diameter_of_binary_tree(root1)}\n")


    # Test Case 2: Diameter is entirely in the left subtree
    #               1
    #              /
    #             2
    #            / \
    #           3   4
    #          /     \
    #         5       6
    # Longest path: 5 -> 3 -> 2 -> 4 -> 6, Diameter = 4
    print("--- Test Case 2: Diameter in left subtree ---")
    root2 = TreeNode(1)
    root2.left = TreeNode(2)
    root2.left.left = TreeNode(3, TreeNode(5))
    root2.left.right = TreeNode(4, None, TreeNode(6))
    print(f"Expected Diameter: 4")
    print(f"Calculated Diameter: {diameter_of_binary_tree(root2)}\n")


    # Test Case 3: A right-skewed tree (like a linked list)
    #   1
    #    \
    #     2
    #      \
    #       3
    #        \
    #         4
    # Longest path: 1 -> 2 -> 3 -> 4, Diameter = 3
    print("--- Test Case 3: Right-skewed tree ---")
    root3 = TreeNode(1)
    root3.right = TreeNode(2)
    root3.right.right = TreeNode(3)
    root3.right.right.right = TreeNode(4)
    print(f"Expected Diameter: 3")
    print(f"Calculated Diameter: {diameter_of_binary_tree(root3)}\n")

    # Test Case 4: Tree with a single node
    #   42
    # Diameter = 0
    print("--- Test Case 4: Single node tree ---")
    root4 = TreeNode(42)
    print(f"Expected Diameter: 0")
    print(f"Calculated Diameter: {diameter_of_binary_tree(root4)}\n")

    # Test Case 5: Empty tree
    #   (None)
    # Diameter = 0
    print("--- Test Case 5: Empty tree ---")
    root5 = None
    print(f"Expected Diameter: 0")
    print(f"Calculated Diameter: {diameter_of_binary_tree(root5)}\n")
    
    # Test Case 6: A more complex tree
    #         1
    #        / \
    #       2   3
    #      /   / \
    #     4   5   6
    #    /     \   \
    #   7       8   9
    #  /           /
    # 10          11
    # Longest path: 10 -> 7 -> 4 -> 2 -> 1 -> 3 -> 6 -> 9 -> 11, Diameter = 8
    print("--- Test Case 6: Complex tree ---")
    root6 = TreeNode(1)
    root6.left = TreeNode(2, TreeNode(4, TreeNode(7, TreeNode(10))))
    root6.right = TreeNode(3)
    root6.right.left = TreeNode(5, None, TreeNode(8))
    root6.right.right = TreeNode(6, None, TreeNode(9, TreeNode(11)))
    print(f"Expected Diameter: 8")
    print(f"Calculated Diameter: {diameter_of_binary_tree(root6)}\n")