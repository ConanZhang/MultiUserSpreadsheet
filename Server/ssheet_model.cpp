/* ssheet_model
*implementation of backend server-side spreadsheet
* Bharath Gunasekaran Dylan Noaker
*/
#include "ssheet_model.h"
ssheet_model::ssheet_model(std::string fname,std::string version)
{
  filename = fname;
}
std::string ssheet_model::get_version(std::string fname)
{
  
}
std::set<std::string> ssheet_model::get_cells()
{
  std::set<std::string> temp;
  for(std::map<std::string,std::string>::iterator it = spreadsheet.begin(); it != spreadsheet.end(); ++it)
    {
      if(spreadsheet[it->first].compare("\n") != 0)
	temp.insert(it->first);
    }
  return temp;
  
}

std::string ssheet_model::get_cell_contents(std::string name)
{
  std::string temp = toUpper(name);

  if(spreadsheet.find(temp)!= spreadsheet.end())
    {
      std::string t = spreadsheet[temp];
      return t;
    }
  else
  {
      std::string s;
      return s;
  }
}
std::set<std::string> ssheet_model::set_cell_contents(std::string name,std::string contents)
{
  
  std::string temp = toUpper(name);
  std::set<std::string> returnset;

  if(contents == "\n")
  {
      returnset.insert(temp);
      spreadsheet.erase(temp);
  }
  //checking if contents empty 
  if(contents.compare("\n") != 0)
    {
    //checks if the cell exist iin the map
      if(spreadsheet.find(temp)== spreadsheet.end())
	{
        //checking if the content is an equation
          if(contents.find("=") == 0)
          {
              returnset = formula(temp,contents);
          }
          // take care of the case that the content is a double or string
          else 
          {
              spreadsheet.insert(std::pair<std::string,std::string>(temp,contents));
              //inserting the cell name into a return set
              returnset.insert(temp);
          }

	}
      else
      {
          if(contents.find("=") == 0)
            {
                returnset = formula(temp,contents);
            }
          else
          {
              spreadsheet[temp] = contents;
              returnset.insert(temp);
          }
            
      }

    }
 return returnset;
  
}

std::set<std::string> ssheet_model::formula(std::string name,std::string contents)
{
  std::string tempCont;
  // std::spreadsheet
  if(spreadsheet.find(name)== spreadsheet.end())
    {
      spreadsheet.insert(std::pair<std::string,std::string>(name,contents));
      std::cout << "Normalized." << std::endl;
    }
  else
    {
      tempCont = spreadsheet[name];
      spreadsheet[name] = contents;
    }
  std::set<std::string> s = parse(contents);
   cellDependency.replaceDependees(name,s);

  //checking for circular dependency
   try
     {
       s = getCellsToRecalculate(name);
     }

   catch (int e)
     {
       std::set<std::string> t;   
       cellDependency.replaceDependees(name,t);   
       spreadsheet[name] = tempCont;
       if(tempCont.find("=") == 0)
	 {
	   s = parse(tempCont);
	   cellDependency.replaceDependees(name,s);
	 }
       throw e;
     }

   //need to change what is returned 

   return s;
  
}

bool ssheet_model::save()
{

  std::string name;
  std::string content;
  std::ofstream myfile(filename.c_str(),std::ofstream::out);
  if(myfile.is_open())
    {
      std::set<std::string> names = get_cells();
      for(std::set<std::string>::iterator it = names.begin(); it != names.end(); ++it)
	{
	  content = get_cell_contents(*it);
	  myfile << "cell " << *it <<" "<<content<<"\n";
	}
      myfile.close();
      return true;
    }
  return false;
}

std::set<std::string> ssheet_model::open(std::string fname)
{
  std::set<std::string> s;  
  std::string name;
  std::string content;
  std::string line;
  std::ifstream myfile(fname.c_str(),std::ifstream::in);
  if(myfile.is_open())
    {
      while(getline(myfile,line))
	{
	      std::stringstream ss(line);
              std::string test;
              ss >> test;
	      ss >> name;
	      ss >> content;
	      set_cell_contents(name,content);
	      s.insert(line);
	    
	}
      
      myfile.close();
    }
  else
  std::cout<<"File is not open"<<std::endl;
  return s; 
}
/*
  Preconditon all equations passed in are valid. 
 */
std::set<std::string> ssheet_model::parse(std::string in)
{
  std::string loopme(in);
  std::set<std::string> returnme;  
  for(int i = 0; i<loopme.length();i++)
    {
      char curr = loopme[i];
      int switchme = curr;
      std::string token;
      switch(switchme)
	{
	  //if the char is a letter
	case 64 ... 91:
	case 96 ... 123:
	
	  token.append(1,loopme[i++]);

	  if(loopme[i]<58&&loopme[i]>47)
	    {  token.append(1,loopme[i++]);
	
	    }
	  if(loopme[i]<58&&loopme[i]>47)
	    {  token.append(1,loopme[i++]);
	 
	    }
	  if(token.length()==1||token.length()>=4)
	    break;
	  
	  returnme.insert(toUpper(token));
	  break;
	default:
	  break;
	}
    }
  return returnme;
  //((switchme>64&&switchme<91)||(switchme>96&&switchme<123)):
}
std::string ssheet_model::toUpper(std::string name)
{
  for(int i = 0; i < name.length(); i++)
    {
      if( name[i] > 96 && name[i]<123) 
	{
	  name[i]-=32;
	}
    }
  return name;
}
std::set<std::string>  ssheet_model::getDirectDependents(std::string name)
{
  
  if(name.compare("") != 0)
    {
      std::string temp = toUpper(name);
      return cellDependency.getDependents(temp);
    }
}
std::set<std::string> ssheet_model::getCellsToRecalculate(std::string name)
{
  std::set<std::string> t;
  t.insert(name);
  return recalculate(t);
}
std::set<std::string>  ssheet_model::recalculate(std::set<std::string> names)
{
  std::set<std::string> changed;
  std::set<std::string> visited;
  for(std::set<std::string>::iterator it = names.begin(); it != names.end(); ++it)
    {
      if((visited.find(*it) != names.end()))
	{
	  visit(*it,*it,visited,changed);
	}
    }
  return changed;
}
bool  ssheet_model::visit(std::string start,std::string name,std::set<std::string> visited,std::set<std::string> changed)
{
  visited.insert(name);
  std::set<std::string> t = getDirectDependents(name);
  for(std::set<std::string>::iterator it = t.begin(); it != t.end(); ++it)
    {
      if(start.compare(*it) == 0)
	throw 20;
      else if(visited.find(*it) == visited.end())
	{
	  visit(start,*it,visited,changed);
	}
    }
  changed.insert(name);
  return true;
}

