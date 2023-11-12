#include <bits/stdc++.h>
#include "slist_dual.cpp"
#include <conio.h>
using namespace std;

int menu()
{
    int ch;
    cout << "------------Cac su lua chon-------------\n";
    cout << "1.Duyet list sau khi xoa cac phan tu trung nhau. \n";
    cout << "2.Duyet list sau khi bien doi cac phan tu thanh (x^2-7x+3)%100 xoa cac phan tu trung nhau. \n";
    cout << "3.Duyet list sau khi sap xep list tang dan. \n";
    cout << "4.Nhap x va chen vao list de day van tang dan.\n";
    cout << "5.Duyet list theo chieu nguoc de duoc thu tu giam dan. \n";
    cout << "6.Thoat.\n";
    cin >> ch;
    return ch;
}

int main()
{
    slist<int> s;
    int n;
    cout << "Nhap so so phan tu trong list : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s.push_back(x);
    }
    int ch;

    do
    {
        ch = menu();
        switch (ch)
        {
        case 1:
            s.eraseDataSame();
            cout << "Duyet list sau khi xoa cac phan tu trung nhau : \n";
            for (auto x : s)
            {
                cout << x << " ";
            }
            cout << endl;
            break;

        case 2:
        {
            s.setNewData();
            s.eraseDataSame();
            cout << "Duyet list sau khi bien doi cac phan tu thanh (x^2-7x+3)%100 xoa cac phan tu trung nhau : \n";
            slist<int>::iterator it;
            for (it = s.begin(); it != NULL; it++)
            {
                cout << *it << " ";
            }
            cout << "\n";
        }
        break;
        case 3:
        {
            s.sortList();
            cout << "Duyet list sau khi sap xep list : \n";
            for (auto x : s)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
        break;
        case 4:
        {
            int x, k;
            cout << "Nhap x : ";
            cin >> x;
            cout << "Nhap vi tri de chen x : ";
            cin >> k;
            s.insertAndSort(x, k);
            cout << "Duyet list sau khi them x va van sap xep : \n";
            for (auto x : s)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
        break;
        case 5:
        {
            slist<int>::iterator it1;
            cout << "Duyet list theo chieu nguoc de duoc thu tu giam dan : \n";
            for (it1 = s.rbegin(); it1 != s.rend(); it1--)
            {
                cout << *it1 << " ";
            }
            cout << "\n";
        }
        break;
            getch();
        }
    } while (ch != 6);
}

// 0 1 7 2 3 5 76 212 100 1 2 345 0 14