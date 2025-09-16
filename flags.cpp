// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iterator>
int solution(vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    vector<int> peaks{};
    // finds all the peaks
    for (int i = 1; i < N - 1; ++i)
    {
        if (A[i] > A[i + 1] && A[i] > A[i - 1])
        {
            peaks.push_back(i);
        }
    }
    int max_flags = peaks.size();
    // if there are no peaks, or only 1 peak, return these result
    if (max_flags == 0 || max_flags == 1)
        return max_flags;
    // it can be sure that we always set 1 flag to - first peak - for example
    // currrent_flags -> how many flags we can bring, further?
    int result{1}, current_flags{}, l{1}, r{max_flags};
    // consider all number of flags that we can possibly bring, maximum is the number of peaks
    while (l <= r)
    {
        current_flags = (r - l) / 2 + l;
        // count the currently set flags, at least 1 from the - first peak
        int flags_set{1}, left_index{}, right_index{};
        while (flags_set < current_flags)
        {
            bool end_of_peaks{false};
            // from left_index, find the nearest right_index that the distance is at least current_flags

            while (peaks[right_index] - peaks[left_index] < current_flags)
            {
                ++right_index;
                if (right_index == max_flags)
                {
                    end_of_peaks = true;
                    break;
                }
            }
            // do not proceed further if we do not have any peaks left
            if (end_of_peaks)
                break;
            // continue searching nearest from current right_index
            left_index = right_index;
            ++flags_set;
        }
        if (flags_set == current_flags)
        {
            result = current_flags;
            l = current_flags + 1;
        }
        else
        {
            r = current_flags - 1;
        }
    }
    return result;
}

/*
    The Hint 💡
    The core of the problem is determining if it's possible to place K flags.
    The number of flags you can place is monotonically increasing with respect to the number of flags you take.

    That is, if you can place K flags,
    you can also place any number of flags less than K (e.g., K−1, K−2, etc.).
    This is because with fewer flags, the distance constraint is smaller, making it easier to place them.
    This monotonic property is a strong signal that a binary search can be applied.


*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A)
{
    // Implement your solution here
    int N = A.size();
    vector<int> peaks{};
    // finds all the peaks
    for (int i = 1; i < N - 1; ++i)
    {
        if (A[i] > A[i + 1] && A[i] > A[i - 1])
        {
            peaks.push_back(i);
        }
    }
    int max_flags = peaks.size();
    max_flags = min(max_flags, sqrt(N));
    // if there are no peaks, or only 1 peak, return these result
    if (max_flags == 0 || max_flags == 1)
        return max_flags;
    // it can be sure that we always set 1 flag to - first peak - for example
    // currrent_flags -> how many flags we can bring, further?
    int result{1}, current_flags{}, l{1}, r{max_flags};
    // consider all number of flags that we can possibly bring, maximum is the number of peaks
    while (l <= r)
    {
        current_flags = (r - l) / 2 + l;
        // count the currently set flags, at least 1 from the - first peak
        int flags_set{1}, left_index{}, right_index{};
        while (flags_set < current_flags)
        {
            bool end_of_peaks{false};
            // from left_index, find the nearest right_index that the distance is at least current_flags

            while (peaks[right_index] - peaks[left_index] < current_flags)
            {
                ++right_index;
                if (right_index == max_flags)
                {
                    end_of_peaks = true;
                    break;
                }
            }
            // do not proceed further if we do not have any peaks left
            if (end_of_peaks)
                break;
            // continue searching nearest from current right_index
            left_index = right_index;
            ++flags_set;
        }
        if (flags_set == current_flags)
        {
            result = current_flags;
            l = current_flags + 1;
        }
        else
        {
            r = current_flags - 1;
        }
    }
    return result;
}
