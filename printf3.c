#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - prints formatted output to the console
 * @format: a string that contains placeholders
 * for the values that will be printed
 * Return: the number of characters written to the console
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int done = 0;
	
	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			++format;
			switch (*format) {
				case 'd':
					done += printf("%d", va_arg(arg, int));
					break;
				case 's':
					done += printf("%s", va_arg(arg, char *));
					break;
				case 'c':
					done += printf("%c", va_arg(arg, int));
					break;
				case 'f':
					done += printf("%f", va_arg(arg, double));
					break;
				case 'b':
					{
						unsigned int num = va_arg(arg, unsigned int);
						char binary[33] = {'\0'};
						int i = 0, j;
						while (num > 0 && i < 32)
						{
							binary[i++] = (num % 2) + '0';
							num /= 2;
						}
						for (j = i - 1; j >= 0; --j)
						{
							done += printf("%c", binary[j]);
						}
					}
					break;
				default:
					done += printf("%%%c", *format);
					break;
			}
		}
		else
		{
			done += printf("%c", *format);
		}
		++format;
	}
	va_end(arg);
	return done;
}
