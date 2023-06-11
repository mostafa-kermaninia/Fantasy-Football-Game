#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

double round_to(double value)
{
    return round(value * 10) / 10.0;
}

double calculate_final_score(double score)
{
    return round_to(10 / (exp(-score / 6) + 1));
}

template <typename T>
void sorter(vector<T> vec)
{
    for (int i = 0; i < vec.size(); i++)
        for (int j = i; j < vec.size(); j++)
            if (vec[j] < vec[i])
            {
                T temp = vec[j];
                vec[j] = vec[i];
                vec[i] = temp;
            }
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     cout << vec[i] << " ";
    // }
}

int main()
{
    // string a = "polo", b = "kikil";

    // cout << (a > b);
    // calculate_final_score(5.4);

    vector<int> a = {1, 2, 5, 7, 8, 6, 2};
    vector<string> b = {"rvg", "sef", "ygtbr", "iujh"};

    sorter(a);
    sorter(b);

    // cout << round_to(54.25);
    cout << calculate_final_score(5.8);

    string po = "poM. Travers:350$";
    int pos = po.find(':');
    cout
        << '\n'
        << po.substr(pos+1, 3) << endl
        << po.substr(0, pos);
    ;
    return 0;
}
