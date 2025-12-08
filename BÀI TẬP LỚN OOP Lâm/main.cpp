#include<iostream>
#include<string>
#include"dangky_couse.h"
#include"thoikhoabieu.h"
#include<stdlib.h>
int couse::sl = 0;
int main(){
 sinhvien a("sv01","Nguyen Dinh Tung Lam","CNTT1","nam","0936363636",12,11,2006,19,60,0,30,0);
    list_couse b;
    b.nhapfile("D:/dulieulophoc.txt");
    dangky_couse c(b);
    c.add_sv(&a);
    tkb tkb;

    // b.nhapdanhsach("D:/dulieulophoc.txt");
    // c.full_ds_monhoc("sv01");
    int chose;
    while (1)
    {
       system("cls");
       cout<<"Xin chao "<<a.get_name()<<endl;
       cout<<"-------------MENU----------------"<<endl;
       cout<<"1.Xem tat ca mon hoc hien co"<<endl;
       cout<<"2.Dang ky mon hoc "<<endl;
       cout<<"3.Huy mon hoc"<<endl;
       cout<<"4.Xem danh sach mon hoc da dang ky "<<endl;
       cout<<"5.Xem thoi khoa bieu"<<endl;
       cout<<"6.Them lop hoc (phan quyen admin) "<<endl;
       cout<<"7.Hien thi thong tin sinh vien "<<endl;
       cout<<"Nhap lua chon cua ban: ";
       cin>>chose;
       switch (chose)
       {
       case 1:
       system("cls");
        c.full_ds_monhoc(a.get_ma());
        cin.ignore();
        cin.get();
        break;
       case 2:
       {
         system("cls");
        string temp;
        cin.ignore();
        cout<<"Nhap ten mon hoc muon dang ky: ";
        getline(cin,temp);
        if(b.timkiem_ten(temp)){
            cout<<"Nhap ma mon hoc muon dang ky: ";
            // cin.ignore();
            getline(cin,temp);
            if(c.dangkymonhoc(temp,a.get_ma())){
                cout<<"DANG KY THANH CONG!";
            }else cout<<"DANG KY THAT BAI";
        }else cout<<"Quay ve menu";
        cin.get();
        }
        break;
       case 3:
       {
         system("cls");
        string temp;
        cout<<"-----------DANH SACH MON DA DANG KY----------"<<endl;;
        c.danhsach_mondky(a.get_ma());
        cin.ignore();
        cout<<"nhap ma mon hoc muon huy: ";
        getline(cin,temp);
        if(c.huymonhoc(temp,a.get_ma())){
            cout<<"Da huy mon hoc thanh cong!";
        }else cout<<"Huy mon hoc that bai, hay thu lai";
        cin.get();
       }
        break;
       case 4:
       {
         system("cls");
        c.danhsach_mondky(a.get_ma());
        cin.ignore();
        cin.get();
       }
        break;
       case 5:
       {
         system("cls");
        tkb.taotkb(a,b);
        tkb.sapxep();
        tkb.hienthi(a);
        cin.ignore();
        cin.get();
       }
        break;
       case 6:
       {
         system("cls");
        cout<<"Nhap thong tin lop hoc muon them: "<<endl;
        cin.ignore();
        b.nhapdanhsach("D:/dulieulophoc.txt");
        cout<<"Them lop hoc thanh cong!";
        cin.get();
       }
        break;
       case 7:
       {
         system("cls");
        cout<<"\t\t\t\t\t----THONG TIN SINH VIEN-----"<<endl;
        a.hienthithongtin();
        cin.ignore();
        cin.get();
       }
        break;
       
       default:
        break;
       }

    }
    
}
