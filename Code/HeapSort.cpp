#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

const int n = 1000000;
int a[1000005];

void heapify(int N, int i)
{
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;
    if (l < N && a[l] > a[largest])
        largest = l;
    if (r < N && a[r] > a[largest])
        largest = r;
    if (largest != i)
    {
        swap(a[i], a[largest]);
        heapify(N, largest);
    }
}

void heapSort()
{
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(n, i);
    for (int i = n - 1; i >= 0; --i)
    {
        swap(a[0], a[i]);
        heapify(i, 0);
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
        heapSort();
        auto finishtime = high_resolution_clock::now();
        cout << duration_cast<microseconds>(finishtime - starttime).count() << '\n';
    }
    return 0;
}
