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
// void offline::nhapdulieutufile(giangvien gv_func,Time time_func,subject sub_func,string file_name){
//     vector<string> a;
//     string line;
//     string temp = "";
//     ifstream f(file_name);
//     if(!f){
//         cout<<"ko mo dc file!"<<endl;
//         return;
//     }else{
//         int n = 0;
//         for(char c : line){
//             if(c == '|'){
//                 a[n++] = temp;
//                 temp = "";
//             }else{
//                 temp +=c;
//             }
//         }
//         a[n++] = temp;
//         temp = "";
//         gv = gv_func;
//         time = time_func;
//         mon_hoc = sub_func;
//     }
// }
 bool offline::nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,ifstream &f){
    cout<<"loi cai dmm";
    return true;
 }