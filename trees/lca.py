"""
Lowest Common Ancestor of a Binary Tree

The lowest common ancestor (LCA) between two nodes p and q in a binary tree is
defined as the lowest node that has both p and q as descendants (where we allow
a node to be a descendant of itself).

The algorithm uses a recursive Depth First Search (DFS) approach. The core idea
is to traverse the tree starting from the root. For any given node, we check if
it's one of the target nodes (p or q). If it is, we return that node. Otherwise,
we recursively search in its left and right subtrees.

- If the recursive calls to both the left and right subtrees return non-null nodes,
  it means p and q were found in different subtrees. Therefore, the current node
  is their lowest common ancestor.
- If only one of the calls (e.g., the left one) returns a non-null node, it means
  both p and q are located in that subtree. The returned node from that call is the LCA.
- If both calls return null, neither p nor q was found in the subtrees of the current node.

Time Complexity: O(N), where N is the number of nodes in the tree, because we visit each node at most once.
Space Complexity: O(H), where H is the height of the tree, due to the recursion stack. In the worst
case of a skewed tree, this can be O(N).
"""

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


def lowest_common_ancestor(root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
    """
    Finds the lowest common ancestor of two given nodes in a binary tree.

    Args:
        root: The root node of the binary tree.
        p: The first node.
        q: The second node.

    Returns:
        The lowest common ancestor node, or None if the tree is empty.
    """
    # Base case: If the tree is empty or we find one of the nodes, return the current node.
    if not root or root == p or root == q:
        return root

    # Recurse on the left and right subtrees
    left_lca = lowest_common_ancestor(root.left, p, q)
    right_lca = lowest_common_ancestor(root.right, p, q)

    # If both left and right recursive calls return a node, it means p and q
    # are in different subtrees, so the current root is their LCA.
    if left_lca and right_lca:
        return root

    # Otherwise, the LCA must be in whichever subtree returned a non-null value.
    # If both returned null, the nodes aren't in this subtree, so we also return null.
    return left_lca or right_lca

# Test cases
if __name__ == "__main__":
    # Construct the following binary tree for testing:
    #        3
    #       / \
    #      5   1
    #     / \ / \
    #    6  2 0  8
    #      / \
    #     7   4
    root = TreeNode(3)
    root.left = TreeNode(5)
    root.right = TreeNode(1)
    root.left.left = TreeNode(6)
    root.left.right = TreeNode(2)
    root.right.left = TreeNode(0)
    root.right.right = TreeNode(8)
    root.left.right.left = TreeNode(7)
    root.left.right.right = TreeNode(4)

    # --- Test Case 1: Nodes are in different subtrees of the root ---
    p1 = root.left       # Node 5
    q1 = root.right      # Node 1
    lca1 = lowest_common_ancestor(root, p1, q1)
    print("--- Test Case 1 ---")
    print(f"Nodes: {p1.val}, {q1.val}")
    print(f"Expected LCA: 3")
    print(f"Calculated LCA: {lca1.val if lca1 else 'Not Found'}\n")

    # --- Test Case 2: One node is an ancestor of the other ---
    p2 = root.left       # Node 5
    q2 = root.left.right.right # Node 4
    lca2 = lowest_common_ancestor(root, p2, q2)
    print("--- Test Case 2 ---")
    print(f"Nodes: {p2.val}, {q2.val}")
    print(f"Expected LCA: 5")
    print(f"Calculated LCA: {lca2.val if lca2 else 'Not Found'}\n")

    # --- Test Case 3: Nodes are siblings ---
    p3 = root.left.left  # Node 6
    q3 = root.left.right # Node 2
    lca3 = lowest_common_ancestor(root, p3, q3)
    print("--- Test Case 3 ---")
    print(f"Nodes: {p3.val}, {q3.val}")
    print(f"Expected LCA: 5")
    print(f"Calculated LCA: {lca3.val if lca3 else 'Not Found'}\n")

    # --- Test Case 4: Nodes are deep in the tree and in different subtrees ---
    p4 = root.left.right.left  # Node 7
    q4 = root.right.right      # Node 8
    lca4 = lowest_common_ancestor(root, p4, q4)
    print("--- Test Case 4 ---")
    print(f"Nodes: {p4.val}, {q4.val}")
    print(f"Expected LCA: 3")
    print(f"Calculated LCA: {lca4.val if lca4 else 'Not Found'}\n")

    # --- Test Case 5: Root is one of the nodes ---
    p5 = root            # Node 3
    q5 = root.left.right # Node 2
    lca5 = lowest_common_ancestor(root, p5, q5)
    print("--- Test Case 5 ---")
    print(f"Nodes: {p5.val}, {q5.val}")
    print(f"Expected LCA: 3")
    print(f"Calculated LCA: {lca5.val if lca5 else 'Not Found'}\n")
