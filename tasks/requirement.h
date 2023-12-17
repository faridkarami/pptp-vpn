#include <iostream>

using namespace std;

void requirement()
{
    std::system(Utility::pkg("update -y"));
    std::system(Utility::pkg("upgrade -y"));
    std::system(Utility::pkg("install -y pptpd"));
    std::system("clear");
}