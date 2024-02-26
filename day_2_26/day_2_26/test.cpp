#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;



//Leetcode 841
class Queue
{
private:
    int* data;
    int pre ;
    int tail ;
public:
    Queue()
    {
        data = new int[1000];
        pre = 0;
        tail = 0;
    }

    ~Queue()
    {
        delete[]data;
        data = nullptr;
        pre = 0;
        tail = 0;
    }

    void Push(int x)
    {
        data[pre] = x;
        pre++;
    }

    int get_data()
    {
        return data[tail];
    }

    int Pop()
    {
        return data[tail++];
        
    }

    bool IsEmpty()
    {
        return pre == tail;
    }
};


class Solution {
public:
    void fun(vector<vector<int>>& rooms,Queue&Q,int room)
    {
        for (int i = 0; i < rooms[room].size(); i++)
        {
            if (rooms[room][i])
            {
                Q.Push(rooms[room][i]);
                rooms[room][i] = 0;
            }

        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        Queue Q;
        for (int i = 0; i < rooms[0].size(); i++)
        {
            if (rooms[0][i])
            {
                Q.Push(rooms[0][i]);
                rooms[0][i] =0;
            }
        }
        while (!Q.IsEmpty())
        {
            int room = Q.get_data();
            if (room)
            {
                fun(rooms, Q,room);
            }
            Q.Pop();
        }
        for (int i = 0; i < rooms.size(); i++)
        {
            for (int j = 0; j < rooms[i].size(); j++)
                if (rooms[i][j])
                    return false;
        }
        return true;
    }
};




void test1(string s)
{
    string::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

void test2(string s)
{
    string::reverse_iterator rit = s.rbegin();
    while (rit != s.rend())
    {
        cout << *rit << " ";
        rit++;
    }
    cout << endl;
}

//int main()
//{
//    vector<vector<int>> rooms = { {1},{2},{3},{} };
//    cout << Solution().canVisitAllRooms(rooms)<< endl;
//    return 0;
//}


//int main()
//{
//    //vector<vector<int>> rooms = { {1},{2},{3},{} };
//    //cout << Solution().canVisitAllRooms(rooms)<< endl;
//    //string s("hello world");
//    //test1(s);
//    //test2(s);
//
//    //cout << s.size() << endl;
//    //cout << s.length() << endl;
//    ////cout << s.max_size() << endl;
//    //string s;
//    //cout << s.capacity() << endl;
//    //int i = 10;
//    //size_t sz = s.capacity();
//
//    //while (i--)
//    //{
//    //    s.push_back('C');
//    //    if (sz != s.capacity())
//    //    {
//    //        sz = s.capacity();
//    //        cout << sz << endl;
//    //    }
//    //}
//    //s.clear();
//    //cout << s.capacity() << endl;
//    //s.resize(50,'#');
//    //string::iterator it = s.begin();
//    //while (it != s.end())
//    //{
//    //    cout << *it<<' ';
//    //    it++;
//    //}
//    //cout << endl;
//    //cout << s.capacity() << endl;
//    //s.reserve(200);
//    //cout << s.capacity() << endl;
//    //s.reserve(20);
//    //cout << s.capacity() << endl;
//    string s = "hello world";
//    s.append("1+1=2");
//    s += "2*2=4\n";
//
//    for (auto e : s)
//    {
//        cout << e << " ";
//    }
//    cout << endl;
//
//
//	return 0;
//}


//面试01-03
class Solution2 {
public:
    string replaceSpaces(string S, int length) {
        string s1 = S;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == ' ')
                s1.replace(i, 1, "%20");
        }
        return s1;

    }
};

class Solution3 {
public:
    string replaceSpaces(string S, int length) {
        //先计算有多少空格，就可以知道替换后的最后一个字符的位置
        string s1 = S;
        int cnt = 0;
        for (int i = 0; i < length; ++i)
        {
            if (' ' == S[i])
            {
                ++cnt;
            }
        }
        s1.resize(length);
        //扩充实际空间到最后返回的空间
        //s1.resize(length+cnt*2);
        for (int i = 0; i < length+cnt*2; i++)
        {
            if (s1[i] == ' ')
                s1.replace(i, 1, "%20");
        }

        return s1;
    }
};

class Solution4 {
public:
    string replaceSpaces(string S, int length) {
        //先计算有多少空格，就可以知道替换后的最后一个字符的位置
        int cnt = 0;
        for (int i = 0; i < length; ++i)
        {
            if (' ' == S[i])
            {
                ++cnt;
            }
        }
        S.resize(length);
        //扩充实际空间到最后返回的空间
        //s1.resize(length+cnt*2);
        for (int i = 0; i < length + cnt * 2; i++)
        {
            if (S[i] == ' ')
                S.replace(i, 1, "%20");
        }

        return S;
    }
};

class Solution5 {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size();
        while (i < j)
        {
            while (!isalpha(s[i]))
                i++;
            while (!isalpha(s[j]))
                j--;
            if (i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};

//双指针法
class Solution6 {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
        {
            while (i < j && !isalpha(s[i]))
                i++;
            while (i < j && !isalpha(s[j]))
                j--;
            if (i < j)
            {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};


int main()
{
    //cout << Solution2().replaceSpaces("hello world", 11) << endl;
    //cout << Solution3().replaceSpaces("               ", 5) << endl;
    cout << Solution5().reverseOnlyLetters("Test1ng-Leet=code-Q!") << endl;
    cout << Solution5().reverseOnlyLetters("a - bC - dEf - ghIj") << endl;
    return 0;
}