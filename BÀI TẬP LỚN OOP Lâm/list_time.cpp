#include<iostream>
#include"list_time.h"
#include<fstream>
#include<vector>    
using namespace std;
void list_time::lay_du_lieu_tu_file(string file_name){
    ifstream f(file_name);
    if(!f.is_open()){
        cout<<"ko mo dc file!"<<endl;
        return;
    }else{
        Time time_temp;
        while(time_temp.nhap_du_lieu_tu_file(f)){
            ds_time.push_back(time_temp);
        }
    }
    f.close();
}
  void list_time::hienthids(){
        cout<<"-------Danh sach giang vien-------"<<endl;
        for(int i = 0;i<ds_time.size();i++){
            ds_time[i].hienthithongtin();
            cout<<"\n";
        }
}
Time list_time::tim_kip_hoc_theo_tg(string ten_kip){
    for(int i = 0;i<ds_time.size();i++){
        if(ds_time[i].get_thoi_gian_hoc() == ten_kip){
            return ds_time[i];
        }
    }
    Time time_null;
    return time_null;
}
