#ifndef COMPILATION_H
# define COMPILATION_H

# include "token.h"
# include "function.h"

typedef enum {
	SOURCE_CONTENT,
	TOKEN_LIST,
	AST,
	ASM_FILE_NAME,
	OBJ_FILE_NAME
}	t_compilation_phase;

typedef struct {
	t_compilation_phase	phase;
	union {
		char		*src_content;
		t_token		*token_list;
		t_func_list	*function_list;
		char		*asm_file_name;
		char		*obj_file_name;
	};
}	t_compilation;

#endif
