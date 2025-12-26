#include "December2025.h"
#include <bits/stdc++.h>

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

// 나머지가 1이 되는 수 찾기
// https://school.programmers.co.kr/learn/courses/30/lessons/87389
int Solution015(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (n % i == 1) return i; 
	}

	// 도달 x 
	return -1; 
}

// x만큼 간격이 있는 n개의 숫자
// https://school.programmers.co.kr/learn/courses/30/lessons/12954
std::vector<long long> Solution016(int x, int n)
{
	std::vector<long long> ret;

	for (int i = 1; i <= n; i++)
	{
		ret.push_back(x * i);
	}

	return ret; 
}

// 자연수 뒤집어 배열로 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/12932
std::vector<int> Solution017(long long n)
{
	std::vector<int> ret;
	std::string s = std::to_string(n);

	for (int i = s.size() - 1; i >= 0; i--)
	{
		ret.push_back(s[i] - '0');
	}

	return ret; 

}

// 문자열을 정수로 바꾸기
// https://school.programmers.co.kr/learn/courses/30/lessons/12925
int Solution018(std::string s)
{
	if (s[0] >= '0' && s[0] <= '9') return std::stoi(s);

	if (s[0] == '+') return std::stoi(s.substr(1));

	if (s[0] == '-') return -std::stoi(s.substr(1));

}

// 정수 제곱근 판별
//https://school.programmers.co.kr/learn/courses/30/lessons/12934
long long Solution019(long long n)
{
	for (long long i = 1; i * i <= n; i++)
	{
		if (i * i == n) return (i + 1) * (i + 1); 
	}

	return -1; 
}

// 정수 내림차순으로 배치하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12933
long long Solution020(long long n)
{
	std::string s = std::to_string(n);
	sort(s.rbegin(), s.rend());

	return std::stoll(s);
}

// ==============
// 2025-12-24
// ==============

// 하샤드 수
// https://school.programmers.co.kr/learn/courses/30/lessons/12947
bool Soution021(int x)
{
	int sum = 0;

	std::string s = std::to_string(x);
	for (char c : s)
	{
		sum += c - '0';
	}

	return x % sum == 0;

	return false;
}

// 두 정수 사이의 합 
// https://school.programmers.co.kr/learn/courses/30/lessons/12912
long long Solution022(int a, int b)
{
	if (a == b) return a;

	long long ret = 0;
	for(long long i = 1ll * std::min(a,b); i <= 1ll * std::max(a,b); i++)
	{
		ret += i; 
	}

	return ret;
}

// 콜라츠 추측 
// https://school.programmers.co.kr/learn/courses/30/lessons/12943
int Soution023(int num)
{
	int cnt = 0;
	long long n = 1ll * num; 

	while (n != 1)
	{
		n = n % 2 == 0 ? n / 2 : 3 * n + 1;
		cnt++;

		if (cnt >= 500) return -1; 
	}

	return cnt; 
}

// 서울에서 김서방 찾기
// https://school.programmers.co.kr/learn/courses/30/lessons/12919
std::string Solution024(std::vector<std::string> seoul)
{
	std::string ret = "김서방은";

	for (int i = 0; i < seoul.size(); i++)
	{
		if (seoul[i] == "Kim") ret += std::to_string(i);
	}

	ret += "에 있다";

	return ret; 
}

// 나누어 떨어지는 숫자 배열
// https://school.programmers.co.kr/learn/courses/30/lessons/12910
std::vector<int> Solution025(std::vector<int> arr, int divisor)
{
	std::set<int> temp; 

	for (const int num : arr)
	{
		if (num % divisor == 0) temp.insert(num);
	}

	if (temp.empty()) return {-1};

	std::vector<int> ret; 
	for (const int num : temp)
	{
		ret.push_back(num); 
	}

	return ret; 
}


// ==============
// 2025-12-26
// ==============

// 음양 더하기 
// https://school.programmers.co.kr/learn/courses/30/lessons/76501
int Solution026(std::vector<int> absolutes, std::vector<bool> signs)
{
	int sum = 0;

	for (int i = 0; i < signs.size(); i++)
	{
		sum += signs[i] ? absolutes[i] : -absolutes[i];
	}

	return sum; 
}

// 핸드폰 번호 가리기 
// https://school.programmers.co.kr/learn/courses/30/lessons/12948
std::string Solution027(std::string phone_number)
{
	for (int i = 0; i < phone_number.size() - 4; i++)
	{
		phone_number[i] = '*';
	}

	return phone_number; 
}