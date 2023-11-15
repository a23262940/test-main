#include<stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long factorial(unsigned long a){
    if(a==1){
        return 1;
    }else if(a==0){
        return 0;
    }
    else{
        return a * factorial(a - 1);
    }
}

int main(int argc, char *argv[]){
    for(int i=0;i<strlen(argv[1]);i++){
        if((argv[1][i]<'0' || argv[1][i]>'9')){
            printf("%c(%d), Not a Number!",argv[1][i],i+1);
            return 0;
        }
    }
    if(atoi(argv[1])>=20){
        printf("Factorial of 20 is 2432902008176640000");
    }else{
        printf("Factorial of %lu is %lu", atol(argv[1]),factorial(atol(argv[1])));
    }
    return 0;
}