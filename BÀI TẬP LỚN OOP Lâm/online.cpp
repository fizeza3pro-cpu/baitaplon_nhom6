#include<iostream>
#include<string>
#include"online.h"
using namespace std;
void online::hienthi(){
     cout<<"---[ONLINE]------"<<endl;
    couse::hienthi();
    cout<<"    "<<"Nen tang hoc: "<<nen_tang<<endl;
}
void online::nhap(giangvien gv_func,Time time_func,subject sub_func){
    couse::nhap(gv_func, time_func, sub_func);
    cout<<"nhap nan tang hoc truc tuyen: ";
    getline(cin,nen_tang);
}
 bool online::nhap_du_lieu_file(list_giangvien &ds_gv,list_time &ds_time,list_subject &ds_sub,ifstream &f){
    vector<string> a;
    string line;
    string temp = "";
    if(!getline(f,line)){
        return false;
    }
    if(line.empty()) return false;
    for(char c : line){ 
            if(c == '|'){
                a.push_back(temp); /* đoạn này tách chuỗi theo dấu '|' */
                temp = "";
            }else{
                temp +=c;
            }
        }
       a.push_back(temp);
       temp = "";
     /*   kiểm tra từ dữ liệu các string vừa tách đc gọi các hàm tìm kiếm trong 
         3 danh sách giảng viên, thời gian, môn học để gán cho các thuộc tính 
         của couse */
        if(a.size() != 5) return false;
       gv = ds_gv.tim_giangvien_theo_id(a[1]);
    //    if(!gv) return false;
        time = ds_time.tim_kip_hoc_theo_tg(a[2]);
        // if(!time) return false;
        mon_hoc = ds_sub.tim_mon_theo_ten(a[0]);
        // if(!mon_hoc) return false;
        nen_tang = a[4];
        max_sv = stoi(a[3]);
    return true;
 }