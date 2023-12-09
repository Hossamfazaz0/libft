/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:33:59 by hfazaz            #+#    #+#             */
/*   Updated: 2023/12/05 21:38:41 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	if (!src && len == 0)
		return (NULL);
	a = 0;
	if (needle[0] == '\0')
		return ((char *)src);
	while (src[a] && a < len)
	{
		b = 0;
		while (src[a + b] == needle[b] && a + b < len)
		{
			b++;
			if (needle[b] == '\0')
				return ((char *)(src + a));
		}
		a++;
	}
	return (0);
}
