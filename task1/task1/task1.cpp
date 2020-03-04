#include <iostream>
#include <string>
#include <cmath>

using namespace std;
string itoBase(unsigned int nb, string base);
string itoBase(string nb, string baseSrc, string baseDst);
unsigned int ito10(string value, string base);
void checkValue(unsigned int value, string &str);
string checkBase(string base);
unsigned int pow(unsigned int a, unsigned int b);

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned int nb;
    string digit;
    string base = "";
    string result = "";

    //cout << "Enter nb";
    cin >> nb;
    if (cin.fail())
    {
        cout << "usage" << endl;
    }
    else
    {
        cin.clear();
        cin.ignore(32767, '\n');
        //cout << "Enter base: ";
        cin >> base;
        if (checkBase(base) == base)
        {
            result += itoBase(nb, base);
            cout << result;
        }
        else
        {
            cout << checkBase(base);
        }
    }
}

string itoBase(unsigned int nb, string base)
{
    string result = "";
    unsigned int p = base.length();

    for (; nb >= p; nb = nb / p)
    {
        checkValue(nb % p, result);
    }

    checkValue(nb, result);

    for (unsigned int i = 0; i < result.length()/2; ++i)
    {
        char tmp = result[i];
        result[i] = result[result.length() - 1 - i];
        result[result.length() - 1 - i] = tmp;
    }
    return result;
}

string itoBase(string nb, string baseSrc, string baseDst)
{
    return itoBase(ito10(nb, baseSrc), baseDst);
}


