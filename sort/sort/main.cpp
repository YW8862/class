#include <iostream>
#include <vector>
#include "sort.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	std::vector<int>nums = { 2,1,5,2,8,6,5,7,9 };
	heapSort(nums);
	for (auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
	return 0;
}