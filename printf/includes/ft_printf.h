/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khanadat <khanadat@student.42tokyo.jp>     #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-12 08:53:24 by khanadat          #+#    #+#             */
/*   Updated: 2025-05-12 08:53:24 by khanadat         ###   ########.jp       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include "ft_fmt.h"

int	ft_printf(const char *format, ...);
int	ft_vprintf(const char *fmt, va_list *ap, unsigned int *i, t_fmt *f);

#endif