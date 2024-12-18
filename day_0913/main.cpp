#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <set>

using  namespace std;

//单链表定义
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//模板树节点定义
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


//#include <iostream>
//#include <string>
//using namespace std;
//std::string solution(std::string binary1, std::string binary2) {
//    // Please write your code here
//    int weight = 1;
//    int num1 = 0;
//    int num2 = 0;
//    while(!binary1.empty()){
//        num1 += (binary1[binary1.length()-1]-48)*weight;
//        binary1.pop_back();
//        weight *= 2;
//    }
//    weight = 1;
//    while(!binary2.empty()){
//        num2 += (binary2.at(binary2.length()-1)-'0')*weight;
//        binary2.pop_back();
//        weight *= 2;
//    }
//    return to_string(num1+num2);
//}
//int main(){
//    cout<<solution("110","101")<<endl;
//    return 0;
//}

//Leetcode1863
//class Solution {
//public:
//    vector<vector<int>>ret;
//    int sum;
//    int subsetXORSum(vector<int>& nums) {
//        sum = 0;
//
//        vector<int>v;
//        bachtracking(nums,v,0);
//        return sum;
//    }
//
//    void bachtracking(vector<int>nums,vector<int>v,int i){
//        if(i == nums.size()){
//            return;
//        }
//        for(int index = i;index<nums.size();index++){
//            v.push_back(nums[index]);
//            int tmp = 1;
//            for(auto e:v){
//                tmp = tmp^e;
//            }
//            sum += tmp;
//            bachtracking(nums,v,index+1);
//            v.pop_back();
//        }
//}
//};
//int main(){
//    vector<int>nums = {1,3};
//    cout<<Solution().subsetXORSum(nums);
//    return 0;
//}

////求字符串配比权重
//double getvalue(std::string s){
//    double weight = 0.1;
//    double value = 0.0;
//    for(auto e:s){
//        value += weight*e;
//        weight = weight+0.1;
//    }
//    return value;
//}
//std::string solution(std::string dna_sequence) {
//    // Please write your code here
//    //旋转字符串，按照权重求值
//    string ret = dna_sequence;
//    string restr = dna_sequence;
//    double minvalue = getvalue(dna_sequence);
//    for(int i=0;i<dna_sequence.size();i++){
//        auto e = dna_sequence.at(dna_sequence.size()-1);
//        dna_sequence.pop_back();
//        dna_sequence = e + dna_sequence;
//        double curval = getvalue(dna_sequence);
//        if(curval < minvalue){
//            ret = dna_sequence;
//            minvalue = curval;
//        }
//    }
//    return ret;
//}
//
//
//int main() {
//    // You can add more test cases here
//    std::cout << solution("ATCA") << std::endl;
//    std::cout << solution("CGAGTC") << std::endl;
//    std::cout << solution("TCATGGAGTGCTCCTGGAGGCTGAGTCCATCTCCAGTAG") << std::endl;
//    return 0;
//}

//class MyQueue {
//public:
//    MyQueue()
//    {
//
//    }
//
//    void push(int x)
//    {
//        s1.push(x);
//    }
//
//    int pop()
//    {
//        //存放返回数据
//        int ret = 0;
//        //存放临时搬运数据
//        int tmp = 0;
//        //将s1的数据放到s2中
//        while(!s1.empty())
//        {
//            tmp = s1.top();
//            s1.pop();
//            s2.push(tmp);
//        }
//        if(!s2.empty())
//        {
//            ret = s2.top();
//            s2.pop();
//        }
//        while(!s2.empty())
//        {
//            tmp = s2.top();
//            s2.pop();
//            s1.push(tmp);
//        }
//        return ret;
//    }
//
//    int peek()
//    {
//        //存放返回数据
//        int ret = 0;
//        //存放临时搬运数据
//        int tmp = 0;
//        //将s1的数据放到s2中
//        while(!s1.empty())
//        {
//            tmp = s1.top();
//            s1.pop();
//            s2.push(tmp);
//        }
//        if(!s2.empty())
//        {
//            ret = s2.top();
//        }
//        while(!s2.empty())
//        {
//            tmp = s2.top();
//            s2.pop();
//            s1.push(tmp);
//        }
//        return ret;
//    }
//
//    bool empty()
//    {
//        return s1.empty();
//    }
//private:
//    stack<int>s1;
//    stack<int>s2;
//};
//
///**
// * Your MyQueue object will be instantiated and called as such:
// * MyQueue* obj = new MyQueue();
// * obj->push(x);
// * int param_2 = obj->pop();
// * int param_3 = obj->peek();
// * bool param_4 = obj->empty();
// */
//
//int main()
//{
//    MyQueue obj;
//    obj.push(1);
//    obj.push(2);
//    cout<<obj.peek()<<endl;
//    cout<<obj.pop()<<endl;
//    cout<<obj.empty()<<endl;
//    return 0;
//}

