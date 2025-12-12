#include<iostream>
#include<string>
#include"phieu_dang_ky.h"
using namespace std;
// void phieu_dang_ky::tao_phieu_dky(sinhvien a,couse* b){
//     sv_dky = a;
//     lop_dky = b;
//     thoi_gian_dky = "12/06/2024"; /* chua xac dinh thoi gian dang ky */  
// }
string phieu_dang_ky::to_string2(int x){
    return (x<10 ? "0" : "")+ to_string(x);
}
string phieu_dang_ky::lay_tg_thuc(){
    time_t now = time(0);
    tm *lmt = localtime(&now);
    string thoi_gian;
    thoi_gian = to_string2(lmt->tm_hour) + ":" + to_string2(lmt->tm_min) 
    + ":" + to_string2(lmt->tm_sec) + " " + to_string(lmt->tm_mday) + "/" 
    + to_string(lmt->tm_mon + 1) + "/" + to_string(1900 + lmt->tm_year);
    return thoi_gian;
}
void phieu_dang_ky::hien_thi_phieu_dky(){
    cout<<"-----PHIEU DANG KY MON HOC-----"<<endl;
    cout<<"Sinh vien: "<<sv_dky.get_name()<<"\t\t"<<"Thoi gian dang ky: "<<thoi_gian_dky<<endl;
    cout<<"lop dang ky: "<<endl;
    lop_dky ->hienthi();
}