unsigned int ito10(string value, string base)
{
    unsigned int result = 0;
    int p = base.length();

    /*for (int i = value.length(); i > 0; --i)
    {
        switch (p)
        {
        case 2:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 3:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 4:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 5:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 6:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 7:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            case '6':
                result += 6 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 8:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            case '6':
                result += 6 * pow(p, value.length - i);
            case '7':
                result += 7 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 9:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            case '6':
                result += 6 * pow(p, value.length - i);
            case '7':
                result += 7 * pow(p, value.length - i);
            case '8':
                result += 8 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 10:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            case '6':
                result += 6 * pow(p, value.length - i);
            case '7':
                result += 7 * pow(p, value.length - i);
            case '8':
                result += 8 * pow(p, value.length - i);
            case '9':
                result += 9 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 11:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            case '6':
                result += 6 * pow(p, value.length - i);
            case '7':
                result += 7 * pow(p, value.length - i);
            case '8':
                result += 8 * pow(p, value.length - i);
            case '9':
                result += 9 * pow(p, value.length - i);
            case 'a':
                result += 10 * pow(p, value.length - i);
            case 'A':
                result += 10 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 12:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            case '6':
                result += 6 * pow(p, value.length - i);
            case '7':
                result += 7 * pow(p, value.length - i);
            case '8':
                result += 8 * pow(p, value.length - i);
            case '9':
                result += 9 * pow(p, value.length - i);
            case 'a':
                result += 10 * pow(p, value.length - i);
            case 'A':
                result += 10 * pow(p, value.length - i);
            case 'b':
                result += 11 * pow(p, value.length - i);
            case 'B':
                result += 11 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 13:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            case '6':
                result += 6 * pow(p, value.length - i);
            case '7':
                result += 7 * pow(p, value.length - i);
            case '8':
                result += 8 * pow(p, value.length - i);
            case '9':
                result += 9 * pow(p, value.length - i);
            case 'a':
                result += 10 * pow(p, value.length - i);
            case 'A':
                result += 10 * pow(p, value.length - i);
            case 'b':
                result += 11 * pow(p, value.length - i);
            case 'B':
                result += 11 * pow(p, value.length - i);
            case 'c':
                result += 12 * pow(p, value.length - i);
            case 'C':
                result += 12 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 14:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            case '6':
                result += 6 * pow(p, value.length - i);
            case '7':
                result += 7 * pow(p, value.length - i);
            case '8':
                result += 8 * pow(p, value.length - i);
            case '9':
                result += 9 * pow(p, value.length - i);
            case 'a':
                result += 10 * pow(p, value.length - i);
            case 'A':
                result += 10 * pow(p, value.length - i);
            case 'b':
                result += 11 * pow(p, value.length - i);
            case 'B':
                result += 11 * pow(p, value.length - i);
            case 'c':
                result += 12 * pow(p, value.length - i);
            case 'C':
                result += 12 * pow(p, value.length - i);
            case 'd':
                result += 13 * pow(p, value.length - i);
            case 'D':
                result += 13 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 15:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            case '6':
                result += 6 * pow(p, value.length - i);
            case '7':
                result += 7 * pow(p, value.length - i);
            case '8':
                result += 8 * pow(p, value.length - i);
            case '9':
                result += 9 * pow(p, value.length - i);
            case 'a':
                result += 10 * pow(p, value.length - i);
            case 'A':
                result += 10 * pow(p, value.length - i);
            case 'b':
                result += 11 * pow(p, value.length - i);
            case 'B':
                result += 11 * pow(p, value.length - i);
            case 'c':
                result += 12 * pow(p, value.length - i);
            case 'C':
                result += 12 * pow(p, value.length - i);
            case 'd':
                result += 13 * pow(p, value.length - i);
            case 'D':
                result += 13 * pow(p, value.length - i);
            case 'e':
                result += 14 * pow(p, value.length - i);
            case 'E':
                result += 14 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        case 16:
        {
            switch (value[i - 1])
            {
            case '0':
                result += 0;
            case '1':
                result += 1 * pow(p, value.length - i);
            case '2':
                result += 2 * pow(p, value.length - i);
            case '3':
                result += 3 * pow(p, value.length - i);
            case '4':
                result += 4 * pow(p, value.length - i);
            case '5':
                result += 5 * pow(p, value.length - i);
            case '6':
                result += 6 * pow(p, value.length - i);
            case '7':
                result += 7 * pow(p, value.length - i);
            case '8':
                result += 8 * pow(p, value.length - i);
            case '9':
                result += 9 * pow(p, value.length - i);
            case 'a':
                result += 10 * pow(p, value.length - i);
            case 'A':
                result += 10 * pow(p, value.length - i);
            case 'b':
                result += 11 * pow(p, value.length - i);
            case 'B':
                result += 11 * pow(p, value.length - i);
            case 'c':
                result += 12 * pow(p, value.length - i);
            case 'C':
                result += 12 * pow(p, value.length - i);
            case 'd':
                result += 13 * pow(p, value.length - i);
            case 'D':
                result += 13 * pow(p, value.length - i);
            case 'e':
                result += 14 * pow(p, value.length - i);
            case 'E':
                result += 14 * pow(p, value.length - i);
            case 'f':
                result += 15 * pow(p, value.length - i);
            case 'F':
                result += 15 * pow(p, value.length - i);
            default:
                cout << "Введите корректное число!" << endl;
                break;
            }
        }
        default:
            cout << "Введите корректную систему счисления!" << endl;
            break;
        }
    }*/
    return result;
}

void checkValue(unsigned int value, string &str)
{
    if (value < 10)
    {
        str += to_string(value);
    }
    else
    {
        switch (value)
        {
        case 10:
            str += "A";
        case 11:
            str += "B";
        case 12:
            str += "C";
        case 13:
            str += "D";
        case 14:
            str += "E";
        case 15:
            str += "F";
        }
    }
}

string checkBase(string base)
{
    if(base == "01" || base == "012" || base == "0123"|| base == "01234" || base == "012345" || base == "0123456" || base == "01234567" || base == "012345678" || base == "0123456789" || base == "0123456789a" || base == "0123456789A" || base == "0123456789ab" || base == "0123456789AB" || base == "0123456789abc" || base == "0123456789ABC" || base == "0123456789abcd" || base == "0123456789ABCD" || base == "0123456789abcde" || base == "0123456789ABCDE" || base == "0123456789abcdef" || base == ("0123456789ABCDEF"))
    {
        return base;
    }
    else
    {
         return "Введите корректную систему счисления";
    }
}

unsigned int pow(unsigned int a, unsigned int b)
{
    unsigned int result = 1;

    for (int i = 0; i < b; ++i)
    {
        result = result * a;
    }

    return result;
}