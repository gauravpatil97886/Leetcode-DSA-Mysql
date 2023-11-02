class Solution {
 public:
  int averageOfSubtree(TreeNode* root) {
    int a = 0;
    dfs(root, a);
    return a;
  }

 private:
  pair<int, int> dfs(TreeNode* b, int& c) {
    if (b == nullptr)
      return {0, 0};
    const auto [d, e] = dfs(b->left, c);
    const auto [f, g] = dfs(b->right, c);
    const int h = b->val + d + f;
    const int i = 1 + e + g;
    if (h / i == b->val)
      ++c;
    return {h, i};
  }
};
