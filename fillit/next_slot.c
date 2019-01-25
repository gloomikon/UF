
#include "fillit.h"

t_vector	next_slot(t_vector ptn, char **sqr)
{
	t_vector ret;
	int size;

	size = ft_strlen(*sqr);
	ret.x = ptn.x;
	ret.y = ptn.y;
	while(ret.y < size)
	{
		if (ret.y > ptn.y)
			ret.x = 0;
		while (ptn.x < size)
		{
			if ((*(sqr + ret.y) + ret.x) == '.')
				return (ret);
			ret.x++;
		}
		ret.y++;
	}
	ret.x = -1;
	return (ret);
}
