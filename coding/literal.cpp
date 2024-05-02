//
// Created by dlut2102 on 2024/5/2.
//
#include <iostream> 
int main() 
{ 
    double float_array[]{ 5.875, 1000, 0.117 }; 
    for (auto elem : float_array) 
    { 
        std::cout << std::hexfloat << elem << " = " 
        << std::defaultfloat << elem << std::endl;
    } 
    int a=0b11'111;
    std::cout<<a<<std::endl;
    std::string s=R"cpp(dsfdcppcppcppcpp()()()()(sfds['f\ffds\f]\sd]f\]sd\f]sd\a)cpp";
    std::string s1=R"(dsfdcppcppcppcpp()()()()(sfds['f\ffds\f]\sd]f\]sd\f]sd\a)";
    std::cout<<s<<std::endl;
    std::cout<<s1<<std::endl;
}