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
    cout<<"Ma sinh vien: "<<id<<endl;
    cout<<"Ho va ten: "<<name<<"\t\t"<<"Ngay sinh: "<<birth[0]<<"/"<<birth[1]<<"/"<<birth[2]<<"\t\t"<<"Tuoi: "<<tuoi<<endl;
    cout<<"Gioi tinh: "<<gioi_tinh<<"\t\t\t\t"<<"So dien thoai: "<<sdt<<endl;
    cout<<"Chuyen nganh: "<<chuyen_nganh<<"\t\t\t"<<"Khoa : K"<<khoa<<endl;
    cout<<"So tin chi toi da: "<<max_tc<<"\t\t\t"<<"So tin chi da dang ky: "<<cur_tc<<endl;
    cout << "So mon da dang ky: " << so_mon_dky << "\n" << endl;
}
void sinhvien::nhap()
{dsfsdfds
    cout << "Nhap ma sinh vien: ";
    getline(cin, id);
    cout << "Nhap ho va ten: "; 
    cin.ignore();
    getline(cin, name);
    cout << "Nhap ngay thang nam sinh: \n";
    cout << "  Ngay: ";
    cin >> birth[0];
    cout << "  Thang: ";
    cin >> birth[1];
    cout << "  Nam: ";
    cin >> birth[2];
    cin.ignore();
    cout << "Nhap gioi tinh: ";
    getline(cin, gioi_tinh);
    cout << "Nhap so dien thoai: ";
    getline(cin, sdt);
    cout << "Nhap chuyen nganh: ";
    getline(cin, chuyen_nganh);
    cout << "Nhap khoa: ";
    cin >> khoa;
    cout << "Nhap so tin chi toi da: ";
    cin >> max_tc;
}


