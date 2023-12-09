/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:15:14 by hfazaz            #+#    #+#             */
/*   Updated: 2023/11/11 23:11:56 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	src_len;

	src_len = ft_strlen(s);
	if ((char)c == '\0')
		return ((char *)s + src_len);
	while (src_len)
	{
		src_len--;
		if (s[src_len] == (char)c)
		{
			return ((char *)s + src_len);
		}
	}
	return (NULL);
}
