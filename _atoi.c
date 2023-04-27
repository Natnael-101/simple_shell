#include "shell.h"

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

int DL(char aba, char *dudu)
{
	while (*dudu)
		if (*dudu++ == aba)
			return (1);
	return (0);
}

int ALP(int aba)
{
	if ((aba >= 'a' && aba <= 'z') || (aba >= 'A' && aba <= 'Z'))
		return (1);
	else
		return (0);
}

int _atoi(char *ss)
{
	int ii, sn = 1, fg = 0, opt;
	unsigned int rst = 0;

	for (ii = 0;  ss[ii] != '\0' && fg != 2; ii++)
	{
		if (ss[ii] == '-')
			sn *= -1;

		if (ss[ii] >= '0' && ss[ii] <= '9')
		{
			fg = 1;
			rst *= 10;
			rst += (ss[ii] - '0');
		}
		else if (fg == 1)
			fg = 2;
	}

	if (sn == -1)
		opt = -rst;
	else
		opt = rst;

	return (opt);
}
