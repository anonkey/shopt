

int		ft_setenv(char *name, char *val, int over, char ***env)
{
	int		i;
	size_t	namelen;
	int		err;

	i = 0;
	if (!name || !env || !*env)
		return ((env && !*env) ? -2 : -1);
	namelen = ft_strlen(name);
	while ((*env)[i] && ft_strncmp((*env)[i], name, namelen))
		++i;
	if (!(*env)[i])
		ft_strtabrealloc(env, 1);
	if (over && (*env)[i])
		ft_strdel(&((*env)[i]));
	if (!(*env)[i])
	{
		if (!((*env)[i] = ft_strjoin(name, "=")))
			return (-3);
	}
	val = val ? val : "";
	if ((*env)[i][namelen + 1])
		err = ft_strsepjoin(&((*env)[i]), val, ":");
	else
		err = ft_strsepjoin(&((*env)[i]), val, "");
	return (err);
}
