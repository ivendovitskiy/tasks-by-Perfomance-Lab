#include <iostream>
#include <string>

using namespace std;
string compStr(string s1, string s2);

int main()
{
    setlocale(LC_ALL, "Russian");
    string str1, str2;

    cin >> str1;
    cin >> str2;
    cout << compStr(str1, str2);
}

string compStr(string s1, string s2)
{
    int count = 0; //количество символов, отличных от '*', в строке 2
    int l1 = s1.length();
    int l2 = s2.length();
    int i = 0;
    int j = 0;

    for (; i < l2; ++i)
    {
        if (s2[i] != '*')
        {
            ++count;
        }
    }
    i = 0;

    if (s1 == s2 || (s2 != "" && count == 0))
    {
        return "OK";
    }
    else
    {
        while (s2[j] == '*')
        {
            ++j;
        }
        while (i < l1 && j < l2)
        {
            if (count > l1 - i)
            {
                return "KO";
                break;
            }
            else if (count == 0 && s2[l2 - 1] == '*')
            {
                return "OK";
                break;
            }
            else if (s2[j] == '*')
            {
                ++j;
                continue;
            }
            else if (s1[i] == s2[j])
            {
                --count;
                ++i;
                ++j;
            }
            else if (j == 0)
            {
                return "KO";
                break;
            }
            else if (s2[j - 1] == '*')
            {
                ++i;
                continue;
            }
            else if (s2[j - 1] == s1[i - 1])
            {
                while (s2[j] != '*')
                {
                    --j;
                    ++count;
                }
                ++j;
                --count;
            }
            else
            {
                return "Ошибка";
                break;
            }
        }
        return "OK";
    }
}
