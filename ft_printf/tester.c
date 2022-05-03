#include <stdio.h>

int	ft_printf(const char *format, ...);

int     main(void)
{
	int	ret, myret;
	///// AVEC UN ARGUMENT
	
	// %c
/*	
	printf("--- %%c ---\n\n");
	
        char	c1 = 'a';
	char	c2 = 42;
	int	c3 = 42;
	char	c4[10] = "Hello";
	int	*c5 = &c3;
	unsigned int	c6 = 0;

        ret = printf("%c\n", c1);
        myret = ft_printf("%c\n", c1);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%c\n", c2);
        myret = ft_printf("%c\n", c2);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%c\n", c3);
        myret = ft_printf("%c\n", c3);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%c\n", c4);
        myret = ft_printf("%c\n", c4);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%c\n", c5);
        myret = ft_printf("%c\n", c5);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%c\n", c6);
        myret = ft_printf("%c\n", c6);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

*/
	// %s
/*	
	printf("--- %%s ---\n\n");

	char	s1[10] = "Hello";
	char	s2[10] = "";
	char	s3 = 'c';
	int	s4 = 42;
	int	*s5 = &s4;
	unsigned int	s6 = 42;

        ret = printf("%s\n", s1);
        myret = ft_printf("%s\n", s1);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%s\n", s2);
        myret = ft_printf("%s\n", s2);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        //ret = printf("%s\n", s3);
        //myret = ft_printf("%s\n", s3);
        //printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%s\n", s5);
        myret = ft_printf("%s\n", s5);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        //ret = printf("%s\n", s6);
        //myret = ft_printf("%s\n", s6);
        //printf("ret : %d\nmyret : %d\n\n", ret, myret);
*/

        // %p
        
        printf("--- %%p ---\n\n");

	char	p1 = 'c';
	char	p2[10] = "Hello";
	int	p3 = 42;
	int	*p4 = &p3;
	unsigned int p5 = 42;

//        ret = printf("%p\n", p1);
//        myret = ft_printf("%p\n", p1);
//        printf("ret : %d\nmyret : %d\n\n", ret, myret);


        ret = printf("%p\n", p2);
        myret = ft_printf("%p\n", p2);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

//        ret = printf("%p\n", p3);
//        myret = ft_printf("%p\n", p3);
//        printf("ret : %d\nmyret : %d\n\n", ret, myret);
	
        ret = printf("%p\n", p4);
        myret = ft_printf("%p\n", p4);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

//        ret = printf("%p\n", p5);
//        myret = ft_printf("%p\n", p5);
//        printf("ret : %d\nmyret : %d\n\n", ret, myret);


        // %d
/* 
        printf("--- %%d ---\n\n");

	int	d1 = 42;
	char	d2 = 'c';
	unsigned int d3 = 42;
	int	d4 = -2147483648;
	char	d5[10] = "Hello";
	int	*d6 = &d1;

        ret = printf("%i\n", d1);
        myret = ft_printf("%i\n", d1);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

	
        ret = printf("%i\n", d2);
        myret = ft_printf("%i\n", d2);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%i\n", d3);
        myret = ft_printf("%i\n", d3);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%i\n", d4);
        myret = ft_printf("%i\n", d4);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%i\n", d5);
        myret = ft_printf("%i\n", d5);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%i\n", d6);
        myret = ft_printf("%i\n", d6);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);
*/

	// %u

/*
        printf("--- %%u ---\n\n");

	int	u1 = 42;
	char	u2 = 'c';
	unsigned int u3 = 42;
	int	u4 = -2147483648;
	char	u5[10] = "Hello";
	int	*u6 = &u1;
	int	u7 = -42;

        ret = printf("%u\n", u1);
        myret = ft_printf("%u\n", u1);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

	
        ret = printf("%u\n", u2);
        myret = ft_printf("%u\n", u2);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%u\n", u3);
        myret = ft_printf("%u\n", u3);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%u\n", u4);
        myret = ft_printf("%u\n", u4);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%u\n", u5);
        myret = ft_printf("%u\n", u5);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%u\n", u6);
        myret = ft_printf("%u\n", u6);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%u\n", u7);
        myret = ft_printf("%u\n", u7);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);
*/

	
	// %x
/*
        printf("--- %%x ---\n\n");

	int	x1 = 42;
	char	x2 = 'c';
	unsigned int x3 = 42;
	int	x4 = -2147483648;
	char	x5[10] = "Hello";
	int	*x6 = &x1;
	int	x7 = -42;

        ret = printf("%x\n", x1);
        myret = ft_printf("%x\n", x1);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

	
        ret = printf("%x\n", x2);
        myret = ft_printf("%x\n", x2);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%x\n", x3);
        myret = ft_printf("%x\n", x3);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%x\n", x4);
        myret = ft_printf("%x\n", x4);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);


        ret = printf("%x\n", x5);
        myret = ft_printf("%x\n", x5);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%x\n", x6);
        myret = ft_printf("%x\n", x6);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

        ret = printf("%x\n", x7);
        myret = ft_printf("%x\n", x7);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);
*/

	// %%
/*	
	ret = printf("%%\n");
	myret = ft_printf("%%\n");
        printf("ret : %d\nmyret : %d\n\n", ret, myret);
*/
	
	// %truc mais sans argument
/*		
	ret = printf("Hello %c\n");
	myret = ft_printf("Hello %c\n");
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

	ret = printf("Hello %s\n");
	myret = ft_printf("Hello %s\n");
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

	ret = printf("Hello %p\n");
	myret = ft_printf("Hello %p\n");
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

	ret = printf("Hello %i\n");
	myret = ft_printf("Hello %i\n");
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

	ret = printf("Hello %u\n");
	myret = ft_printf("Hello %u\n");
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

	ret = printf("Hello %x\n");
	myret = ft_printf("Hello %x\n");
        printf("ret : %d\nmyret : %d\n\n", ret, myret);

	ret = printf("Hello %X\n");
	myret = ft_printf("Hello %X\n");
        printf("ret : %d\nmyret : %d\n\n", ret, myret);
*/

	// %smth avec smth pris en charge par printf et pas par ft_printf
/*
	ret = printf("Hello %a\n", 42);
	myret = ft_printf("Hello %a\n", 42);
        printf("ret : %d\nmyret : %d\n\n", ret, myret);
*/

	// %smth avec smth non pris en charge par printf ou ft_printf
/*
	ret = printf("Hello %y\n");
	myret = ft_printf("Hello %y\n");
        printf("ret : %d\nmyret : %d\n\n", ret, myret);
*/
        return (0);
}

// Problemes :
//
// %p avec un char (ie int), un int ou un unsigned int : valeur affichee ok (c'est le 0x le nombre en hexa)
// mais valeur de retour = la len de l'hexa, pas 14 comme une adresse memoire
//
// si je demande un %x ou %X et donne une string ou un pointeur, j'ai maintenant trop d'infos
//
// %truc sans argument : ca met des random trucs je sais pas trop quoi faire
//
// %someth avec someth pris en charge par printf et pas par ft_printf : well obviously not too sure what to do
//
//
// A TESTER : avec plusieurs arguments ?
