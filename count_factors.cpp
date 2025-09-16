// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>

using namespace std;

int solution(int N)
{
    // Implement your solution here
    long long int result{0}, i{1};
    long long int n = N;
    while (i * i < n)
    {
        if (n % i == 0)
        {
            result += 2;
        }
        ++i;
    }
    if (i * i == n) // consider i * i overflow when i is int? -> negative
    {
        result += 1;
    }
    return result;
}

int main()
{
    cout << solution(INT_MAX);
    return 0;
}