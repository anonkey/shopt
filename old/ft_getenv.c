char	*ft_getenv(const char *name, char **env)
{
	int		i;
	char	*ret;
	size_t	namelen;

	i = 0;
	if (!env || !name)
		return (NULL);
	namelen = ft_strlen(name);
	while (env[i] && (ft_strncmp(env[i], name, namelen)
						|| env[i][namelen] != ENV_SEP))
		++i;
	ret = env[i] ? ft_strdup(env[i] + namelen + 1) : NULL;
	return (ret);
}
