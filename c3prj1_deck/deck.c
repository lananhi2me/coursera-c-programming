#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"

void print_hand(deck_t* hand){
  for (int i = 0; i < hand->n_cards; i++) {
    if (hand->cards[i] == NULL) {
      printf("Null card pointer");
    }
    print_card(*(hand->cards[i]));
    printf(" ");
  }
}

int deck_contains(deck_t* d, card_t c) {
  for (int i = 0; i < d->n_cards; i++) {
    if ((*(d->cards[i])).value == c.value && (*(d->cards[i])).suit == c.suit) {
      return 1;
    }
  }
  return 0;
}

void shuffle(deck_t* d){
  for (int i = 0; i < d->n_cards; i++) {
    long k = random() % d->n_cards;
    card_t* temp = d->cards[k];
    d->cards[k] = d->cards[i];
    d->cards[i] = temp;
  }
}

void assert_full_deck(deck_t* d) {
  if (!d || !d->cards) {
    printf("Null deck pointer");
    exit(EXIT_FAILURE);
  }
  if (d->n_cards != 52) {
    printf("Deck doesn't have 52 cards");
    exit(EXIT_FAILURE);
  }
  card_t* temp_c[52];
  deck_t temp_d = {temp_c, 0};
  for (int i = 0; i < 52; i++) {
    if (!d->cards[i]) {
      printf("Null card pointer");
      exit(EXIT_FAILURE);
    }
    assert_card_valid(*(d->cards[i]));
    if (deck_contains(&temp_d, *(d->cards[i]))) {
      printf("Duplicate card found");
      exit(EXIT_FAILURE);
    }
    temp_d.cards[i] = d->cards[i];
    temp_d.n_cards++;
  }
}
