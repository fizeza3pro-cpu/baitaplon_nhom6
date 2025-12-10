#include<iostream>
#include<string>
#include"online.h"
using namespace std;
void online::hienthi(){
     cout<<"---[ONLINE]------"<<endl;
    couse::hienthi();
    cout<<"    "<<"Nen tang hoc: "<<nen_tang<<endl;
}
void online::nhap(giangvien gv_func,Time time_func,subject sub_func){
    couse::nhap(gv_func, time_func, sub_func);
    cout<<"nhap nan tang hoc truc tuyen: ";
    cin.ignore();
    getline(cin,nen_tang);
}
 bool online::nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,vector<string>a){
    gv = ds_gv.tim_giangvien_theo_id(a[2]);
    //    if(!gv) return false;
        time = ds_time.tim_kip_hoc_theo_tg(a[3]);
        // if(!time) return false;
        mon_hoc = ds_sub.tim_mon_theo_ten(a[1]);
        // if(!mon_hoc) return false;
        nen_tang = a[5];
        max_sv = stoi(a[4]);
    return true;    
 }
  bool online::xuat_du_lieu_file(string file_name){
    ofstream f(file_name,ios::app);
    if(!f.is_open()){
        cout<<"ko mo dc file!";
        return false;
    }else{
        f<<"online|"+mon_hoc.get_ten()+"|"+gv.get_id()+"|"+time.get_thoi_gian_hoc()
        +"|"+to_string(max_sv)+"|"+nen_tang<<"\n";
        f.close();
    }
    return true;

 }