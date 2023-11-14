#include "main.h"

/**
 * _printf - a custom printf function
 * @format: format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;

	va_list args;
	va_start(args, format);

	count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						int ch = va_arg(args, int);
						count += _putchar(ch);
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);
						count += printf("%s", str);
						break;
					}
				case '%':
					count += _putchar('%');
					break;
				default:
					count += _putchar('%');
					count += _putchar(*format);
			}
		}
		else
		{
			count += _putchar(*format);
		}

		format++;
	}

	va_end(args);
	return (count);
}
