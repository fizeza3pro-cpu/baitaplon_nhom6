#pragma once
#include<iostream>
#include<string>
#include"couse.h"
using namespace std;
class offline : public couse {
private:
    string loai;
    string phong_hoc;
    string nha;
public:
    offline() :couse() {
        // tusinhma();
        loai = "OFFLINE";
        nha = "chua xac dinh";
        phong_hoc = "chua xac dinh";
    }
    offline(int max,giangvien a,Time b, subject c,string k, string q) :
        couse(max,a,b,c), nha(q), phong_hoc(k) {
        // tusinhma();
        loai = "OFFLINE";
    }
    string get_data()const {
        return phong_hoc + "|" + nha;
    }
    string get_loai()const {
        return loai;
    }
    void nhap(giangvien gv_func,Time time_func,subject sub_func);
    void hienthi();
    bool nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,vector<string>a);
    bool xuat_du_lieu_file(string &file_name);
    
};