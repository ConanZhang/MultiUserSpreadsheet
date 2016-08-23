#include "ssheet_model.h"
using namespace std;
int main()
{
  /*
  {
    ssheet_model sm("file","file");
    string expected,actual;
    //cell c;
    sm.set_cell_contents("a2","5");
    actual =  sm.get_cell_contents("a2");
    expected = "5";
    bool pass = expected==actual?true:false;
    if(!pass)
      cout<<"Failed Test one: expected "<<expected<<"got" << actual;
  }
  {
    ssheet_model sm("file","file");
    string expected,actual;
    //cell c;
    sm.set_cell_contents("a2","=a1+5");
    actual =  sm.get_cell_contents("a2");
    expected = "=a1+5";
    bool pass = expected==actual?true:false;
    if(!pass)
      cout<<"Failed Test two: expected "<<expected<<"got" << actual;
  } 

  {
    ssheet_model sm("file","file");
    string expected,actual;
    //cell c;
    sm.set_cell_contents("a2","=a1+a3+1e+45");
    actual =  sm.get_cell_contents("a2");
    expected = "=a1+a3+1e+45";
    bool pass = expected==actual?true:false;
    if(!pass)
      cout<<"Failed Test one: expected "<<expected<<"got" << actual;
  }
  */

  {
    ssheet_model sm("file","file");
    sm.set_cell_contents("a2","=a1+1");
    sm.set_cell_contents("a1","=sdf");
    sm.set_cell_contents("a3","3");
    sm.set_cell_contents("a1","4");
   
  }
  /*
  {
    ssheet_model sm("file","file");
    int expected,actual;
    expected = 20;
    //cell c;
    bool passed =false;    
    try
      {
	sm.set_cell_contents("a2","=a1+a2");
      }
    catch (int e)
      {
	actual=e;
      }
    if(expected==actual)
      passed = true;
    if(!passed)
      cout<<"Failed Test three: expected "<<expected<<"got" << actual;
  }
   {
    ssheet_model sm("file","file");
    string expected,actual;
    expected = "5";
    //cell c;
    bool passed =false;    
	sm.set_cell_contents("a2","5");
    try
      {
	sm.set_cell_contents("a2","=(a1+a2)");
      }
    catch (int e)
      {
      }
    actual = sm.get_cell_contents("a2");
    if(expected==actual)
      passed = true;
    if(!passed)
      cout<<"Failed Test three: expected "<<expected<<"got" << actual;
  }
*/
   {
     ssheet_model sm("file","file");
     sm.set_cell_contents("a2","5");
     sm.set_cell_contents("a1","5");
     sm.set_cell_contents("a3","5");
     sm.set_cell_contents("a4","5");
     sm.set_cell_contents("a5","5");
     sm.set_cell_contents("a6","5");
     sm.set_cell_contents("a7","5");
     sm.set_cell_contents("a8","5");
     sm.set_cell_contents("a9","5");
     if(!sm.save())
       cout<<"file could not be opened"<<endl;
   }
/*
   {
     std::string content;
     ssheet_model sm("file","file");
     std::set<std::string> sp = sm.open("file");
     //   sm.open("file");
     std::set<std::string> names = sm.get_cells();
     cout<<"sp memory after open"<<endl;
     for(std::set<std::string>::iterator it = names.begin(); it != names.end(); ++it)
       {
	  content = sm.get_cell_contents(*it);
	  cout << *it <<" "<<content<<endl;
       }
     cout<<"open returned"<<endl;
     for(std::set<std::string>::iterator it = sp.begin(); it != sp.end(); ++it)
       {
	 
	  cout << *it <<endl;
       }
     
   }
  */
}
