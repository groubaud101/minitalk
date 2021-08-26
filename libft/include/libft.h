/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:14:10 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/12 17:59:16 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define ATOI_ERROR 0
# define TRUE 1
# define FALSE 0

# ifndef BUFF
#  define BUFF 11
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}t_list;

typedef struct s_read
{
	char			*str;
	int				rd;
	struct s_read	*next;
}t_read;

/*
** Memory management
*/

void	*ft_memset(void *s, int c, size_t n);
void	*ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** is_something
*/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
int		ft_isinstr(int c, const char *str);
int		ft_str_isdigit(char *str);

/*
** Up or low the case
*/

int		ft_tolower(int c);
int		ft_toupper(int c);

/*
** Looking for char in str
*/

int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);

/*
** String management
*/

char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t size);
char	*ft_strncat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
size_t	ft_strlen(const char *s);

/*
** I AM THE NUMBER
*/

int		ft_len_int_base(int n, int len_base);
int		ft_len_uint_base(unsigned int n, int len_base);
int		ft_len_ulong_base(unsigned long n, int len_base);
int		ft_len_ulonglong_base(unsigned long long n, int len_base);
int		ft_atoi(const char *nptr);
int		ft_atoi_no_overflow(const char *nbr);
int		ft_atoi_base(const char *nptr, const char *base);
char	*ft_itoa(int n);
char	*ft_itoa_base(int n, char *base);
char	*ft_u_itoa_base(unsigned int n, char *base);
char	*ft_u_ltoa_base(unsigned long n, char *base);
char	*ft_u_lltoa_base(unsigned long long n, char *base);
void	*ft_memory_to_a(void *addr, int size, const char *base);

/*
** Math
*/

size_t	ft_abs(int nb);
int		ft_pow_int(int nb, int p);
int		ft_add(int n1, int n2);
int		ft_sub(int n1, int n2);
int		ft_mult(int n1, int n2);
int		ft_div(int n1, int n2);
int		ft_mod(int n1, int n2);
int		ft_the_max(int size, ...);
int		ft_the_min(int size, ...);

/*
** Memory allocation
*/

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);

/*
** Mandatory part two
** String management and memory allocation
*/

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int nb, char c));

/*
** Write on file descriptor or on STDOUT (1)
*/

void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_put_uchar(unsigned char c);
void	ft_put_uchar(unsigned char c);
void	ft_put_uchar_fd(unsigned char c, int fd);
void	ft_putstr(const char *s);
void	ft_putnstr(const char *str, int n);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putnstr_fd(const char *str, int fd, int n);
void	ft_putendl(char *s);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_put_int_base(int n, const char *base);
void	ft_put_int_base_fd(int n, const char *base, int len, int fd);
void	ft_put_uint_base(unsigned int n, const char *base);
void	ft_put_uint_base_fd(unsigned int n, const char *base, int len, int fd);
void	ft_put_ulong_base(unsigned long n, const char *base);
void	ft_put_ulong_base_fd(unsigned long n, const char *b, int len, int fd);
void	ft_put_ulonglong_base(unsigned long long n, const char *base);
void	ft_put_ulonglong_base_fd(unsigned long long n, const char *base,
			int len, int fd);
void	ft_puttab(char **tab, char *sep);
void	ft_puttab_fd(char **tab, char *sep, int fd);

/*
** Read fd
*/

void	ft_lstadd_read(t_read **alst, t_read *new_list);
t_read	*ft_lstnew_read(char *str, int rd);
char	*ft_read_file(int fd);

/*
** **************
** * Chain list *
** **************
*/

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new_lst);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new_lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
