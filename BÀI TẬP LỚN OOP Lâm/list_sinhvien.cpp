#include<iostream>
#include"list_sinhvien.h"
#include<string>
using namespace std;

void list_sinhvien::nhapds()
{
	int sl;
	cout << "Nhap so luong sinh vien :";
	cin >> sl;
	for (int i = 0; i < sl; i++)
	{
		cout << "Nhap thong tin sinh vien thu " << i + 1<<":"<<endl;
		dssv[i].nhap();
	}
}
void list_sinhvien::xuatds()
{
	cout << "-------Thong tin sinh vien-------";
	for (int i = 0; i <dssv.size(); i++)
	{
		dssv[i].hienthithongtin();
		cout << "\n";
	}
}
void list_sinhvien::lay_du_lieu_tu_file(string file_name){
    ifstream f(file_name);
    if(!f.is_open()){
        cout<<"ko mo dc file!"<<endl;
        return;
    }else{
        sinhvien sv_temp;
        while(sv_temp.nhap_du_lieu_tu_file(f)){
            dssv.push_back(sv_temp);
        }
    }
    f.close();
}