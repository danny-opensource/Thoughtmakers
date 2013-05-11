#include<iostream>
#include "../include/Location.h"
#include "../include/location_mtd_proto.h"
#include<fstream>
#include<string>

using namespace std;
string files[255];
int main()
{
readLocationFiles();
buildBST();
return 0;
}

void readLocationFiles()
{
string line;
int line_index = 0;
ifstream locFile;
locFile.open("../../test/LOC_INFO.txt");
if(locFile.is_open())
{
while(!locFile.eof())
{
getline(locFile,line);
cout<<line<<endl;
files[line_index++] = line;
}
locFile.close();
}
else
{
cout<<"Unable to open file"<<endl;
}
}

void buildBST()
{
int index=0;
while(!files[index].empty())
{
insertNode(root,files[index]);
cout<<files[index]<<endl;
index++;
}
}

