#pragma once

class Router {
  private:
    Router() {}
    ~Router() {}
    Router(Router const&);
    Router& operator= (Router const&);
  public:
    static Router& Instance();
    void main();
};
