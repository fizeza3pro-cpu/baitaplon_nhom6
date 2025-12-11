#include<iostream>
#include<string>
#include"subject.h"
using namespace std;
void subject::nhap(){
    cout<<"nhap ten mon hoc: ";
    getline(cin,ten_mon_hoc);
    cout<<"nhap so tin chi: ";
    cin>>so_tin_chi;
    cout<<"nhap so buoi hoc: ";
    cin>>so_buoi;
}
void subject::hienthithongtin(){
    cout<<"ten mon hoc: "<<ten_mon_hoc<<" so tin chi: "<<so_tin_chi<<" so buoi: "<<so_buoi;
}
bool subject::nhap_du_lieu_tu_file(ifstream &f){
    vector<string> a;
    string line;
    string temp = "";
    if(!getline(f,line)){
        return false;
    }
    if(line.empty()) return false;
    for(char c : line){
            if(c == '|'){
                a.push_back(temp);
                temp = "";
            }else{
                temp +=c;
            }
        }
       a.push_back(temp);
       temp = "";
        if(a.size() != 3) return false;
       ten_mon_hoc = a[0];
        so_tin_chi = stoi(a[1]);   
        so_buoi = stoi(a[2]);
    return true;
}