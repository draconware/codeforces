#include<bits/stdc++.h> 
#include<string>

using namespace std; 

string s[101];
string ss[101];
int ans;

int main()
{
	int n, k = 0, l, r, x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cin >> s[i];
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < s[i].size(); j++)
			if(s[i][j] == 'X')
			{
				ss[k] = "1x12";
				k++;
				break;
			}
			
		r = 6;
		l = 0;
		
		while(r < 12)
		{
			if(s[i][l] == 'X' && s[i][l] == s[i][r])
			{
				ss[k] = "2x6";
				k++;
				break;
			}
			
			l++;
			r++;
		}
		
		for(int j = 0; j < s[i].size(); j += 4)
		{
			if(s[i][j] == 'X')
				x1++;
				
			if(s[i][j + 1] == 'X')
				x2++;
				
			if(s[i][j + 2] == 'X')
				x3++;
				
			if(s[i][j + 3] == 'X')
				x4++;
		}
		
		if(x1 == 3 || x2 == 3 || x3 == 3 || x4 == 3)
		{
			ss[k] = "3x4";
			k++;
		}
		
		x1 = 0, x2 = 0, x3 = 0, x4 = 0;
			
		for(int j = 0; j < s[i].size(); j += 3)
		{
			if(s[i][j] == 'X')
				x1++;
				
			if(s[i][j + 1] == 'X')
				x2++;
				
			if(s[i][j + 2] == 'X')
				x3++;
		}
		
		if(x1 == 4 || x2 == 4 || x3 == 4)
		{
			ss[k] = "4x3";
			k++;
		}
			
		x1 = 0, x2 = 0, x3 = 0, x4 = 0;
			
		for(int j = 0; j < s[i].size(); j += 2)
		{
			if(s[i][j] == 'X')
				x1++;
				
			if(s[i][j + 1] == 'X')
				x2++;
		}
		
		if(x1 == 6 || x2 == 6)
		{
			ss[k] = "6x2";
			k++;
		}
		
		x1 = 0, x2 = 0, x3 = 0, x4 = 0;
			
		for(int j = 0; j < s[i].size(); j++)
			if(s[i][j] == 'X')
			{
				x1++;
			}
			
		if(x1 == 12)
		{
			ss[k] = "12x1";
			k++;
		}
		
		x1 = 0, x2 = 0, x3 = 0, x4 = 0;
		cout << k <<" ";
		
		for(int j = 0; j < k; j++)
			cout << ss[j] <<" ";
		
		cout << endl;
			
		k = 0;
	}

	return 0;
}