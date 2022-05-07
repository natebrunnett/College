/*Nathan Brunnett
Lab 1 C++ 
---SOLVED---
Convert Morse.bin to it's decrypted message by reading file in binary mode
After retrieving a string, the string was then translated to hexadecimal
after which each hexadecimal character was translated to it's binary form.
From binary -> Morse Code -> English


*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <stdio.h>
#include <ctype.h>
#include <vector>

#pragma warning(disable:4996)

using namespace std;

/*necessarey*/

string ToHex(const string& s, bool upper_case)
    {
	    ostringstream ret;

    for (string::size_type i = 0; i < s.length(); ++i)
        ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << (int)s[i] << " ";

	return ret.str();
}


// necessary
void CBinaryFiles(string sfile, std::vector<std::string> & hexDec)
{
    ifstream::pos_type size;
    char* memblock;

    ifstream file(sfile, ios::in | ios::binary | ios::ate);
    if (file.is_open())
    {
        size = file.tellg();
        memblock = new char[size];
        file.seekg(0, ios::beg);
        file.read(memblock, size);
        file.close();

        //cout << "the complete file content is in memory" << endl;

        std::string tohexed = ToHex(std::string(memblock, memblock + size), true);
        //std::cout << tohexed << std::endl;

        std::cout << "Hexadecimal translation successful!" << endl;


        //store each translated hexadecimal in a vector of strings
        string temp;
        for (int a = 0; a < tohexed.length(); a++)
        {
            if (isspace(tohexed.at(a)))
            {
                hexDec.push_back(temp);
                temp.clear();
            }
            else
                temp.push_back(tohexed.at(a));
        }
        
        

    }
}

