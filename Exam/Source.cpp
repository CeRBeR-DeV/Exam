#include<iostream>

void fill_rand(char arr[], int n);
void printf(char arr[], int n);
void enter(char str_enter[], char str_rand[], char rand_array[], char enter_array[], int n);
void start(char rand_array[], char enter_array[], int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 50;
	int input;
	char rand_array[n];
	char enter_array[n];
	std::cout << "Программа \"Клавиатурный тренажер\"" << std::endl;
	std::cout << "Перед началом выберите английскую раскладку клавиатуры и нажмите на Caps Lock!" << std::endl;
	std::cout << "Нажмите Enter, если готовы!" << std::endl;
	while (1)
	{
		input = getchar();
		if (input != char(27))
		{
			system("cls");
			start(rand_array, enter_array, n);
		}
	}
}
void fill_rand(char arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i % 5 == 4)arr[i] = ' ';
		else arr[i] = char((rand() % 25) + 65);
	}
}
void printf(char arr[], int n)
{
	for (int i = 0; i < n; i++)std::cout << arr[i];
}
void enter(char str_enter[], char str_rand[], char rand_array[], char enter_array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		str_enter[i] = std::cin.get();
		if (str_enter[i] != str_rand[i])
		{
			system("color 0C");
			system("color 07");
			system("cls");
			start(rand_array, enter_array, n);
		}
		else
		{
			system("cls");
			system("color 02");
			std::cout << "Круто!!!";
			system("color 07");
		}
	}
}
void start(char rand_array[], char enter_array[], int n)
{
	fill_rand(rand_array, n);
	printf(rand_array, n);
	std::cout << std::endl;
	enter(enter_array, rand_array, rand_array, enter_array, n);
}