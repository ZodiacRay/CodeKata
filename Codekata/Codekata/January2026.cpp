#include "January2026.h"


using namespace std; 


#pragma region 01/02 
// ==============
// 2026-01-02
// ==============

// 문자열 내림차순으로 배치하기
// https://school.programmers.co.kr/learn/courses/30/lessons/12917
std::string Solution034(string s)
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

#pragma region 1/19
// 덧칠하기 
// https://school.programmers.co.kr/learn/courses/30/lessons/161989 /
int Solution059(int n, int m, vector<int> section)
{
    int ret = 0;
    int si = 0;

    int paint = 0;
    for (int i = 0; i <= n; i++)
    {
        paint = paint > 0 ? paint-1 : 0;

        if (i == section[si])
        {
            si++;
            if (paint > 0) continue;

            paint = m;
            ret++;
        }
    }

    return ret;
}
#pragma endregion 

#pragma region 1/20 
// 기사단원의 무기
// https://school.programmers.co.kr/learn/courses/30/lessons/136798 /
int Solution060(int number, int limit, int power)
{
    vector<int> factors(number + 1, 1);

    for (int i = 2; i <= number; i++)
    {
        factors[i]++;
        for (int j = i + i; j <= number; j += i)
        {
            factors[j]++;
        }
    }

    int sum = 0;
    for (int i = 1; i <= number; i++)
    {
        sum += factors[i] > limit ? power : factors[i];
    }


    return sum;
}

// 로또의 최고 순위와 최저 순위
// https://school.programmers.co.kr/learn/courses/30/lessons/77484 / 
vector<int> Solution061(vector<int> lottos, vector<int> win_nums)
{
    int zero = 0, cnt = 0;
    for (int i = 0; i < 6; i++)
    {
        if (lottos[i] == 0)
        {
            zero++;
            continue;
        }

        for (int j = 0; j < 6; j++)
        {
            if (lottos[i] == win_nums[j])
            {
                cnt++;
                break;
            }
        }
    }

    int high = min(6, 7 - cnt - zero);
    int low = min(6, 7 - cnt);

    return { high, low };
}

#pragma endregion 


#pragma region 1/21 

// 옹알이 (2) 
// https://school.programmers.co.kr/learn/courses/30/lessons/133499 / 
bool check(string s)
{
    vector<string> str = { "aya", "ye", "woo", "ma" };
    int n = s.size();
    string last = "";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            string temp = s.substr(0, str[j].size());
            if (temp == str[j] && last != temp)
            {
                s.erase(0, str[j].size());
                last = temp;
            }
        }

        if (s.size() == 0) return true;
    }

    return s.size() == 0;

}

int Solution062(vector<string> babbling)
{
    int answer = 0;

    for (string s : babbling)
    {
        if (check(s))
        {
            answer++;

            cout << s << endl;
        }
    }

    return answer;
}

// 숫자 짝꿍
// https://school.programmers.co.kr/learn/courses/30/lessons/131128
string Solution063(string X, string Y)
{
    vector<int> x(10, 0);
    vector<int> y(10, 0);

    string ret = "";

    for (char c : X)
        x[c - '0']++;

    for (char c : Y)
    {
        if (x[c - '0'] > 0)
        {
            ret += c;
            x[c - '0']--;
        }
    }
    if (ret.size() == 0) return "-1";

    sort(ret.rbegin(), ret.rend());
    if (ret[0] == '0') return "0";


    return ret;

}
#pragma endregion 

#pragma region 1/22
// 체육복
// https://school.programmers.co.kr/learn/courses/30/lessons/42862
int Solution064(int n, vector<int> lost, vector<int> reserve)
{
   vector<int> v(n+1, 1);
    
    for (int i : lost) v[i]--;
    for (int i : reserve) v[i]++;
    
    for (int i = 1; i <= n; i++)
    {
        if (v[i] > 0) continue;
        
        if (v[i-1] > 1 )
        {
            v[i] = 1; 
            v[i-1] = 1;
        }
        else if (v[i+1] > 1)
        {
            v[i] = 1;
            v[i-1] = 1; 
        }
    }
    
    int ret = 0;
    for (int i = 1; i <= n; i++) ret += i > 0 ? 1 : 0; 
    
    return ret; 
}

// 문자열 나누기
// https://school.programmers.co.kr/learn/courses/30/lessons/140108
int Solution065(string s)
{
    int n = s.size();
    if (n < 1) return 0;

    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[0] == s[i]) a++;
        else b++;

        if (a == b) return 1 + Solution065(s.substr(i + 1));
    }

    return 1;
}
#pragma endregion 

