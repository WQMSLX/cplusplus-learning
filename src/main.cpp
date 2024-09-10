#include <iostream>
#include <cstring>

#define LOG(x) std ::cout << x << std ::endl;

int main(int argc, const char **argv)
{

    char *buffer = new char[8];
    memset(buffer, 0, 8);

    delete[] buffer;
    return 0;
}