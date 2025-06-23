#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	ft_error(char *str, char *str2)
{
	write(2, str, ft_strlen(str));
	if (str2)
		write(2, str2, ft_strlen(str2));
	write(2, "\n", 1);
}

void	ft_exec(int i, int tmp_fd, char **av, char **env)
{
	av[i] = NULL;
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	execve(av[0], av, env);
	ft_error("error: cannot execute ", av[0]);
	exit(1);
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	tmp_fd;
	int	pipe_fd[2];

	i = 0;
	tmp_fd = dup(STDIN_FILENO);
	(void)ac;
	while (av[i] && av[i + 1])
	{
		av = av + i + 1;
		i = 0;
		while (av[i] && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
			i++;
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				ft_error("error: cd: bad arguments", NULL);
			else if (chdir(av[1]) != 0)
				ft_error("error: cd: cannot change directory to ", av[1]);
		}
		else if (i != 0 && (av[i] == NULL || strcmp(av[i], ";") == 0))
		{
			if (fork() == 0)
			{
				ft_exec(i, tmp_fd, av, env);
			}
			else
			{
				close(tmp_fd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (i != 0 && strcmp(av[i], "|") == 0)
		{
			if (pipe(pipe_fd) == -1)
			{
				ft_error("error", "pipe");
				close(tmp_fd);
				while (waitpid(-1, NULL, WUNTRACED) != -1)
					;
				exit(1);
			}
			if (fork() == 0)
			{
				dup2(pipe_fd[1], STDOUT_FILENO);
				close(pipe_fd[0]);
				close(pipe_fd[1]);
				ft_exec(i, tmp_fd, av, env);
			}
			else
			{
				close(tmp_fd);
				close(pipe_fd[1]);
				tmp_fd = pipe_fd[0];
			}
		}
	}
	close(tmp_fd);
	return (0);
}
