#include<iostream>
#include"list_subject.h"
#include<fstream>
#include<vector>    
using namespace std;
void list_subject::lay_du_lieu_tu_file(string file_name){
    ifstream f(file_name);
    if(!f.is_open()){
        cout<<"ko mo dc file!"<<endl;
        return;
    }else{
       subject mon_temp;
        while(mon_temp.nhap_du_lieu_tu_file(f)){
            ds_mon.push_back(mon_temp);
        }
    }
    f.close();
}
  void list_subject::xuatds(){
        cout<<"-------Danh sach giang vien-------"<<endl;
        for(int i = 0;i<ds_mon.size();i++){
            ds_mon[i].hienthithongtin();
            cout<<"\n";
        }
}
subject list_subject::tim_mon_theo_ten(string ten_mon){
    for(int i = 0;i<ds_mon.size();i++){
        if(ds_mon[i].get_ten() == ten_mon){
            return ds_mon[i];
        }
    }
    subject mon_null;
    return mon_null;
}
