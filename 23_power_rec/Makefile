test: power.o test-power.o
	gcc -o test -pedantic -std=gnu99 -Wall -Werror power.o test-power.o
test-power.o: test-power.c
	gcc -c -o test-power.o -pedantic -std=gnu99 -Wall -Werror test-power.c
power.o: power.c
	gcc -c -o power.o -pedantic -std=gnu99 -Wall -Werror power.c
