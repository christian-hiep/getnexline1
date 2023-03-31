int	main(int ac, char **av)
{
	char			*line;
	int				fd;
	int				i;

	(void)ac;
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (1);
	i = 0;
	while (i++ < GNL_CALL)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (THEN_DIFF)
			printf("%s", line);
		else
			printf("line [%02d]: %s", i, line);
		free(line);
	}
	close(fd);
	return (0);
}
