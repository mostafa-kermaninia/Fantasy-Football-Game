#include <iostream>

using namespace std;

int round(double num)
{
    return (num + 0.5);
}

double round_to(double pre, double value)
{
    cout << round(value * 10) << endl;
    return round(value / pre) * pre;
}
int main()
{
    cout << round_to(0.1, 5.55) << endl;
    cout << round_to(0.1, 5.549) << endl;
    cout << round_to(0.1, 5.551) << endl;
    cout << round(7.5) << endl;
}