/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eidaho <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:11:36 by eidaho            #+#    #+#             */
/*   Updated: 2020/02/24 15:11:41 by eidaho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** '-' - Результат преобразования выравнивается по левому краю
** '+' - Перед положительными числами выводится знак '+',
** а перед отрицательыыми - знак '-'
** ' ' - Если не указан модификатор '+', то перед положительными числами,
** на месте знака числа, будет выводиться пробел.
** '#' - Использовать альтернативную форму представления выводимого числа.
** При выводе чисел в шестнадцатеричном формате (преобразователь 'х' или 'Х')
** перед числом будет указываться 0х или 0Х соответственно.
** При выводе чисел в восьмеричном формате (преобразователь 'о')перед числом
** будет указываться 0. При выводе чисел с плавующей точкой.
** всегда будет содержаться десятичная точка. При использовании преобразователей
** g и G хвостовые нули не будут удаляться (по умолчанию удаляются)
** '0' - Если не указан флаг '-', то слева от выводимого числа будут
** выведены символы '0' для подгона числа к указанной ширене.
** Если для преобразователей d, i, o, x или X указана точность,
** то флаг 0 игнорируется.
*/

void	ft_set_flags(const char **form, t_options *f)
{
	while (**form)
	{
		if (**form == '-')
			f->flags |= F_MINUS;
		else if (**form == '+')
			f->flags |= F_PLUS;
		else if (**form == ' ')
			f->flags |= F_SP;
		else if (**form == '#')
			f->flags |= F_SHARP;
		else if (**form == '0')
			f->flags |= F_NULL;
		else
			break ;
		(*form)++;
	}
}

/*
** Спецификатор [ширина] задаёт минимальный размер
** выводимого числа в символах. Если количество символов
** в выводимом числе меньше указанной минимальной ширины,
** то недостоющее количество символов заполняется нулями
** или пробелами слева или справа в зависимости от указанных
** флагов. Ширина указывается либо целым числом, либо
** символом * с последующим указанием имени переменной
** типа int, содержащей значение ширины, перед аргументом
** к которому он относится. Если аргумент имеет отрицательное
** значение, то он эквивалентен соответствующему
** положительному значению с флагом "-".
*/

void	ft_set_width(const char **form, t_options *f, va_list ap)
{
	if (**form >= '0' && **form <= '9')
	{
		f->width = ft_atoi(*form);
		while ((**form) >= '0' && (**form) <= '9')
			(*form)++;
	}
	else if (**form == '*')
	{
		f->width = va_arg(ap, int);
		if (f->width < 0)
		{
			f->flags |= F_MINUS;
			f->width = -f->width;
		}
		(*form)++;
	}
}

/*
** Действия спецификатора [точность] зависит от типа
** выводимого числа. Для типов d, i, o, u, x, X
** определяет минимальное число выводимых цифр.
** Если количество выводимых цифр в числе меньше,
** чем указано в спецификаторе [точность], то выводимое
** число будет дополнено нулями слева. Для типов a, A, e,
** E, f, F определяет количество выводимых цифр после запятой.
** Если в выводимом числе количество значимых цифр после
** запятой меньше указанной точности, то недостающие символы
** выводятся нулями справа от числа. Если больше, то лишние
** цифры не выводятся. Для типов g и G определяет максимальное
** выводимое число цифр. Точность указывается в виде символа
** точка, за которым следует десятичное число или символ "*",
** с последующим указанием имени переменной типа int, содержащей
** значение точности, перед аргументом к которому он относится
*/

void	ft_set_accur(const char **form, t_options *f, va_list ap)
{
	if (**form == '.')
	{
		(*form)++;
		if (**form >= '0' && **form <= '9')
		{
			f->sum = ft_atoi(*form);
			while ((**form) >= '0' && (**form) <= '9')
				(*form)++;
		}
		else if (**form == '*')
		{
			f->sum = va_arg(ap, int);
			(*form)++;
		}
		else
			f->sum = 0;
	}
}

/*
** h: short int или unsigned short int | hh: char или unsigned char
** l: long int или unsigned long int   |  L: long double
** ll: long long int или unsigned long long int | j: intmax_t или uintmax_t
** z: size_t (или эквивалентный по размеру знаковый тип)
** t: ptrdiff_t (или эквивалентный по размеру беззнаковый тип)
*/

void	ft_set_modif(const char **form, t_options *f)
{
	while (**form)
	{
		if (**form == 'h' && *(*form + 1) == 'h' && (*form)++)
			f->length = f->length < LEN_HH ? LEN_HH : f->length;
		else if (**form == 'h' && f->length != LEN_HH)
			f->length = f->length < LEN_H ? LEN_H : f->length;
		else if (**form == 'l' && *(*form + 1) == 'l' && (*form)++)
			f->length = f->length < LEN_LL ? LEN_LL : f->length;
		else if (**form == 'l' && f->length != LEN_LL)
			f->length = f->length < LEN_L ? LEN_L : f->length;
		else if (**form == 'L')
			f->length = f->length < LEN_LL ? LEN_LL : f->length;
		else if (**form == 't')
			f->length = f->length < LEN_TIME ? LEN_TIME : f->length;
		else if (**form == 'z')
			f->length = f->length < LEN_Z ? LEN_Z : f->length;
		else if (**form == 'j')
			f->length = f->length < LEN_J ? LEN_J : f->length;
		else
			break ;
		(*form)++;
	}
}

int		ft_set_spec(char c, t_options *f)
{
	char *nospec;

	nospec = "-+ #0*.hlLtzj";
	if (!(c >= '0' && c <= '9'))
	{
		while (*nospec)
		{
			if (c == *nospec)
				return (0);
			nospec++;
		}
		f->spec = c;
		return (1);
	}
	return (0);
}
