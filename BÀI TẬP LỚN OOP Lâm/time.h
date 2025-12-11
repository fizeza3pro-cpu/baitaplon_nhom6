#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Time{
    private:
    vector<string>thu_hoc_trong_tuan;
    string thoi_gian_hoc;
    public:
    Time(string a = "chua xac dinh"):thoi_gian_hoc(a){
    };
    void nhap();
    void hienthithongtin();
    bool nhap_du_lieu_tu_file(ifstream &f);
    string get_thoi_gian_hoc()const{
        return thoi_gian_hoc;
    }
    friend class couse;
};
