// Project by Group-1
#include <iostream>
using namespace std;
int main()
{
    cout << "............................................" << '\n';
    cout << "..  Password's Strength check by GROUP-1  .." << '\n';
    cout << "............................................" << '\n';
    cout << "\n";
    cout << "Enter your password : ";
    string pass;
    getline(cin, pass);
    int str_len = 0, special_char = 0, numbers = 0;
    int lower_case = 0, upper_case = 0;
    int spaces = 0, contiguous = 0, partial = 0;
    string common[] = {"asdfghjkl;'", "asdfghjkl;", "asdfghjkl", "';lkjhgfdsa", "qwertyuiop[]", "zxcvbnm,./", "qwertyuiop", "lkjhgfdsa", ";lkjhgfdsa", "poiuytrewq", "[poiuytrewq", "][poiuytrewq", "/.,mnbvcxz", "ASDFGHJKL:\"", "QWERTYUIOP{}", "}{POIUYTREWQ", "\":LKJHGFDSA", "?><MNBVCXZ", "ZXCVBNM<>?"};

    // Calculating Password length
    while (pass[str_len] != '\0')
        str_len++;
    // Reference : https://cybernews.com/best-password-managers/how-to-create-a-strong-password/
    string special_Char = "!#$%&'@()*+,-./:; <=>?[]^_`{|}~\\\"";
    for (int i = 0; i < str_len; ++i)
    {
        for (int j = 0; j < (int)special_Char.length(); ++j)
        {
            // Calculating special Characters
            if (pass[i] == special_Char[j])
            {
                special_char++;
            }
        }
        // Calculating numbers
        if ((pass[i] - '0' >= 0) && (pass[i] - '0' <= 10))
        {
            numbers++;
        }
    }
    for (int i = 0; i < str_len; ++i)
    {
        // Calculating Upper Case letters
        if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            upper_case++;
        }
        // Calculating Lower Case letters
        else if (pass[i] >= 'a' && pass[i] <= 'z')
        {
            lower_case++;
        }
    }
    // Test 1 : Contineous characters in the password
    for (int i = 0; i <= str_len - 2; ++i)
    {
        if (pass[i] == pass[i + 1])
        {
            contiguous++;
        }
        else if (abs(pass[i] - pass[i + 1]) == 1)
        {
            if (!(((pass[i] >= ' ') && (pass[i] <= '/')) || ((pass[i] >= '[') && (pass[i] <= '`'))))
            {
                contiguous++;
            }
            else
            {
                partial++;
            }
        }
    }
    int maximum_contiguous = 0, temp = 0;
    for (int i = 0; i <= str_len - 2; ++i)
    {
        if (abs(pass[i] - pass[i + 1]) < 2)
        {
            temp++;
        }
        else
        {
            maximum_contiguous = max(maximum_contiguous, temp);
            temp = 0;
        }
    }
    maximum_contiguous = max(maximum_contiguous, temp) + 1;
    // Test 2 : Counting spaces in the password
    for (int i = 0; i < str_len; ++i)
    {
        if (pass[i] == ' ')
        {
            spaces++;
        }
    }
    // Verdict based on Higher priority and their numbers
    // length (7) + upper (4) + lower (2) + special (4) + numbers (3) = 20
    int index = 0;
    // Full marks 7 in length test
    if (str_len <= 5)
    {
        index += 3;
    }
    else if (str_len <= 10)
    {
        index += 5;
    }
    else
    {
        index += 7;
    }
    // Full marks 4 in upper case test
    if (upper_case == 1)
    {
        index += 1;
    }
    else if (upper_case == 2)
    {
        index += 2;
    }
    else if (upper_case == 3)
    {
        index += 3;
    }
    else if (upper_case > 3)
    {
        index += 4;
    }
    // Full marks 2 in lower case test
    if (lower_case >= 3)
    {
        index += 2;
    }
    else
    {
        index += 1;
    }
    // Full mark 4 in special test
    if (special_char == 1)
    {
        index += 1;
    }
    if (special_char == 2)
    {
        index += 2;
    }
    else if (special_char == 3)
    {
        index += 3;
    }
    else if (special_char > 3)
    {
        index += 4;
    }
    // Full marks 3 in numbers
    if (numbers >= 5)
    {
        index += 3;
    }
    else if (numbers >= 3)
    {
        index += 2;
    }
    else
    {
        index += 1;
    }
    // Sanitizer checking in the password
    bool flag = false;
    for (auto i : common)
    {
        if (i == pass)
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        index -= 8;
    }
    else if (contiguous >= 5 && maximum_contiguous >= 5)
    {
        index -= 8;
    }
    // Verdict about the passwords strength
    cout << "Judgement of the password [\u001b[33m" << pass << "\u001b[0m]" << '\n';
    cout << "=> ";
    if (str_len <= 5)
    {
        cout << "\u001b[31mExtremely weak password" << '\n';
    }
    else if (str_len <= 7)
    {
        cout << "\u001b[31mWeak Password" << '\n';
    }
    else if (index >= 15)
    {
        cout << "\u001b[32mStrong Password" << '\n';
    }
    else if (index >= 10)
    {
        cout << "\u001b[33mFair Password" << '\n';
    }
    else if (index >= 7)
    {
        cout << "\u001b[31mWeak Password" << '\n';
    }
    else
    {
        cout << "\u001b[31mExtremely Weak Password" << '\n';
    }
    // Comment about the password's strength
    int i = 1;
    bool check = true;
    cout << "\u001b[35m";
    if (str_len <= 10)
    {
        cout << "Comment #" << i << ": ";
        cout << "You should create a lengthy password resulting a higher permutation number." << '\n';
        i++;
        check = false;
    }
    if (partial >= 4)
    {
        cout << "Comment #" << i << ": ";
        cout << "\u001b[31mSpoiler : The special characters you used are contiguos in ascii value." << '\n';
        cout << "            Most likely it will be on the Wordlist of Kali.\u001b[35m" << '\n';
        i++;
        check = false;
    }
    if (flag)
    {
        cout << "Comment #" << i << ": ";
        cout << "\u001b[31mFound using common QWERTY Keyboard combination which is in the Kali Wordlist file.\u001b[35m" << '\n';
        i++;
        check = false;
    }
    if (contiguous >= 5 && maximum_contiguous >= 4)
    {
        cout << "Comment #" << i << ": ";
        cout << "Contiguous characters makes your password valnerable to hackers through bruteforce attack." << '\n';
        i++;
        check = false;
    }
    if (spaces >= 3)
    {
        cout << "Comment #" << i << ": ";
        cout << "Careful about remembering the spaces you entered." << '\n';
        i++;
        check = false;
    }
    if (special_char >= 5)
    {
        cout << "Comment #" << i << ": ";
        cout << "Careful about remembering the special characters you entered." << '\n';
        i++;
    }
    if (special_char <= 2)
    {
        cout << "Comment #" << i << ": ";
        cout << "Try to add more special characters." << '\n';
        i++;
        check = false;
    }
    if (numbers <= 4)
    {
        cout << "Comment #" << i << ": ";
        cout << "Try to add more numbers in the password." << '\n';
        i++;
        check = false;
    }
    if (upper_case + lower_case <= 5)
    {
        cout << "Comment #" << i << ": ";
        cout << "Try to include more alphabets in the password." << '\n';
        i++;
        check = false;
    }
    if (upper_case <= 3)
    {
        cout << "Comment #" << i << ": ";
        cout << "Try to add more upper case letters in the password." << '\n';
        i++;
        check = false;
    }
    if (lower_case <= 4)
    {
        cout << "Comment #" << i << ": ";
        cout << "Try to add more lower case letters in the password." << '\n';
        i++;
        check = false;
    }
    if (abs(numbers - str_len) <= 1)
    {
        cout << "Comment #" << i << ": ";
        cout << "Using numbers only can exploid you to bruteforce attack." << '\n';
        i++;
        check = false;
    }
    if (check)
    {
        cout << "Comment #" << i << ": ";
        cout << "WOW! A Strong password indeed." << '\n';
    }
    return 0;
}