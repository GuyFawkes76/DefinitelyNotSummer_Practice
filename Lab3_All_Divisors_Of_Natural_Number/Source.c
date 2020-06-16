//	Программа All_Divisors_Of_Natural_Number
//
//	Программа преназначена для выполнения следующего задания:
//
//		При нахождении делителей натурального числа количество проверок возможных делителей
//		можно существенно сократить, если учесть, что у каждого делителя d числа n, не
//		превышающего квадратный корень из n, есть “симметричный” ему делитель. 
//		Например, если n = 30, достаточно найти делители 1, 2, 3, 5 
//		(целая часть квадратного корня из 30 равна 5), а все прочие вычисляются.
//		Напишите программу, в которой все делители заданного числа n будут выводиться в порядке
//		возрастания(без дополнительной сортировки, но с использование стеков).
//
//		Текущий файл Source.c содержит в себе основную функцию main и включение всех необходимых файлов.
//		
//	Автор: Степаненко Кирилл
//	Группа: ИВТ-13БО
//
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include "mystacklib.h"

//Функция, заполняющая первую половину стека делителей - до корня из number
stackElement* fillFirstStack(int number, double numberSqrt);
//Функция, заполняющая вторую половину стека делителей - после корня из number
stackElement* fillSecondStack(stackElement* element, int number);

void main() {
	int number;					//Введённое число.
	double numberSqrt;			//Квадратный корень из введённого числа number.
	stackElement * firstHOD;	//Указатель на первую половину делителей (first Half Of Divisors) - до sqrt из number.
	stackElement * secondHOD;	//Указатель на вторую половину делителей (second Half Of Divisors) - после sqrt из number.

	setlocale(LC_ALL, "RUS");
	
	greetUser();
	printf("Введите натуральное число n, для которого требуется найти все делители: ");
	if (!scanf("%d", &number)) {
		printf("Введённая строка не является натуральным числом, повторите попытку.");
		return;
	}
	if (number <= 0) {
		printf("Введённое число не является натуральным, повторите попытку.");
		return;
	}
	numberSqrt = sqrt(number);
	firstHOD = fillFirstStack(number, numberSqrt);
	secondHOD = fillSecondStack(firstHOD, number);
	printf("Делители числа %d:", number);
	popAndPrintDivisors(firstHOD, secondHOD);
}

stackElement * fillFirstStack(int number, double numberSqrt) {
	int divisor;						//Текущее число, проверяемое на делитель.
	stackElement * curElement = NULL;	//Указатель на текущий элемент.
	for (divisor = numberSqrt; divisor > 0; divisor--) {	//Проверяем, является ли число делителем.
		if (number % divisor == 0) {
			push(&curElement, divisor);
		}
	}
	return curElement;
}

stackElement * fillSecondStack(stackElement * element, int number) {
	stackElement * curElement1;				//Указатель на текущий элемент полученного стека делителей.
	stackElement * curElement2 = NULL;		//Указатель на текущий элемент формируемого стека делителей
	for (curElement1 = element; curElement1; curElement1 = curElement1->next) {
		if (number / curElement1->value != curElement1->value) {
			push(&curElement2, number / curElement1->value);
		}
	}
	return curElement2;
}

int greetUser() {	//Функция, выводящая приветствие и описание работы программы.
	printf("Вас привествует программа All_Divisors_Of_Natural_Number.\n\n"
		"Программа преназначена для выполнения задания при следующих условиях:\n\n"
		"При нахождении делителей натурального числа количество проверок возможных делителей\n"
		"можно существенно сократить, если учесть, что у каждого делителя d числа n, не\n"
		"превышающего квадратный корень из n, есть “симметричный” ему делитель.\n"
		"Например, если n = 30, достаточно найти делители 1, 2, 3, 5\n"
		"(целая часть квадратного корня из 30 равна 5), а все прочие вычисляются.\n\n"
		"Задание:\n\n"
		"Вывести все делители заданного числа n в порядке возрастания\n"
		"(без дополнительной сортировки, но с использованием стеков).\n\n"
		"Автор: Степаненко Кирилл\n Группа: ИВТ-13БО.\n\n");
}

int popAndPrintDivisors(stackElement * firstHOD, stackElement * secondHOD) {
	stackElement * curElement;				//Указатель на текущий элемент стека (сначала одного, потом второго) делителей.
	for (curElement = firstHOD; curElement; ) {
		printf(" %d", pop(&curElement));
	}
	for (curElement = secondHOD; curElement; ) {
		printf(" %d", pop(&curElement));
	}
	printf(".");
}