//
// Created by dianyuluo on 2023/5/24.
//
#include "iostream"
#include "filesystem"
using namespace  std;
int main(int argc, char **argv){
    std::cout<<"hello  wealdf"<<std::endl;
    string  s= argv[1];
    std::filesystem::path path(s);
    cout<<path<<endl;
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        std::cout << entry.path() << std::endl; // 输出文件名
    }

}