#pragma region 1/23
// 대충 만든 자판
// https://school.programmers.co.kr/learn/courses/30/lessons/160586 
vector<int> Solution066(vector<string> keymap, vector<string> targets)
{
    vector<int> answer;
    vector<int> mintabs(27, 0);

    for (string key : keymap)
    {
        for (int i = 0; i < key.size(); i++)
        {
            int indx = key[i] - 'A';
            if (mintabs[indx] == 0) mintabs[indx] = i + 1;
            else mintabs[indx] = min(mintabs[indx], i + 1);
        }
    }

    for (string target : targets)
    {
        int tab_count = 0;
        for (char c : target)
        {
            int indx = c - 'A';

            if (mintabs[indx] == 0)
            {
                tab_count = -1;
                break;
            }
            tab_count += mintabs[indx];
        }
        answer.push_back(tab_count);
    }

    return answer;
}

// 둘만의 암호
// https://school.programmers.co.kr/learn/courses/30/lessons/155652
string Solution067(string s, string skip, int index)
{
    vector<bool> should_skip(26, false);

    for (char c : skip) should_skip[c - 'a'] = true;

    string ret = "";
    for (char c : s)
    {
        char cur = c;
        int i = index;

        while (i--)
        {
            cur++;
            if (cur > 'z') cur = 'a';

            if (should_skip[cur - 'a']) i++;
        }

        ret += cur;
    }

    return ret;
}
#pragma endregion 

#pragma region 1/26
// 햄버거 만들기
// https://school.programmers.co.kr/learn/courses/30/lessons/133502 
int Solution068(vector<int> ingredient)
{
    vector<int> st; 
    
    int ret = 0;
    for(int i : ingredient)
    {
        st.push_back(i);
        if(st.size() < 4) continue;
        
        int j = st.size()-1; 
        if(st[j] == st[j-3] && st[j] == 1&& st[j-1] == 3 && st[j-2] == 2) 
        {
            for(int k = 0; k < 4; k++) st.pop_back();
            
            ret++;
        }
    }
    
    return ret; 
}
#pragma endregion

#pragma region 1/27
// 성격 유형 검사     
// https://school.programmers.co.kr/learn/courses/30/lessons/118666 
string Solution069(vector<string> survey, vector<int> choices)
{
    vector<string> str = 
    {
        "RT","CF","JM", "AN"
    };
    vector<int> result(4,0); // RT // CF // JM // AN 
    
    int n = survey.size();
    for(int i = 0; i < n; i++)
    {
        int point = choices[i] - 4;
        if(point == 0) continue; 
        
        if(survey[i] == "RT") result[0] += point;
        else if(survey[i] == "TR") result[0] -= point;    
        
        else if(survey[i] == "CF") result[1] += point;
        else if(survey[i] == "FC") result[1] -= point; 
        
        else if(survey[i] == "JM") result[2] += point;
        else if(survey[i] == "MJ") result[2] -= point; 
        
        else if(survey[i] == "AN") result[3] += point;
        else if(survey[i] == "NA") result[3] -= point; 
    }
    
    string ret = "RCJA";
    for(int i = 0; i < 4; i++)
    {
        if(result[i] == 0) continue;
        
        ret[i] = result[i] > 0 ? str[i][1] : str[i][0];
    }
    
    return ret; 
}
#pragma endregion

#pragma region 1/28

// 바탕화면 정리
// https://school.programmers.co.kr/learn/courses/30/lessons/161990
vector<int> Solution070(vector<string> wallpaper)
{
    int lux = 51, luy = 51;
    int rdx = 0, rdy = 0;
    
    for(int i = 0; i < wallpaper.size(); i++) {
        for(int j = 0; j < wallpaper[0].size(); j++) {
            
            if(wallpaper[i][j] != '#') continue;
            
            lux = min(lux, j);
            luy = min(luy, i);
            
            rdx = max(rdx, j+1);
            rdy = max(rdy, i+1);
        }
    }
    
    return {luy, lux, rdy, rdx};
}


// 개인 정보 수집
// https://school.programmers.co.kr/learn/courses/30/lessons/150370
int GetTotalDays(string date) 
{
    int y = stoi(date.substr(0, 4));
    int m = stoi(date.substr(5, 2));
    int d = stoi(date.substr(8, 2));
    return (y * 12 * 28) + (m * 28) + d;
}

vector<int> Solution071(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> ret;
    
    int todayInDays = GetTotalDays(today);
    int termMap[26] = {0};
    
    for (string term : terms) {
        stringstream ss(term);
        char type;
        int month;
        ss >> type >> month;
        termMap[type - 'A'] = month * 28; 
    }
    
    for(int i = 0; i < privacies.size(); i++)
    {
        int collectDays = GetTotalDays(privacies[i].substr(0, 10));
        int ti = privacies[i].back() - 'A'; 
        collectDays += termMap[ti]; 
        
        if(collectDays <= todayInDays)
            ret.push_back(i+1);
    }
        
    return ret;
}

#pragma endregion
