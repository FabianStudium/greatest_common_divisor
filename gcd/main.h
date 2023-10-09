//
//  Header.h
//  gcd
//
//  Created by Fabian Gazzia on 13.09.23.
//

#ifndef Header_h
#define Header_h

#include <stdio.h>
#include <stdlib.h> // for strtol, abs, and EXIT_ constants
#include <math.h>

int gcd(int a, int b);
int parse_input(const char *str);
void check_argument_count(const int argc);

#endif /* Header_h */
