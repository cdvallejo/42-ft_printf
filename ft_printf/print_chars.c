/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_chars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:48:01 by cvallejo          #+#    #+#             */
/*   Updated: 2022/06/13 12:34:04 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_format_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[count] != '\0')
	{
		write(1, &s[count], 1);
		count++;
	}
	return (count);
}
