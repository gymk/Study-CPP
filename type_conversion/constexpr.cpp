#include <iostream>

constexpr long int fibonacci(int n)
{
	return (n <= 1) ? 1 : fibonacci(n-1) + fibonacci(n-2);
}

#if 0
void test(void)
{
	/*
	time ./a.out

	165580141

	real	0m1.027s
	user	0m1.027s
	sys	0m0.000s
	*/
/*
	0000000000400816 <_Z4testv>:
		400816:	55                   	push   %rbp
		400817:	48 89 e5             	mov    %rsp,%rbp
		40081a:	bf 28 00 00 00       	mov    $0x28,%edi
		40081f:	e8 80 00 00 00       	callq  4008a4 <_Z9fibonaccii>
		400824:	48 89 c6             	mov    %rax,%rsi
		400827:	bf 60 10 60 00       	mov    $0x601060,%edi
		40082c:	e8 6f fe ff ff       	callq  4006a0 <_ZNSolsEl@plt>
		400831:	be 00 07 40 00       	mov    $0x400700,%esi
		400836:	48 89 c7             	mov    %rax,%rdi
		400839:	e8 b2 fe ff ff       	callq  4006f0 <_ZNSolsEPFRSoS_E@plt>
		40083e:	90                   	nop
		40083f:	5d                   	pop    %rbp
		400840:	c3                   	retq   

	Makes recursive call, no compile time calculation
*/

	std::cout << fibonacci(40) << std::endl;
}
#else
void test(void)
{
	/*
	time ./a.out

	165580141

	real	0m0.003s
	user	0m0.000s
	sys	0m0.003s
	*/

	/*
	0000000000400816 <_Z4testv>:
		400816:	55                   	push   %rbp
		400817:	48 89 e5             	mov    %rsp,%rbp
		40081a:	48 83 ec 10          	sub    $0x10,%rsp
		40081e:	48 c7 45 f8 6d 8d de 	movq   $0x9de8d6d,-0x8(%rbp)
		400825:	09 
		400826:	be 6d 8d de 09       	mov    $0x9de8d6d,%esi
		40082b:	bf 60 10 60 00       	mov    $0x601060,%edi
		400830:	e8 6b fe ff ff       	callq  4006a0 <_ZNSolsEl@plt>
		400835:	be 00 07 40 00       	mov    $0x400700,%esi
		40083a:	48 89 c7             	mov    %rax,%rdi
		40083d:	e8 ae fe ff ff       	callq  4006f0 <_ZNSolsEPFRSoS_E@plt>
		400842:	90                   	nop
		400843:	c9                   	leaveq 
		400844:	c3                   	retq  

	0x9de8d6d calculated by compiler
	*/
	const long int val = fibonacci(40);	/* can be const or constexpr, otherwise no compile time calculation */

	std::cout << val << std::endl;
}
#endif

int main()
{
	test();
}

/*
Notes:
	*) refer code comments
*/
