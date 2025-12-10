#pragma once
#include<iostream>
#include"time.h"
#include<vector>
using namespace std;
class list_time{
    private:
    vector<Time>ds_time;
    public:
    void hienthids();
    Time tim_kip_hoc_theo_tg(string ten_kip);
    void add_time(Time a){
        ds_time.push_back(a);
    }
    void delete_time(int i){
        if (i < 0 || i >= ds_time.size()) return;
        ds_time.erase(ds_time.begin() + i);
    }
    void lay_du_lieu_tu_file(string file_name);
};