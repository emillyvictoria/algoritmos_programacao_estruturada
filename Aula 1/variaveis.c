#include <stdio.h>
#include <stdbool.h>

int main () 
{

    int varint = 0 ;               //"%d"
    float varfloat = 1.1;          //"%f"
    double vardouble = 5.6;        //"%lf"
    char varchar = 'E';            //"%c"
    bool varbool = true;           //"%d"
    long varlong = 1;              //"%d"
    unsigned int varunsigned = 10; //"%u" "%d"
    long long varlonglong = 1;     //"%ld"
    short varshort = 1;            //"%d"

    printf("\n Int = %d", varint);
    printf("\n Float = %f", varfloat);
    printf("\n Double = %lf", vardouble);
    printf("\n Char = %c", varchar);
    printf("\n Boolean = %d", varbool);
    printf("\n Long = %d", varlong);
    printf("\n Long long = %ld", varlonglong);
    printf("\n Short = %d", varshort);
    printf("\n Unsigned = %u", varunsigned);
    printf("\n Unsigned = %u \n varfloat = %f", varunsigned), varfloat;


    return 0;
}