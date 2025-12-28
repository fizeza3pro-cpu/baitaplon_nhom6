// #pragma once
#include<iostream>
#include"UI.h"
#include<string>
#include"time.h"
using namespace std;
void Time::nhap(){
    cout<<"nhap thu hoc trong tuan: ";
    cin>>thu;   
    cout<<"nhap thoi gian bat dau: ";
    cin>>thoi_gian_bat_dau; 
    cout<<"nhap thoi gian ket thuc: ";
    cin>>thoi_gian_ket_thuc;
}
void Time::hienthithongtin(){
    cout<<"Thứ: "<<thu<<" ("<<thoi_gian_bat_dau<<"h00 - "<<thoi_gian_ket_thuc<<"h00)";
}
string Time::hienthithongtin_string(){
    return "Thứ "+to_string(thu) + " (" + to_string(thoi_gian_bat_dau) + "h00-" + to_string(thoi_gian_ket_thuc) + "h00)";
}
