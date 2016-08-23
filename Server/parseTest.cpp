//Test the parsing functionality of the model
#include "ssheet_model.h"
#include <iostream>
//using namespace std;
int main()
{
  ssheet_model sm("dfgsdfg","dfasdfgsdfg");
  std::vector<std::string> printme;
  printme = sm.parse("A22+452345345+a3+-T3@");
  
  for(std::vector<std::string>::iterator it = printme.begin(); it!=printme.end();++it)
    {
      std::cout<<*it<<std::endl;
    }

  printme = sm.parse("A2+A1+a1+v2+23+j23*34534*s");
  for(std::vector<std::string>::iterator it = printme.begin(); it!=printme.end();++it)
    {
      std::cout<<*it<<std::endl;
    }
  return 0;
}
