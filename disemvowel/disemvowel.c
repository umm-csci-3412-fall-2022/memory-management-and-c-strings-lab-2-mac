#include <stdlib.h>
#include <string.h>


#include "disemvowel.h"


int vowelCounter(char const *str){
        int i, numVowels;
        for(i=0; i<strlen(str); ++i){
                if(strcasecmp(str[i], 'a') == 0  || strcasecmp(str[i], 'e') == 0  || strcasecmp(str[i], 'i') == 0  || strcasecmp(str[i], 'o') == 0  || strcasecmp(str[i], 'u') == 0){
                        ++numVowels;
                }
        }

return numVowels;

}



char *disemvowel(char const *str) {
  int len,numVowels,i,x;
  char *result;

  numVowels = vowelCounter(str);
  len = strlen(str);
  result = (char*) calloc(len+1-numVowels, sizeof(char));


  for (i=0; i<len; ++i) {
	if(strcasecmp(str[i], 'a') != 0 || strcasecmp(str[i], 'e') != 0 || strcasecmp(str[i], 'i') != 0  || strcasecmp(str[i], 'o') != 0  || strcasecmp(str[i], 'u') != 0){
			result[x] = str[i];
			++x;
	}
  }


	return result;
}
