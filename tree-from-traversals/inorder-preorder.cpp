#include <cassert>
#include <iostream>
#include <map>
#include <ostream>
#include <vector>

using namespace std;

class TreeNode {
 public:
   int val;
   TreeNode *left;
   TreeNode *right;

   TreeNode() : val(0), left(nullptr), right(nullptr){};

   TreeNode(int val) : val(val), left(nullptr), right(nullptr){};

   TreeNode(int val, TreeNode *left, TreeNode *right)
       : val(val), left(left), right(right){};
};

class Solution {
 private:
   map<int, int> indexInorder;
   int n;
   vector<int> preOrder, inOrder;

 public:
   void printInOrder(TreeNode *root) {
      if (root == nullptr)
         return;
      printInOrder(root->left);
      std::cout << root->val << ' ';
      printInOrder(root->right);
   }

   void printPreOrder(TreeNode *root) {
      if (root == nullptr)
         return;
      std::cout << root->val << ' ';
      printPreOrder(root->left);
      printPreOrder(root->right);
   }

   void printPostOrder(TreeNode *root) {
      if (root == nullptr)
         return;
      printPostOrder(root->left);
      printPostOrder(root->right);
      std::cout << root->val << ' ';
   }

   TreeNode *getSubTree(int inLeft, int inRight, int &preOrderIndex) {
      // Note:  preOrderIndex is passed by reference
      if (inLeft > inRight) {
         return nullptr;
      }

      int value = preOrder[preOrderIndex];
      ++preOrderIndex;

      TreeNode *root = new TreeNode(value);

      if (inLeft == inRight) {
         return root;
      }

      int inOrderIndex = indexInorder[value];

      root->left = getSubTree(inLeft, inOrderIndex - 1, preOrderIndex);
      root->right = getSubTree(inOrderIndex + 1, inRight, preOrderIndex);

      return root;
   }

   TreeNode *getTree(vector<int> &preOrder, vector<int> &inOrder) {
      n = preOrder.size();
      assert(n == inOrder.size()); // size of inorder and preorder must be same
      this->preOrder = preOrder;
      this->inOrder = inOrder;

      for (int i = 0; i < n; ++i) {
         indexInorder[inOrder[i]] = i;
      }

      int currentIndex = 0;

      return getSubTree(0, n - 1, currentIndex);
   }
};

int main(int argc, char *argv[]) {

   int n;
   std::cin >> n;

   vector<int> preOrder(n), inOrder(n);
   std::cout << "Enter Preorder\n";
   for (int i = 0; i < n; ++i) {
      std::cin >> preOrder[i];
   }

   std::cout << "Enter Inorder\n";
   for (int i = 0; i < n; ++i) {
      std::cin >> inOrder[i];
   }

   Solution solution;
   TreeNode *root = solution.getTree(preOrder, inOrder);

   solution.printInOrder(root);
   std::cout << '\n';
   solution.printPreOrder(root);
   std::cout << '\n';
   solution.printPostOrder(root);
   std::cout << '\n';

   return 0;
}
