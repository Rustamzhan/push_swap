
#include "ft_swap_header.h"


void print_stack(t_stack *stack_a)
{
	while (stack_a)
	{
		printf("%d\n", stack_a->num);
		stack_a = stack_a->next;
	}
	printf("\n");
}

int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = prepare_stack(ac, av);
	stack_b = NULL;
	print_stack(stack_a);
	while (get_next_line(0, &line) > 0)
	{
		if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "sb") || !ft_strcmp(line, "ss"))
		{
			swap_stacks(&stack_a, &stack_b);
			print_stack(stack_a);
			print_stack(stack_b);
		}
		if (!ft_strcmp(line, "ra") || !ft_strcmp(line, "rb") || !ft_strcmp(line, "rr"))
		{
			rotate_stacks(&stack_a, &stack_b);
			print_stack(stack_a);
			print_stack(stack_b);
		}
		if (!ft_strcmp(line, "rra") || !ft_strcmp(line, "rrb") || !ft_strcmp(line, "rrr"))
		{
			reverse_rotate_stacks(&stack_a, &stack_b);
			print_stack(stack_a);
			print_stack(stack_b);
		}
		if (!ft_strcmp(line, "pa"))
		{
			push_a(&stack_a, &stack_b);
			print_stack(stack_a);
			print_stack(stack_b);
		}
		if (!ft_strcmp(line, "pb"))
		{
			push_b(&stack_a, &stack_b);
			print_stack(stack_a);
			print_stack(stack_b);
		}
	}
	return (0);
}
