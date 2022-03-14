#include <stdio.h>
#include <stdarg.h>

double	moyenne(int nb_valeurs, double valeur1, ...)
{
	double	somme;
	va_list	params;
	va_start(params, valeur1);
	double	valeur_suiv;

	somme = valeur1;
	int	i = 0;
	while (i < nb_valeurs)
	{
		valeur_suiv = va_arg(params, double);
		somme += valeur_suiv;
		i++;	
	}
	va_end(params);
	return (somme / nb_valeurs);
}

int	main(void)
{
	printf("%.3f\n", moyenne(2, 10.0, 20.0));
	return (0);
}
