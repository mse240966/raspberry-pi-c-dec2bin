#include <stdio.h>
#include <stdlib.h>

#include "dec2bin.h"

int main(int argc, char *argv[])
{
    // Validate decimal value argument passed
    if (validArguments(argc) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // Validate decimal argument is valid and pass back value
    DECIMAL decimal;
    if (getDecimalValue(argv[1], &decimal.value) != EXIT_SUCCESS)
        return EXIT_FAILURE;

    // Output binary value
    outputBinaryValue(&decimal);

    return EXIT_SUCCESS;
}

int validArguments(int numberOfArguments)
{
    if (numberOfArguments == 1)
    {
        printf("bin2dec: missing decimal value\n");
        return EXIT_FAILURE;
    }

    if (numberOfArguments > 2)
    {
        printf("bin2dec: invalid number of arguments\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

int getDecimalValue(char *argumentValue, UINT16 *decimalValue)
{
    const unsigned short int MAX_VALUE = 65535;

    int integerValue = atoi(argumentValue);
    if (integerValue < 1 || integerValue > MAX_VALUE || (double)integerValue != atof(argumentValue))
    {
        printf("bin2dec: invalid integer decimal value, needs to be between 1 and %d\n", MAX_VALUE);
        return 1;
    }

    *decimalValue = integerValue;

    return EXIT_SUCCESS;
}

void outputBinaryValue(DECIMAL *decimal)
{
    const char OUTPUT[] = "%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n";

    printf(OUTPUT,
        decimal->bits.sixteen,
        decimal->bits.fifteen,
        decimal->bits.fourteen,
        decimal->bits.thirteen,
        decimal->bits.twelve,
        decimal->bits.eleven,
        decimal->bits.ten,
        decimal->bits.nine,
        decimal->bits.eight,
        decimal->bits.seven,
        decimal->bits.six,
        decimal->bits.five,
        decimal->bits.four,
        decimal->bits.three,
        decimal->bits.two,
        decimal->bits.one);
}
