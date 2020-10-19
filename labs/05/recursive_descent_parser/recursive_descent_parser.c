#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>


/***************************
Example:
Grammar:
E -> T | T  + E
T -> int | int * T| ( E ) 
***************************/

char l;

bool E();
bool E_1();
bool E_2();
bool T();
bool T_1();
bool T_2();
bool T_3();

void error(){
	printf("Error\n");
	exit(-1);
}
// Match function
bool match(char t) {
    if (l == t) {
        l = getchar();
		return true;
    }
    else
		error();
}

// Definition of T as per the given production
bool T(){
	if(l == 'i'){
		if(T_1()){
			if(l == '*'){
				if(T_2()){
					return true;
				}else{
					error();
				}
			}else{
				return true;
			}
		}else{
			error();
		}
		
	}else if(l == '('){
		if(T_3()){
			return true;
		}else{
			error();
		}
	}else{
		error();
	}
}

// Definition of T_1 as per the given production
bool T_1() {
    if(l=='i'){
	    if (match('i') && match('n') && match('t'))
		    return true;
	}else{
		return false;
	}
}

// Definition of T_2 as per the given production
bool T_2() {
    if(l=='*'){
        if (match('*') && T())
            return true;
	}else{
		return false;
	}
}

// Definition of T_3 as per the given production
bool T_3() {
    if (l == '(') {
		if(match('(') && E() && match(')'))
			return true;
    }else{
		return false;
	}
}

// Definition of E, as per the given production
bool E() {
    if(E_1()){
		if( l == '+'){
			if(E_2()){
				return true;
			}else{
				error();
			}
		}else{
			return true;
		}
	}else{
		error();
	}
}

// Definition of E_2 as per the given production
bool E_2() {
	if(match('+') && E()){
        return true;
    }else{
		return false;
    }
}

// Definition of E_1 as per the given production
bool E_1() {
	if(T()){
		return true;
    }else{
		return false;
	}
}

int main() {

    do {
        l = getchar();
		// E is a start symbol.
	    E();

    } while (l != '\n' && l != EOF);

    if (l == '\n')
        printf("Parsing Successful\n");
}
