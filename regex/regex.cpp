
#include <iostream>
#include <regex>
#include <fstream>
using namespace std;
int main()
{
    ifstream in;
    in.open("file.cpp");
    const regex r1(R"(\/\/.+\n)");
    const regex r2(R"(\/\*(?:[^\*]+\n)(?:.+\*\/))");
    const regex r3(R"(\/\*.*\*\/)");
    smatch m;
    string asd;
    char* d = new char[1000];
    while (in.is_open() and !in.eof()) {
        in.getline(d,1000,'\n');
        string s(d);
        asd = asd + s;
        asd += '\n';
    }
    cout << asd << endl << "/////////////////////////////////////////" << endl;
    do {
        if (regex_search(asd, m, r1)) {
            string del;
            for (smatch::iterator it = m.begin(); it != m.end(); it++) {
                del = *it;
                string::size_type pos = asd.find(del);
                if (pos != string::npos)
                {
                    asd.erase(pos, del.length());
                }
            }
        }

        if (regex_search(asd, m, r2)) {
            string del;
            for (smatch::iterator it = m.begin(); it != m.end(); it++) {
                del = *it;
                string::size_type pos = asd.find(del);
                if (pos != string::npos)
                {
                    asd.erase(pos, del.length());
                }
            }
        }

        if (regex_search(asd, m, r3)) {
            string del;
            for (smatch::iterator it = m.begin(); it != m.end(); it++) {
                del = *it;
                string::size_type pos = asd.find(del);
                if (pos != string::npos)
                {
                    asd.erase(pos, del.length());
                }
            }
        }
        regex_search(asd, m, r1);
    } while (m.size() != 0);
    cout << asd;
}
