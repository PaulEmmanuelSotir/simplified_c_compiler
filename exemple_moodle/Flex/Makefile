exemple.c: exemple.l
	flex --header-file=exemple.h -o $@ $^ 
exemple : exemple.c main.c
	clang -o $@ $^
