#include <foo.hpp>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <thread>

void usecmd(std::string str)
{
    system(str.c_str());
}

void usethread(std::string str)
{
    std::thread f(usecmd, str);
    f.detach();
}

int main(int argc, char const *argv[])
{
    system("chcp 65001 > nul");
    using namespace std;
    cout << "参数数量z:";
    cout << argc << "\n";
    for (size_t i = 0; i < static_cast<size_t>(argc); i++)
    {
        cout << argv[i] << "\n";
    }
    usethread("explorer .");
    usethread("explorer ..");
    int x;
    cin >> x;
}
