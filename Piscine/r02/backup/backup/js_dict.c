/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   js_dict.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschott <jschott@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 12:30:50 by jschott           #+#    #+#             */
/*   Updated: 2023/02/25 13:40:35 by jschott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <numbers.dict>

typedef struct	num_names { /* table entry: */
    struct num_struct *next; /* next entry in chain */
    int *key; /* keyvalue as integer */
    char *value; /* word of the integer key */
};

void *get_name(dict_t *dict, int *key)
{
	// missingpointer to key

	while ()	// missing condition to go through all entries
	{	
		if (ptr -> key == key)
			return ptr -> value;
	}
	return NULL;
}
