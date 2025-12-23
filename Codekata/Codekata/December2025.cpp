#include "December2025.h"

// ==============
// 2025-12-22
// ==============

// 두수의 차 구하기 
// https://school.programmers.co.kr/learn/courses/30/lessons/120803

int Solution001(int num1, int num2)
{
	// 두수의 차를 리턴한다. 
	return num1 - num2;
}


// ==============
// 2025-12-23
// ==============

// 두수의 곱 구하기 
// https://school.programmers.co.kr/learn/courses/30/lessons/120804
int Solution002(int num1, int num2)
{
	return num1 * num2;
}


// 몫 구하기 
// https://school.programmers.co.kr/learn/courses/30/lessons/120805

int Solution003(int num1, int num2)
{
	return num1 / num2;
}

// 나이 출력
// https://school.programmers.co.kr/learn/courses/30/lessons/120820
int Solution004(int age)
{
	return 2022 - age + 1;
}

// 숫자 비교하기 
// https://school.programmers.co.kr/learn/courses/30/lessons/120807
int Solution005(int num1, int num2)
{
	return num1 == num2 ? 1 : -1;
}

// 두 수의 합
// https://school.programmers.co.kr/learn/courses/30/lessons/120802
int Solution006(int num1, int num2)
{
	return num1 + num2; 
}

// 두 수의 나눗셈
// https://school.programmers.co.kr/learn/courses/30/lessons/120806
int Solution007(int num1, int num2)
{
	return (num1 * 1000 / num2);
}

// 각도기 
// https://school.programmers.co.kr/learn/courses/30/lessons/120829
int Solution008(int angle)
{
	if (angle > 0 && angle < 90) return 1;

	if (angle == 90) return 2;

	if (angle < 180) return 3;

	if (angle == 180) return 4;

	return -1;
}

// 짝수의 합
// https://school.programmers.co.kr/learn/courses/30/lessons/120831
int Solution009(int n)
{
	int ret = 0;

	for (int i = 0; i <= n; i += 2)
		ret += i;

	return ret; 
}

// 배열의 평균 값
// https://school.programmers.co.kr/learn/courses/30/lessons/12937
double Solution010(std::vector<int> numbers)
{
	int sum = 0;

	for (int num : numbers) sum += num;

	return (double)(sum) / numbers.size();
}

// 짝수와 홀수
// https://school.programmers.co.kr/learn/courses/30/lessons/12937
std::string Solution011(int num)
{
	return num % 2 ? "Odd" : "Even";
}

// 평균 구하기 
// https://school.programmers.co.kr/learn/courses/30/lessons/12944
double Solution012(std::vector<int> arr)
{
	int sum = 0;

	for (int n : arr) sum += n;

	return (double)sum / arr.size(); 
}

// 자릿수 더하기 
// https://school.programmers.co.kr/learn/courses/30/lessons/12931
int Solution013(int n)
{
	int ret = 0;
	while (n > 0)
	{
		ret += n % 10;
		n /= 10;
	}

	return ret; 
}

// 약수의 합
// https://school.programmers.co.kr/learn/courses/30/lessons/12928
int Solution014(int n)
{
	int ret = 0;
	for (int i = 0; i <= n; i++)
	{
		if (n % i == 0) ret += i; 
	}

	return ret ; 
}

