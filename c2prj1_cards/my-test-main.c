#include "cards.h"

int main(void) {
  card_t test1 = {2, 0};
  print_card(test1);

  card_t test2 = card_from_letters('5', 's');
  print_card(test2);

  for (int i = 0; i < 52; i++) {
    print_card(card_from_num(i));
  }
}
