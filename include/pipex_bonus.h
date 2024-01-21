/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:51:23 by kboulkri          #+#    #+#             */
/*   Updated: 2024/01/04 20:15:59 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_data
{
	char	**cmds;
	char	**argv;
	char	**path;
	char	**envp;
	char	*path_i;
	char	*path_o;
	int		here_doc;
	int		fd_i;
	int		fd_o;
	int		tmp_fd;
	int		argc;
	int		count_tab;
	int		nb_cmb;
	int		pid[1024];
	int		pipe_fd[2];

}			t_data;

/* utils_bonus_two */

char		*ft_strdup_access(char *cmd);
int			open_fd(t_data *data, int i);
int			ft_strlen_from(int i, char *str);

/* free_tab_bonus.c */

void		free_tab(char **tab);
void		close_fds(t_data *data);

/* here_doc_bonus.c */

int			find_here_doc(char *str);
void		here_doc(char *pathname, char *limiter);

/* pipex_bonus.c */

void		child_process(t_data *data, int i);
int			exec_pipe(t_data *data);
void		redirection(t_data *data, int i);
void		parent_process(t_data *data, int i);

/* utils_bonus.c */

char		*find_envp_path(char **envp);
char		**split_path(t_data *data);
char		*complete_path(t_data *data, char *cmd);
void		init_data(int argc, char **argv, char **envp, t_data *data);
int			ft_access(char *path);

#endif