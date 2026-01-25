#ifndef SCRABBLE_SCORE_H
#define SCRABBLE_SCORE_H

static const char let[27] = "AEIOULNRSTDGBCMPFHVWYKJXQZ";
static const int fran[7] = {9, 11, 15, 20, 21, 23, 25};
static const int val[7] = {1, 2, 3, 4, 5, 8, 10};

unsigned int
score(const char *word);

#endif
