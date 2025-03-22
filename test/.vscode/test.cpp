#include <functional>

typedef void(*)(int,int) func_t;
using func_t = function<void(int,int)>;


void add(int a,int b)
{
    a+b;
}