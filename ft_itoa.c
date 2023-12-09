/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:42:42 by hfazaz            #+#    #+#             */
/*   Updated: 2023/11/12 21:30:37 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		count += 1;
		n = -n;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len_num;
	int		is_n;
	char	*res;

	is_n = 0;
	len_num = ft_count(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		is_n = 1;
	}
	res = (char *)malloc((len_num + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len_num] = '\0';
	while (len_num)
	{
		res[--len_num] = (n % 10) + '0';
		n /= 10;
	}
	if (is_n)
		res[0] = '-';
	return (res);
}
