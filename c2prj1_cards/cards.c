#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c) {
  assert(c.value >= 2 && c.value <= VALUE_ACE);
  assert(c.suit >= SPADES && c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  if (r == STRAIGHT_FLUSH) {
    return "Straight flush";
  }
  if (r == FOUR_OF_A_KIND) {
    return "Four of a kind";
  }
  if (r == FULL_HOUSE) {
    return "Full house";
  }
  if (r == FLUSH) {
    return "Flush";
  }
  if (r == STRAIGHT) {
    return "Straight";
  }
  if (r == THREE_OF_A_KIND) {
    return "Three of a kind";
  }
  if (r == TWO_PAIR) {
    return "Two pair";
  }
  if (r == PAIR) {
    return "Pair";
  }
  if (r >= NOTHING) {
    return "Nothing";
  }
  fprintf(stderr, "Invalid ranking!");
  exit(1);
}

char value_letter(card_t c) {
  if (c.value >= 2 && c.value <= 9) {
    return '0' + c.value;
  }
  if (c.value == 10) {
    return '0';
  }
  if (c.value == VALUE_JACK) {
    return 'J';
  }
  if (c.value == VALUE_QUEEN) {
    return 'Q';
  }
  if (c.value == VALUE_KING) {
    return 'K';
  }
  if (c.value == VALUE_ACE) {
    return 'A';
  }
  fprintf(stderr, "Invalid value!");
  exit(1);
}


char suit_letter(card_t c) {
  if (c.suit == 0) {
    return 's';
  }
  if (c.suit == 1) {
    return 'h';
  }
  if (c.suit == 2) {
    return 'd';
  }
  if (c.suit == 3) {
    return 'c';
  }
  fprintf(stderr, "Invalid suit!");
  exit(1);
}

void print_card(card_t c) {
  printf("%c%c", value_letter(c), suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let) {
  assert((value_let >= 2 && value_let <= 14 && value_let != 10) || value_let == 0);
  assert(suit_let == 's' || suit_let == 'h' || suit_let == 'd' || suit_let == 'c');
  
  card_t result = {value_let, suit_let};
  return result;
}

card_t card_from_num(unsigned c) {
  assert(c >= 0 && c < 52);
  card_t result = {c % 13, c / 13};
  return result;
}
