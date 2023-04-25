#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - prints formatted output to the console
 * @format: a string that contains placeholders for the values that will be printed
 *
 * Return: the number of characters written to the console
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int done;

	va_start(arg, format);
	done = vfprintf(stdout, format, arg);
	va_end(arg);
	return (done);
}

