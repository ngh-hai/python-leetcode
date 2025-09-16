// you can use includes, for example:
#include <algorithm>
#include <set>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> divisors(int N)
{
    vector<int> divi{};
    long long int i{1};
    long long int n = N;
    while (i * i < n)
    {
        if (n % i == 0)
        {
            divi.push_back(i);
            divi.push_back(n / i);
        }
        ++i;
    }
    if (i * i == n)
    {
        divi.push_back(i);
    }
    return divi;
}

int solution(vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    if (N == 1 || N == 2)
        return 0;
    vector<int> peaks{};
    for (int i = 1; i < N - 1; ++i)
    {
        if (A[i] > A[i + 1] && A[i] > A[i - 1])
        {
            peaks.push_back(i);
        }
    }
    vector<int> div = divisors(N);
    sort(div.begin(), div.end());
    int result{0}, mid{}, low{0}, high = div.size() - 1;
    while (low <= high)
    {
        mid = (high - low) / 2 + low;
        int current_blocks = div[mid], block_size = N / div[mid];
        set<int> s{};
        for (int peak : peaks)
        {
            s.insert((int)(peak / block_size));
        }
        if (s.size() == current_blocks)
        {
            result = current_blocks;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return result;
}
