#include<iostream>
#include<vector>
#include<algorithm>
#include<easyx.h>
using namespace std;


//Leetcode 26
//˫ָ��
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            while (right < nums.size() && nums[right] <= nums[left])
                right++;
            if (right == nums.size())
                break;
            if (nums[left] < nums[right])
            {
                nums[++left] = nums[right];

            }
        }
        return left + 1;
    }
};


//Leetcode 80
//˫ָ�뷨
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            if (left < 2)
            {
                left++;
                right++;
                continue;
            }

            if (nums[right] != nums[left - 2])
            {
                nums[left] = nums[right];
                left++;
                right++;
            }

            else
            {
                right++;
            }
        }
        return left;
    }
};

//
//Leetcode 169
//�������ƽⷨ
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};


//ͶƱ��
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                count++;
            }
            else {
                count--;
                if (count < 0) {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        return candidate;
    }
};
//
//int main()
//{
//    //vector<int>nums1 = { 0,0,0,1,2,3,4,4,4,4,4,4,5,6,7,7,7,8,9,9,9,9,12 };
//    //cout << Solution1().removeDuplicates(nums1) << endl;
//    //for (auto e : nums1)
//    //{
//    //    cout << e << " ";
//    //}
//    //cout << endl;
//
//    //cout << Solution2().removeDuplicates(nums1) << endl;
//    //for (auto e : nums1)
//    //{
//    //    cout << e << " ";
//    //}
//    //cout << endl;
//
//    vector<int>nums2 = { 1,1,1,1,1,1,1,1,3,3,3,3,3,3,3,2,2,2,2,2,2,2,2,6,6,6,6,6,6,6,6,6,6,6,6,66,6,6,6,66,6,6,6,6,6,6,6,6,66,6,6,6,6,6 };
//    cout << Solution().majorityElement(nums2) << endl;
//    return 0;
//}

/*
ͼ�λ����
*/
int main()
{
    //��������
    initgraph(800, 600);

    //���ñ���ɫ
    setbkcolor(RGB(255, 128, 192));

    //����
    cleardevice();

    //ͼƬ��Ⱦ
    /*
    1������ͼƬ����
    2������ͼƬ
    3����ȾͼƬ
    */
    IMAGE pic;
    loadimage(&pic, L"picture.jpg",900,600);
    putimage(0, 0, &pic);

    setbkmode(0);
    settextcolor(WHITE);
    //��ʾ���� 
    int x = 0;
    int y = 0;
    
    for (int i = 0; i < 10000; i++)
    {
        outtextxy(x, y, L"��������ѧ");
        Sleep(100);
        x += 10;
        y += 10;
        cleardevice();
        putimage(0, 0, &pic);
    }

    while (true)
    {
        
    }
    //�رմ���
    closegraph();

    return 0;
}
