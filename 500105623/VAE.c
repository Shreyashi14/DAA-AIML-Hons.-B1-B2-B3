#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100 

int top = -1 ;
char stack[MAX] ;
void push(char) ;
char pop() ;
int isEmpty() ;
int isFull() ;
int check_balanced(char*) ;
int match_char(char , char) ;   

int main(){
    char expr[MAX] ;
    int balanced ;
    printf("Enter the algebraic expression: ") ;
    gets(expr) ;
    
    balanced = check_balanced(expr) ;
    if(balanced == 1)
        printf("\nThe expression is valid!") ;
    else   
        printf("\nThe expression is invalid") ;

    return 0 ; 
}

int match_char(char a , char b ){
    if(a == '[' && b == ']')
        return 1 ;
    if(a == '(' && b == ')')
        return 1 ;
    if(a == '{' && b =='}')
        return 1 ;
    return 0 ;            
}

int check_balanced(char* s){
    int i ; char temp ;
    for(i = 0 ; i<strlen(s) ; i++){
         if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            push(s[i]) ;    

         if (s[i] == ')' || s[i] == ']' || s[i] == '}'){
            if(isEmpty()){
                printf("Right brackets are more than the left brackets\n") ;
                return 0 ;
            }
            else{
                    temp = pop() ; 
                    if(!match_char(temp , s[i])) 
                        printf("Invalid expression: Mismatched Brackets") ;
            }
         }   
    }
    if(isEmpty())
        printf("Brackets are well balanced!");

    return 1 ;
}

void push(char c ){
    if(isFull()){
        printf("stack overflow!");
        exit(1) ;
    }
    top++ ;
    stack[top] = c ;
}

char pop(){
    char c ;
    if(isEmpty()){
        printf("stack underflow!") ;
        exit(1) ;
    }
    c = stack[top] ;
    top-- ;
    return c ;
}

int isEmpty(){
    if(top == -1)
        return 1 ;
    else    
        return 0 ;    
}

int isFull(){
    if(top == MAX-1)
        return 1 ;
    else 
        return 0 ;    
}