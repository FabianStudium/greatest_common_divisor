//
//  main.c
//  gcd
//
//  Created by Fabian Gazzia on 13.09.23.
//

#include "main.h"
#include "../../factor/factor/factor.h"

int main(const int argc, const char * argv[]) {
    check_argument_count(argc);

    int a = parse_input(argv[1]);
    int b = parse_input(argv[2]);
    
    int gcd_result = gcd(a, b);
    
    printf("gcd(%d, %d) is %d\n", a, b, gcd_result);
    
    return EXIT_SUCCESS;
}

/*
Wenn man die Angabe nicht lesen kann, kann man die gcd() Funktion auch ohne factor functions schreiben

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
 */

int gcd(int a, int b) {
    int primes_max_a = log2(a);
    int primes_max_b = log2(b);
    
    int *factors_a = (int *)malloc(sizeof(int) * primes_max_a);
    int *factors_b = (int *)malloc(sizeof(int) * primes_max_b);
    //... [Handle memory allocation failure]
    
    calculate_prime_factors(a, factors_a);
    calculate_prime_factors(b, factors_b);
    
    int *primes_a = (int *)malloc(sizeof(int) * primes_max_a);
    int *primes_b = (int *)malloc(sizeof(int) * primes_max_b);
    int *frequencies_a = (int *)malloc(sizeof(int) * primes_max_a);
    int *frequencies_b = (int *)malloc(sizeof(int) * primes_max_b);
    //... [Handle memory allocation failure]
    
    calculate_prime_frequencies(factors_a, primes_a, frequencies_a, primes_max_a);
    calculate_prime_frequencies(factors_b, primes_b, frequencies_b, primes_max_b);
    
    int gcd_result = 1;
    
    for (int i = 0; i < primes_max_a; i++) {
        for (int j = 0; j < primes_max_b; j++) {
            if (primes_a[i] == primes_b[j]) {
                gcd_result *= pow(primes_a[i], fmin(frequencies_a[i], frequencies_b[j]));
            }
        }
    }
    
    free(factors_a);
    free(factors_b);
    free(primes_a);
    free(primes_b);
    free(frequencies_a);
    free(frequencies_b);
    
    return gcd_result;
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
