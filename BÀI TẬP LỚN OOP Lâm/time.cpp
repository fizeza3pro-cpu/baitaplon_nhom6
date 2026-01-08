// #pragma once
#include<iostream>
#include"UI.h"
#include<string>
#include"time.h"
using namespace std;
void Time::nhap() {
   do {
    cout << "Nhập thứ học trong tuần (2-7): ";
    cin >> thu;
    cout << "Nhập thời gian bắt đầu (vd: 7.5 = 7h30): ";
    cin >> thoi_gian_bat_dau;
    cout << "Nhập thời gian kết thúc: ";
    cin >> thoi_gian_ket_thuc;
    if (thu < 2 || thu > 7)
        cout << "❌ Thứ không hợp lệ!\n";
    else if (thoi_gian_bat_dau >= thoi_gian_ket_thuc)
        cout << "❌ Thời gian bắt đầu phải nhỏ hơn thời gian kết thúc!\n";
} while (thu < 2 || thu > 7 || thoi_gian_bat_dau >= thoi_gian_ket_thuc);
}
void Time::hienthithongtin() {
    int phut_bd = 60 * (thoi_gian_bat_dau - (int)thoi_gian_bat_dau);
    int phut_kt = 60 * (thoi_gian_ket_thuc - (int)thoi_gian_ket_thuc);
    cout << "Thứ: " << thu << " (" << thoi_gian_bat_dau << "h"<<phut_bd<<"-"<< thoi_gian_ket_thuc << "h"<<phut_kt<<")";
}
string Time::hienthithongtin_string() {
    int gio_bd = (int)thoi_gian_bat_dau;
    int gio_kt = (int)thoi_gian_ket_thuc;
    int phut_bd = (int)((thoi_gian_bat_dau - gio_bd) * 60 + 0.5);
    int phut_kt = (int)((thoi_gian_ket_thuc - gio_kt) * 60 + 0.5);
    return "Thứ " + to_string(thu) + " (" +
           to_string(gio_bd) + "h" + (phut_bd < 10 ? "0" : "") + to_string(phut_bd) +
           " - " +
           to_string(gio_kt) + "h" + (phut_kt < 10 ? "0" : "") + to_string(phut_kt) +
           ")";
}
