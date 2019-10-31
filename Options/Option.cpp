//
// Class Options read option from config file and then get this information other components
//

#include "Option.h"

Options& Options::Instance() {
  static Options s;
  return s;
}

void Options::read() {
  ifstream f("Configs/hosts.config");
  f >> backend;
  f >> frontend;
}

string Options::getBackend() const {
  return backend;
}

string Options::getFrontend() const {
  return frontend;
}
