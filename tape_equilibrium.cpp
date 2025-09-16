// you can use includes, for example:
// #include <algorithm>
#include <limits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // Implement your solution here
    int sum{}, length = A.size();
    for (int i : A)
    {
        sum += i;
    }
    int right_sum{A[length - 1]}, left_sum{sum - right_sum}, result{abs(right_sum - left_sum)};
    for (int i = length - 2; i > 0; --i)
    {
        right_sum += A[i];
        left_sum -= A[i];
        int tmp{abs(right_sum - left_sum)};
        result = result < tmp ? result : tmp;
    }
    return result;
}
