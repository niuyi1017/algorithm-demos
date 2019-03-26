#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;

    string str = to_string(a + b);
    int leng = str.length();
    for (int i = 0; i < leng; i++)
    {
        cout << str[i];
        if (str[i] == '-')
        {
            continue;
        }
        if ((i + 1) % 3 == leng % 3 && i != leng - 1)
        {
            cout << ",";
        }
    }
    return 0;
}
// "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.12.25827/include/*",
// "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.12.25827/atlmfc/include/*",
// "C:/Program Files (x86)/Windows Kits/10/Include/10.0.16299.0/um",
// "C:/Program Files (x86)/Windows Kits/10/Include/10.0.16299.0/ucrt",
// "C:/Program Files (x86)/Windows Kits/10/Include/10.0.16299.0/shared",
// "C:/Program Files (x86)/Windows Kits/10/Include/10.0.16299.0/winrt"

// "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.12.25827/include/*",
//     "C:/Program Files (x86)/Microsoft Visual Studio/2017/Community/VC/Tools/MSVC/14.12.25827/atlmfc/include/*",
//     "C:/Program Files (x86)/Windows Kits/10/Include/10.0.16299.0/um",
//     "C:/Program Files (x86)/Windows Kits/10/Include/10.0.16299.0/ucrt",
//     "C:/Program Files (x86)/Windows Kits/10/Include/10.0.16299.0/shared",
//     "C:/Program Files (x86)/Windows Kits/10/Include/10.0.16299.0/winrt"

// "c:/mingw/bin/../lib/gcc/mingw32/6.3.0/include/c++",
//     "c:/mingw/bin/../lib/gcc/mingw32/6.3.0/include/c++/mingw32",
//     "c:/mingw/bin/../lib/gcc/mingw32/6.3.0/include/c++/backward",
//     "c:/mingw/bin/../lib/gcc/mingw32/6.3.0/include",
//     "c:/mingw/bin/../lib/gcc/mingw32/6.3.0/../../../../include",
//     "c:/mingw/bin/../lib/gcc/mingw32/6.3.0/include-fixed"

// ,
//     "C:/MinGW/bin/../lib/gcc/mingw32/6.3.0/include/c++",
//     "C:/MinGW/bin/../lib/gcc/mingw32/6.3.0/include/c++/mingw32",
//     "C:/MinGW/bin/../lib/gcc/mingw32/6.3.0/include/c++/backward",
//     "C:/MinGW/bin/../lib/gcc/mingw32/6.3.0/include",
//     "C:/MinGW/bin/../lib/gcc/mingw32/6.3.0/../../../../include",
//     "C:/MinGW/bin/../lib/gcc/mingw32/6.3.0/include-fixed"

// "intelliSenseMode" : "msvc-x64",