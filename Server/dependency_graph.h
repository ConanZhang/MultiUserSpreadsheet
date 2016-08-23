//dependency_graph.h 
#ifndef DEPENDENCY_GRAPH_H
#define DEPENDENCY_GRAPH_H
#include <iostream>
#include <map>
#include <set>
#include <string.h>
class dependency_graph
{
 public:
  dependency_graph();
  ~dependency_graph();
  int size(); //number of order pairs in graph
  int size(std::string); //the number of dependees for a dependent  
  bool hasDependents(std::string s); //checks if a string has dependents
  bool hasDependees(std::string s); //checks if a string has dependees;
  std::set<std::string> getDependents(std::string s);
  std::set<std::string> getDependees(std::string s);
  void addDependency(std::string s, std::string t);
  void removeDependency(std::string s, std::string t);
  void replaceDependents(std::string s, std::set<std::string> newDependents);
  void replaceDependees(std::string s, std::set<std::string> newDependees);
 
 private:
  //who do I depend on, have dependent as the key and dependees as the value
  std::map<std::string,std::set<std::string> > dependent; 
  //who depends on me, have dependee as the key ad depenents as the value 
  std::map<std::string,std::set<std::string> > dependee;
  void addToDependent(std::string s, std::string t);
  void addToDependee(std::string s, std::string t);
  void removeDependent(std::string s, std::string t);
  void removeDependee(std::string s, std::string t);
};
#endif
