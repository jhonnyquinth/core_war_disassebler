/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 14:45:37 by aenstein          #+#    #+#             */
/*   Updated: 2020/08/07 07:44:07 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include "libft.h"
# include <stdarg.h>
# include <ctype.h>
# include <float.h>
# include <limits.h>
# include <stdio.h>
# define NAN	"nan"
# define NAN_UP	"NAN"
# define INF	"inf"
# define INF_UP	"INF"

typedef union		u_cast
{
	long double		ld;
	struct			s_parts
	{
		uint64_t	mantissa : 64;
		uint64_t	exponent : 15;
		unsigned	sign	: 1;
	}				t_parts;
}					t_cast;

typedef struct		s_mult
{
	int				len1;
	int				len2;
	char			*str1;
	char			*str2;
}					t_mult;

typedef struct		s_persent
{
	int					flag_checker;
	int					width;
	int					precision;
	int					f_hesh;
	int					f_mns;
	int					f_pls;
	int					f_sps;
	int					f_zro;
	int					sign;
	char				trans;
	int					modf;
	char				*tail;
	struct s_persent	*next;
}					t_persent;

int					ft_printf(char *cm_str, ...);
t_persent			*list_make(void);
t_persent			*list_add(t_persent *head);
void				list_pop(t_persent *head);
int					sub_proc(char *str, t_persent *lst, int start_flag);
void				list_print(t_persent *lst);
void				list_print_one(t_persent *tmp);
t_persent			*list_free(t_persent *head);
int					type_char(char c, t_persent *lst);
int					min_int(int a, int b);
int					max_int(int a, int b);
int					type_str(char *str, t_persent *lst);
int					type_proc(t_persent *lst);
int					how_match(char *str);
int					ft_len(int n);
int					type_int(va_list arg, t_persent *lst);
int					type_ox(va_list arg, t_persent *lst);
int					type_ptr(unsigned long long p, t_persent *lst);
char				*ft_itoa_base(int value, int base);
char				*ft_itoa_base_us(long long value, int base);
char				*ft_itoa_base_ox(unsigned long long value,
						int base, char c);
void				list_all_free(t_persent *head);
char				*to_str(t_persent *lst, long long n);
int					heshs(t_persent *lst, char c);
int					print_heshes(int c, t_persent *lst);
void				pres_h(t_persent *lst, int len, int c);
int					value_for_pres(t_persent *lst, int len, int c);
int					ox_o_presison(t_persent *lst, char *s, int len, int c);
int					ox_o_width(t_persent *lst, char *s, int len, int c);
int					ox_o(long long n, t_persent *lst);
int					ox_presison(t_persent *lst, char *s, int len, int c);
int					ox_width(t_persent *lst, char *s, int len, int c);
int					ox(long long n, t_persent *lst);
int					type_ox(va_list arg, t_persent *lst);
void				pres_c(t_persent *lst, int len, char c);
int					check_width(char *str, t_persent *lst);
int					check_precision(char *str, t_persent *lst);
int					get_sub(char *str);
int					rcl_percent_killer(t_persent **lst,\
char **cm_str, int *sf, int len);
void				rcl_iter(int *l, char **cm_str, int sf);
t_persent			*read_command_line(char *cm_str, int *l, int *cnt);
int					get_tail(char *str, t_persent *lst);
char				*proc_str_generator(int n);
int					choose_trans(t_persent *curr, va_list arg, int len);

int					type_float(t_persent *data, va_list ap);
int					parse_float(t_persent *data, long double f);
void				casting_float(t_persent *data, long double *f);
char				*parse_float_number(long double number, t_persent *data);
char				*str_multiplication(t_mult *m, char *tmp);
char				*pow_two(char *res, int pow);
char				*pow_five(char *res, int pow);
char				*parse_exponent(int pow);
char				*parse_mantis(unsigned long mantissa);
char				*make_mantissa(char *str, unsigned long mantissa);
char				*itobs(uint64_t num, char *str);
char				*make_f_str(char *full, char **mantissa, char **exponent);
void				fill_exp_mant(t_mult *m, char **a, char **b);
void				clean_mult(t_mult *m);
char				*make_dot(char **str, unsigned short exponent);
char				*make_dot_zero(char **str);
char				*make_full_str(char *full_str, int precision, int f_hesh);
char				*make_round(char **str, int p);
char				*fill_str(char *str, char *tmp, int p, int tmp_p);
char				*rounding(char *str, int mem);
char				*make_new_str(char *new_str, char *str);
char				*parse_float_flag(t_persent *data, int num_len);
int					parse_float_flag2(t_persent *data, int num_len);
void				record_float(t_persent *data, char **str_flag,\
						char **str_num);
void				out_float_minus(t_persent *data, char **str_flag,\
						char **str_num);
void				out_float(t_persent *data, char **str_flag, char **str_num);
char				*is_nan(unsigned long mantissa, int type);
char				*nan_inf_str(char tmp, int type);
char				*zero_str(int precision, int f_hesh, char *full_str);
char				*no_precision(int f_hesh);
void				pars_nan_inf(t_persent *data, char str);

#endif
