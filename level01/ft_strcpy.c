

char *ft_strcpy(char *dest, const char *src)
{
	char *send;
	if(!src) return NULL;

	send = dest;
	while(*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return send;
}
