/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:27:16 by sbrynn            #+#    #+#             */
/*   Updated: 2020/02/23 18:55:28 by sbrynn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 1
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
typedef struct	s_stack
{
	struct s_stack	*next;
	void			*data;
}				t_stack;
char			*ft_strchr(const char *str, int ch);
char			*ft_strrchr(const char *str, int ch);
int				ft_tolower(int character);
int				ft_toupper(int character);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strnstr(const char *str, const char *to_find, size_t n);
int				ft_isascii(int character);
int				ft_isalnum(int character);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strncpy(char *dest, const char *src, size_t n);
char			*ft_strcat(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strncat(char *dest, const char *src, size_t nb);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isprint(int ch);
int				ft_isdigit(int ch);
int				ft_isalpha(int ch);
int				ft_atoi(const char *str);
size_t			ft_strlcat(char *dest, const char *src, size_t nb);
void			*ft_memset(void *dest, int c, size_t n);
void			ft_bzero(void *dest, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *str, int ch, size_t n);
int				ft_memcmp(const void *arr1, const void *arr2, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
void			ft_putendl(char const *str);
void			ft_putnbr(int nb);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *str, int fd);
void			ft_putendl_fd(char const *str, int fd);
void			ft_putnbr_fd(int nb, int fd);
char			*ft_itoa(int n);
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_striter(char *s, void (*f)(char *));
void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			*ft_memalloc(size_t size);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char			**ft_strsplit(char const *s, char c);
t_stack			*ft_stack_make(void *data);
void			ft_stack_push(t_stack **begin_list, void *data);
void			*ft_stack_pop(t_stack **list);
size_t			ft_stack_size(t_stack *begin_list);
int				ft_match(char *s1, char *s2);
int				ft_nmatch(char *s1, char *s2);
int				ft_get_next_line(const int fd, char **line);
#endif