////newcodeBM44
////堆栈法
//class Solution
//{
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param s string字符串
//     * @return bool布尔型
//     */
//    bool isValid(string s)
//    {
//        stack<char>st;
//        char topvalue = '\0';
//        for(auto e:s)
//        {
//            if(e == '(' || e == '[' || e == '{')
//            {
//                st.push(e);
//            }
//            else
//            {
//                if(st.empty())
//                    return false;
//                topvalue = st.top();
//                st.pop();
//                switch(e)
//                {
//                    case ')':
//                        if (topvalue != '(')
//                            return false;
//                        break;
//                    case ']':
//                        if (topvalue != '[')
//                            return false;
//                        break;
//                    case '}':
//                        if (topvalue != '{')
//                            return false;
//                        break;
//                    default:
//                        break;
//                }
//            }
//
//        }
//        if(!st.empty())
//            return false;
//        return true;
//    }
//};


//* Definition for singly-linked list.

////使用栈完成
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        if(head == nullptr ||head->next == nullptr)
//            return true;
//        stack<int>st;
//        int num = 0,curnum = 1;
//        ListNode*cur = head;
//        int topvalue = 0;
//        while(cur){
//            num++;
//            cur = cur->next;
//        }
//        cur = head;
//        while(cur){
//            if(num%2 && curnum == num/2 + 1){
//                curnum++;
//                cur = cur->next;
//                continue;
//            }
//            else if(curnum > num/2){
//                if(st.empty())
//                    return false;
//                topvalue = st.top();
//                st.pop();
//                if(topvalue != cur->val)
//                    return false;
//            }else{
//                st.push(cur->val);
//            }
//            curnum++;
//            cur = cur->next;
//        }
//        if(st.empty())
//            return true;
//        return false;
//    }
//};

////反拷比对
//class Solution {
//public:
//    bool isPalindrome(ListNode* head) {
//        if(head ==nullptr || head->next == nullptr)
//            return true;
//        forward_list<int>li;
//        ListNode* cur = head;
//        while(cur){
//            li.push_front(cur->val);
//            cur = cur -> next;
//        }
//        cur = head;
//        for(auto e:li)
//        {
//            if(e != cur->val)
//                return false;
//            cur = cur->next;
//        }
//        return true;
//    }
//};
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

////排序复制法
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param lists ListNode类vector
//     * @return ListNode类
//     */
//
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // write code here
//        ListNode* newhead = new ListNode(0);
//        ListNode* p = newhead;
//        multiset<int>ms;
//        for(auto e:lists){
//            ListNode *cur = e;
//            while(cur){
//                ms.insert(cur->val);
//                cur = cur->next;
//            }
//        }
//        for(auto e:ms){
//            ListNode *node = new ListNode(e);
//            node->val = e;
//            p->next = node;
//            p = p->next;
//        }
//        return newhead->next;
//    }
//};

////分治、归并法
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param lists ListNode类vector
//     * @return ListNode类
//     */
//     ListNode* merge(ListNode*list1,ListNode*list2){
//        ListNode* rethead = new ListNode(0);
//        ListNode* opret = rethead;
//        ListNode* p1 = list1;
//        ListNode* p2 = list2;
//        while(p1 && p2){
//            if(p1->val < p2->val){
//                opret->next = p1;
//                p1 = p1->next;
//            }else{
//                opret->next = p2;
//                p2 = p2->next;
//            }
//            opret = opret->next;
//        }
//        opret->next = p1==nullptr?p2:p1;
//        return rethead->next;
//    }
//    void print(ListNode* list){
//        ListNode* cur = list;
//        while(cur){
//            cout<<cur->val<<" ";
//            cur = cur->next;
//        }
//        cout<<endl;
//    }
//    ListNode* mergeKLists(vector<ListNode*>& lists) {
//        // write code here
//        if(lists.size() == 0)
//            return nullptr;
//        if(lists.size() == 1)
//            return lists[0];
//        //return merge(lists[0],lists[1]);
//        int curnum = lists.size();
//        while(curnum != 1){
//            for(int i = 0;i<curnum/2;i++){
//                lists[i] = merge(lists[i], lists[curnum-1-i]);
//            }
//            curnum = curnum/2 + curnum%2;
//        }
//        return lists[0];
//    }
//};

////leetcode965
//class Solution {
//public:
//    bool isUnivalTree(TreeNode<int>* root) {
//        if(root==nullptr)
//            return true;
//        if(root->left&&root->right)
//            return (root->val==root->left->val)
//                   &&(root->val==root->right->val)
//                   &&isUnivalTree(root->left)
//                   &&isUnivalTree(root->right);
//        if(root->left)
//            return (root->val==root->left->val)
//                   &&isUnivalTree(root->left);
//        if(root->right)
//            return (root->val==root->right->val)
//                   &&isUnivalTree(root->right);
//        return true;
//    }
//};

void quicksort(vector<int>&nums,int left,int right){
    if(left == right || nums.size() == 0)
        return;
    int pl = left,pr = right,stdnum = nums[left],stdpos = pl;
    while(pl < pr){
        if(nums[pr] < stdnum) {
            stdpos = pr;
            swap(nums[pl], nums[pr]);
            pl++;
        }else if(nums[pl] > stdnum){
            stdpos = pl;
            swap(nums[pl],nums[pr]);
            pr--;
        }
    }
}

int main(){

    return 0;
}