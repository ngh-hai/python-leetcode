// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <algorithm>
int solution(vector<int> &A)
{
    // Implement your solution here
    int N = A.size(), result{};
    if (N < 3)
        return result;
    std::sort(A.begin(), A.end());
    for (int i = 0; i < N - 2; ++i)
    {
        int k{i + 2};
        for (int j = i + 1; j < N - 1; ++j)
        {
            while (k < N)
            {
                long long int x = A[i], y = A[j], z = A[k];
                if (x + y > z)
                {
                    ++k;
                }
                else
                {
                    break;
                }
            }
            result += k - j - 1;
        }
    }
    return result;
}
