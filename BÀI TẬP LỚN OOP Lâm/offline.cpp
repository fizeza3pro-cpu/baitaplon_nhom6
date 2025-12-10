#include<iostream>
#include<string>
#include<fstream>
#include"offline.h"
using namespace std;
void offline::hienthi(){
    cout<<"---[OFFLINE]------"<<endl;
    couse::hienthi();
    cout<<"    Dia diem: phong "<<phong_hoc<<"-"<<nha<<endl;
}
void offline::nhap(giangvien gv_func,Time time_func,subject sub_func){
     couse::nhap(gv_func, time_func, sub_func);
    cout<<"nhap phong hoc: ";
    cin>>phong_hoc;
    cout<<"nhap toa nha: ";
    cin>>nha;
}
bool offline::nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,vector<string>a){
       gv = ds_gv.tim_giangvien_theo_id(a[2]);
    //    if(!gv) return false;
        time = ds_time.tim_kip_hoc_theo_tg(a[3]);
        // if(!time) return false;
        mon_hoc = ds_sub.tim_mon_theo_ten(a[1]);
        // if(!mon_hoc) return false;
        phong_hoc = a[5];
        nha = a[6];
        max_sv = stoi(a[4]);
    return true;    
 }
 bool offline::xuat_du_lieu_file(string file_name){
    ofstream f(file_name,ios::app);
    if(!f.is_open()){
        cout<<"ko mo dc file!";
        return false;
    }else{
        f<<"offline|"+mon_hoc.get_ten()+"|"+gv.get_id()+"|"+time.get_thoi_gian_hoc()
        +"|"+to_string(max_sv)+"|"+phong_hoc+"|"+nha<<"\n";
        f.close();
    }
    return true;

 }