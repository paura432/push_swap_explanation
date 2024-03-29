/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:03:09 by pramos            #+#    #+#             */
/*   Updated: 2023/01/19 13:04:35 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	a;
	int	signo;

	a = 0;
	signo = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		signo = -1;
		i++;
	}
	else if (str[i] == 43)
		i++;
	while (str[i] > 47 && str[i] < 58)
		a = a * 10 + (str[i++] - '0');
	return (a * signo);
}
