#include <vector>
class TreeNode {
  public:
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
  ~TreeNode() {
    delete left;
    delete right;
  }

  void mid_traverse(std::vector<int>& result) {
    if (left != nullptr) {
      left->mid_traverse(result);
    }
    result.push_back(val);
    if (right != nullptr) {
      right->mid_traverse(result);
    }
  }

  void pre_traverse(std::vector<int>& result) {
    result.push_back(val);
    if (left != nullptr) {
      left->pre_traverse(result);
    }
    if (right != nullptr) {
      right->pre_traverse(result);
    }
  }

  void post_traverse(std::vector<int>& result) {
    if (left != nullptr) {
      left->post_traverse(result);
    }
    if (right != nullptr) {
      right->post_traverse(result);
    }
    result.push_back(val);
  }
};

