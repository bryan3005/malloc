/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 19:30:52 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/17 12:40:18 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdio.h>

t_block		*update_struct(t_block *block)
{
	return (block);
}

t_block		*ask_for_space(t_block *last, size_t size)
{
	int		all_sz;
	t_block *block;

	all_sz = size + sizeof(t_block);
	printf("size_all : %d\n",all_sz );
	block = mmap(0, all_sz, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (block == MAP_FAILED)
		return (NULL);
	if (last)
		last->next = block;
	block->size = size;
	block->next = NULL;
	block->state = 0;
	block->debug = 0x789456;
	return (block);
}

void	*ft_malloc(size_t size)
{
	t_block *block;
	t_block *last;
	t_block *first;

	first = NULL;
	if (size <= 0)
		return (NULL);
	if (!first)
	{
		block = ask_for_space(NULL, size);
		if (!block)
			return (NULL);
		first = block;
	}
	else 
	{
		last = first;
		block = ask_for_space(last, size);
		if (!block)
			return (NULL);
	}
	printf("size_malloc : %d\n",(unsigned int)block->size );
	return (block + 1);
}

int main(int argc, char **argv)
{
	int i;
	int nb;
	char c;
	char *str;

	nb = ft_atoi(argv[2]);
	// ft_putnbr(nb);
	// ft_putchar('\n');
	c = argv[1][0];
	(void)argc;
	str = (char *)ft_malloc(nb + 1);
	if (str == NULL)
	{
		ft_putendl("echec MALLOC");
		exit(EXIT_FAILURE);
	}
	//str = (char *)mmap(0, nb + 1, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	i = 0;
	while (i < nb)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	ft_putstr(str);
	return 0;
}