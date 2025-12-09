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
        nha = "";
        phong_hoc = "";
    }
    offline(int a, int b, int c, int d, int e, string y, string z, int m, int n, int p, string k, string q) :
        couse(a, b, c, d, e, y, z, m, n, p), nha(q), phong_hoc(k) {
        // tusinhma();
        loai = "OFFLINE";
    }
    string get_data()const {
        return phong_hoc + "|" + nha;
    }
    string get_loai()const {
        return loai;
    }
    void nhap();
    void hienthi();
    // void tusinhma();
};