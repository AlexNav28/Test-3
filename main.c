#include <stdint.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


typedef struct String {
	uint32_t length;
	char* content;
}String;

String new_String(char* init_contents);
//String plus(String s1, String s2);
//String join(String strs[], int count, String delimenter);

 
String new_String(char* init_contents){
	uint32_t size = strlen(init_contents);
	char* contents = malloc(size+1);
	strcpy(contents, init_contents);
	String r = {size , contents};
	return r;
}

void parenthesize(String *s){

uint32_t len = s->length + 2;

char* new_content = malloc(len + 1);

new_content[0] = '(';
strcpy(new_content + 1,s->content);
new_content[len-1] = ')';
new_content[len] = '\0';

free(s->content);

s->content = new_content;
s->length = len;

}


int main(){
	
	uint32_t size = 100;
	char* input = malloc(size);
	printf("input: ");
	scanf("%s", input);
	//fgets(input, size, stdin);


	String s = new_String(input);
	free(input);
	
	parenthesize(&s);
	printf("%s\n", s.content);
	printf("length=%ld", s.length);
	free(s.content);

	return 0;

}



	
	



