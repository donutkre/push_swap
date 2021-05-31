/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktiong <ktiong@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 10:42:29 by ktiong            #+#    #+#             */
/*   Updated: 2021/05/31 10:42:29 by ktiong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "limits.h"

# define UNSPECIFIED			0
# define INT					1
# define DOUBLE					2
# define NAME					3
# define NL						5
# define COM					6
# define END					100
# define BUF_SIZE				100
# define READ_BUF_SIZE 			1024

typedef int					t_spect;
typedef unsigned long		t_un;
typedef void				(*t_err)(void *);
typedef struct s_stack		t_stack;
typedef struct s_stack_node	t_stack_node;
typedef struct s_fun		t_fun;
typedef struct s_array		t_array;
typedef struct s_cal		t_cal;
typedef struct s_merge		t_merge;
typedef struct s_pt			t_pt;

typedef struct s_fr
{
	const char	*path;
	int			fd;
	int			pos;
	char		buf[100];
	int			eof;
	int			file_len;
	int			col;
	int			row;
}				t_fr;

typedef struct s_str
{
	t_un	len;
	t_un	max;
	char	*ptr;
}				t_str;

typedef struct s_spec
{
	int				file_row;
	int				file_col;
	t_str			str;
	t_spect			type;
}				t_spec;

typedef struct s_specz
{
	t_spec		current_spec;
	t_str		scan;
	t_un		sort_row;
	t_un		sort_col;
	char		sort_c;
}				t_specz;

typedef struct s_con
{
	t_fr		fr;
	t_specz		specz;
	t_err		error_hand;
	void		*argc_err;
}				t_con;

struct s_stack
{
	t_stack_node	*top;
	t_stack_node	*bottom;
	long			len;
};

struct s_stack_node
{
	t_stack_node	*next;
	t_stack_node	*prev;
	long			val;
};

struct s_array
{
	long	*ds;
	long	len;
};

struct s_fun
{
	t_stack	a;
	t_stack	b;
	t_array	arr;
	char	*input;
	long	input_next;
	int		rra;
	int		rrb;
	int		ra;
	int		rb;
	int		sa;
	int		sb;
	int		call_op;
};

struct s_cal
{
	long	low;
	long	high;
	long	l3;
	long	l2;
	long	l1;
	long	a_len;
	long	b_len;
};

struct s_merge
{
	long	li;
	long	ri;
	long	lb;
	long	rb;
	long	i;
	long	left;
	long	mid;
	long	right;
};

struct s_pt
{
	long	min;
	long	max;
};

t_array			stack_arr(t_stack stack);
int				sorted_arr(t_array arr);
void			print_arr(t_array arr);
void			swap_arr(long *arr, long a, long b);
int				copy_arr(long **r, long *arr, long left, long right);

void			stack_push(t_stack *stack, t_stack_node *item);
t_stack_node	*stack_pop(t_stack *stack);

void			print_char(const char *chars);
void			char_error(const char *chars);

int				parse_single(void);
int				ps_num(const char *str);
void			almost(int argc, char *argv[]);
int				algo(long *arr, long left, long right);
int				mem(void *target, size_t size);
void			frees(void *target);
void			free_ret(int code);
t_fun			*run(void);
int				conv_nb(void);

void			get_pro	(t_array arr, long *small, long *big, t_pt input);
void			cal_ab(t_cal *c, long min, long max);

int				new_stack(t_stack *stack, long val);
int				stack_free(t_stack *stack, long *val);
void			stack_swap(t_stack *stack);
void			stack_move(t_stack *dest, t_stack *src);
void			stack_rotate(t_stack *stack);
void			stack_rev_rotate(t_stack *stack);

void			exe_sa(void);
void			exe_sb(void);
void			exe_ss(void);
void			exe_pa(void);
void			exe_pb(void);
void			exe_ra(void);
void			exe_rb(void);
void			exe_rr(void);
void			exe_rrr(void);
void			exe_rra(void);
void			exe_rrb(void);
int				single_argc(char *a1);
int				argcs(int argc, char *argv[]);
void			print_stack(t_stack stack);
char			reference(void);
void			process_a_stack(long len, long min, long max);
void			loop_divide_a(t_stack_node *cmp, t_cal *c);
void			divide_a_stack(long len, t_cal *c);
void			move_a_stack(t_cal c);
void			sorted_a_arr(void);
void			process_b3(long v1, long v2, long v3);
void			process_small_b(long len, t_stack_node *top);
void			process_a3_e(long v1, long v2, long v3);
void			process_a3(t_stack_node *top, t_cal c);
void			process_b(long len, long min, long max);
void			process_b2(long min, long max, t_cal c);
void			process_b(long len, long min, long max);
void			execute_op(void);
void			conv_error(void);

void			resolve_btop3(t_stack_node *top);
void			divide_b_stack(long len, t_cal *c);
int				open_f(int *fd, const char *path);
int				ret0(void);
int				safe(t_fr *fr);
t_fr			fr(const char *path);
t_spec			spec_create(void);
t_str			ps_putstr(void);
int				is_matching(t_str left, const char *right);
void			ps_strdel(t_str *str);
const char		*is_null(t_str str);
void			allocate_str(t_str *str, t_str other);
void			ps_strcpy(t_str *target, t_str source);
void			allocate_char(t_str *str, const char *raw);
t_str			ps_strjoin_num(t_str str, t_un start, t_un end);
t_str			ps_strjoin(t_str str);
t_str			newstr(const char *raw);
void			push_char(t_str *str, char c);
void			push_chars(t_str *str, const char *s);
void			push_double(t_str *str, double num, unsigned int round);
void			push_long(t_str *str, long num);
void			print_str(t_str str);
long			get_strlen(const char *str);
int				ps_digit(char c);
int				not_zero(char c);
int				ps_alpha(char c);
int				is_lst(char c);
long			ps_ltoi(t_str str);
double			ps_lltoi(t_str str);
long			ps_itoa(const char *s);
int				util1(char c, const char *list);

t_con			*parser(void);

t_spec			next_spec(void);
t_specz			specz_create(void);
void			spec_use(void);
t_spec			spec_next(void);
void			spec_init(void);
int				read_init(char c);
int				spec_name(void);
int				spec_num(void);
int				spec_int(void);
int				spec_comma(void);
int				spec_newl(void);
int				spec_end(void);

void			skip_emp(void);
char			read_all(void);
void			read_push_char(char c);
int				loop_d(char c);

int				validate_svalue(t_spect type, char next, t_str value);
int				validate_s(t_spect type, char next);
int				validate_s_init(t_spect type);
int				valid_sort(void);
int				valid_line(int len, const char *b);
long			valid_int(long min, long max);
double			valid_num_range(double min, double max);
double			valid_num(void);
t_str			valid_type(t_spect type);

void			conv_init(const char *path);
void			conv_fd_init(int fd, const char *name);
void			doneconv(void);
void			error_handle(void (*func)(void *), void *argc_err);

t_fr			fr(const char *path);
void			conv_del(const char *msg, int errcode);
void			file_del(const char *msg, int errcode);
void			conv_range_del(double min, double max);
void			conv_type_del(t_spect type);
void			spec_del(void);

#endif
