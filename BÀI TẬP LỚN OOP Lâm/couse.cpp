#include<iostream>
#include<string>
#include"couse.h"
using namespace std;
void couse::tusinhma(){
    ma_mon_hoc = to_string(sl);
    while(ma_mon_hoc.length()<3){
        ma_mon_hoc.insert(0,"0");
    }
    string thay_the = mon_hoc.get_ten();
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
    if(ma_mon_hoc[0] == 'K' && ma_mon_hoc[1] == 'T' ){
        ma_mon_hoc.erase(0, 2);
    }
}
void couse::hienthi(){
    cout<<"[+] Ten mon hoc: "<<mon_hoc.get_ten()<<"\t"<<"Ma mon hoc: "<<ma_mon_hoc<<"\t"<<"Giang vien: "<<gv.get_name()<<endl;
    cout<<"    Thoi gian: ";
    time.hienthithongtin();
    cout<<"\t"<<"So tin chi: "<<mon_hoc.get_tin_chi()<<"\t\t"<<"So luong :"<<cur_sv<<"/"<<max_sv<<endl;
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
void couse::nhap(giangvien gv_func,Time time_func,subject sub_func){
       gv = gv_func;
    time = time_func;
    mon_hoc = sub_func;
        cout<<"nhap so luong sinh vien toi da: ";
    cin>>max_sv;
}
bool couse::nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,vector<string>a){
       gv = ds_gv.tim_giangvien_theo_id(a[2]);
    //    if(!gv) return false;
        time = ds_time.tim_kip_hoc_theo_tg(a[3]);
        // if(!time) return false;
        mon_hoc = ds_sub.tim_mon_theo_ten(a[1]);
        // if(!mon_hoc) return false;
        max_sv = stoi(a[4]);
    return true;    
 }
 bool couse::xuat_du_lieu_file(string &line){
    line = mon_hoc.get_ten()+"|"+gv.get_id()+"|"+time.get_thoi_gian_hoc()
        +"|"+to_string(max_sv);
    return true;

 }
