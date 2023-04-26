/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:31:34 by rvaz              #+#    #+#             */
/*   Updated: 2023/04/26 01:11:11 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEX_HIGH "0123456789ABCDEF"
# define HEX_LOW "0123456789abcdef"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(char *text, ...);
int		ft_nputchar_fd(char c, int fd);
int		ft_nputstr_fd(char *s, int fd);
int		ft_nputnbr_fd(int n, int fd);
int		ft_nputendl_fd(char *s, int fd);
int		ft_nputaddr_fd(unsigned long ptr, int print0x, int fd);
size_t	ft_strlen(const char *str);
int		ft_nputhex_fd(long int ptr, char *hex_case, int fd);

#endif