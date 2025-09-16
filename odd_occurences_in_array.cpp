// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A)
{
    // Implement your solution here
    int result{};
    for (int i : A)
    {
        result ^= i;
    }
    return result;
}

int main()
{

    return 0;
}