#include<iostream>
#include"list_sinhvien.h"
#include<string>
using namespace std;

void list_sinhvien::nhapds()
{
	cout << "Nhap so luong sinh vien :";
	cin >> sl;
	for (int i = 0; i < sl; i++)
	{
		cout << "Nhap thong tin sinh vien thu " << i + 1<<":"<<endl;
		p[i] = new sinhvien;
		p[i]->nhap();
	}
}
void list_sinhvien::xuatds()
{
	cout << "-------Thong tin sinh vien-------";
	for (int i = 0; i < sl; i++)
	{
		p[i]->hienthithongtin();
	}
}