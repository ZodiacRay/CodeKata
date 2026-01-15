#include "January2026.h"


using namespace std; 


#pragma region 01/02 
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

#pragma endregion 

#pragma region 01/05
// ==============
// 2026-01-05
// ==============

// 3진법 뒤집기
// https://school.programmers.co.kr/learn/courses/30/lessons/68935
int Solution040(int n)
{
    std::string s = "";

    while (n)
    {
        s.push_back((n % 3) + '0');
        n /= 3;
    }

    std::reverse(s.begin(), s.end());

    int ret = 0;
    int k = 1;

    for (int i = 0; i < s.size(); i++)
    {
        ret += (s[i] - '0') * k;
        k *= 3;
    }

    return ret; 
}

// 이상한 문자 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/12930
std::string Solution041(std::string s)
{
    int cnt = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            cnt = 1;
            continue;
        }

        if ((cnt) % 2 != 0)
            s[i] = toupper(s[i]);
        else
            s[i] = tolower(s[i]);

        cnt++;
    }
    return s; 
}

// 삼총사
// https://school.programmers.co.kr/learn/courses/30/lessons/131705
int Solution042(std::vector<int> number)
{
    int ret = 0;
    int n = number.size();

    for (int i = 0; i < n - 2; i++)
    {
        int sum = number[i];
        for (int j = i + 1; j < n - 1; j++)
        {
            sum += number[j];
            for (int k = j + 1; k < n; k++)
            {
                sum += number[k];
                if (sum == 0) ret++;
                sum -= number[k];
            }
            sum -= number[j];
        }
    }
    return ret;
}

// 크기가 작은 부분
// https://school.programmers.co.kr/learn/courses/30/lessons/147355
int Solution043(std::string t, std::string p)
{
    int ret = 0;
    int psize = p.size();

    for (int i = 0; i <= t.size() - psize; i++) {
        std::string sub = t.substr(i, psize);

        if (sub <= p) ret++;
    }

    return ret;
}

// 최소 직사각형 
// https://school.programmers.co.kr/learn/courses/30/lessons/86491
int Solution044(std::vector<std::vector<int>> sizes)
{
    int w = 0, h = 0;

    for (std::vector<int> v : sizes)
    {
        int x = v[0], y = v[1];
        if (v[0] < v[1]) x = v[1], y = v[0];

        w = std::max(w, x);
        h = std::max(h, y);
    }

    return w * h;
}

#pragma endregion 

#pragma region 01/06
// ==============
// 2026-01-06
// ==============

// 시저 암호
// https://school.programmers.co.kr/learn/courses/30/lessons/12926
std::string Solution045(std::string s, int n)
{
    for (char& c : s)
    {
        if (c >= 'a' && c <= 'z')
        {
            int k = c - 'a';
            c = 'a' + (k + n) % 26;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            int k = c - 'A';
            c = 'A' + (k + n) % 26;
        }
    }

    return s;
}

// 숫자 문자열과 영단어
// https://school.programmers.co.kr/learn/courses/30/lessons/81301
int Solution046(std::string s)
{
    std::vector<std::string> nums = {
     "zero",
     "one", "two" ,"three",
     "four", "five", "six",
     "seven", "eight", "nine"
    };

    std::string str = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            str.push_back(s[i]);
            continue;
        }


        for (int j = 0; j < 10; j++)
        {
            int n = nums[j].size();
            if (s.substr(i, n) == nums[j])
            {
                str.push_back('0' + j);
                i += n - 1;
                break;
            }
        }

    }
    return stoi(str);
}

// 문자열 내 마음대로 정렬하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12915
std::vector<std::string> Solution047(std::vector<std::string> strings, int n)
{
    sort(strings.begin(), strings.end(), [n](std::string a, std::string b)
        {
            return a[n] == b[n] ? a < b : a[n] < b[n]; 
        });

    return strings;
}

// K번째수
// https://school.programmers.co.kr/learn/courses/30/lessons/42748
std::vector<int> Solution048(std::vector<int> array, std::vector<std::vector<int>> commands)
{
    std::vector<int> ret;

    for (auto cmd : commands)
    {
        std::vector<int> temp;
        for (int i = cmd[0] - 1; i < cmd[1]; i++) temp.push_back(array[i]);

        sort(temp.begin(), temp.end());

        ret.push_back(temp[cmd[2] - 1]);
    }

    return ret;
}

// 두 개 뽑아서 더하기
// https://school.programmers.co.kr/learn/courses/30/lessons/68644
std::vector<int> Solution049(std::vector<int> numbers)
{
    std::set<int> s;

    for (int i = 0; i < numbers.size() - 1; i++)
        for (int j = i + 1; j < numbers.size(); j++)
            s.insert(numbers[i] + numbers[j]);
        
    std::vector<int> ret;
    for (int i : s) ret.push_back(i);
    
    return ret;;
}

