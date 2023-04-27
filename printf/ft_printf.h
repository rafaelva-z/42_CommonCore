/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:31:34 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/27 11:03:06 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_HIGH "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *text, ...);
size_t	ft_strlen(const char *str);
size_t	ft_nputchar_fd(char c, int fd);
size_t	ft_nputstr_fd(char *s, int fd);
size_t	ft_nputnbr_fd(long n, int fd);
size_t	ft_nputaddr_fd(unsigned long ptr, int fd);
size_t	ft_nputhex_fd(unsigned long ptr, char *hex_case, int fd);

#endif