/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 23:39:53 by smargine          #+#    #+#             */
/*   Updated: 2023/12/08 15:02:18 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "../libft/libft.h"
# include "../libft/ft_printf.h"

extern volatile sig_atomic_t	g_received_signal;

typedef enum e_type
{
	WORD,
	IN_REDIR,
	OUT_REDIR,
	HERE_DOC,
	APPEND,
	PIPE,
	COMMAND
}	t_type;

typedef struct s_token 
{
	char			*content;
	t_type			type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_data 
{
	t_token			*tokens;
	int				no_tokens;
	char			*tok_is_red_str;
	char			*line;
	char			**array;
	char			**env;
	int				argc;
	char			**argv;
	char			**cmd_paths;
	int				heredoc_fd;
	int				stm_count;
	char			**created_files;
	unsigned int	exit_status;
	unsigned int	exit_status_final;
	int				orig_std_in;
	int				orig_std_out;
}	t_data;

typedef struct s_lexer_help 
{
	char	*line;
	char	**result;
	char	*temp;
	int		size;
	int		start;
	int		in_quotes;
	int		quotes_type;
	int		i;
	int		curr_t;
	char	***envp;
}	t_lexer_help;

typedef struct s_statment 
{
	t_token	*start_token;
	int		no_tokens;
	int		no_cmd_tokens;
	int		fd_in;
	int		fd_out;
	pid_t	pid;
	char	*cmd_path;
	char	**cmd_args;
	int		is_builtin;
	int		pipe[2];
	int		cur_token;
	int		stm_has_cmd;
	int		stm_has_red_only;
}	t_statment;

/////////////////////////////////-----MAIN-----/////////////////////////////////

// MAIN
int				main(int ac, char **argv, char **env);
void			ft_minihell(t_data *data);
void			ft_prepare_data(t_data *data);
void			ft_reset_data(t_data *data);
void			init_data(t_data *data, char **env);

/////////////////////////////////-----LEXER-----////////////////////////////////

// LEXER
int				ft_lexer(t_data *data);
t_lexer_help	*ft_init_lexer_help(t_data *data);
char			**ft_lexer_split(t_lexer_help *lh, t_data *data);
void			ft_cleanup_tokens(t_lexer_help *lh);
void			remove_quotes(char *str, int i, int j);

// EXPANDER
void			ft_expander(t_lexer_help *lh, t_data *data);
char			*replace_env_variables(char *str, char **env, t_data *data);
int				calculate_final_length(char *str, char **env, t_data *data);
int				calculate_length(char *ptr, char *end, char **env, \
t_data *data);
void			update_result(char **ptr, char **res_ptr, char **env, \
t_data *data);

// EXPANDER ENV
char			*get_env_value(char *var_name, char **env, t_data *data);
char			*get_var_name(char *ptr, char *end);
int				ft_has_env_value(char *str);

// LEXER SPLIT COUNT
void			ft_get_no_of_tokens(t_lexer_help *lh);
void			ft_get_no_of_tokens_quote(t_lexer_help *lh);
void			ft_get_no_of_tokens_operator(t_lexer_help *lh);

// LEXER SPLIT FILL
void			ft_fill_tokens_array(t_lexer_help *lh, t_data *data);
void			ft_copy_next_token_string(t_lexer_help *lh, \
t_data *data, int length);
void			ft_split_operator_str(t_lexer_help *lh, int \
start, int i, t_data *data);
void			ft_remember_red_strings_set(t_lexer_help *lh, \
t_data *data, int i);
void			ft_remember_red_strings(t_lexer_help *lh, t_data *data);

// LEXER SPLIT FILL HELP
bool			ft_str_has_operator(char *str);
int				ft_is_just_operator_str(char *str);
void			ft_split_op_str_next(t_lexer_help *lh, int start, \
int i, t_data *data);
void			ft_fill_tokens_array_quote(t_lexer_help *lh);
int				ft_split_just_operator_str(t_lexer_help *lh, int \
start, t_data *data);

// TOKENIZER
void			ft_tokenize(t_data *data);
int				ft_last_tok_is_red(t_token *tok);
int				ft_tokenize_handle_string(t_data *data, int i, int flag);
t_token			*ft_new_token(char *content, t_type type);
void			ft_add_token(t_token **list, t_token *new);

// HELPER COMMAND
bool			ft_is_system_command(char *str, t_data *data);
bool			ft_is_builtin(char *str);
bool			ft_is_command(char *str, t_data *data);

// HELPER PATH AND OPERATOR
bool			ft_is_correct_path(char *str);
bool			ft_is_op(char *str);
t_type			ft_find_op_type(char *str);

///////////////////////////////-----EXECUTOR-----///////////////////////////////

// EXECUTOR_1
void			ft_executor(t_token *token, int fdIn, t_data *data);
void			ft_execute_sys_cmd(t_statment *stm, t_data *data);
void			ft_execute_parent(t_statment *stm, t_data *data);
void			ft_executor_child(t_statment *stm, t_data *data);

// EXECUTOR_2
int				ft_execute_builtin(t_statment *stm, t_data *data);
void			ft_handle_io_redirection(t_statment *stm);
void			ft_prepare_fds(t_statment *stm);

// EXECUTOR_HELPER_1
t_statment		*init_stm(int fdIn, t_token *token);
void			prepare_stm(t_statment *stm, t_data *data);
void			count_tokens_helper(t_statment *stm, t_data *data);
void			count_cmd_tokens(t_statment *stm, t_data *data);

// EXECUTOR_HELPER_2
void			get_cmd_path(t_statment *stm, t_data *data);
int				ft_get_cmd_path_protection(t_statment *stm, t_data *data);
void			ft_get_cmd_path_executable(t_statment *stm);
void			get_cmd_args(t_statment *stm);
int				str_in_array(char *str, char **arr);

// PARSER
int				ft_parser(t_statment *stm, t_data *data);
int				ft_lonely_red(t_data *data, t_token *token);
int				ft_syntax_check(t_token *token, t_data *data);
t_token			*ft_syntax_check_cmd(t_token *token);
t_token			*ft_syntax_check_red(t_data *data, t_token *token);

// PARSER HELP
int				ft_same_str(char *s1, char *s2);
bool			ft_is_redirection(t_token *list);
int				handle_red_heredoc_empty(char *line, t_data *data);

// REDIRECTIONS
int				handle_redirections(t_token *token, t_statment *stm, \
t_data *data);
int				handle_red_out(t_token *token, t_statment *stm, t_data *data);
int				handle_red_app(t_token *token, t_statment *stm, t_data *data);
int				handle_red_in(t_token *token, t_statment *stm, t_data *data);
int				handle_red_heredoc(t_token *token, t_statment *stm, \
t_data *data);

///////////////////////////////-----BUILT-IN-----///////////////////////////////

// CD
int				ft_cd(t_statment *stm, t_data *data);
int				ft_cd_home(t_data *data);
int				ft_check_home(t_data *data);
int				ft_change_pwd(t_data *data, char *str);

// ECHO
int				ft_echo(t_statment *stm);
bool			ft_only_n(char *str);

// ENV
int				ft_env(t_statment *stm, t_data *data);

// EXIT
int				ft_exit(t_statment *stm, t_data *data);
bool			ft_check_digit(char *str, t_statment *stm, t_data *data);

// EXPORT
int				ft_export(t_statment *stm, t_data *data);
bool			ft_null_space(char c);
bool			ft_check_ifvar(char	*str, char **env);
int				ft_check_arg(char *str, t_data *data);
bool			ft_special_char(char c);

// PWD
int				ft_pwd(void);

// UNSET
int				ft_unset(t_statment *stm, t_data *data);
char			**ft_remove_from_env(char *str, char **env);
int				ft_var_len(char *str);
char			**ft_add_to_env(char *str, char **env);

////////////////////////////////-----SIGNALS-----///////////////////////////////

void			ft_signals(int signum, t_data *data);
void			ft_handle_sigint(int signum);
void			ft_handle_ctrlc(int signum);
void			ft_handle_backslash(int signum);
void			ft_handle_heredoc(int signum);

////////////////////////////////-----UTILS-----/////////////////////////////////

// CLEAN
void			ft_free_lexer(t_lexer_help *lh);
void			ft_free_tokens(t_token *list);
void			ft_free_str_arr(char **arr);
void			ft_clean_data(t_data *data, int exit);
void			ft_free_stm(t_statment *stm);

// ERROR
void			ft_perror(const char *msg, char *cmd, unsigned int err, \
t_data *data);
int				ft_export_error(char *str, t_data *data);

// HELPER_1
void			copy_env_paths(t_data *data);
char			**add_str_to_arr(char *str, char **arr);
char			**ft_copy_array(char **array);
void			ft_exec_next_stm(t_token *token, t_statment *stm, t_data *data);

// HELPER_2
bool			ft_no_open_quotes(char *str);
bool			is_quote(char c, char quote, int *counter, int *in_quote);

////////////////////////////////-----OTHERS-----////////////////////////////////

// ERROR MESSAGES
# define OP_QUO "minishell: not all quotes were closed\n"
# define NO_CMD "minishell: Command not found"
# define NO_FILE "minishell: No such file or directory\n"
# define SY_ERR_ROUT "minishell: syntax error after '>'\n"
# define SY_ERR_RAPP "minishell: syntax error after '>>'\n"
# define SY_ERR_RIN "minishell: syntax error after '<'\n"
# define SY_ERR_HD "minishell: syntax error after '<<'\n"
# define SY_ERR_PIPE "minishell: syntax error near '|'\n"
# define EXIT_ARG_ERR "minishell: exit: too many arguments\n"
# define CD_NOPTH_ERR "minishell: cd: No such file or directory\n"
# define HERE_DOC_EOF "minishell: warning: here-document \
deliminated by end-of-file (wanted 'EOF')\n"

#endif
