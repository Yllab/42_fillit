/*
** Converts a tetromino from char* representation to unsigned short
**
** Input for convert_tetro should be a null terminated string
** with strlen == 16 and containing only '#' or '.'
*/ 

static unsigned short	two_pow(int power)
{
	unsigned short 		ret;

	if (power == 0)
		return (1);
	ret = 2;
	while (--power > 0)
		ret *= 2;	
	return (ret);
}

unsigned short			convert_tetro(char *s)
{
	int 				i;
	unsigned short 		ret;

	i = 0;
	ret = 0x0;
	while (s[i])
	{
		if (s[i] == '#')
			ret += two_pow(15 - i);
		i++;
	}
	return (ret);
}
