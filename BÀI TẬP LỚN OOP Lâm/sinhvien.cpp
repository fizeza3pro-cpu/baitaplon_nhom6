#include<iostream>
#include<string>
#include"sinhvien.h"
using namespace std;
bool sinhvien::dadangky(const string ma_mon){
    if(so_mon_dky == 0){
        return false;
    }else{
        for(int i = 0;i<so_mon_dky;i++){
            if(ds_ma_mon_dky[i] == ma_mon){
                return true;
            }
        }
        return false;
    }
}
bool sinhvien::add_couse(const string ma_mon,int tin){
    if(dadangky(ma_mon)){
        cout<<"mon hoc da dc dang ki!"<<endl;
        return false;
    }else if(cur_tc + tin > max_tc){
        cout<<"vuot qua so luong tin chi, ko the them"<<endl;
        return false;
    }else{
        ds_ma_mon_dky[so_mon_dky] = ma_mon;
        so_mon_dky++;
        cur_tc += tin;
        return true;
    }
    return false;
}
bool sinhvien::delete_couse(const string ma_mon,int tin){
    if(!dadangky(ma_mon)){
        cout<<"ko co mon hoc, ko the xoa!"<<endl;
        return false;
    }else{
        for(int i = 0;i<so_mon_dky;i++){
            if(ds_ma_mon_dky[i] == ma_mon){
                for(int j = i;j<so_mon_dky -1;j++){
                    ds_ma_mon_dky[j] = ds_ma_mon_dky[j+1];
                }
                ds_ma_mon_dky[so_mon_dky-1] ="";
                so_mon_dky-=1;
                cur_tc -= tin;
                return true;
            }
        }
    }
    return false;
}
void sinhvien::hienthithongtin(){
    cout<<"Ma sinh vien: "<<id<<"\n"<<endl;
    cout<<"Ho va ten: "<<name<<"\t\t"<<"Ngay sinh: "<<birth[0]<<"/"<<birth[1]<<"/"<<birth[2]<<"\t\t"<<"Tuoi: "<<tuoi<<"\n"<<endl;
    cout<<"Gioi tinh: "<<gioi_tinh<<"\t\t\t\t"<<"So dien thoai: "<<sdt<<"\n"<<endl;
    cout<<"Chuyen nganh: "<<chuyen_nganh<<"\t\t\t"<<"Khoa : K"<<khoa<<"\n"<<endl;
    cout<<"So tin chi toi da: "<<max_tc<<"\t\t\t"<<"So tin chi da dang ky: "<<cur_tc<<"\n"<<endl;
    cout<<"So mon da dang ky: "<<so_mon_dky;
}


