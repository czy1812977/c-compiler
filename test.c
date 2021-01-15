int func(int a){
	if(a==1)return 1;
	//return func(1);	
}
int main(){
    int a = 1;
    int b = 3;
    int c = func(a);
    printf_int(c);
    return 0;
}

/*预期输出：30
实际输出：30*/
