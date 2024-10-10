#include <iostream>
#include <vector>
#include <algorithm>
using  namespace std;

template<class T>
class TreeNode{
public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(T x):val(x),left(nullptr),right(nullptr){}
    TreeNode(T x,TreeNode*left,TreeNode*right):val(x),left(left),right(right){}
};

template<class T>
class Tree{
public:
    TreeNode<T>*root;
    void _preorder(TreeNode<T> *root){
        if(root==nullptr)return;
        cout<<root->val<<" ";
        _preorder(root->left);
        _preorder(root->right);
    }
    void _inorder(TreeNode<T> *root){
        if(root==nullptr)return;
        _inorder(root->left);
        cout<<root->val<<" ";
        _inorder(root->right);
    }
    void _postorder(TreeNode<T> *root){
        if(root==nullptr)return;
        _postorder(root->left);
        _postorder(root->right);
        cout<<root->val<<" ";
    }
    TreeNode<T>* _init(vector<T> list,int pos){
        if(pos>=list.size()||list[pos]==INT_MIN)return nullptr;
        TreeNode<T> *node = new TreeNode<T>(list[pos]);
        node->left = _init(list,2*pos+1);
        node->right = _init(list,2*pos+2);
        return node;
    }
public:
    Tree(initializer_list<T> list){
        root = _init(list,0);
    }


    void preorder(){
        _preorder(root);
    }

    void inorder(){
        _inorder(root);
    }
    void postorder(){
        _postorder(root);
    }
};

////Leetcode 11
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        size_t size = height.size();
//        int left=0,right=size-1;
//        //创建数组存放最大面积。
//        vector<int>area;
//        while(left<right){
//            int Area = min(height[left],height[right])*(right-left);
//            area.push_back(Area);
//            if(height[left] < height[right])
//                left++;
//            else if(height[left] > height[right])
//                right--;
//            else{
//                if(height[left+1]>height[right-1])
//                    right--;
//                else
//                    left++;
//            }
//        }
//        int max_area = area[0];
//        for(auto e:area)
//            if(e>max_area)
//                max_area = e;
//        return max_area;
//    }
//};
//bool find(vector<int>price,int start,int dif){
//    int i=start,j=price.size()-1;
//    while(i<=j){
//        int mid = (i+j)/2;
//        if(price[mid]>dif) j--;
//        else if(price[mid]<dif) i++;
//        else return true;
//    }
//    return false;
//}
//int main() {
//    vector<int>height={1,2,3,4,5,6,7,8};
//    cout<<find(height,3,8)<<endl;
//    //cout<<Solution().maxArea(height)<<endl;
//    return 0;
//}

//class Solution {
//public:
//    double myPow(double x, int n) {
//        if(x==0)return 0;
//        if(n==0)return 1;
//        if(n>0)
//            return x*myPow(x,n-1);
//        else
//            return 1.0/x*myPow(x,n+1);
//    }
//};


//Leetcode 2331
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    bool evaluateTree(TreeNode* root) {
//        if(root->left==nullptr&&root->right==nullptr&&root->val)return true;
//        if(root->left==nullptr&&root->right==nullptr&&root->val==0)return false;
//        if(root->val == 2)return evaluateTree(root->left)||evaluateTree(root->right);
//        return evaluateTree(root->left)&&evaluateTree(root->right);
//    }
//};
//
//int main(){
//    cout<<Solution().myPow(2.1,3);
//    return 0;
//
//}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Leetcode 129
//class Solution {
//public:
//    int sumNumbers(TreeNode* root) {
//        if(root==nullptr)return 0;
//        if(root->left==nullptr&&root->right==nullptr)return root->val;
//        return pre(root->left,root->val)+pre(root->right,root->val);
//    }
//    int pre(TreeNode* root,int preval){
//        if(root == nullptr)return preval;
//        int curval = 0;
//        if(root->left==nullptr&&root->right==nullptr){
//            curval = 10*preval+root->val;
//            return curval;
//        }
//        curval = 10*preval+root->val;
//        return pre(root->left,curval)+pre(root->right,curval);
//    }
//};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

////Leetcode 98
//class Solution {
//public:
//    bool isValidBST(TreeNode* root) {
//        if(root->left==nullptr&&root->right==nullptr)return true;
//        return isValid(root,LONG_LONG_MIN,LONG_LONG_MAX);
//    }
//    bool isValid(TreeNode*root,long long min,long long max){
//        if(root==nullptr)return true;
//        return root->val>min
//               &&root->val<max
//               &&isValid(root->left,min,root->val)
//               &&isValid(root->right,root->val,max);
//    }
//};


//int main(){
//    Tree<int> t = {0,1,2,3,4,5,6};
//    t.inorder();
//}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Leetcode230
//template<class T>
//class Solution {
//private:
//    int pos;
//    int ret;
//public:
//    Solution(){
//        pos = 0;
//        ret = 0;
//    }
//
//    int kthSmallest(TreeNode<T>* root, int k) {
//        order(root,k);
//        return ret;
//    }
//    void order(TreeNode<T>*root,int k){
//        if(root==nullptr)return;
//        order(root->left,k);
//        pos++;
//        if(pos == k)
//            ret = root->val;
//        order(root->right,k);
//    }
//};

////Leetcode257
//
//class Solution {
//public:
//    vector<string>ret;
//    vector<string> binaryTreePaths(TreeNode<int>* root) {
//        if(root==nullptr)
//            return ret;
//        string s = to_string(root->val);
//        if(root->left == nullptr && root->right == nullptr){
//            ret.push_back(s);
//            return ret;
//        }
//        order(root->left,s);
//        order(root->right,s);
//        return ret;
//    }
//    void order(TreeNode<int>*root,string s){
//        if(root==nullptr){
//            return;
//        }
//        s+="->";
//        s+=to_string(root->val);
//        order(root->left,s);
//        order(root->right,s);
//        if(root->left==nullptr && root->right==nullptr){
//            ret.push_back(s);
//            return;
//        }
//    }
//
//};
//int main(){
//    Tree<int>t = {1};
//    vector<string>ret = Solution().binaryTreePaths(t.root);
//    for(auto e:ret){
//        cout<<e<<endl;
//    }
//    return 0;
//}

////Leetcode 46
//class Solution {
//public:
//    vector<vector<int>>ret;
//    vector<vector<int>> permute(vector<int>& nums) {
//        vector<int>v;
//        vector<bool>check(nums.size(),false);
//        backtracking(nums,v,check);
//        return ret;
//    }
//    void backtracking(vector<int>nums,vector<int>v,vector<bool>check){
//        if(v.size() == nums.size()){
//            ret.push_back(v);
//            return;
//        }
//        for(int i=0;i<nums.size();i++){
//            if(check[i] == false){
//                //如果数字没有使用过，将数字放进数组中
//                v.push_back(nums[i]);
//                check[i] = true;
//                backtracking(nums,v,check);
//                //回退
//                v.pop_back();
//                check[i] = false;
//            }
//        }
//
//    }
//};

////Leetcode 78
//class Solution {
//public:
//    vector<vector<int>>ret;
//    vector<vector<int>> subsets(vector<int>& nums) {
//        vector<int>v;
//        ret.push_back(v);
//        bachtracking(nums,v,0);
//        return ret;
//    }
//    void bachtracking(vector<int>nums,vector<int>v,int i){
//        if(i == nums.size()){
//            return;
//        }
//        for(int index = i;index<nums.size();index++){
//            v.push_back(nums[index]);
//            ret.push_back(v);
//            bachtracking(nums,v,index+1);
//            v.pop_back();
//        }
//    }
//};

int main(){

    return 0;
}
111111111