#include <stdio.h>
#include "push_swap.h"

void print_moves(t_moves *moves)
{
	printf("Moves for number %d:\n", moves->number);
	printf("Number: %d\n", moves->number);
	printf("ra moves: %d\n", moves->ra_moves);
	printf("rra moves: %d\n", moves->rra_moves);
	printf("rb moves: %d\n", moves->rb_moves);
	printf("rrb moves: %d\n", moves->rrb_moves);
	printf("rr moves: %d\n", moves->rr_moves);
	printf("rrr moves: %d\n", moves->rrr_moves);	
	printf("Total moves: %d\n", moves->total_moves);
}