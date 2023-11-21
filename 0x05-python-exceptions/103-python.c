#include <stdio.h>
#include <stdlib.h>
#include <python.h>
#include <floatobject.h>

/**
 * print_python_float - prints into about python float
 * @p: address of python struct
 */

void print_python_float(PyObject *p)
{
	double d;
	setbuf(stdout, NULL);
	printf("[.] float object info\n");
	if (strcmp(p->ob_type->tp_name, "float"))
	{
		printf("  [ERROR] Invalide float object\n");
		return;
	}
	d = ((PyFloatObject *)p)->ob_fval;
	printf("  value: %s\n", PyOS_double_to_string(d, 'r', 0, Py_DTSF_ADD_DOT_0, NULL));
}
/**
 * print_python_bytes - prints info about python bytes
 * @p: address of pyobject struct
 */
void print_python_bytes(PyObject *p)
{
	size_t i, len, size;
	char *str;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");
	if (strcmp(p->ob_type->tp_name, "bytes"))
	{
		printf("  [ERROR] Invalide Bytes Object\n");
		return;
	}
	size = ((PyVarObject *)p)->ob_size;
	str = ((PyBytesObject *)p)->ob_sval;
	len = size + 1 > 10 ? 10 : size + 1;
	printf("  size: %lu\n", size);
	printf("  trying string: %s\n", str);
	printf("  first %lu bytes: ", len);
	for (i = 0; i < len; i++)
		printf("%02hhx%s", str[i], i + 1 < len ? " " : "");
	printf("\n");
}

/**
 * print_python_list - print info about list
 * @p: first parameter
 */

void print_python_list(PyObject *p)
{
	int i;
	setbuf(stdout, NULL);
	printf("[*]  Python list info\n");
	if (strcmp(p->ob_type->tp_name, "list"))
	{
		printf("  [ERROR] Invalide list object\n");
		return;
	}
	printf("[*] Size of the Python list = %lu\n", ((PyVarObject *)p)->ob_size);
	printf("[*] Allocated = %lu\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < ((PyVarObject *)p)->ob_size; i++)
	{
		printf("Element %d: %s\n", i, ((PyListObject *)p)->ob_item[i]->ob_type->tp_name);
		if (!strcmp(((PyListObject *)p)->ob_item[i]->ob_type->tp_name, "bytes"))
			print_python_bytes(((PyListObject *)p)->ob_item[i]);
		else if (!strcmp(((PyListObject *)p)->ob_type->tp_name, "float"))
			print_python_float(((PyListObject *)p)->ob_item[i]);
	}
}
