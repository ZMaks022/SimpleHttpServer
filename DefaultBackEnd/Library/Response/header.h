#pragma once
#include <stdio.h>

namespace Server {

  class Response {
    private:
      char Body[8096];
      Response() {}
      ~Response() {}
      Response(Response const&);
      Response& operator= (Response const&);
    public:
      static Response& Instance();
      void write(const char* str);
      void header();
  };

};
