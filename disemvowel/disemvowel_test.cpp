#include <gtest/gtest.h>

#include "disemvowel.h"


char *wrd;

TEST(Disemvowel, HandleEmptyString) {
  ASSERT_STREQ("",wrd = disemvowel((char*) ""));

  free(wrd);

}

TEST(Disemvowel, HandleNoVowels) {
  ASSERT_STREQ("pqrst", wrd = disemvowel((char*) "pqrst"));

  free(wrd);

}

TEST(Disemvowel, HandleOnlyVowels) {
  ASSERT_STREQ("", wrd = disemvowel((char*) "aeiouAEIOUOIEAuoiea"));

  free(wrd);

}

TEST(Disemvowel, HandleMorrisMinnesota) {
  ASSERT_STREQ("Mrrs, Mnnst", wrd =  disemvowel((char*) "Morris, Minnesota"));
 
  free(wrd);

}

TEST(Disemvowel, HandlePunctuation) {
  ASSERT_STREQ("n (nxplnd) lphnt!", wrd = disemvowel((char*) "An (Unexplained) Elephant!"));
 
  free(wrd);

}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  ASSERT_STREQ("xyz", wrd = disemvowel(str));
  free(wrd);
  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
