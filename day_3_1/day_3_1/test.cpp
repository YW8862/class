#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//Leetcode 122

//贪心算法
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int size = prices.size();
        if (size == 1 || size == 0)
            return 0;
        for (int i = 1; i < size; i++) {
            int k = prices[i] - prices[i - 1];
            if (k > 0)
                profit += k;
        }
        return profit;
    }
};

//Leetcode 55
//动态规划
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        int max_pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > max_pos)
                return false;
            max_pos = max(max_pos, i + nums[i]);
            if (max_pos >= nums.size() - 1)
                return true;
        }
        return false;
    }
};

//
//int main()
//{
//    //vector<int>prices = { 7,1,5,3,6,4 };
//    //cout<<Solution1().maxProfit(prices) << endl;
//    vector<int>nums = { 3,2,1,0,4 };
//    cout << Solution2().canJump(nums) << endl;
//    return 0;
//}

void test(string &s){
    cout << s.front() << endl;
    cout << s.back() << endl;
    try{
        s.at(15);

     }
    catch (const exception& e){
        cout << e.what() << endl;
    }
}

void test2(string& s){
    s.push_back('h');
    cout << s << endl;
    string s1 = "  apple   ";
    //s.append(s1);
    //s.append("haha");
    //cout << s << endl;


    s.append(10, 'x');
    s.append(s1.begin() + 2, s1.end() - 3);
    s += " apple";
    cout << s << endl;
}

void test3(string& s) {
    int pos = s.find(' ');
    while (pos!=string::npos){
        s.replace(pos,1, "%20");
        pos = s.find(' ');
    }
    cout << s << endl;
}

//int main()
//{
//    string s = "hello world!!!";
//    //cout << s.capacity() << endl;
//    //cout << s.size() << endl;
//    //cout << s << endl;
//    //s.clear();
//    //cout << s.capacity() << endl;
//    //cout << s.size() << endl;
//    //s.shrink_to_fit();
//    //cout << s << endl;
//    //cout << s.capacity() << endl;
//    //cout << s.size() << endl;
//    //cout << s << endl;
//
//    //s.reserve(100);
//    //cout << s.capacity() << endl;
//    //cout << s.size() << endl;
//    //cout << s << endl;
//    //test(s);
//    test2(s);
//    return 0;
//}

int main()
{
    string s = "hello world";
    test3(s);
    return 0;
}

//int main(int argc, char* argv[])
//{
//    string a = "hello world";
//    string b = a;
//    if (a.c_str() == b.c_str()){
//        cout << "true" << endl;
//    }
//    else cout << "false" << endl;
//    string c = b;
//    c = "";
//    if (a.c_str() == b.c_str()){
//        cout << "true" << endl;
//    }
//    else cout << "false" << endl;
//    a = "";
//    if (a.c_str() == b.c_str()){
//        cout << "true" << endl;
//    }
//    else cout << "false" << endl;
//    return 0;
//}