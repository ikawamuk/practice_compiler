
# include "arena.h"
# include "token.h"
# include "function.h"
#include <stdlib.h>

char		*read_src(const char *file_path);
t_token 	*tokenize(const char *str);
t_func_list	*parse(t_token *token_list);
char		*compile(t_func_list *program);
char		*assemble(const char *assem_src_name);
int 		link(const char *assem_src_file, char **argv);

#include <stdio.h>
void	print_token_list(const t_token *token);
void	print_program(t_func_list *program);

int	run_compiler(char **argv)
{
	char	*file_content = read_src(argv[1]);
	if (!file_content)
		return (clear_arena(), EXIT_FAILURE);
	t_token	*token_list = tokenize(file_content);
	if (!token_list)
		return (clear_arena(), EXIT_FAILURE);
	// print_token_list(token_list);
	t_func_list	*program = parse(token_list);
	if (!program)
		return (clear_arena(), EXIT_FAILURE);
	// print_program(program);
	char	*assem_src_name = compile(program);
	if (!assem_src_name)
		return (clear_arena(), EXIT_FAILURE);
	clear_arena();
	char	*obj_name = assemble(assem_src_name);
	if (!obj_name)
		return (free(assem_src_name), EXIT_FAILURE);
	free(assem_src_name);
	if (link(obj_name, argv + 2) < 0)
		return (free(obj_name), EXIT_FAILURE);
	free(obj_name);
	return (EXIT_SUCCESS);
}
