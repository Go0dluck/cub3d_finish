/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:23:22 by ksharee           #+#    #+#             */
/*   Updated: 2020/11/04 13:53:55 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(ptr = (char *)malloc(len + 1)))
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ptr[i] = '\0';
		return (ptr);
	}
	while (len)
	{
		ptr[i] = s[start];
		i++;
		start++;
		len--;
	}
	ptr[i] = '\0';
	return (ptr);
}
