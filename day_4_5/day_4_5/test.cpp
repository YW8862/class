
//牛客OR62
//#include <iostream>
//#include<vector>
//#include<algorithm>
//#include <string>
//using namespace std;
//
//int main() {
//    string s;
//    getline(cin, s);
//    reverse(s.begin(), s.end());
//    string::iterator start = s.begin();
//    string::iterator end = s.end();
//    while (start != end) {
//        string::iterator it = start;
//        while (it != end && *it != ' ')
//            it++;
//        reverse(start, it);
//        if (it == end)
//            break;
//        else
//            start = ++it;
//    }
//    cout << s;
//
//    return 0;
//}



////OR59
//#include <iostream>
//#include <valarray>
//#include<vector>
//#include<string>
//using namespace std;
//
//int main() {
//    string s;
//    cin >> s;
//    string ret;
//    string cur;
//    string::iterator it = s.begin();
//    while (it != s.end()) {
//        if (isdigit(*it))
//            cur += *it;
//        else {
//            if (cur.size() > ret.size()) {
//                ret = cur;
//            }
//            cur.clear();
//        }
//        it++;
//    }
//    if (cur.size() > ret.size()) {
//        ret = cur;
//        cur.clear();
//    }
//    cout << ret << endl;
//    return 0;
//}



////JZ39
//class Solution {
//public:
//    /**
//     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//     *
//     *
//     * @param numbers int整型vector
//     * @return int整型
//     */
//    int MoreThanHalfNum_Solution(vector<int>& numbers) {
//        // write code here
//        if (numbers.size() == 1)return numbers[0];
//        int res = numbers[0];
//        int count = 0;
//        for (auto e : numbers) {
//            if (count == 0) {
//                res = e;
//                count++;
//            }
//            else if (e == res)
//                count++;
//            else {
//                count--;
//            }
//        }
//        return res;
//    }
//};


////WY23
//#include <iostream>
//using namespace std;
//
//int main() {
//    int A, B, C;
//    int a, b, c, d;
//    cin >> a >> b >> c >> d;
//    if ((a + c) % 2) {
//        cout << "No" << endl;
//        return 0;
//    }
//    A = (a + c) / 2;
//    if (c - A < 0) {
//        cout << "No" << endl;
//        return 0;
//    }
//    B = c - A;
//    if (d - B < 0) {
//        cout << "No" << endl;
//        return 0;
//    }
//    C = d - B;
//    cout << A << " " << B << " " << C << endl;
//}


