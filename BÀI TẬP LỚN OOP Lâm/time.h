#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Time {
private:
    int thu;
    float thoi_gian_bat_dau;
    float thoi_gian_ket_thuc;
public:
    Time(float b, float c,int a) {
        thu = a;
        thoi_gian_bat_dau = b;
        thoi_gian_ket_thuc = c;
    }
    Time() {
        thu = 0;
        thoi_gian_bat_dau = 0;
        thoi_gian_ket_thuc = 0;
    }
    void nhap();
    bool ktra_trung_lich(Time a) {
        if (thu != a.thu) {
            return false;
        }
        else {
            if (thoi_gian_bat_dau > a.thoi_gian_ket_thuc || thoi_gian_ket_thuc < a.thoi_gian_bat_dau) {
                return false;
            }
        }
        return true;
    }
    void hienthithongtin();
    string hienthithongtin_string();
    int get_thu()const {
        return thu;
    }
    float get_bat_dau()const {
        return thoi_gian_bat_dau;
    }
    float get_ket_thuc()const {
        return thoi_gian_ket_thuc;
    }
    bool operator==(Time& a)const {
        if (thu == a.thu && thoi_gian_bat_dau == a.thoi_gian_bat_dau && thoi_gian_ket_thuc == a.thoi_gian_ket_thuc) {
            return true;
        }
        return false;
    }
    bool operator<(const Time&a)const{
        if(thu < a.thu){
            return true;
        }else if(thu == a.thu && thoi_gian_bat_dau < a.thoi_gian_bat_dau){
            return true;
        }else{
            return false;
        }
        return false;
    }
};
