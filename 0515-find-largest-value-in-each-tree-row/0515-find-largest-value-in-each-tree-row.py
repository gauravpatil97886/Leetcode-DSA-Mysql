from typing import List
import collections
import math
from queue import SimpleQueue

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        if not root:
            return []

        ans = []
        q = collections.deque([root])

        while q:
            max_val = -math.inf
            for _ in range(len(q)):
                node = q.popleft()
                max_val = max(max_val, node.val)
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            ans.append(max_val)

        return ans
