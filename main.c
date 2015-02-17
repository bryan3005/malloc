/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 19:30:52 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/17 14:59:34 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "malloc.h"

t_block		*update_struct(void *ptr)
{
	return ((t_block*)ptr - 1);
}

void		ft_free(void *ptr)
{
	t_block		*cpy;

	cpy = NULL;
	cpy = update_struct(ptr);
	ft_putendl("try");
	if (!ptr)
		return ;
	ft_putendl("try");
	cpy->state = 1;
	ft_putendl("try");
	munmap(cpy, cpy->size);
	ft_putendl("try");
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
	block->debug = 96561616;
	return (block);
}

t_block		*find_free(t_block **last,t_block *first, size_t size)
{
	t_block *current = first;
  while (current && !(current->state && current->size >= size)) {
    *last = current;
    current = current->next;
  }
  return current;
}

void	*ft_malloc(size_t size)
{
	t_block *block;
	t_block *last;
	 t_block *first = NULL;

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
		block = find_free(&last, first, size);
		if (!block)
		{
			block = ask_for_space(last, size);
			block->debug = 845434;
			ft_putendl("fefef");
			if (!block)
				return (NULL);
		}
		else
		{
			block->state = 0;
			block->debug = 58625;
		}
	}
	printf("size_malloc : %d\n",(unsigned int)block->size );
	printf("debug_malloc : %d\n",(unsigned int)block->debug );
	return (block + 1);
}

int main(int argc, char **argv)
{
	int i;
	int nb;
	char c;
	char z;
	char *str;
	char *str2;

	nb = ft_atoi(argv[2]);
	// ft_putnbr(nb);
	// ft_putchar('\n');
	c = argv[1][0];
	z = argv[1][1];
	(void)argc;
	str = (char *)ft_malloc(nb + 1);
	str2 = (char *)ft_malloc(nb + 1);
	if (str == NULL || str2 == NULL)
	{
		ft_putendl("echec MALLOC");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < nb)
	{
		str[i] = c;
		str2[i] = z;
		i++;
	}
	str[i] = '\0';
	str2[i] = '\0';

	ft_putendl(str);
	ft_free(str);
	ft_putendl(str);
	ft_putendl("fefkwe");
	ft_putendl(str2);
	str = (char *)ft_malloc(nb + 1);
	str2 = (char *)ft_malloc(nb + 1);
	c = 't';
	z = 'p';
	i = 0;
	while (i < nb)
	{
		str[i] = c;
		str2[i] = z;
		i++;
	}
	ft_putendl(str);
	ft_putendl(str2);
	return 0;
}