//*****************************************************************************************************

#include <iostream>
using namespace std;

//*****************************************************************************************************

void reverseString(string& s, int start, int end)
{
    if (start < end)
    {
        char tempStr = s[start];
        s[start] = s[end];
        s[end] = tempStr;
        reverseString(s, start + 1, end - 1);
    }
}

//*****************************************************************************************************

//int main()
//{
//    string s = "ABC";
//
//    reverseString(s, 0, s.length() - 1);
//
//    cout << "Reversed String s: " << s << endl;
//
//    return 0;
//}

//*****************************************************************************************************

/*
Reversed String s: CBA
*/