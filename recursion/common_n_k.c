#include <stdio.h>

int how_many_groups(int num_of_persons_to_choose_from, int num_of_persons_per_group){
	if (num_of_persons_per_group > num_of_persons_to_choose_from)
		return 0;
	if (num_of_persons_per_group == 1)
		return num_of_persons_to_choose_from;
	else
		return (how_many_groups(num_of_persons_to_choose_from - 1, num_of_persons_per_group) + how_many_groups(num_of_persons_to_choose_from - 1, num_of_persons_per_group - 1));
}

int main(int argc, char const *argv[])
{
	printf("%d\n",how_many_groups(5,3));
	return 0;
}