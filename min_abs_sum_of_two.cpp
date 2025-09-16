#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> s{};
    sort(s.begin(), s.end());
    cout << (s.begin() == s.begin());
    return 0;
}