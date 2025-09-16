// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>
#include <set>

using namespace std;
int solution(int M, vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    int i{}, last{};
    long long int result{};
    std::set<int> S{};
    while (i < N)
    {
        if (S.find(A[i]) == S.end())
        {
            S.insert(A[i]);
            ++i;
        }
        else
        {
            long long int dist = i - last;
            result += dist;
            if (result > 1000000000)
            {
                return 1000000000;
            }
            S.erase(A[last]);
            ++last;
        }
    }
    if (!S.empty())
    {
        long long int s = S.size();
        result += (s + 1) * s / 2;
    }
    if (result > 1000000000)
    {
        return 1000000000;
    }
    else
    {
        return result;
    }
}

int main()
{
    int M{6};
    vector<int> A{3, 4, 5, 5, 2};
    cout << solution(M, A);
}