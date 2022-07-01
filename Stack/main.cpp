#include <iostream>
#include "Stack.h"

int main()
{

    Stack<int> st(222);
    st << 33 << 11 << 12 << 22;
    std::cout << st;
    return 0;
}
