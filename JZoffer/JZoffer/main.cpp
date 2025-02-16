#include <vector>
#include <string>
#include <iostream>

using namespace std;


//JZ3
//class Solution
//{
//public:
//    int duplicate(vector<int>& numbers)
//    {
//        vector<int>nums(numbers.size(), 0);
//        for (auto num : numbers)
//        {
//            if (nums[num]++ > 0)
//                return num;
//        }
//        return -1;
//    }
//};


//JZ5
//class Solution {
//public:
//    string replaceSpace(string s)
//    {
//        size_t pos = 0;
//        while (true)
//        {
//            pos = s.find(' ', pos);
//            if (pos == string::npos)
//                break;
//            s.erase(pos, 1);
//            s.insert(pos, "%20");
//        }
//        return s;
//    }
//};
//
//int main()
//{
//    cout << Solution().replaceSpace("We Are Happy") << endl;
//    return 0;
//}


//JZ6
//class Solution {
//public:
//    vector<int> printListFromTailToHead(ListNode* head) {
//        vector<int>ret;
//        ListNode* p = head;
//        while (p)
//        {
//            ret.push_back(p->val);
//            p = p->next;
//        }
//        reverse(ret.begin(), ret.end());
//        return ret;
//    }
//};

