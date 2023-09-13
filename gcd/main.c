//
//  main.c
//  gcd
//
//  Created by Fabian Gazzia on 13.09.23.
//

#include "main.h"

int main(const int argc, const char * argv[]) {
    check_argument_count(argc);

    int a = parse_input(argv[1]);
    int b = parse_input(argv[2]);
    
    int gcd_result = gcd(a, b);
    
    printf("gcd(%d, %d) is %d\n", a, b, gcd_result);
    
    return EXIT_SUCCESS;
}

int gcd(int a, int b) {
    // Take absolute values to handle negative numbers
    a = abs(a);
    b = abs(b);

    // Special case: GCD of 0 and 0 is undefined
    if (a == 0 && b == 0) {
        fprintf(stderr, "GCD of 0 and 0 is undefined.\n");
        return EXIT_FAILURE;
    }
    
    int temp_b;
    
    while (b > 0) {
        temp_b = b;
        b = a % b;
        a = temp_b;
    }
    
    return a;
}

// Source: ChatGPT
int parse_input(const char *str) {
    char *endptr;
    /*
     The function strtol stands for "string to long". It attempts to convert a string to a long integer.
     The first argument (str) is the string you want to convert.
     The second argument (&endptr) is a pointer to a character pointer. strtol sets endptr to point to the first character in the string that it couldn't convert. If the entire string is a valid integer, endptr will point to the null terminator ('\0') of the string.
     The third argument (10) specifies the base of the conversion. In this case, we're using base 10, which means we're converting a decimal number.
     */
    int value = (int) strtol(str, &endptr, 10); // typecasting bc strtol generally return type long
    
    if (*endptr != '\0') {
        fprintf(stderr, "Invalid input: %s is not a whole number.\n", str);
        return EXIT_FAILURE;
    }

    return value;
}

void check_argument_count(const int argc) {
    if(argc != 3) {
        fprintf(stderr, "Please provide two whole numbers.\n");
        exit(EXIT_FAILURE);
    }
}
