#include <iostream>
#include <foo.hpp>
#include <stdlib.h>
#include <thread>
#include <string>
#include <cxxopts.hpp>

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
    using namespace std;
    cout << "参数数量:";
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
