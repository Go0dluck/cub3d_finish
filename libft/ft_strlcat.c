/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksharee <ksharee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:50:06 by ksharee           #+#    #+#             */
/*   Updated: 2020/11/04 16:08:14 by ksharee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t size;

	size = 0;
	while (dst[size] && size < dstsize)
		size++;
	i = size;
	while (src[size - i] && size + 1 < dstsize)
	{
		dst[size] = src[size - i];
		size++;
	}
	if (i < dstsize)
		dst[size] = '\0';
	return (i + ft_strlen(src));
}
