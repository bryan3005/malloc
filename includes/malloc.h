/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 19:32:17 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/17 11:55:59 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MALLOC_H
#	define MALLOC_H


#include "libft.h"
#include <sys/mman.h>
#include <stdlib.h>

typedef struct		s_block
{
	size_t			size;
	int				state;
	int				debug;
	struct s_block	*next;
}					t_block;

#	endif