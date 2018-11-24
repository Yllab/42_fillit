#include <strings.h>

static unsigned short	two_pow(short power)
{
	unsigned short ret;

	ret = 0x2;
	while (--power > 0)
		ret *= 2;	
	return (ret);
}

unsigned short		convert_tetro(char *s)
{
	size_t i;
	unsigned short ret;

	i = 0;
	ret = 0x0;
	while (s[i])
	{
		if (s[i] == '#')
			ret += two_pow(15 - i);
	}
	return (ret);
}

#include <stdio.h>
int main()
{
   	unsigned short	tetrominoes[] =
	{
		0xF000, 0x8888, 0xCC00, 0xC600, 0x4C80, 0xC880, 0xE200,
		0x44C0, 0x8E00, 0xE400, 0x4C40, 0x4E00, 0x8C80
	};
	printf("%d", power_of_2(5));
//	printf("%d\n", find_start_square(tetrominoes, 13));	

}
