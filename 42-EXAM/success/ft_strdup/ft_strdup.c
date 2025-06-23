#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char *new_str;
	int i;

	i = 0;
	new_str= malloc(ft_strlen(src) + 1);
	if (!new_str)
		return (NULL);
	while (src[i])
	{
		new_str[i] = src[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int main(void)
{
	char str[12] = "test";

	printf("%s\n", ft_strdup(str));
	return(0);
}
