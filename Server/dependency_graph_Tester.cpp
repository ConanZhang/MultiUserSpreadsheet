#include "dependency_graph.h"

using namespace std;

int main()
{
  cout<<"Testing"<<endl;
  //empty dg
 cout<<"Test 1"<<endl;
  dependency_graph dg;
  cout<<dg.size()<<endl;
  dg.addDependency("a","b");
  cout<<dg.size()<<endl;
  dg.addDependency("a","b");
  dg.addDependency("a","B");
  cout<<dg.size()<<endl;
  std::set<std::string> set;
  set.insert("c");
  set.insert("5");
  set.insert("b");

  dg.replaceDependents("a",set);
  cout<<"Deee\n"<<endl;
  dg.replaceDependees("a",set);
}
