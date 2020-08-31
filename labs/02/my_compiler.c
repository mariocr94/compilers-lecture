#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char **argv){
    if (argc != 2){
        printf("Please use the following notation:\n");
        printf("./my_compiler <file.c>\n");
        return 0;
    }

    FILE *fp = fopen(argv[1], "r");
    
    int curlyBrackets[100] = {0};
    int parenthesis[100] = {0};
    int brackets[100] = {0};
    int curlyCounter = 0;    
    int parenthesisCounter = 0;
    int bracketsCounter = 0;
    int dQuoteCounter = 0;
    int sQuoteCounter = 0;

    char c;

    if (fp == NULL){
        printf("Could not open file.");
        return 0;
    }
        

    while ((c = fgetc(fp)) != EOF)
    {
        if (c == '/'){
            if(c = fgetc(fp) == '/'){
                while ((c = fgetc(fp)) != '\n'){

                }
            }
        }
        switch(c){
            case '{':
                curlyBrackets[curlyCounter] = 1;
                // printf("Curly in: index: %i, value: %i\n", curlyCounter, curlyBrackets[curlyCounter]);
                curlyCounter++;
                break;


            case '}':
                curlyCounter--;
                if(curlyCounter <0){
                    printf("There is a missing {.\n");
                    break;
                }
                curlyBrackets[curlyCounter] = 0;
                // printf("Curly out: index: %i, value: %i\n", curlyCounter, curlyBrackets[curlyCounter]);
                break;


            case '(':
                parenthesis[parenthesisCounter] = 1;
                // printf("Parenthesis in: index: %i, value: %i\n", parenthesisCounter, parenthesis[parenthesisCounter]);
                parenthesisCounter++;
                break;

            case ')':
                parenthesisCounter--;
                if(parenthesisCounter <0){
                    printf("There is a missing (.\n");
                    break;
                }
                parenthesis[parenthesisCounter] = 0;
                // printf("Parenthesis out: index: %i, value: %i\n", parenthesisCounter, parenthesis[parenthesisCounter]);
                break;

            case '[':
                brackets[bracketsCounter] = 1;
                // printf("Curly in: index: %i, value: %i\n", curlyCounter, curlyBrackets[curlyCounter]);
                bracketsCounter++;
                break;

            case ']':
                bracketsCounter--;
                if(bracketsCounter <0){
                    printf("There is a missing [.\n");
                    break;
                }
                brackets[bracketsCounter] = 0;
                // printf("Curly out: index: %i, value: %i\n", curlyCounter, curlyBrackets[curlyCounter]);
                break;

            case '"':
                // printf("Parenthesis in: index: %i, value: %i\n", parenthesisCounter, parenthesis[parenthesisCounter]);
                dQuoteCounter++;
                break;
            case '\'':
                // printf("Parenthesis in: index: %i, value: %i\n", parenthesisCounter, parenthesis[parenthesisCounter]);
                sQuoteCounter++;
                break;
        }      
        
    }

    bool flag = false;
    for(int i = 0; i < 100; i++){
        if(curlyBrackets[i] == 1){
            printf("Unbalanced braces.\n", i);
            flag = true;
        }
        if(parenthesis[i] == 1){
            printf("Unbalanced parenthesis.\n");
            flag = true;
        }
        if(brackets[i] == 1){
            printf("Unbalanced brackets.\n", i);
            flag = true;
        }
    }
    if(dQuoteCounter%2 == 1){
        printf("Unbalanced double quotation marks.\n");
        flag = true;
    }
    if(sQuoteCounter%2 == 1){
        printf("Unbalanced single quotation marks.\n");
        flag = true;
    }

    if(!flag){
        printf("There are no errors.\n");
    }

    fclose(fp);
    return 0;
}

