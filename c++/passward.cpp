#include <bits/stdc++.h>
using namespace std;
void generate(char* arr, int i, string s, int len)
{
	
	if (i == 0) 
	{
		
		cout << s << "\n";
		
		return;
	}

	
	for (int j = 0; j < len; j++) {

		string appended = s + arr[j];
		generate(arr, i - 1, appended, len);
	}

	return;
}

void crack(char* arr, int len)
{
	
	for (int i = 1; i <= len; i++) {
		generate(arr, i, "", len);
	}
}


int main()
{
	int len ;
	char arr[] = { 'a', 'b', 'c','1','2','3' };
	cout<<"enter the length of passward:";
	cin>>len;
	crack(arr, len);
	
	return 0;
}

