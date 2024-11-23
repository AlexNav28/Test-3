#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>


typedef struct String {
	uint32_t size;
	char* content;
}String;


String new_String(char *s){
	uint32_t new_size = strlen(s);
	char* new_content = malloc(new_size + 1);
	strcpy(new_content, s);
	String r = {new_size, new_content};
	return r;
}

//String append1(char *copy){




//}




void add_String(String *s, uint32_t count){


	uint32_t len = s->size * count; 
	char* copy = malloc(len+1);
	//Struct copy = new_String(&s);

	strcpy(copy, s->content);
	for(uint32_t i = 0; i < count; i++){
	strcat(copy, s->content);
	}
	copy[len] = '\0';	

	free(s->content);
	s->content = copy;
	s->size = len;

}


int mian(){
	String test = new_String("hello");
	printf("%s", test.content);

	add_String(&test,3);
	printf("%s", test.content);

	free(test.content);
	
	return 0;
}
