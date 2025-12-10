// #pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"time.h"
using namespace std;
void Time::nhap(){
    int n;
    string tmp;
    cout<<"nhap so buoi hoc trong tuan: ";
    cin>>n;
    cout<<"nhap thu hoc trong tuan: ";
    for(int i = 0;i<n;i++){
        cin.ignore();
        getline(cin,tmp);
        thu_hoc_trong_tuan.push_back(tmp);
    }
    cin.ignore();
    cout<<"nhap thoi gian hoc: ";
    getline(cin,thoi_gian_hoc);
}
void Time::hienthithongtin(){
    cout<<"thoi gian hoc trong tuan: ";
    for(string x:thu_hoc_trong_tuan){
        cout<<x<<" ";
    }
    cout<<"Thoi gian hoc: tu"<<thoi_gian_hoc;
}
bool Time::nhap_du_lieu_tu_file(ifstream &f){
    vector<string> a;
    string line;
    string temp = "";
    if(!getline(f,line)){
        return false;
    }
    if(line.empty()) return false;
    for(char c : line){
            if(c == '|'){
                a.push_back(temp);
                temp = "";
            }else{
                temp +=c;
            }
        }
       a.push_back(temp);
       temp = "";
        if(a.size() > 8) return false;
        thoi_gian_hoc = a[0];
        for(int i = 1;i<a.size();i++){
            thu_hoc_trong_tuan.push_back(a[i]);
        }
    return true;
}
