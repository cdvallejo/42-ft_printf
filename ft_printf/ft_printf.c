/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:04:03 by cvallejo          #+#    #+#             */
/*   Updated: 2022/06/13 15:36:03 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*Cuando printf encuentra un "%" llama a esta función que, 
dependiendo del tipo de formato, pedirá a una función específica 
que imprima el formato correspondiente. ¡Cada función retorna 
el contador de lo imprimido!*/

int	ft_format_check(char const str, va_list things)
{
	int	print_total;

	print_total = 0;
	if (str == 'c')
		print_total += ft_format_char(va_arg(things, int));
	else if (str == 's')
		print_total += ft_format_str(va_arg(things, char *));
	else if (str == 'p')
		print_total += ft_format_ptr(va_arg(things, unsigned long long));
	else if (str == 'd' || str == 'i')
		print_total += ft_format_dec(va_arg(things, int));
	else if (str == 'u')
		print_total += ft_format_undec(va_arg(things, unsigned int));
	else if (str == 'x')
		print_total += ft_hexabase(va_arg(things, unsigned int), 0);
	else if (str == 'X')
		print_total += ft_hexabase(va_arg(things, unsigned int), 1);
	else if (str == '%')
		print_total += ft_format_char('%');
	return (print_total);
}

/* printf funciona a través de argumentos variables (no sabemos cuántos 
argumentos nos van a pasar). Para eso,trabajamos con una estructura 
"va_list" que gestionará los argumentos. La librería <stdarg.h> contiene 
macros para utilizar estos arg variables. Printf devuelve un int que ha 
contado los caracteres que ha imprimido.*/

int	ft_printf(char const *str, ...)
{
	va_list	things;
	int		i;
	int		print_total;

	print_total = 0;
	va_start(things, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			print_total += ft_format_check(str[i], things);
		}
		else
		{
			ft_putchar(str[i]);
			print_total++;
		}
		i++;
	}
	va_end(things);
	return (print_total);
}

/*int	main(void)
{
	int	ptr[1];
	
	// Single char
	printf("Native test: %c \n", 'a');
	ft_printf("Custom test: %c \n", 'a');
	//String
	printf("Native test: %s \n", "String");
	ft_printf("Custom test: %s \n", "String");
	//Void *
	printf("Native test: %p \n", ptr);
	ft_printf("Custom test: %p \n", ptr);
	//Integer or decimal
	printf("%d\n", printf("Native test: %ld %i \n", -2147483648, 2147483647));
	printf("%d\n", ft_printf("Custom test: %d %i \n", -2147483648, 2147483647));
	//Unsigned decimal
	printf("Native test: %u\n", -10);
	ft_printf("Custom test: %u \n", -10);
	//Hexadecimal lowercase
	printf("Native test: %x\n", 123456);
	ft_printf("Custom test: %x \n", 123456);
	//Hexadecimal upercase
	printf("Native test: %X\n", 123456);
	ft_printf("Custom test: %X \n", 123456);
	// % symbol
	printf("Native test: %% %d\n", 123456);
	ft_printf("Custom test: %% %d \n", 123456);
	return (0);
}

• c para imprimir un solo carácter.
• %s para imprimir una string (como se define por convención en C).
• %p el puntero void * dado como argumento se imprimirá en hexadecimal.
• %d para imprimir un número decimal (de base 10).
• %i para imprimir un entero en base 10.
• %u para imprimir un número decimal (de base 10) sin signo.
• %x para imprimir un número hexadecimal (de base 16), en minúscula.
• %X para imprimir un número hexadecimal (de base 16), en mayúscula.
• % % para imprimir el signo del porcentaje*/
