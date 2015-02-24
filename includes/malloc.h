/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbryan <mbryan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 19:32:17 by mbryan            #+#    #+#             */
/*   Updated: 2015/02/24 11:32:46 by mbryan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MALLOC_H
#	define MALLOC_H


#include "libft.h"
#include <sys/mman.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct		s_block
{
	size_t			size;
	int				state;
	int				debug;
	struct s_block	*next;
}					t_block;

#	endif