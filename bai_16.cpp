#include <bits/stdc++.h>
#include "vector.cpp"
#define ll long long
using namespace std;
class SoLon
{
private:
    vector<int> v;

public:
    SoLon()
    {
        v = {};
    }
    SoLon(string s)
    {
        for (char x : s)
        {
            this->v.push_back(x - '0');
        }
    }
    friend istream &operator>>(istream &in, SoLon &a);
    friend ostream &operator<<(ostream &out, SoLon a);
    friend void addZero(SoLon &x, int sz);
    friend void change(SoLon &x, SoLon &y);
    friend void delZero(SoLon &x);
    friend SoLon operator+(SoLon x, SoLon y);
    friend SoLon operator*(SoLon x, ll z);
    friend SoLon operator*(SoLon x, SoLon y);
    friend SoLon operator-(SoLon x, SoLon y);
};

istream &operator>>(istream &in, SoLon &a)
{
    string s;
    in >> s;
    for (char x : s)
    {
        a.v.push_back(x - '0');
    }
    return in;
}

ostream &operator<<(ostream &out, SoLon a)
{
    for (int x : a.v)
    {
        cout << x;
    }
    return out;
}

void addZero(SoLon &x, int sz)
{
    reverse(x.v.begin(), x.v.end());
    while (x.v.size() < sz)
    {
        x.v.push_back(0);
    }
    reverse(x.v.begin(), x.v.end());
}
void change(SoLon &x, SoLon &y)
{
    int sz = max(x.v.size(), y.v.size());
    addZero(x, sz);
    addZero(y, sz);
}
void delZero(SoLon &x)
{
    reverse(x.v.begin(), x.v.end());
    while (x.v.size() >= 2)
    {
        if (x.v.back() == 0)
        {
            x.v.pop_back();
        }
        else
        {
            break;
        }
    }
    reverse(x.v.begin(), x.v.end());
}

SoLon operator*(SoLon x, ll y)
{
    SoLon z;
    ll carry = 0;
    int sz = x.v.size();
    for (int i = sz - 1; i >= 0; i--)
    {
        int k = x.v[i] * y + carry;
        carry = k / 10;
        k %= 10;
        z.v.push_back(k);
    }
    if (carry != 0)
    {
        z.v.push_back(carry);
    }
    reverse(z.v.begin(), z.v.end());
    return z;
}

SoLon operator*(SoLon x, SoLon y)
{
    SoLon z;
    reverse(x.v.begin(), x.v.end());
    reverse(y.v.begin(), y.v.end());
    vector<int> c(x.v.size() + y.v.size() + 1);
    for (int i = 0; i < (int)x.v.size(); i++)
    {
        for (int j = 0; j < (int)y.v.size(); j++)
        {
            c[i + j] += (x.v[i] * y.v[j]);
            c[i + j + 1] += (c[i + j] / 10);
            c[i + j] %= 10;
        }
    }

    for (int i = 0; i < (int)z.v.size() - 1; i++)
    {
        c[i + 1] += (c[i] / 10);
        c[i] %= 10;
    }
    for (int i : c)
    {
        z.v.push_back(i);
    }
    reverse(z.v.begin(), z.v.end());
    delZero(z);
    return z;
}

SoLon operator+(SoLon x, SoLon y)
{
    SoLon z;
    change(x, y);
    int sz = x.v.size();
    int rem = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        int k = x.v[i] + y.v[i] + rem;
        rem = k / 10;
        k %= 10;
        z.v.push_back(k);
    }
    z.v.push_back(rem);
    reverse(z.v.begin(), z.v.end());
    delZero(z);
    return z;
}

SoLon operator-(SoLon x, SoLon y)
{
    SoLon z;
    change(x, y);
    int sz = x.v.size();
    int rem = 0;
    for (int i = sz - 1; i >= 0; i--)
    {
        int k = x.v[i] - y.v[i] - rem;
        if (k < 0)
        {
            k += 10;
            rem = 1;
        }
        else
        {
            rem = 0;
        }
        z.v.push_back(k);
    }
    reverse(z.v.begin(), z.v.end());
     delZero(z);
    return z;
}

ll f[1002];
int main()
{
    ll n, m;
    cout << "Nhap n : ";
    cin >> n;
    cout << "Nhap so de tinh giai thua : ";
    cin >> m;
    SoLon a("0"), b("1"), f1;
    for (int i = 2; i <= n; i++)
    {
        f1 = a + b;
        a = b;
        b = f1;
    }
    SoLon f2("1");
    for (ll i = 1; i <= m; i = i + 1)
    {
        f2 = f2 * i;
    }
    cout << "So fibonaci thu " << n << " la : " << f1 << endl;
    cout << "Giai thua cua so " << m << " la : " << f2 << endl;
}
