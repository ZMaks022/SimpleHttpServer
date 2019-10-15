#include "Library/Request/header.h"
#include "Library/Response/header.h"
#include "Library/ReadFile/header.h"
#include "Library/Router/header.h"

using namespace Server;

int main() {
  Request& request = Request::Instance();
  Response& response = Response::Instance();
  request.read();
  response.header();

  ReadFile("../DefaultFrontEnd/index.html");

  return 0;
}