#pragma endregion

#pragma region 1/9
// 가장 가까운 같은 글자
// https://school.programmers.co.kr/learn/courses/30/lessons/142086
std::vector<int> Solution050(std::string s)
{
    std::vector<int> ret;

    std::vector<int> v(26, -1);

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (v[c - 'a'] == -1) ret.push_back(-1);
        else ret.push_back(i - v[c - 'a']);

        v[c - 'a'] = i;
    }
    return ret;
}

#pragma endregion 

#pragma region 1/12
// 푸드 파이트 대회
// https://school.programmers.co.kr/learn/courses/30/lessons/134240
string Solution051(std::vector<int> food)
{
    string ret = "0";

    for (int i = food.size()-1; i > 0; i--)
    {
        int cnt = food[i] / 2;

        while (cnt--)
        {
            ret = to_string(i) + ret + to_string(i);
        }
    }

    return ret; 
}

// 콜라 문제
// https://school.programmers.co.kr/learn/courses/30/lessons/132267
int Solution052(int a, int b, int n)
{
    int remains = n;
    int cnt = 0;

    while (remains >= a)
    {
        cnt += (remains / a) * b;
        remains = (remains / a) * b + remains % a;
    }

    return cnt;
}

#pragma endregion

#pragma region 1/13
// 명예의 전당 (1)
// https://school.programmers.co.kr/learn/courses/30/lessons/138477
vector<int> Solution053(int k, vector<int> score)
{
    vector<int> ret;
    multiset<int> ms;

    for (int s : score)
    {
        ms.insert(s);
        if (ms.size() > k)
            ms.erase(ms.begin());

        ret.push_back(*ms.begin());
    }

    return ret;
}
// 2016 년
// https://school.programmers.co.kr/learn/courses/30/lessons/12901
std::string Solution054(int a, int b)
{
    std::vector<string> str = {
    "SUN","MON","TUE","WED","THU","FRI","SAT"
    };

    vector<int> month = { 0,
        31, 29, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    int dif = 4;

    for (int i = 1; i < a; i++)
    {
        dif += month[i];
    }

    dif += b;

    return str[dif % 7];
}

#pragma endregion


#pragma region 1/14
// 카드 뭉치
// https://school.programmers.co.kr/learn/courses/30/lessons/159994
string Solution055(vector<string> cards1, vector<string> cards2, vector<string> goal)
{
    int i1 = 0, i2 = 0;

    for (int i = 0; i < goal.size(); i++)
    {
        if (i1 < cards1.size() && goal[i] == cards1[i1]) i1++;
        else if (i2 < cards2.size() && goal[i] == cards2[i2]) i2++;
        else return "No";
    }

    return "Yes";
}

// 과일 장수 
// https://school.programmers.co.kr/learn/courses/30/lessons/135808
int Solution056(int k, int m, vector<int> score)
{
    sort(score.rbegin(), score.rend());

    int ret = 0;
    for (int i = m - 1; i < score.size(); i += m)
        ret += score[i] * m;

    return ret;
}

// 모의고사 
// https://school.programmers.co.kr/learn/courses/30/lessons/42840
vector<int> Solution057(vector<int> answers)
{
    int n = answers.size(); 

    int t1[] = { 1,2,3,4,5 };
    int t2[] = { 2,1,2,3,2,4,2,5 };
    int t3[] = { 3,3,1,1,2,2,4,4,5,5 };

    vector<int> result(4, 0);

    for (int i = 0; i < n; i++)
    {
        result[1] += t1[i % 5] == answers[i] ? 1 : 0;
        result[2] += t2[i % 8] == answers[i] ? 1 : 0;
        result[3] += t3[i % 10] == answers[i] ? 1 : 0;
    }

    int max_val = *max_element(result.begin(), result.end());

    vector<int> ret;
    for (int i = 1; i < 4; i++)
        if (max_val == result[i]) ret.push_back(i);

    return ret;
}
#pragma endregion 

#pragma region 1/15
// 소수 만들기 
// https://school.programmers.co.kr/learn/courses/30/lessons/12977
bool isPrime(int n)
{
    if (n < 2) return false;

    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;

    return true;
}
int Solution058(vector<int> nums)
{
    int n = nums.size();
    int ret = 0;

    int sum = 0;
    for (int i = 0; i < n - 2; i++)
    {
        sum = nums[i];
        for (int j = i + 1; j < n - 1; j++)
        {
            sum += nums[j];
            for (int k = j + 1; k < n; k++)
            {
                sum += nums[k];

                ret += isPrime(sum) ? 1 : 0;

                sum -= nums[k];
            }
            sum -= nums[j];
        }
    }

    return ret;
}


#pragma endregion 