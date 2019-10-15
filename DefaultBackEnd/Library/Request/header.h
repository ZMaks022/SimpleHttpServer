#pragma once
#include <stdio.h>
#include "../Response/header.h"

namespace Server {

  class Request {
    private:
      char Body[8096];
      char* method;
      char* url;
      Request() {}
      ~Request() {}
      Request(Request const&);
      Request& operator= (Request const&);
    public:
      static Request& Instance();
      void read();
      char* getMethod();
      char* getUrl();
  };

};
