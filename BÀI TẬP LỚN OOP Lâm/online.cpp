#include<iostream>
#include<string>
#include"online.h"
using namespace std;
// void online::tusinhma(){
//     string thay_the = ten_mon_hoc;
//     for(char &temp : thay_the){ /*Range-based for loop*/
//         temp = tolower(temp);
//     }
//     string temp;
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
void online::nhap(){
    couse::nhap();
    cin.ignore();
    cout<<"Nhap nen tang hoc: ";
    getline(cin,nen_tang);
}
void online::hienthi(){
     cout<<"---[ONLINE]------"<<endl;
    couse::hienthi();
    cout<<"    "<<"Nen tang hoc: "<<nen_tang<<endl;
}