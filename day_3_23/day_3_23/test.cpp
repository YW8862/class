#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


//Leetcode LCR193
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        if ((root->val > p->val && root->val < q->val) || (root->val<p->val && root->val>q->val) || root->val == p->val || root->val == q->val)
            return root;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        return nullptr;
    }
};

//Leetcode 136
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};


//Leetcode 1008
class Solution3 {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        size_t len = preorder.size();
        if (len == 0)return nullptr;
        TreeNode* root = new TreeNode(preorder[0]);

        for (int i = 1; i < len; i++) {
            TreeNode* cur = root;
            TreeNode* pra = root;
            while (cur) {
                if (cur->val > preorder[i]) {
                    pra = cur;
                    cur = cur->left;
                }
                else if (cur->val < preorder[i]) {
                    pra = cur;
                    cur = cur->right;
                }
            }
            cur = new TreeNode(preorder[i]);
            if (pra->val < cur->val)
                pra->right = cur;
            else
                pra->left = cur;
        }
        return root;
    }
};