void main()
{
    //hexadecimal string
    std::vector<std::string>hexDec;
	CBinaryFiles("Morse.bin", hexDec);
    
    //used to read each object in vector of hexadecimals
    int i = 0;
    char hexDecNum[10];

    string bits;
    
    for (int q = 0; q < hexDec.size(); q++)
    {
        //cout << "hexDec.at(" << q << ") = " << hexDec.at(q) << endl;
        

        //clear the char[] before use
        for (int a = 0; a < 10; a++)
        {
            hexDecNum[a] = NULL;
        }

        strcpy(hexDecNum, hexDec.at(q).c_str());

        /*
        
        for (int a = 0; a < 10; a++)
        {
            std::cout << hexDecNum[a];
        }

        */ 

       // std::cout << "Equivalent Binary Value = ";
        i = 0;
        while (hexDecNum[i])
        {
            switch (hexDecNum[i])
            {
            case '0':
                //cout << "0000";
                bits += "0000";
                break;
            case '1':
               // cout << "0001";
                bits += "0001";
                break;
            case '2':
              //  cout << "0010";
                bits += "0010";
                break;
            case '3':
               // cout << "0011";
                bits += "0011";
                break;
            case '4':
               // cout << "0100";
                bits += "0100";
                break;
            case '5':
               // cout << "0101";
                bits += "0101";
                break;
            case '6':
                //cout << "0110";
                bits += "0110";
                break;
            case '7':
               // cout << "0111";
                bits += "0111";
                break;
            case '8':
                //cout << "1000";
                bits += "1000";
                break;
            case '9':
               // cout << "1001";
                bits += "1001";
                break;
            case 'A':
            case 'a':
               // cout << "1010";
                bits += "1010";
                break;
            case 'B':
            case 'b':
               // cout << "1011";
                bits += "1011";
                break;
            case 'C':
            case 'c':
              //  cout << "1100";
                bits += "1100";
                break;
            case 'D':
            case 'd':
             //   cout << "1101";
                bits += "1101";
                break;
            case 'E':
            case 'e':
            //    cout << "1110";
                bits += "1110";
                break;
            case 'F':
            case 'f':
                //error prone,
                //cout << "1111";
                break;
            default:
                cout << "--Invalid Hex Digit (" << hexDecNum[i] << ")--";
            }
            i++;
        }
    }

    std::cout << "Hexadecimal to Binary successful " << endl;
    //std::cout << "Bits = " << bits << endl;


    std::vector<char>decrypted;
    string binary;

    for (int w = 0; w < bits.length(); w++)
    {
        binary = bits.at(w); w++;
        binary += bits.at(w);

        if (binary == "00")
        {
            //do nothing
            //cout << binary << " = letter space" << endl;
            decrypted.push_back('L');
            //L for letter space
        }
        else if (binary == "01")
        {
            decrypted.push_back('-');
            //cout << binary << " = -" << endl;
        }
        else if (binary == "10")
        {
            decrypted.push_back('.');
            //cout << binary << " = ." << endl;
        }
        else if (binary == "11")
        {
            decrypted.push_back(' ');
           // cout << binary << " = \' \'" << endl;
        }
       
    }
    cout << "translation to morse code complete!" << endl;
    std::cout << "Morse Code string = " << endl;

    for (int q = 0; q < decrypted.size(); q++)
    {
        cout << decrypted.at(q);
    }

    std::cout << endl;


    string message;
    string currentChar;

    for (int i = 0; i < decrypted.size(); i++)
    {
        currentChar += decrypted.at(i);

        if (decrypted.at(i) == ' ')
        {
            message += " ";
            currentChar.clear();
            continue;
        }
        
        
        if (decrypted.at(i) == 'L')
        {
            currentChar.pop_back();
            //std::cout << "currentChar = " << currentChar << endl;
            if (currentChar == ".-")
                message += "A";
            if (currentChar == "-...")
                message += "B";
            if (currentChar == "-.-.")
                message += "C";
            if (currentChar == "-..")
                message += "D";
            if (currentChar == ".")
                message += "E";
            if (currentChar == "..-.")
                message += "F";
            if (currentChar == "--.")
                message += "G";
            if (currentChar == "....")
                message += "H";
            if (currentChar == "..")
                message += "I";
            if (currentChar == ".---")
                message += "J";
            if (currentChar == "-.-")
                message += "K";
            if (currentChar == ".-..")
                message += "L";
            if (currentChar == "--")
                message += "M";
            if (currentChar == "-.")
                message += "N";
            if (currentChar == "---")
                message += "O";
            if (currentChar == ".--.")
                message += "P";
            if (currentChar == "--.-")
                message += "Q";
            if (currentChar == ".-.")
                message += "R";
            if (currentChar == "...")
                message += "S";
            if (currentChar == "-")
                message += "T";
            if (currentChar == "..-")
                message += "U";
            if (currentChar == "...-")
                message += "V";
            if (currentChar == ".--")
                message += "W";
            if (currentChar == "-..-")
                message += "X";
            if (currentChar == "-.--")
                message += "Y";
            if (currentChar == "--..")
                message += "Z";
            if (currentChar == ".-.-")
                message += "A";
            if (currentChar == "---.")
                message += "O";
            if (currentChar == "..--")
                message += "U";
            if (currentChar == "----")
                message += "Ch";
            if (currentChar == "-----")
                message += "0";
            if (currentChar == ".----")
                message += "1";
            if (currentChar == "..---")
                message += "2";
            if (currentChar == "...--")
                message += "3";
            if (currentChar == "....-")
                message += "4";
            if (currentChar == ".....")
                message += "5";
            if (currentChar == "-....")
                message += "6";
            if (currentChar == "--...")
                message += "7";
            if (currentChar == "---..")
                message += "8";
            if (currentChar == "----.")
                message += "9";
            if (currentChar == ".-.-.-")
                message += ".";
            if (currentChar == "--..--")
                message += ",";
            if (currentChar == "..--..")
                message += "?";
            if (currentChar == "..--.")
                message += "!";
            if (currentChar == "---...")
                message += ":";
            if (currentChar == ".-..-.")
                message += "\"";
            if (currentChar == ".----.")
                message += "\'";
            if (currentChar == "-...-")
                message += "=";
            currentChar.clear();
            continue;
        }
   
    }
   
    std::cout << "Message = " << message << endl;
}

