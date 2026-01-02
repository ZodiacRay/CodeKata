#include "January2026.h"
#include <bits/stdc++.h>

// ==============
// 2026-01-02
// ==============

// 문자열 내림차순으로 배치하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12917
std::string Solution034(std::string s)
{
	sort(s.rbegin(), s.rend());

	return s;
}

// 부족한 금액 계산하기
// https://school.programmers.co.kr/learn/courses/30/lessons/82612
long long Solution035(int price, int money, int count)
{
    long long sum = 0;

    for (int i = 1; i <= count; i++)
    {
        sum += price * i;
    }

    long long ret = sum - 1ll * money;

    return ret >= 0 ? ret : 0;
}

// 문자열 다루기 기본
// https://school.programmers.co.kr/learn/courses/30/lessons/12918
bool Solution036(std::string s)
{
    int n = s.size();
    if (n != 4 && n != 6) return false; 

    for (char c : s)
    {
        if (c < '0' || c > '9') return false; 
    }

    return true;
}

// 행렬의 덧셈
// https://school.programmers.co.kr/learn/courses/30/lessons/12950
std::vector<std::vector<int>> Solution037(std::vector<std::vector<int>> arr1, std::vector<std::vector<int>> arr2)
{
    int n = arr1.size(), m = arr1[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr1[i][j] += arr2[i][j];
        }
    }

    return arr1;
}

// 직사각형 별찍기
// https://school.programmers.co.kr/learn/courses/30/lessons/12969
void Solution038(int a, int b)
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
           std::cout << "*";
        }

        std::cout << std::endl;
    }
}

// 최대공약수와 최소공배수
// https://school.programmers.co.kr/learn/courses/30/lessons/12940

int GCD(int a, int b)
{
    if (b == 0) return a;
    return GCD(b, a % b);
} 

std::vector<int> Solution039(int n, int m)
{
    int gcd = GCD(n, m);
    int lcm = n * m / gcd; 

    return { gcd, lcm }; 
}
