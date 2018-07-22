//
// Created by dawid on 23.07.18.
//

#pragma once

#include <boost/program_options.hpp>

class OptionsHandler {
 private:
  void declareOptions();

  boost::program_options::options_description mOptionsDescription;
  boost::program_options::variables_map mVariablesMap;

 public:
  OptionsHandler(int argumentsCount, char **arguments);
};


