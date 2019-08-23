//
// Created by user on 2019-08-23.
//

#ifndef WEBSERVER_CHECK_H
#define WEBSERVER_CHECK_H

#include <string.h>

bool CheckStaticFile (const char* string) noexcept;
bool CheckAvailabilitySymbols (char* string) noexcept;
bool AvailableExt (char* string) noexcept;

#endif //WEBSERVER_CHECK_H
