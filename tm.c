/* Turing Machine */
#include <stdio.h>

#define N 0
#define L -1
#define R 1

#define H -1

struct Ins {
	char c, m, s;
};

// TODO: parse program from the file
struct Ins tt[][2] = {
	['a'] = {{'a', R, 1}, {'.', R, 0}},
	['.'] = {{'.', N, H}, {'.', N, H}},
};

// TODO: accept tape dynamically
char tape[] = "aaaaaa.";
char state = 0;
int  head = 0;

int main()
{
	for (;;) {
		printf("%s\n", tape);
		printf("%*.s^\n", head, " ");

		char c = tape[head];
		struct Ins ins = tt[c][state];
		tape[head] = ins.c;
		state = ins.s;
		if (state == H)
			break;
		head += ins.m;
	}
	return 0;
}
