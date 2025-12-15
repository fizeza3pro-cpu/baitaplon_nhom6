#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Time{
    private:
    int thu;
    int thoi_gian_bat_dau;
    int thoi_gian_ket_thuc;
    public:
    Time(int a, int b, int c){
        thu = c;
        thoi_gian_bat_dau = a;
        thoi_gian_ket_thuc = b;
    }
    Time(){
        thu = 0;
        thoi_gian_bat_dau = 0;
        thoi_gian_ket_thuc = 0;
    }
    void nhap();
    bool ktra_trung_lich(Time a){
        if(thu != a.thu){
            return false;
        }else{
            if(thoi_gian_bat_dau>a.thoi_gian_ket_thuc || thoi_gian_ket_thuc<a.thoi_gian_bat_dau){
                return false;
            }
        }
        return true;
    }
    void hienthithongtin();
    int get_thu()const{
        return thu;
    }
    int get_bat_dau()const{
        return thoi_gian_bat_dau;
    }
    int get_ket_thuc()const{
        return thoi_gian_ket_thuc;
    }
};
