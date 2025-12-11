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
   couse::nhap_du_lieu_file(ds_gv,ds_time,ds_sub,a);
        nen_tang = a[5];
    return true;    
 }
  bool online::xuat_du_lieu_file(string &file_name){
    ofstream f(file_name,ios::app);
    if(!f.is_open()){
        cout<<"ko mo dc file!";
        return false;
    }else{
        string line;
        couse::xuat_du_lieu_file(line);
        line.insert(0,"online|");
        f<<line+"|"+nen_tang<<"\n";
        f.close();

    }
    return true;

 }