#include "shell.h"

int ext(info_t *info)
{
	int eck;

	if (info->argv[1]) 
	{
		eck = _erratoi(info->argv[1]);
		if (eck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

int cd(info_t *info)
{
	char *ss, *fol, bfr[1024];
	int cdret;

	ss = getcwd(buffer, 1024);
	if (!ss)
		_puts("TODO: >>getcwd failure emsg <<\n");
	if (!info->argv[1])
	{
		fol = _gtv(info, "HOME=");
		if (!fol)
			cdret = 
				cd((fol = _gtv(info, "PWD=")) ? fol : "/");
		else
			cdret = cd(fol);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_gtv(info, "OLDPWD="))
		{
			_puts(ss);
			_putchar('\n');
			return (1);
		}
		_puts(_gtv(info, "OLDPWD=")), _putchar('\n');
		cdret = 
			cd((fol = _gtv(info, "OLDPWD=")) ? fol : "/");
	}
	else
		cdret = cd(info->argv[1]);
	if (cdret == -1)
	{
		print_error(info, "not possible ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

int hlp(info_t *info)
{
	char **ary;

	ary = info->argv;
	_puts("it works! \n");
	if (0)
		_puts(*ary); 
	return (0);
}
