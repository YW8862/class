/*
 * @Author: YW8862 2165628227@qq.com
 * @Date: 2025-03-20 20:37:07
 * @LastEditors: YW8862 2165628227@qq.com
 * @LastEditTime: 2025-03-20 21:33:27
 * @FilePath: \test\mian.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <array>

constexpr int getSize(int a, int b)
{
	return a + b;
}

int main()
{
	std::array<int, getSize(2, 3)> arr;
	return 0;
}