/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:31:58 by rvaz              #+#    #+#             */
/*   Updated: 2023/05/12 15:10:00 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
}	t_list;

//Part 1 - Libc functions

int		ft_atoi(const char *nptr);
int		ft_isalnum(unsigned char c);
int		ft_isalpha(unsigned char c);
int		ft_isascii(unsigned char c);
int		ft_isdigit(unsigned char c);
int		ft_isprint(unsigned char c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strncat(char *s1, char *s2, size_t n);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//Part 2 - Additional functions

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

//Part 3 - Bonus Functions

t_list	*ft_lstnew(int nb);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(int*));
void	ft_lstclear(t_list **lst, void (*del)(int*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstdup(t_list *lst);

//ft_printf

int		ft_printf(const char *text, ...);
size_t	ft_strlen(const char *str);
size_t	ft_nputchar(char c);
size_t	ft_nputstr(char *s);
size_t	ft_nputnbr(long n);
size_t	ft_nputaddr(unsigned long ptr);
size_t	ft_nputhex(unsigned long ptr, char *hex_case);

#endif