//dependency_graph.cpp 
#include "dependency_graph.h"

dependency_graph::dependency_graph()
{
}
dependency_graph::~dependency_graph()
{
}
int dependency_graph::size() //number of order pairs in graph
{
  int count = 0;
  for(std::map<std::string,std::set<std::string> >::iterator 
      it=dependent.begin();
      it!=dependent.end();
      ++it)
    {
      count = count + it->second.size();
    }
  return count;
}
int dependency_graph::size(std::string s) //the number of dependees for a dependent
{
  if(dependent.find(s) != dependent.end())
    {
      return dependent[s].size();
    }
  return 0;
}
bool dependency_graph::hasDependents(std::string s) //checks if a string has dependents
{
  if(dependee.find(s) != dependee.end())
    return dependee[s].size() != 0;
  return false;
}
bool dependency_graph::hasDependees(std::string s) //checks if a string has dependees
{
  if(dependent.find(s) != dependent.end())
    return dependent[s].size() != 0;
}

std::set<std::string> dependency_graph::getDependents(std::string s)
{
 
  if(dependee.find(s) != dependee.end())
    {
      std::set<std::string> temp(dependee[s]);
      return temp;
    }
  std::set<std::string> t;
  return t;
}

std::set<std::string> dependency_graph::getDependees(std::string s)
{
  if(dependent.find(s) != dependent.end())
    {
      std::set<std::string> temp(dependent[s]);
      return temp;
    }
  std::set<std::string> t;
  return t;
}

void dependency_graph::addDependency(std::string s, std::string t)
{
  addToDependent(s,t);
  addToDependee(s,t);
}
void dependency_graph::removeDependency(std::string s, std::string t)
{
  removeDependent(s,t);
  removeDependee(s,t);
}
void dependency_graph::replaceDependents(std::string s, std::set<std::string> newDependents)
{
  if(dependee.find(s) != dependee.end())
    {
      //  std::map<std::string,std::set<std::string> >::iterator it = dependee.find(s);
      std::set<std::string> temp(dependee[s]);
      
      for (std::set<std::string>::iterator it=temp.begin(); it!=temp.end(); ++it)
	{
	  std::cout<<s<<"_"<<*it<<std::endl;
	  removeDependency(s,*it);
	}
     for (std::set<std::string>::iterator nw=newDependents.begin(); nw!=newDependents.end(); ++nw)
       {
	 std::cout<<s<<"_"<<*nw<<std::endl;
	 addDependency(s,*nw);
       }
    } 
}
void dependency_graph::replaceDependees(std::string s, std::set<std::string> newDependees)
{
    if(dependent.find(s) != dependent.end())
    {
      //  std::map<std::string,std::set<std::string> >::iterator it = dependee.find(s);
      std::set<std::string> temp(dependent[s]);
      
      for (std::set<std::string>::iterator it=temp.begin(); it!=temp.end(); ++it)
	{
	  std::cout<<*it<<"_"<<s<<std::endl;
	  removeDependency(*it,s);
	}

    } 

    for (std::set<std::string>::iterator nw=newDependees.begin(); nw!=newDependees.end(); ++nw)
      {
	// std::cout<<*nw<<"_"<<s<<std::endl;
	 addDependency(*nw,s);
      }    
}
void dependency_graph::addToDependent(std::string s, std::string t)
{
  std::set<std::string> temp;
  
   if(dependent.find(t) != dependent.end())
     dependent[t].insert(s);
   else
     {
       temp.insert(s);
       dependent.insert(std::pair<std::string,std::set<std::string> >(t,temp));
     }
}
void dependency_graph::addToDependee(std::string s, std::string t)
{
    std::set<std::string> temp;
  
   if(dependee.find(s) != dependent.end())
     dependee[s].insert(t);
   else
     {
       temp.insert(t);
       dependee.insert(std::pair<std::string,std::set<std::string> >(s,temp));
     }
}
void dependency_graph::removeDependent(std::string s, std::string t)
{
  if(dependent.find(t) != dependent.end())
    {
      dependent[t].erase(s);
      if(!(dependent[t].size()!= 0))
	{
	  dependent.erase(t);
	}
    }
}
void dependency_graph::removeDependee(std::string s, std::string t)
{
    if(dependee.find(s) != dependee.end())
    {
      dependee[s].erase(t);
      if(!(dependee[s].size()!= 0))
	{
	  dependee.erase(s);
	}
    }
}
