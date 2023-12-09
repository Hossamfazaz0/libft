/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfazaz <hfazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:32:09 by hfazaz            #+#    #+#             */
/*   Updated: 2023/11/16 03:40:22 by hfazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (fd == -1 || !s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
// int main(){
//     char p[] = "Hossam";
//  int fd = open("output.txt", O_WRONLY | O_CREAT );

//     ft_putstr_fd(p,fd);
// }