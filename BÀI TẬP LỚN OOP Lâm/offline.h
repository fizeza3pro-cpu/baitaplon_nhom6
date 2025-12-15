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
    offline(string u,subject*c,giangvien *a,int x,int y,int z,int p,string k,string q) :
        couse(u,c,a,x,y,z,p), phong_hoc(k), nha(q) {
        loai = "OFFLINE";
    }
    string get_data()const {
        return phong_hoc + "|" + nha;
    }
    string get_loai()const {
        return loai;
    }
    bool nhap(giangvien* gv_func,subject* sub_func);
    void hienthi();
    bool xuat_du_lieu_file(string &file_name);
    
};