int func(int i,int j,int k){
	int a =5;
	int c = 0;
	c = (i+j)*a-k;
	return c;
}
int main() {
	int c = 10;
	int d = 20;
	d = func(c,d,2)/2+3;
	return d;
}
