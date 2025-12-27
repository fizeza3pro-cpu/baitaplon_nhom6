#include<iostream>
#include<string>
#include"couse.h"
#include"UI.h"
using namespace std;
int couse::sl = 0;
void couse::tusinhma(){
    ma_lop_hoc = to_string(sl);
    while(ma_lop_hoc.length()<3){
        ma_lop_hoc.insert(0,"0");
    }
    ma_lop_hoc = "MTA"+ma_lop_hoc;
}
void couse::hienthi(){
    cout<<"[+] Ten mon hoc: "<<mon_hoc->get_ten()<<"\t"<<"Ma mon hoc: "<<ma_lop_hoc<<"\t"<<"Giang vien: "<<gv->get_name()<<endl;
    cout<<"    Thoi gian: ";
    time.hienthithongtin();
    cout<<"\t"<<"So tin chi: "<<mon_hoc->get_tin_chi()<<"\t\t"<<"So luong :"<<cur_sv<<"/"<<max_sv<<endl;
}
bool couse::tang_sv(){
    if(cur_sv<max_sv){
        cur_sv++;
        return true;
    }else return false;
}
bool couse::giam_sv(){
    if(cur_sv>0){
        cur_sv--;
        return true;
    }else return false;
}
bool couse::ktra_full(){
    if(cur_sv == max_sv){
        return true;
    }else return false;
}
bool couse::nhap(giangvien *gv_func,subject *sub_func){
    time.nhap();
    if(!gv_func->kra_trung_lich(time)){
        cout<<"nhap so luong sinh vien toi da: ";
        cin>>max_sv;
        cout<<"nhap lich hoc cu the: "<<endl;
         cur_sv = 0;
        gv = gv_func;
        gv->them_couse_da_day_id(ma_lop_hoc);
        gv->them_lich_day(time);
        mon_hoc = sub_func;
        mon_hoc->add_ma_lop_hoc(ma_lop_hoc);
        return true;
    }else{
        cout<<"giang vien da trung lich";
        return false;
    }
}
// bool couse::nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,vector<string>a){
//        gv = ds_gv.tim_giangvien_theo_id(a[2]);
//     //    if(!gv) return false;
//         time = ds_time.tim_kip_hoc_theo_tg(a[3]);
//         // if(!time) return false;
//         mon_hoc = ds_sub.tim_mon_theo_ten(a[1]);
//         // if(!mon_hoc) return false;2
//         max_sv = stoi(a[4]);
//         cur_sv = 0;
//     return true;    
//  }
 bool couse::xuat_du_lieu_file(string &line){
    line = ma_lop_hoc+"|"+mon_hoc->get_ten()+"|"+gv->get_id()+"|"+to_string(time.get_bat_dau())+"|"+to_string(time.get_ket_thuc())+"|"+to_string(time.get_thu())
        +"|"+to_string(max_sv);
    return true;
 }
 void couse::cap_nhat_id(string id){
    int so = stoi(id.substr(3));
    if(so> sl){
        sl = so;
    }
}
    
