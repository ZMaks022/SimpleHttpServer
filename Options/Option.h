//
// Created by user on 2019-08-23.
//

#ifndef WEBSERVER_OPTION_H
#define WEBSERVER_OPTION_H
#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class Options {
  private:
    string backend;
    string frontend;
    Options() {}
    ~Options() {}
    Options(Options const&);
    Options& operator= (Options const&);
  public:
    static Options& Instance();
    void read();
    string getBackend() const;
    string getFrontend() const;
};

#endif //WEBSERVER_OPTION_H
