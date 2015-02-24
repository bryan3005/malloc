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