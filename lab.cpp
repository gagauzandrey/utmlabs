#include <iostream>
using namespace std;

int main()
{
    float a = 0;
    float b = 0;
    float c = 0;
    float x_begin = 0;
    float x_end = 0;
    float d_step = 0;
    float F = 0;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "x begin: ";
    cin >> x_begin;
    cout << "x end: ";
    cin >> x_end;
    cout << "step: ";
    cin >> d_step;
    
    for (float x = x_begin; x < x_end; x += d_step){
        if (a < 0 && x != 0)
            F = (a * x * 2) + (b * x * 2);
        else if (a > 0 && x == 0)
            F = (x)-((x - a) / (x - c));
        else
            F = 1 + (x / c);
        cout << "x = " << x << "\t" << "F = " << F << endl;
    }
    return 0;
}
    
