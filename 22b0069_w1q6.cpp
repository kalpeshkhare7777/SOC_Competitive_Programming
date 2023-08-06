
#include <iostream>
#include<cmath>
using namespace std;

void cal(int n, int from, int to, int aux)
{
	if (n == 0) {
		return;
	}
	cal(n - 1, from, aux, to);
	cout << from<<" "<< to<< endl;
	cal(n - 1, aux, to, from);
}

int main()
{
	int N = 0;
    cin>>N;
    cout<<pow(2,N)-1<<endl;

	cal(N, 1, 3, 2);
	return 0;
}

