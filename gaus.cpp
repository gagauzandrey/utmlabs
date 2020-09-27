#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    double a[n][m]; // n: строки, m - столбцы

    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int q = 0; q < m - 1; q++)
    {
        for(int i = q; i < n; i++)
        {
            double k = a[i][q];
            for (int j = 0; j < m; j++)
            {
                a[i][j] /= k;
            }
        }

        if(q != m - 2)
            for (int i = q + 1; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    a[i][j]-= a[q][j];
                }
    }


    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << " \t\t";
        cout << endl;
    }
    double x1, x2, x3;
    /*
    int k = 0;
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < k; j++)
        {

        }
        k++;
    }*/
    x3 = a[n - 1][m - 1];
    x2 =a[n - 2][m - 1] - a[n - 2][m - 2] * x3;
    x1 = a[n - 3][m - 1] - (a[n - 3][m - 3] * x2 + a[n - 3][m - 2] * x3);
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    /*
    3 4
    1 8 9 0
    4 7 8 9
    1 3 4 9
    */
    return 0;
}
