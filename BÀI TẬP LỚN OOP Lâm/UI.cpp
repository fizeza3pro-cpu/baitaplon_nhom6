// #include "ui.h"
// #include <iostream>
// #include <windows.h>
// using namespace std;

// void UI::setColor(Color color) {
//     SetConsoleTextAttribute(
//         GetStdHandle(STD_OUTPUT_HANDLE),
//         static_cast<int>(color)
//     );
// }

// void UI::print(const std::string& text, Color color) {
//     HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

//     // Lưu màu hiện tại
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     GetConsoleScreenBufferInfo(h, &csbi);
//     WORD oldColor = csbi.wAttributes;

//     // Đổi màu
//     SetConsoleTextAttribute(h, static_cast<int>(color));
//     cout << text;

//     // Khôi phục màu cũ
//     SetConsoleTextAttribute(h, oldColor);
// }

// void UI::println(const std::string& text, Color color) {
//     print(text, color);
//     std::cout << std::endl;
// }
