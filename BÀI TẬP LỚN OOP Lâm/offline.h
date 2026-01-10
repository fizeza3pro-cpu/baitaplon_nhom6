#pragma once
#include<iostream>
#include<string>
#include"couse.h"
using namespace std;
class offline : public couse {
private:
    string phong_hoc;
    string nha;
public:
    offline() :couse() {
        // tusinhma();
        nha = "chua xac dinh";
        phong_hoc = "chua xac dinh";
    }
    offline(string u, subject* c, giangvien* a,  float y, float z, int x, int p, string k, string q) :
        couse(u, c, a, y, z, x, p), phong_hoc(k), nha(q) {
    }
    ~offline() {}
    string get_data()const {
        return phong_hoc + "|" + nha;
    }
    virtual void string_file(string &line); 
    bool nhap(giangvien* gv_func, subject* sub_func);
    void hienthi();
    bool xuat_du_lieu_file(string& file_name);

};