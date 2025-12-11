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
  couse::nhap_du_lieu_file(ds_gv,ds_time,ds_sub,a);
        phong_hoc = a[5];
        nha = a[6];
    return true;    
 }
 bool offline::xuat_du_lieu_file(string &file_name){
    ofstream f(file_name,ios::app);
    if(!f.is_open()){
        cout<<"ko mo dc file!";
        return false;
    }else{
        string line;
        couse::xuat_du_lieu_file(line);
        line.insert(0,"offline|");
        f<<line+"|"+phong_hoc+"|"+nha<<"\n";
        f.close();
    }
    return true;

 }