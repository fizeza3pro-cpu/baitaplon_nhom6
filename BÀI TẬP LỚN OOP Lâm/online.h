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
        // tusinhma();
        nen_tang = "";
        link = ""; /* link tam thoi chua viet */
    }
    online(int max,giangvien a,Time b, subject c,string k) :
        couse(max,a,b,c), nen_tang(k) {
        // tusinhma();
        loai = "OFFLINE";
    }
    string get_data()const{
        return nen_tang;
    }
    string get_loai()const{
        return loai;
    }
    void xuatlink();
    void nhap(giangvien gv_func,Time time_func,subject sub_func);
    void hienthi();
    bool nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,vector<string>a); 
    bool xuat_du_lieu_file(string &file_name);
};
