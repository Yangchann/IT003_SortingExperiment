#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

const int n = 1000000;
int a[1000005];

void merge(int l, int mid, int r)
{
    int subarr1 = mid - l + 1, subarr2 = r - mid;
    vector<int> larr(subarr1), rarr(subarr2);
    for (auto i = 0; i < subarr1; i++)
        larr[i] = a[l + i];
    for (auto j = 0; j < subarr2; j++)
        rarr[j] = a[mid + 1 + j];
    int i1 = 0, i2 = 0, idmerged = l;
    while (i1 < subarr1 && i2 < subarr2)
    {
        if (larr[i1] <= rarr[i2])
        {
            a[idmerged] = larr[i1];
            ++i1;
        }
        else
        {
            a[idmerged] = rarr[i2];
            ++i2;
        }
        ++idmerged;
    }
    while (i1 < subarr1)
    {
        a[idmerged] = larr[i1];
        ++i1;
        ++idmerged;
    }
    while (i2 < subarr2)
    {
        a[idmerged] = rarr[i2];
        ++i2;
        ++idmerged;
    }
}

void mergeSort(int l, int r)
{
    if (l >= r)
        return;
    auto mid = l + (r - l) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, r);
}

int main()
{
    for (int Test = 1; Test <= 10; ++Test)
    {
        string filename = "test" + to_string(Test) + ".txt";
        ifstream fi(filename);
        for (int i = 0; i < n; ++i)
            fi >> a[i];
        auto starttime = high_resolution_clock::now();
        mergeSort(0, n - 1);
        auto finishtime = high_resolution_clock::now();
        cout << duration_cast<microseconds>(finishtime - starttime).count() << '\n';
    }
    return 0;
}
