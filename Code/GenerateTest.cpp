#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;
const int N = 1e6;

double generate(double min_val, double max_val)
{
    double range = max_val - min_val;
    return (static_cast<double>(rand()) / (double)RAND_MAX) * range + min_val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(NULL));

    {
        double min_val = 0.0;
        double max_val = 1000000.0;
        string fileName = "test1.txt";
        ofstream fo(fileName);
        for (int i = 1; i <= N; i++)
            fo << fixed << (min_val = generate(min_val, max_val)) << " ";
        fo.close();
    }

    {
        double min_val = 0.0;
        double max_val = 1000000.0;
        string fileName = "test2.txt";
        ofstream fo(fileName);
        for (int i = 1; i <= N; i++)
            fo << fixed << (max_val = generate(min_val, max_val)) << " ";
        fo.close();
    }

    double min_val = 0.0;
    double max_val = 1000000.0;
    for (int test = 3; test <= 10; test++)
    {
        string fileName = "test" + to_string(test) + ".txt";
        ofstream fo(fileName);
        for (int i = 1; i <= N; i++)
            fo << fixed << generate(min_val, max_val) << " ";
        fo.close();
    }

    return 0;
}
