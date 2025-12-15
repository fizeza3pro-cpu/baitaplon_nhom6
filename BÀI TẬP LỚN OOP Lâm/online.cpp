#include<iostream>
#include<string>
#include"online.h"
using namespace std;
void online::hienthi(){
     cout<<"---[ONLINE]------"<<endl;
    couse::hienthi();
    cout<<"    "<<"Nen tang hoc: "<<nen_tang<<endl;
}
bool online::nhap(giangvien* gv_func,subject* sub_func){
    if(couse::nhap(gv_func, sub_func)){
    cout<<"nhap nan tang hoc truc tuyen: ";
    cin.ignore();
    getline(cin,nen_tang);
    return true;
    }
    return false;
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