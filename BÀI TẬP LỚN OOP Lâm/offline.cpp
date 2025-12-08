#include<iostream>
#include<string>
#include"offline.h"
using namespace std;
// void offline::tusinhma(){
//    // string temp;
//     string thay_the = ten_mon_hoc;
//     for(char &temp : thay_the){ /*Range-based for loop*/
//         temp = tolower(temp);
//     }
//     if (thay_the.find("lap trinh") != string::npos || 
//         thay_the.find("cong nghe") != string::npos ||
//         thay_the.find("may tinh") != string::npos) {
//         ma_mon_hoc = "IT" +ma_mon_hoc;
//     }
//     else if (thay_the.find("toan") != string::npos ||
//             thay_the.find("giai tich") != string::npos) {
//         ma_mon_hoc = "GT" +ma_mon_hoc;
//     }
//     else if (thay_the.find("vat ly") != string::npos) {
//         ma_mon_hoc = "VL" +ma_mon_hoc;
//     }
//     else if (thay_the.find("chinh tri") != string::npos ||
//      thay_the.find("mac lenin") != string::npos) {
//         ma_mon_hoc = "CT" +ma_mon_hoc;
//     }else ma_mon_hoc = "KT" +ma_mon_hoc;
// }
void offline::nhap(){
    couse::nhap();
    cin.ignore();
    cout<<"Nhap phong hoc: ";
    cin>>phong_hoc;
    cout<<"Nhap toa nha: ";
    cin.ignore();
    getline(cin,nha);
}
void offline::hienthi(){
    cout<<"---[OFFLINE]------"<<endl;
    couse::hienthi();
    cout<<"    Dia diem: phong "<<phong_hoc<<"-"<<nha<<endl;
}