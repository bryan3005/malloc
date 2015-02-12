/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 19:30:52 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/12 20:00:28 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"


void	*ft_malloc(size_t size)
{
	void	*ret;

	ret = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (ret == MAP_FAILED)
		return (NULL);
	return (ret);
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