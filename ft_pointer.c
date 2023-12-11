/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbadakh <sbadakh@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 23:11:30 by sbadakh           #+#    #+#             */
/*   Updated: 2023/12/11 11:22:39 by sbadakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long long ptr, int c)
{
	int		len;
	char	*hex;

	hex = "0123456789abcdef";
	len = 0;
	if (!c)
	{
		len += write(1, "0x", 2);
		c++;
	}
	if (ptr >= 16)
		len += print_ptr(ptr / 16, c);
	len += print_char(hex[ptr % 16]);
	return (len);
}
