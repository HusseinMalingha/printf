#include "main.h"

/**
 * _printf - a custom printf function
 * @format: format string
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int count;
	char *buffer = (char *)malloc(BUFSIZE);
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
					written = snprintf(buffer + count,
							BUFSIZE - count, "%c",
							va_arg(args, int));
					break;
				case 's':
					written = snprintf(buffer + count,
							BUFSIZE - count, "%s",
							va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					written = snprintf(buffer + count,
							BUFSIZE - count, "%d",
							va_arg(args, int));
					break;
				case '%':
					written = snprintf(buffer + count,
							BUFSIZE - count, "%%");
					break;
				default:
					written = snprintf(buffer + count,
							BUFSIZE - count, "%%%c",
							*format);
			}
			count += (written < 0) ? 0 : written;
		}
		else
			buffer[count++] = *format;

		if (count >= BUFFER_SIZE - 1)
			break;
		format++;
	}
	va_end(args);
	buffer[count] = '\0';
	printf("%s", buffer);
	free(buffer);
	return (count);
}
