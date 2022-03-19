#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <cassert>

using std::cout; using std::endl;
using std::string; using std::hex;
using std::stringstream;
string hexToASCII(string hex)
{
    // initialize the ASCII code string as empty.
    string ascii = "";
    for (size_t i = 0; i < hex.length(); i += 2)
    {
        // extract two characters from hex string
        string part = hex.substr(i, 2);

        // change it into base 16 and
        // typecast as the character
        char ch = stoul(part, nullptr, 16);

        // add this char to final ASCII string
        ascii += ch;
    }
    return ascii;
}
static inline unsigned int value(char c)
{
    if (c >= '0' && c <= '9') { return c - '0';      }
    if (c >= 'a' && c <= 'f') { return c - 'a' + 10; }
    if (c >= 'A' && c <= 'F') { return c - 'A' + 10; }
    return -1;
}

std::string str_xor(std::string const & s1, std::string const & s2)
{
    assert(s1.length() == s2.length());

    static char const alphabet[] = "0123456789abcdef";

    std::string result;
    result.reserve(s1.length());

    for (std::size_t i = 0; i != s1.length(); ++i)
    {
        unsigned int v = value(s1[i]) ^ value(s2[i]);

        assert(v < sizeof alphabet);

        result.push_back(alphabet[v]);
    }

    return result;
}
int main(){
    string s1 = "your";
    string s2;
string s3="70A20FBD7E209324A979BFE2997A46E61B22749692EB1655FA995D46A9FA654F43C93F2114A21E3E227714580A6790B88BD74F9E09107D8B0EAC";
string s4="7DA30ABD753A8E63FB70BEF1D66340BC0D24748D99EB065FEC804B03F9FB6F5F52D02A731CE31B24617F5B431C2496AA94DA1D865D17778109B3";
    cout << "string: " << s1 << endl;
    cout << "hexval: ";
    for (const auto &item : s1) {
        cout << hex << int(item);
    }
    cout << endl;
    cout<<" "<<str_xor(s3,s4);
    //cout<<str_xor("7468656972","0d0105000b");

//
cout<<"\n";
cout<<hexToASCII(str_xor("796f75","0d0105"));



    return EXIT_SUCCESS;
}
//first we can xor the cipher texts with each other then we can try the most common words in english such as the
//        and xor it with the result of xoring the two messages and when we guess correctly the message we can get the key
//                and break the remain ciphers we can get the key by xorig the plaintext with ciphertext.
//and i made function convert from hextostring
//and function to xor two strings