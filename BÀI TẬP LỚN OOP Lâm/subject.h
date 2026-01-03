
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
class subject {
private:
    string ma_mon_hoc;
    string ten_mon_hoc;
    int so_tin_chi;
    int so_buoi;
    vector<string> ma_lop_hoc;
public:
    subject() {
        ma_mon_hoc = "";
        ten_mon_hoc = "";
        so_tin_chi = 0;
        so_buoi = 0;
    }
    subject(string ma, string ten, int tc, int buoi) {
        ma_mon_hoc = ma;
        ten_mon_hoc = ten;
        so_tin_chi = tc;
        so_buoi = buoi;
    }
    string get_ma_mon() const { 
        return ma_mon_hoc; 
    }
    string get_ten() const { 
        return ten_mon_hoc; 
    }
    int get_tin_chi() const { 
        return so_tin_chi; 
    }
    int get_so_buoi() const { 
        return so_buoi; 
    }
    int get_size_lop() const{
        return ma_lop_hoc.size();
    }
    string get_lop(int i)const{
        if(i>=0 && i<ma_lop_hoc.size()){
            return ma_lop_hoc[i];
        }
        return "";
    }
    void ghi_du_lieu_vao_file(string file_name);

    //void nhap();
    //void hienthithongtin();
    bool nhap_du_lieu_tu_file(ifstream& f);
    string to_file_string() const; // Chuyá»ƒn dá»¯ liá»‡u sang dáº¡ng Ma|Ten|TC|Buoi Ä‘á»ƒ ghi file

    void add_ma_lop_hoc(string a) { 
        ma_lop_hoc.push_back(a); 
    }
    bool xoa_ma_lop_hoc(string ma_lop);

    friend ostream& operator<<(ostream& os, const subject& s);
    friend istream& operator>>(istream& is, subject& s);

};