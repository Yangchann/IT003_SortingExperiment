#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const int n = 1000000;
float a[1000005];

void quickSort(float a[], int left, int right)
{
    int i = left, j = right;
    float pivot = a[left + rand() % (right - left)];

    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;

        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (left < j)
        quickSort(a, left, j);
    if (i < right)
        quickSort(a, i, right);
}

int main()
{
    for (int Test = 1; Test <= 10; ++Test)
    {
        string file_name = "test" + to_string(Test) + ".txt";
        ifstream fi(file_name);
        for (int i = 0; i < n; ++i)
            fi >> a[i];
        auto start_time = high_resolution_clock::now();
        quickSort(a, 0, n - 1);
        auto end_time = high_resolution_clock::now();
        cout << duration_cast<microseconds>(end_time - start_time).count() << '\n';
    }
    return 0;
}
