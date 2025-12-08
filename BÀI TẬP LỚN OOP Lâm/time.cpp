// #pragma once
#include<iostream>
#include"time.h"
using namespace std;
void Time::nhap(){
    do{
    cout<<"nhap nam:";
    cin>>y;
    if(y<0){
        cout<<"nam khong hop le, vui long nhap lai!";
    }
    }while(y<0);
    do{
    cout<<"nhap thang:";
    cin>>m;
    if(m<=0 || m>12){
        cout<<"thang khong hop le, vui long nhap lai!";
    }
    }while(m<=0 || m>12);
    if(m == 1 || m == 3 || m == 5 || m == 7|| m == 8 || m == 10 || m == 12){
        do{
        cout<<"nhap ngay:";
        cin>>d;
        if(d<=0 || d>31){
            cout<<"ngay khong hop le, vui long nhap lai!";
    }
    }while(d<=0 || d>31);
    }
    if(m == 4 || m == 6 || m == 9 || m == 11){
        do{
        cout<<"nhap ngay:";
        cin>>d;
        if(d<0 || d>30){
            cout<<"ngay khong hop le, vui long nhap lai!";
    }
    }while(d<0 || d>30);
    }
    if(m == 2){
        int check = y%4;
        if(check == 0){
            do{
            cout<<"nhap ngay:";
            cin>>d;
            if(d<0 || d>29){
            cout<<"ngay khong hop le, vui long nhap lai!";
            }
        }while(d<0 || d>29);
        }
        if(check != 0){
            do{
            cout<<"nhap ngay:";
            cin>>d;
            if(d<0 || d>28){
            cout<<"ngay khong hop le, vui long nhap lai!";
            }
        }while(d<0 || d>28);
        }
    }
    cout<<"nhap tiet bat dau va ket thuc: ";
    cin>>tiet_begin>>tiet_end;/*can toi uu*/
   
}
void Time::xuat(){
    cout<<"Tiet: "<<tiet_begin<<"-"<<tiet_end<<"["<<d<<"/"<<m<<"/"<<y<<"]";
}