// you can use includes, for example:
#include <algorithm>
#include <utility>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    vector<pair<long long int, long long int>> borders(N);
    for (int i = 0; i < N; ++i)
    {
        borders[i] = {(long long int)(i) - (long long int)(A[i]), (long long int)(i) + (long long int)(A[i])};
    }
    sort(borders.begin(),
         borders.end(),
         [](const std::pair<long long int, long long int> &a, const std::pair<long long int, long long int> &b)
         {
             if (a.first == b.first)
             {
                 return a.second < b.second;
             }
             return a.first < b.first;
         });

    // for (auto i : borders)
    // {
    //     cout << i.first << ' ' << i.second << '\n';
    // }
    int result{};
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (borders[j].first <= borders[i].second)
            {
                ++result;
                if (result > 10000000)
                    return -1;
            }
            else
                break;
        }
    }
    return result;
}

/*
    Idea:
    - for each element in array A, we convert it to range of points in x-axis
      example: A[0] = 1 -> [-1; 1]
    - 2 discs intersect does not intersect each other when right1<left2 or right2<left1
    -> we sort base on ascending order of left border, if same left border, then sort by right border
    - from sorted vector, iterate through all pairs of borders (discs), if left2<=right1, this means 1 and 2 intersects.
*/