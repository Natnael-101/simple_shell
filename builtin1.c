#include "shell.h"

int hty(info_t *info)
{
	print_list(info->history);
	return (0);
}

int unals(info_t *info, char *str)
{
	char *pp, cc;
	int non;

	pp = _strchr(str, '=');
	if (!pp)
		return (1);
	cc = *pp;
	*pp = 0;
	non = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pp = cc;
	return (non);
}

int als(info_t *info, char *str)
{
	char *pp;

	pp = _strchr(str, '=');
	if (!pp)
		return (1);
	if (!*++pp)
		return (unals(info, str));

	unals(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

int prals(list_t *dudu)
{
	char *pp = NULL, *dd = NULL;

	if (dudu)
	{
		pp = _strchr(node->str, '=');
		for (dd = node->str; dd <= pp; dd++)
			_putchar(*dd);
		_putchar('\'');
		_puts(pp + 1);
		_puts("\n");
		return (0);
	}
	return (1);
}

int ms(info_t *info)
{
	int pi = 0;
	char *pp = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			prals(node);
			node = node->next;
		}
		return (0);
	}
	for (a = 1; info->argv[a]; a++)
	{
		pp = _strchr(info->argv[a], '=');
		if (pp)
			als(info, info->argv[a]);
		else
			prals(node_starts_with(info->alias, info->argv[a], '='));
	}

	return (0);
}
