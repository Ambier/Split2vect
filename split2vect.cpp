
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <sstream>
#include <iterator>
#include <vector>

void split2vect(const std::string& strline,std::vector<std::string>& vect,const std::string& sep)
{
    size_t left = 0;
    size_t right = strline.find_first_of(sep);

    while(true)
    {
        if(std::string::npos == right)
        {
            vect.push_back(strline.substr(left));
            return ;
        }

        vect.push_back(strline.substr(left,right-left+1));

        left = right+1;

        right = strline.find_first_of(sep,left);
    }

}
int main(int argc,char* argv[])
{
    std::vector<std::string> fields;

    std::string strline = "chen zu  longchen  ";

    split2vect(strline,fields," ");
    std::cout<<fields.size()<<std::endl;
    std::copy(fields.begin(),fields.end(),std::ostream_iterator<std::string>(std::cout,"\n"));
    return 0;
}
