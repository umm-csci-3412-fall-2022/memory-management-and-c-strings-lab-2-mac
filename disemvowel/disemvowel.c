#include <stdlib.h>
#include <string.h>


#include "disemvowel.h"


int vowelCounter(char *str){
        int i, numVowels=0;
	char *vowels = (char*)calloc(11, sizeof(char));
  strcpy(vowels, "aeiouAEIOU\0");
  int len = strlen(str);
        for(i=0; i<len; ++i){
                if(strchr(vowels, str[i]) != NULL){
                        ++numVowels;
                }
        }
free(vowels);
return numVowels;

}



char *disemvowel(char *str) {
  int len,vow,i,x=0;
  char *result;
  char *vowels = (char*)calloc(11, sizeof(char));
  strcpy(vowels, "aeiouAEIOU\0");
 
  vow = vowelCounter(str);
  len = strlen(str);
  result = (char*) calloc(len+1-vow, sizeof(char));


  for (i=0; i<len; ++i) {
	if(strchr(vowels, str[i]) == NULL ){
			result[x] = str[i];
			++x;
	}
  }
  result[len-vow] = '\0';
  free(vowels);
	return result;
}
