/*ssheet_model.h
 *header for the backend server-side spreadsheet model
 * Bharath G., Dylan Noaker
 */
#ifndef SSHEET_MODEL_H
#define SSHEET_MODEL_H
#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "dependency_graph.h"
class ssheet_model
{
 public:
  ssheet_model(std::string fname,std::string version);
  std::string get_version(std::string fname);
  std::set<std::string> get_cells();

  std::string get_cell_contents(std::string name);
  std::set<std::string> set_cell_contents(std::string name,std::string contents);

  bool save();
  std::set<std::string> open(std::string fname);

 private:
  std::set<std::string> parse(std::string in);  
  dependency_graph cellDependency;
  std::map<std::string, std::string> spreadsheet;
  std::string filename;
  std::string version;
  std::set<std::string> formula(std::string name,std::string contents);
  std::set<std::string> getDirectDependents(std::string name);
  std::set<std::string> getCellsToRecalculate(std::string name);
  std::set<std::string> recalculate(std::set<std::string> names);
  bool visit(std::string start,std::string name,std::set<std::string> visited,std::set<std::string> changed);
  std::string toUpper(std::string name);
};
#endif
