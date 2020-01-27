#include <bits/stdc++.h>
using namespace std;

struct min_max
{
    int min, max;
};

struct min_max minMax(int arr[], int low, int high)
{
    struct min_max min_max2;
    if (low == high)
    {
        min_max2.min = arr[low];
        min_max2.max = arr[low];
        return min_max2;
    }
    else if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            min_max2.min = arr[low];
            min_max2.max = arr[high];
        }
        else if (arr[high] < arr[low])
        {
            min_max2.min = arr[high];
            min_max2.max = arr[low];
        }
        return min_max2;
    }

    struct min_max mml, mmr;
    int mid = (low + high) / 2;
    mml = minMax(arr, low, mid);
    mmr = minMax(arr, mid + 1, high);

    if (mml.min < mmr.min)
        min_max2.min = mml.min;
    else
        min_max2.min = mmr.min;

    if (mml.max > mmr.max)
        min_max2.max = mml.max;
    else
        min_max2.max = mmr.max;

    return min_max2;
}

int main()
{
    int n;
    cout << "enter size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    struct min_max minmax1 = minMax(arr, 0, n - 1);
    cout << "minimum element: " << minmax1.min << "\n";
    cout << "maximum element: " << minmax1.max << "\n";
    return 0;
}