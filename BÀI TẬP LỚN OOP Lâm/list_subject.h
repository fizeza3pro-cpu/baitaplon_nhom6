
#pragma once
#include<iostream>
#include"subject.h"
#include<vector>
using namespace std;
class list_subject {
private:
    vector<subject> ds_mon;
public:
    void lay_du_lieu_tu_file(string file_name);
    void ghi_du_lieu_vao_file(string file_name); 


    subject* tim_mon_theo_ten(string ten_mon);
    subject* tim_mon_theo_ma(string ma_mon);

    void add_mon_hoc(string file_name);
    void hthi_ds_mon_hoc();
    bool xoa_mon_hoc_theo_ma(string ma,string file_name);

    subject& get_subject(int i) { 
        return ds_mon[i]; 
    }
    int get_size() const { 
        return (int)ds_mon.size(); 
    }

    // ===== Náº P CHá»’NG =====
    // friend ostream& operator<<(ostream& os, const list_subject& l);
    // friend istream& operator>>(istream& is, list_subject& l);
};