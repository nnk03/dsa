#include <iostream>

enum TraversalType {
   INORDER = 0,
   PREORDER,
   POSTORDER

};

class TreeNode {
 public:
   int val;
   TreeNode *left, *right;
   TreeNode() : val(0), left(nullptr), right(nullptr){};
   TreeNode(int val) : val(val), left(nullptr), right(nullptr){};
   TreeNode(int val, TreeNode *left, TreeNode *right)
       : val(val), left(left), right(right){};
};

void printTraversal(TreeNode *root, const TraversalType &traversal) {
   if (root == nullptr)
      return;

   if (traversal == PREORDER)
      std::cout << root->val << ' ';

   printTraversal(root->left, traversal);

   if (traversal == INORDER)
      std::cout << root->val << ' ';

   printTraversal(root->right, traversal);

   if (traversal == POSTORDER)
      std::cout << root->val << ' ';
}

int main(int argc, char *argv[]) {

   TreeNode *left = new TreeNode(2);
   TreeNode *right = new TreeNode(3);

   TreeNode *root = new TreeNode(1, left, right);

   printTraversal(root, INORDER);
   std::cout << '\n';

   printTraversal(root, PREORDER);
   std::cout << '\n';

   printTraversal(root, POSTORDER);
   std::cout << '\n';

   return 0;
}
