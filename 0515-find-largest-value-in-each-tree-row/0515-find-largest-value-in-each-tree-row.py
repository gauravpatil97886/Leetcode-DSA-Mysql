class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:

        largest_values = []

        current_level = [root]

        while any(current_level):

            largest_values.append(max(node.val for node in current_level))
            next_level = [child for node in current_level for child in (node.left, node.right) if child]
            current_level = next_level

        return largest_values
