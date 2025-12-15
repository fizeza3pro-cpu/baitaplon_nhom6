#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class subject{
    private:
    string ten_mon_hoc;
    int so_tin_chi;
    int so_buoi;
    vector<string>ma_lop_hoc;
    public:
    subject(string a,int b, int c){
        ten_mon_hoc = a;
        so_tin_chi = b;
        so_buoi = c;
    }
    subject(){
        ten_mon_hoc = "";
        so_tin_chi = 0;
        so_buoi = 0;
    }
     bool nhap_du_lieu_tu_file(ifstream &f);
    void nhap();
    void hienthithongtin();
    string get_ten()const{
        return ten_mon_hoc;
    }
    int get_tin_chi()const{
        return so_tin_chi;
    }
    void add_ma_lop_hoc(string a){
        ma_lop_hoc.push_back(a);
    }
};