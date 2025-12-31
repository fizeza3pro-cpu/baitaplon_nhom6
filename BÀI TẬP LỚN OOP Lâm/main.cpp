#include<iostream>
#include<string>
#include"UI.h"
#include<fstream>
#include"nghiepvu.h"
#include<stdlib.h>
using namespace std;
int main() {
    chuanhoa(65001);
    list_sinhvien sv;
    list_giangvien gv;
    list_subject mon;
    list_couse lop;
    gv.lay_du_lieu_tu_file("D:/dulieugiangvien.txt");
    mon.lay_du_lieu_tu_file("D:/dulieumonhoc.txt");
    sv.lay_du_lieu_tu_file("D:/dulieusinhvien.txt");
    // loading();
    nghiepvu nv(lop, sv, gv, mon);
    nv.nhap_du_lieu_cho_couse("D:/dulieulophoc.txt");
    pause();
    while(1){
    system("cls");
    doi_mau_full(6);
    drawTitle();
    doi_mau_full(7);
    cout<<"𝟙.hiển thị danh sách lớp học"<<endl;
    cout<<"𝟚.Dang ky lop hoc"<<endl;
    cout<<"3.Huy dang ky lop hoc"<<endl;
    cout<<"4.Tao lop hoc moi"<<endl;
    cout<<"5.Xoa lop hoc"<<endl;
    cout<<"6.Sua thong tin lop hoc"<<endl;
    cout<<"7.Lich su dang ky lop hoc"<<endl;
    cout<<"8.Tìm kiếm lớp học"<<endl;
    cout<<"Nhap lua chon cua ban: ";
    int chose;
    cin>>chose;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Nhập không hợp lệ!";
        }
    switch (chose){
    case 1:
    {
      system("cls");
      cin.ignore();
      lop.hienthidanhsach();
      cin.get();
    }
      break;
    case 2:
    {
      system("cls");
      cin.ignore();
      string masv,ma_lop;
      cout<<"nhap ma sinh vien: ";
      getline(cin,masv);
      cout<<"nhap ma lop: ";
      getline(cin,ma_lop);
      nv.dang_ky_lop_hoc(masv,ma_lop);
      cin.get();
    }
      break;
    case 3:
    {
      system("cls");
      cin.ignore();
      string masv,ma_lop;
      cout<<"nhap ma sinh vien: ";
      getline(cin,masv);
      cout<<"nhap ma lop: ";
      getline(cin,ma_lop);
      nv.huy_dang_ky_lop_hoc(masv,ma_lop);
      cin.get();
    }
      break;
    case 4:
    {
      system("cls");
      cin.ignore();
      string magv,ten_sub;
      cout<<"nhap ma giang vien: ";
      getline(cin,magv);
      cout<<"nhap ten mon hoc:  ";
      getline(cin,ten_sub);
      nv.them_mon_hoc(magv,ten_sub,"D:/dulieulophoc.txt");
      cin.ignore();
      cin.get();
    }
      break;
    case 5:
    {
      system("cls");
      cin.ignore();
      string ma_lop;
      cout<<"nhap ma lop muon xoa: ";
      getline(cin,ma_lop);
      if(lop.delete_lop_hoc(ma_lop,"D:/dulieulophoc.txt")){
        cout<<"Thanh cong!";
      }else{
        cout<<"ko thanh cong!";
      }
      cin.get();
    }
      break;
    case 6:
    {
      system("cls");
      cin.ignore();
      string ma_lop;
      cout<<"nhap ma lop muon sua: ";
      getline(cin,ma_lop);
      cin.ignore();
      nv.thaydoithongtin_couse(ma_lop,"D:/dulieulophoc.txt");
      cin.get();
    }
      break;
    case 7:
    {
      system("cls");
      nv.hienthi_ds_phieu_dky();
      cin.ignore();
      cin.get();
      break;
    }
    case 8:
    {
      system("cls");
      nv.tim_kiem_lop_hoc();
      cin.get();
    }
      break;
    default:
      break;
    }
}
}