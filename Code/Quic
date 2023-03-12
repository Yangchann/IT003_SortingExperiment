#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

const int n = 1000000;
int a[1000005];

int partition(int l, int r)
{
    int pivot = a[r];
    int i = (l - 1);
    for (int j = l; j <= r - 1; ++j)
    {
        if (a[j] <= pivot)
        {
            ++i;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return (i + 1);
}

int partition_r(int l, int r)
{
    srand(time(NULL));
    int random = l + rand() % (r - l);
    swap(a[random], a[r]);
    return partition(l, r);
}

void quickSort(int l, int r)
{
    if (l < r)
    {
        int pi = partition_r(l, r);
        quickSort(l, pi - 1);
        quickSort(pi + 1, r);
    }
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
        quickSort(0, n - 1);
        auto finishtime = high_resolution_clock::now();
        cout << duration_cast<microseconds>(finishtime - starttime).count() << '\n';
    }
    return 0;
}
