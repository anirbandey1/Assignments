#include <bits/stdc++.h>
using namespace std;

typedef long long int li;
typedef long double ld;


int functi(){
	return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int tt;
    cin >> tt;

    while (tt-- > 0)
    {
	int n;
	cin>>n;

	vector<int>vec(n,0);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>vec[i];
		sum+=vec[i];
	}
	cout<<sum<<endl;
	functi();
    }

    return 0;
}

