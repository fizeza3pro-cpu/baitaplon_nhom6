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
    online(int a, int b, int c,int d,int e, string y, string z,int m,int n,int p ,string q):
    couse(a,b,c,d,e,y,z,m,n,p),nen_tang(q){
        link = "";
        // tusinhma();
         loai = "ONLINE";
    }
    string get_data()const{
        return nen_tang;
    }
    string get_loai()const{
        return loai;
    }
    void nhap();
    void hienthi();
    void xuat_link();
    // void tusinhma();
};
366666