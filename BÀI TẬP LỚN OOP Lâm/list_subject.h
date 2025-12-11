#pragma once
#include<iostream>
#include"subject.h"
#include<vector>
using namespace std;
class list_subject{
    private:
    vector<subject>ds_mon;
    public:
    void xuatds();
    subject tim_mon_theo_ten(string ten_mon);
    void add_mon_hoc(subject a){
        ds_mon.push_back(a);
    }
    void delete_mon_hoc(int i){
        if (i < 0 || i >= ds_mon.size()) return;
        ds_mon.erase(ds_mon.begin() + i);
    }
    void lay_du_lieu_tu_file(string file_name);
    subject get_subject(int i){
        return ds_mon[i];
    }
};