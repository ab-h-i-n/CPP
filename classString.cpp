//29.

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class String {
    char* str;

public:
    String() {
        str = nullptr;
    }

    String(char* s) {
        int len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }

    String(string& s) {
        int len = s.length();
        str = new char[len + 1];
        for (int i = 0; i < len; ++i) {
            str[i] = s[i];
        }
        str[len] = '\0';
    }
    
    String operator+(String& S) {
        int len1 = strlen(str);
        int len2 = strlen(S.str);

        char* result = new char[len1 + len2 + 1];

        strcpy(result, str);
        strcat(result, S.str);

        String newString(result);

        return newString;
    }

    bool operator<=(String& S) {
        return (strcmp(str, S.str) <= 0);
    }

    void display() {
        cout << str << endl;
    }
};

int main() {
    string input1, input2;

    cout << "Enter the first string: ";
    cin >> input1;

    cout << "Enter the second string: ";
    cin >> input2;

    String s1(input1);
    String s2(input2);

    String s3 = s1 + s2;
    s3.display();

    if (s1 <= s2) {
        cout << "s1 is less than or equal to s2" << endl;
    } else {
        cout << "s1 is greater than s2" << endl;
    }

    return 0;
}
