#include <bits/stdc++.h>
using namespace std;
void mul(vector<vector<int>> &a, vector<vector<int>> &b, int n)
{
    int r[n][n], sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                sum += a[i][k] * b[k][j];
            }
            r[i][j] = sum;
            sum = 0;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = r[i][j];
}
void power(vector<vector<int>> &v, int n, int p)
{

    vector<vector<int>> I;
    for (int i = 0; i < n; i++)
    {
        I.push_back(vector<int>());
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                I[i].push_back(1);
            else
                I[i].push_back(0);
        }
    }
    while (p)
    {
        if (p % 2 == 1)
        {
            mul(I, v, n);
            p--;
        }
        else
        {
            mul(v, v, n);
            p /= 2;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << I[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    int dim, pow;
    cin >> dim >> pow;
    vector<vector<int>> vec;
    for (int i = 0; i < dim; i++)
    {

        vec.push_back(vector<int>());
        for (int j = 0; j < dim; j++)
        {
            int x;
            cin >> x;
            vec[i].push_back(x);
        }
    }
    power(vec, dim, pow);

    return 0;
}