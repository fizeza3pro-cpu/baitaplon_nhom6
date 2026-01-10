#pragma once
#include<iostream>
#include<string>
#include"couse.h"
using namespace std;
class online : public couse {
private:
    string nen_tang;
    string link;
public:
    online() :couse() {
        nen_tang = "";
        link = "ko có dữ liệu"; 
    }
    online(string u, subject* c, giangvien* a, float y, float z, int x, int p, string k,string q) :
        couse(u, c, a, y, z, x, p) {
        nen_tang = k;
        link = q;

    }
    ~online() {}
    virtual void string_file(string &line);
    string tao_random(int do_dai);
    bool nhap(giangvien* gv_func, subject* sub_func);
    void hienthi();
    bool xuat_du_lieu_file(string& file_name);
};
