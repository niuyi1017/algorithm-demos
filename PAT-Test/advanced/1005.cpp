#include<iostream>
#include<string>

using namespace std;

main(int argc, char const *argv[])
{
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    string c;
    cin >>c;
    int sum = 0;
    for(int i = 0;i<c.length();i++){
        sum = sum+(c[i]-'0');
    }
    
    string s = to_string(sum);
    cout<<arr[s[0]-'0'];
    for(int i = 1;i<s.length();i++){
        cout<<" "<<arr[s[i]-'0'];
    }
    
    return 0;
}
