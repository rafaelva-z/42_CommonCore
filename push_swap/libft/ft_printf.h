/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:31:34 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/27 16:35:50 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_HIGH "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *text, ...);
size_t	ft_strlen(const char *str);
size_t	ft_nputchar(char c);
size_t	ft_nputstr(char *s);
size_t	ft_nputnbr(long n);
size_t	ft_nputaddr(unsigned long ptr);
size_t	ft_nputhex(unsigned long ptr, char *hex_case);

#endif