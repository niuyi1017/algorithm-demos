#include<iostream>
using namespace std;

main(int argc, char const *argv[])
{
    float x = 3.1415;
    x = (int)(x*100+0.5)/100.0;
    cout<<x;
    return 0;
}
