/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:32:40 by mhaouas           #+#    #+#             */
/*   Updated: 2023/11/13 14:37:22 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <string.h>

int	ft_printf(const char *str, ...);
int	ft_cputstr(char *str);
int	ft_cputnbr(int nb);
int	ft_cuputnbr(unsigned int nb);
int	ft_cputchar(char c);
int	ft_convert_to_hex(unsigned int nb, char type);
int	ft_point_to_hex(unsigned long long nb);

#endif