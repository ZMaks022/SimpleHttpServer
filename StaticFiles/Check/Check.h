//
// CheckStaticFile - find point in string
// CheckAvailabilitySymbols - is cheking available symbols get true if data is valid
// AvailableExt - is cheking extension of static file and get true if extension is valid
//

#ifndef WEBSERVER_CHECK_H
#define WEBSERVER_CHECK_H

#include <string.h>

bool CheckStaticFile (const char* string) noexcept;
bool CheckAvailabilitySymbols (char* string) noexcept;
bool AvailableExt (char* string) noexcept;

#endif //WEBSERVER_CHECK_H
