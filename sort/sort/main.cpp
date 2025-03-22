#include <iostream>
#include <vector>
#include "sort.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	std::vector<int>nums = {2,6,1,2,7,5,2,1,8,6,9,4,5,7,6};
	insertSort(nums);
	for (auto& num : nums)
	{
		cout << num << " ";
	}
	cout << endl;
	return 0;
}