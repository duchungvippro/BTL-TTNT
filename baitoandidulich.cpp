#include <iostream>
#include <climits>

#define maxN 100

using namespace std;

int n;
int c[maxN + 1][maxN + 1];
int x[maxN], kq[maxN];
bool cx[maxN + 1];
long Min, cp, Cmin;

void khoitao()
{
    cout << "Nhap so thanh pho n = ";
    cin >> n;
    // Nhap ma tran chi phi
    cout << "Nhap ma tran chi phi:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "c[" << i << "][" << j << "] = ";
            cin >> c[i][j];
        }
    }
    cout << "So thanh pho n = " << n << "\n";
    cout << "Ma tran chi phi:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";

    for (int i = 1; i <= n; i++)
        cx[i] = true;

    x[1] = 1;
    cx[1] = false;

    Min = LONG_MAX;
    cp = 0;

    // Tim PT nho nhat cua ma tran chi phi
    Cmin = LONG_MAX;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (c[i][j] != 0 && c[i][j] < Cmin)
                Cmin = c[i][j];
}

void capnhat()
{
    if (cp + c[x[n]][1] < Min)
    {
        Min = cp + c[x[n]][1];
        for (int i = 1; i <= n; i++)
            kq[i] = x[i];
    }
}

void Try(int i)
{
    for (int j = 2; j <= n; j++)
        if (cx[j])
        {
            x[i] = j;
            cp = cp + c[x[i - 1]][j];
            cx[j] = false;
            if (i == n)
                capnhat();
            else if (cp + (n - i + 1) * Cmin < Min)
                Try(i + 1);
            cx[j] = true;
            cp = cp - c[x[i - 1]][j];
        }
}

void inkq()
{
    cout << "Hanh trinh voi chi phi nho nhat:\n";
    for (int i = 1; i <= n; i++)
        cout << kq[i] << " --> ";
    cout << "1\n";

    cout << "Chi phi: " << Min << "\n";
}

int main()
{
    khoitao();
    Try(2);
    inkq();

    return 0;
}

