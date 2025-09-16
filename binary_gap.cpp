// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <vector>
using namespace std;

int solution(int N)
{
    // Implement your solution here
    vector<int> x{};
    while (N)
    {
        x.push_back(N & 1);
        N >>= 1;
    }
    int result{}, temp{}, length = x.size();
    bool surrounded{false};

    for (int i = 0; i < length; ++i)
    {
        if (x[i] == 1)
        { // possibly the border for zeros
            if (surrounded)
            { // if already surrounded, this definitely the right border
                surrounded = false;
                result = result > temp ? result : temp; // update the result
            }
            if (i + 1 < length && x[i + 1] == 0)
            { // if not surrounded, and right next item is 0, this is definitely the left border
                surrounded = true;
                temp = 0;
            }
            /*
                otherwise, not surrounded, and next item is 1 -> continue the loop, to avoid a sequence of 1
            */
        }
        else
        {
            if (surrounded)
            { // add to the temp when surrounded
                ++temp;
            }
        }
    }
    return result;
}

#include <algorithm>
using namespace std;

int solution(int N)
{
    int max_gap = 0;
    int current_gap = -1; // -1 means we haven't seen the first '1' yet

    while (N > 0)
    {
        if (N & 1)
        {
            if (current_gap > max_gap)
                max_gap = current_gap;
            current_gap = 0; // Start counting zeros after this '1'
        }
        else if (current_gap != -1)
        {
            ++current_gap;
        }
        N >>= 1;
    }
    return max_gap;
}