#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string input, string output, int index)
{
    if (index == input.length())
    {
        return;
    }
    if (output != "")
    {
        cout << output << endl;
    }

    for (int i = index + 1; i < input.length(); i++)
    {
        output += input[i];
        printSubsequence(input, output, i);
        output.pop_back();
    }
    return;
}

int main()
{
    string output = "";
    string input = "abcd";

    printSubsequence(input, output, -1);

    return 0;
}