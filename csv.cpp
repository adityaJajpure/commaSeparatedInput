#include <vector>
#include <string.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;
struct tokens: std::ctype<char>
{
    tokens(): std::ctype<char>(get_table()) {}

    static std::ctype_base::mask const* get_table()
    {
        typedef std::ctype<char> cctype;
        static const cctype::mask *const_rc= cctype::classic_table();

        static cctype::mask rc[cctype::table_size];
        memcpy(rc, const_rc, cctype::table_size * sizeof(cctype::mask));

        rc[','] = std::ctype_base::space;
        rc[' '] = std::ctype_base::space;
        return &rc[0];
    }
};
typedef struct myStruct{
    char book_name[100];
    char name[100];
    char date[10];
};
int main(){
FILE *ptr = fopen("adi.txt","r");
if(ptr!=NULL)
    {
        char s[300];
        while(fgets(s,300,ptr)!=NULL)
        {
            std::stringstream ss(s);
            ss.imbue(std::locale(std::locale(), new tokens()));
            int flag=1,count=0;
             while (!ss.eof())
                {
                    count++;
                    char temp[50];
                    ss >> temp;
                    //case for print only the book name irodov
                    if(count==1 && strcmp(temp,"Irodov")!=0){break;}
                    cout<<temp<<endl;
                    if(count==3) break;
                }
            //std::istream_iterator<std::string> begin(ss);
            //std::istream_iterator<std::string> end;
            //std::vector<std::string> vstrings(begin, end);
           // cout<<vstrings.begin();
            //int i=0;
            //std::copy(vstrings.begin(), vstrings.end(), myStruct[i].book_name);
        }
    }
    else{
        perror("somya.txt");}
}
