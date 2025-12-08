#pragma once
#include<iostream>
#include<string>
using namespace std;
class Time{
    private:
    int d,m,y;
    int tiet_begin;
    int tiet_end;
    public:
    Time(int a = 12, int b = 12,int c = 1,int d = 1, int e = 1):
    tiet_begin(a),tiet_end(b),d(c),m(d),y(e){};
    void nhap();
    void xuat();
    friend class couse;
};
hhhhhhhhhhhhh
con som ma hoc di