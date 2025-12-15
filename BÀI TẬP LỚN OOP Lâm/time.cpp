// #pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
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
    cout<<"thoi gian hoc trong tuan: thu"<<thu;
    cout<<" Thoi gian hoc: tu "<<thoi_gian_bat_dau<<"h den "<<thoi_gian_ket_thuc<<"h";
}