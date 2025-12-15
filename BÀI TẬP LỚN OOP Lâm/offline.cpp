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
bool offline::nhap(giangvien* gv_func,subject* sub_func){
     if(couse::nhap(gv_func, sub_func)){
    cout<<"nhap phong hoc: ";
    cin>>phong_hoc;
    cout<<"nhap toa nha: ";
    cin>>nha;
    return true;
    }
    return false;
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