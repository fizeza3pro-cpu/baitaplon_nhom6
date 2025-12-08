#include<iostream>
#include<string>
#include"couse.h"
using namespace std;
void couse::tusinhma(){
    ma_mon_hoc = to_string(sl);
    while(ma_mon_hoc.length()<3){
        ma_mon_hoc.insert(0,"0");
    }
    string thay_the = ten_mon_hoc;
    for(char &temp : thay_the){ /*Range-based for loop*/
        temp = tolower(temp);
    }
    string temp;
    if (thay_the.find("lap trinh") != string::npos || 
        thay_the.find("cong nghe") != string::npos ||
        thay_the.find("may tinh") != string::npos) {
        ma_mon_hoc = "IT" +ma_mon_hoc;
    }
    else if (thay_the.find("toan") != string::npos ||
            thay_the.find("giai tich") != string::npos ||
        thay_the.find("dai so") != string::npos) {
        ma_mon_hoc = "GT" +ma_mon_hoc;
    }
    else if (thay_the.find("vat ly") != string::npos) {
        ma_mon_hoc = "VL" +ma_mon_hoc;
    }
    else if (thay_the.find("chinh tri") != string::npos ||
            thay_the.find("mac lenin") != string::npos || 
            thay_the.find("chu nghia") != string::npos || 
            thay_the.find("hoc") != string::npos) {
        ma_mon_hoc = "CT" +ma_mon_hoc;
    }else ma_mon_hoc = "KT" +ma_mon_hoc;
}
void couse::fix_matusinh(){
    if(ma_mon_hoc[0] == 'K' && ma_mon_hoc[1] == 'K' ){
        ma_mon_hoc.erase(0, 2);
    }
}
void couse::nhap(){
    cout<<"Nhap ten mon hoc: ";
    getline(cin,ten_mon_hoc);
    cout<<"Nhap thoi gian hoc: "<<endl;
    time.nhap();
    cout<<"Nhap ten giang vien: ";
    cin.ignore();
    getline(cin,gv);
    cout<<"Nhap so luong sinh vien toi da: ";
    cin>>max_sv;
    cout<<"nhap so tin chi mon hoc:";
    cin>>tc;
}
void couse::hienthi(){
    cout<<"[+] Ten mon hoc: "<<ten_mon_hoc<<"\t"<<"Ma mon hoc: "<<ma_mon_hoc<<"\t"<<"Giang vien: "<<gv<<endl;
    cout<<"    Thoi gian: ";
    time.xuat();
    cout<<"\t"<<"So tin chi: "<<tc<<"\t\t"<<"So luong :"<<cur_sv<<"/"<<max_sv<<endl;
}
bool couse::tang_sv(){
    if(cur_sv<max_sv){
        cur_sv++;
        return true;
    }else return false;
}
bool couse::giam_sv(){
    if(cur_sv<max_sv){
        cur_sv--;
        return true;
    }else return false;
}
bool couse::ktra_full(){
    if(cur_sv == max_sv){
        return true;
    }else return false;
}
nhanh ve ngu thoi