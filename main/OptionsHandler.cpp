//
// Created by dawid on 23.07.18.
//

#include "OptionsHandler.h"

namespace progOpt = boost::program_options;

void OptionsHandler::declareOptions() {
  mOptionsDescription.add_options()("help", "some help... TODO")
      ("daemon", progOpt::value<bool>(), "on/off daemon mode");

}
OptionsHandler::OptionsHandler(int argumentsCount, char **arguments) {
  declareOptions();
  progOpt::store(progOpt::parse_command_line(argumentsCount, arguments,
                                             mOptionsDescription), mVariablesMap);
  progOpt::notify(mVariablesMap);
}
