#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < n; i++)
        sum2 = sum2 + arr[i] * (n - i);

    sum2 = sum2 / n;
    cout << sum2;
}
