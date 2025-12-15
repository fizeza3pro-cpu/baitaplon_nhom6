#pragma once
#include<iostream>
#include<string>
#include"couse.h"
using namespace std;
class online: public couse{
    private:
    string loai;
    string nen_tang;
    string link;
    public:
    online():couse(){
        loai = "ONLINE";
          nen_tang = "";
        link = ""; /* link tam thoi chua viet */
    }
    online(string u,subject*c,giangvien *a,int x,int y,int z,int p,string k) :
        couse(u,c,a,x,y,z,p), nen_tang(k) {
        loai = "ONLINE";
    }
    string get_data()const{
        return nen_tang;
    }
    string get_loai()const{
        return loai;
    }
    void xuatlink();
    bool nhap(giangvien* gv_func,subject* sub_func);
    void hienthi();
    bool xuat_du_lieu_file(string &file_name);
};
