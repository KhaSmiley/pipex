/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboulkri <kboulkri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:38:22 by kboulkri          #+#    #+#             */
/*   Updated: 2024/01/17 12:40:59 by kboulkri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	int		fd_infile;
	int		fd_outfile;
	int		tmp_fd;
	int		argc;
	int		count_tab;
	int		nb_cmb;
	int		pid[1024];
	int		pipe_fd[2];

}			t_data;

/* free_tab */

void		free_tab(char **tab);
void		close_fds(t_data *data);

/* pipex.c */

void		child_process(t_data *data, int i);
int			exec_pipe(t_data *data);
void		redirection(t_data *data, int i);
void		parent_process(t_data *data, int i);

/* utils_two.c */

char		*ft_strdup_access(char *cmd);
int			ft_strlen_from(int i, char *str);
int			open_fd(t_data *data, int i);

/* utils.c */

char		*find_envp_path(char **envp);
char		**split_path(t_data *data);
char		*complete_path(t_data *data, char *cmd);
void		init_data(int argc, char **argv, char **envp, t_data *data);
int			ft_access(char *path);

#endif