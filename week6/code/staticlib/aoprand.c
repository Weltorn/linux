int max(int* a, int n)
{
	int m,i;
	m = a[0];
	for(i = 1;i<n;i++)
	{
		if(m<a[i])
		{
			m = a[i];
		}
	}
	return m;
}
int sum(int* a, int n)
{
	int s,i;
	s = a[0];
	for(i = 1;i<n;i++)
	{		
		s = s+a[i];		
	}
	return s;
}


