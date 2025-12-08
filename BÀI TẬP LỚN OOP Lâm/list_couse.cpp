#include<iostream>
#include<fstream>
#include"list_couse.h"
#include<string>
using namespace std;
void list_couse::nhapfile(string file_name){
    string a[100];
    string line;
    string temp = "";
    ifstream f(file_name);
    if(!f.is_open()){
        cout<<"ko mo dc file!"<<endl;
        return;
    }else{
        while(getline(f,line) && cnt <= 100){
            // for(int k = 0; k < 100; k++) a[k] = "";
            // temp = "";
            int n = 0;
            for(char c : line){
                if(c == '|'){
                    a[n++] = temp;
                    temp = "";
                }else{
                    temp += c;
                }
            }
            cout<<"o";
            a[n++] = temp;
            temp ="";
            if(a[0] == "online"){
                p[cnt++] = new online(stoi(a[1]),stoi(a[2]),stoi(a[3])
            ,stoi(a[4]),stoi(a[5]),a[6],a[7],stoi(a[8]),stoi(a[9]),stoi(a[10]),a[11]);
            }else if(a[0] == "offline"){
                p[cnt++] = new offline(stoi(a[1]),stoi(a[2]),stoi(a[3])
            ,stoi(a[4]),stoi(a[5]),a[6],a[7],stoi(a[8]),stoi(a[9]),stoi(a[10]),a[11],a[12]);

            }
        }
        f.close();
        cout<<"da tai thanh cong "<<cnt<<" mon!"<<endl;
    }
}
void list_couse::xuatdanhsach(){
    cout<<"--------------DANH SACH TEST---------------"<<endl;
    for(int i = 0;i<cnt;i++){
        p[i] ->hienthi();
        cout<<"\n";
    }
}
bool list_couse::timkiem_ten(string ten_mon){
    int dem = 0;
    string ten_mon_upper = ten_mon;
    ten_mon_upper[0] = toupper(ten_mon_upper[0]);
    for(int i = 0;i<cnt;i++){
        if(p[i]->getten_mon_hoc().find(ten_mon_upper) != string::npos||
        p[i]->getten_mon_hoc().find(ten_mon) != string::npos){
        p[i] ->hienthi();
        dem++;
        }
    }
    if(dem == 0){
        cout<<"ko tim thay ket qua!"<<endl;
        return false;
    }else{
    cout<<"tim thay tat ca "<<dem<<" mon hoc!"<<endl;
    return true;
    }
}
bool list_couse::timkiem_ma(string ma){/* muốn có thể hiển thị cả trạng thái đăng ký lúc tìm kiếm */
    for(int i = 0;i<cnt;i++){            /*nhưng chưa làm đc vì 1 là cho friend hoặc viết hàm này trong danhsachdangky*/ 
        if(p[i] -> getma_mon_hoc() == ma){
            p[i] -> hienthi();
             cout<<"\n";
            return true;
        }
    }
    return false;
}
void list_couse::nhapdanhsach(string file_name){
    string chose;
    string line;
    ofstream f(file_name,ios::app);
    if(!f.is_open()){
        cout<<"ko mo dc file!"<<endl;
        return;
    }
    cout<<"Nhap loai lop hoc muon dang ( ON / OFF): ";
    getline(cin,chose);
    if(chose == "ON" || chose == "on"){
        p[cnt] = new online;
        p[cnt] -> nhap();
        p[cnt] ->fix_matusinh();
        p[cnt] ->tusinhma(); /* xử lý hàm tự sinh mã khởi tạo trc khi có tên môn ->mã sai */
        line = "online|"+ p[cnt]->get_time()+"|"+p[cnt]->getten_mon_hoc()
        +"|"+p[cnt]->get_gv()+"|"+to_string(p[cnt]->get_tc())+"|"+to_string(p[cnt]->get_cursv())
        +"|"+to_string(p[cnt]->get_maxsv())+"|"+p[cnt]->get_data();
        cnt++;
    }else if(chose == "OFF" || chose == "off"){
        p[cnt] = new offline;
        p[cnt] -> nhap();
         p[cnt] ->fix_matusinh();
        p[cnt] ->tusinhma();
        line = "offline|" + p[cnt]->get_time()+"|"+p[cnt]->getten_mon_hoc()
        +"|"+p[cnt]->get_gv()+"|"+to_string(p[cnt]->get_tc())+"|"+to_string(p[cnt]->get_cursv())
        +"|"+to_string(p[cnt]->get_maxsv())+"|"+p[cnt]->get_data();
        cnt++;
    }else{
        cout<<"loi nhap lieu, vui long chon dung!"<<endl;
    }
    f<<endl;
    f<<line;
    f.close();
    cout<<"them mon hoc thanh cong!";
}
