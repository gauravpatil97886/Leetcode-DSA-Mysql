class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        row_max = []
        stack = [(root, 0)]
        while stack:
            curr, row = stack.pop()
            if row > len(row_max) - 1:
                row_max.append(curr.val)
            else:
                row_max[row] = max(row_max[row], curr.val)
            for child in [curr.left, curr.right]:
                if not child:
                    continue
                stack.append((child, row + 1))
        return row_max