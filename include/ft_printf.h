/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:29:59 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/09 16:55:03 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# define MASK 32768
# define MASKEXP 32767
# define MASKHASH 32767
# define MASKSIGN 32768
# define MASKSPACE 61439
# define MASKZERO 49151
# define RST "\x1B[0m"
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CYN "\x1B[36m"
# define WHT "\x1B[37m"

/*
** |0   0   0   0  0 | 0   0 |
** |#   0   -      + |lc  . p|
** |   attributs     |       |
** |   		      	 |	     |
*/

enum				e_type
{
	tint,
	tchar,
	tshort,
	tlong,
	tlonglong,
	tunsignedint,
	tunsignedchar,
	tunsignedshort,
	tunsignedlong,
	tunsignedlonglong,
	tcharptr,
	tcharchar,
	tdouble,
	tlongdouble,
	tbint,
	tbchar,
	tbshort,
	tblong,
	tblonglong,
	tblongdouble,
	tpercent
};

enum				e_flag
{
	FHASH,
	FZERO,
	FMINUS,
	FSPACE,
	FPLUS,
	FWIDTH,
	FPREC
};

typedef union			u_test
{
	long double			ld;
	double				d;
	char				*str;
	unsigned long long	ull;
	unsigned long		ul;
	unsigned int		ui;
	unsigned short		ush;
	unsigned char		uc;
	long long			ll;
	long				l;
	int					i;
	char				c;
	short				sh;
}						t_test;

typedef struct			s_double_str
{
	char				*result_ent;
	char				*result_dec;
	char				*buff_ent;
	char				*buff_dec;
	short				exp;
	char				*mantissa;
	uint8_t				sign;
}						t_double_params;

typedef struct			s_pflist
{
	char				conv_id;
	int					type;
	unsigned short		param;
	int					field_width;
	int					field_precision;
	int					size;
	uint8_t				hh;
	uint8_t				h;
	uint8_t				ll;
	uint8_t				l;
	uint8_t				upl;
	uint8_t				upf;
	t_double_params		double_param;
	unsigned int		base_nb;
	char				sign;
}						t_pflist;

int						ft_printf(char *str, ...);
void					get_type(t_pflist *list);
void					pf_putnbr(long nb, t_pflist *list);
t_pflist				check_arg(char *str, va_list ap);
int						check_attributs(char *str, t_pflist *list);
int						check_fw_prec(char *str, t_pflist *list, int i,
							va_list ap);
t_pflist				check_color(char *str);
void					pf_putstr(char *str, t_pflist *list);
char					*pf_percent(va_list ap, t_pflist *list);
char					*apply_color(t_pflist *list);
char					*pf_binary(va_list ap, t_pflist *list);

char					*pf_itoa(va_list ap, t_pflist *list);
int						check_fzero(t_pflist *list, int size_nb);
int						check_precision(long long arg, t_pflist *list,
							int size_nb);
int						get_size_nb(long long arg);
char					get_sign(long long arg, t_pflist *list);

char					*pf_str(va_list ap, t_pflist *list);
char					*pf_char(va_list ap, t_pflist *list);
char					*ft_strjoin_free_order(const char *s1, const char *s2,
							int free, int order);
char					*pf_utoa(unsigned long arg, t_pflist *list);
char					*width_str(int size_width, char c);
char					*pf_utoabase(va_list ap, t_pflist *list);
char					*pf_doubletoa(va_list arg, t_pflist *list);
char					*get_width_space_str(char *result, int len,
							t_pflist *list);
int						pf_atoi(const char *str);
void					init_fct_tabs(void);
int						init_tab_double(t_pflist *list);
char					*double_exception(char *mantissa, t_pflist *list);
void					double_round(char *d_decimal, char *decimal, int i,
							int check);
int						check_d(char *decimal, int i);
void					tab_fill_mult2(t_pflist *list);
void					tab_fill_mult2(t_pflist *list);
char					*get_final_str(t_pflist *list);
void					double_str_to_null(t_double_params param);

int						init_double_str(t_pflist *list);
void					check_for_operation(t_pflist *list);
void					add_buff_to_result(char *dest, char *source,
							int correc);
void					get_mult_by_exp(char *result, char *buff, int j);
void					get_div_by_exp(char *result, char *buff, int j);

t_test					get_arg_int(va_list ap);
t_test					get_arg_char(va_list ap);
t_test					get_arg_short(va_list ap);
t_test					get_arg_long(va_list ap);
t_test					get_arg_longlong(va_list ap);
t_test					get_arg_unsignedint(va_list ap);
t_test					get_arg_unsignedchar(va_list ap);
t_test					get_arg_unsignedshort(va_list ap);
t_test					get_arg_unsignedlong(va_list ap);
t_test					get_arg_unsignedlonglong(va_list ap);
t_test					get_arg_strptr(va_list ap);
t_test					get_arg_double(va_list ap);
t_test					get_arg_longdouble(va_list ap);

unsigned int			g_fd;
char					**g_sptr;

t_test					(*g_get_arg_tab[21])(va_list);

char					*(*g_fct_tab[22])(va_list, t_pflist *);

#endif
