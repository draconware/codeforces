#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<pair<int, int> > arr(n, make_pair(0, 0));
    for (int i = 0; i < n; ++i)
        cin >> arr[i].first >> arr[i].second;
    int max = 0;
    for (int i = 0; i < arr.size(); ++i)
        for (int j = i + 1; j < arr.size(); ++j) {
            if (((arr[i].first + arr[j].first <= a && arr[i].second <= b && arr[j].second <= b) || (arr[i].second + arr[j].second <= b && arr[j].first <= a && arr[i].first <= a)) && arr[i].first * arr[i].second +
                arr[j].first * arr[j].second > max)
                max = arr[i].first * arr[i].second +
                    arr[j].first * arr[j].second;
           swap(arr[j].first, arr[j].second);
           if (((arr[i].first + arr[j].first <= a && arr[i].second <= b && arr[j].second <= b) || (arr[i].second + arr[j].second <= b && arr[j].first <= a && arr[i].first <= a)) && arr[i].first * arr[i].second +
                arr[j].first * arr[j].second > max)
                max = arr[i].first * arr[i].second +
                arr[j].first * arr[j].second;
           swap(arr[i].first, arr[i].second);
           if (((arr[i].first + arr[j].first <= a && arr[i].second <= b && arr[j].second <= b) || (arr[i].second + arr[j].second <= b && arr[j].first <= a && arr[i].first <= a)) && arr[i].first * arr[i].second +
               arr[j].first * arr[j].second > max)
               max = arr[i].first * arr[i].second +
                   arr[j].first * arr[j].second;
           swap(arr[j].first, arr[j].second);
           if (((arr[i].first + arr[j].first <= a && arr[i].second <= b && arr[j].second <= b) || (arr[i].second + arr[j].second <= b && arr[j].first <= a && arr[i].first <= a)) && arr[i].first * arr[i].second +
               arr[j].first * arr[j].second > max)
               max = arr[i].first * arr[i].second +
                   arr[j].first * arr[j].second;
        }
    cout << max << endl;
    return 0;
}